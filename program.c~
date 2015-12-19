#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

typedef struct node{
    int number;
    char name[SIZE];
    struct node *nextNode;
} Node;

Node* insertIntoList(Node *list, Node *newNode){
	Node *head=list;
    Node *assist;
	//if the list is empty
	if(list==NULL) return newNode;
	//if first element is bigger than the one we will insert
	if(list->number > newNode->number){
		newNode->nextNode=list;
		return newNode;
		}
    while(list!=NULL){
    assist=list;
      list=list->nextNode;
        //insert at the end
        if(assist->nextNode==NULL){
            assist->nextNode=newNode;
            return head; //return head
        }
        //insert in the middle
      if(list->number >= newNode->number){
        assist->nextNode=newNode;
        newNode->nextNode=list;
        return head;
      }
    }
	return head;
}

Node* removeFromList(int number, Node *list){
    Node *head=list;
    Node *assist;

    //empty list
    if(list==NULL) return list;

    //if it is the first to remove
    if(list->number==number){
        head=list->nextNode;
        free(list);
        return head;
    }

    while(list!=NULL){
    assist=list;
    list=list->nextNode;
    //if it is the last to remove
    if(assist->nextNode==NULL){
            free(assist);
            return head; //return head
        }

        //remove last
      if(list->number == number){
        assist->nextNode=list->nextNode;
        free(list);
        return head;
      }
    }
    return head;
}

Node* createNode(char *name,int number,Node *list){
    Node *newNode;
    newNode =(Node *) malloc(sizeof(Node));
    newNode->nextNode=NULL;
    newNode->number=number;
    strcpy(newNode->name,name);
    list=insertIntoList(list, newNode);
    return list;
}

void printList(Node *list){
	while(list!=NULL){
		printf("Number: %d",list->number);
		printf("\tname: ");
		puts(list->name);
	    list=list->nextNode;
	}
}


int main(){
    int menu=1;
    int studentNumber;
    char name[SIZE];
    Node *list=NULL;

    while(menu!=0){
        printf("1 - Insert Student\n");
        printf("2 - Remove Student\n");
        printf("3 - Show Students List\n");
        printf("4 - Exit\n");

        scanf("%d",&menu);

        if(menu==1){
        	printf("Name: ");
        	scanf("%s",name);
        	printf("Number: ");
        	scanf("%d",&studentNumber);
        	printf("\n");
        	list=createNode(name,studentNumber,list);
        }

        if(menu==2){
            printf("Remove student with number: \n");
            scanf("%d",&studentNumber);
            list=removeFromList(studentNumber,list);
        }

        if(menu==3) printList(list);

        if(menu==4) menu=0;

    }
    return 0;
}
