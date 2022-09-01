#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef enum { F, T } boolean;

typedef struct n
{
   int student_id;
   int student_year;
   int couseId[3];
   float grades[3];
    struct n* next;
    
}node;

typedef struct 
{
    node* head;
}linked_list;
//global initialisation 
linked_list *l;
// to creat a node
 node * newnode ()
{
     node* n= malloc (sizeof(node));
     n->next=NULL;
    return n; 
}
//to creat a linked list
linked_list* init ()
{
   l = malloc (sizeof (linked_list));
    l->head =NULL;
    return l;
} 
// to add Entry
boolean SDB_AddEntry (int id,int year, int*subjects, int*g)
{
   
   boolean flag;
    node*n= newnode();
    l->head = n;
    n->student_id =id;
    n->student_year =year;
    for (int i =0; i<3; i++){
       n->couseId [i]=subjects[i];
    }
   for (int i =0; i<3; i++){
       n->grades [i]=g[i];
    }

    if (n)
      flag = T;
    else 
      flag = F;

  return flag;

}
//to get the size 
int SDB_GetUsedSize (void)
{
    int count=0;
    while (l->head->next)
    {
        count ++;
        l->head=l->head->next;
    }
    return count;
    
}
// consider it full if it complete 10 student
boolean SDB_IsFull (void)
{
    if (SDB_GetUsedSize()==10)
    return T;
    return F;
}
 
 // to delete
 void SDB_DeleteEntry (int id)
 {
    //1st case if it is the head
    if (l->head->student_id == id)
    {
         node*temp=l->head;
        l->head= l->head->next;
        free (temp);
    }
   // to find the node that you want to delete 2n case
    node* current= l->head;
    node* next = l->head->next;
    node* temp;
   while (next->next)
   {
   if (next->student_id != id)
        {
           current=next;
            next = current->next;
        }
    else if (next->student_id == id)
      //delete 
      {
        temp = next;
        current->next = temp->next->next;
        free (temp);
        
      }
     printf("deleted succefully \n"); 
   }
 }
   
  // to read information about on student

  boolean SDB_ReadEntry (int id )
{
    node* current= l->head;
    while (current)
    {
        if (current->student_id==id)
        {
         printf ("\n the student id= %d ",current->student_id);
         printf ("\n the student year= %d ",current->student_year); 
        for (int i =0 ; i<3;i++)
        {
            printf ("\nsubject id =%d course grade=%d",current->couseId[i], current->grades[i]);
        }
        return T;
        }
        else 
        {
        current = current->next;
         
        }

    }
    return F;
    
}

// to get a linked list 
void SDB_GetIdList (int count, linked_list* s)
{
    l = s;
    if (l!=NULL)
    printf ("number of student = %d ",count);

}

boolean SDB_IsIdExist (int id)
{
      node* current= l->head;
    while (current!= NULL)
    {
        if (current->student_id==id)
        {
        return T;
        }
        else 
        {
        current = current->next;
        }
    }
    return F;  
}
 
void execute (int x)
{
    linked_list *s;
    int count,id,year;
    int courses[3];
    int grades[3];
    boolean flag;
    switch (x)
{
case 1:
    printf (" enter a pointer to the list\n");
    scanf ("%p",&s);
    printf ("please enter count \n");
    scanf("%d",&count);
    SDB_GetIdList (count, s);
    break;
case 2:
printf ("enter id \n");
scanf("%d",&id);
printf("enter year \n");
scanf ("%d",&year);
printf ("enter 3 courses id and gpa");
for (int i =0; i<3; i++)
{
    printf("enter course and gpa");
    scanf("%d%d",&courses[i],&grades[i]);
}
flag= SDB_AddEntry ( id, year,&courses, &grades);
if (flag==T)
printf("add sucessfuly");
else
printf ("something went wrong");

    break; 
 case 3:
    printf ("enter the id \n");
    scanf("%d",&id);
     flag =SDB_IsIdExist (id);
    if (flag == T)
    printf (" the member exists ");
    else 
    printf("the member deoesn't exist"); 
    break;
 case 4:
    printf ("enter the id \n");
    scanf("%d",&id);
       flag = SDB_ReadEntry ( id );

    break;       
 case 5:
    printf ("enter the id \n");
    scanf("%d",&id);
     SDB_DeleteEntry ( id);

    break;
case 6:
   count = SDB_GetUsedSize;
    printf ("the size of the list = %d",count);
    break;
 case 7:
     flag=  SDB_IsFull ();
    if (flag== T)
     printf ("the list is full");
     else 
     printf ("the list is not full");
         
    break;
default:
    break;
}
}     
int main (void)
{
    l= init();
    int x;
printf ("to excute the program press a number for bellow  \n");
printf("to add a list of ids press 1 \n");
printf ("to add one member to the list press 2\n");
printf ("to search if the id exists or not press 3\n");
printf ("to find info about an id press 4\n");
printf ("to delete an id press 5\n");
printf ("to find the size of the list press 6\n");
printf (" to know if it is full or not press 7 \n");
scanf ("%d",&x);
execute(x);
return 0;
}

