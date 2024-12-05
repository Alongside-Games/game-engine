#pragma once

namespace core
{
    struct window_size
    {
        window_size() = default;
        window_size(int32_t width, int32_t height);

        [[nodiscard]] auto width()  const -> int32_t;
        [[nodiscard]] auto height() const -> int32_t;
        [[nodiscard]] auto ratio()  const -> float;

        static constexpr auto default_width  { 1280 };
        static constexpr auto default_height {  720 };

    private:
        int32_t _width  { default_width  };
        int32_t _height { default_height };
        float   _ratio  { };
    };
}