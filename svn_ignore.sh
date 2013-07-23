#! /bin/bash -e
# -----------------------------------------------------------------------------
cat << EOF > ./svn_ignore.$$
aclocal.m4
autom4te.cache
doc
config.h
config.status
configure
getstarted
getstarted.out
mat2cpp_ok
depcomp
.deps
INSTALL
install-sh
*.in
junk
junk.*
*.log
mat2cpp-[0-9]*
Makefile
missing
new
stamp-h1
svn_commit.*
temp
temp.sh
*.tgz
*.gz
EOF
svn propset svn:ignore --recursive -F ./svn_ignore.$$ .
rm ./svn_ignore.$$
#
echo 'svn_ignore.sh: OK'
exit 0 
