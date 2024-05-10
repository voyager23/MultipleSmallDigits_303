/*
 * classProperDivisors.cpp
 * 
 * Copyright 2024 mike <mike@Fedora37>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "classProperDivisors.hpp"

#define DEBUG 1


// Class Definitions
ProperDivisors::ProperDivisors(uint64_t p){
	// Initialise the class
	SieveOfEratosthenes(primes, p);
}

// private functions

void ProperDivisors::SieveOfEratosthenes(std::vector<uint64_t> &primes, uint64_t n)
{
	std::cout << "Sieving..." << flush;
    // internal vector of bool
    std::vector<bool> prime;
    // Set n+1 entries in vector<bool> to true
    for(uint64_t c = 0; c != n+1; ++c) prime.push_back(true);

    for (uint64_t p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			for (uint64_t i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    primes.clear();
    for(uint64_t pn = 2; pn != n+1; ++pn) if(prime[pn]) primes.push_back(pn);
    std::cout << "done." << std::endl;
}


void ProperDivisors::generate_descriptors(std::vector<uint64_t> primes, uint64_t n, Vpp &vpp){
	// Generates a vector of descriptors for integer n. Each element is a pair<prime, power>
	PrimePower temp;
	vpp.clear();
	for(auto i = primes.begin(); i != primes.end(); ++i){
		uint64_t p = *i;
		if(p > n) break;
		temp = {p,0};
		while((n % p)==0){
			temp.second += 1;
			n /= p;
		}
		// save <prime,power> to vector
		if(temp.second > 0) vpp.push_back(temp);
	}
    // print the vector of prime/exponent
    // prt_current_values(vpp);
}

void ProperDivisors::prt_current_values(Vpp &vpp) {
    for(PrimePower pp : vpp)
        cout << pp.first << "/" << pp.second << "  ";
    cout << endl;
}

void ProperDivisors::find_combinations(Vpp &vpp, vector<uint64_t>& combinations, bool verbose){
    
    uint64_t N, M, idx, product;

    // Convert the vector prime/exponent to vector<uint64_t> source
	vector<uint64_t> source;
    for(PrimePower pp : vpp) {
        while(pp.second-- > 0) source.push_back(pp.first);
    }
    const size_t limit = (1 << source.size());
    // cout << "-----integer-----" << endl;
    combinations = {1};
    for(M = 1; M != limit; ++M) {
        idx = 0; product = 1;
        N = M;
        while(N > 0) {
            if ((N % 2)==1) {
                product *= source[idx];
            }
            N >>= 1;    // n %= 2
            ++idx;
        }
        combinations.push_back(product);
    }
    // remove duplicates and order combinations;
    set<uint64_t> s(combinations.begin(), combinations.end());
    combinations.assign(s.begin(), --s.end());
    //cout << "The proper divisors of a positive integer N are those numbers, \nother than N itself, that divide N without remainder." << endl;
}

vector<uint64_t> ProperDivisors::get_properdivisors(uint64_t n, bool verbose) { 
	generate_descriptors(primes, n, vpp);
	find_combinations(vpp, combinations, verbose); 
	return combinations;
}

vector<uint64_t> ProperDivisors::get_bydivision_properdivisors(uint64_t n, bool verbose) {
	// Approx 8* slower than get_properdivisors
	combinations = {1};
	for(auto p : primes){
		if(p < n) continue;
		if(p == n){
			combinations.push_back(p);
			return combinations;
		}
		break;	// (p > n)
	}
	
	uint64_t d = 2;
	uint64_t e = n;
	while(d <= e){
		if((n % d)==0) {
			combinations.push_back(d);
			e = n/d;
			combinations.push_back(e);
		}
		d++;
	}
    // remove duplicates and order combinations;
    set<uint64_t> s(combinations.begin(), combinations.end());
    combinations.assign(s.begin(), --s.end());
	return combinations;
}
	
	


//==============================================================================
#if(DEBUG)

int main(int argc, char ** argv)
{
	uint64_t N = 212222122;
	ProperDivisors pdiv(100000);
	vector<uint64_t> combs;
	for(uint64_t N = 2122; N < 10000000; N = N*10 + 2){
		combs = pdiv.get_properdivisors(N, true);
		cout << "Proper divisors of " << N << ":\t";
		for(auto c : combs) cout << c << " ";
		cout << endl;
	}
	return 0;	
}

#endif


