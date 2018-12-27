//
// Created by enrico on 12/26/18.
//

#ifndef PROJECT_EULER_NUMBER_H
#define PROJECT_EULER_NUMBER_H

#include <stdexcept>

namespace number
{
  template<typename T>
  T truncate_lsd(T n, T base = 10)
  {
    if (n < base) throw std::runtime_error("");

    return n / base;
  }

  template<typename T>
  T truncate_msd(T n, T base = 10)
  {
    if (n < base) throw std::runtime_error("");

    T m{base};

    while (m <= n)
    {
      m *= base;
    }

    m /= base;

    return n % m;
  }

  template<class T>
  unsigned int digits_in_number(T number, T base = 10)
  {
    unsigned int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit

    while (number)
    {
      number /= base;
      digits++;
    }

    return digits;
  }

  template<typename T>
  void find_digits(T number, std::vector<bool>& digits, T base = 10)
  {
    while (number)
    {
      digits[number % base] = true;
      number /= base;
    }
  }

  template<typename T>
  bool is_pandigital(T product, T base = 10)
  {
    std::vector<bool> digits(base, false);
    digits[0] = true;

    number::find_digits(product, digits);

    for (const auto d : digits) if (!d) return false;

    return true;
  }

  template<typename T>
  bool is_pandigital(T i, T j, T product)
  {
    std::vector<bool> digits(10, false);
    digits[0] = true;

    find_digits(i, digits);
    find_digits(j, digits);
    find_digits(product, digits);

    for (const auto d : digits) if (!d) return false;

    return true;
  }
}

#endif //PROJECT_EULER_NUMBER_H
