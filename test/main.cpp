#include <ysLog.hpp>
#include <fstream>

void NewHandler()
{
    std::cout << "NEW HANDLER!!!" << std::endl;
}

int main()
{
    YS::assert_handler handler;
    std::ofstream ofs("log.txt");
    handler = YS::SetAssertHandler(NewHandler);

    YS::Log("Log Message.", ofs);
    YS::Assert(false, "Assert Message.", ofs);
    ofs.close();
    YS::SetAssertHandler(handler);
    YS::Assert(false, "Assert Message.", ofs);
}