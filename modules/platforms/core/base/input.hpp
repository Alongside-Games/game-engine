#pragma once

namespace core::base
{
    class Input
    {
    public:
        virtual auto init() -> void = 0;

        std::unordered_map<int32_t, int32_t>               codes;
        std::unordered_map<int32_t, std::function<void()>> actions;
    };
}