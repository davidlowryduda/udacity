#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
Compute fib(m) + ... + fib(n) % 10

The key observation is that fib(0) + ... + fib(n) = fib(n+2) - 1. So one computes

    (fib(n+2) - 1) - (fib(m+1) - 1) = fib(n+2) - fib(m+1)     (mod 10)
'''
import sys

## Copied from previous exercise
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
## End copy from previous exercise

def get_input():
    line = sys.stdin.readline()
    if not line:
        raise EOFError
    num1, num2 = [int(x) for x in line.split()]
    return num1, num2

if __name__ == "__main__":
    while True:
        try:
            num1, num2 = get_input()
            ret = (fib_mod_m(num2 + 2, 10) - fib_mod_m(num1 + 1, 10)) % 10
            print(ret)
        except EOFError:
            break
