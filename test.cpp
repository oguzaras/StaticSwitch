/*
 *  Copyright (C) 2016  Oguz ARAS
 *
 *	This file is part of StaticSwitch.
 *
 *    StaticSwitch is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    StaticSwitch is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdlib.h>



#include "StaticSwitch.h"

enum test_enum {
	toto,
	lolo,
	coco,
	popo,
	momo,
	soso
};

struct ITestTemp {
	virtual std::string print() = 0;
};


template<int theEnum>
struct TestTemp : public ITestTemp {
public:
	std::string print() { return "error"; }
};
template<>
struct TestTemp<toto> : public ITestTemp {
public:
	std::string print() { return "toto"; }
};
template<>
struct TestTemp<lolo> : public ITestTemp {
public:
	std::string print() { return "lolo"; }
};
template<>
struct TestTemp<coco> : public ITestTemp {
public:
	std::string print() { return "coco"; }
};





template<int Enum1, int Enum2>
struct TestTemp2 : public ITestTemp {
public:
	std::string print() { return "error"; }
};
template<>
struct TestTemp2<popo, lolo> : public ITestTemp {
public:
	std::string print() { return "popo, lolo"; }
};
template<>
struct TestTemp2<soso, momo> : public ITestTemp {
public:
	std::string print() { return "soso, momo"; }
};
template<>
struct TestTemp2<coco, soso> : public ITestTemp {
public:
	std::string print() { return "coco, soso"; }
};





template<int Enum1, int Enum2, int Enum3>
struct TestTemp3 : public ITestTemp {
public:
	std::string print() { return "error"; }
};
template<>
struct TestTemp3<popo, lolo, coco> : public ITestTemp {
public:
	std::string print() { return "popo, lolo, coco"; }
};
template<>
struct TestTemp3<soso, momo, lolo> : public ITestTemp {
public:
	std::string print() { return "soso, momo, lolo"; }
};
template<>
struct TestTemp3<coco, soso, toto> : public ITestTemp {
public:
	std::string print() { return "coco, soso, toto"; }
};



typedef ClassSwitch<TestTemp, ITestTemp, (int)soso> testChooser;
typedef ClassSwitch2<TestTemp2, ITestTemp, (int)soso, (int)soso> testChooser2;
typedef ClassSwitch3<TestTemp3, ITestTemp, (int)soso, (int)soso, (int)soso> testChooser3;


int main() {

	ITestTemp* test1 = testChooser::Choose((int)lolo);
	std::string s = test1->print();
	std::cout << s.c_str() << std::endl;

	ITestTemp* test2 = testChooser2::Choose((int)popo, (int)lolo);
	s = test2->print();
	std::cout << s.c_str() << std::endl;
	ITestTemp* test22 = testChooser2::Choose((int)soso, (int)momo);
	s = test22->print();
	std::cout << s.c_str() << std::endl;
	ITestTemp* test23 = testChooser2::Choose((int)coco, (int)soso);
	s = test23->print();
	std::cout << s.c_str() << std::endl;



	ITestTemp* test3 = testChooser3::Choose((int)popo, (int)lolo, (int)coco);
	s = test3->print();
	std::cout << s.c_str() << std::endl;
	ITestTemp* test32 = testChooser3::Choose((int)soso, (int)momo, (int)lolo);
	s = test32->print();
	std::cout << s.c_str() << std::endl;
	ITestTemp* test33 = testChooser3::Choose((int)coco, (int)soso, (int)toto);
	s = test33->print();
	std::cout << s.c_str() << std::endl;

	system("pause");
	return 0;
}