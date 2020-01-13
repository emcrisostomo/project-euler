#include <iostream>

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
  size_t count{0};
  std::cout << count << '\n';

  return 0;
}
