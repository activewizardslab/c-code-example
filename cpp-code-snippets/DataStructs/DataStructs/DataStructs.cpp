// DataStructs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Iterator_base.h"
#include "FListIterator.h"
#include "ForwardIterator.h"
#include "Traits.h"
#include "TemplateMagic.h"

#include "IteratorAlgorithms.h"

#include <iostream>
#include <typeinfo>
#include <time.h>
#include <vector>



template<>
struct haveFunc<nullptr_t> {
	static const bool val = false;
};

template<typename funcT>
struct haveFunc {
	static const bool val = true;
};

struct A {
	void d();
};


//template <typename T>
//using Iterator = ForwardIterator<T>;


int main()
{

	//for (int i = 3; i < 6; i++) {
	//	Iterator<int> t();
	//	std::cout << *t << std::endl;
	//}


	std::cout << "endTest" << std::endl;





	getchar();
    return 0;
}

