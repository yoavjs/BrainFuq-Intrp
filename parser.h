#pragma once

#include <iostream>
#include <string>

#include "operation.h"

class Parser
{
public:

    Parser();

    void SetString(const std::string& str);

    Operation* Parse() const;

private:

    void m_Rec_Parse(size_t& ind, Operation* &op) const;

    std::string m_Cmd;
};