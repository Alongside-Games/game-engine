#pragma once

#include "core/base/factory.hpp"

namespace windows
{
    class Factory final : public core::base::Factory
    {
    public:
        auto create_context()           -> std::unique_ptr<core::base::Context>          override;
        auto create_context_functions() -> std::unique_ptr<core::base::ContextFunctions> override;

        auto create_window()        -> std::unique_ptr<core::base::Window>       override;
        auto create_window_events() -> std::unique_ptr<core::base::WindowEvents> override;
    };
}