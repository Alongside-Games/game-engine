#pragma once

namespace core
{
    class InputStates
    {
    public:
        auto  update()                               -> void;
        auto  update(input::keys key,    bool state) -> void;
        auto pressed(input::keys key) -> bool;

    private:
        std::unordered_map<input::keys,  bool>  _current;
        std::unordered_map<input::keys,  bool> _previous;

        std::vector<uint32_t> _changes;
    };
}