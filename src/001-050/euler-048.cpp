#include <iostream>

unsigned long pow_mod_n(unsigned long base, unsigned long exp, unsigned long mod);

// The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
//
// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
//
int main(int argc, char *argv[])
{
  unsigned long sum{0};

  for (unsigned long i = 1; i <= 1000; ++i)
  {
    sum += pow_mod_n(i, i, 10000000000);
  }

  std::cout << sum % 10000000000 << "\n";
  return 0;
}

unsigned long pow_mod_n(unsigned long base, unsigned long exp, unsigned long mod)
{
  unsigned long pow{1};

  for (auto i = 0; i < exp; ++i)
  {
    pow *= (base % mod);
    pow %= mod;
  }

  return pow;
}
