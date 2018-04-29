/*
 * Given 'n m' on a line, compute fib(n) mod m.
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

void run_tests()
{
  assert(compute_period(2) == 3);
  assert(compute_period(3) == 8);
  assert(fast_fib_mod(3, 3) == naive_fib_mod(3, 3));
  assert(fast_fib_mod(5, 4) == naive_fib_mod(5, 4));
  std::cout << "All tests pass." << std::endl;
}

int main()
{
  //run_tests();
  long a, b;
  while (std::cin >> a && std::cin >> b)
  {
    std::cout << fast_fib_mod(a, b) << std::endl;
  }
}
