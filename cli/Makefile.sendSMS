#
# writeSerialPort -> usb modem
#

# -----------------------------------------------------------------------------
# - Define macros
# ---------------
SHELL = /bin/csh

OTHER_ARG =
OTHER_ARG_afn =

#CC = gcc
CPP = g++

CFLAGS = -Iinclude -O -Wall -g
CFLAGS_fn = -Iinclude -O -Wall -g -c
# !debugging:
# CFLAGS_fn = -Iinclude -O -Wall -ansi -pedantic -c

#  include debug_macros

# -----------------------------------------------------------------------------
# - Targets, prerequisites and their build rules
# ----------------------------------------------
writeSerialPort: writeSerialPort.cpp
	${CC} ${CFLAGS} writeSerialPort.cpp -o writeSerialPort

#  include debug_targets

# -----------------------------------------------------------------------------
# - misc commands
# ---------------
clean:
	\rm writeSerialPort
