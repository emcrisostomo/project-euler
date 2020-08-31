#include <iostream>
#include <cmath>

// All square roots are periodic when written as continued fractions and can be
// written in the form:
//
//   \sqrt{N} = a_0 + \frac{1}{a_1 + \frac{1}{a_2 + \dots}}
//
// How many continued fractions for \(N \leq 10000\) have an odd period?
int
main(int argc, char *argv[])
{
  // Let's assume we have:
  //
  //   f_n = \frac{\sqrt{S} + m_n}{d_n}
  //
  // Then, a_{n+1} = \right\floor \frac{\sqrt(S) + m_n}{a_n} \left\floor
  // If we then rewrite the previous one:
  //
  //  a_{n+1} + \frac{\sqrt{S} + m_n}{d_n} - a_{n+1}
  //    = a_{n+1} + \frac{\sqrt{S} + m_n - a_{n+1} d_n}{d_n}
  //
  // Let's write
  //
  //   m_{n+1} = a_{n+1} d_n - m_n
  //
  // then
  //
  //   a_{n+1} + \frac{\sqrt{S} - m_{n+1}}{d_n}
  //
  // Since the second term is < 1, let's rewrite it as
  //
  //   a_{n+1} + \frac{1}{\frac{d_n}{\sqrt{S} - m_{n+1}}}
  //
  // Multiplying both numerator and denominator by \sqrt{S} + m_{n+1} yields
  //
  //   a_{n+1} + \frac{1}{\frac{d_n (\sqrt{S} + m_{n+1})}{S - m_{n+1}^2}}
  //
  // If we write
  //
  //   d_{n+1} = \frac{S - m_{n+1}^2}{d_n}
  //
  // we get
  //
  //   a_{n+1} + \frac{1}{\frac{\sqrt{S} + m_{n+1}}{d_{n+1}}
  //   a_{n+1} + \frac{1}{f_{n+1}}
  //
  // Hence, we can use the recursive expressions for a, d and m.
  // It can be shown that the period ends when a_n == 2 a_0.
  //
  size_t count{0};

  for (int i = 2; i <= 10000; ++i)
  {
    int root = sqrt(i);
    size_t period{0};
    if (root * root == i) continue;

    int m{0};
    // I haven't proved that d \in N
    int d{1};
    int a{root};

    do
    {
      m = a * d - m;
      d = (i - (m * m)) / d;
      a = (root + m) / d;
      ++period;
    } while (a != 2 * root);

    if (period % 2 != 0) ++count;
  }

  std::cout << count << '\n';
}
