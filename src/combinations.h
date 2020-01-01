//
// Created by enrico.m.crisostomo on 31/12/2019.
//

#ifndef PROJECT_EULER_COMBINATIONS_H
#define PROJECT_EULER_COMBINATIONS_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace combinations
{
std::vector<bool> init(size_t k, size_t n);

template<typename T>
std::vector<T> get(const std::vector<T>& set, std::vector<bool>& combination_mask);

bool next(std::vector<bool>& combination_mask);

std::vector<bool> init(size_t k, size_t n)
{
  if (k <= 0) throw std::runtime_error("k must be greater than 0");
  if (k > n) throw std::runtime_error("n must be greater than or equal to n");

  std::vector<bool> combination_mask(k, true);
  combination_mask.resize(n, false);

  return combination_mask;
}

template<typename T>
std::vector<T> get(const std::vector<T>& set, std::vector<bool>& combination_mask)
{
  std::vector<T> ret;

  for (int i = 0; i < set.size(); ++i)
  {
    if (combination_mask[i]) ret.push_back(set[i]);
  }
  return ret;
}

bool next(std::vector<bool>& combination_mask)
{
  return std::prev_permutation(combination_mask.begin(), combination_mask.end());
}
}

#endif //PROJECT_EULER_COMBINATIONS_H
