#ifndef TOKENSTREAM_H
#define TOKENSTREAM_H
#include "Token.h"

const char number = '0';
const char quit = 'q';
const char print = ';';

class TokenStream {
private:
	bool full;
	Token buffer;

public:
	TokenStream() : full(false), buffer(0) {};
	Token get();
	void putback(Token t);
	void ignore(char c);
};

#endif