#include "pch.h"
#include "TestFixtureWithParam.h"
#include <vector>

//INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam,
//	::testing::Values(Param("2,3", 5), Param("4", 4)));

std::vector<Param> CreateParametersSet()
{
	std::vector<Param> p;
	p.push_back(Param("7456,55", 7511));
	p.push_back(Param("34,5623345", 5623379));
	p.push_back(Param(",55", -2));
	p.push_back(Param("10,", -2));
	p.push_back(Param("10,50,10", 70));
	p.push_back(Param("10,50,10,130", 200));
	p.push_back(Param("10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10", 200));
	p.push_back(Param("1\n2,3", 6));
	p.push_back(Param("10,10,10,10,10\n10,10,10,10,10\n10,10,10,10,10,10,10,10,10,10", 200));
	p.push_back(Param("1,\n", -3));
	p.push_back(Param("10,10,1\n,10,10\n10,10,1\n,10,10\n10,10,10,10,10,10,10,10,10,10", -3));
	p.push_back(Param("//;\n10;10;10;10;10;10;10;10", 80));
	p.push_back(Param("//!\n10!10!10!10!10!10!10!10", 80));
	p.push_back(Param("//;;\n10;;10;;10", -4)); //Предположим, что по ТЗ сепатор сосотоит только из одного символа
	p.push_back(Param("//1\n1011011011011010110110", -4)); //Числововой сепаратор недопустим
	p.push_back(Param("//;\n10!10!10", -3));
	p.push_back(Param("/;\n10;10;10", -3));
	return p;
}

INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam,
	::testing::ValuesIn(CreateParametersSet()));