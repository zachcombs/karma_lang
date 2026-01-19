#include "lexer/lexer.hpp"
#include "token/token.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct Expected
{
    token::TokenType type;
    std::string literal;
};

int main()
{
    std::string input =
        "let five = 5;\n"
        "let ten = 10;\n"
        "\n"
        "let add = fn(x, y) {\n"
        "    x + y;\n"
        "};\n"
        "\n"
        "let result = add(five, ten);\n"
        "!-/*5;\n"
        "5 < 10 > 5;\n"
        "\n"
        "if (5 < 10) {\n"
        "   return true;\n"
        "} else {\n"
        "   return false;\n"
        "}\n"
        "\n"
        "10 == 10;\n"
        "10 != 9;\n"
        "\n";

    std::vector<Expected> tests = {
        {token::LET, "let"},
        {token::IDENT, "five"},
        {token::ASSIGN, "="},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "ten"},
        {token::ASSIGN, "="},
        {token::INT, "10"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "add"},
        {token::ASSIGN, "="},
        {token::FUNCTION, "fn"},
        {token::LPAREN, "("},
        {token::IDENT, "x"},
        {token::COMMA, ","},
        {token::IDENT, "y"},
        {token::RPAREN, ")"},
        {token::LBRACE, "{"},
        {token::IDENT, "x"},
        {token::PLUS, "+"},
        {token::IDENT, "y"},
        {token::SEMICOLON, ";"},
        {token::RBRACE, "}"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "result"},
        {token::ASSIGN, "="},
        {token::IDENT, "add"},
        {token::LPAREN, "("},
        {token::IDENT, "five"},
        {token::COMMA, ","},
        {token::IDENT, "ten"},
        {token::RPAREN, ")"},
        {token::SEMICOLON, ";"},
        {token::BANG, "!"},
        {token::MINUS, "-"},
        {token::SLASH, "/"},
        {token::ASTERISK, "*"},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::INT, "5"},
        {token::LT, "<"},
        {token::INT, "10"},
        {token::GT, ">"},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::IF, "if"},
        {token::LPAREN, "("},
        {token::INT, "5"},
        {token::LT, "<"},
        {token::INT, "10"},
        {token::RPAREN, ")"},
        {token::LBRACE, "{"},
        {token::RETURN, "return"},
        {token::TRUE, "true"},
        {token::SEMICOLON, ";"},
        {token::RBRACE, "}"},
        {token::ELSE, "else"},
        {token::LBRACE, "{"},
        {token::RETURN, "return"},
        {token::FALSE, "false"},
        {token::SEMICOLON, ";"},
        {token::RBRACE, "}"},
        {token::INT, "10"},
        {token::EQ, "=="},
        {token::INT, "10"},
        {token::SEMICOLON, ";"},
        {token::INT, "10"},
        {token::NOT_EQ, "!="},
        {token::INT, "9"},
        {token::SEMICOLON, ";"},
        {token::END_OF_FILE, ""}};

    lexer::Lexer l(input);

    for (size_t i = 0; i < tests.size(); ++i)
    {
        token::Token tok = l.NextToken();

        if (tok.type != tests[i].type)
        {
            std::cerr << "tests[" << i << "] - tokenType wrong. expected \""
                      << tests[i].type << "\", got=\"" << tok.type << "\"\n";

            return 1;
        }

        if (tok.literal != tests[i].literal)
        {
            std::cerr << "tests[" << i << "] - literal wrong. expected \""
                      << tests[i].literal << "\", got=\"" << tok.literal << "\"\n";

            return 1;
        }
    }

    std::cout << "PASS\n";
    return 0;
}