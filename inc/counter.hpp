/*
 * counter.cxx
 * 
 * 
 */

#ifndef __Counter__
#define __Counter__

#include <iostream>
#include <array>

template<typename T>
class Counter
{	
	public:
		Counter(T [], int s);
		void print();
		void add_n(int n);
		size_t sum_digits();
		size_t count();
		
		std::pair<size_t,size_t> mod_9();
	
	private:
	T* ptr;
	int size;
	int sum,carry,sd,cnt;	
};

template<typename T>
Counter<T>::Counter (T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];	
	
}

template<typename T>
void Counter<T>::print()
{
	// print msd first
	for (int i = size-1; i >= 0; --i)
		std::cout << "" << *(ptr + i);
	std::cout << std::endl;
}

template<typename T> 
void Counter<T>::add_n(int n)
{
	const int base = 3;
	if(n < 0){
		std::cout << "Counter::add_n parameter must be +ve.\n";
		return;
	}
	int i = 0; carry = abs(n);
	do{
		*(ptr + i) = *(ptr + i) + carry;
		carry = *(ptr + i) / base;	//integer math
		*(ptr + i) %= base;			// LSD
		++i;
		if(i >= size) {
			std::cout << "Overflow.\n";
			return;
		}
	}while(carry);
	return;
}
template<typename T> size_t Counter<T>::sum_digits()
{
	size_t sum = 0;
	int i = 0;
	do{
		sum += *(ptr + i);
		++i;
	}while(i < size);
	sd = sum;
	return sum;
}
template<typename T> std::pair<size_t,size_t> Counter<T>::mod_9()
{
	return std::pair<size_t,size_t> {cnt/9, cnt%9};
}
template<typename T> size_t Counter<T>::count()
{
	size_t count = 0;
	size_t i = size-1;
	do{
		count *= 10;
		count += *(ptr + i);
	}while(--i != -1);
	cnt = count;
	return count;
}


//==============================================
#if(0)
	int main(int argc, char **argv)
	{
		int arr[16] {};
		Counter<int> counter(arr, 16);
		size_t sd, a = 4;
		std::pair<size_t,size_t> qr;
		//counter.add_n();

		do{
			counter.print();
			//sd = counter.sum_digits();
			//std::cout << counter.count() <<"    Digit Sum: " << sd;
			counter.add_n(1);
			a += 1;
			//qr = counter.mod_9();
			//std::cout << "\tq:" << qr.first << " r:" << qr.second << std::endl;
			//std::cout << std::endl;
		}while(a <= 10);

		counter.print();
		
		return 0;
	}
#endif

#endif
