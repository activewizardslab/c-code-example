#pragma once
#include <type_traits>

template<typename traits>
struct ForwardIterator_type
{
	using Val_t  = typename traits::Val_t;
	using Elem_t = typename traits::Elem_t;
	using PtrE_t = typename traits::PtrE_t;
	using PtrV_t = typename traits::PtrV_t;
	using RefE_t = typename traits::RefE_t;
	using RefV_t = typename traits::RefV_t;

	virtual void reverse() = 0;
	//virtual PtrE_t next();

protected:
	PtrE_t start;
};

