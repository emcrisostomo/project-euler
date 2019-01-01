//
// Created by enrico on 12/26/18.
//

#ifndef PROJECT_EULER_NUMBER_H
#define PROJECT_EULER_NUMBER_H

#include <stdexcept>
#include <vector>
#include <cmath>

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
  void find_digits(T number,
                   std::vector<bool>& digits,
                   unsigned int *number_of_digits,
                   T base = 10)
  {
    unsigned int digits_num{0};

    while (number)
    {
      digits[number % base] = true;
      number /= base;
      ++digits_num;
    }

    if (number_of_digits != nullptr) *number_of_digits = digits_num;
  }

  template<typename T>
  std::vector<unsigned short> get_digits(T number, T base = 10)
  {
    std::vector<unsigned short> digits;

    while (number)
    {
      digits.push_back(number % base);
      number /= base;
    }

    return digits;
  }

  template<typename T>
  bool is_pandigital(T product, T base = 10)
  {
    unsigned int number_of_digits{0};
    std::vector<bool> digits(base, false);
    digits[0] = true;

    number::find_digits(product, digits, &number_of_digits);

    for (auto i = number_of_digits + 1; i < digits.size(); ++i)
      if (digits[i]) return false;

    for (auto i = 1; i <= number_of_digits; ++i)
      if (!digits[i]) return false;

    return true;
  }

  bool is_perfect_square(unsigned long n)
  {
    unsigned long r{static_cast<unsigned long>(std::round(std::sqrt(n)))};

    return (n == r * r);
  }

  bool is_triangular(unsigned int number)
  {
    // The n-th triangular number is t_n:
    //
    //   t_n = n(n+1)/2
    //
    // This is a second degree equation in n.  Solving it yields only one valid
    // solution for n > 0:
    //
    //   n = (-1 +- sqrt(1+8t))/2
    //
    // Since n is integer, sqrt(1+8t) must be integer as well.
    unsigned int n = 8 * number + 1;

    return number::is_perfect_square(n);
  }
}

#endif //PROJECT_EULER_NUMBER_H
