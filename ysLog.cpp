#include "ysLog.hpp"

#define YS_BEGIN namespace YS {
#define YS_END }

YS_BEGIN
static assert_handler current_assert_handler = std::terminate;

assert_handler SetAssertHandler(assert_handler newHandler)
{
    assert_handler prevHandler = current_assert_handler;
    current_assert_handler = newHandler;
    return prevHandler;
}

void Assert(bool condition, StringView message, std::ostream &outStream, const std::source_location &location)
{
    if (!condition)
    {
        Log(message, outStream, location);
        current_assert_handler();
    }
}
YS_END