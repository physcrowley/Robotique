#!/usr/bin/env pybricks-micropython

"""
Nom : David Crowley
Fichier : calibrate_refl.py
Date : 2024-05-22

Description :  Programme pour obtenir des valeurs de calibrage
pour le capteur de couleur en mode réflexion. Le programme attend
en clignotant une lumière jusqu'à ce qu'un bouton soit enfoncé. La brique
prend alors une lecture de réflexion pour le noir et l'affiche sur son écran. 

Ce processus est répété pour le blanc. 

Finalement, le programme attend à nouveau pour laisser le temps aux 
roboticiennes de noter les résultats.
"""

from pybricks.hubs import EV3Brick
from pybricks.ev3devices import ColorSensor
from pybricks.parameters import Port, Color
from pybricks.tools import wait, StopWatch

# DÉFINIR LES VALEURS GLOBALES DU PROGRAMME

# Initialisez la brique
ev3 = EV3Brick()

# Initialisez le capteur couleur
sensor = ColorSensor(Port.S3)

# Initialiser un chronomètre pour gérer le clignotement
timer = StopWatch()
blinking = False
lit = False

# DÉFINIR LES FONCTIONS DU PROGRAMME


def blink():
    """Fonction qui gère le clignotement de la lumière"""
    global blinking, lit

    color = Color.PURPLE

    # seulement la première fois
    if not blinking:
        # allume la lumière
        ev3.light.on(color)
        lit = True
        # prend une référence de temps pour le clignotement
        blink.last_time = timer.time()
        blinking = True

    # change l'état de la lumière chaque 500ms
    if timer.time() - blink.last_time > 500:
        if lit:
            ev3.light.off()
        else:
            ev3.light.on(color)
        lit = not lit  # change True à False et vice versa
        blink.last_time = timer.time()  # réinitialise le temps


def stop_blink():
    global blinking, lit

    blinking = False
    lit = False
    ev3.light.off()


def wait_for_button_press():
    """Fonction qui clignote la lumière en attendant qu'un bouton soit enfoncé"""
    while True:
        blink()
        if any(ev3.buttons.pressed()):
            stop_blink()
            return  # quitte la fonction


def read_reflection_value():
    """Fonction pour attendre un bouton avant de lire et afficher le
    pourcentage de lumière réfléchie sur le capteur de couleur"""

    wait_for_button_press()

    # capter la valeur après un délai d'une seconde
    wait(1000)
    reflection_value = sensor.reflection()
    ev3.speaker.beep()

    # afficher la valeur captée à l'écran de la brique
    ev3.screen.print(reflection_value)


# LE PROGRAMME

# Lancer la lecture de calibrage pour le noir
ev3.screen.print("noir... ")
read_reflection_value()

# Lancer la lecture de calibrage pour le blanc
ev3.screen.print("blanc... ")
read_reflection_value()

# attendre avant de mettre fin au programmme
wait_for_button_press()
