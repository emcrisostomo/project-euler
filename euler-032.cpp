#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include "number.h"

void process_range(unsigned int min0,
                   unsigned int max0,
                   unsigned int min1,
                   unsigned int max1,
                   std::set<unsigned long>& pandigital_products);

// We shall say that an n-digit number is pandigital if it makes use of all the
// digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
// through 5 pandigital.
//
// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
// multiplicand, multiplier, and product is 1 through 9 pandigital.
//
// Find the sum of all products whose multiplicand/multiplier/product identity
// can be written as a 1 through 9 pandigital.
//
// HINT: Some products can be obtained in more than one way so be sure to only
// include it once in your sum.
//
int main()
{
  std::set<unsigned long> pandigital_products;

  process_range(2, 9, 1234, 9876, pandigital_products);
  process_range(12, 98, 123, 987, pandigital_products);

  std::cout << std::accumulate(pandigital_products.begin(), pandigital_products.end(), 0ul) << "\n";

  return 0;
}

void process_range(unsigned int min0,
                   unsigned int max0,
                   unsigned int min1,
                   unsigned int max1,
                   std::set<unsigned long>& pandigital_products)
{
  for (unsigned int i = min0; i <= max0; ++i)
  {
    for (unsigned int j = min1; j <= max1; ++j)
    {
      unsigned long product = i * j;
      auto digits = number::digits_in_number(i)
                    + number::digits_in_number(j)
                    + number::digits_in_number(product);

      if (digits < 9) continue;
      if (digits > 9) break;

      if (number::is_pandigital((unsigned long) i,
                                (unsigned long) j,
                                product))
        pandigital_products.insert(product);
    }
  }
}
