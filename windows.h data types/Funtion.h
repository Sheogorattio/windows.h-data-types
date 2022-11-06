#pragma once
#include<iostream>
#include<tchar.h>
#include<windows.h>
using namespace std;

void SpaceToTab(TCHAR* str, INT size) {
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ') str[i] = '\t';
	}
}

INT* nCountSynbols(TCHAR* str, INT size) {
	INT let=0, num=0, other = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] >= 48 && str[i] <= 57) num++;
		else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 192 && str[i] <= 255)) let++;
		else other++;
	}
	INT* res = new INT[3]{let, num, other};
	return res;
}

INT nWordsCounter(TCHAR* str) {
	BOOL isWord = FALSE;
	INT counter = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isWord == FALSE && str[i] != ' ') {
			isWord = TRUE;
			counter++;
		}
		else if (isWord == TRUE && str[i] == ' ') {
			isWord = FALSE;
		}
	}
	return counter;
}

INT nVowelsCounter(TCHAR* str) {
	for (int i = 0; str[i] != '\0'; i++) {//если есть английские буквы
		if((str[i]>=65 && str[i]<=90)||(str[i]>=97 && str[i]<=122)) return 0;
	}
	TCHAR vowels[21] = TEXT("ја”уќоџыЁэя€ёю®Є»и≈е");
	INT counter = 0;
	for (int i = 0; vowels[i] != '\0'; i++) {
		for (int j = 0; str[j] != '\0'; j++) {
			if (vowels[i] == str[j]) counter++;
		}
	}
	return counter;
}

BOOL bIsPalindrom(TCHAR* str) {
	BOOL rezult = TRUE;
	INT size = 0;

	for (int i = 0; str[i] != '\0'; i++)size++;

	for (int i = 0; i < size / 2; i++) {
		if (str[i] != str[size - i - 1]) rezult = FALSE;
	}
	return rezult;
}

TCHAR* pDeleteChar(TCHAR* str, INT index) {
	INT size = 0;
	for (int i = 0; str[i] != '\0'; i++)size++;
	if (size < index)return nullptr;
	TCHAR* buff = new TCHAR[--size];

	for (int i = 0, j = 0; i < size; j++, i++) {
		if (j == index) {
			i--;
			continue;
		}
		buff[i] = str[j];
		str[i] = buff[i];
	}
	str[size] = '\0';
	delete[] buff;
	return str;
}

TCHAR* pDeleteAllChar(TCHAR* str, TCHAR ch) {
	INT size = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
		if (str[i] == ch) size--;
	}
	TCHAR* buff = new TCHAR[size];

	for (int i = 0, j=0; str[i] != '\0'; i++, j++) {
		if (str[i] == ch) {
			j--;
			continue;
		}
		buff[j] = str[i];
	}
	for (int i = 0; i < size; i++) {
		str[i] = buff[i];
	}
	str[size] = '\0';
	delete[]buff;
	return str;
}

TCHAR* pAddChar(TCHAR* str, INT pos, TCHAR ch) {
	INT size = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
	}
	size++;
	TCHAR* buff = new TCHAR[size];
	buff[size - 1] = '\0';
	for (int i = 0, j=0; i < size; i++, j++) {
		if (i == pos) {
			buff[i] = ch;
			j--;
			continue;
		}
		buff[i] = str[j];
	}
	//delete[]str;		//////////тут возникает ошибка при попытке очистить пам€ть
	//str = buff;   
	//delete[]buff;
	return buff;
}