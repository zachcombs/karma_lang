#include "repl/repl.hpp"

#include <iostream>
#include <string>

#if defined(__UNIX__) || defined(__APPLE__)
#include <unistd.h>
#include <pwd.h>
#endif

int main()
{
    std::string username = "there";

#if defined(__UNIX__) || defined(__APPLE__)
    if (passwd pw = getpwuid(getuid))
    {
        username = pw->pw_name;
    }
#endif

    std::cout << "Hello" << username << "! This is the Karma programming language!\n";
    std::cout << "Feel free to type in commands\n";

    repl::Start(std::cin, std::cout);

    return 0;
}