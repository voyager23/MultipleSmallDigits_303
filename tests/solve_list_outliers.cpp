/*
 * solve_list_outliers.cpp
 * 
 * Copyright 2024 mike <mike@f39evo970-1.home>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


// Local definition

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm> 

typedef uint64_t T;

#include "classBaseN.hpp"

//--------------------Main----------------------------------------------

int main(int argc, char **argv)
{

	const T expected = 11'363'107;
	const bool not_true = false;
	// Consider a range of values 1 <= n <= MaxN
	const T MaxN = 100;
	BaseNCounter<T> bnc(3);	//base3 counter
	bnc.set_accum(0);
	vector<bool> found(MaxN+1,false);
	found[0] = true;
	found[1] = true;
	T idx, Sum = 1;
	while(any_of(found.begin(), found.end(), [not_true](bool y) { return y == not_true; })){
		idx = 1;
		// Adjust the index
		while(found[idx] == true) ++idx;
		bnc.inc_accum();
		// Adjust the accumulator to match
		//bnc.set_accum(1);
		//while(bnc.get_accum() < idx) bnc.inc_accum();		
		while(idx <= MaxN){
			if ((found[idx] == false) and ( bnc.get_accum() % idx == 0 )){
				found[idx] = true;
				Sum += bnc.get_accum() / idx;
				cout << idx << "/" << bnc.get_accum() << endl;
				// check for any simple multiples
				//~ T mult = 2;
				//~ T temp;
				//~ do {
					//~ temp = idx * mult;
					//~ if (temp > MaxN) break;
					//~ if ((found[temp] == false) and ( bnc.get_accum() % temp == 0 )){
						//~ found[temp] = true;
						//~ Sum += bnc.get_accum() / temp;
					//~ }
				//~ } while(++mult < 8);
			}
			++idx;
			while(bnc.get_accum() < idx) bnc.inc_accum();
		}
		//cout << "Part Sum:" << Sum << endl;
	} // main while loop
	
	cout << "Expect: " << expected << endl;
	cout << "Sum:" << Sum << endl;
	
	return 0;
}

	//~ // TEST AREA
	//~ const bool not_true = false;
	//~ vector<bool> foo(5, false);
	//~ foo[0] = true;
	//~ foo[1] = true;
	//~ foo[3] = true;
	//~ for(auto b : foo) cout << "  " << b;
	//~ cout << endl;
	//~ cout << any_of(foo.begin(), foo.end(), [not_true](bool y) { return y == not_true; }) << endl;
	
	//~ // TEST EXIT
	//~ exit(0);
	//~ // END TEST AREA
