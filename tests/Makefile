#Makefile for folder tests/*

TARGET = classBaseN

AUX=classPrime

CFLAGS = -g

$(TARGET): $(TARGET).cpp
	g++ $(CFLAGS) $(TARGET).cpp -o ../bin/$(TARGET)

classPrime.o : classPrime.cpp
	g++ $(CFLAGS) -c classPrime.cpp
	
phony: run gdb

run:
	../bin/$(TARGET)
	
gdb:
	/usr/bin/gdb ../bin/$(TARGET)
