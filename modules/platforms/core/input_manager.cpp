#include "input_manager.hpp"
#include "platform.hpp"

namespace core
{
    InputManager::InputManager()
        : _states { std::make_unique<InputStates>() }
        , _mouse  { std::make_unique<InputMouse>()  }
    {
    }

    auto InputManager::init() -> void
    {
        _input  = Platform::create_factory()->create_input();
        _input->init();
    }

    auto InputManager::update(const int32_t item, const bool state) const -> void
    {
        if (const auto it  = _input->codes.find(item);
                       it != _input->codes.end())
        {
            _states->update(it->second, state);
        }
    }

    auto InputManager::scroll(const int32_t delta) const -> void
    {
        if (_mouse->on_scroll)
        {
            _mouse->on_scroll(delta);
        }
    }

    auto InputManager::input() const -> base::Input&
    {
        return *_input;
    }

    auto InputManager::states() const -> InputStates&
    {
        return *_states;
    }

    auto InputManager::mouse() const -> InputMouse&
    {
        return *_mouse;
    }

    auto InputManager::instance() -> InputManager&
    {
        static InputManager instance;
        return instance;
    }
}