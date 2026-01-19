CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Isrc

COMMON_SRC = \
    src/lexer/lexer.cpp \
    src/token/token.cpp \
    src/repl/repl.cpp

TEST_SRC = \
    $(COMMON_SRC) \
    src/lexer/lexer_test.cpp

APP_SRC = \
    $(COMMON_SRC) \
    src/main.cpp

lexer_test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o lexer_test

karma: $(APP_SRC)
	$(CXX) $(CXXFLAGS) $(APP_SRC) -o karma

clean:
	rm -f lexer_test karma
