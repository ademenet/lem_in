#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

static int g_tests_attempt = 0;
static int g_tests_success = 0;

#define MY_TEST(name, ft)	fprintf(stdout, "\033[0m%s -- \033[0m", name); ft();\
							puts("\n");

#define MY_UNIT_TEST(name) void name()

#define check_int_eq(std, own)	if(std ==  own)\
								{ puts("\033[32mo\033[32m");\
								g_tests_success++;
								g_tests_attempt++; }\
								else { puts("\033[31mx\033[31m");\
								g_tests_attempt++; }\

#define check_str_eq(std, own)	if(strcmp(std, own) == 0)\
								{ puts("\033[32mo\033[32m");\
								g_tests_success++;
								g_tests_attempt++; }\
								else { puts("\033[31mx\033[31m");\
								g_tests_attempt++; }\

#define check(cond)	if(cond)\
					{puts("\033[32mo\033[32m");\
					g_tests_success++;
					g_tests_attempt++; }\
					else {puts("\033[31mx\033[31m");\
					g_tests_attempt++; }\



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
