#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time

def afficher_temps(fonction):
    def fonction_modifiee():
        print("%" * 80)
        t_depart = time.clock()
        valeur_retournee = fonction()
        t_fin = time.clock()
        print("%" * 80)
        print("Temps écoulé : {}".format(t_fin - t_depart))
        return valeur_retournee
    return fonction_modifiee
