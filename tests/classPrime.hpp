/*
 * classPrime.hpp
 * 
 * Copyright 2024 mike <mike@fedora>
 * Header File for classPrime.cpp
 * A modified version of the code in Toolkit.
 * Provides a class which offers functions to construct a Sieve of Primes 
 * and to find the prime factors of a given number.
 * Uses uint64_t as the base type
 * 
 */

#ifndef __classPrime__
#define __classPrime__
#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;
typedef uint64_t T;

template<typename T>
class Primes
{
public:
	//Primes() { this->sieve(1000);	} //default
	//Primes(T n) { this->sieve(n); }	//specify the upper prime limit
	T get_hi_prime() { return primes.back(); }
	vector<T> prime_factors(T n);

private:
	vector<T> primes;
	vector<T> factors;
	void sieve(T limit);
};
#endif
