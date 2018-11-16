//my comment
// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
//сортування вставкою
void sort(int mas[5][5])
{
	int temp, item;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 1; k < 5; k++)
		{
			temp = mas[i][k];
			item = k - 1;
			while (item >= 0 && mas[i][item] < temp)
			{
				mas[i][item + 1] = mas[i][item];
				mas[i][item] = temp;
				item--;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << mas[i][j] << '\t';
		}
		cout << endl;
	}
}
//середнє арифметичне чисел над допоміжною діагоналлю
void ser_arefm(int mas[5][5])
{
	int sum, ser;
	for (int j = 0; j < 4; j++)
	{
		sum = 0;
		for (int i = 0; i < 5; i++)
		{
			if ((i + j) < 4)
			{
				sum += mas[i][j];
				ser = sum / (4 - j);
			}
		}
		cout << "ser=" << ser << endl;
	}
}
//добуток чисел над допоміжною діагоналлю
void dobutok(int mas[5][5])
{
	int dob, ser, sum;
	dob = 1;
	for (int j = 0; j < 4; j++)
	{
		sum = 0;
		for (int i = 0; i < 5; i++)
		{
			if ((i + j) < 4)
			{
				sum += mas[i][j];
				ser = sum / (4 - j);
			}
		}
		dob *= ser;
	}
	cout << "dob=" << dob << endl;
}
int main()
{
	int i, j;
	int mas[5][5];
	for (i = 0; i < 5; i += 1)
	{
		for (j = 0; j < 5; j += 1)
		{
			cin >> mas[i][j];
		}
	}
	cout << endl;
	for (i = 0; i < 5; i += 1)
	{
		for (j = 0; j < 5; j += 1)
		{
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	sort(mas);
	cout << endl;
	ser_arefm(mas);
	cout << endl;
	dobutok(mas);
	cout << endl;
	// додавання і добуток всіх ел.над допоміжною діагоналлю 
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
