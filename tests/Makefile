#Makefile for folder tests/*

TARGET = search_multiset

CFLAGS = -g -std=c++20

$(TARGET): $(TARGET).cpp 
	g++ $(CFLAGS) $(TARGET).cpp  -o ../bin/$(TARGET)
	
phony: run gdb

run:
	../bin/$(TARGET)
	
gdb:
	/usr/bin/gdb ../bin/$(TARGET)
