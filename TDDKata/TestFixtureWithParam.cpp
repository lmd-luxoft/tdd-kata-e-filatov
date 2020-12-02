#include "pch.h"
#include "TestFixtureWithParam.h"
#include <vector>

std::vector<Param> CreateParametersSet() {
	std::vector<Param> params;
	char str[] = "0,10";
	params.push_back(Param(str, 10));
	params.push_back(Param(str, 10));
	return params;
}

INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam, ::testing::ValuesIn(CreateParametersSet()));