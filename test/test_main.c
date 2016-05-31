#include "test.h"
#include "../inc/lem_in.h"

MY_UNIT_TEST(parsing_name)
{
	char	str[3][8] = {
		"nom1 2 3",
		"nom2 3 4",
		"nom3 4 5" };
}

void		main()
{
	MY_TEST(parsing name, parsing_name)
	fprintf(stdout, "%d / %d tests.\n", g_tests_success, g_tests_attempt);
	return (0);
}
