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

  if (number == 0)
  {
    digits.push_back(0);
    return digits;
  }

  digits.reserve((log(number)) / (log(base)) + 1);

  while (number)
  {
    digits.push_back(number % base);
    number /= base;
  }

  return digits;
}

template<typename T, typename R>
R number_from_digits(const std::vector<T>& digits, T base = 10)
{
  R ret{0};

  for (auto i = digits.rbegin(); i != digits.rend(); ++i)
  {
    ret *= base;
    ret += *i;
  }

  return ret;
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

bool is_heptagonal(unsigned long number)
{
  // The n-th heptagonal number is h_n:
  //
  //   h_n = n (5n - 3) / 2
  //       = (5n^2 - 3n) / 2
  //   =>
  //   5n^2 -3n - 2h_n = 0
  //   =>
  //   n = 3 +- sqrt(9 + 40 h_n)
  //       ---------------------
  //                 10
  //
  // Since n \in N, then
  //
  //   3 +- sqrt(9 + 40 h_n) \equiv 0 (mod 10)
  //   =>
  //   sqrt(9 + 40 h_n) \equiv 7 (mod 10)
  auto s = sqrtl(9 + 40 * number);

  return std::fmod(s, 10) == 7;
}

bool is_octagonal(unsigned long number)
{
  // The n-th octagonal number is h_n:
  //
  //   h_n = n (3n - 2)
  //       = 3n^2 - 2n
  //   =>
  //   3n^2 - 2n - h_n = 0
  //   =>
  //   n = 1 +- sqrt(1 + 3 h_n)
  //       --------------------
  //                3
  //
  //  Since n \in N, then
  //
  //    1 +- sqrt(1 + 3 h_n) \equiv 0 (mod 3)
  //    =>
  //    sqrt(1 + 3 h_n) \equiv 2 (mod 3)
  auto s = sqrtl(1 + 3 * number);

  return std::fmod(s, 3) == 2;
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

template<typename T>
void next_number(std::vector<T>& digits)
{
  bool carry = false;

  for (auto i = 0; i < digits.size(); ++i)
  {
    if (carry)
    {
      ++digits[i];
      carry = false;
    }

    ++digits[i];

    if (digits[i] >= 10)
    {
      digits[i] -= 10;
      carry = true;
    }
  }

  if (carry) digits.push_back(1);
}

template<typename T>
T reverse(T i, T base = 10)
{
  const std::vector<unsigned short>& digits = get_digits(i, base);

  return number_from_digits<unsigned short, T>(std::vector<unsigned short>(digits.rbegin(), digits.rend()));
}

bool is_lychrel(unsigned long i)
{
  if (i == 0) return false;

  size_t iterations{0};

  do
  {
    ++iterations;
    i += reverse(i);

    if (is_palindrome(i)) return false;
  } while (iterations < 50);

  return true;
}
}

#endif //PROJECT_EULER_NUMBER_H
