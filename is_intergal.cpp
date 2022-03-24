#pragma once

#include <>
template <class T>
struct is_integral
{
    typedef T type;
    typedef bool value_type;
    static const bool value = false;
};
template <>
struct is_integral<bool>
{
    typedef bool type;
    typedef bool value_type;
    static const bool value = true;
};

template <>
struct is_integral<char>
{
    typedef char type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<char16_t>
{
    typedef char16_t type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<char32_t>
{
    typedef char32_t type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<wchar_t>
{
    typedef wchar_t type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<signed char>
{
    typedef signed char type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<short int>
{
    typedef short int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<int>
{
    typedef int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<long int>
{
    typedef long int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<long long int>
{
    typedef long long int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<unsigned char>
{
    typedef unsigned char type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<unsigned short int>
{
    typedef unsigned short int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<unsigned int>
{
    typedef unsigned int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<unsigned long int>
{
    typedef unsigned long int type;
    typedef bool value_type;
    static const bool value = true;
};
template <>
struct is_integral<unsigned long long int>
{
    typedef unsigned long long int type;
    typedef bool value_type;
    static const bool value = true;
};