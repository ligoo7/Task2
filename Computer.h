#pragma once

#include <fstream>
#include <algorithm> 
#include <vector>
#include <iterator>
#include "Helper.h"

class Computer
{
public:

	int code;
	std::string mark;
	std::string processor;
	int frequency;
	int RAM;
	int HDD;
	int VideoCard;
	int value;
	int count;

	Computer(int Acode, std::string Amark, std::string Aprocessor, int Afrequency, int ARAM, int AHDD, int AVideoCard, int Avalue, int Acount)
	{
		code = Acode;
		mark = Amark;
		processor = Aprocessor;
		frequency = Afrequency;
		RAM = ARAM;
		HDD = AHDD;
		VideoCard = AVideoCard;
		value = Avalue;
		count = Acount;
	}

	Computer()
	{
		code = 0;
		mark = "";
		processor = "";
		frequency = 0;
		RAM = 0;
		HDD = 0;
		VideoCard = 0;
		value = 0;
		count = 0;
	}

	~Computer()
	{
	}

	bool operator==(const Computer& comp) const
	{
		return	this->code == comp.code;
	}
};

//поток вывода
std::ostream& operator<<(std::ostream &os, const Computer &comp) {
	os << std::to_string(comp.code) + "\t" + comp.mark + "\t" +	comp.processor + "\t" +
		std::to_string(comp.frequency) + "\t" +	std::to_string(comp.RAM) + "\t" + std::to_string(comp.HDD) + "\t" +
		std::to_string(comp.VideoCard) + "\t" +	std::to_string(comp.value) + "\t" + std::to_string(comp.count) + "\n";

	return os;
}

//поток ввода
std::istream& operator>>(std::istream& is, Computer &comp)
{
	is >> comp.code;
	is >> comp.mark;
	is >> comp.processor;
	is >> comp.frequency;
	is >> comp.RAM;
	is >> comp.HDD;
	is >> comp.VideoCard;
	is >> comp.value;
	is >> comp.count;

	return is;
}

//Predicates

class ProcessorPredicate
{
protected:
	std::string processor;

public:
	ProcessorPredicate(std::string Aprocessor)
	{
		processor = Aprocessor;
	}

	bool operator() (Computer comp)
	{
		return comp.processor == processor;
	}
};

class RAMPredicate
{
protected:
	int RAM;

public:
	RAMPredicate(int ARAM)
	{
		RAM = ARAM;
	}

	bool operator() (Computer comp)
	{
		return comp.RAM == RAM;
	}
};

class VideoPredicate
{
protected:
	int VideoCard;

public:
	VideoPredicate(int AVideoCard)
	{
		VideoCard = AVideoCard;
	}

	bool operator() (Computer comp)
	{
		return comp.VideoCard == VideoCard;
	}
};

class HDDPredicate
{
protected:
	int HDD;

public:
	HDDPredicate(int AHDD)
	{
		HDD = AHDD;
	}

	bool operator() (Computer comp)
	{
		return comp.HDD == HDD;
	}
};

//Comparators

class ProcessorComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.processor < comp2.processor;
	}
};

class RAMComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.RAM < comp2.RAM;
	}
};

class VideoComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.VideoCard < comp2.VideoCard;
	}
};

class HDDComparator
{
public:
	bool operator() (Computer comp1, Computer comp2)
	{
		return comp1.HDD < comp2.HDD;
	}
};

//Sets

class ProcessorSet
{
protected:
	std::string processor;
	std::vector<Computer>* vect;

public:
	ProcessorSet(std::string Aprocessor)
	{
		processor = Aprocessor;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.processor == processor)
			(*vect).push_back(comp);
	}
};

class RAMSet
{
protected:
	int RAM;
	std::vector<Computer>* vect;

public:
	RAMSet(int ARAM)
	{
		RAM = ARAM;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.RAM == RAM)
			(*vect).push_back(comp);
	}
};

class VideoSet
{
protected:
	int VideoCard;
	std::vector<Computer>* vect;

public:
	VideoSet(int AVideoCard)
	{
		VideoCard = AVideoCard;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.VideoCard == VideoCard)
			(*vect).push_back(comp);
	}
};

class HDDSet
{
protected:
	int HDD;
	std::vector<Computer>* vect;

public:
	HDDSet(int AHDD)
	{
		HDD = AHDD;
		vect = new std::vector<Computer>();
	}

	std::vector<Computer> getSet()
	{
		return *vect;
	}

	void operator() (Computer comp)
	{
		if (comp.HDD == HDD)
			(*vect).push_back(comp);
	}
};

//ввод данных
Computer inputComputer()
{
	int code, frequency, RAM, HDD, VideoCard, value, count;
	std::string mark, processor;

	std::cout << "\nƒл€ остановки введите 'stop'\n";
	std::cout << "\n¬ведите код: ";
	code = getInt(1);
	std::cout << "\n¬ведите название марки: ";
	std::cin >> mark;
	if (mark == "stop") throw "stop";
	std::cout << "\n¬ведите тип процессора: ";
	std::cin >> processor;
	if (processor == "stop") throw "stop";
	std::cout << "\n¬ведите частоту работы процессора: ";
	frequency = getInt(1);
	std::cout << "\n¬ведите объем оперативной пам€ти: ";
	RAM = getInt(1); 
	std::cout << "\n¬ведите объем жесткого диска: ";
	HDD = getInt(1);
	std::cout << "\n¬ведите объем пам€ти видеокарты: ";
	VideoCard = getInt(1);
	std::cout << "\n¬ведите ценность: ";
	value = getInt(1);
	std::cout << "\n¬ведите количество экземпл€ров: ";
	count = getInt(1);
	std::cout << std::endl;
	
	return Computer(code, mark, processor, frequency, RAM, HDD, VideoCard, value, count);
}

//редактирование
void editComputer(Computer &comp)
{
	int ACode, Afrequency, ARAM, AHDD, AVideoCard, Avalue, ACount;
	std::string AMark, Aprocessor;

	std::cout << "\nƒл€ отмены введите 'stop', дл€ пропуска пол€ - 'skip'\n";
	std::cout << "\n¬ведите код(текущий = " + std::to_string(comp.code) + "): ";
	ACode = getInt(1, 999999, true);
	if (ACode != -1) comp.code = ACode;

	std::cout << "\n¬ведите название марки(текуща€ = " + comp.mark + "): ";
	std::cin >> AMark;
	if (AMark == "stop") throw "stop";
	if (AMark != "skip")  comp.mark = AMark; 

	std::cout << "\n¬ведите тип процессора(текущий = " + comp.processor + "): ";
	std::cin >> Aprocessor;
	if (Aprocessor == "stop") throw "stop";
	if (Aprocessor != "skip") comp.processor = Aprocessor;

	std::cout << "\n¬ведите частоту работы процессора(текуща€ = " + std::to_string(comp.frequency) + "): ";
	Afrequency = getInt(1, 999999, true);
	if (Afrequency != -1) comp.frequency = Afrequency;

	std::cout << "\n¬ведите объем оперативной пам€ти(текущий = " + std::to_string(comp.RAM) + "): ";
	ARAM = getInt(1, 999999, true);
	if (ARAM != -1) comp.RAM = ARAM;

	std::cout << "\n¬ведите объем жесткого диска(текущий = " + std::to_string(comp.HDD) + "): ";
	AHDD = getInt(1, 999999, true);
	if (AHDD != -1) comp.HDD = AHDD;

	std::cout << "\n¬ведите объем пам€ти видеокарты(текущий = " + std::to_string(comp.VideoCard) + "): ";
	 AVideoCard = getInt(1, 999999, true);
	if (AVideoCard != -1) comp.VideoCard = AVideoCard;

	std::cout << "\n¬ведите ценность(текуща€ = " + std::to_string(comp.value) + "): ";
	Avalue = getInt(1, 999999, true);
	if (Avalue != -1) comp.value = Avalue;

	std::cout << "\n¬ведите количество экземпл€ров(текущее = " + std::to_string(comp.count) + "): ";
	ACount = getInt(1, 999999, true);
	if (ACount != -1) comp.count = ACount;
}