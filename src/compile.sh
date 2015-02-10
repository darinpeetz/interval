#!/bin/bash
rm *.o main 2>/dev/null
g++ -c interval.cpp
g++ -c main.cpp
g++ interval.o main.o -o main
