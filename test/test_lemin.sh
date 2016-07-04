#!/bin/sh

#
# This is a shell script in order to test your lem-in program.
#

test_errors1()
{
	for i in {1..24}
	do
		printf "\033[34;1m./lem-in < test/test_err%d.map\n\033[0m" $i
		./lem-in < test/test_err$i.map
		echo '-----'
	done
}

test_errors2()
{
	for i in {25..48}
	do
		printf "\033[34;1m./lem-in < test/test_err%d.map\n\033[0m" $i
		./lem-in < test/test_err$i.map
		echo '-----'
	done
}

test_valid1()
{
	for i in {1..15}
	do
		printf "\033[34;1m./lem-in < test/test_%d.map\n\033[0m" $i
		./lem-in < test/test_$i.map
		echo '-----'
	done
}

test_valid2()
{
	for i in {16..30}
	do
		printf "\033[34;1m./lem-in < test/test_%d.map\n\033[0m" $i
		./lem-in < test/test_$i.map
		echo '-----'
	done
}

test_bonus()
{
	printf "\033[34;1m./lem-in -c < test/test_30.map\n\033[0m"
	./lem-in -c < test/test_30.map
	echo '-----'
	printf "\033[34;1m./lem-in -v < test/test_err2.map\n\033[0m"
	./lem-in -v < test/test_err2.map
	echo '-----'
	printf "\033[34;1m./lem-in -v < test/test_err7.map\n\033[0m"
	./lem-in -v < test/test_err7.map
	echo '-----'
}

# Checking if the program exist. If not: do make.
if [ ! -f ./lem-in ];
then
	make
fi

# Ask the user which test to launch.
while true; do
	echo "\033[34;1mChoose a test:\n
		[1]\tValids from 1 to 15\n
		[2]\tValids from 16 to 30\n
		[3]\tErrors from 1 to 24\n
		[4]\tErrors from 25 to 48\n
		[5-i]\tBig with i from 1 to 5\n
		[b]\tSee bonuses\n
		[q]\tQuit\n
		\033[0m"
	read tests
	case $tests in
		"1" )		test_valid1 ;;
		"2" )		test_valid2 ;;
		"3" )		test_errors1 ;;
		"4" )		test_errors2 ;;
		"5-1" )		./lem-in < test/test_big1.map ;;
		"5-2" )		./lem-in < test/test_big2.map ;;
		"5-3" )		./lem-in < test/test_big3.map ;;
		"5-4" )		./lem-in < test/test_big4.map ;;
		"5-5" )		./lem-in < test/test_big5.map ;;
		"b" )		test_bonus ;;
		"q" )		exit ;;
	esac
done
