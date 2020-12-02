#pragma once
#include "pch.h"
#include "Calculator.h"

class TestFixture : public ::testing::Test {
protected:
	Calculator* test_calc;
	void SetUp() override;
	void TearDown() override;
};