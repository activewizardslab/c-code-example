#pragma once

#include "Iterator_base.h"

template< typename iterator >
void swap(iterator& f, iterator& s) {

	iterator temp = f;
	f = s;
	s = std::move(temp);

}

template< typename iterator >
size_t getSize(iterator begin, const iterator& end) {

	size_t size = 0;

	while (begin != end) {
		++size;
		++begin;
	}

	return size;
}

template<typename T>
using comparator = bool(*) (T, T);

template<typename T>
bool isGreater(T f, T s) {
	return (f > s) ? true : false;
}


template< typename iterator, typename comparator >
void bubbleSort(const iterator& begin, iterator end, comparator condition) {

	size_t size = getSize(begin, end); // n steps

	// use end us second iterator, couse dont wanna create a new iterator;
	iterator temp;
	for (size_t i = 1; i < size; i++) {
		end = begin;
		temp = end++;
		for (size_t j = 0; j < size - i; j++) {

			if(condition(*temp, *end)){
				swap(*temp, *end);
			}

			++temp;
			++end;
		}
	}

}

template< typename iterator>
void bubbleSort(const iterator& begin, iterator end) {

	size_t size = getSize(begin, end); // n steps

									   // use end us second iterator, couse dont wanna create a new iterator;
	iterator temp;
	for (size_t i = 1; i < size; i++) {
		end = begin;
		temp = end++;
		for (size_t j = 0; j < size - i; j++) {

			if (isGreater(*temp, *end)) {
				swap(*temp, *end);
			}

			++temp;
			++end;
		}
	}

}


