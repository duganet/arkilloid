#!/bin/bash

for arg in "$@"; do
	case "$arg" in
	'--debug' | '-d' | 'debug')
		CMAKE_RUN_FLAGS="${CMAKE_RUN_FLAGS} -DDEBUG=1"
		;;
	'--win32' | '--windows' | 'win32' | 'windows')
		CMAKE_RUN_FLAGS="${CMAKE_RUN_FLAGS} \
		-DCMAKE_TOOLCHAIN_FILE=~/dev/Toolchain-mingw32.cmake \
		-DCMAKE_INSTALL_PREFIX=/home/mcdebugger/dev/mingw32-install/setup \
		-DSDL_INCLUDE_DIR=/home/mcdebugger/dev/i686-mingw32/include/SDL/"
		;;
	*)
		echo 'Default settings:'
		echo 'DEBUG OFF'
		echo 'WIN32 OFF'
		;;
	esac
done

if [ ! -f "extern/glftfont/GLFT_Font.cpp" ]; then
	echo -n 'Initializing and updating required git submodules... '
	git submodule init > /dev/null 2>&1
	git submodule update > /dev/null 2>&1
	echo '[OK]'
fi

if [ ! -d "build" ]; then
	mkdir build
fi

cd build
cmake ${CMAKE_RUN_FLAGS} ..
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
