#include "rho.hpp"
#include <iostream>

mpz_class array_func(const mpz_class x, const mpz_class n) {
	return (x*x+1)%n;
}

mpz_class gcd(mpz_class a, mpz_class b) {
	mpz_class c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

std::vector<mpz_class> factorization(const mpz_class n) {
	int i = 1;
	mpz_class x = rnd.get_z_range(n);
	mpz_class y = x;
	mpz_class d = 1;
	while (d != n) {
		if (d == 1) {
			// std::cout << "i=" << i << ", x=" << x << ", y=" << y << ", d=" << d << '\n';
			i++;
			x = array_func(x, n);
			y = array_func(array_func(y, n), n);
			for (int j = 0; j < i; j++) {
				y = array_func(y, n);
			}
			d = gcd(abs(x-y), n);
		}else{
			std::cout << d << '\n';
			break;
		}
	}
	std::vector<mpz_class> v;
	return v;
}
