#include <iostream>
#include <vector>

typedef std::vector<int> vect_t;
typedef std::vector<int>::iterator vect_iter;

vect_iter bsearch (vect_t& v, int value)
{
	auto left  = v.begin();
	auto right = v.end();
	while (left != right)
	{
		auto mid = left + (right - left) / 2;
		if (*mid == value)
			return mid;
		else if (value > *mid)
			left = mid + 1;
		else
			right = mid;
	}
	return v.end();
}

vect_iter recursive_bsearch (vect_iter left, vect_iter right, int value)
{
	if (left != right)
	{
		auto mid = left + (right - left) / 2;
		if (*mid == value)
			return mid;
		else if (value > *mid)
			return recursive_bsearch (++mid, right, value);
		else
			return recursive_bsearch (left, --mid, value);
	}
	return right;
}

int main()
{
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << *bsearch(v, 7) << std::endl;
	std::cout << *bsearch(v, 3) << std::endl;
	std::cout << *bsearch(v, 11) << std::endl;

	std::cout << *recursive_bsearch(v.begin(), v.end(), 7) << std::endl;
    std::cout << *recursive_bsearch(v.begin(), v.end(), 3) << std::endl;
    std::cout << *recursive_bsearch(v.begin(), v.end(), 11) << std::endl;
}
