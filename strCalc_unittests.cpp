#include <CppUTest/CommandLineTestRunner.h>

extern "C"{
#include "strCalc.h"
}

// Exec unit tests
int main(int ac, char** av)
{
	   return CommandLineTestRunner::RunAllTests(ac, av);
}

TEST_GROUP(strCalcTests)
{

};

TEST(strCalcTests, first)
{
	char s[]="1";
	CHECK_EQUAL(1,Add(s));
}

TEST(strCalcTests, twoNums)
{
	char s[]="1 2";
	CHECK_EQUAL(3,Add(s));
}

TEST(strCalcTests, threeNums)
{
	char s[]="1, -10, 12";
	CHECK_EQUAL(3,Add(s));
}

TEST(strCalcTests, test1)
{
	char s[]="1\n2,3";
	CHECK_EQUAL(6,Add(s));
}

TEST(strCalcTests, test2)
{
	char s[]="1";
	CHECK_EQUAL(1,Add(s));
}


TEST(strCalcTests, test3)
{
	char s[]="//%\n12, 48%-48";
	CHECK_EQUAL(12,Add(s));
}



