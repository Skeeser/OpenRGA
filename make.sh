#!/bin/bash

cd build && cmake .. && make && sudo make install

cd ..

cd test/build/ && cmake .. && make

./OpenRGATest

