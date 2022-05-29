#pragma once

#include <vector>
#include <map>

enum class OpCode {
    TOP,
	OPEN_BRACKET, CLOSE_BRACKET, RIGHT, LEFT, PLUS, MINUS, DOT, COMMA,
    CNT,
};



class Operation
{
public:
    const static std::map<char, OpCode> ops_map;

    Operation(const OpCode& opCode);
    ~Operation();

	inline OpCode GetOpCode() const { return m_OpCode; }

	auto GetIterator() const;

	std::vector<Operation*>& GetChildren();

private:
	OpCode m_OpCode;
	
	std::vector<Operation*> m_Children;
};
