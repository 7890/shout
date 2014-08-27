CC ?= gcc
CFLAGS ?= -Wall -std=c99
PREFIX ?= /usr/local
PREFIX_PACKAGES ?= /usr
INSTALLDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man/man1
PROGNAME ?= shout

SRC=src
DOC=doc
DIST=dist

#.deb package
SRC_URL ?= "https://github.com/7890/shout"
MAINTAINER ?= "Thomas Brand \<tom@trellis.ch\>"
LICENSE ?= "GPL2"
VERSION ?= 0
RELEASE ?= 9
RELEASE_DATE ?= 140826
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
	chmod 0644 doc-pak/README.md
	chmod 0644 doc-pak/copyright

	mkdir -p doc-pak/doc
	chmod 0755 doc-pak/doc
	cp doc/shout.man.asciidoc doc-pak/doc
	chmod 0644 doc-pak/doc/shout.man.asciidoc

	echo "Print large characters in terminal" > description-pak
	echo "Print large pixel-style characters with custom colors in terminal" >> description-pak

	@echo "done."
	@echo "next: sudo make deb64"

deb64: 
	rm -f doc-pak/changelog.Debian.gz
	cp $(DOC)/changelog.Debian.amd64 doc-pak/changelog.Debian
	gzip -9 doc-pak/changelog.Debian	
	chmod 0644 doc-pak/changelog.Debian.gz

	checkinstall -D --exclude="/home/*" --arch=amd64 --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="text" --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: lintian <created package>"

deb64_dist:
	mkdir -p $(DIST)
	mv $(PROGNAME)_$(VERSION)-$(RELEASE)_amd64.deb  $(DIST)/$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_amd64.deb
	$(DIST)/create_report.sh $(DIST)/$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_amd64.deb > $(DIST)/$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_amd64.deb.txt 2>&1

deb32: 
	rm -f doc-pak/changelog.Debian.gz
	cp $(DOC)/changelog.Debian.i386 doc-pak/changelog.Debian
	gzip -9 doc-pak/changelog.Debian	
	chmod 0644 doc-pak/changelog.Debian.gz

	checkinstall -D --exclude="/home/*" --arch=i386 --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup="text" --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: lintian <created package>"

deb32_dist:
	mkdir -p $(DIST)
	mv $(PROGNAME)_$(VERSION)-$(RELEASE)_i386.deb  $(DIST)/$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_i386.deb
	$(DIST)/create_report.sh $(DIST)/$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_i386.deb > $(DIST)/$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_i386.deb.txt 2>&1

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
