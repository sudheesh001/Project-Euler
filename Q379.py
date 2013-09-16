#!/usr/bin/env python
import math
from itertools import *
from operator import mul

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def lcm(a, b):
    return (a / gcd(a, b)) * b

def factorize(n):
    res = []
    # iterate over all even numbers first.
    while n % 2 == 0:
        res.append(2)
        n //= 2
    # try odd numbers up to sqrt(n)
    limit = math.sqrt(n+1)
    i = 3
    while i <= limit:
        if n % i == 0:
            res.append(i)
            n //= i
            limit = math.sqrt(n+i)
        else:
            i += 2
    if n != 1:
        res.append(n)
    return res

def f(n):
    s = 0
    for y in range(1, n + 1):
        for x in range(1, y + 1):
            if lcm(x, y) == n:
                s += 1
    return s

def g(n):
    return sum(f(i) for i in range(1, n + 1))

print (g(100))