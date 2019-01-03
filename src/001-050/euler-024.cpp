#include <iostream>
#include <vector>
#include <algorithm>

std::vector<unsigned int> to_lehmer_code(unsigned long n, size_t elements);
std::vector<unsigned long> build_base(size_t elements);
std::vector<unsigned int> to_permutation(const std::vector<unsigned int>& lehmer_code);

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

  // To avoid iterating through all the permutations, we can find the one
  // million-th permutation by:
  //
  //   - Converting 999.999 to the factorial number system.
  //   - Decoding the resulting Lehmer code to the mapped permutation.
  std::vector<unsigned int> lehmer_code = to_lehmer_code(999999, permutation.size());
  std::vector<unsigned int> perm = to_permutation(lehmer_code);
  std::reverse(perm.begin(), perm.end());

  for (const auto& d : perm)
    std::cout << d;

  std::cout << "\n";

  return 0;
}

std::vector<unsigned int> to_permutation(const std::vector<unsigned int>& lehmer_code)
{
  std::vector<unsigned int> perm = lehmer_code;

  for (auto i = 0; i < perm.size(); ++i)
  {
    for (long j = i - 1; j >= 0; --j)
    {
      if (perm[j] >= perm[i]) ++perm[j];
    }
  }

  return perm;
}

std::vector<unsigned int> to_lehmer_code(unsigned long n, size_t elements)
{
  std::vector<unsigned long> base = build_base(elements);
  std::vector<unsigned int> lehmer_code;
  lehmer_code.push_back(0);

  for (auto i = 1; i < base.size(); ++i)
  {
    auto d = n % base[i];
    n /= base[i];

    lehmer_code.push_back(d);
  }

  return lehmer_code;
}

std::vector<unsigned long> build_base(size_t elements)
{
  std::vector<unsigned long> base;

  for (unsigned long i = 1; i <= elements; ++i)
    base.push_back(i);

  return base;
}
