#Makefile for folder tests/*

TARGET = classBaseN

AUX=classPrime

CFLAGS = -g

$(TARGET): $(TARGET).cpp $(AUX).cpp
	g++ $(CFLAGS) $(TARGET).cpp $(AUX).cpp -o ../bin/$(TARGET)
	
phony: run gdb

run:
	../bin/$(TARGET)
	
gdb:
	/usr/bin/gdb ../bin/$(TARGET)
