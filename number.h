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

    T num{n};
    T m{1};

    while (num >= base)
    {
      num /= base;
      m *= base;
    }

    return n % m;
  }
}

#endif //PROJECT_EULER_NUMBER_H
