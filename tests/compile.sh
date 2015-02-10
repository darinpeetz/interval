#!/bin/bash
rm *.o 2> /dev/null
g++ -c interval-test.cpp
g++ ../src/interval.o interval-test.o -o interval-test

