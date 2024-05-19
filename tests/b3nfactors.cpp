/*
 * b3nfactors.cpp
 * 
 * Copyright 2024 mike <mike@f39evo970-1.home>
 * 
 * 				Solution 1111981904675169 - 16 digits
 */


// Local definition

#include <iostream>
#include <cstdint>
#include <vector>
#include <set>
#include <iterator>		// std::next
#include <algorithm>	// std::reverse

#include "./classPrime.hpp"
#include "./classBaseN.hpp"

// Declarations
void prt_factors(vector<T> pf);
void find_combinations(vector<uint64_t> source, 
					   vector<uint64_t>& combinations, bool verbose);
					   
// Definitions
void prt_vector(vector<T> pf){
	if(!(pf.empty())){
	for(T p : pf) cout << "  " << p;
	cout << endl;
	}
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
    // Program Specific - reverse order
    combinations.assign(s.rbegin(), --s.rend());
    // Normal Order
    //combinations.assign(s.begin(), --s.end());
}

typedef uint64_t T;

using namespace std;

int main(int argc, char **argv)
{
	const T Limit = 10000;
	Primes<T> primes(Limit*10 + 1);
	set<T> dbase;
	
	for(T i = 11; i != Limit+1; ++i) dbase.insert(dbase.end(), i);
	T Sum = 1+4+3+2+2+3+14+1358+2;
	BaseNCounter bcn(3);
	bcn.set_accum(10);
	T b3n = bcn.get_accum();
	
	// DEBUG CODE FOR BaseNCounter
	
	bcn.set_accum(2122222222);
	for(auto loop = 0; loop != 5; ++loop)
	{
		T foo = bcn.get_accum();
		cout << foo << endl;
		bcn.inc_accum();
	}
	
	exit(1);
	
	// END DEBUG CODE
	while(dbase.empty() == false){
		bcn.inc_accum();
		b3n = bcn.get_accum();
		vector<T> pf = primes.prime_factors(b3n);
		//prt_vector(pf);
		vector<T> combinations;
		find_combinations(pf, combinations, false);
		// Eliminate combinations from the database set
		for(T c : combinations){
			if(c > Limit) continue;
			if(c < 11) break;
			auto i = dbase.find(c);
			if(i != dbase.end()){
				cout << "Erasing " << c << " | "  << b3n << endl;
				Sum += b3n / *i;
				dbase.erase(i);
			}
		}
	}
	
	for(auto n : dbase) cout << " " << n;
	cout << endl;
	
	cout << Sum << endl;
	return 0;
}
