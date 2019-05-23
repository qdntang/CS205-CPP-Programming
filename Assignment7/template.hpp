#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>

template<class, class = void>
struct is_incrementable : std::false_type {};

template<class T>
struct is_incrementable<T, std::void_t<decltype(((++std::declval<T&>())++))>> : std::true_type {};
