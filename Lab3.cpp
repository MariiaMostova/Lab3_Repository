#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define n 5
using namespace std;

void arithmetic_mean_of_column_elements_above_auxiliary_diagonalt_sort_lines_decrease(int array[n][n])
{
	int temp, item;
	for (int column_number = 0; column_number< n; column_number++)
	{
		for (int line_number_for_sort = 1; line_number_for_sort < n; line_number_for_sort++)
		{
			temp = array[column_number][line_number_for_sort];
			item = line_number_for_sort - 1;
			while (item >= 0 && array[column_number][item] < temp)
			{
				array[column_number][item + 1] = array[column_number][item];
				array[column_number][item] = temp;
				item--;
			}
		}
	}
	for (int column_number= 0; column_number< n; column_number++)
	{
		for (int line_number = 0; line_number < n; line_number++)
		{
			cout << array[column_number][line_number] << '\t';
		}
		cout << endl;
	}
}

void arithmetic_mean_of_each_column_elements_above_auxiliary_diagonal(int array[n][n])
{
	int sum_of_elements_of_each_column_above_auxiliary_diagonal, arithmetic_mean_of_column_elements_above_auxiliary_diagonal;
	for (int line_number = 0; line_number < n-1; line_number++)
	{
		sum_of_elements_of_each_column_above_auxiliary_diagonal = 0;
		for (int column_number= 0; column_number< n; column_number++)
		{
			if ((column_number+ line_number) < n-1)
			{
				sum_of_elements_of_each_column_above_auxiliary_diagonal += array[column_number][line_number];
				arithmetic_mean_of_column_elements_above_auxiliary_diagonal = sum_of_elements_of_each_column_above_auxiliary_diagonal / (n - 1 - line_number);
			}
		}
		cout << "arithmetic_mean_of_column_elements_above_auxiliary_diagonal=" << arithmetic_mean_of_column_elements_above_auxiliary_diagonal << endl;
	}
}

void product_of_all_elements_above_auxiliary_diagonal(int array[5][5])
{
	int product_of_all_elements_above_auxiliary_diagonal, arithmetic_mean_of_column_elements_above_auxiliary_diagonal, sum_of_elements_of_each_column_above_auxiliary_diagonal;
	product_of_all_elements_above_auxiliary_diagonal = 1;
	for (int line_number = 0; line_number < n-1; line_number++)
	{
		sum_of_elements_of_each_column_above_auxiliary_diagonal = 0;
		for (int column_number= 0; column_number< n; column_number++)
		{
			if ((column_number+ line_number) < n-1)
			{
				sum_of_elements_of_each_column_above_auxiliary_diagonal += array[column_number][line_number];
				arithmetic_mean_of_column_elements_above_auxiliary_diagonal = sum_of_elements_of_each_column_above_auxiliary_diagonal / (n - 1 - line_number);
			}
		}
		product_of_all_elements_above_auxiliary_diagonal *= arithmetic_mean_of_column_elements_above_auxiliary_diagonal;
	}
	cout << "product_of_all_elements_above_auxiliary_diagonal=" << product_of_all_elements_above_auxiliary_diagonal << endl;
}

int main()
{
	int column_number, line_number;
	int array[5][5];
	for (column_number= 0; column_number< 5; column_number++ )
	{
		for (line_number = 0; line_number < 5; line_number ++ )
		{
			cin >> array[column_number][line_number];
		}
	}
	cout << endl;
	for (column_number= 0; column_number< 5; column_number++ )
	{
		for (line_number = 0; line_number < 5; line_number ++ )
		{
			cout << array[column_number][line_number] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	arithmetic_mean_of_column_elements_above_auxiliary_diagonalt_sort_lines_decrease(array);
	cout << endl;
	arithmetic_mean_of_each_column_elements_above_auxiliary_diagonal(array);
	cout << endl;
	product_of_all_elements_above_auxiliary_diagonal(array);
	cout << endl;
}