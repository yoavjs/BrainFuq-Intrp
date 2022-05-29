#pragma once

#include <string.h>

#include <iostream>
#include <string>

class CmdLine
{
public:

    CmdLine();

    const char* HandleInput() const;

private:

    const static char* PREFIX;
    const static long long int MAX_CMD_LENGTH;

    char* m_Cmd = new char[CmdLine::MAX_CMD_LENGTH];
};