#include "AttendenceWrapper.h"

int main(void) {
	AttendenceWrapper menu = AttendenceWrapper();
	LinkClass *pHead = (LinkClass *)malloc(sizeof(LinkClass));
	pHead->setmpHead(NULL);

	cin >> menu;
	while (menu.run(&pHead)) {
		cin >> menu;
	}

	delete pHead;
}