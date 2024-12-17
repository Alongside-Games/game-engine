#include "factory.hpp"

#include "context.hpp"
#include "context_functions.hpp"

#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Factory::create_context() -> std::unique_ptr<core::base::Context>
    {
        return std::make_unique<Context>();
    }

    auto Factory::create_context_functions() -> std::unique_ptr<core::base::ContextFunctions>
    {
        return std::make_unique<ContextFunctions>();
    }

    auto Factory::create_window() -> std::unique_ptr<core::base::Window>
    {
        return std::make_unique<Window>();
    }

    auto Factory::create_window_events() -> std::unique_ptr<core::base::WindowEvents>
    {
        return std::make_unique<WindowEvents>();
    }
}