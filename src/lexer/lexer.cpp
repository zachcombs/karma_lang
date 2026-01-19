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

        skipWhitespace();

        switch (ch)
        {
        case '=':
            if (peekChar() == '=')
            {
                char first = ch;
                readChar();
                std::string literal;
                literal.push_back(first);
                literal.push_back(ch);
                tok = newToken(token::EQ, literal);
            }
            else
            {
                tok = newToken(token::ASSIGN, ch);
            }
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
        case '-':
            tok = newToken(token::MINUS, ch);
            break;
        case '!':
            if (peekChar() == '=')
            {
                char first = ch;
                readChar();
                std::string literal;
                literal.push_back(first);
                literal.push_back(ch);
                tok = newToken(token::NOT_EQ, literal);
            }
            else
            {
                tok = newToken(token::BANG, ch);
            }
            break;
        case '/':
            tok = newToken(token::SLASH, ch);
            break;
        case '*':
            tok = newToken(token::ASTERISK, ch);
            break;
        case '<':
            tok = newToken(token::LT, ch);
            break;
        case '>':
            tok = newToken(token::GT, ch);
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
            else if (isDigit(ch))
            {
                tok.type = token::INT;
                tok.literal = readNumber();
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

    token::Token Lexer::newToken(token::TokenType tokenType, std::string literal)
    {
        token::Token tok{};
        tok.type = tokenType;
        tok.literal = std::move(literal);

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

    bool Lexer::isDigit(char ch)
    {
        return '0' <= ch && ch <= '9';
    }

    void Lexer::skipWhitespace()
    {
        while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
        {
            readChar();
        }
    }

    std::string Lexer::readNumber()
    {
        int start = position;

        while (isDigit(ch))
        {
            readChar();
        }

        return input.substr(start, position - start);
    }

    char Lexer::peekChar()
    {
        if (readPosition >= static_cast<int>(input.size()))
        {
            return 0;
        }
        else
        {
            return input[readPosition];
        }
    }
}