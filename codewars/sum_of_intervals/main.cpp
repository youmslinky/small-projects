#include <string>
#include <iostream>

#include <vector>
#include <utility>
#include <algorithm>


int sum_intervals(std::vector<std::pair<int, int>> intervals) {
	if(intervals.size() == 1)
	{
		return intervals.begin()->second - intervals.begin()->first;
	}
	int sum = 0;
	auto current = intervals.begin();
	for(auto other = current+1; other != intervals.end(); ++other)
	{
		std::cout << "current: " << current->first << "," << current->second << std::endl;
		std::cout << "other: " << other->first << "," << other->second << std::endl;
		if(current->second < other->first) break;
		if(current->second < other->first) break;
	}
	return sum;
}

int main()
{
	std::vector<std::pair<int, int>> intervals = {{1, 5}};
	int sum = sum_intervals(intervals);
	std::cout << sum << " should equal " << 4 << std::endl;
	
	intervals = {{1, 5}, {6, 10}};
	sum = sum_intervals(intervals);
	std::cout << sum << " should equal " << 8 << std::endl;

	intervals = {{1, 10}, {6, 10}};
	sum = sum_intervals(intervals);
	std::cout << sum << " should equal " << 9 << std::endl;
	return 0;
}
