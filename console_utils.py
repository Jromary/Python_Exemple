#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def no_closing_console(func):
    try:
        func()
    except:
        print("\n---> ERROR\n\n")
    finally:
        input("Press any key to exit... ")
