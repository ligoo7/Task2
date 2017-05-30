/*5. ������ ���������� ��������������� ����� � ��������� ����� ����������, ����� ����������, �������� ������ ����������, 
������� ����������� ������, ������� �������� �����, ������� ������ ����������, ��������� ���������� � ����������� �����������. 
����� �� ���� ����������, ������ ���, ������ ���������� � ������ �������� �����. 
��������� �����, 2 ���� 9 ������*/

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
		//�������� ������
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
		//�����
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
					std::cout << "���������\n";
					break;
				case 0:
					break;
				}
				break;
		//�����
		case 3:
			printMenuSearch();
			choice = getInt(0, 2);
			//���
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
				//��������
				switch (choice)
				{
				case 1:
					std::cout << "������� ��� ����������: ";
					std::cin >> str;
					if (binary)
						found = cont.findProcessorBinary(str, it);
					else
						found = cont.findProcessor(str, it);
					break;
				case 2:
					std::cout << "������� ����� ���: ";
					if (binary)
						found = cont.findRAMBinary(getInt(1), it);
					else
						found = cont.findRAM(getInt(1), it);
					break;
				case 3:
					std::cout << "������� ������ ����������: ";
					if (binary)
						found = cont.findVideoBinary(getInt(1), it);
					else
						found = cont.findVideo(getInt(1), it);
					break;
				case 4:
					std::cout << "������� ����� �������� �����: ";
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
						std::cout << "������ �������\n";
						printMenuAction();
						choice = getInt(0, 3);
						while (choice != 0)
						{
							//�������� � �������
							switch (choice)
							{
							case 1:
								std::cout << "\n���\t�����\t���\t�������\tram\thdd\t�����\t����\t����������\n\n";
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
						std::cout << "������ �� �������\n\n";
			}
			break;
		//����������
		case 4:
			try
			{
				cont.add(inputComputer());
			}
			catch (const char*) 
			{
			}
			break;
		//������������
		case 5:
			printMenuFind();
			choice = getInt(0, 4);
			switch (choice)
			{
			case 1:
				std::cout << "������� ��� ����������: ";
				std::cin >> str;
				subset = cont.findProcessorSet(str);
				break;
			case 2:
				std::cout << "������� ����� ���: ";
				subset = cont.findRAMSet(getInt(1));
				break;
			case 3:
				std::cout << "������� ������ ����������: ";
				subset = cont.findVideoSet(getInt(1));
				break;
			case 4:
				std::cout << "������� ����� �������� �����: ";
				subset = cont.findHDDSet(getInt(1));
				break;
			case 0:
				break;
			}
			if (choice != 0)
			{
				if (subset.vectSize() == 0)
				{
					std::cout << "\n������� � ����� ��������������� ���\n\n";
					break;
				}
				else
				{
					std::cout << std::endl;
					std::cout << subset.vectSize();
					std::cout << " ������� �������. �������:\n";
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
					std::cout << "���������\n\n";
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

