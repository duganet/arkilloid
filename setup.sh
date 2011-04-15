#!/bin/bash

if [ ! -d "build" ]; then
	mkdir build
fi

cd build
cmake ../
make

echo ''
echo '********************************************************************'
echo 'Compile should be completed.'
echo 'Type `make install` or `sudo make install` to install application.'
echo '********************************************************************'
echo ''
