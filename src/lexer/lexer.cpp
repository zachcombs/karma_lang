#include "lexer/lexer.hpp"
#include "token/token.hpp"

namespace lexer
{
    Lexer::Lexer(std::string_view input) : input(input)
    {
        readChar();
    }

    void Lexer::readChar()
    {
        if (readPosition >= static_cast<int>(input.size()))
        {
            ch = 0;
        }
        else
        {
            ch = input[readPosition];
        }
        position = readPosition;
        readPosition++;
    }

    token::Token Lexer::NextToken()
    {
        token::Token tok{};

        switch (ch)
        {
        case '=':
            tok = newToken(token::ASSIGN, ch);
            break;
        case ';':
            tok = newToken(token::SEMICOLON, ch);
            break;
        case '(':
            tok = newToken(token::LPAREN, ch);
            break;
        case ')':
            tok = newToken(token::RPAREN, ch);
            break;
        case '{':
            tok = newToken(token::LBRACE, ch);
            break;
        case '}':
            tok = newToken(token::RBRACE, ch);
            break;
        case ',':
            tok = newToken(token::COMMA, ch);
            break;
        case '+':
            tok = newToken(token::PLUS, ch);
            break;
        case 0:
            tok.literal = "";
            tok.type = token::END_OF_FILE;
            break;

        default:
            if (isLetter(ch))
            {
                tok.literal = readIdentifier();
                tok.type = token::LookupIdent(tok.literal);
                return tok;
            }
            else
            {
                tok = newToken(token::ILLEGAL, ch);
            }
            break;
        }

        readChar();
        return tok;
    }

    token::Token Lexer::newToken(token::TokenType tokenType, char ch)
    {
        token::Token tok{};
        tok.type = tokenType;
        tok.literal = std::string(1, ch);

        return tok;
    }

    std::string Lexer::readIdentifier()
    {
        int start = position;

        while (isLetter(ch))
        {
            readChar();
        }

        return input.substr(start, position - start);
    }

    bool Lexer::isLetter(char ch)
    {
        return ('a' <= ch && ch <= 'z') ||
               ('A' <= ch && ch <= 'Z') ||
               (ch == '_');
    }
}