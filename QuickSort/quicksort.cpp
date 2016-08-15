#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <thread>


template<class Iter>
Iter partition(Iter first, Iter last)
{
	Iter pivot = last - 1;
	Iter right = first;
	for (auto unknown = first; unknown != last - 1; ++unknown)
	{
		if (*unknown <= *pivot)
		{
			std::iter_swap(right, unknown);
			++right;
		}
	}
	std::iter_swap(right, pivot);
	return right;
}

template<class Iter>
void quick_sort(Iter first, Iter last)
{
	if (std::distance(first, last) > 1)
	{
		auto q = partition(first, last);
		quick_sort(first, q);
		quick_sort(q + 1, last);
	}
}

template<class Iter>
void print(Iter first, Iter last)
{
	while (first != last)
	{
		std::cout << *first << " ";
		++first;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v = { 6, 17, 1, 3, 2, 9, 19, 8, 4, 11 };

	quick_sort(v.begin(), v.end());
	print(v.begin(), v.end());
}