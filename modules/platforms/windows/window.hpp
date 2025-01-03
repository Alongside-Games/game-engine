#pragma once

#include "core/base/window.hpp"

namespace windows
{
    class Window final : public core::base::Window
    {
    public:
        auto    init(const core::configuration::window& config) -> void override;
        auto release()     const                                -> void override;

        auto title(const std::string& title) -> void override;
        auto show()      const               -> void override;

        [[nodiscard]]    auto handle() const -> std::any override;

    private:
        uint32_t  style { WS_CLIPSIBLINGS | WS_CLIPCHILDREN };
        uint32_t  extra { WS_EX_APPWINDOW };

        HWND hwnd { };
        WORD   id { };
    };
}