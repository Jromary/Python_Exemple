#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from math import sqrt, ceil
from time import clock
from sys import argv

def main():
    assert len(argv) > 1
    n = int(argv[1])
    liste_diviseurs = []

    t_depart = clock()

    puissance_2 = 0
    while n % 2 == 0:
        puissance_2 += 1
        n //= 2

    if puissance_2:
        liste_diviseurs.append((2, puissance_2))

    i = 3
    while n > 1:
        trouve_diviseur = False
        limite = int(sqrt(n))
        while i <= limite and not trouve_diviseur:
            if n % i == 0:
                trouve_diviseur = True
                puissance_i = 0
                while n % i == 0:
                    puissance_i += 1
                    n //= i
                liste_diviseurs.append((i, puissance_i))
            i += 2
        if not trouve_diviseur:
            liste_diviseurs.append((n, 1))
            n = 1

    t_fin = clock()

    print(" ".join([str(elt) for elt in liste_diviseurs]))
    print("Temps : " + str(t_fin - t_depart))

if __name__ == "__main__":
    main()
