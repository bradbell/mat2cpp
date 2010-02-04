#!/bin/bash 
# ----------------------------------------------------------------
boost_dir=/usr/include # location of boost directory on this machine
prefix=/usr/local      # prefix for installation
# ----------------------------------------------------------------
#
Today=`date +%F | sed -e 's|-||g'`
#
if [ "$1" == "-g" ]
then
        echo "Building Debug Version:"
        compile_flags="-g -Wall"
else
        echo "Building Optimized Version:"
        compile_flags="-DNDEBUG -O2 -Wall"
fi
set -ue
#
for name in \
	NEWS \
	README \
	AUTHORS \
	ChangeLog 
do
	if [ ! -e $name ]
	then
		echo "no $name file in mat2cpp distribution"  > $name
	fi
done
#
sed -i configure.ac \
	-e "s|AC_INIT(mat2cpp, [0-9]\{8\},|AC_INIT(mat2cpp, $Today,|"
#
sed -i mat2cpp.omh \
	-e "s|mat2cpp-[0-9]\{8\}|mat2cpp-$Today|"
#
echo "autoreconf --force --install"
autoreconf --force --install
#
./configure  \
	--prefix=$prefix \
	BOOST_DIR=$boost_dir \
	COMPILE_FLAGS="$compile_flags"
#
echo "make"
make 
#
echo "./RunOMhelp"
./RunOMhelp
#
echo "make dist"
make dist
#
if [ -e "mat2cpp-$Today" ]
then
	rm mat2cpp-$Today
fi
echo "tar -xvzf mat2cpp-$Today.tar.gz"
tar -xvzf mat2cpp-$Today.tar.gz
cd mat2cpp-$Today
#
./configure  \
	--prefix=$prefix \
	BOOST_DIR=$boost_dir \
	COMPILE_FLAGS="$compile_flags"
make
cpp/mat2cpp_ok
