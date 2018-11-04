//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#ifndef PROJECT_EULER_PRIME_H
#define PROJECT_EULER_PRIME_H

#include <vector>

namespace prime
{
  typedef void (*A)(unsigned long i, void *context);

  unsigned long upper_bound_of_nth_prime(unsigned int nth_prime);
  std::vector<bool> sieve_of_erathostenes(size_t size);
  std::vector<bool> sieve_of_erathostenes(size_t size, A prime_found_callback, void *context);
};


#endif //PROJECT_EULER_PRIME_H
