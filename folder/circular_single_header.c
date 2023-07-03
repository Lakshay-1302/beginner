#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct node Node;

void display(Node* head,Node* ptr){
    while(ptr!=head){
        printf("%d, ",ptr->data);
        ptr=ptr->next;
    }
}

void insert(Node* prev, int data){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=prev->next;
    prev->next=ptr;
}

 Node* insertfront(Node*head, int data){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->next=head->next;
    head->next=ptr;
    ptr->data=data;
    return ptr;
}

Node* insertend(Node* head, int data){
    Node* ptr=(Node*)malloc(sizeof(Node));
    Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    ptr->data=data;
    head=head->next;
    return head;
    
}

void input(Node* head,Node* node, int n){
    int i,temp;
    for(i=0;i<n-1;i++){
        printf("enter the data to be inserted: ");
        scanf("%d",&temp);
        if(i==0){
            node->data=temp;
            node->next=head;
        }
        else{
            insert(node,temp);
            node=node->next;
        }
    }
    printf("enter the data to be inserted: ");
    scanf("%d",&temp);
    insert(node,temp);
    node=node->next;
    node->next=head;
}

void delete(Node** list, Node* tbd){
    Node* new=(Node*)malloc(sizeof(Node));
    if(*list==tbd){
        *list=tbd->next;
    }
    else{
        new=*list;
        while(new->next!=NULL){
            if(new->next==tbd){
                new->next=tbd->next;
                break;
            }
           new=new->next;
        }
        
        }
        free(tbd);
}


int main(){
    int n1,n2;
    Node* list1=(Node*)malloc(sizeof(Node));
    Node* list2=(Node*)malloc(sizeof(Node));
    Node* head=(Node*)malloc(sizeof(Node));
    Node* temp=(Node*)malloc(sizeof(Node));
    printf("enter the number of elements in list 1 :");
    scanf("%d",&n1);
    head->data=n1;
    head->next=list1;
    printf("enter the elements for list 1:\n ");
    input(head,list1,n1);
    printf("list 1 is: ");
    display(head,list1);
    printf("\n");
    temp=insertfront(head,66);
    display(head,temp);
    printf("\n");
    //temp=insertend(head,77);
    //display(temp);
    printf("\n");
    delete(&list1,list1);
    display(head,list1);
    return 0;




}
