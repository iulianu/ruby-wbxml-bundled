require "test/unit"

$:.unshift File.dirname(__FILE__) + "/../ext/wbxml"
require "wbxml.so"

class TestWbxmlExtn < Test::Unit::TestCase
  def test_truth
    assert true
  end
end