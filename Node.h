#pragma once
#include "header.h"

class Node
{
public:
	Node();
	~Node() /*{ delete this->pNext; }*/;
	Node(ClassData StudentData);
	Node(const Node &copyNode);

	//Getters
	Node * getpNext() const;
	int getAbsences() const;
	int getRecord() const;
	int getID() const;
	int getUnits() const;
	ClassData getVars() const;
	string getName() const;
	string getEmail() const;
	string getMajor() const;
	string getLevel() const;
	string getAbsentDate();
	StackAbsence getAbList() const;

	//Setters
	void setpNext(Node * const newNode);
	void setAbsences(int Data);
	void setRecord(int Data);
	void setID(int Data);
	void setUnits(int Data);
	void setName(string Data);
	void setEmail(string Data);
	void setMajor(string Data);
	void setLevel(string Data);
	void setAbsentDate();
	void setAbsenceStack(StackAbsence Data);

private:
	ClassData mStudentData;
	Node *pNext = (Node *)malloc(sizeof(Node));
};