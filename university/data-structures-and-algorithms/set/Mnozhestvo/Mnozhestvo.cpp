// Mnozhestvo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <sstream>
using namespace std;

const int uSize = 10; // ������ ����������.
int u[uSize] = { 0,1,2,3,4,5,6,7,8,9 }; // ���������.
int currentSet = 0;
// ������ ������ � �������.
wstring commands[10][3] = 
{
	{L"CurrSet", L"������� ������� ���������, � ������� ����� ��������", L"(��������: 1 ��� 2 ��� 3)"},
	{L"Add", L"�������� ������� � ������� ���������", L"(��������: 0-9)"},
	{L"Contains", L"���� �� ������� � ������� ���������?", L"(��������: 0-9)"},
	{L"Remove", L"������� ������� �� �������� ���������", L"(��������: 0-9)"},
	{L"IsEmpty", L"������� ��������� ������?", L""},
	{L"Addition", L"�������� ���������� � �������� ���������", L""},
	{L"Print", L"������������� ��� �������� �������� ���������", L""},
	{L"Union", L"�������� ����������� 1 � 2 ���������", L""},
	{L"Intersection", L"�������� ����������� 1 � 2 ���������", L""},
	{L"Difference", L"�������� �������� 1 � 2 ���������", L""},
};

// ����� ���������.
class Set
{
public:
	// �����.
	bool mask[uSize];

	// ����������� ������� ������ ���������.
	Set()
	{
		for (int i = 0; i < uSize; i++) mask[i] = 0;
	}

	// ���������� �������� �� ���������� � ���������.
	void Add(int t)
	{
		for (int i = 0; i < uSize; i++) if (t == u[i] && !mask[i]) mask[i] = 1;
	}

	// ���������� ���� �� ������� � ���������.
	bool Contains(int t)
	{
		for (int i = 0; i < uSize; i++) if (t == u[i]) return mask[i];
		return false;
	}

	// ������� ������� �� ���������.
	void Remove(int t)
	{
		for (int i = 0; i < uSize; i++) if (t == u[i]) mask[i] = 0;
	}

	// ���������� ������ �� ���������.
	bool IsEmpty()
	{
		for (int i = 0; i < uSize; i++) if (mask[i]) return false;
		return true;
	}

	// ������������� �������� ���������.
	void Print()
	{
		for (int i = 0; i < uSize; i++) if (mask[i]) wprintf(L"{%d} ", u[i]);
		wcout << endl;
	}

	
};

// ���������� � ���������.
void Addition(Set s1, Set& s3)
{
	for (int i = 0; i < uSize; i++) s3.mask[i] = 0;
	for (int i = 0; i < uSize; i++)
	{
		if (s1.mask[i] == 0) s3.mask[i] = 1;
	}
}

// �������� ����������� ��������.
void Union(Set s1, Set s2, Set& s3)
{
	for (int i = 0; i < uSize; i++) s3.mask[i] = 0;
	for (int i = 0; i < uSize; i++)
	{
		if (s1.mask[i] || s2.mask[i]) s3.mask[i] = 1;
	}
}

// �������� ����������� ��������.
void Intersection(Set s1, Set s2, Set& s3)
{
	for (int i = 0; i < uSize; i++) s3.mask[i] = 0;
	for (int i = 0; i < uSize; i++)
	{
		if (s1.mask[i] && s2.mask[i]) s3.mask[i] = 1;
	}
}

// �������� �������� ��������.
void Difference(Set s1, Set s2, Set& s3)
{
	for (int i = 0; i < uSize; i++) s3.mask[i] = 0;
	for (int i = 0; i < uSize; i++)
	{
		if (s1.mask[i] && !s2.mask[i]) s3.mask[i] = 1;
	}
}

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	/*wcout << L"��������� �������:" << endl;
	for (int i = 0; i < 10; i++) 
	{
		wprintf(L"%ls - %ls %ls \n", commands[i][0].c_str(), commands[i][1].c_str(), commands[i][2].c_str());
	}
	wcout << endl;*/

	Set s1, s2, s3;

	s1.Add(1);
	s1.Add(2);
	s2.Add(2);
	s2.Add(3);
	s2.Add(5);

	wcout << "Union:" << endl;
	Union(s1, s2, s3);
	s3.Print();
	wcout << "Intersection:" << endl;
	Intersection(s1, s2, s3);
	s3.Print();
	wcout << "Difference:" << endl;
	Difference(s1, s2, s3);
	s3.Print();
	wcout << "Addition s2:" << endl;
	Addition(s2, s3);
	s3.Print();

	wcout << "s1 contains 1:" << endl;
	wcout << s1.Contains(1) << endl;
	wcout << "s1 is empty:" << endl;
	wcout << s1.IsEmpty() << endl;
	wcout << "s1 remove 1:" << endl;
	s1.Remove(1);
	s1.Print();
	/*while (true)
	{
		wstring line;
		wstring command;
		wstring arg;
		wcout << L"������� �������: ";
		getline(wcin, line);
		wstringstream stream(line);
		stream >> command;
		stream >> arg;

		int commandIndex = -1;
		for (int i = 0; i < 10; i++) if (commands[i][0] == command) commandIndex = i;

		switch (commandIndex)
		{
		case 0:
			currentSet = stoi(arg) - 1;
			wcout << L"������ ������������ ��������� - " << currentSet + 1 << endl;
			break;
		case 1:
			sets[currentSet].Add(stoi(arg));
			wcout << L"������� ��������." << endl;
			break;
		case 2:
			if (sets[currentSet].Contains(stoi(arg))) wcout << L"������� ������������ � ���������.";
			else wcout << L"������� ���������� � ���������.";
			wcout << endl;
			break;
		case 3:
			sets[currentSet].Remove(stoi(arg));
			wcout << L"������� ������." << endl;
			break;
		case 4:
			if (sets[currentSet].IsEmpty()) wcout << L"��������� ������.";
			else wcout << L"��������� �� ������.";
			wcout << endl;
			break;
		case 5:
			//sets[currentSet].Addition(sets[2]);
			wcout << L"��������� �������� � ��������� ����� 3." << endl;
			break;
		case 6:
			sets[currentSet].Print();
			break;
		case 7:
			Union(sets[0], sets[1], sets[2]);
			wcout << L"��������� �������� � ��������� ����� 3." << endl;
			break;
		case 8:
			Intersection(sets[0], sets[1], sets[2]);
			wcout << L"��������� �������� � ��������� ����� 3." << endl;
			break;
		case 9:
			Difference(sets[0], sets[1], sets[2]);
			wcout << L"��������� �������� � ��������� ����� 3." << endl;;
		default:
			break;
		}
	}*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
