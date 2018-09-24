#! /bin/bash -e
project_home_page='https://github.com/bradbell/mat2cpp'
if [ -e doc ]
then
	rm -r doc
fi
mkdir doc
cd doc
if ! omhelp ../doc.omh \
	-noframe -debug -image_link "$project_home_page"
then
	echo 'Aborting, see OMhelp error message in omhelp.log'
	exit 1
fi
if grep 'OMhelp Warning:' ../omhelp.log
then
	echo 'See the complete warning message in omhelp.log'
	exit 1
fi
