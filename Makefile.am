#
SUBDIRS = lib cpp
#
include_HEADERS = mat2cpp.hpp mztuni.hpp
#
EXTRA_DIST = \
	build.sh \
	run_omhelp.sh \
	doc.omh \
	doc \
	omh \
	mat
#
dist-hook:
	rm -rf $(distdir)/.git
