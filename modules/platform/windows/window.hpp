#pragma once

#include "core/base/window.hpp"

namespace windows
{
    class Window final : public core::base::Window
    {
    public:
        auto init(const core::configuration::window& config) -> void override;
        auto release()  const                                -> void override;
        auto show()     const                                -> void override;

        [[nodiscard]]   auto handle() const -> std::any override;

    private:
        auto   register_id(const std::string& title) -> void;
        auto unregister_id()                   const -> void;

        uint32_t styles { WS_CLIPSIBLINGS | WS_CLIPCHILDREN };
        uint32_t extras { WS_EX_APPWINDOW };

        ATOM   id { };
        HWND hwnd { };
    };
}