#include<string>
#include<iostream>

#include <sstream>
#include <vector>

int YEAR = 60*60*24*365;
int DAY = 60*60*24;
int HOUR = 60*60;
int MINUTE = 60;

std::string time_part(std::string timeString, int timeAmount)
{
	std::stringstream ss;
	if(timeAmount >= 1)
	{
		ss << timeAmount << ' ' << timeString;
	}
	if(timeAmount > 1)
	{
		ss << "s";
	}
	return ss.str();
}

std::string format_duration(int s)
{
	std::stringstream ss;
	std::vector<std::string> parts;
	if(s == 0) return "now";
	int years=0,days=0,hours=0,minutes=0;
	if(s >= YEAR)
	{
		years = s/YEAR;
		s %= YEAR;
		if(years > 0) parts.push_back(time_part("year", years));
	}
	if(s >= DAY)
	{
		days = s/DAY;
		s %= DAY;
		if(days > 0) parts.push_back(time_part("day", days));
	}
	if(s >= HOUR)
	{
		hours = s/HOUR;
		s %= HOUR;
		if(hours > 0) parts.push_back(time_part("hour", hours));
	}
	if(s >= MINUTE)
	{
		minutes = s/MINUTE;
		s %= MINUTE;
		if(minutes > 0) parts.push_back(time_part("minute", minutes));
	}
	if(s > 0) parts.push_back(time_part("second", s));

	if(parts.size() == 1)
	{
		ss << parts.at(0);
		return ss.str();
	}
	for(int i=0; i<parts.size()-2; ++i)
	{
		ss << parts.at(i) << ", ";
	}
	ss << parts.at(parts.size()-2);
	ss << " and " << parts.back();
	return ss.str();
}

int main()
{
	std::cout << format_duration(0) << " --- " << "now" << std::endl << std::endl;
	std::cout << format_duration(1) <<  " --- " << "1 second" << std::endl << std::endl;
    std::cout << format_duration(62) << " --- " << "1 minute and 2 seconds" << std::endl << std::endl;
    std::cout << format_duration(120) <<  " --- " << "2 minutes" << std::endl << std::endl;
    std::cout << format_duration(3662) << " --- " << "1 hour, 1 minute and 2 seconds" << std::endl << std::endl;
    std::cout << format_duration(DAY) << " --- " << "1 hour, 1 minute and 2 seconds" << std::endl << std::endl;
    std::cout << format_duration(DAY+YEAR) << " --- " << "1 year and 1 day" << std::endl << std::endl;
    std::cout << format_duration(YEAR) << " --- " << "1 year" << std::endl << std::endl;
    std::cout << format_duration(YEAR+3662) << " --- " << "1 year, 1 hour, 1 minute and 2 seconds" << std::endl << std::endl;
    std::cout << format_duration(2*YEAR) << " --- " << "2 years" << std::endl << std::endl;
	return 0;
}
