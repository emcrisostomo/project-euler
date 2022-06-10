//
// Created by Enrico Maria Crisostomo on 2018-12-21.
//

#ifndef PROJECT_EULER_FACTORIAL_H
#define PROJECT_EULER_FACTORIAL_H

namespace emc
{
namespace factorial
{
template<typename T, typename R>
R of(const T& n)
{
  if (n <= 1) return 1;

  return n * factorial::of<T, R>(n - 1);
}

template<typename T>
T of(const T& n)
{
  return factorial::of<T, T>(n);
}
}
}

#endif //PROJECT_EULER_FACTORIAL_H
