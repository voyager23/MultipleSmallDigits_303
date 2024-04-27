#Makefile for folder tests/*

TARGET = classBaseN

CFLAGS = -g

$(TARGET): $(TARGET).cpp
	g++ $(CFLAGS) $(TARGET).cpp -o ../bin/$(TARGET)
	
phony: run gdb

run:
	../bin/$(TARGET)
	
gdb:
	/usr/bin/gdb ../bin/$(TARGET)
