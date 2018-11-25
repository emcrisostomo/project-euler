#include <iostream>
#include <vector>
#include <algorithm>

unsigned long find_next_k(const std::vector<unsigned int>& vector);

void print_permutation(const std::vector<unsigned int>& vector);

// A permutation is an ordered arrangement of objects.  For example, 3124 is one possible permutation of the digits 1,
// 2, 3 and 4.  If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
// The lexicographic permutations of 0, 1 and 2 are:
//
//   012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
//
int main()
{
  std::vector<unsigned int> permutation = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  unsigned long k{0};
  unsigned long index{1};

  while ((k = find_next_k(permutation)) < permutation.size())
  {
    ++index;
    unsigned long l = k + 1;
    for (unsigned long i = k + 1; i < permutation.size(); ++i)
    {
      if (permutation[k] < permutation[i]) l = i;
    }

    std::swap(permutation[k], permutation[l]);
    std::reverse(permutation.begin() + k + 1, permutation.end());

    if (index == 1000000) print_permutation(permutation);
  }

  return 0;
}

void print_permutation(const std::vector<unsigned int>& vector)
{
  std::for_each(vector.begin(),
                vector.end(),
                [](const auto& n)
                { std::cout << n; });
  std::cout << "\n";
}

unsigned long find_next_k(const std::vector<unsigned int>& vector)
{
  unsigned long ret = vector.size();

  for (unsigned long k = 0; k < vector.size() - 1; ++k)
  {
    if (vector[k] < vector[k + 1]) ret = k;
  }

  return ret;
}

