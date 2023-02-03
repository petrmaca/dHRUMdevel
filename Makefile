# Author: Petr Maca \
Last revision: Feb 2 2023 \
TODO: replace with pattern rules; mkdir for folders 


TARGET = bin/dHRUMdevel
CC = g++ 	# compiler
CPPFLAGS = -std=c++14 -Wall -pedantic -Iinclude -fopenmp # bad code warnings and include header folder
OBJ = obj/data_HB_1d.o obj/main.o obj/params.o obj/single_HMunit.o obj/dHRUM.o# TODO
LDFLAGS := -Llib 
#LDFLAGS := -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib

.PHONY: all clean

all: $(TARGET)

obj/main.o: src/main.cpp
	$(CC) -c $< -o obj/main.o $(CPPFLAGS)

obj/data_HB_1d.o: src/data_HB_1d.cpp
	$(CC) -c $< -o obj/data_HB_1d.o $(CPPFLAGS)

obj/params.o: src/params.cpp
	$(CC) -c $< -o obj/params.o $(CPPFLAGS)

obj/single_HMunit.o: src/single_HMunit.cpp
	$(CC) -c $< -o obj/single_HMunit.o $(CPPFLAGS)	

obj/Parameters.o: src/Parameters.cpp
	$(CC) -c $< -o obj/Parameters.o $(CPPFLAGS)		

obj/dHRUM.o: src/dHRUM.cpp
	$(CC) -c $< -o obj/dHRUM.o $(CPPFLAGS)		

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean:
	rm -r -f -v obj/*
	rm -f -v $(TARGET)
