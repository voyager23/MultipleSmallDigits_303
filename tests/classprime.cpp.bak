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


#include <iostream>
#include <cstdint>
#include <cmath>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
typedef uint64_t T;

template<typename T>
class Primes
{
public:
	Primes()	//default
	{
		sieve(1000);
	}
	Primes(T n)	//specify the upper prime limit
	{
		sieve(n);
	}

private:
	vector<T> primes;
	void sieve(T limit);
};


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
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are multiples
			// of p and are less than p^2 are already been marked.
			for (T i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    primes.clear();
    for(T pn = 2; pn != n+1; ++pn) if(prime[pn]) primes.push_back(pn);
    printf("Completed Sieve\n");
}




int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}