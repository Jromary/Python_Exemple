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

def no_closing_console(fonction):
    def fonction_modifiee():
        valeur_retournee = None
        try:
            valeur_retournee = fonction()
        except:
            print("\n--> Erreur")
        finally:
            input("\nAppuyez sur une touche pour quitter...")
        return valeur_retournee
    return fonction_modifiee

