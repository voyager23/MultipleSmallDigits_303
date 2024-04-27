/*
 * classBaseN.cpp
 * 
 * 
 */

#ifndef __BaseNCounter__
#define __BaseNCounter__

#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class BaseNCounter
{	
	public:
		BaseNCounter(int base); // Warning: No Sanity Checks
		BaseNCounter(int base, int v); // initial value base10 converted internally 
		BaseNCounter(int base, string v); // Inital value as a string
		string str_accum();

	private:
	std::vector<T> accumulator;
	int base;
	int sum,carry;
};

// ---------------------------------------------------------------------
template<typename T>
BaseNCounter<T>::BaseNCounter (int b)
// !No_San_Chx!
{
	base = b;
	accumulator.clear();	
}

template<typename T>
BaseNCounter<T>::BaseNCounter (int b, int v)
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
BaseNCounter<T>::BaseNCounter (int b, string v)
// !No_San_Chx!

{

	
}

template<typename T>
string BaseNCounter<T>::str_accum(){
	string a;
	for(auto n : accumulator){
		a = to_string(n) + a;
	}
	return(a);
}
// ---------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	BaseNCounter<int> bnc(3,42);
	cout << bnc.str_accum() << endl;
	return 0;
}

#endif