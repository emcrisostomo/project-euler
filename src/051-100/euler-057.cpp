#include <iostream>
#include <gmpxx.h>
#include "number.h"

// It is possible to show that the square root of two can be expressed as an
// infinite continued fraction.
//
// \sqrt{2} = 1 + \frac{1}{2 + \frac{1}{2 + \frac{\dots}}}
//
// By expanding this for the first four iterations, we get:
//
// 1 + \frac{1}{2} = \frac{3}{2} = 1.5
// 1 + \frac{1}{2 + \frac{1}{2}} = \frac{7}{5} = 1.4
// 1 + \frac{1}{2 + \frac{1}{2 + \frac{1}{2 + \frac{1}{2}}}} = \frac{17}{12} = 1.41666\dots
//
// The next three expansions are \frac{99}{70}, \frac{239}{169}, and
// \frac{577}{408}, but the eighth expansion, \frac{1393}{985}, is the first
// example where the number of digits in the numerator exceeds the number of
// digits in the denominator.
//
// In the first one-thousand expansions, how many fractions contain a numerator
// with more digits than the denominator?
//
int main(int argc, char *argv[])
{
  // The series can be expressed recursively as:
  //
  //   f_{k + 1} = 1 + \frac{1}{1 + f_k}
  //
  // If f_k = n_k/d_k, we have:
  //
  //   f_{k + 1} = 1 + \frac{1}{1 + {\frac{n_k}{d_k}}
  //             = 1 + \frac{1}{{\frac{n_k + d_k}{d_k}}
  //             = 1 + \frac{d_k}{n_k + d_k}}
  //             = \frac{n_k + 2 d_k}{n_k + d_k}
  //
  // Hence a recursive formula can be given for both the numerator and the
  // denominator:
  //
  //   n_{k+1} = n_k + 2 d_k
  //   d_{k+1} = n_k + d_k
  //
  size_t count{0};

  mpz_class nk{3};
  mpz_class dk{2};

  for (auto i=0; i < 1000; ++i)
  {
    auto nk_copy {nk};
    nk = nk + 2 * dk;
    dk = nk_copy + dk;

    if (nk.get_str(10).size() > dk.get_str(10).size()) ++count;
  }

  std::cout << count << '\n';

  return 0;
}
