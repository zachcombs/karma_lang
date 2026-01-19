#include "token/token.hpp"

namespace token
{
    static const std::unordered_map<std::string_view, TokenType> keywords{
        {"fn", FUNCTION},
        {"let", LET},
        {"true", TRUE},
        {"false", FALSE},
        {"if", IF},
        {"else", ELSE},
        {"return", RETURN}};

    TokenType LookupIdent(std::string_view ident)
    {
        auto it = keywords.find(ident);
        if (it != keywords.end())
        {
            return it->second;
        }

        return IDENT;
    }
}