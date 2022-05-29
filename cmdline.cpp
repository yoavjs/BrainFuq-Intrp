#include "cmdline.h"

const char* CmdLine::PREFIX = "$$ ";
const int CmdLine::MAX_CMD_LENGTH = 1 << 16;


CmdLine::CmdLine() {}

const char* CmdLine::HandleInput() const {
    std::cout << CmdLine::PREFIX;

    char* cmd = new char[CmdLine::MAX_CMD_LENGTH];
    std::cin.getline(cmd, CmdLine::MAX_CMD_LENGTH);

    return cmd;
}