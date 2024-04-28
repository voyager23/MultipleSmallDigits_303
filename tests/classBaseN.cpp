/*
 * classBaseN.cpp
 * 
 * 
 */

#include "classBaseN.hpp"

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

/*
	BaseNCounter bnc(3,0)
	for n : 100 {
		bnc.set_accum(0)
		while(true){ 
			bnc.inc_accum(n)
			T z = bnc.get_accum()
			if ((T % n) == 0){
				output solution
				break
			} if...
		} while...
		next n
	} for...
*/


// ============================================================================
int main(int argc, char const *argv[])
{
	BaseNCounter<unsigned> bnc(3, 24);
	int loop = 32;
	while(loop--){
		cout << bnc.get_accum() << endl;
		bnc.inc_accum();
	}
	cout << endl;
	bnc.inc_accum(1024);
	cout << bnc.get_accum() << endl;
	bnc.inc_accum();
	cout << bnc.get_accum() << endl;
	bnc.set_accum(5);
	cout << bnc.get_accum() << endl;

	// BaseNCounter<unsigned> bnd(3, "22");
	// cout << bnd.get_accum() << endl;
	// bnd.inc_accum();
	// cout << bnd.get_accum() << endl;	
	// bnd.inc_accum();
	// cout << bnd.get_accum() << endl;	
	return 0;
}
