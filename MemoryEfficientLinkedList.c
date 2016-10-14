#include<stdio.h>
#include<iso646.h>

struct node{
        int data;
        struct node *ptrdiff;//XOR OF PREVIOUS AND NEXT NODE
        };
struct node *start=NULL;
// FUNCTION TO CREATE DOUBLY LINKED LIST        
void createList(){
        struct node *temp,*pprev,*prev;//PPREV IS PREV TO PREV NODE
        temp=(struct node*)malloc(sizeof(struct node));
        printf("please enter data\n");
        scanf("%d",&temp->data);
        if(start==NULL)
        {
                start=temp;
                start->ptrdiff=NULL;
                prev=temp;
                pprev=NULL;
        }
        else
        {
                prev->ptrdiff=(struct node*)((unsigned int)(pprev)^(unsigned int)(temp));
                pprev=prev;
                temp->ptrdiff=prev;
                prev=temp;
                        
        }
}
//FUNCTION TO INSERT INTO LINKED LIST AT DESIRED POSITION
void insertatpos(int pos)
{
        struct node *temp,*next,*prev,*pprev;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("please enter data\n");
        scanf("%d",&temp->data);
        int count=1;
        if(pos==1)
        {
        temp->ptrdiff=start;
        start->ptrdiff=(struct node*)((unsigned int)(temp)^(unsigned int)(start->ptrdiff));
        start=temp;
        }
        else
        {
        next=start;//NEXT NODE
        prev=NULL;//PREVIOUS NODE
        pprev=NULL;//PPREV IS PREVIOUS TO PREVIOUS NODE
        while(count!=pos)
        {
                prev=next;
                next=(struct node*)((unsigned int)(pprev)^(unsigned int)(next->ptrdiff));
                pprev=prev;
                
                count++;
        }
        temp->ptrdiff=(struct node*)((unsigned int)(prev)^(unsigned int)(next));
        prev->ptrdiff=(struct node*)((unsigned int)(temp)^(unsigned int)(prev->ptrdiff)^(unsigned int)(next));
        if(next!=NULL)
        next->ptrdiff=(struct node*)((unsigned int)(temp)^(unsigned int)(next->ptrdiff)^(unsigned int)(prev));
        }
}
//FUNCTION TO PRINT LINKED LIST
void print()
{
        
        struct node *curr,*prev=NULL,*next;
        curr=start;
        
        while(curr!=NULL)
        {       
                
                printf("%d->",curr->data);
                next=(struct node*)((unsigned int)(prev)^(unsigned int)(curr->ptrdiff));
               
                prev=curr;
                curr=next;
        }
        printf("NULL\n");
        
} 
//MAIN FUNCTION
int main()
{
int i,n,pos;
printf("Please enter no of nodes\n");
scanf("%d",&n);
//LIST CREATION
for(i=0;i<n;i++)
        createList();
//PRINT LIST        
print();
printf("value of n is:%d\n",n);
printf("Please enter position no. which is less than equal to n+1\n");

scanf("%d",&pos);
if(pos<=n+1)
{      
        insertatpos(pos);
        n++;
}
else
        printf("no such position exist\n");
//PRINT LIST
print();
}       
        
