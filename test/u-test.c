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

MY_UNIT_TEST(errorempty)
{
	char line[1] = "a";
	li_errorempty(line);
	// char linerr[0];
	// li_errorempty(linerr);
}

MY_UNIT_TEST(get_room)
{
	char	*nom;
	int		coord_x;
	int		coord_y;

	char	line1[30] = "nom 2 3";
	nom = li_get_room(line1, &coord_x, &coord_y);
	UT_ASS("coord_x", coord_x == 2)
	UT_ASS("coord_y", coord_y == 3)
	UT_ASS("nom", strcmp(nom, "nom") == 0)

	char	line5[30] = "21 3 3";
	nom = li_get_room(line5, &coord_x, &coord_y);
	UT_ASS("coord_x", coord_x == 3)
	UT_ASS("coord_y", coord_y == 3)
	UT_ASS("21", strcmp(nom, "21") == 0)

	char	line6[50] = "nom-bizarre-avec-des-tirets 2147483647 2147483647";
	nom = li_get_room(line6, &coord_x, &coord_y);
	UT_ASS("coord_x", coord_x == 2147483647)
	UT_ASS("coord_y", coord_y == 2147483647)
	UT_ASS("tirets", strcmp(nom, "nom-bizarre-avec-des-tirets") == 0)


	// char	line2[30] = "Lerror 2 3";
	// nom = li_get_room(line2, &coord_x, &coord_y);

	// char	line3[30] = "#error 2 3";
	// nom = li_get_room(line3, &coord_x, &coord_y);

	// char	line3[30] = "error -21 3";
	// nom = li_get_room(line3, &coord_x, &coord_y);

	// char	line4[30] = "21 3";
	// nom = li_get_room(line4, &coord_x, &coord_y);

	// char	line6[30] = "21 3 4 3 osa oasjqh 9";
	// nom = li_get_room(line6, &coord_x, &coord_y);


}

ALL_TESTS
{
	MY_TEST("get_ants_nb", get_ants_nb)
	MY_TEST("errorempty", errorempty)
	MY_TEST("get_room", get_room)
}

RUN_TEST
