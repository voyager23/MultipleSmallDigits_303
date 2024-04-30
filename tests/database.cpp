/*
 * database.cpp
 * 
 */

#include <iostream>
#include <unordered_map>
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
	BaseNCounter<T> bnc(3);
	vector<T> pd;
	int c = 100;
	while(c--){
		cout << bnc.get_accum() << "\t";
		pd = S(bnc.get_accum());
		for(T d : pd) cout << " " << d;
		cout << endl;
		bnc.inc_accum();
	}	
	return 0;
}
