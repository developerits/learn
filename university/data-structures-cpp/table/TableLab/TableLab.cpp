﻿// TableLab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Table.h"

int main()
{
	setlocale(0, "");

	Table<string, int>* t = new Table<string, int>();
	t->add("apple", 1);
	t->add("apple", 5);
	t->add("orange", 2);
	cout << t->toJSON() << endl;
	//cout << (*t)["apple"] << endl;
	/*t->remove("apple");
	try {
		cout << (*t)["apple"] << endl;
	}
	catch (int e) {
		if (e == -10) cout << "Попытка обратиться к несуществующему ключу." << endl;
		else throw e;
	}
	t->clear();
	t->add("fruit", 1);
	t->add("strawberry", 5);
	cout << t->toJSON() << endl;
	cout << t->keys()->front() << endl;*/
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
