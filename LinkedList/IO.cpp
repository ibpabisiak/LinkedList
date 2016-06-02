#include "stdafx.h"
#include "IO.h"

List IO::list;

int IO::Main(void)
{
	int choice = 0;
	do
	{
		std::cout
			<< "[----------------------------------------]" << std::endl
			<< "[1] Dodaj element do listy" << std::endl
			<< "[2] Usun element z listy" << std::endl
			<< "[3] Sortuj liste" << std::endl
			<< "[4] Wyswietl zawartosc listy" << std::endl
			<< "[0] Zakoncz dzialanie programu" << std::endl;
		std::cin >> choice;
	
		switch (choice)
		{
		case 1:	IO::AddNewItem();
			break;
		case 2:	IO::RemoveItem();
			break;
		case 3:	IO::SortList();
			break;
		case 4:	IO::PrintList();
			break;
		default: IO::BadChoice();
			break;
		}
	} while (choice != 0);
	return 0;
}

void IO::AddNewItem()
{
	std::string tmp;
	system("cls");
	std::cout << " * Wprowadz wartosc dla nowego elementu: " << std::endl;
	std::cin >> tmp;

	if (IO::list.Add(tmp))
		std::cout << " * Nowy element dodany pomyslnie." << std::endl << std::endl;
	else
		std::cout << " * Nie udalo sie dodac nowego elementu, sprobuj ponownie." << std::endl << std::endl;
}

void IO::RemoveItem()
{
	std::string tmp;
	system("cls");
	std::cout << " * Wprowadz wartosc elementu ktory chcesz usunac: " << std::endl;
	std::cin >> tmp;

	if (IO::list.Remove(tmp))
		std::cout << " * Element usuniety pomyslnie." << std::endl << std::endl;
	else
		std::cout << " * Nie udalo sie usunac wskazanego elementu, sprobuj ponownie." << std::endl << std::endl;
}

void IO::SortList()
{
	system("cls");
	IO::list.Sort();
	std::cout << " * Lista zostala posortowana alfabetycznie." << std::endl;
}

void IO::PrintList()
{
	system("cls");
	IO::list.ShowList();
}

void IO::BadChoice()
{
	std::cout << " * Zly wybor, sprobuj ponownie." << std::endl;
}
