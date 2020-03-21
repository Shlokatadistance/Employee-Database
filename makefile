#		ENGG1340 Computer Programming 2
#   Group Project [Employee Manaagement System]
#   Group Number: 27
#   Members:  Shandilya Eeshaanee (UID: 3035552234)
#             Sinha Shlok (UID: 3035554256)

#                                                      makefile
#    This is our make file in which we have made made us of the .cpp file, header files and generated object for the program execution.

Employee.o:Employee.h Employee.cpp
	g++ -c Employee.cpp

main.o:main.cpp Employee.h
	g++ -c main.cpp

main: main.o Employee.o
	g++ -pedantic-errors -std=c++11 Employee.o main.o -o main
