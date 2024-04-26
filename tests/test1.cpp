/*
 * test1.cpp
 * 
 * Copyright 2024 mike <mike@fedora>
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


#include <iostream>
#include <cstdint>
#include <cmath>
#include <iterator>
#include <vector>
#include <algorithm>

#include "../inc/counter.hpp"

typedef uint64_t T;

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	int arr[16] {};	// used by counter
	Counter<int> counter(arr, 16);
	counter.add_n(1);
	int loop = 16;
	while(true){
		counter.print();
		// rebase counter to base10
		int c = counter.count();
		std::cout << c << std::endl;
		if(((c % 111)==0)or(0)) break;

		counter.add_n(1);
	}
	return 0;
}