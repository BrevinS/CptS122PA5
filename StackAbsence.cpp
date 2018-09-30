#include "StackAbsence.h"

StackAbsence::StackAbsence() {
	mIndex = -1;
}

//Getter
void StackAbsence::push(string data) {
	mIndex++;
	mData[mIndex] = data;
}

//Setter
string StackAbsence::pop() {
	string cur = peek();
	mData[mIndex] = "";
	mIndex--;

	return cur;
}

//Removing
StackAbsence::~StackAbsence() {
	//Empty the stack
	while (!isEmpty()) {
		pop();
	}
}

//Setters
string StackAbsence::peek() {
	return mData[mIndex];
}

bool StackAbsence::isEmpty() {
	bool success = false;
	//mIndex value of (-1)
	if (mIndex == -1) {
		success = true;
	}
	return success;
}