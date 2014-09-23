CC ?= gcc
CFLAGS ?= -Wall
#-std=c99
PREFIX ?= /usr/local
PREFIX_PACKAGES ?= /usr
INSTALLDIR ?= $(PREFIX)/bin
MANDIR ?= $(PREFIX)/share/man/man1
PROGNAME ?= shout

#cshout
#ushout

SRC=src
DOC=doc
DIST=dist

BUILD=build
FONTS=fonts

#.deb package
SRC_URL ?= "https://github.com/7890/shout"
MAINTAINER ?= "Thomas Brand \<tom@trellis.ch\>"
LICENSE ?= "GPL2"
VERSION ?= 0
RELEASE ?= 98
RELEASE_DATE ?= 140923
#REQUIRES ?= "libc6 (>= 2.14)"
REQUIRES ?= "libc6"
PKG_GROUP ?= "text"

ARCH ?= "i386"
#ARCH ?= "amd64"
#ARCH ?= "armhf"

#gcc -Wall -c -o utf8.o utf8.c 
#gcc -Wall -c -o font.o font.c 
#gcc -Wall -c -o ushout.o ushout.c 
#gcc -Wall -o ushout ushout.o utf8.o font.o

#note: lintian to test created packages

###############################################################################

#https://www.gnu.org/software/make/manual/html_node/Parallel.html
#You can inhibit parallelism in a particular makefile with the .NOTPARALLEL pseudo-target
.NOTPARALLEL:

all: cshout ushout bdf2spf

default: all

$(SRC)/encoding_patterns.h.header:
$(SRC)/spfenc.c:
$(SRC)/font.c:
$(SRC)/font.h:
$(FONTS)/c64_extended.spf.gz:
$(FONTS)/nl_tab_unknown_8x8.spf:

$(FONTS)/unifont-7.0.03.spf.gz:
$(FONTS)/nl_tab_unknown_8x16.spf:

$(BUILD)/c/gen_cshout: $(SRC)/encoding_patterns.h.header $(SRC)/spfenc.c $(SRC)/font.c $(SRC)/font.h $(FONTS)/c64_extended.spf.gz $(FONTS)/nl_tab_unknown_8x8.spf

	mkdir -p $(BUILD)/c

	@echo "start build c64_extended font =================="
	@echo ""

	$(SRC)/create_encoding_patterns.sh --pass 0 \
	--source $(SRC) \
	--build $(BUILD)/c \
	--out cshout \
	--spfgz $(FONTS)/c64_extended.spf.gz \
	--lpc 8 \
	--ammend $(FONTS)/nl_tab_unknown_8x8.spf \
	--name "c64 extended" \
	--desc "spf derived from file c64font.bdf.tgz, `date --iso-8601`"

	touch $(BUILD)/c/gen_cshout

	@echo "done! =========================================="

$(BUILD)/u/gen_ushout: $(SRC)/encoding_patterns.h.header $(SRC)/spfenc.c $(SRC)/font.c $(SRC)/font.h $(FONTS)/unifont-7.0.03.spf.gz $(FONTS)/nl_tab_unknown_8x16.spf

	mkdir -p $(BUILD)/u

	@echo "start build unifont font ======================="
	@echo ""

	$(SRC)/create_encoding_patterns.sh --pass 0 \
	--source $(SRC) \
	--build $(BUILD)/u \
	--out ushout \
	--spfgz $(FONTS)/unifont-7.0.03.spf.gz \
	--lpc 16 \
	--ammend $(FONTS)/nl_tab_unknown_8x16.spf \
	--name "unifont 7" \
	--desc "spf derived from file unifont-7.0.03.bdf.tgz, `date --iso-8601`"

	touch $(BUILD)/u/gen_ushout

	@echo "done! =========================================="

$(BUILD)/utf8.o: $(SRC)/utf8.c
	$(CC) -c -o $(BUILD)/utf8.o $(SRC)/utf8.c $(CFLAGS)

$(BUILD)/c/cshout.o: $(SRC)/shout.c
	$(CC) -c -o $(BUILD)/c/cshout.o $(SRC)/shout.c $(CFLAGS)

$(BUILD)/c/cfont.o: $(SRC)/font.c
	$(CC) -c -o $(BUILD)/c/cfont.o $(SRC)/font.c $(CFLAGS) -I $(BUILD)/c

cshout: $(BUILD)/c/gen_cshout $(BUILD)/utf8.o $(BUILD)/c/cfont.o $(BUILD)/c/cshout.o
	$(CC) -o $(BUILD)/c/cshout $(BUILD)/c/cshout.o $(BUILD)/utf8.o $(BUILD)/c/cfont.o $(CFLAGS)
	$(BUILD)/c/cshout --fontinfo
	$(BUILD)/c/cshout --eval 'congrat\/s!'

$(BUILD)/u/ushout.o: $(SRC)/shout.c
	$(CC) -c -o $(BUILD)/u/ushout.o $(SRC)/shout.c $(CFLAGS)

$(BUILD)/u/ufont.o: $(SRC)/font.c
	$(CC) -c -o $(BUILD)/u/ufont.o $(SRC)/font.c $(CFLAGS) -I $(BUILD)/u

ushout: $(BUILD)/u/gen_ushout $(BUILD)/utf8.o $(BUILD)/u/ufont.o $(BUILD)/u/ushout.o
	$(CC) -o $(BUILD)/u/ushout $(BUILD)/u/ushout.o $(BUILD)/utf8.o $(BUILD)/u/ufont.o $(CFLAGS)
	$(BUILD)/u/ushout --fontinfo
	$(BUILD)/u/ushout --eval 'congrat\/s!'

bdf2spf: $(SRC)/bdf2spf.c
	$(CC) -o $(BUILD)/bdf2spf $(SRC)/bdf2spf.c $(CFLAGS)	

$(DOC)/$(PROGNAME).1.gz: $(DOC)/$(PROGNAME).man.asciidoc
	a2x --doctype manpage --format manpage $(DOC)/$(PROGNAME).man.asciidoc
	gzip -9 -f $(DOC)/$(PROGNAME).1

manpage: $(DOC)/$(PROGNAME).1.gz

install: cshout ushout
	mkdir -p $(DESTDIR)$(INSTALLDIR)/
	mkdir -p $(DESTDIR)$(MANDIR)/

	install -m755 $(SRC)/shout.sh $(DESTDIR)$(INSTALLDIR)/shout
	install -m755 $(SRC)/ishout.sh $(DESTDIR)$(INSTALLDIR)/ishout
	install -m755 $(BUILD)/c/cshout $(DESTDIR)$(INSTALLDIR)/
	install -m755 $(BUILD)/u/ushout $(DESTDIR)$(INSTALLDIR)/

	install -m644 $(DOC)/$(PROGNAME).1.gz $(DESTDIR)$(MANDIR)/

uninstall:
	rm -f $(DESTDIR)$(INSTALLDIR)/shout
	rm -f $(DESTDIR)$(INSTALLDIR)/ishout
	rm -f $(DESTDIR)$(INSTALLDIR)/cshout
	rm -f $(DESTDIR)$(INSTALLDIR)/ushout

	rm -f $(DESTDIR)$(MANDIR)/$(PROGNAME).1.gz
	-rmdir $(DESTDIR)$(INSTALLDIR)
	-rmdir $(DESTDIR)$(MANDIR)

clean:
	rm -rf $(BUILD)
	rm -f $(PROGNAME)*.deb
	rm -f $(PROGNAME)*.deb.txt
	rm -rf doc-pak
	rm -f description-pak

prepare_checkinstall: manpage
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
deb: prepare_checkinstall cshout ushout
	rm -f doc-pak/changelog.Debian.gz
	cp $(DOC)/changelog.Debian.$(ARCH) doc-pak/changelog.Debian
	gzip -9 doc-pak/changelog.Debian	
	chmod 0644 doc-pak/changelog.Debian.gz

	checkinstall -D --exclude="/home/*" --arch=$(ARCH) --pkgname=$(PROGNAME) --pkgsource=$(SRC_URL) --pkgversion=$(VERSION) --pkgrelease=$(RELEASE) \
	--requires=$(REQUIRES) --maintainer=$(MAINTAINER) --pkglicense=$(LICENSE) --pkggroup=$(PKG_GROUP) --backup=no --install=no make install PREFIX=$(PREFIX_PACKAGES)

	@echo "done."
	@echo "next: make deb_dist ARCH=i386|amd64|armhf"

deb_dist: deb
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

.PHONY: clean all install uninstall gen_cshout gen_ushout prepare_checkinstall deb deb_dist
