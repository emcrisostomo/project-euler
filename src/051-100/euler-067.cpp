#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
#include "triangle.h"

// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//
//    3
//   7 4
//  2 4 6
// 8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom in triangle.txt, a 15K text file
// containing a triangle with one-hundred rows.
//
int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of arguments: " << argc << "\n";
    return 1;
  }

  std::fstream infile(argv[1]);
  std::string line;
  std::vector<std::vector<unsigned long>> triangle;

  while (std::getline(infile, line))
  {
    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    std::vector<unsigned long> row;
    row.reserve(results.size());

    for (const auto& r : results)
    {
      row.push_back(std::stoul(r, nullptr, 10));
    }

    triangle.push_back(row);
  }

  while (triangle.size() > 1)
    triangle::reduce_max_path(triangle);

  if (triangle.empty() || triangle[0].empty())
    return 2;

  std::cout << triangle[0][0] << "\n";
  return 0;

}
