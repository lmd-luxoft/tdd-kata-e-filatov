#pragma once
#include "TestFixture.h"

struct Param {
	char* _input;
	int _result;
	Param(char* input, int result) : _input(input), _result(result) {};
};

class TestFixtureWithParam : public TestFixture, public ::testing::WithParamInterface<Param>{
};

