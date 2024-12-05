#include "window_manager.hpp"

namespace core
{
    auto WindowManager::init(const configuration::window& window_config) -> void
    {
    }

    auto WindowManager::release() const -> void
    {
    }

    auto WindowManager::window() const -> base::Window&
    {
        return *_window;
    }

    auto WindowManager::window_events() const -> base::WindowEvents&
    {
        return *_window_events;
    }

    auto WindowManager::instance() -> WindowManager&
    {
        static WindowManager instance;
        return instance;
    }
}