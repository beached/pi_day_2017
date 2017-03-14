#!/bin/bash

g++ -std=c++14 -march=native -O3 -fno-math-errno -fno-trapping-math -fno-signaling-nans -fno-rounding-math ./pi_day_2017.cpp

./a.out
