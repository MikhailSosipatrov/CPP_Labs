#include <iostream>
#include <fstream> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cmath>

#include "constantsLab1.h"
#include "functionsLab1.h"
using namespace std;




void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");



	string FLAG;
	string READING;
	string WRITING;
	int i;
	float numbers[N]{};
	float numbersBoof[N]{};
	float numbersOld[N]{};
	string text;


	do
	{
		std::cout << "Выберите, откуда будет осуществляться ввод данных\n" << "0 - из консоли (будут случайные значения)\n" << "1 - Из файла" << endl;
		std::cout << endl;
		getline(cin, READING);
		std::cout << endl;
		if (((READING != "1") && (READING != "0")))
		{
			while ((READING != "1") && (READING != "0"))
			{
				std::cout << "Вы ввели неверный символ! Пожалуйста, повторите ввод: ";
				getline(cin, READING);
			}
			if (READING == "0")
			{
				std::cout << "Начальный массив: \n";
				for (i = 0; i <= N - 1; i++)
				{
					numbers[i] = GetRandomNumber(-100, 100);
					std::cout << numbers[i] << " ";
				}
			}
			else
			{
				fstream fileread;
				fileread.open(readingpath, fstream::in | fstream::app);
				for (i = 0; i <= N - 1; i++)
				{
					fileread >> text;
					numbers[i] = stoi(text);
				}
				fileread.close();
			}
		}
		else if (READING == "0")
		{
			std::cout << "Начальный массив: \n";
			for (i = 0; i <= N - 1; i++)
			{
				numbers[i] = GetRandomNumber(-100, 100);
				std::cout << numbers[i] << " ";

			}
		}
		else
		{
			fstream fileread;
			fileread.open(readingpath, fstream::in | fstream::app);
			for (i = 0; i <= N - 1; i++)
			{
				fileread >> text;
				numbers[i] = stoi(text);
			}
			fileread.close();
		}



		std::cout << endl << endl;



		FlattenArray(numbers, N);
		for (int i = 0; i <= N; i++)
		{
			numbersBoof[i] = numbers[i];
		}
		FlattenArrayOld(numbersBoof, numbersOld, N);



		std::cout << "Выберите, куда будет осуществляться вывод данных\n" << "0 - в консоль \n" << "1 - В файл" << endl;
		std::cout << endl;
		getline(cin, WRITING);
		std::cout << endl;
		if (WRITING != "1" && WRITING != "0" && (WRITING.size() != 1))
		{
			while (WRITING != "1" && WRITING != "0")
			{
				std::cout << "Вы ввели неверный символ! Пожалуйста, повторите ввод: ";
				getline(cin, WRITING);
			}
			if (WRITING == "0")
			{
				std::cout << "а) Сглаженный массив (обновляющийся):\n";
				for (i = 0; i <= N - 1; i++)
				{
					std::cout << numbers[i] << " ";
				}
				cout << endl;
				std::cout << "б) Сглаженный массив (на основе старых чисел):\n";
				for (i = 0; i <= N - 1; i++)
				{
					std::cout << numbersOld[i] << " ";
				}
			}
			else
			{
				fstream filewrite;
				filewrite.open(writingpath, fstream::out);
				filewrite << "";
				filewrite.close();

				filewrite.open(writingpath, fstream::out | fstream::app);
				filewrite << "а) Сглаженный массив (обновляющийся):" << '\n';
				for (i = 0; i <= N - 1; i++)
				{
					filewrite << numbers[i] << '\n';
				}
				cout << endl;
				filewrite << "б) Сглаженный массив (на основе старых чисел):" << '\n';
				for (i = 0; i <= N - 1; i++)
				{
					filewrite << numbersOld[i] << '\n';
				}
				filewrite.close();
			}

		}
		else if (WRITING == "0")
		{
			std::cout << "а) Сглаженный массив (обновляющийся):\n";
			for (i = 0; i <= N - 1; i++)
			{
				std::cout << numbers[i] << " ";
			}
			cout << endl;
			std::cout << "б) Сглаженный массив (на основе старых чисел):\n";
			for (i = 0; i <= N - 1; i++)
			{
				std::cout << numbersOld[i] << " ";
			}
		}
		else
		{
			fstream filewrite;
			filewrite.open(writingpath, fstream::out);
			filewrite << "";
			filewrite.close();

			filewrite.open(writingpath, fstream::out | fstream::app);
			filewrite << "а) Сглаженный массив (обновляющийся):" << '\n';
			for (i = 0; i <= N - 1; i++)
			{
				filewrite << numbers[i] << '\n';
			}
			cout << endl;
			filewrite << "б) Сглаженный массив (на основе старых чисел):" << '\n';
			for (i = 0; i <= N - 1; i++)
			{
				filewrite << numbersOld[i] << '\n';
			}
			filewrite.close();
		}



		std::cout << endl << endl;



		if (READING != "1")
		{
			std::cout << "Хотите повторить ввод?\n" << "0 - нет\n" << "1 - да" << endl;
			std::cin >> FLAG;
			if ((FLAG != "1") && (FLAG != "0"))
			{
				while ((FLAG != "1") && (FLAG != "0"))
				{
					std::cout << "Вы ввели неверный символ! Пожалуйста, повторите ввод: ";
					std::cin >> FLAG;
				}
				if (FLAG == "0")
				{
					std::cout << "Работа программы завершена";
				}
				else
				{

				}
			}
			else if (FLAG == "0")
			{
				std::cout << "Работа программы завершена";
			}
			else
			{

			}
		}
		else
		{
			std::cout << "Работа программы завершена" << endl;
		}



	} while (FLAG == "1" && READING != "1");







}
