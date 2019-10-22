#include<iostream>
#include<fstream>
#include<conio.h>
#include "header.h"
#include<string>
#include <windows.h>
#include<time.h>
using namespace std;
int main()
{
	SetConsoleTitleA("Your FlashCards");
	int c = count();
	int* correcttab = new int[c];
	fillzero(correcttab,c);
	int* wrongtab = new int[c];
	fillzero(wrongtab, c);
	StartApp(c*2,correcttab,wrongtab);
	return 0;
}

/*
zliczanie elementów countem()
do tablicy
interfejs: zamykanie:q 
*/
