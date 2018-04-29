
#include <iostream>
#include <cassert>

int fib(int n)
{
  if (n <= 1)
  {
    return n;
  }
  long long a, b, count, tmp;
  count = 0;
  a = 0;
  b = 1;
  while (count++ < n)
  {
    tmp = a;
    a = b;
    b = tmp + a;
  }
  return a;
}

void run_tests()
{
  assert(fib(0) == 0);
  assert(fib(1) == 1);
  assert(fib(3) == 2);
  assert(fib(5) == 5);
  assert(fib(10) == 55);
  std::cout << "All tests pass." << std::endl;
  return;
}

int main()
{
  //run_tests();
  long long n;
  while (std::cin >> n)
  {
    std::cout << fib(n) << std::endl;
  }
}
