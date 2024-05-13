/*
 * solve_outliers.cpp
 * 
 * Copyright 2024 mike <mike@f39evo970-1.home>
 * 
 * 
 */
using namespace std;

#include <iostream>
#include <cstdint>
#include <map>
#include <vector>
#include <set>
#include <queue>

typedef uint64_t T;

#include "classBaseN.hpp"
//--------------------Main----------------------------------------------

bool verbose = false;

int main(int argc,char ** argv)
{
	// Must specify typename T, else defaults to int which causes overflow
	BaseNCounter<T> bnc(3);	//base3 counter
	bnc.set_accum(22222);
	
	queue<T> q1, q2;
	for(T n = 90; n != 110; ++n){
		q1.push(n);
        q1.push(n*2);
        q1.push(n*3);
        q1.push(n*5);
        q1.push(n*7);
        q1.push(n*11);
    }
		
	while(!(q1.empty())) {
		T b3n = bnc.get_accum();
		// cout << "Testing" << b3n << "\t";
		do {
			T divisor = q1.front();
			q1.pop();
			if ((b3n % divisor)==0) {
				cout << divisor << "\t/ " << b3n << endl;
			} else {
				q2.push(divisor);
			}
		} while(!(q1.empty()));
		if(q2.empty()) break;
		q1 = q2;
		q2 = {};
		bnc.inc_accum();
	}
	return 0;
}
