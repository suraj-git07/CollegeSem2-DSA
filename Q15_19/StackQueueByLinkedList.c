#include<stdio.h>
#include<malloc.h>

struct Node{
   int data;
   struct Node *next;
}*top = NULL,*front = NULL,*rear = NULL;

void pushInStack(int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)//first element
      newNode->next = NULL;
   else
      newNode->next = top;
      top = newNode;
      printf("\n%d is Inserted\n",value);
}
void popInStack(){
   if(top == NULL)
      printf("\nStack is Empty.\n");
   else{
      struct Node *temp = top;
      printf("\nDeleted element: %d", temp->data);
      top = temp->next;
      free(temp);
   }
}

void display(int n){
   if (n==1)
   {
      printf("Displaying Stack\n");
      if(top == NULL)
      printf("\nStack is Empty.\n");
   else{
      struct Node *temp = top;
      while(temp!= NULL){
	      printf("%d   ",temp->data);
	      temp = temp -> next;
      }
   }
   }
   else{
      if(front == NULL)
      printf("\nQueue is Empty,.\n");
   else{
      struct Node *temp = front;
      while(temp != NULL){
	      printf("%d   ",temp->data);
	      temp = temp -> next;
      }
   }
   }
   
}

void insert(int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\n%d is inserted.\n",value);
}
void delete(){
   if(front == NULL)
      printf("\nQueue Underflow.\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
int main(){
   int p;
   printf("->Enter 1 for Stacks.\n->Enter 2 for Queues.\n");
   scanf("%d",&p);

   if(p==1){
      int choice, value;
      printf("\n-> Stack using Linked List <-\n");
      while(1){
         printf("\n1. pushInStack\n2. popInStack\n3. Display\n4. Exit\n");
         printf("Enter your choice: ");
         scanf("%d",&choice);
         switch(choice){
            case 1: printf("Enter the value to be insert: ");
               scanf("%d", &value);
               pushInStack(value);
               break;
            case 2: popInStack(); break;
            case 3: display(1); break;
            case 4: return 0;
            default: printf("\nWrong selection!!! Please try again!!!\n");
         }
      }
   }
   else if(p==2){
      int choice, value;
      printf("\n->Queue Implementation using Linked List <-\n");
      while(1){
         printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
         printf("Enter your choice: ");
         scanf("%d",&choice);
         switch(choice){
            case 1: printf("Enter the value to be insert: ");
               scanf("%d", &value);
               insert(value);
               break;
            case 2: delete(); break;
            case 3: display(2); break;
            case 4: return 0;
            default: printf("\nWrong selection!!! Please try again!!!\n");
         }
      }
   }
}