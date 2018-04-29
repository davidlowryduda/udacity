#!/usr/bin/env python3

import sys

def gcd(a, b):
    '''Returns the gcd of a and b'''
    if a > b:
        a, b = b, a
    while a != 0:
        b, a = a, (b % a)
    return b

def lcm(a, b):
    '''Returns the lcm of a and b'''
    return a * b // gcd(a, b)

def get_input():
    line = sys.stdin.readline()
    if not line:
        raise EOFError
    a, b = [int(x) for x in line.split()]
    return a, b

def run_tests():
    assert lcm(1, 5) == 5
    assert lcm(2, 4) == 4
    assert lcm(6, 15) == 30
    assert lcm(226553150, 1023473145) == 46374212988031350
    print("All tests pass.")
    return

#run_tests()

if __name__ == "__main__":
    #run_tests()
    while True:
        try:
            a, b = get_input()
            print(lcm(a, b))
        except EOFError:
            break
