shout - alphanumeric terminal chars
===================================

![shout example 1](doc/shout4.png?raw=true)

Install on Linux
----------------

```
  git clone git://github.com/7890/shout.git
  cd shout
  make
  ./shout 123
  #sudo make install
  #will install to /usr/local/bin, /usr/local/share/man/man1

  #alternatively use a binary package from dist/
```

How does shout differ from figlet?
----------------------------------

figlet (ftp://ftp.figlet.org/pub/figlet/README) is a well-known tool.
It supports many fonts and powerful display options like "smushing".
The fonts are made up of character symbols. The difference of shout vs. 
figlet output is shown best with an image:

![shout / figlet comparison](doc/shout_vs_figlet.png?raw=true)

Please note, shout has just one built-in font at this time.

man page
--------

```
NAME
       shout - prints large alphanumeric characters to terminal

SYNOPSIS
       shout OPTIONS <string>

DESCRIPTION
       shout takes a string argument and prints it to the terminal as
       pixel-style symbols using color escape sequences.

       The following characters can be printed:

       0123456789+-=_.,:;!?|%&$@#^~/\[](){}<>*°§çäöüèéàßœæëÿïêôûâî"'`*
       (plus [a-Z] and space) lowercase letters will be printed
       uppercase

       If <string> is -, stdin will be used

       Foreground and background colors can be set individually. The
       following escape sequences are interpreted for color styling:

       \R: red

       \G: green

       \B: blue

       \Y: gray

       \K: black

       \_: prepended to colors sets background color

       \|: reset style

       \/: invert the foreground/background color scheme

       If the terminal width is not wide enough for displaying the input
       on one line, the output will be wrapped.

       shout version is 0.9

OPTIONS
       --help
           Show help (if given as only argument)

       --version
           Show version (if given as only argument)

       --info
           Show info (if given as only argument)

       --clear
           If equal 1, the screen will be cleared and cursor put to top
           left before output takes place

       --clearnl
           If equal 1, the screen will be cleared for every new input
           line (useful in conjuction with -)

       --nocursor
           If equal 1, the cursor will be hidden (stays hidden after
           program exits)

EXIT STATUS
       0
           Success

       1
           Wrong arguments, no input string given

EXAMPLES
       Simple shout
           $ shout "123 abc"

       Use some symbols
           $ shout "%?@#é"

       Highlight a part in string by temporary inverting (and resetting)
       style
           $ shout "1\/2\|3"

       Colorful test
           $ shout "\R1\G2\B3"

       Setting background red and foreground green
           $ shout "\_\R\G1"

       The same inverted
           $ shout "\_\R\G\/1"

       Using options, clear screen before print
           $ shout --clear "123"

       Using options, hide cursor (use command reset to reset terminal)
           $ shout --nocursor "123"

       Read from stdin
           $ echo "abc" | shout -

       Using options, clear screen for every new line (input from stdin)
           $ shout --clearnl -

       Multiline from stdin
           $ printf "1\n2\n3\n" | shout -

BUGS
       Please report any bugs to https://github.com/7890/shout/issues

AUTHOR
       shout was written by Thomas Brand <tom@trellis.ch>

RESOURCES
       Github: https://github.com/7890/shout

SEE ALSO
       osctermd(1)

COPYING
       Copyright (C) 2013 - 2014 Thomas Brand. Free use of this software
       is granted under the terms of the GNU General Public License
       (GPL).


                               08/25/2014                       SHOUT(1)
```

PAGER="cat" man shout
