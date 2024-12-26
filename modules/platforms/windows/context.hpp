#pragma once

#include "core/base/context.hpp"

namespace windows
{
    class Context final : public core::base::Context
    {
    public:
        auto init(const core::configuration::context& config, const std::any& handle) -> void override;
        auto init(                                            const std::any& handle) -> void override;

        auto sync(int32_t interval) -> void override;

        auto release() -> void override;
        auto present() -> void override;

    private:
        HGLRC hrc { };
        HDC   hdc { };
    };
}