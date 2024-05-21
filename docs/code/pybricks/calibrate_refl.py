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
def reflection_test(c: str) :
    """  c : le nom de la couleur à tester ('noir' ou 'blanc') """
    
    # attendre qu'un bouton soit enfoncé sur la brique
    while not any(ev3.buttons.pressed()):
        continue
   
    # capter la valeur après un délai d'une seconde
    wait(1000)
    colour_value = sensor.reflection()
    ev3.speaker.beep()
    
    # afficher la valeur captée à la console de l'ordinateur
    print(f"couleur {c} : {colour_value}")


# Lancer le test de calibrage pour le noir
reflection_test("noir")

# Lancer le test de calibrage pour le blanc
reflection_test("blanc")
