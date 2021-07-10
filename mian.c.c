/*
Ìæä ÕÇÈÑ ÚÈÏÇááå
ÔåÇÈ ãÍãÏ ÇÍãÏãÍãÏ
ãÕØİì

*/


#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>

struct students{
char std_name[20];
int std_id;
int year;
int month;
int day;
int std_score;
};

struct studentL {
    char std_nameL[20];
    int std_idL;
    int yearL;
    int monthL;
    int dayL;
    int std_scoreL;
    struct node *next;
};

struct node {
   int test;
   struct node *next;
};


int n;
struct students *std ;
struct studentL* head;
int new_std=0;
char std_nameT[20];
int std_idT;
int yearT;
int monthT;
int dayT;
int std_scoreT;
double timespent = 0.0;

// ********************dynamic array functions*****************

void create_dynamic_array ();
void show_students_list_dynamic_array ();
void enter_in_the_mddle_dynamic_array();
void enter_at_the_beginnig_dynamic_array();
void enter_at_the_end_dynamic_array();

//********************linked list functions********************

void create_linked_list();
void show_students_list_linkedlist();
void enter_in_the_mddle_linkedlist();
void enter_at_the_beginnig_linkedlist();
void enter_at_the_end_linkedlist();
//********************compare time****************************
void compare(int);
//************************main function***********************

int main (){

    char choice;
    char choice1;
    int type;
    s:
    printf("do you want to use dynamic array(1)   OR   linked list(2) data structure or compare time(3) \n");
    scanf("%d",&type);

    // if the user chooses to use dynamic array
    if (type==1){
    // create the array
    create_dynamic_array();
    printf("do you want to check the list (Y/N)? \n");
    scanf("%s",&choice1);
    if (choice1=='y' || choice1=='Y'){show_students_list_dynamic_array();} // displaying the list
    g:
    // student insertion
    printf("do you want to insert another student (Y/N)? \n");
    scanf("%s",&choice);
    if (choice=='y' || choice=='Y'){
        printf("\n where do you want to put him from 1 (beginning) to %d (end)\n" , n+1);
        //  the number of elements is n so if you want to insert at the beginning then choose 1 if you want to insert at the end choose n+1
        scanf("%d",&new_std);
        if(new_std>n+1 || new_std<=0){
            printf("error try again \n");
            goto g ;
              }else {
                   n++;
                   if (new_std==1){enter_at_the_beginnig_dynamic_array();}
                   else if(new_std==n+1){enter_at_the_end_dynamic_array();}
                   else{enter_in_the_mddle_dynamic_array();}
                   printf("do you want to check the list (Y/N)? \n");
                   scanf("%s",&choice1);
                   if (choice1=='y' || choice1=='Y'){show_students_list_dynamic_array();}

                   goto g;
              }
        }

    printf("thank you \n");
    }
    else if(type==2){
    // if the user chooses to use dynamic array
    create_linked_list();
    // create linked list
    printf("do you want to check the list (Y/N)? \n");
    scanf("%s",&choice1);
    if (choice1=='y' || choice1=='Y'){show_students_list_linkedlist();}
    d:
    printf("do you want to insert another student (Y/N)? \n");
    scanf("%s",&choice);
    if (choice=='y' || choice=='Y'){
        printf("\n where do you want to put him from 1 (beginning) to %d (end)\n" , n+1);
        //  the number of elements is n so if you want to insert at the beginning then choose 1 if you want to insert at the end choose n+1 if he wants to insert in the middle choose the position
        scanf("%d",&new_std);
        if(new_std>n+1 || new_std<=0){
            printf("error try again \n");
            goto d ;
              }else {
                   n++;
                   if (new_std==1){enter_at_the_beginnig_linkedlist();}
                   else if(new_std==n+1){enter_at_the_end_linkedlist();}
                   else{enter_in_the_mddle_linkedlist();}
                   printf("do you want to check the list (Y/N)? \n");
                   scanf("%s",&choice1);
                   if (choice1=='y' || choice1=='Y'){show_students_list_linkedlist();}

                   goto d;
              }
        }

    printf("thank you \n");
    }

    else if(type==3) {
        printf("small number of elements:100\n");
        compare(100);
        printf("medium number of elements:100000\n");
        compare(100000);
        printf("large number of elements:100000000\n");
        compare(100000000);

    }
    else {
        printf("wrong answer try again \n");
        goto s;
    }

    goto s;
    return 0;
}


//****************************************************************
//****************************************************************
// ********************dynamic array functions********************
//****************************************************************
//****************************************************************
void create_dynamic_array (){

    printf("enter the number of students you want to add \n");
    scanf("%d",&n);
    std =(struct students *)malloc(n*sizeof( struct students));
    for(int i=0;i<n;i++){
       printf("\n enter student %d name \n",i+1);
       scanf("%s",std[i].std_name);
       printf("\n enter student %d ID \n",i+1);
       scanf("%d",&std[i].std_id);
       printf("\n enter student %d birth date day//month//year: \n",i+1);
       scanf("%d",&std[i].day);
       scanf("%d",&std[i].month);
       scanf("%d",&std[i].year);
       printf("\n enter student %d last year score:",i+1);
       scanf("%d",&std[i].std_score);



    }

}

void show_students_list_dynamic_array (){

   if (n==0){printf("the list is empty \n");}
   else{
   for(int i=0;i<n;i++){
        printf("\n\n student name : %s", std[i].std_name);
        printf("\n student ID : %d",std[i].std_id);
        printf("\n student birth date (day//month//year): %d",std[i].day);
        printf("// %d",std[i].month);
        printf("// %d", std[i].year);
        printf("\n student last year score: %d", std[i].std_score);
        printf("\n*******************************\n");
    }
   }

}

void enter_in_the_mddle_dynamic_array(){

    std =(struct students *)realloc(std,n*sizeof( struct students));
    for(int i=n-1;i>=new_std;i--){
    strcpy(std[i].std_name,std[i-1].std_name);
    std[i].std_id=std[i-1].std_id;
    std[i].day=std[i-1].day;
    std[i].month=std[i-1].month;
    std[i].year=std[i-1].year;
    std[i].std_score=std[i-1].std_score;
    }

    printf("\n enter student %d name \n",new_std);
    scanf("%s",std[new_std-1].std_name);
    printf("\n enter student %d ID \n",new_std);
    scanf("%d",&std[new_std-1].std_id);
    printf("\n enter student %d birth date day//month//year: \n",new_std);
    scanf("%d",&std[new_std-1].day);
    scanf("%d",&std[new_std-1].month);
    scanf("%d",&std[new_std-1].year);
    printf("\n enter student %d last year score:",new_std);
    scanf("%d",&std[new_std-1].std_score);

}
void enter_at_the_beginnig_dynamic_array(){

    std =(struct students *)realloc(std,n*sizeof( struct students));
    for(int i=n-1;i>=new_std;i--){
    strcpy(std[i].std_name,std[i-1].std_name);
    std[i].std_id=std[i-1].std_id;
    std[i].day=std[i-1].day;
    std[i].month=std[i-1].month;
    std[i].year=std[i-1].year;
    std[i].std_score=std[i-1].std_score;
    }

    printf("\n enter student %d name \n",new_std);
    scanf("%s",std[new_std-1].std_name);
    printf("\n enter student %d ID \n",new_std);
    scanf("%d",&std[new_std-1].std_id);
    printf("\n enter student %d birth date day//month//year: \n",new_std);
    scanf("%d",&std[new_std-1].day);
    scanf("%d",&std[new_std-1].month);
    scanf("%d",&std[new_std-1].year);
    printf("\n enter student %d last year score:",new_std);
    scanf("%d",&std[new_std-1].std_score);

}
 void enter_at_the_end_dynamic_array(){

    std =(struct students *)realloc(std,n*sizeof( struct students));
    for(int i=n-1;i>=new_std;i--){
    strcpy(std[i].std_name,std[i-1].std_name);
    std[i].std_id=std[i-1].std_id;
    std[i].day=std[i-1].day;
    std[i].month=std[i-1].month;
    std[i].year=std[i-1].year;
    std[i].std_score=std[i-1].std_score;
    }

    printf("\n enter student %d name \n",new_std);
    scanf("%s",std[new_std-1].std_name);
    printf("\n enter student %d ID \n",new_std);
    scanf("%d",&std[new_std-1].std_id);
    printf("\n enter student %d birth date day//month//year: \n",new_std);
    scanf("%d",&std[new_std-1].day);
    scanf("%d",&std[new_std-1].month);
    scanf("%d",&std[new_std-1].year);
    printf("\n enter student %d last year score:",new_std);
    scanf("%d",&std[new_std-1].std_score);

 }


