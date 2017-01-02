#/usr/bin/env python3
# -*- coding: utf-8 -*-

from time import time
from math import ceil

def main():
    n = int(input()) - 1
    pr = (input() != "0")

    size = int(ceil((n - 3) / 2) + 1)

    tab = [True] * size
    prime_list = [2]

    t_start = time()

    for i in range(size):
        if tab[i]:
            current_nb = 2 * i + 3
            prime_list.append(current_nb)
            for k in range(i + current_nb, size, current_nb):
                tab[k] = False

    t_end = time()

    print("Time: " + str(t_end - t_start))

    if pr:
        print(prime_list)
    else:
        print(prime_list[-1])

if __name__ == "__main__":
    main()
