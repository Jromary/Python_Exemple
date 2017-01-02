#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Import des modules

from random import randint

# Déclaration des fonctions

def tri_pivot(liste):
    n = len(liste)
    elt_tri = liste[randint(0, n - 1)]
    (tab_inf, tab_egal, tab_sup) = ([], [], [])
    for elt in liste:
        if elt < elt_tri:
            tab_inf.append(elt)
        elif elt > elt_tri:
            tab_sup.append(elt)
        else:
            tab_egal.append(elt)
    if len(tab_inf) > 0:
        tab_inf = tri_pivot(tab_inf)
    if len(tab_sup) > 0:
        tab_sup = tri_pivot(tab_sup)
    tab_egal = tab_inf + tab_egal + tab_sup
    return tab_egal

# Fonction Main

def main():
    liste_test = [randint(1, 20) for i in range(20)]
    print(liste_test)
    liste_triee = tri_pivot(liste_test)
    print(liste_triee)
    print(liste_triee == sorted(liste_test))

# Initialisation de la fonction Main

if __name__ == "__main__":
    main()
