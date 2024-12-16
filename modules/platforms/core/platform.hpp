#pragma once

#include "base/factory.hpp"

namespace core
{
    class Platform
    {
    public:
        static auto create_factory() -> std::unique_ptr<base::Factory>;
    };
}