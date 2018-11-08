#include <stdio.h>
#include <stdlib.h>
#define null 0
 struct employee {
    int id ;
    char name[20];
    int salary ;
};
typedef struct employee employee ;
typedef struct node node ;
struct node {
    employee emp ;
    node *prev ,*next;
};
node *first = null,*last=null;
 node * create_node(int count){
     node * new_node = (node*)malloc(1*sizeof(node));
     printf("Enter Employee.ID[%d]= ",count);
	scanf("%d",&new_node->emp.id);
	printf("Enter Employee.Salary[%d]= ",count);
	scanf("%d",&new_node->emp.salary);
	printf("Enter Employee.Name[%d]= ",count);
	scanf("%s",&new_node->emp.name);
    printf("              ----------------                       \n");
     new_node->next=new_node->prev=null;

     return new_node;
 }
  void add_node (node * new_node){
     if(first ==null){
        first=last=new_node;
     }
     else{
        last->next=new_node;
        new_node->prev=last;
        last = new_node;
     }
 }
  void DisplayAll_node(){
      int i;
     node *p = first;
     while(p !=null){
        printf("\nemployee.id=%d",p->emp.id);// or p[0].emp.id
        printf("\nemployee.salary=%d",p->emp.salary);
        printf("\nemployee.name=%s",p->emp.name);
        printf("\n------------------------------------");
        p=p->next;
        i++;
     }
 }
 void swap (node* B ,node *C){//let Nodes be Node A ,||B,C,||||D
     node * temp1,*temp2,*temp3,*temp4,*temp5,*temp6,*A,*D;

        if (B->prev == null){


            D=C->next;
            temp1=B;
            temp2=B->prev;
            temp3=B->next;

            temp4=C;
            temp5=C->prev;
            temp6=C->next;

            temp4->next->prev=temp1;

            temp4->prev=null;
            temp4->next=temp1;


            temp1->prev=temp4;
            temp1->next=D;

            //y=temp1;
            //x=temp4;
            first = temp4;
            last=temp1;
        }

        else if (C->next ==null){


            A=B->prev;

            temp1=B;
            temp2=B->prev;
            temp3=B->next;

            temp4=C;
            temp5=C->prev;
            temp6=C->next;

            printf("Bye");
            temp1->prev->next=C;

            temp4->prev=A;
            temp4->next=temp1;


            temp1->prev=temp4;
            temp1->next=null;

            //y=temp1;
            //x=temp4;
            last=C;
        }

         else {

        A=B->prev;
        D=C->next;
        temp1=B;
        temp2=B->prev;
        temp3=B->next;
        temp4=C;
        temp5=C->prev;
        temp6=C->next;

        temp1->prev->next=C;
        temp4->next->prev=B;

        temp4->prev=A;
        temp4->next=temp1;


        temp1->prev=temp4;
        temp1->next=D;

        //y=temp1;
        //x=temp4;
         }



 }
 void bubble_sort(int size){
		int counter,i=0,flag=0;
        node *temp,*A,*B ;


    node *ptr,*p = first;

        //while (ptr->next!=null){
        for(counter =0 ;counter<size;counter++){
        p = first;
        while (p->next!=null){
        if (p->emp.id > p->next->emp.id)
            {
                if (p== first)
                    {
                    A = p ;
                    B= p->next;
                    swap(A,B);
                    first =B;//sure
                    ptr=B;
                    p=A;
                    flag=1;
                    }
                    else if (p->next ==last){
                     A = p ;
                     B= p->next;
                     swap(A,B);
                     p=A;

                    }
                else{
                     A = p ;
                     B= p->next;
                     swap(A,B);
                     p=A;

                     //ptr=B;
                    }
            }
        else {
        p=p->next;
        printf("kkk");


            }
     }

     ptr=ptr->next;
     }
 }

int main()
{
    int l;int i=0;int i2;int temp,counter,size;
	printf("-----------Bubble Sort using Linked-list------------\n");
	char ch =null;
    while (ch !=27){

    node *p= create_node(i);
    add_node(p);
    i++;
    printf("\nEnter Esc to Exit or any key to continue inputing employees\n");
    ch=getch();
    }
    bubble_sort(i);
	DisplayAll_node();
    return 0;
}
