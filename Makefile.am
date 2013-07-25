#
SUBDIRS = lib cpp 
#
include_HEADERS = mat2cpp.hpp mztuni.hpp
#
EXTRA_DIST = \
	build.sh \
	run_omhelp.sh \
	mat2cpp.omh \
	doc \
	omh \
	mat
#
dist-hook:
	rm -rf `find $(distdir) -name .svn`
