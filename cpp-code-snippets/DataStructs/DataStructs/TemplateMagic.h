#pragma once

template <typename T>
struct removeRef {
	using value = T;
};

template <typename T>
struct removeRef<T&> {
	using value = T;
};

template <typename T>
struct removeRef<T&&> {
	using value = T;
};



template <typename T>
struct removePtr {
	using value = T;
};

template <typename T>
struct removePtr<T*> {
	using value = T;
};


template <typename T>
struct getType {
	using type = T;
};


template <typename T, bool>
struct EnableIf {

};

template <typename T>
struct EnableIf<T, true> {
	using type = T;
};


template <typename T1, typename T2>
struct isEquals {
	const static bool value = false;
};

template <typename T1>
struct isEquals<T1, T1> {
	const static bool value = true;
};