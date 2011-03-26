# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{wbxml}
  s.version = "0.0.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Clifford Heath"]
  s.date = %q{2008-05-21}
  s.description = %q{Wrapper for wbxml2, a WAP<->XML converter}
  s.email = ["cjheath@rubyforge.org"]
  s.extensions = ["ext/wbxml/extconf.rb"]
  s.extra_rdoc_files = ["History.txt", "License.txt", "Manifest.txt", "README.txt"]
  s.files = ["History.txt", "License.txt", "Manifest.txt", "README.txt", "config/hoe.rb", "config/requirements.rb", "lib/wbxml/version.rb", "setup.rb", "test/test_wbxml_extn.rb"] + Dir.glob("ext/wbxml/**/*")
  s.homepage = %q{http://wbxml.rubyforge.org}
  s.rdoc_options = ["--main", "README.txt"]
  s.require_paths = ["lib", "ext/wbxml"]
  s.rubyforge_project = %q{wbxml}
  s.rubygems_version = %q{1.4.2}
  s.summary = %q{Wrapper for wbxml2, a WAP<->XML converter}
  s.test_files = ["test/test_wbxml_extn.rb"]

  if s.respond_to? :specification_version then
    s.specification_version = 2

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end
