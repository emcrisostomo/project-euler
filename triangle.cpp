//
// Created by enrico on 11/22/18.
//

#include "triangle.h"

void triangle::reduce_max_path(std::vector<std::vector<unsigned long>>& triangle)
{
  if (triangle.empty())
  {
    triangle.push_back({0});
    return;
  }

  if (triangle.size() == 1) return;

  const auto removed = std::move(triangle.back());
  triangle.pop_back();
  auto& last = triangle.back();

  for (auto i = 0; i < last.size(); ++i)
  {
    last[i] += std::max(removed[i], removed[i + 1]);
  }
}