require 'mkmf'

dir_config("wbxml")

$libs = append_library($libs, "wbxml2")

create_makefile("wbxml")
