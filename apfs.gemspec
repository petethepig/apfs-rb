lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)

require 'apfs/version'

Gem::Specification.new do |s|
  s.name          = "apfs"
  s.version       = Apfs::VERSION
  s.summary       = "apfs"
  s.description   = "Apple File System Utils"
  s.authors       = ["Dmitry Filimonov"]
  s.email         = "me@dfilimonov.com"
  s.files         = `git ls-files`.split("\n")
  s.homepage      = "http://rubygems.org/gems/apfs"
  s.license       = "MIT"
  s.require_paths = ["lib"]
  s.extensions    = ["ext/apfs_ext/extconf.rb"]

  s.add_development_dependency "rake-compiler", ">= 0.7.0"
end
