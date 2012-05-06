#! /bin/bash -e
# ----------------------------------------------------------------
boost_dir=/usr/include        # prefix for boost on this machine
prefix=$HOME/prefix/mat2cpp   # prefix for installation
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
cat << EOF
./configure  \
	--prefix=$prefix \
	BOOST_DIR=$boost_dir \
	COMPILE_FLAGS="$compile_flags"
EOF
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
#
echo "cp mat2cpp-$Today.tar.gz doc/mat2cpp-$Today.tar.gz"
cp mat2cpp-$Today.tar.gz doc/mat2cpp-$Today.tar.gz
#
echo "tar -xvzf mat2cpp-$Today.tar.gz"
tar -xvzf mat2cpp-$Today.tar.gz
#
cd mat2cpp-$Today
#
cat << EOF
./configure  \\
	--prefix=$prefix \\
	BOOST_DIR=$boost_dir \\
	COMPILE_FLAGS="$compile_flags"
EOF
#
./configure  \
	--prefix=$prefix \
	BOOST_DIR=$boost_dir \
	COMPILE_FLAGS="$compile_flags"
#
echo "make"
make
#
echo "cpp/mat2cpp_ok"
cpp/mat2cpp_ok
#
echo "cd .."
cd ..
#
if [ "$USER" != "bradbell" ]
then
	echo "Only Brad Bell can copy a new version to the internet."
	exit 1
fi
file=doc/mat2cpp-$Today.tar.gz
remote_machine='moby'
remote_directory='/var/www.html/bradbell'
if [ ! -e "$file" ]
then
	echo "The file $file is missing"
	exit 1
fi
echo "tar -czf doc.tgz doc"
tar -czf doc.tgz doc
#
echo "ssh.sh $remote_machine -p doc.tgz"
ssh.sh $remote_machine -p doc.tgz
#
cat << EOF
------------------------------
Enter the following commands: 
	ssh.sh $remote_machine -l
	rm -rf doc
	tar -xzf doc.tgz
	rm -r $remote_directory/mat2cpp
	cp -r doc $remote_directory/mat2cpp
	exit
------------------------------
EOF
echo "build.sh: mat2cpp OK"
exit 0
