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

void fillzero(int* tab, int c) {
	for (int i = 0; i < c; i++) {
		tab[i] = 0;
	}
}
int checkall(int* tab, int c) {
	for (int i = 0; i < c; i++) {
		if (tab[i] != 4) {
			return 0;
		}
	}
	return 1;
}
void StartApp(int c, int * ctab, int * wtab)
{

	fstream file;
	int select,goodanswer=0,badanswer=0;
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
			cout << "Correct: " << goodanswer << " Wrong: " << badanswer<<endl;
			//select the index of first word
			if (checkall(ctab,c) == 1) {
				cout << "You are the best!!!";
				goto over;
			}
			do
				select = (rand() % c / 2) * 2;
			while (ctab[select]==4);

			cout <<endl<< text[select + 1] << " - ";
			cin >> word;
			if (word == text[select]) {
				cout << "Correct!";
				goodanswer++;
				ctab[select / 2]++;
				if (ctab[select / 2] == 4) {
					cout << endl << "COOL, you answer correct 4 times!!!";
				}
			}
			else {
				cout << "There's sth wrong!!! "<<endl<< "Correct answet is: "<<text[select];
				badanswer++;
				wtab[select / 2]++;
				if (wtab[select / 2] == 4) {
					cout << endl << "Ughh, you hadn't translated this word fourth time! Write this 3 times correct!" << endl<<endl;
					for (int i = 1; i < 4; i++) {
						do {
							cin >> word;
							if (word == text[select]) {
								cout << endl << "Correct!";
							}
							else {
								cout << endl << "Wrong!!!"<<endl;
							}
						} while (word!=text[select]);
						cout << endl;
					}
					cout << "I hope, that you will remember that!"<<endl;
					wtab[select / 2] = 0;
				}
			}
			cout << endl;
			system("pause");
		}
	}
	else {
		cout << "blad";
	}
	over:
	file.close();
}
