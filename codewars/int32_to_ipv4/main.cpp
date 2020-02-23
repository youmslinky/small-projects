#include<string>
#include<iostream>
#include<sstream>


std::string uint32_to_ip(uint32_t ip)
{
	std::stringstream ss;
	for(int i=24;i>0;i-=8){
		ss << +(uint8_t)(ip>>i) << "."; 
	}
	ss << +(uint8_t)ip; 
	return ss.str();
}

int main()
{
	std::cout << uint32_to_ip(2154959208) << std::endl;
	return 0;
}
