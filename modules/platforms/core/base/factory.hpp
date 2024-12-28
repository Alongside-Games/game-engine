#pragma once

#include "context.hpp"
#include "context_functions.hpp"

#include "window.hpp"
#include "window_events.hpp"

#include "input.hpp"

namespace core::base
{
    class Factory
    {
    public:
        virtual auto create_context()           -> std::unique_ptr<Context>          = 0;
        virtual auto create_context_functions() -> std::unique_ptr<ContextFunctions> = 0;

        virtual auto create_window()        -> std::unique_ptr<Window>       = 0;
        virtual auto create_window_events() -> std::unique_ptr<WindowEvents> = 0;

        virtual auto create_input() -> std::unique_ptr<Input> = 0;
    };
}