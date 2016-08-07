#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> &selection_sort (std::vector<int> &v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		auto smallest = std::min_element (it, v.end());
		std::iter_swap (it, smallest);
	}
	return v;
}

int main()
{
	std::vector<int> v = {8, 2, 3, 4, 7, 1, 5, 9, 10, 6};
	v = selection_sort (v);
	for (auto &i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}
