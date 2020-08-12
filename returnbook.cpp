#include"return_book.h"
using namespace std;
void return_book::ret_book()
{
	cout << "\t\t\t LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;

	ofstream output;
	ifstream input("issuancebook.txt", ios::in);
	cout << "Enter the book id which u want to return in the library!!!";
	cout << endl;
	cout << "Enter the bid\t:";
	cin >> rbid;
	if (!input)
	{
		cout << "\nFile not exist";

	}
	else {
		ofstream output("temp.txt", ios::out);
		while (input >> bid >> nop >> n >> an >> in >> stdid)
		{
			n1++;
			if (rbid == bid)
			{

				cout << "succefully return";
				cout << endl;
				ofstream output1;
				output1.open("book.txt", ios::app);
				if (!output1)
				{
					cout << "not exist";
				}
				else {
					output1 << bid << "\t" << nop << "\t" << n << "\t" << an << "\t" << in << "\t" << '\n';
					cout << endl << endl << "\nbook is updated" << endl;
					output1.close();
				}

			}
			if (rbid != bid) {
				n2++;
				output << "\n" << bid << "\t" << nop << "\t" << n << "\t" << an << "\t" << in << "\t" << stdid << "\n" << endl;
			}
		}
		if (n1 == n2)
		{
			cout << "\ncan't be returned b/c bid recrd not exist" << endl;
		}
		input.close();
		output.close();
		remove("issuancebook.txt");
		rename("temp.txt", "issuancebook.txt");
	}
}



