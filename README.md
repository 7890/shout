shout - alphanumeric terminal chars
===================================

![shout example 1](doc/shout3.png?raw=true)

Install on Linux
----------------

```
  git clone git://github.com/7890/shout.git
  cd shout
  make
  ./shout 123
  #sudo make install
  #will install to /usr/local/bin, /usr/local/share/man/man1
```

man page
--------

```
SHOUT(1)                                                                              SHOUT(1)



NAME
       shout - prints large alphanumeric characters to terminal

SYNOPSIS
       shout string [clear_screen [cursor_off]]
       shout [-h | --help | -v | --version | -i | --info ] 

DESCRIPTION
       shout takes a string argument and prints it to the terminal using color escape
       sequences (VT100 compatible).

       The following characters can be printed:

       0123456789+-=_.,:;!?/\[](){}abcdefghijklmnopqrstuvwxyz* (and space)

       Prefixed with the escape character \ (backslash), the following characters or tags are
       interpreted for highlighting or inverting:

       \[...\]: background red

       \{...\}: background green

       \(...\): background blue

       \<...\>: invert the foreground/background color scheme

       Any input enclosed with these characters is highlighted. Highlighting can not be
       nested. On closing the hightlight, the color scheme reverts to standard (light gray on
       black). Simplified notation is possible by using only the start tag, see examples.
       Strings enclosed in \<\> can contain highlighted parts.

       If the terminal width is not wide enough for displaying the input on one line, the
       output will look weird.

       shout version is 0.3

OPTIONS
       -h, --help
           Show help (if given as only argument)

       -v, --version
           Show version (if given as only argument)

       -i, --info
           Show info (if given as only argument)

       clear_screen
           If equal 1, the screen will be cleared and cursor put to top left before output
           takes place

       cursor_off
           If equal 1, the cursor will be hidden (stays hidden after program exits)

EXIT STATUS
       0
           Success

       1
           No input string given

EXAMPLES
       Simple shout
           $ shout "123 abc"

       Use special symbols
           $ shout "+-?()[]{}"

       Highlight part in string
           $ shout "1\[2\]3"

       Colorful (simplified notation, no closing tags)
           $ shout "\[ \{ \( "

       Partial color inversion in string
           $ shout "123\<4567"

       Highlighted parts inside inversion
           $ shout "\[5\(6\) \<\[5\(6\>"

       Using options, clear screen before print
           $ shout "123" 1

       Using options, hide cursor
           $ shout "123" 0 1

       Multiline output
           $ shout 123; shout 456

BUGS
       See the BUGS file in the source distribution.

AUTHOR
       shout was written by Thomas Brand <tom@trellis.ch>

RESOURCES
       Github: https://github.com/7890/shout

SEE ALSO
       osctermd(1)

COPYING
       Copyright (C) 2013 Thomas Brand. Free use of this software is granted under the terms
       of the GNU General Public License (GPL).



                                          07/15/2013                                  SHOUT(1)
```
