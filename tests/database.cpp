/*
 * database.cpp
 * 
 */

#include <iostream>
#include <map>
#include <cstdint>
#include <cmath>

#include "classBaseN.hpp"
#include "classPrime.hpp"

using namespace std;
typedef uint64_t T;

// Declaration
vector<T> S(T n);

// Definition
vector<T> S(T n){
	// make a vector of divisor pairs by simple division
	//Using the process from mapped find and count divisor pairs
	std::vector<T> divisors;
	T nn = n;
	T d = (T)std::sqrt(n);
	while(d) {
		if((n % d)==0){
			divisors.push_back(d);
			T temp = n/d;
			if(temp != d) divisors.push_back(n/d);
		}
		d -= 1;
	}
	std::sort(divisors.begin(), divisors.end());
	return divisors;		
}


int main(int argc, char **argv)
{
	/* 
	 * setup map<{n = proper divisor}, associated base3 number
	 * As each base3 number is analysed, scan the map with each proper divisor.
	 * if not found add entry map( proper_divisor, base3 );
	 */
	 bool verb = true;	// q = quiet
	std::map<T,T> db;	// < {n or divisor}, base3		 
	vector<T> pdivs;
	
	const T limit = 1000;
	
	BaseNCounter<T> bnc(3);	// set base 3
	T m = 1;
	do {
		bnc.inc_accum();
		// add the proper divisors of the base3 number
		pdivs = S(bnc.get_accum());
		if(verb) cout << m << " " << bnc.get_accum() << "  ";
		for(T pd : pdivs) {
			if(verb) cout << " " << pd;
			// key value is divisor
			auto r = db.try_emplace(pd, bnc.get_accum());
		}		
		if(verb) cout << endl;
		m++;
	} while(m <= limit);
	// Finally scan the map for 1 <= key <= ???
	for(T n = 1; n <= 300; ++n)
		if(db.find(n) == db.end()) cout << "key:" << n << " not found." << endl;
	cout << endl;
	return 0;
}
