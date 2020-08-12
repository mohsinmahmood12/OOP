#include"book.h"
#include<fstream>
#include<iostream>
using namespace std;
void book::create()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string bid, nop, bn, an, in;
	cout << "Enter the attributes of book which you want to create in the library!" << endl;
	cout << endl;
	cout << "Enter the book ID!\t:";
	cin >> bid;
	cout << endl;
	cout << "Enter the no. of pages of book!\t:";
	cin >> nop;
	cout << endl;
	cout << "Enter the book name!\t:";
	cin >> bn;
	cout << endl;
	cout << "Enter the book's auther name!\t:";
	cin >> an;
	cout << endl;
	cout << "Enter the book's issuer name!\t:";
	cin >> in;
	cout << endl;
	ofstream output;
	output.open("book.txt", ios::app);
	if (!output)
	{
		cout << "File cannot be opened!!!" << endl;
	}
	else
	{
		output << "\n" << bid << "\t\t" << nop << "\t\t " << bn << "\t\t" << an << "\t\t " << in << "\n";
		cout << endl;
		output.close();
		cout << "\nYou have successfully created a book in the library!" << endl;
	}
}
void book::modify()
{
	cout << "\t\t\tLIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string cid, bid, nop, bn, an, in;
	int n1 = 0, n2 = 0;
	ifstream input("book.txt");
	ofstream output("temp.txt");
	cout << "Enter  book Id(which u wnt to modify)\t:";
	cin >> cid;
	cout << endl;
	if (!input)
	{
		cout << "Input file failed to open(not exist)\n";
	}
	else
	{
		while (input >> bid >> nop >> bn >> an >> in)
		{
			n1++;
			if (cid == bid)
			{
				string bid, nop, bn, an, in;
				cout << "Enter the attributes of book which you wnt to modify in existing book recrd!" << endl;
				cout << "\nEnter the book ID!\t:";
				cin >> bid;
				cout << endl;
				cout << "Enter the no. of pages of book!\t:";
				cin >> nop;
				cout << endl;
				cout << "Enter the book name!\t:";
				cin >> bn;
				cout << endl;
				cout << "Enter the book's auther name!\t:";
				cin >> an;
				cout << endl;
				cout << "Enter the book's issuer name!\t:";
				cin >> in;
				cout << endl;
				output << "\n" << bid << "\t\t" << nop << "\t\t " << bn << "\t\t" << an << "\t\t " << in;
				cout << endl;
				cout << "You have successfully modified a book in the library!" << endl;
				cout << endl;
			}
			else
			{
				n2++;
				output << "\n" << bid << "\t\t" << nop << "\t\t " << bn << "\t\t" << an << "\t\t " << in << '\n';
			}
		}
		if (n1 == n2)
		{
			cout << "\nThe entered BId not exist so can't be modified" << endl;
			cout << endl;
		}
		input.close();
		output.close();
		remove("book.txt");
		rename("temp.txt", "book.txt");
	}
}
void book::search()
{
	cout << "\t\t\tLIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;

	string bid, nop, bn, an, in;
	int n1 = 0, n2 = 0;
	string c;
	ifstream input;
	cout << "Enter the book id of book which you want to search in the library:" << endl;
	cout << endl;
	cout << "Enter the Book ID\t:";
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
				cout << "The record is as follows!!" << endl;
				cout << "\n" << nop << "\t" << bn << "\t" << an << "\t" << in << '\n';
			}
			else {
				n2++;
			}
		}
		if (n1 == n2)
		{
			cout << "\nThe entered BId not exist so can't be searched" << endl;
			cout << endl;
		}
		cout << endl;
	}
}
void book::Delete()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	int i = 0, n1 = 0, n2 = 0;
	char bid[30], nop[30], bn[30], an[30], in[30];
	string eid;
	cout << "Enter book ID for delete\t :";
	cin >> bid;
	cout << endl;
	for (i = 0; bid[i] != '\0'; i++);
	ifstream input;
	ofstream output;
	input.open("book.txt");
	if (!input)
	{
		cout << "Input file not exist ";
	}
	else
	{
		output.open("temp.txt");
		while (input >> eid >> nop >> bn >> an >> in)
		{
			n1++;
			if (bid == eid)
			{
				cout << "\nThe entered BID recrd has been Dleted....!" << endl;

			}
			else
			{
				n2++;
				output << "\n" << eid << "\t\t" << nop << "\t\t" << bn << "\t\t" << an << "\t\t" << in << "\n" << endl;
			}
		}
		if (n1 == n2)
		{
			cout << "Cannot delet this record as the ID is not found!" << endl;
		}


		input.close();
		output.close();
		remove("book.txt");
		rename("temp.txt", "book.txt");

	}
}
