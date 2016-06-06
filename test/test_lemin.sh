#!/bin/sh

# Checking if the program exist. If not: do make.
if [ ! -f ./lem_in ];
then
	make
fi

# Ask the user which test to launch.
while true; do
	echo "\033[34;1mChoose a test: 1, 2, 1000, errors or q to quit.\033[0m"
	read tests
	case $tests in
		"1" )		./lem_in < test/test_1.map ;;
		"2" )		./lem_in < test/test_2.map ;;
		"1000" )	./lem_in < test/test_1000.map ;;
		"errors" )	./lem_in < test/test_err1.map
					./lem_in < test/test_err2.map
					./lem_in < test/test_err3.map
					./lem_in < test/test_err4.map ;;
		"q" )		exit ;;
	esac
done
