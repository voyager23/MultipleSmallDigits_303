/*
 * classBaseN.cpp
 * 
 * 
 */

#ifndef __BaseNCounter__
#define __BaseNCounter__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename T>
class BaseNCounter
{	
	public:
		BaseNCounter(unsigned base); // Warning: No Sanity Checks
		BaseNCounter(unsigned base, unsigned v); // initial value base10 - converted internally 
		BaseNCounter(unsigned base, string v); // Inital value as a string
		string str_accum();
		void inc_accum();
		void inc_accum(unsigned m);
		void set_accum(unsigned m);
		T get_accum();

	private:
	std::vector<T> accumulator;
	typename std::vector<T>::iterator i;
	unsigned base;
	unsigned sum,carry;
};

#endif