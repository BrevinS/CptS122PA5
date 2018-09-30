#include "LinkClass.h"

LinkClass::LinkClass() {
	mpHead = nullptr;
}

LinkClass::~LinkClass() {
	delete mpHead;
}

void LinkClass::pushNode(Node *newNode) {
	if (newNode != nullptr) {
		newNode->setpNext(mpHead);
		mpHead = newNode;
	}
}

Node * LinkClass::getmpHead() const {
	return mpHead;
}

bool LinkClass::isEmpty() {
	return mpHead == nullptr;
}

void LinkClass::setmpHead(Node * const pHead) {
	mpHead = pHead;
}