#include "std_lib_facilities.h"
#include "TokenStream.h"

double expression(TokenStream & ts);
double term(TokenStream & ts);
double primary(TokenStream & ts);
void calculator();
void clear_up_mess(TokenStream & ts);
const string prompt = ">";
const string result = "=";

int main() {
	try {
		calculator();
		keep_window_open("~");
		return 0;
	}
	catch (exception & e) {
		cerr << "error:" << e.what() << "\n";
		keep_window_open("~");
		return 1;
	}
	catch (...) {
		cerr << "Oops: unkonwn exception!\n";
		keep_window_open("~");
		return 2;
	}
	
}

void calculator() {
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n";
	TokenStream ts = TokenStream();
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.type == print) t = ts.get();
			if (t.type == quit) {
				return;
			}
			ts.putback(t);
			cout << result << expression(ts) << endl;
		}
		catch (exception & e){
			cerr << e.what() << endl;
			clear_up_mess(ts);
		}
	}
}

void clear_up_mess(TokenStream & ts) {
	ts.ignore(print);
}

double expression(TokenStream & ts) {
	double left = term(ts);
	Token t = ts.get();
	while (true) {
		switch (t.type) {
		case'+':
			left += term(ts);
			t = ts.get();
			break;
		case '-':
			left -= term(ts);
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term(TokenStream & ts) {
	double left = primary(ts);
	Token t = ts.get();
	while (true) {
		switch (t.type) {
		case '*':
			left *= primary(ts);
			t = ts.get();
			break;
		case '/': {
					  double val = primary(ts);
					  if (val == 0) {
						  error("Divisor is zers!");
					  }
					  else {
						  left /= val;
						  t = ts.get();
						  break;
					  }
		}
		default:
			ts.putback(t);
			return left;
		}
	}

}

double primary(TokenStream & ts) {
	Token t = ts.get();
	switch (t.type) {
	case number:
		return t.value;
	case '(': {
				  double d = expression(ts);
				  t = ts.get();
				  if (t.type != ')') {
					  error("')' expected!");
				  }
				  return d;
	}
	case '{': {
				  double d = expression(ts);
				  t = ts.get();
				  if (t.type != '}') {
					  error("'}' expected!");
				  }
				  return d;
	}
	case '-':
		return -primary(ts);
	case '+':
		return primary(ts);
	default:
		error("primary expected!");
	}
}