#ifndef MILLER_RABIN_HPP_INCLUDED
#define MILLER_RABIN_HPP_INCLUDED

#include "gmp_setting.hpp"

static const int k = 100;
static const int base = 10;

mpz_class modexp(mpz_class base, mpz_class exp, const mpz_class &mod);

bool primality(const mpz_class n);

#endif /* end of include guard: MILLER_RABIN_HPP_INCLUDED */
