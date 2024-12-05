#include "window_size.hpp"

namespace core
{
    window_size::window_size(const int32_t width, const int32_t height)
        : _width  { width  }
        , _height { height }
        , _ratio  { static_cast<float>(width) / static_cast<float>(height) }
    {
    }

    auto window_size::width() const -> int32_t
    {
        return _width;
    }

    auto window_size::height() const -> int32_t
    {
        return _height;
    }

    auto window_size::ratio() const -> float
    {
        return _ratio;
    }
}