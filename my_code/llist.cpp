#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (nd) cout << nd->data;
	else cout << "nullptr";
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
		cout << endl;
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

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head) {
	if (head) {
		Node* secondNode = head->next;
		delete head;
		head = secondNode;
		return true;
	}
	return false;
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& head) {
	if (head) {
		Node* curr = head;
		if (curr->next) {
			while (curr->next->next) {
				curr = curr->next;
			}
			delete curr->next;
			curr->next = nullptr;
			return true;
		}
		delete head;
		head = nullptr;
		return true;
	}
	return false;

}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head) {
	if (head) {
		Node* list = new Node(head->data);
		Node* curr = head;
		Node* temp = list;
		while (curr->next) {
			curr = curr->next;
			list->next = new Node(curr->data);
			list = list->next;
		}
		list = temp;
		return list;
	}
	return head;
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next) {
	if (!curr) return nullptr;
	if (!curr->next) return new Node(curr->data);
	Node* reversed = reverse(curr->next, curr);
	add_at_end(reversed, curr->data);
	return reversed;
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2) {
	if (list1) {
		Node* curr1 = list1;
		while (curr1->next) curr1 = curr1->next;
		if (list2) {
			Node* curr2 = list2;
			curr1->next = curr2;
			while (curr2->next) {
				curr1 = curr2->next;
				curr2 = curr2->next;
			}
		}
		return list1;
	}
	return list2;
}