#include <iostream>
#include <vector>
#include <set>
#include <numeric>

bool is_pandigital(unsigned int i, unsigned int j, unsigned long product);
void find_digits(unsigned long number, std::vector<bool>& digits);
void process_range(unsigned int min0,
                   unsigned int max0,
                   unsigned int min1,
                   unsigned int max1,
                   std::set<unsigned long>& pandigital_products);

template<class T>
unsigned int digits_in_number(T number)
{
  unsigned int digits = 0;
  if (number < 0) digits = 1; // remove this line if '-' counts as a digit

  while (number)
  {
    number /= 10;
    digits++;
  }

  return digits;
}

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
      auto digits = digits_in_number(i) + digits_in_number(j) + digits_in_number(product);

      if (digits < 9) continue;
      if (digits > 9) break;

      if (is_pandigital(i, j, product)) pandigital_products.insert(product);
    }
  }
}

bool is_pandigital(unsigned int i, unsigned int j, unsigned long product)
{
  std::vector<bool> digits(10, false);
  digits[0] = true;

  find_digits(i, digits);
  find_digits(j, digits);
  find_digits(product, digits);

  for (const auto d : digits) if (!d) return false;

  return true;
}

void find_digits(unsigned long number, std::vector<bool>& digits)
{
  while (number)
  {
    digits[number % 10] = true;
    number /= 10;
  }
}
