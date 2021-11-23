#!/bin/python3
import random
import sys

n = int(sys.argv[1])

random.seed()

ar = []

i = 0

while i < n:
    new = random.randint(-n, n)

    if new not in ar:
        ar.append(new)
        i += 1

print('  '.join(map(str, ar)))