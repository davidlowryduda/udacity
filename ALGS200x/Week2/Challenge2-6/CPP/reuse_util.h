#include <iostream>
#include <set>
#include <vector>

long compute_period(long mod);
// Compute the Pisano period modulo 'mod'

long naive_fib_mod(long num, long mod);
// Compute fib(num) % mod naively

long fast_fib_mod(long num, long mod);
// Compute fib(num) % mod quickly, using Pisano periods
