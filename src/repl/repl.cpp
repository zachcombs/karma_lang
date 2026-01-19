#include <string>
#include <iostream>

#include "repl.hpp"
#include "lexer/lexer.hpp"
#include "token/token.hpp"

namespace repl
{
    const std::string prompt = ">> ";

    void Start(std::istream &in, std::ostream &out)
    {
        std::string line;

        while (true)
        {
            out << prompt;
            out.flush();

            if (!std::getline(in, line))
            {
                return;
            }

            lexer::Lexer l(line);

            for (token::Token tok = l.NextToken();
                 tok.type != token::END_OF_FILE;
                 tok = l.NextToken())
            {
                out << "Token{ type=" << tok.type << ", literal=\"" << tok.literal << "\" }\n";
            }
        }
    }
}