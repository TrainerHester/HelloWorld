// NESTED.H -- Nested struct in linked list
#ifndef NESTED_H
#define NESTED_H

struct stack {
	struct link {
		void* data;
		link* next;
		void initialize(void* data, link* next);
	}* head;

	void initialize();
	void push(void* data);
	void* peek();
	void* pop();
	void clearup();
};

#endif