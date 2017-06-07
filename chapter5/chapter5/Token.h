#ifndef TOKEN_H
#define TOKEN_H

class Token {
public:
	char type;
	double value;
public:
	Token(char ch, double val) : type(ch), value(val) {}
	Token(char ch) : type(ch), value(0) {}
};

#endif