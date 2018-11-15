#include <stdio.h>
#include<windows.h>
#define null 0
//--------------------------Global Variables----------------
char menu[5][13]={"New","Search","Delete","Display All","Exit"};

void display_Items(state){
    int i ;
  for (i =0 ; i< 5 ; i++){
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
    node *right ,*left;
};
node *root =null;
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}
 node * search_node(int data){
     node *Psearch=root;
     while(Psearch !=null){
        if (Psearch->emp.id==data){
            return Psearch;
        }
        else if (data >Psearch->emp.id){
            Psearch=Psearch->right;
        }
        else {
            Psearch =Psearch->left;
        }

     }
     return null;
 }
 node * create_node(int count){
     int id ;
     node * new_node = (node*)malloc(1*sizeof(node));

     do {
        printf("Enter unique Employee.ID[%d]= ",count);
        scanf("%d",&id);
     }while(search_node(id) !=null); //search_node must be equal null to exit from the loop
     new_node->emp.id=id ;

	printf("Enter Employee.Salary[%d]= ",count);
	scanf("%d",&new_node->emp.salary);
	printf("Enter Employee.Name[%d]= ",count);
	scanf("%s",&new_node->emp.name);
     new_node->right=null;
     new_node->left=null;
     return new_node;
 }

 void add_node (node * pnew){
     if(root ==null){
        root=pnew;
     }
     else {
        node *pcurrent =root;
        node * parent;
        while (pcurrent !=null){
            parent =pcurrent;
            if (pnew->emp.id > pcurrent->emp.id){
                pcurrent=pcurrent->right;
            }
            else {
                    pcurrent=pcurrent->left;
            }
        } //parent here will be the leaf node after which we wanna put our new node
        if (pnew->emp.id > parent->emp.id){
            parent->right=pnew;
        }
        else {
            parent->left=pnew;
        }
     }

 }
 void DisplayAll_node( node *Pnode){
     if (Pnode !=null){
        DisplayAll_node(Pnode->left);
        display_node(Pnode);
        DisplayAll_node(Pnode->right);
     }
 }
 node * GetParent_node(node * child ){
     node * parent = root;
     while (parent !=null){
        if (parent ->left ==child || parent->right==child){
            return parent;
        }
        else if (child->emp.id > parent->emp.id){
             parent= parent->right;
        }
        else {
            parent = parent->left;
        }
     }
     return null;
 }
 void delete_node(node *pdelete ){
     if (pdelete ==root){
        if (root->left ==null && root->right ==null){
            root=null;
        }
        else if (root->right==null){
            root=root->left;
        }
        else if (root->left==null){
            root=root->right;
        }
        else {// if the node has a child
            node *pcurrent=root->left; // the node which i wanna make the future root
            while(pcurrent->right !=null){
                pcurrent=pcurrent->right;
            }
            pcurrent->right=root->right;
            root=root->left;
        }
     }
     else {
        node * parent = GetParent_node(pdelete);
        if (pdelete->left == null && pdelete->right ==null)//leaf
            {
            if (parent->left ==pdelete){
                parent->left=null;
                }
            else {
                parent->right=null;
                }
            }
        else if (pdelete->right ==null)//node  has nodes on left but no at right
            {
            if (parent->left ==pdelete){
                parent->left=pdelete->left;
                }
            else {
                parent->right=pdelete->left;
                }
            }
        else if (pdelete->left ==null)//Pdelete has nodes at right but no nodes at left
            {
            if (parent->left ==pdelete){
                parent->left=pdelete->right;
                }
            else {
                parent->right=pdelete->right;
                }
            }
        else {
            node *pcurrent=pdelete->left;
            while(pcurrent->right !=null)
                    {
                        pcurrent=pcurrent->right;
                    }
            pcurrent->right=pdelete->right;
            if (parent->left ==pdelete){
                parent->left=pdelete->left;
                }
            else {
                parent->right=pdelete->left;
                 }
            }

     }


     //free(p);
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
             if (state <0){state =4;}

		display_Items(state);

        }
        else if (c ==80  ){//down

           system("cls");
           state++;
             if (state >4){state =0;}
          display_Items(state);
        }

        else if (c == 71 ){//home

            system("cls");
            state =0;
      display_Items(state);
        }
        else if (c == 79 ){//end

           system("cls");
           state =4;
        display_Items(state);

        }
        // up = 72  down = 80  home = 71  end = 79
            mainMenu =1 ;

        }
        else if (c== 13){
            if (state == 0){
            create =1 ;
            c = 0;
            }
            else if (state ==1){
            search =1 ;
            c = 0;

        }
        else if (state ==2 ){
            del =1 ;
            c = 0;
        }
        else if (state ==3){

            displayAll=1 ;
            c = 0;
        }

        else if (state ==6){

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
    add_node(p);
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
    int id;
    printf("Enter Employee ID you wanna Delete=");
    scanf("%d",&id);

    if (search_node(id) ==null){
            printf("No Found Employee to delete\n");
        }
        else{
             node * p=search_node(id);
             delete_node(p);
             printf("Employee was deleted to successfully\n");
        }

    count--;
    printf("Please Enter Anything \n");
    getch();
    flag_delete=create =search =del=insert=displayAll=flag=state=0;
    mainMenu =1;
}
else if (mainMenu ==0 && displayAll ==1 && search ==0 ){// DisplayAll

   if (flag_diaplayAll ==0){system("cls");}
    flag_diaplayAll =1;

    DisplayAll_node(root);
    printf("\nPlease Enter Anything to MainMenu\n");
    getch();
    mainMenu =1;
    displayAll=flag =create =state=flag_diaplayAll=0;
}
else if  (exit ==1){
    mainMenu =0;
    system("cls");

}
	}

   return(0);
}
