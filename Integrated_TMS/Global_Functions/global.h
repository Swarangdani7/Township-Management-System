#ifndef GLOBAL_H
#define GLOBAL_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

namespace IO_FILE
{
	vector<vector<string>> readData(ifstream&);
}

namespace Date
{
	int getDay();
	int getMonth();
	int getYear();
}

namespace Time
{
	int getHour();
	int getMinute();
	int getSecond();
}
#endif
