#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node node;
void display(node *tail);
node *insert_at_end(node *tail);
node *insert_at_front(node *tail);
node *delete_at_begin(node *tail);
node *delete_at_end(node *tail);

struct Node
{
	int Data;
	struct Node *next;
};

node *random_list(node *tail)
{
	int t;
	printf("Enter number of elements: ");
	scanf("%d",&t);
	free(tail);
	tail=(node*)malloc(sizeof(node));
	node* head=tail;
	tail->Data=rand()%20 +1;
	tail->next=tail;
	for (int i = 0; i < t-1; i++)
	{
		node* new=(node*)malloc(sizeof(node));
		new->Data=rand()%20 + 1;
		tail->next=new;
		new->next=head;
		tail=new;
	}
	return head;
}

void display(node *tail)
{
	node *root, *ptr;
	if (tail == NULL)
		printf("\nList is empty\n\n");
	else
	{
		root = tail->next;
		ptr = root;
		while (ptr != tail)
		{
			printf("%d ", ptr->Data);
			ptr = ptr->next;
		}
		printf("%d\n", ptr->Data);
	}
}
node
	*
	insert_at_front(node *tail)
{ 
	node *temp = (node *)malloc(sizeof(node));
	printf("\nEnter Data:");
	scanf("%d", &temp->Data);
	if (tail == NULL)
	{
		tail = temp;
		tail->next = temp;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
	}
	return (tail);
}
node
	*
	insert_at_end(node *tail)
{
	node *temp = (node *)malloc(sizeof(node));
	printf("\nEnter Data:");
	scanf("%d", &temp->Data);
	if (tail == NULL)
	{
		tail = temp;
		tail->next = temp;
	}
	else
	{
		node *root;
		root = tail->next;
		tail->next = temp;
		temp->next = root;
		tail = temp;
	}
	return (tail);
}
node
	*
	delete_at_begin(node *tail)
{
	if (tail == NULL)
		printf("\nList is Empty\n\n");
	else
	{
		if (tail->next == tail)
		{
			free(tail);
			tail = NULL;
		}
		else
		{
			node *root, *ptr;
			ptr = root = tail->next;
			root = root->next;
			tail->next = root;
			free(ptr);
		}
	}
	return (tail);
}
node
	*
	delete_at_end(node *tail)
{
	if (tail == NULL)
		printf("\nList is empty\n\n");
	else
	{
		if (tail->next == tail)
		{
			free(tail);
			tail = NULL;
		}
		else
		{
			node *root;
			root = tail->next;
			while (root->next != tail)
			{
				root = root->next;
			}
			root->next = tail->next;
			free(tail);
			tail = root;
		}
	}
	return (tail);
}

int main(int argc, char *argv[])
{ 
	srand(time(0));
	node *tail = NULL;
	int choice;
	while (1)
	{ 
		printf("1.Create a random list\n2.Insert at front\n3.Insert at end \n4.Display\n5.Delete from front\n6.Delete from End\n7.Exit\nEnter choice:");
		scanf("%d", &choice);
		switch (choice)
		{

		case 1:
			tail = random_list(tail);
			break;
		case 2:
			tail = insert_at_front(tail);
			break;
		case 3:
			tail = insert_at_end(tail);
			break;
		case 4:
			display(tail);
			break;
		case 5:
			tail = delete_at_begin(tail);
			break;
		case 6:
			tail = delete_at_end(tail);
			break;
		case 7:
			return (0);
		}
	}
}