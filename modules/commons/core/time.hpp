#pragma once

namespace core
{
    #pragma region types

    using seconds      = std::chrono::duration<float>;
    using milliseconds = std::chrono::duration<float, std::milli>;

    using time_clock   = std::chrono::high_resolution_clock;
    using time_point   = std::chrono::high_resolution_clock::time_point;

    #pragma endregion

    class Time
    {
    public:
        auto init()   -> void;
        auto update() -> void;

        static auto total_time() -> float;
        static auto delta_time() -> float;
        static auto   now_time() -> time_point;

    private:
        inline static float _total_time { };
        inline static float _delta_time { };

        time_point   _start_time { };
        time_point _current_time { };
    };
}