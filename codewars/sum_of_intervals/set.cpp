#include <string>
#include <iostream>

#include <algorithm>

#include <vector>
#include <utility>
#include <set>


int sum_intervals(std::vector<std::pair<int, int>> intervals) {
	std::set<int> s;
	for(auto p: intervals)
	{
		for(int i=p.first; i<p.second; i++) s.insert(i);
	}
	return s.size();
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
