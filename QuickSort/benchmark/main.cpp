#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <vector>
#include <chrono>
#include "insertion.h"
#include "benchmark.h"


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

/* Classic quicksort implementation */
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

/* Use insertion sort instead of qsort when the length of sequence is <= 22*/
template<class Iter>
void qsort_insertion(Iter first, Iter last)
{
	if (std::distance(first, last) > 22)
	{
		auto q = partition(first, last);
		qsort_insertion(first, q);
		qsort_insertion(q + 1, last);
	}
	else insertion_sort(first, last);
}

/* Print range of elements */
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
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::vector<int> v;

	// Initial filling
	for (int i = 0; i < 70000; ++i)
		v.push_back(i);

	std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
	benchmark(v.begin(), v.end(), qsort_insertion, "Improvement with insertion sort when size < 22 elem");

	// Randomize vector
	std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
	benchmark(v.begin(), v.end(), quick_sort, "Simple quicksort");

	std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
	benchmark(v.begin(), v.end(), qsort_insertion, "Improvement with insertion sort when size < 22 elem");
}