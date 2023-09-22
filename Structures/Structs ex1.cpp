#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <io.h>

using namespace std;

struct date
{
	int m;
	int d;
	int y;
	void Print () 
	{
		cout << right << setw (2) << m << "." << right << setw (2) << d << "." << y << " ";
	}
};

struct heavycar
{
	string model;
	double weight; 
	string color;
	date data;
	string owner;
	string adress;
	int gosnum;
	void printFilm()
	{
		cout << left << "| " << setw (10) << model << "| " << setw (5) << weight << "| " << setw (6) << color << "| "; data.Print(); cout << left << "| " << setw (18) << owner << "| " << setw (17) << adress << "| " << setw (2) << gosnum << "|" << endl;
	}
};

//struct lightcar 
//{
//	string model;
//	string color;
//	date data;
//	string owner;
//	string adress;
//	double gosnum;
//	void printFilm () {
//		cout << left << "| " << setw (25) << model << "| " << setw (21) << color << "| " << setw (5) << data << "| " << setw (5) << owner << setw (5) << adress << setw (5) << gosnum << "|" << endl;
//	}
//};



void search_nds(heavycar ar[], int size, string _nds, int _nds_case);

void sort_by_rating (heavycar ar[], int size, int _up_down, int _raiting_price);

heavycar *add_new_film(heavycar *tmp, int *size);

heavycar *remove_film(heavycar * tmp, int* size);

void menu_1();

void printFilms(heavycar ar[], int _size);

void printUp_Down();

void printNDS();

void printNDSinput();

void pause();

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	system("mode con cols=84 lines=50");
	menu_1();
	return 0;
}

void menu_1()
{
	int size = 5;
	heavycar m1 = { "MAN", 2000, "Red", {12,12,2020}, "Belolipetskyi D N", "Kisheneva 3", 0001};
	heavycar m2 = { "MERCEDES", 1300, "Red", {11,1,2020}, "Nemcov K D", "Kisheneva 3", 0002 };
	heavycar m3 = { "SUZUKI", 1900, "Black", {2,2,2021}, "Belolipetskyi D N", "Coporova 6", 0003 };
	heavycar m4 = { "RENAULT", 1800, "White", {12,16,2019}, "Tamov P M", "Novoorlovskaya 4", 0004 };
	heavycar m5 = { "VOLVO", 900, "Black", {3,4,2028}, "Yampoltsev N D", "Novoorlovskaya 4", 0005 };


	heavycar *heavycar_all /*_old*/ = new heavycar[size]{ m1, m2, m3, m4, m5};
	//fun_of_stream(movies_all_old, size);

	//Movies* movies_all = new Movies[size];
	//fun_if_stream(movies_all, size);
	//pause();
	
	do
	{
		int change_action;
		int nds_case;
		string nds;
		int up_down;

		do
		{
			system("cls");
			printFilms(heavycar_all, size);
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << "                           ЧТО ВЫ ХОТИТЕ ВЫПОЛНИТЬ?" << endl;
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << "                           1. ПОИСК" << endl;
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << "                           2. СОРТИРОВКА ПО ВЕСУ" << endl;
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << "                           3. СОРТИРОВКА ПО ГОС. НОМЕРУ" << endl;
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << "                           4. ДОБАВИТЬ СВОЙ ФИЛЬМ" << endl;
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << "                           5. УДАЛИТЬ ФИЛЬМ" << endl;
			cout << "____________________________________________________________________________________" << endl;
			cout << endl;
			cout << endl;
			cout << ">>> "; cin >> change_action;
		} while (change_action < 1 or change_action > 5);
		
		switch (change_action)
		{
		case 1:
			do
			{
				system("cls");
				printFilms(heavycar_all, size);
				printNDS(); 
				cin >> nds_case;
			} while (nds_case < 1 or nds_case > 4);
			system("cls");
			printFilms(heavycar_all, size);
			printNDSinput();
			cin.ignore();
			getline(cin, nds);
			search_nds(heavycar_all, size, nds, nds_case);
			pause();
			break;
		case 2:
			do
			{
				system("cls");
				printFilms(heavycar_all, size);
				printUp_Down();
				cin >> up_down;
			} while (up_down < 1 or up_down > 2);
			sort_by_rating (heavycar_all, size, up_down, 1);
			break;
		case 3:
			do
			{
				system("cls");
				printFilms(heavycar_all, size);
				printUp_Down();
				cin >> up_down;
			} while (up_down < 1 or up_down > 2);
			sort_by_rating(heavycar_all, size, up_down, 2);
			break;
		case 4:
			heavycar_all = add_new_film(heavycar_all, &size);
			//fun_of_stream(movies_all, size);
			break;
		case 5:
			heavycar_all = remove_film(heavycar_all, &size);
			break;
		}
	} while (true);
}

void printFilms(heavycar ar[], int _size)
{
	cout << "____________________________________________________________________________________" << endl;
	cout << "|           |      |       |            |                   |                  |   |" << endl;
	cout << "|   МОДЕЛЬ  |  ВЕС |  ЦВЕТ |    ДАТА    |  ФАМИЛИЯ ИНИЦИАЛЫ |       АДРЕС      | N |" << endl;
	cout << "|___________|______|_______|____________|___________________|__________________|___|" << endl;
	cout << "|           |      |       |            |                   |                  |   |" << endl;
	for (int i = 0; i < _size; i++)
	{
		ar[i].printFilm();
	}
	cout << "|___________|______|_______|____________|___________________|__________________|___|" << endl;
}

void search_nds(heavycar ar[], int _size, string _nds, int _nds_case)
{
	int count_spaces = 0;
	for (int i = 0; i < _nds.size(); i++)
	{
		if (_nds[i] < 90 and _nds[i] != 32 and _nds[i] != 45)
		{
			_nds[i] = _nds[i] + 32;
		}
		if (_nds[i] == 32)
		{
			count_spaces++;
		}
	}
	for (int i = 0; i < count_spaces; i++) 
	{
		for (int i = 0; i < _nds.size(); i++)
		{
			if (_nds[i] == 32)
			{
				for (int j = i; j < _nds.size(); j++)
				{
					_nds[j] = _nds[j + 1];
				}
			}
		}
	}
	_nds.resize(_nds.size () - count_spaces);
	count_spaces = 0;

	//////////////////////////////////////////////////////////////////////////

	//cout << "Вы ввели: " << _nds << endl << endl;
	string buffer_nds;

	cout << "____________________________________________________________________________________" << endl;
	cout << "|           |      |       |            |                   |                  |   |" << endl;
	for (int i = 0; i < _size; i++)
	{
		switch (_nds_case)
		{
		case 1:
			//cout << endl << "РЕЗУЛЬТАТЫ ПОИСКА ПО ИМЕНИ ФИЛЬМА >> " << _nds << endl << endl;
			buffer_nds = ar[i].model;
			break;

		case 2:
			//cout << endl << "РЕЗУЛЬТАТЫ ПОИСКА ПО РЕЖИССЁРУ ФИЛЬМА >> " << _nds << endl;
			buffer_nds = ar[i].owner;
			break;

		case 3:
			//cout << endl << "РЕЗУЛЬТАТЫ ПОИСКА ПО ЖАНРУ ФИЛЬМА >> " << _nds << endl;
			buffer_nds = ar[i].color;
			break;
		case 4:
			//cout << endl << "РЕЗУЛЬТАТЫ ПОИСКА ПО ЖАНРУ ФИЛЬМА >> " << _nds << endl;
			buffer_nds = ar[i].adress;
			break;
		}
		int count_spaces = 0;
		for (int i = 0; i < buffer_nds.size(); i++)
		{

			if (buffer_nds[i] < 90 and buffer_nds[i] != 32 and buffer_nds[i] != 45)
			{
				buffer_nds[i] = buffer_nds[i] + 32;
			}

		}
		for (int i = 0; i < buffer_nds.size(); i++)
		{
			if (buffer_nds[i] == 32)
			{
				for (int j = i; j < buffer_nds.size(); j++)
				{
					buffer_nds[j] = buffer_nds[j + 1];
				}
				count_spaces++;
			}
		}
		buffer_nds.resize(buffer_nds.size() - count_spaces);
		//cout << endl << "buffer_nds " << buffer_nds.length () << endl;
		//cout << "_nds " << _nds.length() << endl;
		if (buffer_nds == _nds)
		{

			ar[i].printFilm();
		}
	}
	cout << "|___________|______|_______|____________|___________________|__________________|___|" << endl;
}

void printNDS()
{
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ПО КАКОМУ КРИТЕРИЮ ХОТИТЕ НАЙТИ? " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                           1. МОДЕЛЬ" << endl;
	cout << endl;
	cout << "                           2. ИНИЦИАЛЫ" << endl;
	cout << endl;
	cout << "                           3. ЦВЕТ" << endl;
	cout << endl;
	cout << "                           4. АДРЕС" << endl;
	cout << "________________________________________________________________________________" << endl;

	cout << endl;
	cout << ">>> ";
}

void printNDSinput()
{
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ВВЕДИТЕ ТЕКСТ, ЛЮБЫМ РЕГИСТРОМ" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << ">>> ";
}

void printUp_Down()
{
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ПО ВОЗРАСТАНИЮ ИЛИ ПО УБЫВАНИЮ? " << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                           1. ПО ВОЗРАСТНИЮ" << endl;
	cout << endl;
	cout << "                           2. ПО УБЫВАНИЮ" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << ">>> ";
}

void sort_by_rating(heavycar ar[], int _size, int _up_down, int _raiting_price)
{
	for (int e = 0; e < _size; e++)
	{
		for (int i = 0; i < _size; i++)
		{
			for (int j = i + 1; j < _size; j++)
			{
				switch (_raiting_price)
				{
				case 1:
					switch (_up_down)
					{
					case 1:
						if (ar[j].weight > ar[i].weight)
						{
							swap(ar[i], ar[j]);
						}
						break;
					case 2:
						if (ar[j].weight < ar[i].weight)
						{
							swap(ar[i], ar[j]);
						}
						break;
					}
					break;
				case 2:
					switch (_up_down)
					{
					case 1:
						if (ar[j].gosnum > ar[i].gosnum)
						{
							swap(ar[i], ar[j]);
						}
						break;
					case 2:
						if (ar[j].gosnum < ar[i].gosnum)
						{
							swap(ar[i], ar[j]);
						}
						break;
					}
					break;
				}	
			}
		}
	}
}

heavycar *add_new_film(heavycar *tmp, int *size)
{
	heavycar* new_all_heavycar = new heavycar[*size + 1];

	string model, color, owner, adress;
	double weight;
	int gosnum;

	system("cls");
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ВВЕДИТЕ МОДЕЛЬ" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << ">>> "; cin.ignore(); getline(cin, model);
	system("cls");
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ВВЕДИТЕ ВЛАДЕЛЬЦА" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << ">>> "; getline(cin, owner);
	system("cls");
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ВВЕДИТЕ ЦВЕТ" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << ">>> "; getline(cin, color);
	system ("cls");
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << "                        ВВЕДИТЕ АДРЕС" << endl;
	cout << "________________________________________________________________________________" << endl;
	cout << endl;
	cout << ">>> "; getline (cin, adress);
	do
	{
		system("cls");
		cout << "________________________________________________________________________________" << endl;
		cout << endl;
		cout << "                        ВВЕДИТЕ ВЕС" << endl;
		cout << "________________________________________________________________________________" << endl;
		cout << endl;
		cout << ">>> "; cin >> weight;
	} while (weight < 0.1 or weight > 9999);
	
	do
	{
		system("cls");
		cout << "________________________________________________________________________________" << endl;
		cout << endl;
		cout << "                   ВВЕДИТЕ ГОС. НОМЕР" << endl;
		cout << "________________________________________________________________________________" << endl;
		cout << endl;
		cout << ">>> "; cin >> gosnum;
	} while (gosnum <= 0 or gosnum > 9);

	heavycar new_heavycars = { model ,weight, color, {3,4,2028}, owner, adress, gosnum };

	for (int i = 0; i < *size; i++)
	{
		new_all_heavycar[i] = tmp[i];
	}
	new_all_heavycar[*size] = new_heavycars;
	(*size)++;
	tmp = new_all_heavycar;
	return tmp;
}

heavycar* remove_film(heavycar* tmp, int* size)
{
	if(*size > 0)
	{
		int place;
		heavycar *new_all_heavycar = new heavycar[*size - 1];
		cout << "Какую позицию удалить? ";
		cin >> place;
		for (int i = 0; i < *size - 1; i++)
		{
			if (i < place - 1)
			{
				new_all_heavycar[i] = tmp[i];
			}
			if (i >= place - 1)
			{
				new_all_heavycar[i] = tmp[i + 1];
			}
		}
		(*size)--;
		tmp = new_all_heavycar;
	}
	return tmp;
}

void pause()
{
	system("pause >> 0");
}