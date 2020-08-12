#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include"book.h";
#include"Student.h";
#include"Issuebook.h";
#include"return_book.h";
using namespace std;
int main()
{
	system("COLOR fC");
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl << endl;
	book c;
	Student s;
	Issuebook u;
	return_book r;
	string p = "";
	char ch;
	cout << "Enter the password to enter into the library:" << endl << endl;
	ch = _getch();
	while (ch != 13)
	{
		p.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl << endl;
	if (p == "dawn" || p == "DAWN" || p == "Dawn")
	{
		cout << "Welcome!you have entered correct password now you can enter into the library!" << endl;
		cout << endl;
		system("pause");
		int cho;
		do
		{
			system("cls");
			cout << "\t\t\tLIBARARY MANEGMENT SYSTEM" << endl;
			cout << "\n\t\t\t\t MAIN MENU" << endl;
			cout << "Press 0 to creat a book record-----> " << endl;
			system("COLOR 0C");
			cout << endl;
			cout << "Press 1 to Modify a book record-----> " << endl;
			cout << endl;
			cout << "Press 2 to Search a book record-----> " << endl;
			cout << endl;
			cout << "Press 3 to Delete a book record-----> " << endl;
			cout << endl;
			cout << "Press 4 to Add a student record----->" << endl;
			cout << endl;
			cout << "Press 5 to Modify in a student record----->" << endl;
			cout << endl;
			cout << "Press 6 to Search a student record----->" << endl;
			cout << endl;
			cout << "Press 7 to Delete a student record----->" << endl;
			cout << endl;
			cout << "Press 8 to check validity of book & student record---->" << endl;
			cout << endl;
			cout << "Press 9 to check limit to issue a book--->" << endl;
			cout << endl;
			cout << "Press 10 to issue a book to a student----->" << endl;
			cout << endl;
			cout << "Press 11 to Return book to librarian----->" << endl;
			cout << endl;
			cout << "Press 12 to exit to the main menue!!" << endl;
			cout << endl;
			cout << "Enter your choice number from (0-->12)!!" << endl;
			cout << endl;
			cin >> cho;
			system("cls");
			switch (cho)
			{
			case 0:
				c.create();
				break;
			case 1:
				c.modify();
				break;
			case 2:
				c.search();
				break;
			case 3:
				c.Delete();
				break;
			case 4:
				s.add();
				break;
			case 5:
				s.modify();
				break;
			case 6:
				s.search();
				break;
			case 7:
				s.Delete();
				break;
			case 8:
				u.validity();
				break;
			case 9:
				u.lim_check();
				break;
			case 10:
				u.issue();
				break;
			case 11:
				r.ret_book();
				break;
			case 12:
				break;
			default:
				cout << "\nYou have entered number out of range!!" << endl;
			}
			cout << endl;
			system("Pause");
			system("cls");
		} while (cho >= 0 && cho <= 12);
	}
	if (p != "dawn" && p != "DAWN" && p != "Dawn")
	{
		cout << "Sorry! You have enterd wrong password!" << endl;
	}
}
