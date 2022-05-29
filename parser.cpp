#include "parser.h"

Parser::Parser() {}

void Parser::SetString(const std::string& str) {
    m_Cmd = str;
}

void Parser::m_Rec_Parse(size_t& ind, Operation* &op) const {
    if (ind >= m_Cmd.size()) return;
    char ch = m_Cmd[ind];
    // Operation not permitted - parsing as comment
    while (ind != m_Cmd.size())
    {
        if (Operation::ops_map.find(ch) != Operation::ops_map.end())
        {
            ind++;
            Operation* newOp = new Operation(Operation::ops_map.at(ch));
            if (newOp->GetOpCode() == OpCode::CLOSE_BRACKET)
                return;
            
            (*op).GetChildren().push_back(newOp);

            if (newOp->GetOpCode() == OpCode::OPEN_BRACKET)
                m_Rec_Parse(ind, newOp);
        }
    }
}

Operation* Parser::Parse() const {
    Operation* op = new Operation(OpCode::TOP);
    
    size_t ind = 0;
    m_Rec_Parse(ind, op);

    return op;
}