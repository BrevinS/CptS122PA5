#pragma once
#include "header.h"
#include "Node.h"

class LinkClass
{
public:
	LinkClass();
	~LinkClass();
	//Setters
	Node * getmpHead() const;
	bool isEmpty();
	//Getters
	void setmpHead(Node * const pHead);
	void pushNode(Node *newNode);
private:
	Node *mpHead;
};
