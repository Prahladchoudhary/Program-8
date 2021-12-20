#include <iostream>
using namespace std;

struct node 
{
    int num;                
    node *nextptr;             
}*stnode; 

void listBanao(int n);                 
void reverse(node **stnode);	            
void listDhikhao();
 
int main()
{
    int n,num,item;
		
    cout<<"Enter the number of nodes: ";
    cin>>n;
    listBanao(n);
    cout<<"\nLinked list data: \n";		
    listDhikhao();
    cout<<"\nAfter reversing\n";
    reverse(&stnode);
    listDhikhao();
   return 0;
}
void listBanao(int n) 
{
    struct node *frntNode, *tmp;
    int num, i;
 
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL)        
    {
        cout<<" Memory can not be allocated";
    }
    else
    {
                                  
        cout<<"Enter the data for node 1: ";
        cin>>num;
        stnode-> num = num;      
        stnode-> nextptr = NULL; 
        tmp = stnode;
 
        for(i=2; i<=n; i++)
        {
            frntNode = (struct node *)malloc(sizeof(struct node)); 
 

            if(frntNode == NULL) 
            {
                cout<<"Memory can not be allocated";
                break;
            }
            else
            {
                cout<<"Enter the data for node "<<i<<": "; 
                cin>>num;
                frntNode->num = num;         
                frntNode->nextptr = NULL;    
                tmp->nextptr = frntNode;     
                tmp = tmp->nextptr;
            }
        }
    }
} 

void reverse(node **stnode) 
{
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*stnode);
    while(current != NULL) {
        temp = current->nextptr;
        current->nextptr = prev;
        prev = current;
        current = temp;
    }
    (*stnode) = prev;
}
void listDhikhao()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            cout<<tmp->num<<"\t";   
            tmp = tmp->nextptr;                 
        }
    }
}