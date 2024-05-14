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
#include <set>		// 

typedef uint64_t T;

#include "classBaseN.hpp"

//--------------------Main----------------------------------------------

int main(int argc, char **argv)
{
	// Must specify typename T, else it defaults to int 
	// which causes overflow.
	BaseNCounter<T> bnc(3);	//base3 counter
	bnc.set_accum(2);	
	return 0;
}

