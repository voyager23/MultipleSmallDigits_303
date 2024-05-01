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
	BaseNCounter<T> bnc(3);	// set base 3
	T m = 1;
	do {
		bnc.inc_accum();
		cout << m << " " << bnc.get_accum() << endl;
		m++;
	} while(m < 100);
	exit(0);


	T Sum = 0;
	T n = 1;
	while(n++ <= 100){
		T b3 = bnc.get_accum();
		T g = b3/n;
		Sum += g;
		bnc.inc_accum();
	}
	cout << "n:" << n << " Sum:" << Sum << endl;
	return 0;
}
