#pragma once

#include <iostream>

#include "brainfuck.h"
#include "cmdline.h"
#include "parser.h"

class Application
{
public:

    Application();
    ~Application();

    void Init();
    void Mainloop();
    void Destory();

private:

    CmdLine m_CmdLine;
    Brainfuck m_Brainfuck;
    Parser m_Parser;
};