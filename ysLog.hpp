#pragma once

#include <iostream>
#include <format>
#include <source_location>
#include <ysDefine.hpp>

namespace YS
{
    using assert_handler = void(*)(void);

    /**
     * @brief AssertHandler 설정
     * 
     * @param newHandler 교체할 assert_handler
     * @return assert_handler 이전 assert_handler
     */
    assert_handler SetAssertHandler(assert_handler newHandler);


    /**
     * @brief Log를 작성하는 함수
     * 
     * @param message 작성할 메시지
     * @param outStream Log를 출력할
     * @param location Log함수를 발생시킨 위치 정보. 일반적으로는 기본값으로 사용하면 된다.
     */
    inline void Log(const StringView message, std::ostream& outStream = std::clog, const std::source_location& location = std::source_location::current())
    {
        outStream << std::format("[{} ${}:{}]{}\n", location.file_name(), location.line(), location.column(), message);
    }
    /**
     * @brief condition이 참이면 assertHandler에 등록된 Assert를 발생시킨다.
     * 
     * @param condition Assert가 발생하는 조건. false면 발생
     * @param message Assert에 대한 메시지
     * @param outStream Log를 출력할 ostream
     * @param location Assert함수를 발생시킨 위치 정보. 일반적으로는 기본값으로 사용하면 된다
     */
    void Assert(bool condition, StringView message, std::ostream& outStream = std::cerr, const std::source_location& location = std::source_location::current());
}