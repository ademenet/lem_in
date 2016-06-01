#!/bin/sh

# Checking if the program exist. If not: do make.
if [ ! -f ./lem_in ];
then
	make
fi

# Ask the user which test to launch.
echo "\033[34;1mWhich test would you like to launch ? 1000 or... q to quit.\033[0m"
while true; do
	read tests
	case $tests in
		"1000" )	./lem_in < test_1000.map ;;
		"q" )		exit ;;
		* )			echo "\033[34;1mPlease tell me which test you wan't: 1000, or... q to quit.\033[0m" ;;
	esac
done
