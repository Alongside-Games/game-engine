#include "input.hpp"

namespace windows
{
    auto Input::init() -> void
    {
        codes[VK_ESCAPE] = core::input::escape;
        codes[VK_SPACE]  = core::input::space;

        codes['W'] = core::input::w;
        codes['A'] = core::input::a;
        codes['S'] = core::input::s;
        codes['D'] = core::input::d;
    }
}