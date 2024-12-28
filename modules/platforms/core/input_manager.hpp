#pragma once

#include "input_states.hpp"

#include "base/input.hpp"

namespace core
{
    class InputManager
    {
    public:
        auto init() -> void;

        [[nodiscard]]  auto input()  const -> base::Input&;
        [[nodiscard]]  auto states() const -> InputStates&;

        static auto instance() -> InputManager&;

    private:
        std::unique_ptr<base::Input> _input;
        std::unique_ptr<InputStates> _states;

        InputManager() = default;
    };
}