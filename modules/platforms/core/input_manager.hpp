#pragma once

#include "base/input.hpp"

#include "input_mouse.hpp"
#include "input_states.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto   init()                                -> void;
        auto update(int32_t item,  bool state) const -> void;

        #pragma region events

        auto scroll(int32_t delta) const -> void;

        #pragma endregion

        #pragma region getters

        [[nodiscard]] auto input()  const -> base::Input&;

        [[nodiscard]] auto states() const -> InputStates&;
        [[nodiscard]] auto  mouse() const -> InputMouse&;

        static  auto  instance() -> InputManager&;

        #pragma endregion

    private:
        std::unique_ptr<base::Input> _input;

        std::unique_ptr<InputStates> _states;
        std::unique_ptr<InputMouse>  _mouse;

        InputManager();
    };
}