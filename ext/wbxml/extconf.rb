require 'mkmf'

dir_config("wbxml")

$libs = append_library($libs, "expat")

create_makefile("wbxml")
