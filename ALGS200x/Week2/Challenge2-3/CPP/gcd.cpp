
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

void run_tests()
{
  assert(gcd(1, 5) == 1);
  assert(gcd(2, 4) == 2);
  assert(gcd(6, 15) == 3);
  assert(gcd(15, 6) == 3);
  assert(gcd(11, 1001) == 11);
  std::cout << "All tests pass." << std::endl;
}

int main()
{
  //run_tests();
  long a, b;
  while (std::cin >> a && std::cin >> b)
  {
    std::cout << gcd(a, b) << std::endl;
  }
}
