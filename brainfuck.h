#pragma once

#include <iostream>
#include <string>
#include <deque>

#include "operation.h"

class Brainfuck
{
public:

    Brainfuck();

    void ApplyAll(Operation* &top);

	void ApplyOperation(const Operation& op);

private:
    std::string inp;

	std::deque<int>::iterator m_It;
	std::deque<int> m_Mem;
};