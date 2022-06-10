#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "number.h"

using cube_key_freq = struct cube_key_freq
{
  unsigned short freq;
  uint64_t min_cube;
};

// The cube, 41063625 (345^3), can be permuted to produce two other cubes:
// 56623104 (384^3) and 66430125 (405^3).  In fact, 41063625 is the smallest
// cube which has exactly three permutations of its digits which are also cube.
//
// Find the smallest cube for which exactly five permutations of its digits are
// cube.
//
int
main(int argc, char *argv[])
{
  std::map<uint64_t, cube_key_freq> cube_key_frequencies;

  // n^3 will overflow when n \approx 2^20 when using 64-bit integers.
  for (uint64_t i = 10; i < 2000000; ++i)
  {
    uint64_t cube = i * i * i;

    std::vector<unsigned short> digits = number::get_digits(cube);
    std::sort(digits.begin(), digits.end());
    uint64_t cube_key = number::number_from_digits<unsigned short, uint64_t>(digits);

    const auto& pos = cube_key_frequencies.find(cube_key);
    if (pos == cube_key_frequencies.end())
    {
      cube_key_frequencies[cube_key] = {1, i};
    }
    else
    {
      cube_key_freq& ckf = cube_key_frequencies[cube_key];
      ++ckf.freq;
      ckf.min_cube = std::min(ckf.min_cube, i);

      if (ckf.freq == 5)
      {
        std::cout << (ckf.min_cube * ckf.min_cube * ckf.min_cube) << '\n';
        break;
      }
    }
  }
}
