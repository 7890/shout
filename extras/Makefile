#!/usr/bin/make -f

CC ?= gcc
CFLAGS ?= -Wall -std=c99
PREFIX ?= /usr/local
INSTALLDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man/man1
PROGNAME ?= osctermd

LO_FLAGS ?= $(shell pkg-config --cflags --libs liblo)
#-I/usr/local/include  -L/usr/local/lib -llo -lpthread

SRC=src
DOC=doc

#osctermd needs liblo (http://liblo.sourceforge.net)
#on ubuntu: packages liblo7, liblo-dev, liblo-tools

#gcc -o osctermd osctermd.c `pkg-config --cflags --libs liblo`
###############################################################################

default: $(PROGNAME)
all: $(PROGNAME) manpage

$(PROGNAME): $(SRC)/$(PROGNAME).c
	$(CC) $(SRC)/$(PROGNAME).c -o $(PROGNAME) $(CFLAGS) $(LO_FLAGS)

manpage: $(DOC)/$(PROGNAME).man.asciidoc
	a2x --doctype manpage --format manpage $(DOC)/$(PROGNAME).man.asciidoc

install: $(PROGNAME)
	install -m755 $(PROGNAME) $(DESTDIR)$(INSTALLDIR)/
	install -m644 $(DOC)/$(PROGNAME).1 $(DESTDIR)$(MANDIR)/

uninstall:
	rm -f $(DESTDIR)$(INSTALLDIR)/$(PROGNAME)
	rm -f $(DESTDIR)$(MANDIR)/$(PROGNAME).1

clean:
	rm -f $(PROGNAME) 
	#$(DOC)/$(PROGNAME).1

.PHONY: clean all install uninstall
