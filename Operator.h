#pragma once
#include "header.h"
#include "LinkClass.h"

void readFile(LinkClass **pHead);

void readMasterToList(LinkClass **pList);

void writeMaster(LinkClass *pHead);

void attendence(LinkClass **pHead);

string editName(string newString);

void genReport(LinkClass *pHead);

void genReport(LinkClass *pHead, int swap);

string editAscii(string newString);

void editAbsences(LinkClass **pHead);
