#!/bin/bash

if [ ! -d "build" ]; then
	mkdir build
fi

cd build
cmake ../
make

echo ''
echo '***************************************************'
echo '*                                                 *'
echo '* Compile should be completed.                    *'
echo '*                                                 *'
echo '* Type `make install` or `sudo make install`      *'
echo '* from "build/" directory to install application. *'
echo '*                                                 *'
echo '***************************************************'
echo ''
