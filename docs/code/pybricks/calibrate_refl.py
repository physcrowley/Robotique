#!/usr/bin/env pybricks-micropython

"""
Programme de calibrage du capteur de rélexion de lumière
"""

from pybricks.hubs import EV3Brick
from pybricks.ev3devices import ColorSensor
from pybricks.parameters import Port
from pybricks.tools import wait

# Initialisez la brique
ev3 = EV3Brick()

# Initialisez le capteur couleur
sensor = ColorSensor(Port.S3)


# Définir une fonction avec le code du test de calibrage
def reflection_test() :
    # attendre qu'un bouton soit enfoncé sur la brique
    while not any(ev3.buttons.pressed()):
        continue
   
    # capter la valeur après un délai d'une seconde
    wait(1000)
    colour_value = sensor.reflection()
    ev3.speaker.beep()
    
    # afficher la valeur captée à l'écran de la brique 
    ev3.screen.print(colour_value)


# Lancer le test de calibrage pour le noir
ev3.screen.print("noir... ")
reflection_test()

# Lancer le test de calibrage pour le blanc
ev3.screen.print("blanc... ")
reflection_test()

# attendre qu'un bouton soit enfoncé sur la brique
# avant de quitter
while not any(ev3.buttons.pressed()):
    continue
