#include "input_states.hpp"
#include "input_manager.hpp"

namespace core
{
    auto InputStates::update() -> void
    {
        if (_changes.empty())
        {
            return;
        }
                const auto& input = InputManager::instance().input();

        for (auto change : _changes)
        {
            if (const auto  it  = input.actions.find(change);
                            it != input.actions.end())
            {
                it->second();
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

                        previous  = std::exchange(current, state);

        if (current && !previous && std::ranges::find(_changes, item) == _changes.end())
        {
            _changes.emplace_back(item);
        }
    }

    auto InputStates::pressed(const int32_t item) -> bool
    {
        return _current[item];
    }
}