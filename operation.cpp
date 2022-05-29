#include "operation.h"

const std::map<char, OpCode> Operation::ops_map = {
        {'[', OpCode::OPEN_BRACKET},
        {']', OpCode::CLOSE_BRACKET},
        {'>', OpCode::RIGHT},
        {'<', OpCode::LEFT},
        {'+', OpCode::PLUS},
        {'-', OpCode::MINUS},
        {'.', OpCode::DOT},
        {',', OpCode::COMMA}
};

Operation::Operation(const OpCode& opCode) {
    m_OpCode = opCode;
}

Operation::~Operation() {
    for (auto op : m_Children) delete op;
    m_Children.clear();
}

auto Operation::GetIterator() const
{
	return m_Children.begin();
}

std::vector<Operation*>& Operation::GetChildren()
{
	return m_Children;
}