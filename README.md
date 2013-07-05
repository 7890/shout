shout - terminal digits
=======================

![shout example 1](doc/shout1.png?raw=true)

![shout example 2](doc/shout2.png?raw=true)

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
SHOUT(1)                                                              SHOUT(1)



NAME
       shout - prints large digits to terminal

SYNOPSIS
       shout [-h | --help] | string [clear_screen [cursor_off [invert_color]]]

DESCRIPTION
       shout takes a string argument and prints it to the terminal using color
       escape sequences (VT100 compatible).

       The following characters can be printed:

       0123456789 +-=_.,:;!?/*

       The following characters are interpreted for highlighting or inverting:

       []: background red

       {}: background green

       (): background blue

       Any input enclosed with these characters are highlighted. Highlighting
       can not be nested.

       <>: Invert the foreground/background color scheme

       Strings enclosed in <> can contain highlighted parts.

       If the terminal width is not wide enough for displaying the input on
       one line, it will look weird.

OPTIONS
       -h, --help
           Show help (if given as only argument)

       clear_screen
           If equal 1, the screen will be cleared and cursor put to top left
           before output takes place

       cursor_off
           If equal 1, the cursor will be hidden (stays hidden after program
           exits)

       invert_color
           If equal 1, the colors will be inverted globally. This can not be
           combined with <> partial inversions

EXIT STATUS
       0
           Success

       1
           No input string given

EXAMPLES
       Simple shout
           $ shout 123

       Use special symbols
           $ shout ",;.:+-?"

       Highlight part in string
           $ shout "1[2]3"

       Colorful
           $ shout "[ ]{ }( )"

       Partial color inversion in string
           $ shout "123<4567>"

       Highlighted parts inside inversion
           $ shout "[5](6) <[5](6)>"

       Using options, clear screen before print
           $ shout "123" 1

       Using options, hide cursor
           $ shout "123" 0 1

       Using options, global color inversion
           $ shout "123" 0 0 1

       Using options, all
           $ shout "123" 1 1 1

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
       Copyright (C) 2013 Thomas Brand. Free use of this software is granted
       under the terms of the GNU General Public License (GPL).



                                  07/05/2013                          SHOUT(1)
```
