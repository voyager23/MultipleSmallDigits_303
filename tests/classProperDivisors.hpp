/*
 * classProperDivisors.hpp
 * 
 * Copyright 2024 mike <mike@Fedora37>
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

#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <set>

using namespace std;

class ProperDivisors {
	// Class Declarations
	
	typedef std::pair<uint64_t,uint64_t> PrimePower;
	typedef std::vector<PrimePower> Vpp;  // describes the prime powers of a factorial
	
	public:		
		ProperDivisors(uint64_t p);
		vector<uint64_t> get_properdivisors(uint64_t n, bool verbose = false);
		vector<uint64_t> get_bydivision_properdivisors(uint64_t n, bool verbose = false);
		
	private:
		vector<uint64_t> primes; // vector of primes
		vector<uint64_t> combinations; // vector of combinations
		Vpp vpp;	// vector of prime powers
		void generate_descriptors(std::vector<uint64_t> primes, uint64_t n, Vpp& vpp);
		void prt_current_values(vector<PrimePower> &vpp);
		void SieveOfEratosthenes(std::vector<uint64_t> &primes, uint64_t n);
        void find_combinations(Vpp &vpp, vector<uint64_t>& combinations, bool verbose= false );

};
 
