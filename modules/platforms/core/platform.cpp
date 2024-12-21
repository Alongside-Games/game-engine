#include "platform.hpp"

#include "windows/factory.hpp"

namespace core
{
    auto Platform::init() -> void
    {
        init_context_functions();
    }

    auto Platform::init_context_functions() -> void
    {
        const auto factory = create_factory();

        const auto  window = factory->create_window();
        const auto context = factory->create_context();

         window->init({ "context", { 0, 0 } });
        context->init(window->handle());
    }

    auto Platform::create_factory() -> std::unique_ptr<base::Factory>
    {
        #ifdef _WINDOWS
        return std::make_unique<windows::Factory>();
        #endif
    }
}