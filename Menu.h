#pragma once

#include <iostream>
#include <string>

//основное меню
void printMenu()
{
	std::cout << "Основное меню:\n";
	std::cout << "1. Загрузка данных\n";
	std::cout << "2. Вывод данных\n";
	std::cout << "3. Поиск\n";
	std::cout << "4. Добавление\n";
	std::cout << "5. Подмножество\n";
	std::cout << "0. Выход\n\n";
}

//файл или консоль
void printMenuWay()
{
	std::cout << "\n1. Консоль\n";
	std::cout << "2. Файл\n";
	std::cout << "0. Отмена\n\n";
}

//критерий поиска
void printMenuFind()
{
	std::cout << "\n1. По типу процессора\n";
	std::cout << "2. По объему ОЗУ\n";
	std::cout << "3. По памяти видеокарты\n";
	std::cout << "4. По объему жесткого диска\n";
	std::cout << "0. Отмена\n\n";
}

//способ поиска
void printMenuSearch()
{
	std::cout << "\n1. Линейный\n";
	std::cout << "2. Двоичный\n";
	std::cout << "0. Отмена\n\n";
}

//действия с записью
void printMenuAction()
{
	std::cout << "\n1. Вывести\n";
	std::cout << "2. Изменить\n";
	std::cout << "3. Удалить\n";
	std::cout << "0. Назад\n\n";
}