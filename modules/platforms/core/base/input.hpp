#pragma once

namespace core::base
{
    class Input
    {
    public:
        virtual auto init() -> void = 0;

        std::unordered_map<uint32_t, std::function<void()>> actions;
        std::unordered_map<uint32_t, input::keys>           codes;
    };
}