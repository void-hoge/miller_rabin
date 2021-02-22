#ifndef RHO_HPP_INCLUDD
#define RHO_HPP_INCLUDD

#include "gmp_setting.hpp"
#include <vector>

mpz_class array_func(mpz_class x, mpz_class n);

mpz_class gcd(mpz_class a, mpz_class b);

std::vector<mpz_class> factorization(mpz_class n);

#endif /* end of include guard: RHO_HPP_INCLUDD */
