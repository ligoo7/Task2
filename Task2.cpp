/*5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора, частотой работы процессора, 
объемом оперативной памяти, объемом жесткого диска, объемом памяти видеокарты, ценностью компьютера и количеством экземпляров. 
Поиск по типу процессора, объему ОЗУ, памяти видеокарты и объему жесткого диска. 
Горлищева Лидия, 2 курс 9 группа*/

#include "stdafx.h"
#include "Computer.h"
#include "Menu.h"
#include "Template.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	ContainerComp cont = ContainerComp();
	ContainerComp subset = ContainerComp();
	std::vector<Computer>::iterator it;
	std::string FName;
	std::string str;
	int choice;
	bool binary;
	bool found;

	while (true)
	{
		printMenu();
		choice = getInt(0,5);

		switch (choice)
		{
		//загрузка данных
		case 1:
			printMenuWay();
			choice = getInt(0, 2);
			switch (choice)
			{
			case 1:
				getFromConsole(cont);
				break;
			case 2:
				FName = fileIn();
				cont.getFromFile(std::fstream(FName,std::ios::in));
				break;
			case 0:
				break;
			}
			break; 
		//вывод
		case 2:
				printMenuWay();
				choice = getInt(0, 2);
				switch (choice)
				{
				case 1:
					printToConsole(cont);
					break;
				case 2:
					FName = fileOut();
					cont.printToFile(std::fstream(FName, std::ios::out));
					std::cout << "Сохранено\n";
					break;
				case 0:
					break;
				}
				break;
		//поиск
		case 3:
			printMenuSearch();
			choice = getInt(0, 2);
			//тип
			switch (choice)
			{
			case 1:
				binary = false;
				break;
			case 2:
				binary = true;
				break;
			case 0:
				break;
			}
			if (choice != 0)
			{
				printMenuFind();
				choice = getInt(0, 4);
				//критерий
				switch (choice)
				{
				case 1:
					std::cout << "Введите тип процессора: ";
					std::cin >> str;
					if (binary)
						found = cont.findProcessorBinary(str, it);
					else
						found = cont.findProcessor(str, it);
					break;
				case 2:
					std::cout << "Введите объем ОЗУ: ";
					if (binary)
						found = cont.findRAMBinary(getInt(1), it);
					else
						found = cont.findRAM(getInt(1), it);
					break;
				case 3:
					std::cout << "Введите память видеокарты: ";
					if (binary)
						found = cont.findVideoBinary(getInt(1), it);
					else
						found = cont.findVideo(getInt(1), it);
					break;
				case 4:
					std::cout << "Введите объем жесткого диска: ";
					if (binary)
						found = cont.findHDDBinary(getInt(1), it);
					else
						found = cont.findHDD(getInt(1), it);
					break;
				case 0:
					break;
				}
				if (choice != 0)
					if (found)
					{
						std::cout << "Запись найдена\n";
						printMenuAction();
						choice = getInt(0, 3);
						while (choice != 0)
						{
							//действия с записью
							switch (choice)
							{
							case 1:
								std::cout << "\nкод\tмарка\tтип\tчастота\tram\thdd\tвидео\tцена\tколичество\n\n";
								std::cout << *it;
								break;
							case 2:
								try
								{
									editComputer(*it);
								}
								catch (const char* str)
								{
									if (str == "stop")
										break;
								}
								break;
							case 3:
								cont.remove(it);
								break;
							case 0:
								break;
							}
							if (choice == 3) break;
							printMenuAction();
							choice = getInt(0, 3);
						}
					}
					else
						std::cout << "Запись не найдена\n\n";
			}
			break;
		//добавление
		case 4:
			try
			{
				cont.add(inputComputer());
			}
			catch (const char*) 
			{
			}
			break;
		//подмножество
		case 5:
			printMenuFind();
			choice = getInt(0, 4);
			switch (choice)
			{
			case 1:
				std::cout << "Введите тип процессора: ";
				std::cin >> str;
				subset = cont.findProcessorSet(str);
				break;
			case 2:
				std::cout << "Введите объем ОЗУ: ";
				subset = cont.findRAMSet(getInt(1));
				break;
			case 3:
				std::cout << "Введите память видеокарты: ";
				subset = cont.findVideoSet(getInt(1));
				break;
			case 4:
				std::cout << "Введите объем жесткого диска: ";
				subset = cont.findHDDSet(getInt(1));
				break;
			case 0:
				break;
			}
			if (choice != 0)
			{
				if (subset.vectSize() == 0)
				{
					std::cout << "\nЗаписей с такой характеристикой нет\n\n";
					break;
				}
				else
				{
					std::cout << std::endl;
					std::cout << subset.vectSize();
					std::cout << " записей найдено. Вывести:\n";
				}
				printMenuWay();
				choice = getInt(0, 2);
				switch (choice)
				{
				case 1:
					printToConsole(subset);
					break;
				case 2:
					FName = fileOut();
					cont.printToFile(std::fstream(FName, std::ios::out));
					std::cout << "Сохранено\n\n";
					break;
				case 0:
					break;
				}
			}
			break;
		case 0:
			return 0;
		}
	}
}

