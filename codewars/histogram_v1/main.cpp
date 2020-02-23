#include <string>
#include <iostream>

#include <vector>
#include <sstream>

std::string histogram(std::vector<int> results)
{
	std::stringstream ss;
	int count = 6;
	for(auto n: results)
	{
		ss << count-- << '-';
		for(int i=0;i<n;i++)
		{
			ss << '#';
		}
		ss << std::endl;
	}
	
    return ss.str();
}

int main()
{
	std::string expected = "    10\n"
						   "    #\n"
						   "    #\n"
						   "7   #\n"
						   "#   #\n"
						   "#   #     5\n"
						   "#   #     #\n"
						   "# 3 #     #\n"
						   "# # #     #\n"
						   "# # # 1   #\n"
						   "# # # #   #\n"
						   "-----------\n"
						   "1 2 3 4 5 6\n";
	
	std::string actual = histogram({ 7, 3, 10, 1, 0, 5 });
	
	std::cout << actual << "\nshould equal: \n" << expected << std::endl;
	return 0;
}
