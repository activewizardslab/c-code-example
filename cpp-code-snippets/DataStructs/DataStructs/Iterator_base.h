#pragma once
#include "Traits.h"


/// Provide pointer API
/// Iterator_base contract:	
///		template parameters:
///			T - formaly iterated type
///			iterator_type - type of iterator @see ::iterator_types
///			traits - incapsulate and automize type declaration @see iterator_traits<..> path://Traits.h

///		API:
///				

template<typename T, 
		typename traits,
		typename iterator_type>
class Iterator_base : public iterator_type
{
protected:
	// type declaration @see iterator_traits contract path://Traits.h

	using Val_t  = typename traits::Val_t;
	using Elem_t = typename traits::Elem_t;
	using PtrE_t = typename traits::PtrE_t;
	using PtrV_t = typename traits::PtrV_t;
	using RefE_t = typename traits::RefE_t;
	using RefV_t = typename traits::RefV_t;
	
	// Pointer to an element
	PtrE_t pElem;
	
public:

	// Construct section
	Iterator_base(const PtrE_t& pElem = nullptr) noexcept : pElem( pElem ) {}
	Iterator_base(PtrE_t&& src) noexcept : pElem( src ) {
		src = nullptr;
	}
	Iterator_base(const Iterator_base& src) noexcept : pElem( src.pElem ){}
	Iterator_base(Iterator_base&& src) noexcept : pElem( src.pElem ) {
		src.pElem = nullptr;
	}


	// Reinit section
	virtual Iterator_base& operator= (const PtrE_t& src) = 0;
	virtual Iterator_base& operator= (PtrE_t&& src) = 0;


	// Logical section	// for derived classes
	virtual bool operator== (PtrE_t iter) const = 0;
	virtual bool operator!= (PtrE_t iter) const = 0;


	// Move section
	virtual Iterator_base& operator++ () = 0;
	//virtual Iterator_base& operator++ (int) = 0; can return a ptr to a abstract class wrapped at smartPtr


	// Acess section
	virtual	RefV_t operator* () const = 0; 
	virtual PtrV_t operator-> () const = 0;


	virtual ~Iterator_base() = default;

protected:

	inline void movePtr(PtrE_t& to, PtrE_t& from) noexcept {
		to = from;
		from = nullptr;
	}

};
