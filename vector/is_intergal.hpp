#pragma once

#include <cstdint>

template <class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  integral_constant() { return (v); }
};
template <typename T> 
	struct is_integral : public integral_constant<bool,false>
	{};
template <>
struct is_integral <char>: public integral_constant<char, true> {};
template <>
struct is_integral <char16_t>: public integral_constant<char16_t, true> {};
template <>
struct is_integral <char32_t>: public integral_constant<char32_t, true> {};
template <>
struct is_integral <wchar_t>: public integral_constant<wchar_t, true> {};
template <>
struct is_integral <signed char>: public integral_constant<signed char, true> {};
template <>
struct is_integral <short int>: public integral_constant<short int, true> {};
template <>
struct is_integral <int>: public integral_constant<int, true> {};
template <>
struct is_integral <long int>: public integral_constant<long int, true> {};
template <>
struct is_integral <unsigned char>: public integral_constant<unsigned char, true> {};
template <>
struct is_integral <unsigned int>: public integral_constant<unsigned int, true> {};
template <>
struct is_integral <unsigned short int>: public integral_constant<unsigned short int, true> {};
template <>
struct is_integral <long long int>: public integral_constant<long long int, true> {};
template <>
struct is_integral <unsigned long int>: public integral_constant<unsigned long int, true> {};
template <>
struct is_integral <unsigned long long int>: public integral_constant<unsigned long long int, true> {};