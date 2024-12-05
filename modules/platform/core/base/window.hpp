#pragma once

namespace core::base
{
    class Window
    {
    public:
        virtual auto  create(const configuration::window& config) -> void = 0;
        virtual auto  destroy()    const                          -> void = 0;
        virtual auto  show()       const                          -> void = 0;

        [[nodiscard]] virtual auto handle() const -> std::any = 0;
    };
}