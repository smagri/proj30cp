# note: look at specific module, fn, app makefiles for more guidence but
# this is the basic template
#
# PROJECT NAME gmake description file
#

# -----------------------------------------------------------------------------
# - Define macros
# ---------------
SHELL = /bin/csh

APROG = main

##include debug_info

OTHER_ARG =
OTHER_ARG_aprog =

CC = gcc
CPP = g++

CFLAGS = -Iinclude -O -Wall -g -ansi -pedantic
CFLAGS_fn = -Iinclude -O -Wall -ansi -pedantic -g -c 
# !debugging:
# See GNUmakfile in parent dir for explanation of options.
#CFLAGS = -Iinclude -O -Wall -ansi -pedantic

# -----------------------------------------------------------------------------
# - Targets, prerequisites and their build rules
# ----------------------------------------------
#ass1: main.cpp time.o
#	${CPP} ${CFLAGS} main.cpp ${OTHER_ARG} time.o -o ass1
listing1: listing1.cpp
	${CPP} ${CFLAGS} listing1.cpp ${OTHER_ARG} -o listing1

#time.o: time.cpp
#	${CPP} ${CFLAGS_fn} ${OTHER_ARG_afn} time.cpp

#include debug_targets

# -----------------------------------------------------------------------------
# - misc commands
# ---------------
clean:
	\rm listing1
