#pragma once

#include "ListNodes.h"

template<typename T>
struct base_traits {
	using Val_t = T;
	using Arg_t = T&;
	using Ptr_t = Val_t*;
	using Ref_t = Val_t&;
};

template<>
struct base_traits<char> {
	using Val_t = char;
	using Arg_t = char;
	using Ptr_t = char*;
	using Ref_t = char&;
};

template<>
struct base_traits<int> {
	using Val_t = int;
	using Arg_t = int;
	using Ptr_t = int*;
	using Ref_t = int&;
};

/// Provide pointer API
/// iterator_traits contract:	
///		Elem_t - type of nominaly iterated elements
///		Val_t - type of formaly iterated element
///		Arg_t - argument type
///		PtrE_t - pointer type to nominaly iterated element
///		PtrV_t - pointer type to formaly iterated element
///		RefE_t - reference to nominaly iterated element
///		RefV_t - reference to formaly iterated element

// Example: List iterator iterates Node<T> elements (Elem_t), but provide API on type T (Val_t)

template<typename element,
		typename wrapper = element>
struct iterator_traits : public base_traits<element> {

	using Elem_t = wrapper;
	using PtrE_t = Elem_t*;
	using PtrV_t = Val_t*;
	using RefE_t = Elem_t&;
	using RefV_t = Val_t&;
};
