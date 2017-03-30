require 'mkmf'

abort "missing copyfile()" unless have_func "copyfile"

create_makefile 'apfs'
