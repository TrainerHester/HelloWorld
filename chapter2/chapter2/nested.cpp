// nested.cpp linked list with nesting.
#include <stdlib.h>
#include <assert.h>
#include "stdafx.h"
#include "nested.h"

void stack::link::initialize(void* data, link* next) {
	this->data = data;
	this->next = next;
}

void stack::initialize() {
	head = 0;
}

void stack::push(void* data) {
	link* newlink = (link*)malloc(sizeof(link));
	assert(newlink);
	newlink->initialize(data, head);
	head = newlink;
}

void* stack::peek() {
	return head->data;
}

void* stack::pop() {
	if (head == 0) {
		return 0;
	}
	void* result = head->data;
	link* oldHead = head;
	head = head->next;
	free(oldHead);
	return result;
}

void stack::clearup() {
	/*while (!head) {
		pop();
	}*/
	link* cursor = head;
	while (head) {
		cursor = cursor->next;
		free(head->data);
		free(head);
		head = cursor;
	}
}
