#include "event.hpp"
#include "catch.hpp"

using namespace model;

TEST_CASE("Basic connection checked")
{
  event<> e;
  bool called = false;

  e.emit();
  REQUIRE_FALSE(called);
  e.connect([&called]() { called = true; });
  e.emit();
  REQUIRE(called);
}

TEST_CASE("Disconnection test")
{
  int value = 42;
  event<int> e;

  e.emit(1337);
  REQUIRE(value == 42);

  auto connection = e.connect([&value](int v) { value = v; });
  e.emit(1337);
  REQUIRE(value == 1337);

  e.disconnect(connection);
  e.emit(13);
  REQUIRE(value == 1337);
}