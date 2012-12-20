#
# Makefile:
#	Library to utilise the 4D Systems Genie interface to displays
#	that have been created using the Visi-Genie creator platform.
#	Primarily aimed at the Raspberry Pi, however this may be used
#	on most Linux platforms with a serial connection (USB on
#	on-board) to the 4D Systems Intelligent displays.
#
#	Gordon Henderson, December 2012, <projects@drogon.net>
#	Copyright (c) 2012 4D Systems PTY Ltd, Sydney, Australia
#######################################################################
# This file is part of geniePi:
#    geniePi is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as
#    published by the Free Software Foundation, either version 3 of the
#    License, or (at your option) any later version.
#
#    geniePi is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public
#    License along with geniePi.
#    If not, see <http://www.gnu.org/licenses/>.
#######################################################################

DESTDIR=/usr
PREFIX=/local

STATIC=libgeniePi.a
DYNAMIC=libgeniePi.so

#DEBUG	= -g -O0
DEBUG	= -O2
CC	= gcc
INCLUDE	= -I.
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

#LIBS    = -lpthread

SRC	=	geniePi.c

# May not need to  alter anything below this line
###############################################################################

OBJ	=	$(SRC:.c=.o)

#all:	$(STATIC)
all:	$(DYNAMIC)

$(STATIC):	$(OBJ)
	@echo "[Link (Static)]"
	@ar rcs $(STATIC) $(OBJ)
	@ranlib $(STATIC)
#	@size   $(STATIC)

$(DYNAMIC):     $(OBJ)
	@echo "[Link (Dynamic)]"
	@$(CC) -shared -Wl,-soname,libgeniePi.so -o libgeniePi.so -lpthread $(OBJ)

.c.o:
	@echo [Compile] $<
	@$(CC) -c $(CFLAGS) $< -o $@

.PHONEY:	clean
clean:
	rm -f $(OBJ) *~ core tags *.bak Makefile.bak libgeniePi.*

.PHONEY:	tags
tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

.PHONEY:	depend
depend:
	makedepend -Y $(SRC)

.PHONEY:	install
install:	$(TARGET)
	@echo "[Install]"
	@install -m 0755 -d            $(DESTDIR)$(PREFIX)/lib
	@install -m 0755 -d            $(DESTDIR)$(PREFIX)/include
	@install -m 0644 geniePi.h     $(DESTDIR)$(PREFIX)/include
#	@install -m 0755 libgeniePi.a  $(DESTDIR)$(PREFIX)/lib
	@install -m 0755 libgeniePi.so $(DESTDIR)$(PREFIX)/lib

.PHONEY:	uninstall
uninstall:
	@echo "[Un-Install]"
	@rm -f	$(DESTDIR)$(PREFIX)/include/geniePi.h
	@rm -f	$(DESTDIR)$(PREFIX)/lib/libgeniePi.*

# DO NOT DELETE

geniePi.o: geniePi.h
