#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
inline void keep_window_open(string s) { 
	cout << "Please enter " + s + " to exit\n";
	string ch; 
	while (cin >> ch) {
		if (ch == s)
			break;
	}
}
inline void error(string s) { throw runtime_error(s); }