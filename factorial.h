//
// Created by Enrico Maria Crisostomo on 2018-12-21.
//

#ifndef PROJECT_EULER_FACTORIAL_H
#define PROJECT_EULER_FACTORIAL_H

template <typename T>
T factorial(const T& n)
{
  if (n <= 1) return 1;

  return n * factorial<T>(n - 1);
}

#endif //PROJECT_EULER_FACTORIAL_H
