#pragma once

#include <iostream>
#include <format>
#include <string_view>
#include <source_location>

namespace YS::Log
{
    void log(const std::string_view message, std::ostream& outStream = std::cout , const std::source_location& location = std::source_location::current())
    {
        #ifdef _DEBUG
        outStream << std::format("{}\npath : {}\nline : {}\n", message, location.file_name(), location.line());
        #endif
    }
}