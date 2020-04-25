﻿// VT46.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Double.h"
using namespace std;

int main()
{
	string s1, s2;
	ifstream ifile("C:\\Users\\GD\\source\\repos\\University\\Exercises\\VT46\\VT46\\COMPARE.IN.txt");
	getline(ifile, s1);
	getline(ifile, s2);

	Double d1 = Double(s1);
	Double d2 = Double(s2);
	d1.Print();
	d2.Print();

	ifile.close();

	ofstream ofile("C:\\Users\\GD\\source\\repos\\University\\Exercises\\VT46\\VT46\\COMPARE.OUT.txt");
	if (d1 == d2) ofile << 0;
	else if (d1 < d2) ofile << -1;
	else ofile << 1;
	ofile.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.