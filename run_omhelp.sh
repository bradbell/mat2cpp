#! /bin/bash -e
brad_home_page="http://www.seanet.com/~bradbell/home.htm"
if [ -e doc ]
then
	rm -r doc
fi
mkdir doc
cd doc
if ! omhelp ../mat2cpp.omh \
	-xml -noframe -debug -image_link "$brad_home_page" > ../omhelp.log
then
	echo 'Aborting, see OMhelp error message in omhelp.log'
	exit 1
fi
if grep 'OMhelp Warning:' ../omhelp.log
then
	echo 'See the complete warning message in omhelp.log'
	exit 1
fi
omhelp ../mat2cpp.omh -noframe -debug -image_link "$brad_home_page"
