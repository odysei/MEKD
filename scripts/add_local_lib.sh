#! /bin/bash

OS_TYPE=`uname`

# Linux lib path
if [ "${OS_TYPE}" == "Linux" ]; then
	export LD_LIBRARY_PATH=${PWD}/lib:${LD_LIBRARY_PATH}
	return
fi

# OSX, Darwin lib path
if [ "${OS_TYPE}" == "OSX" ]; then
	export DYLD_LIBRARY_PATH=${PWD}/lib:${DYLD_LIBRARY_PATH}
	return
elif [ "${OS_TYPE}" == "Darwin" ]; then
	export DYLD_LIBRARY_PATH=${PWD}/lib:${DYLD_LIBRARY_PATH}
	return
fi