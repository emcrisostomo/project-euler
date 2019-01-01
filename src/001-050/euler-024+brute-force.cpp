#include <iostream>
#include <vector>
#include <algorithm>

void print_permutation(const std::vector<unsigned int>& permutation);

// A permutation is an ordered arrangement of objects.  For example, 3124 is one
// possible permutation of the digits 1, 2, 3 and 4.  If all of the permutations
// are listed numerically or alphabetically, we call it lexicographic order.
// The lexicographic permutations of 0, 1 and 2 are:
//
//   012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
// 5, 6, 7, 8 and 9?
//
int main()
{
  std::vector<unsigned int> permutation = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  unsigned long index{0};

  do
  {
    ++index;
    if (index == 1000000)
    {
      print_permutation(permutation);
      break;
    }
  } while (std::next_permutation(permutation.begin(), permutation.end()));

  return 0;
}

void print_permutation(const std::vector<unsigned int>& permutation)
{
  std::for_each(permutation.begin(),
                permutation.end(),
                [](const auto& n)
                { std::cout << n; });
  std::cout << "\n";
}
