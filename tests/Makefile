#Makefile for folder tests/*

TARGET = classOutlier

CFLAGS = -g -std=c++17

$(TARGET): $(TARGET).hpp 
	g++ $(CFLAGS) $(TARGET).hpp  -o ../bin/$(TARGET)
	
phony: run gdb

run:
	../bin/$(TARGET)
	
gdb:
	/usr/bin/gdb ../bin/$(TARGET)
