#!/bin/sh

#
# This is a shell script in order to test your lem_in program.
#

test_errors()
{
	for i in {1..17}
	do
		printf "\033[34;1m./lem_in < test/test_err%d.map\n\033[0m" $i
		./lem_in < test/test_err$i.map
		echo '-----'
	done
}

test_valid()
{
	for i in {1..6}
	do
		printf "\033[34;1m./lem_in < test/test_%d.map\n\033[0m" $i
		./lem_in < test/test_$i.map
		echo '-----'
	done
}

# Checking if the program exist. If not: do make.
if [ ! -f ./lem_in ];
then
	make
fi

# Ask the user which test to launch.
while true; do
	echo "\033[34;1mChoose a test: 1, 2, ... 6, all, 1000, err or q to quit.\033[0m"
	read tests
	case $tests in
		"1" )		./lem_in < test/test_1.map ;;
		"2" )		./lem_in < test/test_2.map ;;
		"3" )		./lem_in < test/test_3.map ;;
		"4" )		./lem_in < test/test_4.map ;;
		"5" )		./lem_in < test/test_5.map ;;
		"6" )		./lem_in < test/test_6.map ;;
		"all" )		test_valid ;;
		"1000" )	./lem_in < test/test_1000.map ;;
		"err" )		test_errors ;;
		"q" )		exit ;;
	esac
done
