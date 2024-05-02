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

using namespace std;

#include <iostream>
#include <cstdint>
#include <map>
#include <vector>

typedef uint64_t T;

#include "classBaseN.hpp"

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

//--------------------Main----------------------------------------------

int main(int argc,char ** argv)
{
	Outlier<T> ds(18);
	// Must specify typename T, defaults to int which causes overflow
	BaseNCounter<T> bnc(3);
	bnc.inc_accum();
	vector<T> b3n1e13;
	T n, count=0;;
	n = bnc.get_accum();
	while(true){
		
		if ((n % (1188)==0)) {
			cout << n << endl;
			break;
		}
		bnc.inc_accum();
		n = bnc.get_accum();
		if(n > 10000000000000)break;
		count++;
		b3n1e13.push_back(n);
	}
	cout << "count: " << count << endl;
	cout << "size: " << b3n1e13.size() << endl;
}


