#pragma once
#include "Operator.h"

class AttendenceWrapper
{
public:
	AttendenceWrapper();
	~AttendenceWrapper();

	int getOption();

	void setMenu(int Menu);

	void makeMenu();
	bool run(LinkClass **pHead);
private:
	int mMenuOption;
};

istream& operator >> (istream &insert, AttendenceWrapper &attendencewrapper);
