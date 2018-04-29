/*
 * Compute fib(0) + ... + fib(n) % 10.
 *
 * The key is that fib(0) + ... + fib(n) = fib(n+2) - 1.
 */

#include <iostream>
#include <cassert>
#include <set>
#include <vector>

long compute_period(long mod)
{
  // To use unordered_set would be faster, but then it is necessary
  // to implement a hash function for <std::vector<long>>
  // If desired, that can be done: https://stackoverflow.com/a/29855973/1141805
  std::set<std::vector<long>> seen;
  long period = 0;
  long a = 0;
  long b = 1;
  long tmp;
  while (seen.count({a, b}) == 0)
  {
    period++;
    seen.insert({a, b});
    tmp = a;
    a = b;
    b = (a + tmp) % mod;
    //std::cout << a << " " << b << std::endl;
  }
  //std::cout << period << std::endl;
  return period;
}

long naive_fib_mod(long num, long mod)
{
  long a = 0;
  long b = 1;
  long count = 0;
  long tmp;
  while (count++ < num)
  {
    tmp = a;
    a = b;
    b = (tmp + a) % mod;
  }
  return a;
}

long fast_fib_mod(long num, long mod)
{
  long period = compute_period(mod);
  num = num % period;
  return naive_fib_mod(num, mod);
}

int main()
{
  //run_tests();
  long num, ans;
  while (std::cin >> num)
  {
    ans = (fast_fib_mod(num+2, 10) + 9) % 10;
    std::cout << ans << std::endl;
  }
}
