#include "property.hpp"
#include "catch.hpp"

using namespace model;

TEST_CASE("Basic property")
{
  property<int> prop = 42;

  REQUIRE(prop == 42);

  prop.changed.connect([](int value) { REQUIRE(value == 1337); });

  prop = 1337;
}