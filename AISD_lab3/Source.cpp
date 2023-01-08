#pragma once
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <class T>
class Plenty {
private:
	vector<T*> data;
	int size;

public:
	Plenty() = default;
	Plenty(int s) {
		size = s;
		data.reserve(s);
	}
	Plenty(Plenty<T>& second) = default;
	~Plenty() = default;
	Plenty& operator =(const Plenty& v) = default;

	bool check_num(T num) {
		for (int i = 0; i < size; i++) {
			if (num == data.at(i)
				return true;
		}
		return false;
	}


	T operator[](const int i) {
		if (!data)
			throw std::logic_error("arr == nullptr");
		if (i > size - 1 || i < 0)
			throw std::logic_error("invalide index");
		return data.at(i);
	}

	Plenty& operator+=(T num)
	{
		data.push_back(num);
		return *this;
	}
	Plenty operator+(const Plenty& second) {
		Plenty tmp;
		tmp.data = data;
		for (int i = 0; i < second.size; i++) {
			if (check_num(second.data.at(i) == false))
			{
				tmp.data.push_back(second.data.at(i));
			}
		}
		return tmp;
	}
	Plenty operator-(const Plenty& second) {
		Plenty tmp(size);
		tmp.data = data;
		bool flag = false;
		for (int i = 0; i < size; i++) {
			flag = false;
			for (int j = 0; j < second.size; j++) {
				if (data.at(i) == second.data.at(j)
				{
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				tmp.data.push_back(data.at(i));
			}
		}
		return tmp;
	}
	Plenty operator+(T num) {
		Plenty tmp;
		tmp.data = data;
		if (check_num(num) == false) {
			tmp.data.push_back(num);
		}
		return tmp;
	}
	Plenty operator-(T num)
	{
		Plenty tmp;
		tmp.data = data;
		if (check_num(num) == true) {
			for (int i = 0; i < tmp.size; i++) {
				if (tmp.data.at(i) == num)
				{
					tmp.data.erase(i);
					data_n.size--;
					break;
				}
			}
		}
		else std::cout << "Set have not got this num" << std::endl;
		return tmp;
	}
	Plenty& operator-=(T num) {
		if (check_num(num) == true) {
			for (int i = 0; i < size; i++) {
				if (data.at(i) == num)
				{
					data.erase(i);
					size--;
					break;
				}
			}
		}
		else std::cout << "Set have not got this num" << std::endl;
		return *this;
	}
	Plenty intersection(const Plenty& second) {
		Plenty tmp(size);
		bool flag = false;
		for (int i = 0; i < size; i++) {
			flag = false;
			for (int j = 0; j < second.size; j++) {
				if (data.at(i) == second.data.at(j))
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
			{
				tmp.data.push_back(data[i]);
				tmp.size++;
			}
		}
		return tmp;
	}

	bool operator==(const Plenty& second) {
		if (second.size != size)
			return false;
		else
		{
			bool flag = false;
			for (int i = 0; i < size; i++)
			{
				flag = false;
				for (int j = 0; j < second.size; j++) {
					if (data[i] == second.data[j]) {
						flag = true;
						break;
					}
				}
				if (flag == false)
					return false;
			}
			return true;
		}
	}

	bool operator!=(const Plenty& second) {
		if (second.size != size)
			return true;
		else
		{
			bool flag = true;
			for (int i = 0; i < size; i++)
			{
				flag = true;
				for (int j = 0; j < second.size; j++) {
					if (data[i] == second.data[j]) {
						flag = false;
						break;
					}
				}
				if (flag == true)
					return true;
			}
			return false;
		}
	}
	friend std::ostream& operator<<(std::ostream& s, const Plenty<T>& set)
	{
		for (int i = 0; i < set.size; i++) {
			s << set.data[i] << "  ";
		}
		return s;
	}
};

std::ostream& operator<<(std::ostream& out, const std::pair<int, double>& p)
{
	out << "{" << p.first << ", " << p.second << "}";
	return out;
}

int main() {
	try {
		Plenty<int> p1, p11;
		p1 += 6;
		p1 += 7;
		p1 += 8;
		p1 += 3;
		p1 += 4;
		/*set11 += 2;
		set11 += 3;
		set11 += 7;
		set11 += 8;*/
		p11 = p1 + 5;
		p11 = p1 - 6;
		p11 -= 7;
		std::cout << "p 1: " << p1 << std::endl;
		std::cout << "p 11: " << p11 << std::endl;
		std::cout << "p1+p11: " << p1 + p11 << std::endl;
		std::cout << "p1-p11: " << p1 - p11 << std::endl;
		std::cout << "intersection: " << p1.intersection(p11) << std::endl;
		//std::cout << "task: " << set1.check_count(set11) << std::endl;
		std::cout << "equality: " << (p1 == p11) << std::endl;
		std::cout << "not equality: " << (p1 != p11) << std::endl;
		std::cout << "index: " << p1[1] << std::endl;
		std::cout << std::endl;

		Plenty<float> p2, p22;
		p2 += 6.4;
		p2 += 7.5;
		p2 += 8.9;
		p2 += 1.1;
		p2 += 4.9;
		/*set22 += 3.3;
		set22 += 6.4;
		set22 += 7.7;*/
		p22 = p2 + 4.4;
		p22 = p2 - 6.4;
		p22 -= 7.5;
		std::cout << "p 2: " << p2 << std::endl;
		std::cout << "p 22: " << p22 << std::endl;
		std::cout << "p2+p22: " << p2 + p22 << std::endl;
		std::cout << "p2-p22: " << p2 - p22 << std::endl;
		std::cout << "intersection: " << p2.intersection(p22) << std::endl;
		//std::cout << "task: " << set22.check_count(set2) << std::endl;
		std::cout << "equality: " << (p2 == p22) << std::endl;
		std::cout << "not equality: " << (p2 != p22) << std::endl;
		std::cout << "index: " << p2[1] << std::endl;
		std::cout << std::endl;

		Plenty<std::string> p3, p33;
		p3 += "mom";
		p3 += "nik";
		p3 += "kot";
		p3 += "nen";
		p3 += "pol";
		/*set33 += "m";
		set33 += "rt";
		set33 += "w";*/
		p33 = p3 + "ret";
		p33 = p3 - "mom";
		p33 -= "nik";
		p33 += "you";
		std::cout << "p 3: " << p3 << std::endl;
		std::cout << "p 33: " << p33 << std::endl;
		std::cout << "p3+p33: " << p3 + p33 << std::endl;
		std::cout << "p3-p33: " << p3 - p33 << std::endl;
		std::cout << "intersection: " << p3.intersection(p33) << std::endl;
		//std::cout << "task: " << set3.check_count(set33) << std::endl;
		std::cout << "equality: " << (p3 == p33) << std::endl;
		std::cout << "not equality: " << (p3 != p33) << std::endl;
		std::cout << "index: " << p3[1] << std::endl;
		std::cout << std::endl;

		Plenty<std::pair<int, double>> p4, p44;
		p4 += {1, 3.2};
		p4 += {2, 5.7};
		p4 += {3, 4.4};
		p4 += {8, 9.0};
		p4 += {10, 3.5};
		/*set44 += {1, 3.3};
		set44 += {1, 3.2};
		set44 += {2, 5.6};*/
		p44 = p4 + std::pair<int, double>(1, 4.4);
		p44 = p4 - std::pair<int, double>(1, 3.2);
		p44 -= {2, 5.7};
		std::cout << "p 4: " << p4 << std::endl;
		std::cout << "p 44: " << p44 << std::endl;
		std::cout << "p4+p44: " << p4 + p44 << std::endl;
		std::cout << "p4-p44: " << p4 - p44 << std::endl;
		std::cout << "intersection: " << p4.intersection(p44) << std::endl;
		//std::cout << "task: " << set44.check_count(set4) << std::endl;
		std::cout << "equality: " << (p4 == p44) << std::endl;
		std::cout << "not equality: " << (p4 != p44) << std::endl;
		std::cout << "index: " << p4[1] << std::endl;
		std::cout << std::endl;


		Plenty<std::pair<int, double>> p, pp;
		p += {1, 3.2};
		p += {2, 5.7};
		p += {3, 4.4};
		pp = p + std::pair<int, double>(1, 4.4);
		p += {1, 4.4};
		std::cout << "p: " << p << std::endl;
		std::cout << "pp: " << pp << std::endl;
		std::cout << "equality: " << (p == pp) << std::endl;
		std::cout << "not equality: " << (p != pp) << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}