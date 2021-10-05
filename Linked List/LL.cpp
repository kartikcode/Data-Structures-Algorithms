#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node* next; 

    // self referential class
	node(int d): data(d), next(NULL){

    }
};

// function to calculate length of LL
int length(node* head) {

	int count = 0;
	while (head) {
		count++;
		head = head -> next;
	}
	return count;
}

// recursive function to calculate length of LL
int lengthRec(node* head) {

	// base case
	if (!head) { 
		return 0;
	}

	// recursive case
	return 1 + lengthRec(head->next);
}

/////////////// INSERTION FUNCTIONS ///////////////
void insertAtFront(node* &head, node* &tail, int data) {

	node* n = new node(data);
	if (head == NULL) {
		// inserting the first node
		head = tail = n;
	}
	else {
		// we have the LL already
		n->next = head;
		head = n;
	}
}

void insertAtEnd(node* &head, node* &tail, int data) {

	node* n = new node(data);
	if (head == NULL) {
		// inserting the first node
		head = tail = n;
	}
	else {
		// we have the LL already
		tail -> next = n;
		tail = n;
	}
}

void insertAtMid(node* &head, node* &tail, int data, int pos) {
	if (pos == 0) {
		insertAtFront(head, tail, data);
	}
	else if (pos >= length(head) - 1) {
		insertAtEnd(head, tail, data);
	}
	else {
		node* temp = head;
		node* n = new node(data);
		for (int i = 1 ; i <= pos - 1 ; i++) {
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}
}

// function to print LL
void printLL(node* head) {
	while (head) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL" << endl;
}


/////////////// DELETION FUNCTIONS ///////////////
void deleteAtFront(node* &head, node* &tail) {
	if (head == NULL) {
		return;
	}
	else if (head->next == NULL) {
		delete head;
		head = tail = NULL;
	}
	else {
		node* n = head;
		head = head->next;
		delete n;
	}
}

void deleteAtEnd(node* &head, node* &tail) {
	if (head == NULL) {
		return;
	}
	else if (head->next == NULL) {
		delete head;
		head = tail = NULL;
	}
	else {
		node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail -> next = NULL;
	}
}

void deleteAtMid(node* &head, node* &tail, int pos) {
	if (pos == 0) {
		deleteAtFront(head, tail);
	}
	else if (pos >= length(head) - 1) {
		deleteAtEnd(head, tail);
	}
	else {
		node* temp = head;
		for (int i = 1 ; i < pos ; i++) {
			temp = temp->next;
		}
		node* n = temp->next;
		temp->next = n->next;
		delete n;
	}
}


/////////////// SEARCHING ///////////////
node* searchRec(node* head, int key) {
	// base case
	if (!head) {
		return NULL;
	}

	// recursive case
	if (head -> data == key) {
		return head;
	}

	return searchRec(head->next, key);
}

node* searchIterative(node* head, int key) {
	while (head) {
		if (head->data == key) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}

// find mid without calculating the length
// fast and slow pointers
node* mid(node* head) {
	if (!head) {
		return head;
	}
	node* fast = head->next, *slow = head;

	while (fast and fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* head = NULL, *tail = NULL;
	// insertAtFront(head,tail,1);
	// insertAtFront(head,tail,2);
	// insertAtFront(head,tail,3);
	insertAtEnd(head, tail, 1);
	insertAtEnd(head, tail, 2);
	insertAtEnd(head, tail, 3);
	insertAtEnd(head, tail, 4);
	// printLL(head);
	insertAtMid(head, tail, 5, 2);
	// printLL(head);
	insertAtMid(head, tail, 6, 0);
	printLL(head);
	cout << lengthRec(head) << endl;
	node * ans = searchRec(head, 4);
	if (ans != NULL) {
		// node is found
		cout << "Node Found " << ans->data << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
	ans = searchIterative(head, 4);
	if (ans != NULL) {
		// node is found
		cout << "Node Found " << ans->data << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
	deleteAtFront(head, tail);
	printLL(head);
	ans = mid(head);
	if (ans != NULL) {
		// node is found
		cout << "Middle Found " << ans->data << endl;
	}
	else {
		cout << "Not Found" << endl;
	}
	// cout<<length(head)<<endl;
	// printLL(head);
	// deleteAtFront(head,tail);
	// deleteAtFront(head,tail);
	// printLL(head);
	// deleteAtEnd(head,tail);
	// deleteAtEnd(head,tail);
	// printLL(head);
	// deleteAtMid(head,tail,0);
	// printLL(head);

	return 0;
}