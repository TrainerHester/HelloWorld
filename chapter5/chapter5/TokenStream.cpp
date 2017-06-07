#include "TokenStream.h"
#include "std_lib_facilities.h"

Token TokenStream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case quit:
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '{':
	case '}':
		return Token(ch);
	case '.':
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9': 
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('0', val);
	}
	default:
		error("Bad Token!");
	}
}

void TokenStream::putback(Token t) {
	if (full) {
		error("putback into a full buffer");
	}
	buffer = t;
	full = true;
}

void TokenStream::ignore(char c) {
	if (full && c == buffer.type) {
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while (cin >> ch) {
		if (ch == c) {
			return;
		}
	}
}