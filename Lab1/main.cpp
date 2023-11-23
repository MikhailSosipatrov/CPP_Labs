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
		std::cout << "��������, ������ ����� �������������� ���� ������\n" << "0 - �� ������� (����� ��������� ��������)\n" << "1 - �� �����" << endl;
		std::cout << endl;
		getline(cin, READING);
		std::cout << endl;
		if (((READING != "1") && (READING != "0")))
		{
			while ((READING != "1") && (READING != "0"))
			{
				std::cout << "�� ����� �������� ������! ����������, ��������� ����: ";
				getline(cin, READING);
			}
			if (READING == "0")
			{
				std::cout << "��������� ������: \n";
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
			std::cout << "��������� ������: \n";
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



		std::cout << "��������, ���� ����� �������������� ����� ������\n" << "0 - � ������� \n" << "1 - � ����" << endl;
		std::cout << endl;
		getline(cin, WRITING);
		std::cout << endl;
		if (WRITING != "1" && WRITING != "0" && (WRITING.size() != 1))
		{
			while (WRITING != "1" && WRITING != "0")
			{
				std::cout << "�� ����� �������� ������! ����������, ��������� ����: ";
				getline(cin, WRITING);
			}
			if (WRITING == "0")
			{
				std::cout << "�) ���������� ������ (�������������):\n";
				for (i = 0; i <= N - 1; i++)
				{
					std::cout << numbers[i] << " ";
				}
				cout << endl;
				std::cout << "�) ���������� ������ (�� ������ ������ �����):\n";
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
				filewrite << "�) ���������� ������ (�������������):" << '\n';
				for (i = 0; i <= N - 1; i++)
				{
					filewrite << numbers[i] << '\n';
				}
				cout << endl;
				filewrite << "�) ���������� ������ (�� ������ ������ �����):" << '\n';
				for (i = 0; i <= N - 1; i++)
				{
					filewrite << numbersOld[i] << '\n';
				}
				filewrite.close();
			}

		}
		else if (WRITING == "0")
		{
			std::cout << "�) ���������� ������ (�������������):\n";
			for (i = 0; i <= N - 1; i++)
			{
				std::cout << numbers[i] << " ";
			}
			cout << endl;
			std::cout << "�) ���������� ������ (�� ������ ������ �����):\n";
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
			filewrite << "�) ���������� ������ (�������������):" << '\n';
			for (i = 0; i <= N - 1; i++)
			{
				filewrite << numbers[i] << '\n';
			}
			cout << endl;
			filewrite << "�) ���������� ������ (�� ������ ������ �����):" << '\n';
			for (i = 0; i <= N - 1; i++)
			{
				filewrite << numbersOld[i] << '\n';
			}
			filewrite.close();
		}



		std::cout << endl << endl;



		if (READING != "1")
		{
			std::cout << "������ ��������� ����?\n" << "0 - ���\n" << "1 - ��" << endl;
			std::cin >> FLAG;
			if ((FLAG != "1") && (FLAG != "0"))
			{
				while ((FLAG != "1") && (FLAG != "0"))
				{
					std::cout << "�� ����� �������� ������! ����������, ��������� ����: ";
					std::cin >> FLAG;
				}
				if (FLAG == "0")
				{
					std::cout << "������ ��������� ���������";
				}
				else
				{

				}
			}
			else if (FLAG == "0")
			{
				std::cout << "������ ��������� ���������";
			}
			else
			{

			}
		}
		else
		{
			std::cout << "������ ��������� ���������" << endl;
		}



	} while (FLAG == "1" && READING != "1");







}
