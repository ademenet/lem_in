#include "u-test.h"
#include "../inc/lem_in.h"

MY_UNIT_TEST(get_ants_nb)
{
	int	nb;
	nb = li_get_ants_nb("42");
	UT_ASS("Normal", nb == 42)
	nb = li_get_ants_nb("42");
	UT_ASS("Normal", nb == 42)
	nb = li_get_ants_nb("2147483647");
	UT_ASS("Int max", nb)
	nb = li_get_ants_nb("1");
	UT_ASS("Zero", nb == 1)
	nb = li_get_ants_nb("0");
	UT_ASS("Zero", nb == 0)

	// I have to silence these lines because program exits when it finds an error.
	// nb = li_get_ants_nb("-42");
	// UT_ASS("Negative", nb)
	// nb = li_get_ants_nb("34s3");
	// UT_ASS("Non digit", nb)
	// nb = li_get_ants_nb("");
	// UT_ASS("Nothing", nb)
	// nb = li_get_ants_nb("-2147483648");
	// UT_ASS("Int min", nb)
	// nb = li_get_ants_nb("2147483648");
	// UT_ASS("Int max", nb)
	// nb = li_get_ants_nb("-1");
	// UT_ASS("Zero", nb)

}

ALL_TESTS
{
	MY_TEST("get_ants_nb", get_ants_nb)
}

RUN_TEST
