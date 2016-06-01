#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define DEBUG 1

int		test_run = 0;

#define MY_TEST(name, ft) printf("%-15s -- ", name); ft(); printf("\n");

#define MY_UNIT_TEST(name) void name()

#define ALL_TESTS void run_all_tests(void)

#define RUN_TEST	int main()\
					{\
						setbuf(stdout, NULL);\
						run_all_tests();\
						fprintf(stdout, "\nTESTS RUN: %d\n", test_run);\
						return (0);\
					}\

#define UT_ASS(msg, test) test_run++; do { if (!(test)) printf("%s", msg); else printf("."); } while (0);

/*
** The file should be as follow:
**
** void	test_ft_test()
** {
** 		check(ft_test(sthing) == "sthing");
** }
**
** int		main(void)
** {
** 		MY_TEST("name of your function", test_ft_test);
** 		fprintf(stdout, "%d / %d tests.\n", g_tests_success, g_tests_attempt);
** 		return (0);
** }
*/
