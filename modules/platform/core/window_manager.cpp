#include "window_manager.hpp"
#include "platform.hpp"

namespace core
{
    auto WindowManager::init(const configuration::window& window_config) -> void
    {
        const auto factory = Platform::create_factory();

        _window        = factory->create_window();
        _window_events = factory->create_window_events();

        _window->create(window_config);
    }

    auto WindowManager::release() const -> void
    {
        _window->destroy();
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