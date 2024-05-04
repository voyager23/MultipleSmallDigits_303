/*
 * classOutlier.cpp
 * 
 * Copyright 2024 mike <mike@f39evo970-1.home>
 * 
 * Intended as an include file.
 * Because the class is templated, both declarations and definitions are
 * included in this file.
 * 
 * Developing this file as .cpp
 * 
 */


#ifndef __Class_Outlier__
#define __Class_Outlier__

#include <iostream>
#include <cstdint>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef uint64_t T;

#include "classBaseN.hpp"
#include "classPrime.hpp"

//--------------------Class Declaration---------------------------------
template<typename T>
class Outlier
{	
	private:
	T width;
	vector<T> lookup;
	
	public:
		//Outlier();
		Outlier(int w);	// Specify the maximum width of base3 numbers
		~Outlier();
		T funct(T n);	
};
//--------------------Class Definitions---------------------------------

template<typename T>
Outlier<T>::Outlier(int w)	// Constructor
{
	width = w;
	// Construct a lookup vector of base3 numbers 
	// up to the requested width
	BaseNCounter<T> bnc(3);
}
	
template<typename T>
Outlier<T>::~Outlier()	// Destructor
{

}

template<typename T>
T Outlier<T>::funct(T n)
{
	T sum = 0;

	return sum;
}


#endif

struct
    {
        //bool operator()(vector<T> a, vector<T> b) const { return a.size() < b.size(); }
        bool operator()(vector<T> a, vector<T> b) const 
        { 
        	if(a.size() < b.size()) return true; 
        	if(a.size() > b.size()) return false;
        	return a < b;
        }
    }
    customLess;

//--------------------Main----------------------------------------------

int main(int argc,char ** argv)
{
	Primes<T> primes(10000);
	Outlier<T> ds(18);
	// Must specify typename T, defaults to int which causes overflow
	BaseNCounter<T> bnc(3);
	bnc.inc_accum();

	vector<T> b3n1e13;
	vector<vector<T>> factors;
	map<T, vector<T>> b3n_factors;
	map<T,multiset<T>> b3n_set_factors;

	T n, count=0;;
	n = bnc.get_accum();
	while(true){
		bnc.inc_accum();
		n = bnc.get_accum();
		if(n > 2222)break;
		count++;
		b3n1e13.push_back(n);
		cout << n << " ";
		factors.push_back(primes.prime_factors(n));
		b3n_factors.emplace(n, primes.prime_factors(n));
	}
	cout << endl;

	sort(factors.begin(), factors.end(), customLess);

	//reverse(factors.begin(), factors.end());
	
	// for(auto p : factors){
	// 	for(auto q : p) cout << " " << q;
	// 	cout << endl;
	// }
	//cout << "size: " << b3n1e13.size() << endl;

	for(auto i = b3n_factors.begin(); i != b3n_factors.end(); ++i){		
		// construct a multiset
		multiset<T> temp;
		for(auto j = i->second.begin(); j != i->second.end(); ++j) temp.insert(*j);
		b3n_set_factors.emplace(i->first, temp);
		cout << endl;
	}

	return 0;

}
