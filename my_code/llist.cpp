#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (nd) {
		cout << nd->data;
	}
	return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (head) {
		Node* curr = head;
		while (curr->next) {
			curr = curr->next;
		}
		Node* end = new Node(d, nullptr);
		curr->next = end;
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	if (curr) {
		cout << curr->data << " ";
		if (curr->next) {
			Node* temp = curr->next;
			while (temp) {
				cout << temp << " ";
				temp = temp->next;
			}
		}
	}
	else cout << "Empty list" << endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	Node* newHead = new Node(d, head);
	head = newHead;
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (head)
	{
		Node* curr = head;
		while (curr->next) {
			curr = curr->next;
		}
		return curr;
	}
	return head;
}