#include "event.hpp"
#include <type_traits>

namespace model
{

  namespace default_equal
  {
    template<typename T, typename U>
    bool operator==(T&&, U&&) { return false; }
    template<typename T, typename U>
    bool operator!=(T&&, U&&) { return true; }
  }

  template<typename T>
  class property
  {
  public:
    property() = default;
    property(const property&) = delete;
    property(property&&) = delete;

    property(const T& value)
      : _value(value)
    {}

    property(T&& value)
      : _value(std::move(value))
    {}

    const T& get() const { return _value; }

    void set(const T& value)
    {
      using namespace default_equal;

      if (value != _value)
      {
        _value = value;
        changed.emit(_value);
      }
    }

    void set(T&& value)
    {
      using namespace default_equal;

      if (value != _value)
      {
        _value = std::move(value);
        changed.emit(_value);
      }
    }

    property& operator=(const T& value)
    {
      set(value);
      return *this;
    }

    property& operator=(T&& value)
    {
      set(std::move(value));
      return *this;
    }

    operator const T&() const { return _value; }

    mutable event<const T&> changed;

  private:
    T _value;
  };

}