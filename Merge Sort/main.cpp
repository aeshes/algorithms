#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


template<class Iter>
void merge_sort(Iter begin, Iter end)
{
	const auto dist = std::distance(begin, end);
	if (dist > 1)
	{
		const auto mid = begin + dist / 2;
		merge_sort(begin, mid);
		merge_sort(mid, end);
		std::inplace_merge(begin, mid, end);
	}
}

int main()
{
	std::vector<int> v = { 4, 2, 10, 7, 5, 6, 3, 1, 8, 9 };
	merge_sort(v.begin(), v.end());

	for (const auto &i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}