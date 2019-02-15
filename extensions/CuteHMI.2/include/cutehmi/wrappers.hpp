#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <algorithm>
#include <iterator>

namespace cutehmi {

template <class INPUT_IT, class SIZE, class OUTPUT_IT>
OUTPUT_IT copy_n(INPUT_IT first, SIZE count, OUTPUT_IT result);

template <class INPUT_IT1, class INPUT_IT2>
bool equal(INPUT_IT1 first1, INPUT_IT1 last1, INPUT_IT2 first2);

template <class INPUT_IT, class SIZE, class OUTPUT_IT>
OUTPUT_IT copy_n(INPUT_IT first, SIZE count, OUTPUT_IT result)
{
	// Avoid MSVC C4996 warning, when using std::copy_n with raw pointers.
#ifdef _MSC_VER
	return ::std::copy_n(first, count, ::stdext::checked_array_iterator<OUTPUT_IT>(result, count)).base();
#else
	return ::std::copy_n(first, count, result);
#endif
}

template <class INPUT_IT1, class INPUT_IT2>
bool equal(INPUT_IT1 first1, INPUT_IT1 last1, INPUT_IT2 first2)
{
	// Avoid MSVC C4996 warning, when using std::copy_n with raw pointers.
#ifdef _MSC_VER
	return ::std::equal(first1, last1, ::stdext::make_unchecked_array_iterator(first2));
#else
	return ::std::equal(first1, last1, first2);
#endif
}

}

#endif // FUNCTIONS_HPP
