#!/usr/bin/env python3

import sys

def gcd(a, b):
    '''Returns the gcd of a and b'''
    if a > b:
        a, b = b, a
    while a != 0:
        b, a = a, (b % a)
    return b

def get_input():
    line = sys.stdin.readline()
    if not line:
        raise EOFError
    a, b = [int(x) for x in line.split()]
    return a, b

def run_tests():
    '''Test gcd'''
    assert gcd(1, 5) == 1
    assert gcd(2, 4) == 2
    assert gcd(6, 15) == 3
    assert gcd(15, 6) == 3
    assert gcd(11, 1001) == 11
    print("All tests pass.")
    return

#run_tests()

if __name__ == "__main__":
    while True:
        try:
            a, b = get_input()
            print(gcd(a, b))
        except EOFError:
            break
