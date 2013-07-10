osctermd - print OSC strings to terminal
========================================

Install on Linux
----------------

```
  git clone git://github.com/7890/shout.git
  cd shout/extras
  make
  ./osctermd
  #ctrl+c
  #sudo make install
  #will install to /usr/local/bin, /usr/local/share/man/man1
```

man page
--------

```
OSCTERMD(1)                                                                      OSCTERMD(1)

NAME
       osctermd - prints strings received as OSC messages to terminal

SYNOPSIS
       osctermd [-h | --help] | [OSC PORT]

DESCRIPTION
       osctermd takes an optional OSC PORT argument. If no port is given, osctermd will
       start on port 7770

       OSC messages with the the pattern /display s "my string" are processed.

       To suppress osctermd to output a newline \n after every received string, the
       following pattern can be used: /display si "my partial string without newline" 0

       oscterm runs as long as it is not killed (CTRL+C received).

       osctermd will reset the terminal when finished to avoid any effects from previously
       sent escape sequences (like cursor off).

EXAMPLES
       Terminal 1
           $ osctermd

       Terminal 2
           $ oscsend localhost 7770 /display s "hi"

       Terminal 2
           $ oscsend localhost 7770 /display si "h" 0

BUGS
       See the BUGS file in the source distribution.

AUTHOR
       osctermd was written by Thomas Brand <tom@trellis.ch>

RESOURCES
       Github: https://github.com/7890/shout/extras

       oscsend used in the examples is part of liblo tools: http://liblo.sourceforge.net

SEE ALSO
       shout(1)

COPYING
       Copyright (C) 2013 Thomas Brand. Free use of this software is granted under the terms
       of the GNU General Public License (GPL).



                                         07/10/2013                              OSCTERMD(1)
```
