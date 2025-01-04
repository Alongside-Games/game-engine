#include "window_manager.hpp"
#include "platform.hpp"

namespace core
{
    auto WindowManager::init(const configuration::platform& config) -> void
    {
        const auto factory = Platform::create_factory();

        _window  = factory->create_window();
        _events  = factory->create_window_events();
        _context = factory->create_context();

         _window->init(config.window);
        _context->init(config.context, _window->handle());
    }

    auto WindowManager::release() const -> void
    {
        _context->release();
         _window->release();
    }

    auto WindowManager::resize(const int32_t width, const int32_t height) const -> void
    {
        if (_events->on_size)
        {
            _events->on_size(width, height);
        }
    }

    auto WindowManager::close() const -> void
    {
        if (_events->on_close)
        {
            _events->on_close();
        }
    }

    auto WindowManager::window() const -> base::Window&
    {
        return *_window;
    }

    auto WindowManager::events() const -> base::WindowEvents&
    {
        return *_events;
    }

    auto WindowManager::context() const -> base::Context&
    {
        return *_context;
    }

    auto WindowManager::instance() -> WindowManager&
    {
        static WindowManager instance;
        return instance;
    }
}