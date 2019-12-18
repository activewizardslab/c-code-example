#pragma once


template<typename T>
struct base_traits {
	using Val_t = T;
	using Arg_t = T&;
	using Ptr_t = Val_t*;
	using Ref_t = Val_t&;
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

template<typename T>
struct iterator_traits : base_traits<T> {
	using Elem_t = T;
	using PtrE_t = Elem_t*;
	using PtrV_t = Val_t*;
	using RefE_t = Elem_t&;
	using RefV_t = Val_t&;
};


/// Provide pointer API
/// Iterator_base contract:	
///		template parameters:
///			T - formaly iterated type
///			iterator_type - type of iterator @see ::iterator_types
///			traits - incapsulate and automize type declaration @see iterator_traits<..>

///		API:
///				

template<typename T, 
		typename iterator_type,
		typename traits = iterator_traits<T>>
class Iterator_base /*: iterator_type*/
{
protected:
	using Val_t  = traits::Val_t;
	using Elem_t = traits::Elem_t;
	using PtrE_t = traits::PtrE_t;
	using PtrV_t = traits::PtrV_t;
	using RefE_t = traits::RefE_t;
	using RefV_t = traits::RefV_t;
	
public:

	Iterator_base() {}
	Iterator_base(PtrE_t pElem) {}


	bool operator == (Iterator_base iter) {}
	bool operator == (PtrE_t iter) {}
	bool operator != (Iterator_base iter) {}
	bool operator != (PtrE_t iter) {}


	PtrE_t& next(){}


	RefV_t operator *(){}
	PtrV_t operator ->(){}


	//~Iterator_base();
};

