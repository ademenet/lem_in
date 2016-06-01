#include "u-test.h"
#include "../inc/lem_in.h"

MY_UNIT_TEST(parsing_name)
{
	// li_parsing();
	UT_ASS("OK", 1 == 1)
}

ALL_TESTS
{
	MY_TEST("parsing", parsing_name)
}

RUN_TEST
