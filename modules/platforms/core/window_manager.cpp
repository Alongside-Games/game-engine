#include "window_manager.hpp"
#include "platform.hpp"

namespace core
{
    auto WindowManager::init(const configuration::window& window_config) -> void
    {
         const auto factory = Platform::create_factory();

        _window = factory->create_window();
        _events = factory->create_window_events();

        _window->init(window_config);
    }

    auto WindowManager::release() const -> void
    {
        _window->release();
    }

    auto WindowManager::window() const -> base::Window&
    {
        return *_window;
    }

    auto WindowManager::events() const -> base::WindowEvents&
    {
        return *_events;
    }

    auto WindowManager::instance() -> WindowManager&
    {
        static WindowManager instance;
        return instance;
    }
}