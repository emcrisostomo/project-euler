#include <iostream>
#include <cmath>
#include "../prime.h"

bool check_factorizations(std::vector<std::map<unsigned long, unsigned int>> vector);

// The first two consecutive numbers to have two distinct prime factors are:
//
//   14 = 2 × 7
//   15 = 3 × 5
//
// The first three consecutive numbers to have three distinct prime factors are:
//
//   644 = 2^2 × 7 × 23
//   645 = 3 × 5 × 43
//   646 = 2 × 17 × 19.
//
// Find the first four consecutive integers to have four distinct prime factors
// each.  What is the first of these numbers?
//
int main(int argc, char *argv[])
{
  const unsigned short ring_size = 4;
  std::vector<std::map<unsigned long, unsigned int>> factorization_ring(ring_size);

  for (unsigned int p = 2000;; ++p)
  {
    factorization_ring[p % ring_size] = prime::factorize(p);
    if (check_factorizations(factorization_ring))
    {
      std::cout << p - 3 << "\n";
      return 0;
    };
  }
}

bool check_factorizations(std::vector<std::map<unsigned long, unsigned int>> vector)
{
  for (const auto& f : vector) if (f.size() != 4) return false;

  return true;
}
