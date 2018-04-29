# python3

import sys

def fib(n):
    a, b = 0, 1
    count = 0
    while count < n:
        count = count + 1
        a, b = b, a + b
        a = a % 10
        b = b % 10
    return a

def run_tests():
    assert fib(0) == 0
    assert fib(1) == 1
    assert fib(2) == 1
    assert fib(3) == 2
    assert fib(5) == 5
    assert fib(7) == 3
    print("All tests pass.")

#run_tests()

if __name__ == "__main__":
    while True:
        try:
            n = int(input())
            print(fib(n))
        except EOFError:
            break
