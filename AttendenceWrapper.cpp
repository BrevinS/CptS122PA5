#include "AttendenceWrapper.h"

AttendenceWrapper::AttendenceWrapper() {
	mMenuOption = -1;
}

AttendenceWrapper::~AttendenceWrapper() {
	return;
}

int AttendenceWrapper::getOption() {
	return mMenuOption;
}

void AttendenceWrapper::setMenu(int Menu) {
	mMenuOption = Menu;
}

void AttendenceWrapper::makeMenu() {
	cout << "1.)\tImport course list" << endl
		<< "2.)\tLoad master list" << endl
		<< "3.)\tStore master list" << endl
		<< "4.)\tMark absences" << endl
		<< "5.)\tEdit absences" << endl
		<< "6.)\tGenerate report" << endl
		<< "7.)\tExit" << endl;
}

bool AttendenceWrapper::run(LinkClass **pHead) {
	LinkClass *pCur = *pHead;
	int menuOption;

	switch (mMenuOption) {
	case 1:
		readFile(&pCur);
		break;
	case 2:
		readMasterToList(&pCur);
		break;
	case 3:
		writeMaster(pCur);
		break;
	case 4:
		attendence(&pCur);
		break;
	case 5:
		editAbsences(&pCur);
		break;
	case 6:
		cout << "1.)\tGenerate report for all students" << endl
			<< "2.)\tGenerate report for students with certain number of absences" << endl
			<< "-> ";
		cin >> menuOption;

		switch (menuOption) {
		case 1:
			genReport(pCur);
			break;
		case 2:
			cout << "How many absences?" << endl << "-> ";
			cin >> menuOption;
			genReport(pCur, menuOption);
			break;
		}
		break;
	default:
		cout << "Invalid input" << endl;
	case 7:
		cout << endl << "Exiting!" << endl;
		return false;
	}
	*pHead = pCur;
	return true;
}

istream& operator >> (istream &insert, AttendenceWrapper &attendencewrapper) {
	int newSet;

	attendencewrapper.makeMenu();
	cout << "> ";

	cin >> newSet;
	attendencewrapper.setMenu(newSet);

	cout << endl;

	return insert;
}