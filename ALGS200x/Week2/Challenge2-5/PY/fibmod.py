#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
Given `n m` on a line, compute fib(n) mod m.
'''
import sys

def compute_period(mod):
    '''Compute the Pisano period modulo `mod`'''
    seen = set()
    period = 0
    a = 0
    b = 1
    while (a, b) not in seen:
        period = period + 1
        seen.add((a, b))
        a, b = b, ((a + b) % mod)
    return period

def fib_mod(num, mod):
    '''naive computation for testing'''
    a, b = 0, 1
    count = 0
    while count < num:
        count = count + 1
        a, b = b, ((a + b) % mod)
    return a

def fib_mod_m(num, mod):
    '''compute fib(num) module mod'''
    period = compute_period(mod)
    num = num % period
    return fib_mod(num, mod)

def get_input():
    line = sys.stdin.readline()
    if not line:
        raise EOFError
    a, b = [int(x) for x in line.split()]
    return a, b

def run_tests():
    '''basic tests'''
    assert compute_period(2) == 3
    assert compute_period(3) == 8
    assert fib_mod_m(3, 3) == fib_mod(3, 3)
    assert fib_mod_m(5, 4) == fib_mod(5, 4)
    print("All tests pass.")

if __name__ == "__main__":
    #run_tests()
    while True:
        try:
            num, mod = get_input()
            print(fib_mod_m(num, mod))
        except EOFError:
            break
