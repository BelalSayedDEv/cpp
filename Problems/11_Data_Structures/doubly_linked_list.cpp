
#include <iostream>

using namespace std;


//class Node
//{
//public:
//
//	int data;
//	Node* next;
//
//private:
//
//};
//
//void Insertatbegaining(Node* &head, int value) {
//
//	Node* new_node = new Node();
//
//	new_node->data = value;
//	new_node->next = head;
//
//	head = new_node;
//
//}
//void PrintNode(Node* head) {
//
//	while (head != NULL) {
//		cout << head->data << endl;
//		head = head->next;
//	}
//}
//
//void InsertatEnd(Node*& head, int value) {
//
//	Node* new_node = new Node();
//	new_node->data = value;
//	new_node->next = NULL;
//
//	if (head == NULL) {
//		head = new_node;
//		return;
//	}
//
//	Node* LastNode = head;
//
//	while (LastNode->next != NULL) {
//
//		LastNode = LastNode->next;
//	}
//
//	LastNode->next = new_node;
//	return;
//
//
//	/*Node* new_node = new Node();
//
//	new_node->data = value;
//	new_node->next = head;
//
//	head = new_node;*/
//
//}
//
//void DeleteFirstNode(Node*& head) {
//
//	Node* Current = head;
//	if (head == NULL) {
//		cout << "Linked List is empty" << endl;
//		return;
//	}
//	head = head->next;
//	delete Current;
//	return;
//
//}
//
//void deleteLastNode(Node*& head) {
//
//	if (head == NULL) {
//		cout << "Linked List is empty" << endl;
//		return;
//	}
//	Node* Previous = head;
//	Node* Current = head;
//
//	while (Current != NULL && Current->next != NULL) {
//
//		Previous = Current;
//		Current = Current -> next;
//	}
//
//	Previous->next = NULL;
//	delete Current;
//}

class Node
{
public:

	int data;
	Node* next;
	Node* prev;

private:

};

void Insertatbegaining(Node*& head, int value) {

	Node* new_Node = new Node();
	new_Node->data = value;
	new_Node->prev = NULL;
	new_Node->next = NULL;

	if (head == NULL) {
		head = new_Node;
		return;
	}
	Node* Current = head;

	if (head != NULL) {
		Current->prev = new_Node;
		new_Node->next = Current;
		head = new_Node;
		return;
	}

}



void PrintNodeDetails(Node* head)
{

	if (head->prev != NULL)
		cout << head->prev->data;
	else
		cout << "NULL";

	cout << " <--> " << head->data << " <--> ";

	if (head->next != NULL)
		cout << head->next->data << "\n";
	else
		cout << "NULL";

}

// Print the linked list

void PrintListDetails(Node* head)

{
	cout << "\n\n";
	while (head != NULL) {
		PrintNodeDetails(head);
		head = head->next;
	}
}

Node* FindNode(Node* Head, int value) {

	while (Head != NULL) {
		if (Head->data == value) {
			return Head;
		}
		Head = Head->next;
	}

}

void InsertAfter(Node* &head, int searchValue, int NewValue) {

	while (head != NULL) {

		if (head->data == searchValue)
		{
			Node* New_Node = new Node();
			New_Node->data = NewValue;

			Node* temp = head->next;

			New_Node->prev = head;
			New_Node->next = temp;


			if (temp != NULL) {
				temp->prev = New_Node;  
			}

			head->next = New_Node;
			return;
		}


		head = head->next;

	}

}

void InsertAtEnd(Node*& head, int NewValue) {

	Node* New_Node = new Node();
	New_Node->data = NewValue;
	New_Node->next = NULL;
	New_Node->prev = NULL;
	if (head == NULL) {
		head = New_Node;
		return;
	}

	Node* Current = head;

	if (Current->next == NULL) {
		Current->next = New_Node;
		New_Node->prev = Current;
		return;
	}

	while (Current->next != NULL) {
		Current = Current->next;
	}
	New_Node->prev = Current;
	Current->next = New_Node;
	return;
}

void Delete(Node* &Head, int search) {


	Node* Current = Head;
	/*Node* pre = Head;*/
	while (Current != NULL) {

		if (Current->data == search) {
			 
			Current->prev->next = Current->next;
			Current->next->prev = Current->prev;
			delete Current;
			return;
		}

		Current = Current->next;
	}
}	


void DeleteFirst(Node * & Head) {


	/*Node* Current = Head;*/
	/*Node* pre = Head;*/

	if (Head == NULL) {
		cout << "the Node is empty" << endl;
		return;
	}

	Node * Current = Head;

	if (Current->next != NULL) {
		Head = Current->next;
		Current->next->prev = NULL;
		delete Current;
		return;
	}
}

void DeleteEndNode(Node*& Head) {


	/*Node* Current = Head;*/
	/*Node* pre = Head;*/

	if (Head == NULL) {
		cout << "the Node is empty" << endl;
		return;
	}

	Node* Current = Head;

	/*if (Current->next != NULL) {
		Head = Current->next;
		Current->next->prev = NULL;
		delete Current;
		return;
	}*/

	while (Current != NULL && Current->next != NULL) {

		Current = Current->next;
	}

	Current->prev->next = NULL;
	delete Current;
	return;

}

int main()
{

	Node* Head = NULL;

	Insertatbegaining(Head, 5);
	Insertatbegaining(Head, 4);
	Insertatbegaining(Head, 3);
	Insertatbegaining(Head, 2);
	Insertatbegaining(Head, 1);

	/*PrintListDetails(Head);*/


	cout << endl << endl;
	
	DeleteEndNode(Head);

	PrintListDetails(Head);

	/*Node* N1 = FindNode(Head, 5);

	if (N1 != NULL) {
		cout << "\nNode Found" << endl;
	}
	else
	{
		cout << "\nNode Not Found" << endl;
	}
	*/
	/*Head = Node3;
	while (Head != NULL) {
		cout << Head->data << endl;
		Head = Head->prev;
	}*/
}

