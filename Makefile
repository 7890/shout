#!/usr/bin/make -f

CC ?= gcc
CFLAGS ?= -Wall -std=c99
PREFIX ?= /usr/local
PREFIX_PACKAGES ?= /usr
INSTALLDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man/man1
PROGNAME ?= shout

SRC=src
DOC=doc

#.deb package
SRC_URL="https://github.com/7890/shout"
MAINTAINER="tom@trellis.ch"
LICENSE="GPL"
VERSION ?= 0
RELEASE ?= 9

#gcc -c digits.c -o digits.o -std=gnu99;
#gcc -c shout.c -o shout.o -std=gnu99;
#gcc shout.o digits.o -o shout
###############################################################################

default: $(PROGNAME)
all: $(PROGNAME) manpage

chars:
	cd $(SRC)/chars && ./generate_all.sh

digits.o: $(SRC)/digits.c
	$(CC) -c $(SRC)/digits.c -o $(SRC)/digits.o $(CFLAGS)

$(PROGNAME).o: $(SRC)/$(PROGNAME).c
	$(CC) -c $(SRC)/$(PROGNAME).c -o $(SRC)/$(PROGNAME).o $(CFLAGS)

$(PROGNAME): $(SRC)/digits.o $(SRC)/$(PROGNAME).o
	$(CC) $(SRC)/digits.o $(SRC)/$(PROGNAME).o -o $(PROGNAME) $(CFLAGS)

manpage: $(DOC)/$(PROGNAME).man.asciidoc
	a2x --doctype manpage --format manpage $(DOC)/$(PROGNAME).man.asciidoc
	gzip -9 -f $(DOC)/$(PROGNAME).1

deb64: 
	checkinstall -D --exclude="/home/*" --arch=amd64 --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="shellutils" --install=no make install PREFIX=$(PREFIX_PACKAGES)
deb32: 
	checkinstall -D --exclude="/home/*" --arch=i386 --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="shellutils" --install=no make install PREFIX=$(PREFIX_PACKAGES)
debarmhf: 
	checkinstall -D --exclude="/home/*" --arch=armhf --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="shellutils" --install=no make install PREFIX=$(PREFIX_PACKAGES)

install: $(PROGNAME)
	mkdir -p $(DESTDIR)$(INSTALLDIR)/
	mkdir -p $(DESTDIR)$(MANDIR)/
	install -m755 $(PROGNAME) $(DESTDIR)$(INSTALLDIR)/
	install -m644 $(DOC)/$(PROGNAME).1.gz $(DESTDIR)$(MANDIR)/

uninstall:
	rm -f $(DESTDIR)$(INSTALLDIR)/$(PROGNAME)
	rm -f $(DESTDIR)$(MANDIR)/$(PROGNAME).1.gz

clean:
	rm -f $(PROGNAME) $(SRC)/$(PROGNAME).o $(SRC)/digits.o 
	#$(DOC)/$(PROGNAME).1.gz

.PHONY: clean all chars install uninstall
