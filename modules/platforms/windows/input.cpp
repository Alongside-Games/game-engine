#include "input.hpp"

namespace windows
{
    auto Input::init() -> void
    {
        codes['W'] = core::input::w;
        codes['A'] = core::input::a;
        codes['S'] = core::input::s;
        codes['D'] = core::input::d;

        codes[VK_ESCAPE]  = core::input::escape;
        codes[VK_SPACE]   = core::input::space;

        codes[VK_LBUTTON] = core::input::left;
        codes[VK_MBUTTON] = core::input::middle;
        codes[VK_RBUTTON] = core::input::right;
    }
}