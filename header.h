//Everything in here is for all files
#pragma once
#include <ctime>
#include <sstream>
#include <fstream>
#include "StackAbsence.h"
#include <iostream>

using std::getline;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::stringstream;
using std::string;
using std::to_string;
using std::stoi;
using std::cout;
using std::cin;
using std::endl;
using std::istream;

//Global struct for all files
typedef struct classData
{
	int mRecord;
	int mID;
	string mName;
	string mEmail;
	int mUnits;
	string mMajor;
	string mLevel;
	int mAbsences;
	StackAbsence dateOfAbsences;
} ClassData;