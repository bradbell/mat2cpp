#
SUBDIRS = lib cpp 
#
include_HEADERS = mat2cpp.hpp
#
EXTRA_DIST = \
	Build \
	RunOMhelp \
	mat2cpp.omh \
	doc \
	omh \
	mat
#
dist-hook:
	rm -rf `find $(distdir) -name *.scc`
