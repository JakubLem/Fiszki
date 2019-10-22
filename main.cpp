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
	SetConsoleTitleA("Twoje Fiszki");
	int c = count();
	StartApp(c*2);
	return 0;
}

/*
zliczanie elementów countem()
do tablicy
interfejs: zamykanie:q 
*/