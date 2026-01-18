CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Isrc

SRC = \
    src/lexer/lexer.cpp \
    src/token/token.cpp \
    src/lexer/lexer_test.cpp

lexer_test: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o lexer_test

clean:
	rm -f lexer_test
