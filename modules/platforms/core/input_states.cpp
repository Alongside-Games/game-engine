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

    auto InputStates::update(int32_t item, const bool state) -> void
    {
        #pragma region references

        auto& previous = _previous[item];
        auto&  current =  _current[item];

        #pragma endregion

            previous = current;
             current = state;

        if (current && !previous)
        {
            if (std::ranges::find(_changes, item) == _changes.end())
            {
                _changes.emplace_back(item);
            }
        }
    }

    auto InputStates::pressed(const int32_t item) -> bool
    {
        return _current[item];
    }
}