#include "iostream"

using namespace std;
char en = '\n'; // easy new line type on keyboard

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	Node* head;
	
public:
	// LinkedList() {
		// head = NULL;
	// }
	LinkedList() : head(NULL) {}
	
	// Insert new node at the beginning of the list
	void insertAtBeginning(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}
	
	// Insert new node at the end of the list
	void insertAtEnd(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = NULL;
		
		// in case of new node, update the head to new node
		if (!head) {
			head = newNode;
			return;
		}
		
		// traverse to the last node
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		
		// update the last node's next to the new node
		temp->next = newNode;
	}
	
	// insert a new node at a specific position in the list
	void insertAtPosition(int value, int position) {
		if (position < 1) {
			cout<< "Position should be >=1. "<< en;
			return;
		}
		
		if (position == 1) {
			insertAtBeginning(value);
			return;
		}
		
		Node* newNode = new Node();
		newNode->data = value;
		
		//traverse to the node before the desired position
		Node* temp = head;
		for (int i = 1; i< position -1 && temp; i++) {
			temp = temp->next;
		}
		
		if(!temp) {
			cout << "position out of range.\n";
			delete newNode;
			return;
		}
		
		// insert new node at desired position
		newNode->next = temp->next;
		temp->next = newNode;
	}
	
	// delete the first node of the list
	void deleteFromBeginning () {
		if(!head) {
			cout<< "list is empty. \n";
			return;
		}
		
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
	// Delete the last node of the list
	void deleteFromEnd () {
		if(!head){
			cout<< "List is empty."<< en;
			return;
		}
		
		if (!head->next) {
			delete head;
			head = NULL;
			return;
		}
		
		// Traverse to the second to last node
		Node* temp = head;
		while (temp->next->next) {
			temp = temp->next;
		}
		
		// Delete the last node
		delete temp ->next;
		// set the second to last node's next to NULL
		temp->next = NULL;
	}
	
	// Delete a node at a specific position in the list
	void deleteFromPosition (int position) {
		if (position < 1) {
			cout<< "Position should be >= 1."<< en;
			return;
		}
		
		if (position == 1) {
			deleteFromBeginning();
			return;
		}
		
		Node* temp = head;
		for (int i = 1; i < position -1 && temp; i++) {
			temp = temp->next;
		}
		
		if (!temp || !temp->next){
			cout<< "Position out of range." << en;
			return;
		}
		
		// save the node to be deleted
		Node* nodeToDelete = temp->next;
		// update the next pointer
		temp->next = temp->next->next;
		// Delete the node
		delete nodeToDelete;
	}
	
	// Print the nods of the linked list
	void display() {
		if (!head) {
			cout << "List is empty." << en;
			return;
		}
		
		Node* temp = head;
		while (temp) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		
		cout << "NULL"<< en;
	}
};





int main() {
	
	LinkedList list;
	
	int ans, num, pos;
	bool loop = true;
	while (loop) {
		cout << "Choose what to do." << en;
		cout << "1. Insert at the beginning." << en;
		cout << "2. Insert at a position." << en;
		cout << "3. Insert at the end." << en;
		cout << "4. Delete from beginning." << en;
		cout << "5. Delete from a position." << en;
		cout << "6. Delete from end." << en;
		cout << "7. Display" << en;
		cout << "8. exit!" << en;
		cin >> ans;
		if (ans>=1 && ans <=3){
			cout<< "Enter the number: ";
			cin>> num;
		}
		if (ans==2 || ans == 5) {
			cout<< "Enter the position: ";
			cin>> pos;
		}
		switch (ans) {
			case 1:
				list.insertAtBeginning(num);
				break;
			case 2:
				list.insertAtPosition(num, pos);
				break;
			case 3:
				list.insertAtEnd(num);
				break;
			case 4:
				list.deleteFromBeginning();
				break;
			case 5:
				list.deleteFromPosition(pos);
				break;
			case 6:
				list.deleteFromEnd();
				break;
			case 7:
				list.display();
				break;
			default:
				loop = false;
				break;
		}
		cout << en;
	}
	
	return 0;
}


