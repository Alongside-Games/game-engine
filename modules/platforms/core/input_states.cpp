#include "input_states.hpp"
#include "input_manager.hpp"

namespace core
{
    auto InputStates::update() -> void
    {
        #pragma region references

        auto& actions = InputManager::instance().input().actions;

        #pragma endregion

        if (_changes.empty()) return;

        for (auto change : _changes)
        {
            if (actions.contains(change))
            {
                actions[change]();
            }
        }

        _changes.clear();
    }

    auto InputStates::update(input::keys key, const bool state) -> void
    {
        #pragma region references

        auto& previous = _previous[key];
        auto&  current =  _current[key];

        #pragma endregion

            previous = current;
             current = state;

        if (current && !previous)
        {
            if (std::ranges::find(_changes, key) == _changes.end())
            {
                _changes.emplace_back(key);
            }
        }
    }

    auto InputStates::pressed(const input::keys key) -> bool
    {
        return _current[key];
    }
}