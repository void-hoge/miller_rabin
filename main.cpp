#include <iostream>
#include <gmpxx.h>
#include <gmp.h>
#include <cassert>
#include <random>

static const int k = 100;
static const int base = 10;
static gmp_randclass rnd(gmp_randinit_default);

mpz_class modexp(mpz_class base, mpz_class exp, const mpz_class &mod){
	mpz_class result = 1;
	while (exp != 0){
		if ((exp & 1) == 1){
			result *= base;
			result %= mod;
		}
		base*=base;
		base%=mod;
		exp>>=1;
	}
	return result;
}

bool primality(const mpz_class n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if ((n&1) == 0) return false;
	const mpz_class m = n-1;
	const int s = mpz_scan1(m.get_mpz_t(), 0);
	const mpz_class d = n >> s;
	for (size_t i = 0; i < k; i++) {
		const mpz_class a = rnd.get_z_range(n-2)+1;
		mpz_class t = d;
		mpz_class y = modexp(a, t, n);
		while ((t != n-1) && (y != 1) && (y != n-1)){
			y = (y*y)%n;
			t <<= 1;
		}
		if ((y != n-1) && ((t&1) == 0)){
			return false;
		}
	}
	return true;
}

int main(const int argc, const char *argv[]){
	if (argc < 2) return 0;
	mpz_class n;
	mpz_set_str(n.get_mpz_t(), argv[1], 10);
	if (n < 2) {
		std::cout << "composite\n";
		return 0;
	}
	switch (primality(n)) {
		case 0:
			std::cout << "composite\n";
			break;
		case 1:
			std::cout << "prime\n";
			break;
		default:
			break;
	}
	return 0;
}
