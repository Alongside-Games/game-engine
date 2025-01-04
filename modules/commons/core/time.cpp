#include "time.hpp"

namespace core
{
    auto Time::init() -> void
    {
           start_time =   now_time();
         current_time = start_time;
    }

    auto Time::update() -> void
    {
         const auto current = now_time();

        _total_time = seconds(current -   start_time).count();
        _delta_time = seconds(current - current_time).count();

       current_time = current;
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