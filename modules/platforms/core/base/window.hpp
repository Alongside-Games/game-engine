#pragma once

namespace core::base
{
    class Window
    {
    public:
        virtual auto  init(const configuration::window& config) -> void = 0;
        virtual auto  release()  const                          -> void = 0;

        virtual auto  title(const std::string& title) -> void = 0;
        virtual auto  show()      const               -> void = 0;

        [[nodiscard]] virtual auto handle() const     -> std::any = 0;
    };
}