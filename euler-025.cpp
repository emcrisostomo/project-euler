#include <iostream>
#include <gmpxx.h>

// The Fibonacci sequence is defined by the recurrence relation:
//
// Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
// Hence the first 12 terms will be:
//
// F1 = 1
// F2 = 1
// F3 = 2
// F4 = 3
// F5 = 5
// F6 = 8
// F7 = 13
// F8 = 21
// F9 = 34
// F10 = 55
// F11 = 89
// F12 = 144
// The 12th term, F12, is the first term to contain three digits.
//
// What is the index of the first term in the Fibonacci sequence to contain
// 1000 digits?
//
int main()
{
  mpz_class limit = 10;
  mpz_pow_ui(limit.get_mpz_t(), limit.get_mpz_t(), 999);

  mpz_class ring[3];
  ring[0] = 0;
  ring[1] = 1;
  ring[2] = 1;
  unsigned int i = 2;

  while (true)
  {
    ++i;
    ring[i % 3] = ring[(i - 1) % 3] + ring[(i - 2) % 3];

    if (ring[i % 3] >= limit) break;
  }

  std::cout << i << "\n";
  return 0;
}
