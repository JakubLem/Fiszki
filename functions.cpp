#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string>
#include<fstream>
#include <windows.h>
#include<time.h>
#include<iostream>
using namespace std;
int count()
{
	fstream file;
	int counter = 0;
	file.open("data.txt", ios::in);
	if (file.good() == true) {
		
		string t;
		while (!file.eof()) {
			getline(file, t);
			counter++;
		}
	}
	else {
		cout << "blad";
	}
	file.close();
	return counter;
}
void StartApp(int c)
{
	fstream file;
	int select;
	string word;
	string* text = new string[c];
	file.open("data.txt", ios::in);
	if (file.good() == true) {
		for (int i = 0; i < c; i++) {
			file >> text[i];
			cout << text[i] << " ";
		}
		srand(time(0));
		while (true) {
			system("cls");
			//select the index of first word
			select = (rand() % c/2)*2;
			cout <<endl<< text[select + 1] << " - ";
			cin >> word;
			if (word == text[select]) {
				cout << "gratki";
			}
			else {
				cout << "nope"<<endl<< text[select+1]<< " - " <<text[select];
			}
			cout << endl;
			system("pause");
		}
	}
	else {
		cout << "blad";
	}
	file.close();
}