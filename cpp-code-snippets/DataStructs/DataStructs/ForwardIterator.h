#pragma once

#include "Iterator_base.h"
#include "ForwardIterator_type.h"
#include "TemplateMagic.h"


// aliases section
template <typename value_t,
		  typename wrapper_t = value_t>
using forward_iterator_traits = iterator_traits<value_t, wrapper_t>;


template <typename T,
		  typename wrapper_t = T>
using forward_iterator_base = typename Iterator_base<	T,
	forward_iterator_traits<T, wrapper_t>,
	typename ForwardIterator_type<forward_iterator_traits<T, wrapper_t>>>;


// iterator interface
template <typename value_t,
		typename wrapper_t = value_t>
class ForwardIterator : public forward_iterator_base<value_t, wrapper_t> {
public:

	ForwardIterator(const PtrE_t& src = nullptr) noexcept : forward_iterator_base<value_t, wrapper_t>(src) {
		start = src;
	}

	// use copy const of base class, becouse need `src` ptr at body of func
	ForwardIterator(PtrE_t&& src) noexcept : forward_iterator_base<value_t, wrapper_t>(src) {
		start = src;

		src = nullptr;
	}
	ForwardIterator(const ForwardIterator& src) noexcept : forward_iterator_base<value_t, wrapper_t>(src) {
		start = src.start;
	}
	ForwardIterator(ForwardIterator&& src) noexcept : forward_iterator_base<value_t, wrapper_t>(std::move(src)) {
		movePtr(start, src.start);
	}


	// Reinit section
	virtual ForwardIterator& operator= (const ForwardIterator& src) noexcept;
	virtual ForwardIterator& operator= (ForwardIterator&& src) noexcept;
	ForwardIterator& operator= (const PtrE_t& src) noexcept override;
	ForwardIterator& operator= (PtrE_t&& src) noexcept override;


	// Logical section
	virtual bool operator== (const ForwardIterator& iter) const noexcept;
	virtual bool operator!= (ForwardIterator iter) const noexcept;
	bool operator== (PtrE_t iter) const noexcept override;
	bool operator!= (PtrE_t iter) const noexcept override;


	// Move section
	ForwardIterator& operator++ () noexcept override;
	virtual ForwardIterator operator++ (int) noexcept;


	// Acess section
	RefV_t operator* () const noexcept override;
	PtrV_t operator-> () const noexcept override;


	// Special methods
	void reverse() noexcept override;
	virtual ForwardIterator getNext() noexcept;


	virtual ~ForwardIterator() = default;
};



// iterator implementation
template <typename value_t,
	typename wrapper_t>
ForwardIterator<value_t, wrapper_t>& ForwardIterator<value_t, wrapper_t>::operator= (const ForwardIterator& src) noexcept {
	if (&src == this)
		return *this;

	pElem = src.pElem;
	start = src.start;

	return *this;
}

template <typename value_t,
	typename wrapper_t>
ForwardIterator<value_t, wrapper_t>& ForwardIterator<value_t, wrapper_t>::operator= (ForwardIterator&& src) noexcept {
	if (&src == this)
		return *this;

	pElem = src.pElem;
	src.pElem = nullptr;

	start = src.start;
	src.start = nullptr;

	return *this;
}

template <typename value_t,
	typename wrapper_t>
ForwardIterator<value_t, wrapper_t>& ForwardIterator<value_t, wrapper_t>::operator= (const PtrE_t& src) noexcept {
	if (src == pElem)
		return *this;

	pElem = src;

	return *this;
}

template <typename value_t,
	typename wrapper_t>
	ForwardIterator<value_t, wrapper_t>& ForwardIterator<value_t, wrapper_t>::operator= (PtrE_t&& src) noexcept {
	if (src == pElem)
		return *this;

	movePtr(pElem, src);

	return *this;
}



template <typename value_t,
	typename wrapper_t>
bool ForwardIterator<value_t, wrapper_t>::operator== (const ForwardIterator& iter) const  noexcept {
	if (iter.pElem != pElem) {
		return false;
	}

	return true;
}

template <typename value_t,
	typename wrapper_t>
bool ForwardIterator<value_t, wrapper_t>::operator== (PtrE_t iter) const  noexcept {
	if (iter != pElem) {
		return false;
	}

	return true;
}

template <typename value_t,
	typename wrapper_t>
bool ForwardIterator<value_t, wrapper_t>::operator!= (ForwardIterator iter) const  noexcept {
	if (iter.pElem != pElem) {
		return true;
	}

	return false;
}

template <typename value_t,
	typename wrapper_t>
bool ForwardIterator<value_t, wrapper_t>::operator!= (PtrE_t iter) const  noexcept {
	if (iter != pElem) {
		return true;
	}

	return false;
}



template <typename value_t,
	typename wrapper_t>
ForwardIterator<value_t, wrapper_t>& ForwardIterator<value_t, wrapper_t>::operator++ () noexcept {

	pElem++;

	return *this;
}

template <typename value_t,
	typename wrapper_t>
ForwardIterator<value_t, wrapper_t> ForwardIterator<value_t, wrapper_t>::operator++ (int) noexcept {

	ForwardIterator temp(pElem);
	pElem++;

	return std::move(temp);
}

template <typename value_t,
	typename wrapper_t>
typename ForwardIterator<value_t, wrapper_t>::RefV_t ForwardIterator<value_t, wrapper_t>::operator* () const noexcept {
	return *pElem;
}

template <typename value_t,
	typename wrapper_t>
typename ForwardIterator<value_t, wrapper_t>::PtrV_t ForwardIterator<value_t, wrapper_t>::operator-> () const noexcept {
	return pElem;
}


template <typename value_t,
	typename wrapper_t>
void ForwardIterator<value_t, wrapper_t>::reverse() noexcept {
	pElem = start;
}

template <typename value_t,
	typename wrapper_t>
ForwardIterator<value_t, wrapper_t> ForwardIterator<value_t, wrapper_t>::getNext() noexcept {
	return (pElem + 1);
}