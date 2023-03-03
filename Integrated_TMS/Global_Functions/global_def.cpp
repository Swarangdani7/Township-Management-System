#include "global.h"

/* Function to read all records from a file */
vector<vector<string>> IO_FILE::readData(ifstream& in){
	string line,token;
	vector<vector<string>>record;
	vector<string>rec;
	
	while(getline(in,line))
	{	
		istringstream ss(line);
		while(getline(ss,token,',')) // function to tokenize string based on comma
		{
			rec.push_back(token);
		}
		record.push_back(rec);
		rec.clear();
	}
	return record;
}

int Date::getDay()
{
	time_t curr_time = time(0); // current date and time 
	tm *dt = localtime(&curr_time); // tm is strucure which holds date and time. localtime() returns pointer to tm 
	return (dt->tm_mday);
}

int Date::getMonth()
{
	time_t curr_time = time(0);
	tm *dt = localtime(&curr_time);
	return 1+(dt->tm_mon);
}

int Date::getYear()
{
	time_t curr_time = time(0);
	tm *dt = localtime(&curr_time);
	return 1900+(dt->tm_year);
}

int Time::getHour()
{
	time_t curr_time = time(0); // current date and time 
	tm *dt = localtime(&curr_time); // tm is strucure which holds date and time. localtime() returns pointer to tm 
	return (dt->tm_hour);
}

int Time::getMinute()
{
	time_t curr_time = time(0);
	tm *dt = localtime(&curr_time);
	return (dt->tm_min);
}

int Time::getSecond()
{
	time_t curr_time = time(0);
	tm *dt = localtime(&curr_time);
	return (dt->tm_sec);
}
