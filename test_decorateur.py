#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Import des modules

import decorateur

# Déclaration des fonctions

# Fonction Main

@decorateur.afficher_temps
def main():
    print("Hello World!")
    total = 0.0
    for i in range(1, 100000 + 1):
        total += i ** 2 / i ** 1.5
    print("Finished!")

# Initialisation de la fonction Main

if __name__ == "__main__":
    main()
