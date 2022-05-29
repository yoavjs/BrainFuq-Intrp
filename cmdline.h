#pragma once

#include <iostream>
#include <string>

class CmdLine
{
public:

    CmdLine();

    const char* HandleInput() const;

private:

    const static char* PREFIX;
    const static int MAX_CMD_LENGTH;
};