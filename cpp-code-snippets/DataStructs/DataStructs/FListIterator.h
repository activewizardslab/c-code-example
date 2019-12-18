#pragma once

#include "Iterator_base.h"
#include "ForwardIterator_type.h"
#include "TemplateMagic.h"
#include "ForwardIterator.h"


template <typename T>
class FListIterator : public ForwardIterator<T, Node<T>>
{
public:

	// Construct section
	FListIterator(const PtrE_t& src = nullptr) noexcept : ForwardIterator<T, Node<T>>( src ) {}
	FListIterator(PtrE_t&& src) noexcept : ForwardIterator<T, Node<T>>( std::move(src) ) {}
	FListIterator(const FListIterator& src) noexcept : ForwardIterator<T, Node<T>>( src ) {}
	FListIterator(FListIterator&& src) noexcept : ForwardIterator<T, Node<T>>( std::move(src) ) {}


	// Move section
	ForwardIterator& operator++ () noexcept override;
	ForwardIterator operator++ (int) noexcept override;


	// Acess section
	RefV_t operator* () const noexcept override;
	PtrV_t operator-> () const noexcept override;


	// Special methods
	ForwardIterator getNext() noexcept override;
	virtual void setNext(PtrE_t) noexcept;


	virtual ~FListIterator() { std::cout << "dstr" << std::endl; }
};



//
//template <typename T>
//FListIterator<T>& FListIterator<T>::operator= (const FListIterator& src) noexcept {
//	if (&src == this)
//		return *this;
//
//	pElem = src.pElem;
//	start = src.start;
//
//	return *this;
//}
//
//template <typename T>
//FListIterator<T>& FListIterator<T>::operator= (FListIterator&& src) noexcept {
//	if (&src == this)
//		return *this;
//
//	pElem = src.pElem;
//	src.pElem = nullptr;
//
//	start = src.start;
//	src.start = nullptr;
//
//	return *this;
//}


template <typename T>
ForwardIterator<T, Node<T>>& FListIterator<T>::operator++ () noexcept {

	pElem = pElem->next;

	return *this;
}

template <typename T>
ForwardIterator<T, Node<T>> FListIterator<T>::operator++ (int) noexcept {

	FListIterator temp(pElem);
	pElem = pElem->next;

	return std::move(temp);
}


template <typename T>
typename FListIterator<T>::RefV_t FListIterator<T>::operator* () const noexcept {
	return pElem->element;
}

template <typename T>
typename FListIterator<T>::PtrV_t FListIterator<T>::operator-> () const noexcept {
	return &(pElem->element);
}


template <typename T>
ForwardIterator<T, Node<T>> FListIterator<T>::getNext() noexcept {
	return pElem->next;
}

template <typename T>
void FListIterator<T>::setNext(PtrE_t next) noexcept {
	pElem->next = next;
}