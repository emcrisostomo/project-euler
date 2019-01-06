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
  bool is_pandigital(T product, bool zero_included = false, T base = 10)
  {
    unsigned int number_of_digits{0};
    std::vector<bool> digits(base, false);

    number::find_digits(product, digits, &number_of_digits);

    if (zero_included && !digits[0]) return false;

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

  bool is_pentagonal(unsigned long number)
  {
    // The n-th pentagonal number is p_n:
    //
    //   p_n = n (3n - 1) / 2
    //       = (3n^2 - n) / 2
    //   =>
    //   3n^2 - n - 2p_n = 0
    //   =>
    //   n = (1 +- sqrt(1 + 24p_n)) / 6
    //
    // Since n \in N, only the positive solution is valid and is equivalent to:
    //
    //   (sqrt(1 + 24p_n) \in N) \and (1 + sqrt(1 + 24p_n) \equiv 0 (mod 6)
    auto s = std::sqrt(1 + 24 * number);

    return std::fmod(s, 6) == 5;
  }

  bool is_hexagonal(unsigned long number)
  {
    // The n-th hexagonal number is h_n:
    //
    //   h_n = n (2n - 1)
    //       = 2n^2 - n
    //   =>
    //   2n^2 - n - h_n = 0
    //   =>
    //   n = (1 +- sqrt(1 + 8h_n) ) / 4
    //
    // Since n \in N, then:
    //
    //   1 + sqrt(1 + 8h_n) \equiv 0 (mod 4)
    //   =>
    //   sqrt(1 + 8h_n) \equiv 3 (mod 4)
    auto s = std::sqrt(1 + 8 * number);

    return std::fmod(s, 4) == 3;
  }

  bool is_palindrome(unsigned long n, unsigned int base = 10)
  {
    unsigned long reversed{0};
    auto num = n;

    while (num != 0)
    {
      auto u = num % base;
      num /= base;
      reversed *= base;
      reversed += u;
    }

    return (n == reversed);
  }
}

#endif //PROJECT_EULER_NUMBER_H
