#include "functions_loader.hpp"

namespace opengl
{
    auto FunctionsLoader::init_core() -> void
    {
        const auto instance = LoadLibrary("opengl32.dll");

        if (instance == nullptr)
        {
            std::exit(EXIT_FAILURE);
        }

        glViewport   = reinterpret_cast<PFNGLVIEWPORTPROC>  (GetProcAddress(instance, "glViewport"));
        glClear      = reinterpret_cast<PFNGLCLEARPROC>     (GetProcAddress(instance, "glClear"));
        glClearColor = reinterpret_cast<PFNGLCLEARCOLORPROC>(GetProcAddress(instance, "glClearColor"));

        FreeLibrary(instance);
    }

    auto FunctionsLoader::init_extensions() -> void
    {
    }
}