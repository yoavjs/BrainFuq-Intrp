#include "cmdline.h"

const char* CmdLine::PREFIX = "$$ ";
const long long int CmdLine::MAX_CMD_LENGTH = 1 << 8;


CmdLine::CmdLine() {}

const char* CmdLine::HandleInput() const {
    // Clear buffer
    memset(m_Cmd, 0, CmdLine::MAX_CMD_LENGTH);

    std::cout << CmdLine::PREFIX;
    
    std::cin.getline(m_Cmd, CmdLine::MAX_CMD_LENGTH);

    return m_Cmd;
}