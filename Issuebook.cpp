#include<iostream>
#include<fstream>
#include"Issuebook.h"
using namespace std;
int Idcheck, rcheck;
void Issuebook::search()
{

	string bid, nop, bn, an, in;
	string c;
	int n1 = 0, n2 = 0;
	ifstream input;
	cout << "Enter the book id of book which you want to search in the library:" << endl;
	cout << endl;
	cout << "Enter the BID \t: ";
	cin >> c;
	cout << endl;
	input.open("book.txt", ios::in);

	if (!input)
	{
		cout << "File cannot be opened!!!" << endl;
	}
	else
	{
		while (input >> bid >> nop >> bn >> an >> in)
		{
			n1++;
			if (bid == c)
			{
				cout << "\nThat book of ID exist in the library!" << endl;
			}
			else {
				n2++;
			}
		}
		if (n1 == n2)
		{
			cout << "\nbook do not exist!!" << endl;
		}
		cout << endl;
	}

	cout << endl;
}
void Issuebook::search2()        // For searching a student present in the class.
{
	string sid1, name1, dname1, sem1, nib1;
	int n1 = 0, n2 = 0;
	string x;
	ifstream input1;
	cout << "Enter the student id for finding his record in the class" << endl;
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
		while (input1 >> sid1 >> name1 >> dname1 >> sem1 >> nib1)
		{
			n1++;
			if (sid1 == x)
			{
				cout << "Student exist!" << endl;

			}
			else {
				n2++;
			}

		}
		if (n1 == n2)
		{
			cout << "\nStudent do not has the membership of library!!" << endl;
		}
		cout << endl;


	}

}
void Issuebook:: issue()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;

	int n = 0, t = 0, Uid, Urno;
	int ID, Rno, nop, noib;
	string Bkname, Stdname, Aname, Iname, Dep, semster;
	//validaty book
	cout << "Enter Book ID for searching\t:";
	cin >> Uid;
	cout << endl;
	ifstream input1("book.txt");
	if (!input1) {
		cout << "Error";
	}
	else {
		while (input1 >> ID >> nop >> Bkname >> Aname >> Iname) {
			if (Uid == ID) {
				n = 1;
				cout << "Found" << endl << endl;
				//student
				cout << "Enter Student ID for searching\t:";
				cin >> Urno;
				cout << endl;
				t = 0;
				ifstream input2("student.txt");
				if (!input2) {
					cout << "Error";
				}
				else {
					while (input2 >> Rno >> Stdname >> Dep >> semster >> noib) {
						if (Urno == Rno) {
							cout << "\nAvailable" << endl << endl;
							t = 1;
							if (noib == 0) {
								cout << "You can issue the book to this student." << endl << endl;
								int chk;
								cout << "Enter 1 to confirm book issuence\t:";
								cin >> chk;
								if (chk == 1) {
									ofstream issue("issuancebook.txt", ios::app);
									if (!issue) {
										cout << "error";
									}
									else {
										issue << ID << "\t\t" << nop << "\t\t" << Bkname << "\t\t" << Aname << "\t\t" << Iname << "\t\t" << Rno << "\n";
										cout << endl << endl << "book issued";
										Idcheck = ID;
										rcheck = Rno;
									}
									issue.close();

								}
							}
							else {
								cout << "You cannot issue the book." << endl;
							}
							break;
						}
					}
				}
				input2.close();
			}
		}
	}
	if (n != 1) {
		cout << "Book not found" << endl;
	}
	else if (t != 1) {
		cout << "Student Not found" << endl;
	}
	input1.close();
	//delete issed book
	ifstream indel("book.txt");
	if (!indel) {
		cout << "Error";
	}
	else {
		ofstream outdel("temp.txt", ios::out);
		if (!outdel) {
			cout << "Error";
		}
		else {
			while (indel >> ID >> nop >> Bkname >> Aname >> Iname) {
				if (Idcheck == ID) {
					cout << endl << "Deleting....(bid recrd from the book.txt file mean updated ) " << endl;
				}
				else {
					outdel << ID << "\t\t" << nop << "\t\t" << Bkname << "\t\t" << Aname << "\t\t" << Iname;
				}
			}
		}
		outdel.close();
	}
	indel.close();
	remove("book.txt");
	rename("temp.txt", "book.txt");
	//change student 
	ifstream indel1("student.txt");
	if (!indel1) {
		cout << "Error";
	}
	else {
		ofstream outdel1("temp.txt", ios::out);
		if (!outdel1)
		{
			cout << "Error";
		}
		else
		{
			while (indel1 >> Rno >> Stdname >> Dep >> semster >> noib)
			{
				if (rcheck == Rno)
				{

					cout << endl << "Changing....(student.txt file also updated) ";
					outdel1 << Rno << "\t\t" << Stdname << "\t\t" << Dep << "\t\t" << semster << "\t\t" << 1 << "\n";
				}
				else {
					outdel1 << Rno << "\t\t" << Stdname << "\t\t" << Dep << "\t\t" << semster << "\t\t" << 0 << "\n";
				}
			}
		}
		outdel1.close();
	}
	indel1.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");
}
void Issuebook::validity()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string a, b, c, d, e;
	fstream in;
	in.open("book.txt", ios::in);
	if (!in)
	{
		cout << "File opening error!" << endl;
	}
	else
	{
		while (in >> a >> b >> c >> d >> e)
		{
			search();
			break;
		}
		cout << endl;
	}
	string f, g, h, i, j, sidf;
	fstream inp;
	inp.open("student.txt", ios::in);
	if (!inp)
	{
		cout << "File opening error!" << endl;
	}
	else
	{
		while (inp >> f >> g >> h >> i >> j)
		{
			search2();
			break;
		}
		cout << endl;
	}
}
void Issuebook::lim_check()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	ifstream input;
	string q;
	cout << "Enter the student id to want limit check" << endl;
	cout << endl;
	cout << "Enter your reg. no.\t:";
	cin >> q;
	cout << endl;
	input.open("student.txt", ios::in);
	string bid, nop, bn, an, in;

	if (!input)
	{
		cout << "File cannot be opened!!!" << endl;
	}
	else
	{

		while (input >> bid >> nop >> bn >> an >> in)
		{

			if (in == "0" && bid == q)
			{
				cout << "The student of ID " << bid << " can get a book!" << endl;
			}
			if (in != "0" && bid == q)
			{
				cout << "Sorry student of ID " << bid << " cannot get book as your limit is over!" << endl;
			}
			cout << endl;
		}
	}
}
