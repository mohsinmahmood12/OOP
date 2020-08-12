#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class book
{
private:
	string bid;           //Book ID.
	string nop;          //No. of pages.
	string bn;          //Book name.
	string an;         //Auther name.
	string in;        //Issuer name.
	ifstream input;
	ofstream output;
public:
	void create();
	void modify();
	void search();
	void Delete();
};
