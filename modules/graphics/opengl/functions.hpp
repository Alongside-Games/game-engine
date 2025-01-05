#pragma once

namespace opengl
{
    #pragma region types

    using GLint      =  int32_t;
    using GLsizei    =  int32_t;
    using GLbitfield = uint32_t;

    using GLfloat    =  float;

    #pragma endregion

    #pragma region core

    using  PFNGLCLEARPROC      = auto(APIENTRY*)(GLbitfield)                         -> void;
    using  PFNGLVIEWPORTPROC   = auto(APIENTRY*)(GLint, GLint, GLsizei, GLsizei)     -> void;
    using  PFNGLCLEARCOLORPROC = auto(APIENTRY*)(GLfloat, GLfloat, GLfloat, GLfloat) -> void;

    inline PFNGLCLEARPROC      glClear;
    inline PFNGLCLEARCOLORPROC glClearColor;
    inline PFNGLVIEWPORTPROC   glViewport;

    #pragma endregion
}