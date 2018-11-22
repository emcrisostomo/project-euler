#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void reduce(std::vector<std::vector<unsigned long>>& vector);

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
int main()
{
  std::fstream infile("p067_triangle.txt");
  std::string line;
  std::vector<std::vector<unsigned long>> triangle;

  while (std::getline(infile, line))
  {
    std::istringstream iss(line);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());

    std::vector<unsigned long> row(results.size());

    for (const auto& r : results)
    {
      row.push_back(std::stoul(r, nullptr, 10));
    }

    triangle.push_back(row);
  }

  std::cout << triangle[0][0] << "\n";

  while (triangle.size() > 1)
    reduce(triangle);

  std::cout << triangle[0][0] << "\n";
  return 0;
}

void reduce(std::vector<std::vector<unsigned long>>& vector)
{
  if (vector.empty())
  {
    vector.push_back({0});
    return;
  }

  if (vector.size() == 1) return;

  const auto& removed = vector.back();
  vector.pop_back();
  auto& last = vector.back();

  for (auto i = 0; i < last.size(); ++i)
  {
    last[i] += std::max(removed[i], removed[i + 1]);
  }
}



