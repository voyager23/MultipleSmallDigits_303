/*
 * search_multiset.cpp
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

#define NL std::cout<<std::endl


struct
    {
        //bool operator()(vector<T> a, vector<T> b) const { return a.size() < b.size(); }
        bool operator()(vector<T> a, vector<T> b) const 
        { 
        	if(a.size() < b.size()) return true; 
        	if(a.size() > b.size()) return false;
        	return a < b;
        }
    }customLess;

 void prt_multiset(map<T,multiset<T>>);
 void prt_multiset(map<T,multiset<T>> mst)
 {
 	for(auto e : mst)
 	{
 		cout << e.first << "\t";
 		for(auto f : e.second) cout << f << " ";
 		NL;
 	}
 }

//--------------------Main----------------------------------------------

int main(int argc,char ** argv)
{
	Primes<T> primes(10000000);
	// Must specify typename T, defaults to int which causes overflow
	BaseNCounter<T> bnc(3);
	bnc.inc_accum();

	vector<T> b3n1e13;
	vector<vector<T>> factors;
	map<T, vector<T>> b3n_factors;
	map<T,multiset<T>> b3n_set_factors;
	cout << "Generating the prime factors of base3 numbers"; NL;
	T n, count=0;;
	n = bnc.get_accum();
	while(true){
		bnc.inc_accum();
		n = bnc.get_accum();
		if(n > 22222222)break;
		count++;
		b3n1e13.push_back(n);
		//cout << n << " ";
		factors.push_back(primes.prime_factors(n));
		b3n_factors.emplace(n, primes.prime_factors(n));
	}
	cout << endl;

	sort(factors.begin(), factors.end(), customLess);
	cout << "Constructing the multiset"; NL;
	for(auto i = b3n_factors.begin(); i != b3n_factors.end(); ++i){		
		// construct a multiset
		multiset<T> temp;
		for(auto j = i->second.begin(); j != i->second.end(); ++j) temp.insert(*j);
		b3n_set_factors.emplace(i->first, temp);
		//cout << endl;
	}

	//prt_multiset(b3n_set_factors);

	// query the multimap with vector<T>
	NL;
	cout << "----------Search function----------";
	NL;
	T Sum = 0;
	for(T n = 3; n < 101 ; ++n )
	{
		vector<T>factors = primes.prime_factors(n);
		set<T> query(factors.begin(), factors.end());

		for(auto e : b3n_set_factors)
	 	{
	 		if(e.first < n) continue;
	 		multiset<T> target = e.second;
			if (includes(target.begin(), target.end(), query.begin(), query.end())) {
				cout << n << "\t" << e.first << " ";
				for(auto f : e.second) cout << f << " ";
				NL;
				Sum += e.first / n;
				break;
			}
		}
	}
	cout << endl << "Sum:" << Sum << endl;
	return 0;
}
