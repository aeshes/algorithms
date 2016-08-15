#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <string>


template<class Iter>
inline void benchmark(Iter first,
					  Iter last,
					  void(*proc)(Iter first, Iter last),
					  std::string comment)
{
	typedef std::chrono::high_resolution_clock hr_clock;

	auto t1 = hr_clock::now();
	proc(first, last);
	auto t2 = hr_clock::now();

	std::cout << comment << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << " milliseconds" << std::endl;
	std::cout << std::endl << std::endl;
}
