#include "application.h"

Application::Application() {}
Application::~Application() {}

void Application::Init()
{
    std::cout << "Welcome to my Brainf*ck Interpeter!" << '\n'
            << "(written in cpp by Yoav Shifman, all rights reserved)" << '\n';
}

void Application::Mainloop()
{
    while(1)
    { // MAIN LOOP

        std::string inp = m_CmdLine.HandleInput();

        m_Parser.SetString(inp);

        Operation* op = m_Parser.Parse();

        m_Brainfuck.ApplyAll(op);
        std::cout << '\n';
        
        m_Brainfuck.Reset();
        

        delete op;

    } // END MAIN LOOP
}

void Application::Destory() {}