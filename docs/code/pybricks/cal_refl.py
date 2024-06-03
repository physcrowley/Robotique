#!/usr/bin/env pybricks-micropython

"""
Nom : David Crowley
Fichier : main.py (ou cal_refl.py)
Date : 2024-05-31 (mise à jour 2024-06-03)

Description : Programme pour obtenir des valeurs de calibrage
pour le capteur de couleur en mode réflexion. Le programme affiche 
en continu les valeurs captées ainsi que les valeurs max et min.

Quand un bouton est enfoncé, les valeurs max et min sont affichés
en plus grande taille.

Le programme inclut également un algorithme pour clignoter la 
lumière de la brique à un délai et avec une couleur prescrits.
"""

from pybricks.hubs import EV3Brick
from pybricks.ev3devices import ColorSensor
from pybricks.parameters import Port, Color
from pybricks.media.ev3dev import Font
from pybricks.tools import wait, StopWatch

#
# DÉFINIR LES VALEURS GLOBALES DU PROGRAMME
#

# Initialisez la brique
EV3 = EV3Brick()

# Initialisez le capteur couleur
SENSOR = ColorSensor(Port.S3)

# Initialiser les polices
BIG = Font(size=36)
SMALL = Font(size=24)

# Déclarer des variables pour gérer le clignotement
TIMER = StopWatch()
on = True
start = TIMER.time()

#
# LOGIQUE DU PROGRAMME
#


def main():
    # valeurs initiales de variables locales
    whitest = SENSOR.reflection()
    blackest = SENSOR.reflection()

    # boucle de calibrage
    while not any(EV3.buttons.pressed()):
        # gérer la lumière
        blink(1000, Color.GREEN)

        # lire le capteur
        value = SENSOR.reflection()

        # mettre à jour les valeurs limites
        if value > whitest:
            whitest = value
        elif value < blackest:
            blackest = value

        # preparer le texte à afficher
        current = str(value)
        historic = "max=" + str(whitest) + ", min=" + str(blackest)

        # afficher le texte
        show_live(current, historic)
        wait(20)  # laisser le temps à l'écran de se rafraîchir

    # afficher le résultat final
    EV3.speaker.beep()
    EV3.light.off()
    show_final(str(blackest) + "-" + str(whitest))

    # attendre un arrêt intentionnel du programme
    wait(200)  # distinguer le prochain clic du précédent
    while not any(EV3.buttons.pressed()):
        blink(200, Color.YELLOW)
    EV3.light.off()


#
# FONCTIONS POUR LE TEXTE ET LA LUMIÈRE
#


def show_live(current: str, historic: str) -> None:
    ch = BIG.text_height(current)
    cw = BIG.text_width(current)

    hh = SMALL.text_height(historic)
    hw = SMALL.text_width(historic)

    y_padding = 5
    cx = (EV3.screen.width - cw) // 2
    cy = (EV3.screen.height - ch - hh - y_padding) // 2

    hx = (EV3.screen.width - hw) // 2
    hy = cy + ch + y_padding

    # afficher les valeurs
    EV3.screen.clear()
    EV3.screen.set_font(BIG)
    EV3.screen.draw_text(cx, cy, current)
    EV3.screen.set_font(SMALL)
    EV3.screen.draw_text(hx, hy, historic)


def show_final(historic: str) -> None:
    hh = BIG.text_height(historic)
    hw = BIG.text_width(historic)

    hx = (EV3.screen.width - hw) // 2
    hy = (EV3.screen.height - hh) // 2

    EV3.screen.clear()
    EV3.screen.set_font(BIG)
    EV3.screen.draw_text(hx, hy, historic)


def blink(delay: int, colour: Color) -> None:
    global on, start  # on modifie ces variables globales

    if on:
        EV3.light.on(colour)
    else:
        EV3.light.off()

    # change l'état de la lumière chaque `delay` ms
    if TIMER.time() - start > delay:
        on = not on  # change True à False et vice versa
        start = TIMER.time()  # ... et redémarre le chrono


#
# LANCER LE PROGRAMME
#

main()
