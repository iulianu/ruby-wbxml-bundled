= wbxml

* http://wbxml.rubyforge.org/

== DESCRIPTION:

Convert XML to WBXML for WAP mobile phone services
wbxml is a simple Ruby wrapper for the wbxml2 library.

== FEATURES/PROBLEMS:

* WBXML.xml_to_wbxml - converts XML to WBXML
* WBXML.wbxml_to_xml - converts WBXML to XML

== SYNOPSIS:

  xml = File.open("message.xml"){|f| f.read}
  wbxml = WBXML.xml_to_wbxml xml
  $output.print wbxml

== REQUIREMENTS:

* a working wbxml2
** OSX: port install wbxml2
** Debian: apt-get install libwbxml2

== INSTALL:

* sudo gem install

== LICENSE:

(The MIT License)

Copyright (c) 2008 FIX

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
