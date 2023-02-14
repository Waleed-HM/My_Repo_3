#!/bin/bash

# Globbing (File name splitting) is only performed on words (not operators)
# Globbing patterns are words that contain unquotted Special Pattern Characters : * ? [
# They are usually used in the shell to replace characters when performing certain commands

# * usually takes the place of any patern of string characters of any length
# ex : ls file*.txt		,	ls file.*

# ? replaces a single characters, multiple of them can be used
# ex : ls file?.txt		,	ls file???.txt

# [] used to exacly specify the desired character
# ex : ls file[ab].txt   : this means apply on files where a or b single character exists
# ex : ls file[a-g].txt  : any letter from a to g