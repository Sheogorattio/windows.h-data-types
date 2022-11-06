#include<windows.h>
#include<tchar.h>
#include <iostream>
#include"Funtion.h"

using namespace std;

int main() {
	TCHAR str[50] = TEXT("случайный текст на кириллице");
	cout << nWordsCounter(str) << endl << nVowelsCounter(str) << endl;
	TCHAR palindrom[30] = TEXT("tenet tenet");
	cout << bIsPalindrom(palindrom) << endl;
	wcout << pDeleteChar(palindrom, 3) << endl;
	wcout << pDeleteAllChar(palindrom, 'n')<< endl;
	TCHAR* buff = new TCHAR[20];
	buff = (TCHAR *)TEXT("random text");
	wcout << pAddChar(buff, 3, 'B');
}