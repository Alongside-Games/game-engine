#include "time.hpp"

namespace core
{
    auto Time::init() -> void
    {
           _start_time =  now_time();
         _current_time = _start_time;
    }

    auto Time::update() -> void
    {
        const auto current_time = now_time();

        _total_time = seconds(current_time -   _start_time).count();
        _delta_time = seconds(current_time - _current_time).count();

      _current_time = current_time;
    }

    auto Time::total_time() -> float
    {
        return _total_time;
    }

    auto Time::delta_time() -> float
    {
        return _delta_time;
    }

    auto Time::now_time() -> time_point
    {
        return time_clock::now();
    }
}