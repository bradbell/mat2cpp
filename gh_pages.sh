#! /bin/bash -e
# -----------------------------------------------------------------------------
if [ "$0" != './gh_pages.sh' ]
then
	echo './gh_pages.sh: must be run from top source directory'
	exit 1
fi
# -----------------------------------------------------------------------------
package='mat2cpp'
version=`grep '^AC_INIT(' configure.ac | \
	sed -e "s|AC_INIT( *$package *,||" -e 's|,.*||'`
tmp_doc='build/tmp/doc'
#
# build doc directory
echo "./run_omhelp.sh"
./run_omhelp.sh
#
# move doc to tmp_doc
if [ ! -e build/tmp ]
then
	mkdir -p build/tmp
fi
if [ -e $tmp_doc ]
then
	rm -r $tmp_doc
fi
mv doc $tmp_doc
#
# checkout gh-pages branch
echo "git checkout gh-pages"
git checkout gh-pages
#
# remove files that are no longer in doc directory
list=`ls -a doc`
for file in $list
do
	if [ ! -e "$tmp_doc/$file" ]
	then
		echo "git rm doc/$file"
		git rm doc/$file
	fi
done
#
# copy new version of files
list=`ls $tmp_doc`
for file in $list
do
	if [ ! -e doc/$file ]
	then
		echo "git add doc/$file"
	fi
	cp $tmp_doc/$file doc/$file
done
#
# stage all the changes
git add doc/*
# -----------------------------------------------------------------------------
list=`git status -s`
if [ "$list" != '' ]
then
	echo 'Currently in the gh-pages branch. The following will commit changes'
	echo "	git commit -m 'update gh-pages to version $version'"
fi
# -----------------------------------------------------------------------------
echo 'gh_pages.sh: OK'
exit 0
