#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Student
{
private:
	string sid;        //Student ID.
	string name;       //Student name.
	string dname;       //Degree name.
	string sem;         // Semester.
	string nib;         //NO. Of Issued books.
	ifstream input1;
	ofstream output1;
public:
	void add();
	void modify();
	void search();
	void Delete();
};
