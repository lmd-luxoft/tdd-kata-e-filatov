#include "pch.h"
#include "TestFixture.h"

void TestFixture::SetUp() {
	test_calc = new Calculator();
}

void TestFixture::TearDown() {
	delete test_calc;
}