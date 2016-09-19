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
OTHER_ARG_afn =

CC = gcc
CPP = g++

CFLAGS = -Iinclude -O -Wall -g
CFLAGS_fn = -Iinclude -O -Wall -g -c
# !debugging:
# See GNUmakfile in parent dir for explanation of options.
#CFLAGS = -Iinclude -O -Wall -ansi -pedantic

# -----------------------------------------------------------------------------
# - Targets, prerequisites and their build rules
# ----------------------------------------------
motorControlClient: motorControlClient.cpp xfer2as.o
	${CPP} ${CFLAGS} motorControlClient.cpp xfer2as.o -o motorControlClient

tcpipSocketClient: tcpipSocketClient.cpp
	${CPP} ${CFLAGS} tcpipSocketClient.cpp ${OTHER_ARG} -o tcpipSocketClient

xfer2as.o: xfer2as.cpp
	${CPP} ${CFLAGS_fn} ${OTHER_ARG_afn} xfer2as.cpp

#include debug_targets

# -----------------------------------------------------------------------------
# - misc commands
# --------------
clean:
	\rm motorControlClient.cpp

clean1:
	\rm tcpipSocketClient

cleanobj:
	\rm xfer2as.o
