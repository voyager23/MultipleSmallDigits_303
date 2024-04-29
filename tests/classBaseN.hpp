/*
 * classBaseN.hpp
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
		BaseNCounter(T base); // Warning: No Sanity Checks
		BaseNCounter(T base, T v); // initial value base10 - converted internally 
		BaseNCounter(T base, string v); // Inital value as a string
		string str_accum();
		void inc_accum();
		void inc_accum(T m);
		void set_accum(T m);
		T get_accum();

	private:
	std::vector<T> accumulator;
	typename std::vector<T>::iterator i;
	T base;
	T sum,carry;
};

#endif