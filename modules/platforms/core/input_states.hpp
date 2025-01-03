#pragma once

namespace core
{
    class InputStates
    {
    public:
        auto  update()                            -> void;
        auto  update(int32_t item,    bool state) -> void;

        auto pressed(int32_t item) -> bool;

    private:
        std::unordered_map<int32_t, bool>  _current;
        std::unordered_map<int32_t, bool> _previous;

        std::vector<int32_t> _changes;
    };
}