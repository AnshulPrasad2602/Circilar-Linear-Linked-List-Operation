

//code for circular linked list having create, delete, insert & display
#include <iostream>
#include <stdlib.h>
using namespace std;

class node	//class node that contain data value and link to the next node
{
	public:
		int data;
		node *next;
};

class list
{
	public :
		node *lstptr, *temp;	//pointers to point to the first and last node
		list()	//Default constructor
		{
			lstptr = temp = NULL;
		}
		
		void create_node()	//function to create node
		{
			cout << "\n\n\tCREATE NODE OF LINKED LIST\n\n";
			
			node *newnode = new node();	//node pointer to create new node (dynamically memory allocated)
			int value;	//variable from which user will enter data
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;	//storing value to the data section of node
			if (lstptr == NULL)		//checking condition for empty
			{
				lstptr = temp = newnode;	//pointing lstpr and temp to 1st node
				newnode->next = lstptr;	//making link between last and first node
				cout << "Node created successfully";
			}
			else
			{
				for (temp = lstptr; temp->next != lstptr; temp = temp->next);
				temp->next = newnode;	//creating link between the nodes
				newnode->next = lstptr;	//next is assigned to NULL because it points to nothing
				temp = temp->next;	//temp pointing to newly linked node
				cout << "Node created successfully";
			}
		}
		
		void print_lnkdlst()	//function to print whole linked list
		{
			cout << "\n\n\tPRINT WHOLE LINKED LIST\n\n";
			
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				cout << "Elements in the linked list : ";
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next)
				{
					cout << temp1->data << " ";		//printing each value of linked list
				}
				cout << temp1->data << " ";
			}
		}
		
		void length_lnkdlst()	//function to print length of linked list
		{
			cout << "\n\n\tLENGTH OF LINKED LIST\n\n";
			
			int count = 0; 	//variable to count the node in linked list
			node *temp1;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "Linked list is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next)
				{
					count++;	//incremeting the counter
				}
				count++;	//to count last node also
				cout << "Length of the linked list is " << count;
			}
		}
		
		void insert_begnn()	//function to insert node at beginning
		{
			cout << "\n\n\tINSERT NODE AT BEGINNING\n\n";
			
			node *temp1;
			node *newnode = new node();
			int value;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = lstptr;	//making link between last and first node
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next);	//traversing till last last node
				newnode->next = lstptr;
				lstptr = newnode;
				temp1->next = lstptr;
				cout << "Node added successfully.";
			}
		}
		
		void insert_pos()	//function to insert at specified position
		{
			cout << "\n\n\tINSERT NODE AT SPECIFIED POSITION\n\n";
			
			node *newnode = new node();
			node *temp1;
			int pos;	//variable for position
			int count;
			int value;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			cout << "Enter the position : ";
			cin >> pos;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = lstptr;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next)
				{
					count++;	//incremeting the counter to count whole liked list
				}
				count++;
				if (pos > count)
				{
					cout << "Can't create the node.";
					delete newnode;
					return;
				}
				else
				{
					temp1 = lstptr;
					for (int i = 1; i < pos-1; i++)
					{
						temp1 = temp1->next;
					}
					newnode->next = temp1->next;
					temp1->next = newnode;
					cout << "Node added successfully";
				}
			}
		}
		
		void insert_end()	//function for insert at end
		{
			cout << "\n\n\tINSERT NODE AT END\n\n";
			
			int value;
			node *newnode = new node();
			node *temp1;
			
			cout << "Enter the value : ";
			cin >> value;
			newnode->data = value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				lstptr = temp = newnode;	//creates newnode
				newnode->next = lstptr;
				cout << "List was empty, new node created.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next);	//traversing till last node
				temp1->next = newnode;	//creating link between newnode and last node
				newnode->next = lstptr;
				temp1 = temp1->next;
				cout << "Node added successfully";
			}
		}
		
		void delete_node_front()	//function to delete 1st node
		{
			cout << "\n\n\tDELETE NODE FROM FRONT\n\n";
			
			node *temp1, *temp2;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp2 = lstptr; temp2->next != lstptr; temp2 = temp2->next);	//traversing till last node
				temp1 = lstptr;
				lstptr = lstptr->next;	//pointing lstptr to next node
				cout << "Deleted node had : " << temp1->data;
				delete temp1;
				temp2->next = lstptr;
			}
		}
		
		void delete_node_end()	//function to delete last node
		{
			cout << "\n\n\tDELETE NODE FROM END\n\n";
			
			node *temp1, *temp2;
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; (temp1->next)->next != lstptr; temp1 = temp1->next);	//temp1 will traverse to the second last node
				temp2 = temp1->next;
				temp1->next = lstptr;
				cout << "Deleted node had : " << temp2->data;
				delete temp2;
			}
		}
		
		void delete_node_position()	//function to delete node at specified position
		{
			cout << "\n\n\tDELETE NODE AT SPECIFIED POSITION\n\n";
			
			node *temp1, *temp2;
			int count = 0;
			int node_pos;	//variable for storing node position
			
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				cout << "Enter the node position to be deleted : ";
				cin >> node_pos;
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next)
				{
					count++;	//incremeting the counter to count whole liked list
				}
				count++;
				if (node_pos > count)
				{
					cout << "Can't delete the node.";
					return;
				}
				else
				{
					temp1 = lstptr;
					for (int i = 1; i < node_pos-1; i++)
					{
						temp1 = temp1->next;
					}
					temp2 = temp1->next;
					temp1->next = temp2->next;
					cout << "Deleted node had : " << temp2->data;
					delete temp2;
				}
			}
		}
		
		void delete_by_searched_value()	//function to delete by searched value
		{
			cout << "\n\n\tDELETE BY SEARCHED VALUE\n\n";
			
			node *temp1, *temp2;
			int search_value;	//to store the search value entered by the user
			int pos = 0; 		//to determine the position of searched value
			int stat = 0;	//if searched element not found then stat will remain 0
			
			cout << "Enter the data value of the node to be deleted : ";
			cin >> search_value;
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next)
				{
					pos++;
					if (temp1->data == search_value)
					{
						stat++;
						temp2 = lstptr;
						for (int i = 1; i < pos-1; i++)
						{
							temp2 = temp2->next;
						}
						temp2->next = temp1->next;
						delete temp1;
						cout << pos << " st/nd/rd/th node is deleted.";
						break;
					}
				}	
				if (stat == 0)
				{
					if (temp1->data == search_value)
					{
						pos++;
						stat++;
						temp2 = lstptr;
						for (int i = 1; i < pos-1; i++)
						{
							temp2 = temp2->next;
						}
						temp2->next = temp1->next;
						delete temp1;
						cout << pos << " st/nd/rd/th node is deleted.";
					}
				}
				if (stat == 0)
				{
					cout << "No node contain " << search_value << ".";
				}
			}
		}
		
		void search_node()	//function for searching data in a node
		{
			cout << "\n\n\tSEARCH DATA OF THE NODE\n\n";
			
			int search, pos = 0;	//search variable to store search value, pos variable to determine position of node
			int count = 0;	//if remained 0 then element not found
			node *temp1;
			
			cout << "Enter the search element : ";
			cin >> search;
			if (lstptr == NULL)	//condition for empty linked list
			{
				cout << "List is empty.";
			}
			else
			{
				for (temp1 = lstptr; temp1->next != lstptr; temp1 = temp1->next)
				{
					pos++;
					if (temp1->data == search)
					{
						count++;
						cout << "Search element found at node " << pos <<".";
						break;
					}
				}	
				if (count == 0)
				{
					if (temp1->data == search)	//if element is present at the last node
					{
						pos++;
						count++;
						cout << "Search element found at node " << pos <<".";
					}
				}
				if (count == 0)
				{
					cout << "Element not found.";
				}
			}
		}
};

void choice(list lst)	//function for user choice
{
	int ch;	//choice variable for user
	
	cout << "\n\n\nChoose one of the following:\n1. Create a node\n2. Insert node at begining\n3. Insert node at end\n4. Insert node at specified position\n5. Print linked list\n6. Length of linked list\n7. Delete node from front\n8. Delete node from end\n9. Delete node from node position\n10. Delete node by searched value\n11. Search of node\n12. Exit\nEnter your choice : ";
	cin >> ch;
	switch(ch)
	{
		case 1 :
			lst.create_node();
			choice(lst);
			break;
			
		case 2 :
			lst.insert_begnn();
			choice(lst);
			break;
			
		case 3 :
			lst.insert_end();
			choice(lst);
			break;
			
		case 4 :
			lst.insert_pos();
			choice(lst);
			break;
			
		case 5 :
			lst.print_lnkdlst();
			choice(lst);
			break;
			
		case 6 :
			lst.length_lnkdlst();
			choice(lst);
			break;
			
		case 7 :
			lst.delete_node_front();
			choice(lst);
			break;
			
		case 8 :
			lst.delete_node_end();
			choice(lst);
			break;
		
		case 9 :
			lst.delete_node_position();
			choice(lst);
			break;
			
		case 10 :
			lst.delete_by_searched_value();
			choice(lst);
			break;
			
		case 11 :
			lst.search_node();
			choice(lst);
			break;
			
		case 12 :
			cout << "\n\nProgram ended!!";
			exit (0);
			break;
			
		default :
			cout << "\nChoice not valid.";
			choice (lst);
	}
}

main ()
{
	list lst;
	choice(lst);
}
