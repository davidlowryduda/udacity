/*
 * Compute fib(0) + ... + fib(n) % 10.
 *
 * The key is that fib(0) + ... + fib(n) = fib(n+2) - 1.
 */

#include <iostream>
#include "reuse_util.h"

int main()
{
  long num, ans;
  while (std::cin >> num)
  {
    ans = (fast_fib_mod(num+2, 10) + 9) % 10;
    std::cout << ans << std::endl;
  }
}
