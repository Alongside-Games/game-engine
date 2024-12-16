#include "factory.hpp"
#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Factory::create_window() -> std::unique_ptr<core::base::Window>
    {
        return std::make_unique<Window>();
    }

    auto Factory::create_window_events() -> std::unique_ptr<core::base::WindowEvents>
    {
        return std::make_unique<WindowEvents>();
    }
}