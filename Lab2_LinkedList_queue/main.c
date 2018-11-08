#include <stdio.h>
#include<windows.h>
#define null 0
//--------------------------Global Variables----------------
char menu[3][13]={"Enqueue","Dequeue","Exit"};

void display_Items(state){
    int i ;
  for (i =0 ; i< 3 ; i++){
                if (i==state){
                    textattr(20);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                    textattr(15);
                }
                else {
                    textattr(15);// Red = 4 and White = 7
                    printf("%s\n",menu[i]);
                }
		}}
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
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 node * create_node(int count){
     node * new_node = (node*)malloc(1*sizeof(node));
     printf("Enter Employee.ID[%d]= ",count);
	scanf("%d",&new_node->emp.id);
	printf("Enter Employee.Salary[%d]= ",count);
	scanf("%d",&new_node->emp.salary);
	printf("Enter Employee.Name[%d]= ",count);
	scanf("%s",&new_node->emp.name);


     new_node->next=new_node->prev=null;
     return new_node;
 }
 void enqueue_node (node * new_node){
     if(first ==null){
        first =new_node;
        last=new_node;
     }
     else{
        last->next =new_node;
        last = new_node;
     }
 }
 void DisplayAll_node(){
     node *p = first;
     while(p !=null){
        printf("\nemployee.id=%d",p->emp.id);// or p[0].emp.id
        printf("\nemployee.salary=%d",p->emp.salary);
        printf("\nemployee.name=%s",p->emp.name);
        printf("\n------------------------------------");
        p=p->next;
     }
 }
 node * dequeue_node(){
        node * temp = null;
        if (first !=null){
            temp =first;
            first =first->next;
            temp->next=null;
        }
        return temp;


     //free(p);
 }
 node * search_node(int data){
     node *Psearch=first;
     while(Psearch !=null){
        if (Psearch->emp.id==data){
            return Psearch;
        }
        else {
            Psearch =Psearch->next;
        }

     }
     return null;
 }
 void insertAfter_node(node * after ,node *Pnew){
     Pnew->prev =after;
     Pnew->next=after->next;
     after->next->prev=Pnew;
     after->next=Pnew;

 }
 void display_node(node * p){
     printf("\nEmployee.id=%d",p->emp.id);
     printf("\nEmployee.=%s",p->emp.name);
     printf("\nEmployee.salary=%d\n",p->emp.salary);
 }
 // Global Variables
 int count =0 ;

int main () {

	int mainMenu=1,search=0 , create=0,exit =0 ,displayAll=0,del=0,insert=0,display_one =0,flag =0,flag2=1,i,state = 0,\
	flag_diaplayAll=0,flag_search=0,flag_insert=0,flag_delete=0,flag_create=0,flag_displayOne=0,esc=0,flag_forward=0,flag_backward=0;
	char c,y ;

while (exit !=1){
    if (mainMenu == 1 && search == 0 && create ==0 && exit ==0 && del==0 && insert==0 && displayAll==0 ){

         if (flag ==0){
        system("cls");
        state =0;
		display_Items(state);
		}

        c=getch();
        if (c == -32){

        c = getch();
          if (c == 72 ){ //up
             system("cls");
             state--;
             if (state <0){state =2;}

		display_Items(state);

        }
        else if (c ==80  ){//down

           system("cls");
           state++;
             if (state >2){state =0;}
          display_Items(state);
        }

        else if (c == 71 ){//home

            system("cls");
            state =0;
      display_Items(state);
        }
        else if (c == 79 ){//end

           system("cls");
           state =5;
        display_Items(state);

        }
        // up = 72  down = 80  home = 71  end = 79
            mainMenu =1 ;

        }
        else if (c== 13){
            if (state == 0){//Push
            create =1 ;
            c = 0;
            }
            else if (state ==1){//Pop

            del =1 ;
            c = 0;

        }
        else if (state ==2 ){//Exit

            exit =1 ;
            c = 0;
        }

        mainMenu = 0;

        }
flag =1;
}
else if (mainMenu ==0 && create ==1 && search ==0 && del ==0 && insert ==0 && displayAll ==0 && display_one ==0){// Create New

   if (flag_create ==0){system("cls");}
    flag_create =1;
    node * p=create_node(count);
    enqueue_node(p);
    count++;
    printf("Please Enter Anything \n");
    getch();
    mainMenu =1;
    flag =create =state=flag_create =0;

}
else if  (search == 1 && create ==0 && mainMenu ==0 && del ==0){//search

        int id ;
        system("cls");
        printf("Enter Employee ID=");
        scanf("%d",&id);

        if (search_node(id) !=null){
            node * p=search_node(id);
            display_node(p);
        }
        else{
            printf("Not Found Employee\n");
        }
        printf("Press any Keys to return to the main menu\n ");
        getch();
        mainMenu =1 ;
        flag=search =state=0;

}

else if (mainMenu ==0 && del ==1 && search ==0 && create==0){// Delete

   if (flag_delete ==0){system("cls");}
    flag_delete =1;
    node * p;
    p=dequeue_node();
    if ( p!=null){
            display_node(p);
            count--;
        }
        else{
            printf("No Employee to dequeue\n");
        }


    printf("Please Enter Anything \n");
    getch();
    flag_delete=create =search =del=insert=displayAll=flag=state=0;
    mainMenu =1;
}

else if (mainMenu ==0 && insert==1 && search ==0 ){// Insert

   if (flag_insert ==0){system("cls");}
    flag_insert =1;
    int id;
    printf("Enter Employee ID you wanna Insert after=");
    scanf("%d",&id);
    if (search_node(id) !=null){
            node * p=search_node(id);
            if (p == last){
                node * new_node=create_node(count);
                enqueue_node(new_node);
            }
            else{
            node * new_node=create_node(count);
            insertAfter_node(p,new_node);
            }
        }
        else{
            printf("Not Found Employee\n");
        }

    printf("Please Enter Anything to return to MainMenu \n");
    getch();
    mainMenu =1;
    flag =state=create =search =del=insert=displayAll=flag_insert=0;


}
else if (mainMenu ==0 && displayAll ==1 && search ==0 ){// DisplayAll

   if (flag_diaplayAll ==0){system("cls");}
    flag_diaplayAll =1;

    DisplayAll_node();
    printf("\nPlease Enter Anything to MainMenu\n");
    getch();
    mainMenu =1;
    displayAll=flag =create =state=flag_diaplayAll=0;
}
else if (mainMenu ==0 && displayAll ==0 && search ==0 && display_one==1 ){// DisplayOneByOne
    node *p = first;
    if (flag_displayOne ==0){system("cls");printf("Press left or right arrows to switch between linkedList characters");}
    flag_displayOne =1;
    flag_forward=0;
    flag_backward =0;
    while (esc != 1){
    y =getch();
    if (y == -32){
         y= getch();
        if(y ==77){//right arrow
            if (first ==null && last ==null){
                printf("No Employees\n");
            }
            else if (p->next == null ){
                if (flag_forward ==0){
                flag_forward =1;
                display_node(p);
                printf("Last Employee");
                }
                else {
                    printf("\nNo Forward Employees\n");
                }
            }
            else{
            display_node(p);
            p=p->next;
            }
	   }
	    else if (y==75){//left arrow
            if (first ==null && last ==null){
                printf("No Employees\n");
            }
            else if (p->prev == null){
                if (flag_backward ==0){
                    flag_backward =1;
                    display_node(p);
                    printf("First Employee");
                }
                else {
                    printf("\nNo Backward Employees\n");
                }
            }
            else {

                display_node(p);
                p=p->prev;
            }
        }
    }
    else if (y==27){//Esc
	   printf("\nByeBye\n");
	   esc = 1;

   }
   }

    mainMenu =1;
    displayAll=flag =create =state=display_one=flag_displayOne=esc=0;
}
else if  (exit ==1){
    mainMenu =0;
    system("cls");

}
	}

   return(0);
}
