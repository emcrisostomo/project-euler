#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "../number.h"

bool is_triangular_word(std::string word);

// The nth term of the sequence of triangle numbers is given by
//
//   t_n = n(n+1)/2
//
// So the first ten triangle numbers are:
//
//   1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
// By converting each letter in a word to a number corresponding to its
// alphabetical position and adding these values we form a word value.  For
// example, the word value for SKY is 19 + 11 + 25 = 55 = t10.  If the word
// value is a triangle number then we shall call the word a triangle word.
//
// Using words.txt, a 16K text file containing nearly two-thousand common
// English words, how many are triangle words?
//
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments: " << argc << "\n";
    return 1;
  }

  std::fstream infile(argv[1]);

  if (!infile.is_open())
  {
    std::cerr << "Cannot open file: " << argv[1] << "\n";
    return 1;
  }

  unsigned int count{0};
  std::string line;

  while (std::getline(infile, line, ','))
  {
    line = line.substr(1, line.size() - 2);
    if (is_triangular_word(line)) ++count;
  }

  std::cout << count << "\n";

  return 0;
}

bool is_triangular_word(std::string word)
{
  unsigned int value{0};

  for (const auto& c : word)
  {
    value += c - 'A' + 1;
  }

  return number::is_triangular(value);
}
