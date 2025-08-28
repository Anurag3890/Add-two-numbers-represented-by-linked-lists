#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create_node(int val){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

struct Node* add_lists(struct Node* l1, struct Node* l2){
    struct Node *res=NULL, *tail=NULL;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=(l1?l1->data:0)+(l2?l2->data:0)+carry;
        carry=sum/10;
        struct Node* newnode=create_node(sum%10);
        if(!res)res=tail=newnode;
        else{tail->next=newnode; tail=newnode;}
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;
    }
    return res;
}

void print_list(struct Node* head){
    while(head){printf("%d ",head->data); head=head->next;}
    printf("\n");
}

int main(){
    struct Node *l1=create_node(2); l1->next=create_node(4); l1->next->next=create_node(3);
    struct Node *l2=create_node(5); l2->next=create_node(6); l2->next->next=create_node(4);
    struct Node *res=add_lists(l1,l2);
    print_list(res);
    return 0;
}