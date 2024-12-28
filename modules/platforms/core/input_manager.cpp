#include "input_manager.hpp"
#include "platform.hpp"

namespace core
{
    auto InputManager::init() -> void
    {
        _states = std::make_unique<InputStates>();

        _input  = Platform::create_factory()->create_input();
        _input->init();
    }

    auto InputManager::input() const -> base::Input&
    {
        return *_input;
    }

    auto InputManager::states() const -> InputStates&
    {
        return *_states;
    }

    auto InputManager::instance() -> InputManager&
    {
        static InputManager instance;
        return instance;
    }
}