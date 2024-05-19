#Makefile for folder tests/*

#TARGET = search_multiset
#TARGET = classOutlier
#TARGET = solve_outliers
#TARGET = solve_list_outliers

TARGET = b3nfactors


CFLAGS = -g -std=c++23

$(TARGET): $(TARGET).cpp 
	g++ $(CFLAGS) $(TARGET).cpp  -o ../bin/$(TARGET)
	
phony: run gdb

run:
	../bin/$(TARGET)
	
gdb:
	/usr/bin/gdb ../bin/$(TARGET)
