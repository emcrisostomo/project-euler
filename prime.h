//
// Created by Enrico M. Crisostomo on 01/11/2018.
//

#ifndef PROJECT_EULER_PRIME_H
#define PROJECT_EULER_PRIME_H

#include <vector>

namespace prime
{
  typedef void (*prime_found_callback)(unsigned long i, void *context);

  unsigned long upper_bound_of_nth_prime(unsigned int nth_prime);
  std::vector<bool> sieve_of_erathostenes(size_t size);
  std::vector<bool> sieve_of_erathostenes(size_t size, prime_found_callback prime_found_callback, void *context);
};


#endif //PROJECT_EULER_PRIME_H
