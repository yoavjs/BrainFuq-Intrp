#pragma once

#include <conio.h>

#include <iostream>
#include <string>
#include <deque>

#include "operation.h"

class Brainfuck
{
public:

    Brainfuck();

    void Print();

    void Reset();

    void ApplyAll(Operation* &top);

	void ApplyOperation(const Operation& op);

private:

	std::deque<char>::iterator m_It;
	std::deque<char> m_Mem;
};