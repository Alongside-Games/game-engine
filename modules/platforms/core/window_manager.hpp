#pragma once

#include "base/factory.hpp"

namespace core
{
    class WindowManager
    {
    public:
        auto    init(const configuration::platform& config) -> void;
        auto release()     const                            -> void;

        #pragma region events

        auto resize(int32_t width, int32_t height) const -> void;
        auto close()                               const -> void;

        #pragma endregion

        #pragma region getters

        [[nodiscard]] auto window()  const -> base::Window&;
        [[nodiscard]] auto events()  const -> base::WindowEvents&;
        [[nodiscard]] auto context() const -> base::Context&;

        static  auto  instance() -> WindowManager&;

        #pragma endregion

    private:
        std::unique_ptr<base::Window>       _window;
        std::unique_ptr<base::WindowEvents> _events;
        std::unique_ptr<base::Context>      _context;

        WindowManager() = default;
    };
}