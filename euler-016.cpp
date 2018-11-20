#include <iostream>
#include <cmath>
#include <vector>

unsigned long exp_two(unsigned int exponent);

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?
//
int main()
{
  std::cout << exp_two(1000) << "\n";
  return 0;
}

unsigned long exp_two(unsigned int exponent)
{
  unsigned long sum{0};
  const auto digits = static_cast<unsigned long>(floor(1 + exponent * log(2) / log(10)));
  std::vector<int> product(digits);
  product[0] = 1;
  unsigned int current_msd = 0;

  for (auto i = 0; i < exponent; ++i)
  {
    unsigned int carry{0};

    for (auto d = 0; d <= current_msd; ++d)
    {
      unsigned int current = 2 * product[d] + carry;

      product[d] = current % 10;
      carry = current / 10;
      assert(carry <= 1);
    }

    if (carry > 0) ++current_msd;
    if (current_msd < product.size()) product[current_msd] += carry;
  }

  for (const auto& d : product)
    sum += d;

  return sum;
}


