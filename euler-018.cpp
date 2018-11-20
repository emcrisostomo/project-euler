#include <iostream>
#include <vector>

unsigned long exp_two(unsigned int exponent);

void reduce(std::vector<std::vector<unsigned int>>& vector);

// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//
//    3
//   7 4
//  2 4 6
// 8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom of the triangle below:
//
//                             75
//                           95  64
//                         17  47  82
//                       18  35  87  10
//                     20  04  82  47  65
//                   19  01  23  75  03  34
//                 88  02  77  73  07  63  67
//               99  65  04  28  06  16  70  92
//             41  41  26  56  83  40  80  70  33
//           41  48  72  33  47  32  37  16  94  29
//         53  71  44  65  25  43  91  52  97  51  14
//       70  11  33  28  77  73  17  78  39  68  17  57
//     91  71  52  38  17  14  91  43  58  50  27  29  48
//   63  66  04  68  89  53  67  30  73  16  69  87  40  31
// 04  62  98  27  23  09  70  98  73  93  38  53  60  04  23
//
int main()
{
  std::vector<std::vector<unsigned int>> triangle;
  triangle.push_back({75});
  triangle.push_back({95, 64});
  triangle.push_back({17, 47, 82});
  triangle.push_back({18, 35, 87, 10});
  triangle.push_back({20, 04, 82, 47, 65});
  triangle.push_back({19, 01, 23, 75, 03, 34});
  triangle.push_back({88, 02, 77, 73, 07, 63, 67});
  triangle.push_back({99, 65, 04, 28, 06, 16, 70, 92});
  triangle.push_back({41, 41, 26, 56, 83, 40, 80, 70, 33});
  triangle.push_back({41, 48, 72, 33, 47, 32, 37, 16, 94, 29});
  triangle.push_back({53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14});
  triangle.push_back({70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57});
  triangle.push_back({91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48});
  triangle.push_back({63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31});
  triangle.push_back({04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23});

  while (triangle.size() > 1)
    reduce(triangle);

  std::cout << triangle[0][0] << "\n";
  return 0;
}

void reduce(std::vector<std::vector<unsigned int>>& vector)
{
  if (vector.size() == 1) return;

  const auto& removed = vector.back();
  vector.pop_back();
  auto& last = vector.back();

  for (auto i = 0; i < last.size(); ++i)
  {
    last[i] += std::max(removed[i], removed[i + 1]);
  }
}



