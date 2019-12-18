#pragma once

template <typename T>
struct Node{
	T element;
	Node* next;

	operator T (){
		return element;
	}
};