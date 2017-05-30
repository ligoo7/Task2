#pragma once

#include <iostream>
#include <string>

//получить число из указанного диапазона
int getInt(int min = 0, int max = 999999)
{
	std::string str;
	int res; 

	while (true)
	{
		try
		{
			std::cin >> str;
			if (str == "stop") throw "stop";
			if (str == "skip") return -1;
			res = std::stoi(str);
			while (res < min || res > max)
			{
				std::cout << "Введите число от " << min << " до " << max << std::endl;
				std::cin >> str;
				if (str == "stop") throw "stop";
				if (str == "skip") return -1;
				res = std::stoi(str);
			}
			return res;
		}
		catch (std::exception)
		{
			std::cout << "Неверный символ! Повторите ввод:\n";
		}
	}
}

//проверка имени файла
std::string fileIn()
{
	std::fstream file;
	std::string res;
	std::cout << "Введите имя файла: ";
	std::cin >> res;
	std::cout << std::endl;
	file.open(res + ".txt");
	while (!file.is_open()) 
	{
		std::cout << "Невозможно открыть файл, повторите ввод: ";
		std::cin >> res;
		file.open(res + ".txt");
	};
	file.close();
	return res + ".txt";
}

//имя файла для записи
std::string fileOut()
{
	std::string fout;
	std::cout << "Введите имя файла: ";
	std::cin >> fout;
	std::cout << std::endl;
	return fout + ".txt";
}