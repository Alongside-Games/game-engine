#pragma once

namespace core::base
{
    class Context
    {
    public:
        virtual auto init(const configuration::context& config, const std::any& handle) -> void = 0;
        virtual auto init(                                      const std::any& handle) -> void = 0;

        virtual auto release() -> void = 0;
        virtual auto present() -> void = 0;
    };
}