#include <stdio.h>
#include <malloc.h>
#define N 5

typedef struct node_tag{

	int x;
	struct node_tag *next;
	struct node_tag *prev;
	
}node;


//void insertSort(node *h);
void insert(node **h);

void append(node **h, node **t);

void view(node *h);

void delete(node *h);

void view2(node *t);

main(){

node *head=NULL, *tail=NULL;
//head=(node *)malloc(sizeof(node));
//head->x=-999;
//head->next=NULL;

int choice;

	do{
		printf("Enter choice:\n[1]Append\n[2]View\n[3]Delete\n[4]View2\n[5]Exit\nChoice:");
		scanf("%d", &choice);
		
		switch(choice){
		
		case 1: //insertSort(head);
				insert(&head);
				break;
				
		case 2: view(head);
				break;
			
		case 3: delete(head);
				head=NULL;
				tail=NULL;
				break;
				
		case 4:	tail=head;
				while(tail->next!=NULL){
				tail=tail->next;
				}	
				view2(tail);
				break;
		
		case 5: return(0);
		
		default: printf("No such choice exists.");
		
		
		}

	}while(choice!=5);

}

/*void insertSort(node *h){

node *temp, *tail;
int value;
printf("Enter value:\n");
scanf("%d", &value);
temp=(node *)malloc(sizeof(node));
temp->x=value;
temp->next=NULL;

	
		tail=h;
		while((tail->next!=NULL)&&tail->next->x<value){
			tail=tail->next;
		}
		
	if(tail->x<value){
		temp->next=tail->next;
		tail->next=temp;
	}
	
	else{
		temp->next=h;
		h=temp;	
	}


}
*/
void append(node **h, node **t){

node *temp, *temp2;			//temp2 ung pangtraverse
int value;
printf("Enter value:\n");
scanf("%d", &value);
temp=(node *)malloc(sizeof(node));
temp->x=value;
temp->next=NULL;
temp->prev=NULL;

	if(*h==NULL)
		*t=*h=temp;
		
	else{
	/*
		temp2=*h;
			while(temp2->next!=NULL)
				temp2=temp2->next;
		
		temp2->next=temp;
		temp->prev=temp2;
	*/
	
		(*t)->next=temp;
		temp->prev=(*t);
		(*t)=(*t)->next;
	}


}


void view(node *h){

node *temp=NULL;
temp=h;

	while(temp!=NULL){
		printf("%d", temp->x);
		temp=temp->next;
	}
	
	printf("\n");
}

void delete(node *h){

node *temp=NULL;

	while(h!=NULL){
		temp=h;
		h=h->next;
		free(temp);
	}
}

void view2(node *t){
	node *temp=NULL;
	temp=t;
	while(temp!=NULL){
		printf("%d", temp->x);
		temp=temp->prev;
	
	}
	printf("\n");
}

void insert(node **h){

node *temp, *temp2;
int val;
printf("Enter value:");
scanf("%d", &val);
	temp=(node *)malloc(sizeof(node));
	temp->x=val;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(*h==NULL)
		*h=temp;
		
	else{
	
		temp2=*h;
		while(temp2->next!=NULL&&temp2->next->x<val)
				temp2=temp2->next;
				
		if(temp2->x<val){
			temp->next=temp2->next;
			temp2->next=temp;
			if(temp->next!=NULL){
				temp->next->prev=temp;
			}
		temp->prev=temp2;
		}
		
		else{
			temp->next=*h;
			*h=temp;
			temp2->prev=temp;
		}
	
	}



}





/*
void appendwithouttail(node **h){

node *temp, *temp2;			//temp2 ung pangtraverse
int value;
printf("Enter value:\n");
scanf("%d", &value);
temp=(node *)malloc(sizeof(node));
temp->x=value;
temp->next=NULL;
temp->prev=NULL;

	if(*h==NULL)
		*t=*h=temp;
		
	else{
	
		temp2=*h;
			while(temp2->next!=NULL)
				temp2=temp2->next;
		
		temp2->next=temp;
		temp->prev=temp2;

	}


}

*/


