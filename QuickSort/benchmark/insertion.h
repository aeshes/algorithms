#pragma once
#include <algorithm>
#include <iterator>

template<class I>
void insertion_sort(I begin, I end)
{
	for (auto i = begin; i != end; ++i)
	{
		auto index = std::upper_bound(begin, i, *i);
		std::rotate(index, i, i + 1);
	}
}