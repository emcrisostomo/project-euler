#include <iostream>
#include <vector>
#include <exception>

unsigned int get_days_in_month(unsigned int m, bool is_leap);

// You are given the following information, but you may prefer to do some
// research for yourself.
//
//   * 1 Jan 1900 was a Monday.
//   * Thirty days has September,
//     April, June and November.
//     All the rest have thirty-one,
//     Saving February alone,
//     Which has twenty-eight, rain or shine.
//     And on leap years, twenty-nine.
//   * A leap year occurs on any year evenly divisible by 4, but not on a
//     century unless it is divisible by 400.
//
// How many Sundays fell on the first of the month during the twentieth century
// (1 Jan 1901 to 31 Dec 2000)?
//
int main()
{
  // Sunday = 0
  unsigned int sundays{0};
  unsigned int current_day{1};
  current_day += 365;

  for (auto y = 1901; y <= 2000; ++y)
  {
    const bool is_leap = ((y % 4 == 0) && (y % 100 != 0 || y % 400 == 0));

    for (unsigned int m = 0; m < 12; ++m)
    {
      if (current_day % 7 == 0) ++sundays;

      current_day += get_days_in_month(m, is_leap);
      current_day -= (current_day / 7) * 7;
    }
  }

  std::cout << sundays << "\n";
  return 0;
}

unsigned int get_days_in_month(unsigned int m, const bool is_leap)
{
  switch (m)
  {
  case 0:
    return 31;
  case 1:
    return is_leap ? 29 : 28;
  case 2:
    return 31;
  case 3:
    return 30;
  case 4:
    return 31;
  case 5:
    return 30;
  case 6:
    return 31;
  case 7:
    return 31;
  case 8:
    return 30;
  case 9:
    return 31;
  case 10:
    return 30;
  case 11:
    return 31;
  default:
    throw std::runtime_error("Invalid month");
  }
}


