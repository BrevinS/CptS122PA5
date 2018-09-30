#include "Node.h"

Node::Node() {
	mStudentData.mAbsences = mStudentData.mRecord = mStudentData.mID = mStudentData.mUnits = NULL;
	mStudentData.mName = mStudentData.mEmail = mStudentData.mMajor = mStudentData.mLevel = "";
	pNext = nullptr;
}

Node::~Node() {
	delete this->pNext;
}

Node::Node(ClassData StudentData) {
	mStudentData.mAbsences = StudentData.mAbsences;
	mStudentData.mRecord = StudentData.mRecord;
	mStudentData.mID = StudentData.mID;
	mStudentData.mUnits = StudentData.mUnits;
	mStudentData.mName = StudentData.mName;
	mStudentData.mEmail = StudentData.mEmail;
	mStudentData.mMajor = StudentData.mMajor;
	mStudentData.mLevel = StudentData.mLevel;
	mStudentData.dateOfAbsences = StudentData.dateOfAbsences;
	pNext = nullptr;
}

Node::Node(const Node &copyNode) {
	this->mStudentData.mAbsences = copyNode.getAbsences();
	this->mStudentData.mRecord = copyNode.getRecord();
	this->mStudentData.mID = copyNode.getID();
	this->mStudentData.mUnits = copyNode.getUnits();
	this->mStudentData.mName = copyNode.getName();
	this->mStudentData.mEmail = copyNode.getEmail();
	this->mStudentData.mMajor = copyNode.getMajor();
	this->mStudentData.mLevel = copyNode.getLevel();
	this->mStudentData.dateOfAbsences = copyNode.getAbList();
	this->pNext = copyNode.getpNext();
}

//GETTERS
Node * Node::getpNext() const {
	return pNext;
}

int Node::getAbsences() const {
	return mStudentData.mAbsences;
}

int Node::getRecord() const {
	return mStudentData.mRecord;
}

int Node::getID() const {
	return mStudentData.mID;
}

int Node::getUnits() const {
	return mStudentData.mUnits;
}

ClassData Node::getVars() const {
	return mStudentData;
}

string Node::getName() const {
	return mStudentData.mName;
}

string Node::getEmail() const {
	return mStudentData.mEmail;
}

string Node::getMajor() const {
	return mStudentData.mMajor;
}

string Node::getLevel() const {
	return mStudentData.mLevel;
}

StackAbsence Node::getAbList() const {
	return mStudentData.dateOfAbsences;
}

string Node::getAbsentDate() {
	return mStudentData.dateOfAbsences.peek();
}

//SETTERS
void Node::setpNext(Node * const newNode) {
	pNext = newNode;
}

void Node::setAbsences(int Data) {
	mStudentData.mAbsences = Data;
}

void Node::setRecord(int Data) {
	mStudentData.mRecord = Data;
}

void Node::setID(int Data) {
	mStudentData.mID = Data;
}

void Node::setUnits(int Data) {
	mStudentData.mUnits = Data;
}

void Node::setName(string Data) {
	mStudentData.mName = Data;
}

void Node::setEmail(string Data) {
	mStudentData.mEmail = Data;
}

void Node::setMajor(string Data) {
	mStudentData.mMajor = Data;
}

void Node::setLevel(string Data) {
	mStudentData.mLevel = Data;
}

void Node::setAbsenceStack(StackAbsence Data) {
	mStudentData.dateOfAbsences = Data;
}

//Cite: https://eecs.wsu.edu/~aofallon/cpts122/labs/Lab11.htm
void Node::setAbsentDate() {
	stringstream date;

	time_t t = time(0);
	struct tm * now = localtime(&t);
	date << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday;

	mStudentData.dateOfAbsences.push(date.str());
	setAbsences(getAbsences() + 1);
}