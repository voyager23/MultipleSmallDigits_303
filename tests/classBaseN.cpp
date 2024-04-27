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

	private:
	std::vector<T> accumulator;
	typename std::vector<T>::iterator i;
	unsigned base;
	unsigned sum,carry;
};

// ---------------------------------------------------------------------
template<typename T>
BaseNCounter<T>::BaseNCounter (unsigned b)
// !No_San_Chx!
{
	base = b;
	accumulator.clear();	
}

template<typename T>
BaseNCounter<T>::BaseNCounter (unsigned b, unsigned v)
// !No_San_Chx!
// Assume base b and intial base10 value v as parameters
{
	base =  b;
	accumulator.clear();
	while(v > 0){
		accumulator.push_back(v % b);
		v /= b;
	}	
}

template<typename T>
void BaseNCounter<T>::set_accum(unsigned v)
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
BaseNCounter<T>::BaseNCounter (unsigned b, string v)
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
void BaseNCounter<T>::inc_accum(unsigned m){
	while(m--) inc_accum();
}

// ---------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	BaseNCounter<unsigned> bnc(3, 24);
	int loop = 32;
	while(loop--){
		cout << bnc.str_accum() << endl;
		bnc.inc_accum();
	}
	cout << endl;
	bnc.inc_accum(1024);
	cout << bnc.str_accum() << endl;
	bnc.inc_accum();
	cout << bnc.str_accum() << endl;
	bnc.set_accum(5);
	cout << bnc.str_accum() << endl;

	// BaseNCounter<unsigned> bnd(3, "22");
	// cout << bnd.str_accum() << endl;
	// bnd.inc_accum();
	// cout << bnd.str_accum() << endl;	
	// bnd.inc_accum();
	// cout << bnd.str_accum() << endl;	
	return 0;
}

#endif