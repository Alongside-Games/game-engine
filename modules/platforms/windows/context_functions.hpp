#pragma once

#include "core/base/context_functions.hpp"

namespace windows
{
    #pragma region functions

    using  PFNWGLCREATECONTEXTATTRIBSARBPROC = auto(WINAPI*)(HDC, HGLRC, const int32_t*)                                              -> HGLRC;
    using  PFNWGLCHOOSEPIXELFORMATARBPROC    = auto(WINAPI*)(HDC,        const int32_t*, const float*, uint32_t, int32_t*, uint32_t*) -> int32_t;
    using  PFNWGLSWAPINTERVALEXTPROC         = auto(WINAPI*)(int32_t)                                                                 -> int32_t;

    inline PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribs;
    inline PFNWGLCHOOSEPIXELFORMATARBPROC    wglChoosePixelFormat;
    inline PFNWGLSWAPINTERVALEXTPROC         wglSwapInterval;

    #pragma endregion

    class ContextFunctions final : public core::base::ContextFunctions
    {
    public:
        auto init() -> void override;
    };
}