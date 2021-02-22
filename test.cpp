#include "rho.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
	mpz_class a = 1, b = 1;
	a = (a<<31)-1;
	b = (a<<61)-1;
	std::cout << a << '\n';
	std::cout << b << '\n';
	std::cout << a*b << '\n';
	// mpz_class ab = (mpz_class)2131273821517;
	factorization(a*a);
	// factorization(91);
	return 0;
}
