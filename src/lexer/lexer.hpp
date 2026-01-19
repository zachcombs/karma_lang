#pragma once

#include "token/token.hpp"
#include <string>
#include <string_view>

namespace lexer
{
    struct Lexer
    {
        std::string input;
        int position = 0;
        int readPosition = 0;
        char ch = 0;

        explicit Lexer(std::string_view input);

        void readChar();
        token::Token NextToken();

    private:
        token::Token newToken(token::TokenType, char ch);
        std::string readIdentifier();
        static bool isLetter(char ch);
        void skipWhitespace();
        std::string readNumber();
        static bool isDigit(char ch);
    };
}