#include <stdio.h>
#include<windows.h>
#define null 0
//--------------------------Global Variables----------------
char menu[3][13]={"Push","Pop","Exit"};

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
 void push_node (node * new_node){
     if(last ==null){
        last=new_node;
     }
     else{
        new_node->prev=last;
        last = new_node;
     }
 }

 node * pop_node(){

        if (last ==null){
            return null;
        }
        else {
            node * temp = last ;
            last=last->prev;
            return temp;
        }


     //free(p);
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
    push_node(p);
    count++;
    printf("Please Enter Anything \n");
    getch();
    mainMenu =1;
    flag =create =state=flag_create =0;

}


else if (mainMenu ==0 && del ==1 && search ==0 && create==0){// Pop

   if (flag_delete ==0){system("cls");}
    flag_delete =1;
    node * p;
    p=pop_node();
    if ( p!=null){
            display_node(p);
            count--;
        }
        else{
            printf("No Employee to pop\n");
        }


    printf("Please Enter Anything \n");
    getch();
    flag_delete=create =search =del=insert=displayAll=flag=state=0;
    mainMenu =1;
}

else if  (exit ==1){
    mainMenu =0;
    system("cls");

}
	}

   return(0);
}
