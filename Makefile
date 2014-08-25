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
SRC_URL ?= "https://github.com/7890/shout"
MAINTAINER ?= "Thomas Brand \<tom@trellis.ch\>"
LICENSE ?= "GPL2"
VERSION ?= 0
RELEASE ?= 9

#REQUIRES ?= "libc6 (>= 2.14)"
REQUIRES ?= "libc6"

#gcc -c digits.c -o digits.o -std=gnu99;
#gcc -c shout.c -o shout.o -std=gnu99;
#gcc shout.o digits.o -o shout

#note: lintian to test created packages

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

prepare_checkinstall:
	mkdir -p doc-pak
	chmod 0755 doc-pak
	cp README.md doc-pak
	cp COPYING doc-pak/copyright
	cp doc/changelog.Debian.gz doc-pak
	chmod 0644 doc-pak/README.md
	chmod 0644 doc-pak/copyright
	chmod 0644 doc-pak/changelog.Debian.gz

	mkdir -p doc-pak/doc
	chmod 0755 doc-pak/doc
	cp doc/shout.man.asciidoc doc-pak/doc
	cp doc/shout.1.gz doc-pak/doc
	chmod 0644 doc-pak/doc/shout.man.asciidoc
	chmod 0644 doc-pak/doc/shout.1.gz

	echo "Print large characters in terminal" > description-pak
	echo "Print large pixel-style characters with custom colors in terminal" >> description-pak

	@echo "done."
	@echo "next: sudo make deb64"

deb64: 
	checkinstall -D --exclude="/home/*" --arch=amd64 --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="text" --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: lintian <created package>"

deb32: 
	checkinstall -D --exclude="/home/*" --arch=i386 --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="text" --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: lintian <created package>"

debarmhf: 
	checkinstall -D --exclude="/home/*" --arch=armhf --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="text" --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: lintian <created package>"

install: $(PROGNAME)
	mkdir -p $(DESTDIR)$(INSTALLDIR)/
	mkdir -p $(DESTDIR)$(MANDIR)/
	install -m755 $(PROGNAME) $(DESTDIR)$(INSTALLDIR)/
	install -m644 $(DOC)/$(PROGNAME).1.gz $(DESTDIR)$(MANDIR)/

uninstall:
	rm -f $(DESTDIR)$(INSTALLDIR)/$(PROGNAME)
	rm -f $(DESTDIR)$(MANDIR)/$(PROGNAME).1.gz
	-rmdir $(DESTDIR)$(INSTALLDIR)
	-rmdir $(DESTDIR)$(MANDIR)

clean:
	rm -f $(PROGNAME) $(SRC)/$(PROGNAME).o $(SRC)/digits.o 
	rm -rf doc-pak
	rm -f description-pak

.PHONY: clean all chars install uninstall
