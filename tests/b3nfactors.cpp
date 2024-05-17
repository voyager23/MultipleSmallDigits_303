/*
 * b3nfactors.cpp
 * 
 * Copyright 2024 mike <mike@f39evo970-1.home>
 * 
 */


// Local definition

#include <iostream>
#include <cstdint>
#include <vector>
#include <set>

#include "./classPrime.hpp"
#include "./classBaseN.hpp"

// Declarations
void prt_factors(vector<T> pf);
void find_combinations(vector<uint64_t> source, 
					   vector<uint64_t>& combinations, bool verbose);
					   
// Definitions
void prt_factors(vector<T> pf){
	for(T p : pf) cout << "  " << p;
	cout << endl;
	}

void find_combinations(vector<uint64_t> source, 
					   vector<uint64_t>& combinations, bool verbose){
    // Modified code from classProperDivisors
    uint64_t N, M, idx, product;

    //~ // Convert the vector prime/exponent to vector<uint64_t> source
	//~ vector<uint64_t> source;
    //~ for(PrimePower pp : vpp) {
        //~ while(pp.second-- > 0) source.push_back(pp.first);
    //~ }
    
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
}

typedef uint64_t T;

using namespace std;

int main(int argc, char **argv)
{
	Primes<T> primes(100001);
	BaseNCounter bcn(3);
	bcn.set_accum(100);
	T b3n = bcn.get_accum();
	while(b3n < 100000){
		bcn.inc_accum();
		b3n = bcn.get_accum();
		vector<T> pf = primes.prime_factors(b3n);
		prt_factors(pf);
		vector<T> combinations;
		find_combinations(pf, combinations, false);
		cout << b3n << " | ";
		prt_factors(combinations);
	}
	
	return 0;
}

