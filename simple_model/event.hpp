#pragma once

#include <list>
#include <functional>

namespace model
{

  template<typename... TArgs>
  class event
  {
  public:
    using handler = std::function<void(TArgs...)>;
    using connection = typename std::list<handler>::const_iterator;

    connection connect(handler h)
    {
      return _handlers.insert(_handlers.end(), std::move(h));
    }

    void disconnect(connection c)
    {
      _handlers.erase(c);
    }

    void emit(TArgs... args) const
    {
      for (const handler& h : _handlers)
        if (h)
          h(args...);
    }

  private:
    std::list<handler> _handlers;
  };

}
