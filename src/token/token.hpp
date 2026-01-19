#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

namespace token
{
    using TokenType = std::string_view;

    struct Token
    {
        TokenType type;
        std::string literal;
    };

    inline constexpr TokenType ILLEGAL = "ILLEGAL";
    inline constexpr TokenType END_OF_FILE = "EOF";
    inline constexpr TokenType IDENT = "IDENT";
    inline constexpr TokenType INT = "INT";

    inline constexpr TokenType ASSIGN = "=";
    inline constexpr TokenType PLUS = "+";
    inline constexpr TokenType MINUS = "-";
    inline constexpr TokenType BANG = "!";
    inline constexpr TokenType ASTERISK = "*";
    inline constexpr TokenType SLASH = "/";

    inline constexpr TokenType LT = "<";
    inline constexpr TokenType GT = ">";

    inline constexpr TokenType COMMA = ",";
    inline constexpr TokenType SEMICOLON = ";";
    inline constexpr TokenType LPAREN = "(";
    inline constexpr TokenType RPAREN = ")";
    inline constexpr TokenType LBRACE = "{";
    inline constexpr TokenType RBRACE = "}";

    inline constexpr TokenType FUNCTION = "FUNCTION";
    inline constexpr TokenType LET = "LET";
    inline constexpr TokenType TRUE = "TRUE";
    inline constexpr TokenType FALSE = "FALSE";
    inline constexpr TokenType IF = "IF";
    inline constexpr TokenType ELSE = "ELSE";
    inline constexpr TokenType RETURN = "RETURN";

    TokenType LookupIdent(std::string_view ident);
}