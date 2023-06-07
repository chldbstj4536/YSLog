#pragma once

#include <iostream>
#include <format>
#include <string_view>
#include <source_location>

namespace YS::Log
{
    void log(const std::string_view message, const std::ostream& outStream = std::cout , const std::source_location& location = std::source_location::current())
    {
        outStream << std::format("{}\n:filename : {}\nline : {}\n", message, location.file_name(), location.line());
    }
}