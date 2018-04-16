ACLOCAL_AMFLAGS = -I m4
sbin_PROGRAMS = main

main_SOURCES = main.cpp foo.cpp baz.cpp
main_LDFLAGS = $(LIBSYSTEMD_LIBS)
main_CFLAGS = $(LIBSYSTEMD_CFLAGS)

check_PROGRAMS =
XFAIL_TESTS =

include test/Makefile.am.include

TESTS = $(check_PROGRAMS)
