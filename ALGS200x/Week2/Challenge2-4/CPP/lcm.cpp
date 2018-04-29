#include <iostream>
#include <cassert>

long gcd(long a, long b)
{
  long tmp;
  // guarantee that b >= a
  if (a > b)
  {
    tmp = b;
    b = a;
    a = tmp;
  }
  // Euclidean algorithm
  while (a != 0)
  {
    tmp = b;
    b = a;
    a = tmp % b;
  }
  return b;
}

long lcm(long a, long b)
{
  return a*b/gcd(a, b);
}

void run_tests()
{
  assert(lcm(1, 3) == 3);
  assert(lcm(6, 15) == 30);
  std::cout << "All tests pass." << std::endl;
}

int main()
{
  //run_tests();
  long a, b;
  while (std::cin >> a && std::cin >> b)
  {
    std::cout << lcm(a, b) << std::endl;
  }
}
