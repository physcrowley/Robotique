"""
Fichier : comparisons.py
Date : 11 mai 2024
Auteur : David Crowley
Description : Ce programme explore l'utilisation de comparaisons en Python
"""

# Assigner des valeurs à des variables
x = 5
y = 3
print('Valeurs de x et y:', x, y)

# Comparer les valeurs
print('x est égal à y:', x == y)
print('x est différent de y:', x != y)
print('x est plus grand que y:', x > y)
print('x est plus petit que y:', x < y)
print('x est plus grand ou égal à y:', x >= y)
print('x est plus petit ou égal à y:', x <= y)

# Comparer des chaînes de caractères
nom = 'Alice'
print('Le nom est Alice:', nom == 'Alice')
print('Le nom est différent de Bob:', nom != 'Bob')

# Comparer des valeurs dans une liste ou un texte
values = [1, 2, 3, 4, 5]
print(values)
print('5 est dans la liste:', 5 in values)
print('6 est dans la liste:', 6 in values)

word = 'Bonjour'
print(word)
print('o est dans le mot:', 'o' in word)