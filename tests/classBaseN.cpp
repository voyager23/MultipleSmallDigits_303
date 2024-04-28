/*
 * classBaseN.cpp
 * 
 * 
 */

#include "classBaseN.hpp"
#include "classPrime.hpp"

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

// ============================================================================
int main(int argc, char const *argv[])
{

	// Setup Primes
	Primes<unsigned> P(10000);
	cout << "<"<<P.get_hi_prime()<<">"<< endl;

	BaseNCounter<unsigned> bnc(3,1);
	unsigned n = 2;
	while(n++ < 100){
		bnc.set_accum(1);
		while(true){ 
			bnc.inc_accum();
			unsigned z = bnc.get_accum();
			if ((z % n) == 0){
				//output solution -> n, primefactors(n), f(n), primefactors(f(n))
				cout << n << "\t";
				for(auto pf : P.prime_factors(n)) cout << " " << pf;
				cout << "\t" << z << "\t";
				for(auto pf : P.prime_factors(z)) cout << " " << pf;
				cout << endl;
				break;
			} //if...
		} //while...
	} //for...


	return 0;
}
