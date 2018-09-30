#pragma once
//#include "header.h"
#include <string>
using std::string;

class StackAbsence
{
public:
	StackAbsence();
	~StackAbsence();

	void push(string data);

	string pop();
	string peek();
	bool isEmpty();
private:
	int mIndex;
	string mData[100];
};
