/*
 * filename.cxx
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
#include <set>

using namespace std;

typedef uint64_t T;

void prt_multiset(multiset<T> mst);
void prt_multiset(multiset<T> mst)
 {
 	for(auto f : mst) cout << f << " ";
 	cout << endl;
 }

 bool query_in_target(multiset<T>target, multiset<T>query);
 bool query_in_target(multiset<T>target, multiset<T>query)
 /*
  * q==qend	t==tend return
  *		0		0	continue
  * 	0		1	false
  * 	1		0	false
  * 	1		1	true
  */
 {
	multiset<T>::iterator tend, qend, t, q;
	if (target.size() < query.size()) return false;
	tend = target.end();
	qend = query.end();
	t = target.begin();
	q = query.begin();
	
	while(true){
		if(*q == *t) {
			if(++q == qend) return true;
			if(++t == tend) return false;
		} else if(*t < *q) {
			if(++t == tend) return false;
		} else // (*q < *t)
			return false;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	multiset<T> query = {2,3,7};
	multiset<T> target = {2,2,5,5};

	bool result = query_in_target(target,query);
	prt_multiset(query);
	prt_multiset(target);
	cout << "Result:" << result << endl;

	return 0;
}