#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length=0;

int getlength()
{
    return length;
}

int insertItemAt(int pos, int item)
{
    if(pos>=length)return NULL_VALUE;
    if(length==listMaxSize)
    {
        int *tempList;
        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;

        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ;
        }
        free(list) ;
        list = tempList ;
    };
    list[length++]=list[pos];
    list[pos]=item;
    return SUCCESS_VALUE;
}
void initializeList()
{
    listMaxSize = LIST_INIT_SIZE;
    list = (int*)malloc(sizeof(int)*listMaxSize) ;
    length = 0 ;
}

int searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item ) return i;
    }
    return NULL_VALUE;
}

int insertItem(int newitem)
{
    if(list==0)initializeList ();
    if (length == listMaxSize)
    {
        int * tempList ;//allocate new memory space for tempList
        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
    };

    list[length] = newitem ; //store new item
    length++ ;
    return SUCCESS_VALUE ;
}

int shrinkList()
{
    if(listMaxSize==LIST_INIT_SIZE)return NULL_VALUE;
    if(2*length<=listMaxSize)
    {
        listMaxSize/=2;
        int *tempList;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
        return SUCCESS_VALUE;
    }
    else return NULL_VALUE;
}

int deleteItemAt(int position) //version 2, do not preserve order of items
{
    if ( position >= length ) return NULL_VALUE;
    list[position] = list[length-1] ;
    length-- ;
    shrinkList ();
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    int position;
    position = searchItem(item) ;
    if ( position == NULL_VALUE ) return NULL_VALUE;
    deleteItemAt(position) ;
    return SUCCESS_VALUE ;
}

int deleteLast()
{
    if(length==0)return NULL_VALUE;
    else deleteItemAt (length-1);
    return SUCCESS_VALUE;
}


void deleteAll()
{
    free(list);
    initializeList ();
}

void clearList()
{

    free(list);
    list=0;
    listMaxSize=0;
    length=0;
}

void printList()
{
    int i;
    printf("List--> ");
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\nCurrent size: %d, current length: %d\n", listMaxSize, length);
}

//int main(void)
//{
//    //initializeList();
//    while(1)
//    {
//        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
//        printf("4. insert item at. 5. Print. 6. Shrink list\n");
//        printf("7. delete last. 8. Get length. 9. Clear list 10. Delete all\n");
//        printf("11. Exit\n");
//        int ch;
//        scanf("%d",&ch);
//        if(ch==1)
//        {
//            int item;
//            printf ("Insert item\n");
//            scanf("%d", &item);
//            insertItem(item);
//        }
//        else if(ch==2)
//        {
//            int pos;
//            printf("Position?\n");
//            scanf("%d", &pos);
//            deleteItemAt(pos);
//        }
//        else if(ch==3)
//        {
//            int item;
//            printf("Item?\n");
//            scanf("%d", &item);
//            deleteItem(item);
//        }
//        else if(ch==4)
//        {
//            int pos,item;
//            printf("Position & Item?\n");
//            scanf("%d%d", &pos, &item);
//            insertItemAt (pos,item);
//        }
//        else if(ch==5)
//        {
//            printList();
//        }

//        else if(ch==6)
//        {
//            shrinkList ();
//        }
//        else if(ch==7)
//        {
//            deleteLast ();
//        }

//        else if(ch==8)
//        {
//            printf("%d\n",getlength ());
//        }
//        else if(ch==9)
//        {
//            clearList ();
//        }
//        else if(ch==10)
//        {
//            deleteAll ();
//        }
//        else if(ch==11)
//        {
//            break;
//        }



//    }

//}



int main()
{
    char s[100];
    scanf("%s",s);
    int i,b,a,c;
    for(i=0;s[i];i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            b=list[length-1];
            deleteLast ();
            a=list[length-1];
            deleteLast ();

            switch (s[i])
            {
            case '+':
                c=a+b;
                break;
            case '-':
                c=a-b;
                break;
            case '*':
                c=a*b;
                break;
            case '/':
                c=a/b;
                break;
            }
            if(c<10)insertItem (c);
            else
            {
                insertItem (c/10);
                insertItem (c%10);
            }
        }
        else insertItem (s[i]-'0');
    }
    for(i=0;i<length;i++)printf("%d",list[i]);
    clearList ();
    return 0;

}
