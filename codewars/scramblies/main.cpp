#include<string>
#include<iostream>
#include<algorithm>


bool scramble(const std::string& str1, const std::string& str2)
{
	std::string s1 = str1;
	std::string s2 = str2;
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	auto s2_iter = s2.begin();
	for(char const &c: s1)
	{
		if(*s2_iter == c)
		{
			s2_iter++;
		}
	}
	if(s2_iter == s2.end())
	{
		return true;
	}
	return false;
}

int main()
{
	std::cout << scramble("worldworld","rldow") << std::endl;
	return 0;
}
