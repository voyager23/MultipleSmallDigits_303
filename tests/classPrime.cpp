/*
 * classPrime.cpp
 * 
 * Copyright 2024 mike <mike@fedora>
 * A modified version of the code in Toolkit.
 * Provides a class which offers functions to construct a Sieve of Primes 
 * and to find the prime factors of a given number.
 * Uses uint64_t as the base type
 * 
 */



#include "classPrime.hpp"

template<typename T>
void Primes<T>::sieve(T n)
{
	printf("Starting Sieve for n = %llu...",n);
    // internal vector of bool
    std::vector<bool> prime;
    // Set n+1 entries in vector<bool> to true
    for(T c = 0; c != n+1; ++c) prime.push_back(true);

    for (T p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		// Update all multiples of p greater than or
		// equal to the square of it numbers which are multiples
		// of p and are less than p^2 are already been marked.
			{
				for (T i = p * p; i <= n; i += p)
					prime[i] = false;
			}
	}
    primes.clear();
    for(T pn = 2; pn != n+1; ++pn) if(prime[pn]) primes.push_back(pn);
    printf("Completed Sieve\n");
}

template<typename T>
vector<T> Primes<T>::prime_factors(T n){
	factors.clear();
	for(auto i = primes.begin(); i != primes.end(); ++i){
		T p = *i;
		if(p > n) break;
		while((n % p)==0){
			factors.push_back(p);
			n /= p;
		}
	}
	return factors;
}


// Test code
int main(int argc, char const *argv[])
{
	/* code */
	Primes<uint64_t> P;
	cout << "<"<<P.get_hi_prime()<<">"<< endl;

	uint64_t query = 60*32*510;
	vector<uint64_t> factors = P.prime_factors(query);
	cout << query << " : ";
	for(auto f : factors) cout << " " << f;
	cout << endl;	

	return 0;
}