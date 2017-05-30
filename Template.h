#pragma once
//2stop числом не считывает
//cохранение подвектора
template <class T>
class Container
{
protected:

	std::vector<T> vect;

public:
	typedef std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> iter;
	typedef std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<T>>> constIter;

	int vectSize()
	{
		return vect.size();
	}

	void vectClear()
	{
		vect.clear();
	}

	constIter vectBegin()
	{
		return vect.cbegin();
	}

	constIter vectEnd()
	{
		return vect.cend();
	}

	Container(int size)
	{
		vect = std::vector<T>(size);
	}

	Container()
	{
		vect = std::vector<T>();
	}

	~Container() 
	{
	}

	void add(T el)
	{
		if (!find(el))
			vect.push_back(el);
	}

	void remove(iter &it) {
		vect.erase(it);
	}

	bool find(T el)
	{
		return std::find(vect.begin(), vect.end(), el) != vect.end();
	}

	template<class Predicate>
	bool find(Predicate &pred, iter &it)
	{
		iter tmp = std::find_if(vect.begin(), vect.end(), pred);
		if (tmp == vect.end()) return false;
		it = tmp;
		return true;
	}

	template<class Comparator>
	bool find(T el, Comparator &comp, iter &it)
	{
		std::sort(vect.begin(), vect.end(), comp);
		iter tmp = std::lower_bound(vect.begin(), vect.end(), el, comp);
		if (tmp == vect.end() || comp(el, *tmp))
			return false;
		it = tmp;
		return true;
	}

	template<class Set>
	std::vector<T> findSubSet(Set subset)
	{
		std::for_each(vect.begin(), vect.end(), subset);
		return subset.getSet();
	}
};

class ContainerComp : public Container<Computer>
{
public:
	typedef std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Computer>>> iter;

	bool findProcessor(std::string processor, iter &it)
	{
		return find(ProcessorPredicate(processor), it);
	}

	bool findRAM(int RAM, iter &it)
	{
		return find(RAMPredicate(RAM), it);
	}

	bool findVideo(int VideoCard, iter &it)
	{
		return find(VideoPredicate(VideoCard), it);
	}

	bool findHDD(int HDD, iter &it)
	{
		return find(HDDPredicate(HDD), it);
	}

	bool findProcessorBinary(std::string processor, iter &it)
	{
		return find(Computer(0, "", processor, 0, 0, 0, 0, 0, 0), ProcessorComparator(), it);
	}

	bool findRAMBinary(int RAM, iter &it)
	{
		return find(Computer(0, "", "", 0, RAM, 0, 0, 0, 0), RAMComparator(), it);
	}

	bool findVideoBinary(int VideoCard, iter &it)
	{
		return find(Computer(0, "", "", 0, 0, 0, VideoCard, 0, 0), VideoComparator(), it);
	}

	bool findHDDBinary(int HDD, iter &it)
	{
		return find(Computer(0, "", "", 0, 0, HDD, 0, 0, 0), HDDComparator(), it);
	}

	ContainerComp findProcessorSet(std::string processor)
	{
		ContainerComp set;
		set.vect = findSubSet(ProcessorSet(processor));
		return set;
	}

	ContainerComp findRAMSet(int RAM)
	{
		ContainerComp set;
		set.vect = findSubSet(RAMSet(RAM));
		return set;
	}

	ContainerComp findVideoSet(int VideoCard)
	{
		ContainerComp set;
		set.vect = findSubSet(VideoSet(VideoCard));
		return set;
	}

	ContainerComp findHDDSet(int HDD)
	{
		ContainerComp set;
		set.vect = findSubSet(HDDSet(HDD));
		return set;
	}

	void getFromFile(std::fstream fin)
	{
		std::istream_iterator<Computer> is(fin);
		vect.clear();
		if (fin.eof()) return;
		Computer comp = *is;
		while (!fin.fail() && !fin.eof())
		{
			comp = *is++;
			add(comp);
		}
		std::cout << "Готово\n\n";
		fin.close();
	}

	void printToFile(std::fstream fout)
	{
		copy(vect.begin(), vect.end(), std::ostream_iterator<Computer>(fout, "\n"));
		fout.close();
	}
};

void getFromConsole(ContainerComp &cont)
{
	cont.vectClear();
	Computer comp;
	while (true)
	{
		try
		{
			comp = inputComputer();
		}
		catch (const char*)
		{
			return;
		}
		cont.add(comp);
	}
}

void printToConsole(ContainerComp &cont)
{
	if (cont.vectSize() == 0)
		std::cout << std::endl << "Записи отсутствуют\n" << std::endl;
	else
	{
		std::cout << "код\tмарка\tтип\tчастота\tram\thdd\tвидео\tцена\tколичество\n\n";
		copy(cont.vectBegin(), cont.vectEnd(), std::ostream_iterator<Computer>(std::cout, "\n"));
	}
}