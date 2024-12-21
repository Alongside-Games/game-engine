#pragma once

#include "base/factory.hpp"

namespace core
{
    class WindowManager
    {
    public:
        auto init(const configuration::platform& config) -> void;
        auto release()  const                            -> void;

        [[nodiscard]] auto window()  const -> base::Window&;
        [[nodiscard]] auto events()  const -> base::WindowEvents&;
        [[nodiscard]] auto context() const -> base::Context&;

        static auto instance() -> WindowManager&;

    private:
        std::unique_ptr<base::Window>       _window;
        std::unique_ptr<base::WindowEvents> _events;
        std::unique_ptr<base::Context>      _context;

        WindowManager() = default;
    };
}