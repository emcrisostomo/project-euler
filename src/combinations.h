//
// Created by enrico.m.crisostomo on 31/12/2019.
//

#ifndef PROJECT_EULER_COMBINATIONS_H
#define PROJECT_EULER_COMBINATIONS_H

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

namespace combinations
{
std::vector<bool> init(size_t k, size_t n);

template<typename T>
std::vector<T> get(const std::vector<T>& set, std::vector<bool>& combination_mask);

bool next(std::vector<bool>& combination_mask);

template<typename T, typename R = T>
R binom(T n, T r);

template<typename T>
std::vector<T>
get_masked_elements(const std::vector<T>& elements, const std::vector<bool>& mask);

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

template<typename T, typename R>
R binom(T n, T r)
{
  static std::map<std::pair<T, T>, R> cache;

  if (n < 0 || r < 0) throw std::runtime_error("n and r must be positive");

  if (r > n) return 0;
  if (r == n) return 1;

  const auto& pair = std::make_pair(n, r);

  if (cache.find(pair) == cache.end())
    cache[pair] = binom<T, R>(n - 1, r) + binom<T, R>(n - 1, r - 1);

  return cache[pair];
}

template<typename T>
std::vector<T>
get_masked_elements(const std::vector<T>& elements, const std::vector<bool>& mask)
{
  assert(elements.size() == mask.size());

  std::vector<T> ret;
//  ret.reserve(mask.size());

  for (auto i = 0; i < mask.size(); ++i)
  {
    if (mask[i])
      ret.push_back(elements[i]);
    if (ret.size() == 5)
      break;
  }

  return ret;
}
}

#endif //PROJECT_EULER_COMBINATIONS_H
