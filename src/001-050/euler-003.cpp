
#include <iostream>
#include "../prime.h"
#include <string>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    return 1;
  }

  for (auto i = 1; i < argc; ++i)
  {
    try
    {
      auto n = std::stoull(argv[i]);
      std::cout << prime::largest_prime_factor_of(n) << "\n";
    }
    catch (std::invalid_argument& ex)
    {
      std::cerr << "Invalid number: " << argv[i] << "\n";
      continue;
    }
  }

  return 0;
}