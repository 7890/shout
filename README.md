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
SHOUT(1)                                                              SHOUT(1)

NAME
       shout - print large pixel fonts in terminal

SYNOPSIS
       shout OPTIONS <string>

DESCRIPTION
       shout takes a string argument and prints it to the terminal as
       pixel-style symbols. The output can be styled using color escape
       sequences.

       If <string> is -, stdin will be read

       The number of available characters depends on the used font. By
       default, shout uses "c64_extended" font which covers most ASCII input.

       Using the parameter --uni will switch the font to unifont 7. This font
       covers a large set of unicode characters. See
       http://savannah.gnu.org/projects/unifont

       To use any unicode character in the terminal, press ctrl+shift+u, then
       enter the code in hex, i.e. ctrl+shift+u ab12 (enter)

       If the terminal width is not wide enough for displaying the input on
       one line, the output will be wrapped. The terminal width used to
       calculate where wrapping takes place can be set manually. Wrapping can
       also be turned off completely.

       shout version is 0.97

OPTIONS
       --eval
           evaluate input string i.e. a string \n is interpreted as newline
           control byte

               style marks (see: styling)
               note that --eval adds one level of escaping
               (also see: escaping rules)

       --relax8
           process input even if system is not reporting UTF-8

       --deffg
           set default foreground color

       --defbg
           set default background color

       --termwidth <x>
           set (virtual) terminal width in pixels default: use current
           terminal width

       --autowidth
           the first line of in input (up to \n) will set the terminal width
           for all following lines (if any)

       --tabsize <n>
           display tabs as n spaces (default: 2)

       --shownl
           indicate newline with a symbol

       --showtab
           indicate tab with a symbol

       --showall
           indicate all characters, including control and unknown

       --hideuk
           don’t indicate unknown characters (overrides --showall)

       --clearnl
           screen will be cleared before a new line is printed

       --nowrap
           don’t wrap lines exceeding (given) terminal width

       --fill
           fill up to (given) terminal width with background if there is a gap

       --plain
           print the characters in plain spf mode

       --single
           output one character per line

       --ppm
           output as (colored) ppm image skeleton with placeholders for
           _WIDTH_ _HEIGHT_ (also see: ishout wrapper, --img)

       --left <x>
           trim (extend or cut) at left edge of a character

               x>0: extend
               x<0: cut

       --right <x>
           trim (extend or cut) at right edge of a character

               x>0: extend
               x<0: cut

       --top <y>
           trim (extend or cut) at top edge of a character

               y>0: extend
               y<0: cut

       --bottom <y>
           trim (extend or cut) at bottom edge of a character

               y>0: extend
               y<0: cut

       --wabs <w>
           trim (extend or cut) character to absolute width

               x>0

       --habs <h>
           trim (extend or cut) character to absolute height

               h>0

       --fontinfo
           print information about the font

       --mapping
           print all index <→ codepoint relations in font

       --spf
           print each character of font (plain, header)

       --debug
           add some debug information to output, printed to stderr

       --help
           print this help text

       --info
           copyright info

       --version
           print version of shout

       shout help (from ishout wrapper), output PNG image data to stdout:

       --img
           dump a shout string as PNG image to stdout

               (the 'convert' tool from imagemagick must be installed)

       --border <n>
           add border of n pixels

       --bordercolor <c>
           color of border (default: black) white,red,green,blue,yellow,cyan

       --trans <c>
           make color <c> transparent

       --negate
           invert colors

       --resize <nx |xn>
           resize output image

               nx: set width n pixels (height derived)
               xn: set height n pixels (width derived)

       --antialias
           if set, output will be ~blurred

       most of the regular non-img specific shout parameters can be used with
       --img

OUTPUT COLOR STYLES
       Foreground and background colors can be set individually. The following
       escape sequences are interpreted for color styling (use along with
       --eval):

       \R: red

       \G: green

       \B: blue

       \Y: gray

       \K: black

       \_: prepended to colors sets background color

       \|: reset style

       \/: invert the foreground/background color scheme

INPUT ESCAPING
       ono escaping (apos)
           $ shout \Rx\nB

       one level of escaping (double quotes)
           $ shout "\\Rx\\nB"

       one level (eval, apos)
           $ shout --eval '\\Rx\\nB'

       two levels (eval, double quotes)
           $ shout --eval "\\\\Rx\\\\nB"

       style red, newline
           $ shout --eval "\Rx\nB"

       style red, newline
           $ shout --eval '\Rx\nB'

       display apos between double quotes
           $ shout --eval "a’b"

       display apos between apos
           $ shout --eval 'a'"'"'b'

       display double quotes between apos
           $ shout --eval 'a"b'

       display double quotes between double quotes
           $ shout --eval "a"'"'"b"

EXIT STATUS
       0
           Success

       1
           Wrong arguments, no input string given

EXAMPLES
       simple shout
           $ shout 1

       using command output
           $ shout "hostname"

       evaluate and show tabs, newlines, unknown
           $ shout --eval --showall "123\n\tabc"

       setting background red and foreground green
           $ shout "\_\R\G1"

       the same inverted
           $ shout "\_\R\G\/1"

       more coloring
           $ shout --eval "\/\R1\G2\B3\|1\/2\|3_\R1_\G\R2\_\B3"

       backslash
           $ shout '\' special case input argument starting with --: $ shout
           '--foo'

       using stdin
           $ echo a | shout -

       don’t wrap lines that do not fit
           $ cat /etc/release | shout --nowrap -

       output variation
           $ shout --plain --left 4 --fill "abc"

       information about font (--uni in that case)
           $ shout --uni --fontinfo

       Eamples for --img (output PNG image data to stdout)

       display large character '8' with transparent background
           $ shout --img --autowidth --resize 400x --trans black --negate
           --eval "8" | display -

       display two large lines, with fixed (virtual) terminal width with
       unifont 7
           $ shout --img --uni --left 5 --termwidth 50 --resize 800x --eval
           "DIS\/PLAY" | display -

       display text roughly like it would appear in a terminal
           $ cat /etc/resolv.conf | shout --img --uni --termwidth 800 - |
           display -

BUGS
       Please report any bugs to https://github.com/7890/shout/issues

AUTHOR
       shout was written by Thomas Brand <tom@trellis.ch>

RESOURCES
       Github: https://github.com/7890/shout

SEE ALSO
       osctermd(1)

COPYING
       Copyright (C) 2013 - 2014 Thomas Brand. Free use of this software is
       granted under the terms of the GNU General Public License (GPL).



                                  09/21/2014                          SHOUT(1)
```

PAGER="cat" man shout
