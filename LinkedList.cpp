#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

typedef struct listNode listNodes;
listNodes * list;

void initializeList()
{
    list = 0;                                       //initially set to NULL
}

int insertItem(int item) //insert at the beginning
{
    listNodes * newNode ;
    newNode = (listNodes*) malloc (sizeof(listNodes)) ;
    newNode->item = item ;
    newNode->next = list ; //point to previous first node
    list = newNode ; //set list to point to newnode as this is now the first node
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    listNodes *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete the first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    return SUCCESS_VALUE ;
}


listNodes * searchItem(int item)
{
    listNodes * temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp ;
        temp = temp->next ; //move to next node
    }
    return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    listNodes * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int insertLast(int item)
{
    //write your codes here
    listNodes * temp,* newNode;
    newNode=(listNodes*)malloc(sizeof(listNodes));
    newNode->item=item;
    newNode->next=0;
    if(list==0)
    {
        list=newNode;
        return SUCCESS_VALUE;
    }
    temp=list;
    while(temp->next!=0)
        temp=temp->next;

    temp->next=newNode;
    return SUCCESS_VALUE;

}

int insertAfter(int oldItem, int newItem)
{
    //write your codes here
    listNodes *temp,*newNode;
    temp=searchItem (oldItem);
    if(temp==0)return NULL_VALUE;
    else
    {
        newNode=(listNodes*)malloc(sizeof(listNodes));
        newNode->item=newItem;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    return SUCCESS_VALUE;
}

int deleteLast()
{
    //write your codes here
    listNodes *temp;
    if(list==0)return NULL_VALUE;
    temp=list;
    if(temp->next==0)
    {
        free(temp);
        list=0;
        return SUCCESS_VALUE;
    }
    else
    {
        while(temp->next->next!=0)
            temp=temp->next;

        free(temp->next);
        temp->next=0;
    }
}

int deleteFirst()
{
    //write your codes here
    listNodes *temp;
    if(list==0)return NULL_VALUE;

    temp=list;
    list=list->next;
    free(temp);
    return SUCCESS_VALUE;
}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert last. 5. Print. 6. Insert after. 7. Delete first.\n");
        printf("8. Delete last. 9. Exit.\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            insertLast (item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            int old,newi;
            printf("Old item?\n");
            scanf("%d",&old);
            printf("New item?\n");
            scanf("%d",&newi);
            insertAfter (old,newi);
        }
        else if(ch==7)
        {
            deleteFirst ();
        }
        else if(ch==8)
        {
            deleteLast ();
        }
        else if(ch==9)
        {
            break;
        }
    }

}
