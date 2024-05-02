/*
 * classBaseN.hpp
 * Templated class file - contains declarations and definitions
 * 
 * 
 */

#ifndef __BaseNCounter__
#define __BaseNCounter__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

typedef uint64_t T;

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

// ---------------------------------------------------------------------

template<typename T>
BaseNCounter<T>::BaseNCounter (T b)
// !No_San_Chx!
{
	base = b;
	accumulator = {0,0};
}

template<typename T>
BaseNCounter<T>::BaseNCounter (T b, T v)
// !No_San_Chx!
// Assume base b and intial base10 value v as parameters
{
	base =  b;
	accumulator = {0,0};
	while(v > 0){
		accumulator.push_back(v % b);
		v /= b;
	}	
}

template<typename T>
void BaseNCounter<T>::set_accum(T v)
// !No_San_Chx!
{
	// No change to base
	accumulator.clear();
	while(v > 0){
		accumulator.push_back(v % base);
		v /= base;
	}	
}

template<typename T>
BaseNCounter<T>::BaseNCounter (T b, string v)
// !No_San_Chx!
// Save the input string in the accumulator
{
	base = b;
	accumulator.clear();
	for(auto i = v.rbegin(); i != v.rend(); ++i) {
		accumulator.push_back(*i - '0');
	}	
}

template<typename T>
string BaseNCounter<T>::str_accum(){
// return the contents of the accumulator as a string
	string a;
	for(auto n : accumulator){
		a = to_string(n) + a;
	}
	return(a);
}

template<typename T>
void BaseNCounter<T>::inc_accum(){
	i = accumulator.begin();
	do{
		*i += 1;
		carry = *i / base;
		(*i) %= base;
		if((carry)and(++i == accumulator.end())) {
			accumulator.push_back(0);
			i = --accumulator.end();
		}
	}while(carry);
}

template<typename T>
void BaseNCounter<T>::inc_accum(T m){

	while(m--) inc_accum();
}

template<typename T>
T BaseNCounter<T>::get_accum(){
	// return the digits of the accumulator as a type T number
	T n = 0;
	for(auto i = accumulator.rbegin(); i != accumulator.rend(); ++i){
		n *= 10;
		n += *i;
	}
	return n;
}

#endif
