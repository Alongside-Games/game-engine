#include "platform.hpp"

#include "windows/factory.hpp"

namespace core
{
    auto Platform::create_factory() -> std::unique_ptr<base::Factory>
    {
        #ifdef _WINDOWS
        return std::make_unique<windows::Factory>();
        #endif
    }
}