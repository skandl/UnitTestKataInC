#include <CppUTest/CommandLineTestRunner.h>

extern "C"{
#include "strCalc.h"
}

// Exec unit tests
int main(int ac, char** av)
{
	   return CommandLineTestRunner::RunAllTests(ac, av);
}


TEST_GROUP(strCalcGrp)
{

};

TEST(strCalcGrp, strCalc_null)
{
	char s[]="";
	CHECK_EQUAL(Add(0),0);
	CHECK_EQUAL(Add(s),0);
}

TEST(strCalcGrp, strCalc_invalidStr)
{
	char s1[]="asdf";
	char s2[]="asdf ghsfdlg; kjsf";
	CHECK_EQUAL(Add(s1),0);
	CHECK_EQUAL(Add(s2),0);
}

TEST(strCalcGrp, strCalc_oneNum)
{
	char s1[]="1";
	char s2[]="93251";
	CHECK_EQUAL(Add(s1),1);
	CHECK_EQUAL(Add(s2),93251);
}

TEST(strCalcGrp, strCalc_twoNums)
{
	char s1[]="1 0";
	char s2[]="-21 2";
	CHECK_EQUAL(Add(s1),1);
	CHECK_EQUAL(Add(s2),-19);
}

TEST(strCalcGrp, strCalc_threeNums)
{
	char s[]="1 2 3";
	CHECK_EQUAL(Add(s),6);
}

TEST(strCalcGrp, strCalc_mixed)
{
	char s[]="1,2 3";
	CHECK_EQUAL(6, Add(s));
}






