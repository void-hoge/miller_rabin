#include <iostream>
#include <cassert>
#include <random>
#include "miller_rabin.hpp"

int main(const int argc, const char *argv[]){
	switch (argc){
		case 2:
		{
			mpz_class n;
			mpz_set_str(n.get_mpz_t(), argv[1], base);
			if (n <= 1) {
				std::cout << "not prime" << '\n';
				return 1;
			}else if (primality(n)){
				std::cout << "prime" << '\n';
				return 0;
			}else {
				std::cout << "composite" << '\n';
				return 2;
			}
			break;
		}
		case 3:
		{
			mpz_class n;
			mpz_set_str(n.get_mpz_t(), argv[1], base);
			mpz_class count;
			mpz_set_str(count.get_mpz_t(), argv[2], base);
			if (count==0)break;
			int inc;
			if (count < 0){
				inc = -1;
			}else{
				inc = 1;
			}
			for (int i = 0; i < abs(count); n+=inc){
				if (n < 2 && inc < 0)break;
				if (primality(n)){
					std::cout << n << std::endl;
					i++;
				}
			}
			break;
		}
		default:
			break;
	}
	return 0;
}
