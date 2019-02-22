#include <stdio.h>

typedef struct node{
	struct node *next_node = NULL;
	int data;
}Node, *pNode;

Node *head = NULL;

int insert_data(int data)
{
	
	Node *pre = NULL;
	Node *current = NULL;
	Node *Node_link = head;
		
	while(Node_link->next_node){
		if (Node_link->data > data)
			break;
		pre = Node_link;
		Node_link = Node_link->next_node;
	}
	
	current = (Node *)malloc(sizeof(Node));
	if (current == NULL)
		return -1;
	
	current->data = data;
	current->next_node = Node_link;
	
	if (pre){	
		pre->next_node = current;
	}else{
		head->next_node = current;
	}
	return 0;	
}

int delete_node(int data)
{
	Node *pre = NULL;
	Node *node_link = head;
	
	while(node_link->next_node){
		if (node_link->data == data){
			if (pre == NULL){
				head->next_node = node_link->next_node;
				free(node_link);
			}
			pre->next_node = node_link->next_node;
			free(node_link);
			break;
		}
		pre = node_link;
		node_link = node_link->next_node;
	}
	return 0;
}

int changed_node(int old_val, int new_val)
{
	return 0;
}

void free_Node()
{
	pNode tmp;
	while(Node->next_node != NULL){
		tmp = Node->next_node;
		free(Node);
		Node = tmp;
	}
	//free last node;
	free(Node);
}

int main()
{
	//create node head;
	head = (Node *)malloc(sizeof(Node));
	return 0;
}
