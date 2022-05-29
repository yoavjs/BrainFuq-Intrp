#include "brainfuck.h"

Brainfuck::Brainfuck() {}

void Brainfuck::ApplyAll(Operation* &top){
    for (Operation* &op : top->GetChildren()) {
        // LOOP Impl
        if ((*op).GetOpCode() == OpCode::OPEN_BRACKET)
        {
            while((*m_It) != 0) {
                ApplyOperation(*op);
                ApplyAll(op);
            }
            continue;
        }
        // ELSE
        ApplyOperation(*op);
    }
}

void Brainfuck::ApplyOperation(const Operation& op)
{
	switch (op.GetOpCode())
    {
    case OpCode::OPEN_BRACKET:
        {
            if ((*m_It) > 0)
                (*m_It)--;
        }
	case OpCode::RIGHT:
        {
            if (m_It == m_Mem.end())
                m_Mem.push_back(0);
            m_It++;

            break;
        }
    case OpCode::LEFT:
        {
            if (m_It == m_Mem.begin())
                m_Mem.push_front(0);
            m_It--;

            break;
        }
    case OpCode::PLUS:
        {
            (*m_It)++;

            break;
        }
    case OpCode::MINUS:
        {
            (*m_It)--;

            break;
        }
    case OpCode::DOT:
        {
            char chr = ((*m_It) & 0xFF);
            std::cout << chr;

            break;
        }
    case OpCode::COMMA:
        {
            char chr = getchar();
            (*m_It) = chr;

            break;
        }
    default: // this is not getting called since parser is removing all other characters
        {
            break;
        }
	}
}