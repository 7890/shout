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
RELEASE ?= 96
RELEASE_DATE ?= 140827
#REQUIRES ?= "libc6 (>= 2.14)"
REQUIRES ?= "libc6"
PKG_GROUP ?= "text"

ARCH ?= "i386"
#ARCH ?= "amd64"
#ARCH ?= "armhf"

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
	rm -f $(PROGNAME)*.deb
	rm -f $(PROGNAME)*.deb.txt
	rm -rf doc-pak
	rm -f description-pak

prepare_checkinstall:
	mkdir -p doc-pak
	chmod 0755 doc-pak
	cp README.md doc-pak
	cp COPYING doc-pak/copyright

	chmod 0644 doc-pak/README.md
	chmod 0644 doc-pak/copyright

	mkdir -p doc-pak/doc
	chmod 0755 doc-pak/doc

	cp $(DOC)/shout.man.asciidoc doc-pak/doc
	cp $(DOC)/description-pak .
	
	chmod 0644 doc-pak/doc/shout.man.asciidoc

	@echo "done."
	@echo "next: sudo make deb ARCH=i386|amd64|armhf"

#set ARCH to i386, amd64 or armhf
deb: 
	rm -f doc-pak/changelog.Debian.gz
	cp $(DOC)/changelog.Debian.$(ARCH) doc-pak/changelog.Debian
	gzip -9 doc-pak/changelog.Debian	
	chmod 0644 doc-pak/changelog.Debian.gz

	checkinstall -D --exclude="/home/*" --arch=$(ARCH) --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup=$(PKG_GROUP) --backup=no --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: make deb_dist ARCH=i386|amd64|armhf"

deb_dist:
	@echo "doing lintian check of deb, installation test, creating report..."

	mkdir -p $(DIST)
	mv $(PROGNAME)_$(VERSION)-$(RELEASE)_$(ARCH).deb  $(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_$(ARCH).deb
	$(DIST)/create_report.sh $(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_$(ARCH).deb > $(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_$(ARCH).deb.txt 2>&1

	@echo "done."
	@echo ""
	cat $(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_$(ARCH).deb.txt
	@echo ""
	@echo "files created:"
	@echo "$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_$(ARCH).deb"
	@echo "$(PROGNAME)_$(RELEASE_DATE)_$(VERSION)-$(RELEASE)_$(ARCH).deb.txt"
	@echo ""
	@echo "if package is ok to release, move to $(DIST) and add to repository"

.PHONY: clean all chars install uninstall prepare_checkinstall deb deb_dist
