#!/bin/sh

# Checking if the program exist. If not: do make.
if [ ! -f ./lem_in ];
then
	make
fi

# Ask the user which test to launch.
while true; do
	echo "\033[34;1mChoose a test: 1, 2, 1000 or q to quit.\033[0m"
	read tests
	case $tests in
		"1" )		./lem_in < test_1.map ;;
		"2" )		./lem_in < test_2.map ;;
		"1000" )	./lem_in < test_1000.map ;;
		"q" )		exit ;;
	esac
done
