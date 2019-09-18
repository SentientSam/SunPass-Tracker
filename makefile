#
# partial makefile for DOT SunPass project
# to be completed by student
#

cflags = -I. -Wall -Wextra
#CC     = clang++ -std=c++11
CC     = g++ -std=c++11

AREA51  = /home/courses/cop3330p/LIB/area51

all:         clients benchmarks
clients:     stester.x vtester.x tracker.x
benchmarks:  stester_i.x vtester_i.x tracker_i.x 

# build executables

tracker.x: tracker.o shapes.o vehicles.o
	$(CC) -o tracker.x tracker.o shapes.o vehicles.o

stester.x: stester.o shapes.o
	$(CC) $(cflags) -o stester.x stester.o shapes.o

vtester.x: vehicles.o vtester.o shapes.o
	$(CC) $(cflags) -o vtester.x vtester.o vehicles.o shapes.o 


# build object code files

tracker.o: shapes.h vehicles.h tracker.cpp
	$(CC) $(cflags) -c tracker.cpp

stester.o:	shapes.h stester.cpp
	$(CC) $(cflags) -c stester.cpp shapes.h

vtester.o: vtester.cpp vehicles.h
	$(CC) $(cflags) -c vtester.cpp vehicles.h

shapes.o:	shapes.cpp shapes.h
	$(CC) $(cflags) -c shapes.cpp shapes.h

vehicles.o: vehicles.cpp vehicles.h
	$(CC) $(cflags)	-c vehicles.cpp vehicles.h



# build benchmarks

tracker_i.x: $(AREA51)/tracker_i.x
	cp   $(AREA51)/tracker_i.x .
	chmod 700 tracker_i.x

stester_i.x:



vtester_i.x:
