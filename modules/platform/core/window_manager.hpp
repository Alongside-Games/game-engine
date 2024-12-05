#pragma once

#include "base/factory.hpp"

namespace core
{
    class WindowManager
    {
    public:
        auto init(const configuration::window& window_config) -> void;
        auto release()                                        -> void;

        [[nodiscard]] auto window()        const -> base::Window&;
        [[nodiscard]] auto window_events() const -> base::WindowEvents&;

        static auto instance() -> WindowManager&;

    private:
        std::unique_ptr<base::Window>       _window;
        std::unique_ptr<base::WindowEvents> _window_events;

        WindowManager() = default;
    };
}