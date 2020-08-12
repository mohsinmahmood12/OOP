#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;
void Student::add()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid, name, dname, sem, nib;
	cout << "\nEnter the attributes for student which you want to add in the class!!" << endl;
	cout << endl;
	cout << "Enter the student ID\t:";
	cin >> sid;
	cout << endl;
	cout << "Enter the name of the student\t:";
	cin >> name;
	cout << endl;
	cout << "Enter the Degree Name of the student\t:";
	cin >> dname;
	cout << endl;
	cout << "Enter the semester of the student\t:";
	cin >> sem;
	cout << endl;
	cout << "Enter the number of issued books to the name of that student\t:";
	cin >> nib;
	cout << endl;
	ofstream output1;
	output1.open("student.txt", ios::app);
	if (!output1)
	{
		cout << "Student cannot be added in the class!!!!" << endl;
	}
	else
	{
		output1 << "\n" << sid << "\t\t" << name << "\t\t" << dname << "\t\t" << sem << "\t\t" << nib << "\n";
		cout << endl;
		output1.close();
		cout << "\nYou have successfully added a student in the class!!!" << endl;
	}
}
void Student::modify()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid, name, dname, sem, nib, id;
	int n1 = 0, n2 = 0;
	ifstream input("student.txt");
	ofstream output("temp.txt");
	cout << "\nEnter  student Id(which u wnt to  record modify)\t:";
	cin >> id;
	cout << endl;
	if (!input)
	{
		cout << "Input file failed to open(not exist)\n";
	}
	else
	{
		while (input >> sid >> name >> dname >> sem >> nib)
		{
			n1++;
			if (id == sid)
			{
				string sid, name, dname, sem, nib;
				cout << endl << "Yes,this student id record exist" << endl;
				cout << "\nEnter the attributes for student which you want to add in the class!!" << endl;
				cout << endl;
				cout << "Enter the student ID\t:";
				cin >> sid;
				cout << endl;
				cout << "Enter the name of the student\t:";
				cin >> name;
				cout << endl;
				cout << "Enter the Degree Name of the student\t:";
				cin >> dname;
				cout << endl;
				cout << "Enter the semester of the student\t:";
				cin >> sem;
				cout << endl;
				cout << "Enter the number of issued books to the name of that student\t:" << endl;
				cin >> nib;
				cout << endl;
				output << "\n" << sid << "\t\t" << name << "\t\t " << dname << "\t\t" << sem << "\t\t " << nib << "\n";
				cout << endl;
				cout << "You have successfully added a student in the class after modifying!!!" << endl;
			}
			else
			{
				n2++;
				output << "\n" << sid << "\t\t" << name << "\t\t" << dname << "\t\t" << sem << "\t\t" << nib << "\n";
			}
		}
		if (n1 == n2)
		{
			cout << "\nCannot be modified b/c given student ID recrd not exist !" << endl;
		}
		input.close();
		output.close();
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}
}
void Student::search()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid1, name1, dname1, sem1, nib1;
	int n1 = 0, n2 = 0;
	string x;
	ifstream input1;
	cout << "\nEnter the student id for finding his record in the class" << endl;
	cout << endl;
	cout << "Enter the stdID\t:";
	cin >> x;
	cout << endl;
	input1.open("student.txt", ios::in);
	if (!input1)
	{
		cout << "File cannot be opened!!!" << endl;
	}
	else
	{
		while (!input1.eof())
		{
			n1++;
			input1 >> sid1 >> name1 >> dname1 >> sem1 >> nib1;
			if (sid1 == x)
			{
				cout << "Student of entered Id is as follows!" << endl;
				cout << "\n" << name1 << "\t\t" << dname1 << "\t\t" << sem1 << "\t\t" << nib1 << "\n" << endl;
			}
			else
			{
				n2++;
			}
		}
		if (n1 == n2)
		{
			cout << "\nRecord of entered student ID not exist so can't be searched'!" << endl;
		}
	}
}
void Student::Delete()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	int i = 0;
	char sid[30], sn[30], dn[30], sen[30], nob[30];
	int n1 = 0, n2 = 0;
	string fsid;
	cout << "Enter student_ID for delete : ";
	cin >> sid;
	cout << endl;
	for (i = 0; sid[i] != '\0'; i++);
	ifstream input("student.txt");
	if (!input)
	{
		cout << "Input file failed to open\n";
	}
	else
	{
		ofstream output("temp.txt");
		while (input >> fsid >> sn >> dn >> sen >> nob)
		{
			n1++;
			if (sid == fsid)
			{
				cout << "The entered ID of student has been deleted  !" << endl;
			}
			else
			{
				n2++;
				output << "\n" << fsid << "\t\t" << sn << "\t\t" << dn << "\t\t" << sen << "\t\t" << nob << "\n";
			}

		}
		if (n1 == n2)
		{
			cout << "\nThe entered ID of student has not been deleted b/c recrd not exist !" << endl;
			cout << endl;
		}
		input.close();
		output.close();
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}
}
