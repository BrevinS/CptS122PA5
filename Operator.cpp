#include "Operator.h"
//FILE FOR READING AND WRITING FUNCTIONS

void readFile(LinkClass **pList) {
	LinkClass *dataList = *pList;
	ClassData dataTemp = { NULL };
	ifstream infile("classList.csv");
	string line, data;
	int i = 0;
	line = "";
	//Problems on reading the file
	getline(infile, line, '\n');
	getline(infile, line, '\n');
	while (line != "") {
		istringstream iss(line);

		if (line.front() == *",")
			continue;

		for (int i = 0; i <= 7; i++) {
			getline(iss, data, ',');

			switch (i) {
			case 0:
				dataTemp.mRecord = stoi(data.c_str());
				break;
			case 1:
				dataTemp.mID = stoi(data.c_str());
				break;
			case 2:
				if (data.front() == *"\"")
					dataTemp.mName = data.erase(0, 1);
				break;
			case 3:
				if (data.back() == *"\"")
					dataTemp.mName = data.erase(data.size() - 1) + " " + dataTemp.mName;
				break;
			case 4:
				dataTemp.mEmail = data;
				break;
			case 5:
				if (data == "AU")
					dataTemp.mUnits = -1;
				else
					dataTemp.mUnits = stoi(data.c_str());
				break;
			case 6:
				dataTemp.mMajor = data;
				break;
			case 7:
				dataTemp.mLevel = data;
				break;
			}
		}
		Node *nodeTemp = new Node(dataTemp);
		dataList->pushNode(nodeTemp);
		line = "";
		getline(infile, line, '\n');
	}
	*pList = dataList;
	i++;
}

void attendence(LinkClass **pHead) {
	LinkClass *dataList = *pHead;
	Node *pTemp = dataList->getmpHead();

	int menu = 0;
	while (pTemp != NULL) {
		cout << endl << "Is " << pTemp->getName() << " absent? \n1.) Yes\n2.) No\n-> ";
		cin >> menu;

		if (menu == 1) {
			pTemp->setAbsentDate();
			cout << endl << pTemp->getName() << " marked absent." << endl;
		}

		pTemp = pTemp->getpNext();
	}

	*pHead = dataList;
}

void readMasterToList(LinkClass **pList) {
	LinkClass *dataList = *pList;
	ClassData dataTemp = { NULL };

	int index = 0;
	string line, data, temp, date;
	ifstream studentData("MasterList.txt");

	while (getline(studentData, line, '\n')) {
		istringstream iss(line);

		if (line.front() == *",")
			continue;

		for (int i = 0; i <= 9; i++) {
			getline(iss, data, ',');

			switch (i) {
			case 0:
				dataTemp.mRecord = stoi(data.c_str());
				break;
			case 1:
				dataTemp.mID = stoi(data.c_str());
				break;
			case 2:
				if (data.front() == *"\"")
					dataTemp.mName = data.erase(0, 1);
				break;
			case 3:
				if (data.back() == *"\"")
					dataTemp.mName = data.erase(data.size() - 1) + " " + dataTemp.mName;
				if (data.front() == *" ")
					dataTemp.mName.erase(0, 1);
				break;
			case 4:
				dataTemp.mEmail = data;
				break;
			case 5:
				if (data == "AU")
					dataTemp.mUnits = -1;
				else
					dataTemp.mUnits = stoi(data.c_str());
				break;
			case 6:
				dataTemp.mMajor = data;
				break;
			case 7:
				dataTemp.mLevel = data;
				break;
			case 8:
				dataTemp.mAbsences = stoi(data.c_str());
			case 9:
				if (data.at(0) == *"{")
					data.erase(0, 1);

				if (data == "}")
					break;
				else if (data.at(data.size() - 1) == *"}")
					data.erase(data.size() - 1);

				istringstream absenceListStream(data);

				while (getline(absenceListStream, date, ','))
					dataTemp.dateOfAbsences.push(date);
			}
		}

		Node *nodeTemp = new Node(dataTemp);
		dataList->pushNode(nodeTemp);
	}
	*pList = dataList;
}

string editName(string newString) {
	istringstream stream(newString);
	string string, out;
	int i = 0;

	while (getline(stream, string, ' ')) {
		if (i == 0) {
			out = string;
		}
		else if (i == 1) {
			out = "\"" + string + "," + out + "\"";
		}
		else {
			break;
		}
		i++;
	}
	return out;
}

void writeMaster(LinkClass *pHead) {
	LinkClass backup = *pHead;
	Node *pTemp = pHead->getmpHead();
	ofstream output("MasterList.txt", ofstream::out | ofstream::trunc);

	output << ",ID,Name,Email,Units,Program,Level,Absences,{AbsenceList}" << endl;

	while (pTemp != NULL) {
		string absenceList = "{";

		StackAbsence tempStack = pTemp->getAbList();
		for (int i = 0; i < pTemp->getAbsences(); i++) {
			absenceList += tempStack.pop();
		}

		absenceList += "}";

		stringstream lines;
		lines << pTemp->getRecord() << ","
			<< to_string(pTemp->getID()) << ","
			<< editName(pTemp->getName()) << ","
			<< pTemp->getEmail() << ","
			<< to_string(pTemp->getUnits()) << ","
			<< pTemp->getMajor() << ","
			<< pTemp->getLevel() << ","
			<< to_string(pTemp->getAbsences()) << ","
			<< absenceList;

		output << lines.str() << endl;

		pTemp = pTemp->getpNext();
	}

	output.close();
}

void genReport(LinkClass *pList) {
	Node *pCur = pList->getmpHead();
	ofstream output("CptsAttendanceReport.txt");

	while (pCur != NULL) {
		if (pCur->getAbsences() == 0)
			output << pCur->getName() << ",0," << endl;
		else
			output << pCur->getName() << "," << pCur->getAbsences() << "," << pCur->getAbsentDate() << endl;

		pCur = pCur->getpNext();
	}

	output.close();
}

void genReport(LinkClass *pList, int swap) {
	Node *pCur = pList->getmpHead();
	ofstream output("AttendanceReport.txt");

	while (pCur != NULL) {
		if (pCur->getAbsences() >= swap) {
			output << pCur->getName() << endl;

			StackAbsence tempList = pCur->getAbList();
			for (int i = 0; i < pCur->getAbsences(); i++)
				output << "\t" << i + 1 << ".) " << tempList.pop() << endl;
		}

		pCur = pCur->getpNext();
	}

	output.close();
}

string editAscii(string newString) {
	string temp = newString;
	for (int i = 0; i < newString.length(); i++) {
		temp[i] = tolower(temp[i]);
	}
	return temp;
}

void editAbsences(LinkClass **pHead) {
	LinkClass *dataList = *pHead;
	Node *pTemp = dataList->getmpHead();

	string studentName, newAbsenceDate;
	int absenceQuery, menuOption, AbsenceDate;

	cout << "Insert the name you would to edit, First then Last: ";
	cin.ignore(1, '\n');
	getline(cin, studentName);

	studentName = editAscii(studentName);

	while (pTemp != NULL) {
		if (studentName == editAscii(pTemp->getName()))
			break;
		pTemp = pTemp->getpNext();
	}

	if (editAscii(pTemp->getName()) != studentName) {
		cout << "Did not find name <" << studentName << ">" << endl << endl;
		return;
	}

	if (pTemp->getAbsences() == 0) {
		cout << "The student <" << pTemp->getName() << "> does not have an absence to edit" << endl << endl;
		return;
	}

	StackAbsence attendanceStack = pTemp->getAbList(), tempData;

	for (int i = 0; i < pTemp->getAbsences(); i++)
		cout << i + 1 << ".) " << attendanceStack.pop() << endl;

	cout << "What absence do you want to edit?" << endl;
	cin >> absenceQuery;

	if (absenceQuery > pTemp->getAbsences() || absenceQuery < 1) {
		cout << endl << "Invalid input, Please try again." << endl << endl;
		return;
	}

	attendanceStack = pTemp->getAbList();

	for (int i = 1; i <= absenceQuery; i++)
		tempData.push(attendanceStack.pop());

	cout << endl << "Press 1 to edit and 2 to delete" << endl;
	cin >> menuOption;

	if (menuOption == 1) {
		cout << endl << "Insert Year ";
		cin >> AbsenceDate;
		newAbsenceDate = to_string(AbsenceDate) + "-";

		cout << endl << "Insert Month";
		cin >> AbsenceDate;
		newAbsenceDate = newAbsenceDate + to_string(AbsenceDate) + "-";

		cout << endl << "Insert Day";
		cin >> AbsenceDate;
		newAbsenceDate = newAbsenceDate + to_string(AbsenceDate);

		attendanceStack.push(newAbsenceDate);
	}
	else if (menuOption == 2) {
		pTemp->setAbsences(pTemp->getAbsences() - 1);
	}
	else {
		cout << "Index out of bounds. Please try again." << endl << endl;
	}

	tempData.pop();
	while (!tempData.isEmpty())
		attendanceStack.push(tempData.pop());

	pTemp->setAbsenceStack(attendanceStack);

	cout << endl;

	*pHead = dataList;
}