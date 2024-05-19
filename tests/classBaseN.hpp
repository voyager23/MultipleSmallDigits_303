/*
 * classBaseN.hpp
 * Templated class file - contains declarations and definitions
 * HEADER ONLY FILE
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
		string accum_str();
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
// Basic sanity checks
{
	if(v == 0){
		accumulator = {0};
	} else {
		accumulator = {};
		while(v > 0){
			T d = v % 10;
			if(base > d) {
				accumulator.push_back(d);
				v /= 10;
			} else { // error clause
				cout << d << " >= " << base;
				exit(1);
			}
		}
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
string BaseNCounter<T>::accum_str(){
// return the contents of the accumulator as a string
	string a;
	for(auto n : accumulator){
		a = to_string(n) + a;
	}
	return(a);
}

//~ template<typename T>
//~ void BaseNCounter<T>::inc_accum(){
	//~ i = accumulator.begin();
	//~ do{
		//~ *i += 1;
		//~ carry = *i / base;
		//~ (*i) %= base;
		//~ if((carry)and(++i == accumulator.end())) {
			//~ accumulator.push_back(0);
			//~ i = --accumulator.end();
		//~ }
	//~ }while(carry);
//~ }

template<typename T>
void BaseNCounter<T>::inc_accum(){
	// Version 1.1 2024/05/19 18:00:24
	carry = 1;
	for(i = accumulator.begin(); i != accumulator.end(); ++i) {
		*i += carry;
		*i %= base;
		if(*i == 0) {
			carry = 1;
		} else {
			carry = 0;
			break;
		}
	}
	if(carry == 1) accumulator.push_back(carry);
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
