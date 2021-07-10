/*
ÃÊ‰ ’«»— ⁄»œ«··Â
‘Â«» „Õ„œ «Õ„œ„Õ„œ
„’ÿ›Ï

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

//*************************************************************
//*************************************************************
//********************linked list functions********************
//*************************************************************
//*************************************************************

 void create_linked_list(){

    printf("enter the number of students you want to add \n");
    scanf("%d",&n);
    if (n<=0){
    return;
    }
    struct studentL *newNode, *temp;
    head = (struct studentL *)malloc(sizeof(struct studentL));

    printf("\n enter student name \n");
    scanf("%s",&std_nameT);
    printf("\n enter student ID \n");
    scanf("%d",&std_idT);
    printf("\n enter student birth date day//month//year: \n");
    scanf("%d",&dayT);
    scanf("%d",&monthT);
    scanf("%d",&yearT);
    printf("\n enter student last year score:");
    scanf("%d",&std_scoreT);

    strcpy(head->std_nameL,std_nameT);
    head->std_idL = std_idT;
    head->dayL = dayT;
    head->monthL = monthT;
    head->yearL = yearT;
    head->std_scoreL = std_scoreT;
    head->next = NULL;
    temp = head;

    for(int i=2; i<=n; i++){
    newNode = (struct studentL *)malloc(sizeof(struct studentL));
    printf("\n enter student name \n");
    scanf("%s",&std_nameT);
    printf("\n enter student ID \n");
    scanf("%d",&std_idT);
    printf("\n enter student birth date day//month//year: \n");
    scanf("%d",&dayT);
    scanf("%d",&monthT);
    scanf("%d",&yearT);
    printf("\n enter student last year score:");
    scanf("%d",&std_scoreT);

    strcpy(newNode->std_nameL,std_nameT);
    newNode->std_idL = std_idT;
    newNode->dayL = dayT;
    newNode->monthL = monthT;
    newNode->yearL = yearT;
    newNode->std_scoreL = std_scoreT;
    newNode->next = NULL;
    temp->next = newNode;
    temp = temp->next;

    }
}

void show_students_list_linkedlist(){
    struct studentL*temp;

    if(n<=0)
    {
        printf("the list is empty \n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
           printf("\n\n student name : %s", temp->std_nameL);
           printf("\n student ID : %d",temp->std_idL);
           printf("\n student birth date (day//month//year): %d",temp->dayL);
           printf("// %d",temp->monthL);
           printf("// %d",temp->yearL);
           printf("\n student last year score: %d", temp->std_scoreL);
           printf("\n*******************************\n");
           temp = temp->next;
        }
    }
}



void enter_in_the_mddle_linkedlist(){

    struct studentL *newNode, *temp;

    newNode = (struct studentL*)malloc(sizeof(struct studentL));

    printf("\n enter student name \n");
    scanf("%s",&std_nameT);
    printf("\n enter student ID \n");
    scanf("%d",&std_idT);
    printf("\n enter student birth date day//month//year: \n");
    scanf("%d",&dayT);
    scanf("%d",&monthT);
    scanf("%d",&yearT);
    printf("\n enter student last year score:");
    scanf("%d",&std_scoreT);


    strcpy(newNode->std_nameL,std_nameT);
    newNode->std_idL = std_idT;
    newNode->dayL = dayT;
    newNode->monthL = monthT;
    newNode->yearL = yearT;
    newNode->std_scoreL = std_scoreT;
    newNode->next = NULL;
    temp = head;

    for(int i=2; i<new_std; i++)
        {
            temp = temp->next;
            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }



}


 void enter_at_the_beginnig_linkedlist(){

   struct studentL *newNode;
   newNode = (struct studentL*)malloc(sizeof(struct studentL));

    printf("\n enter student name \n");
    scanf("%s",&std_nameT);
    printf("\n enter student ID \n");
    scanf("%d",&std_idT);
    printf("\n enter student birth date day//month//year: \n");
    scanf("%d",&dayT);
    scanf("%d",&monthT);
    scanf("%d",&yearT);
    printf("\n enter student last year score:");
    scanf("%d",&std_scoreT);

    strcpy(newNode->std_nameL,std_nameT);
    newNode->std_idL = std_idT;
    newNode->dayL = dayT;
    newNode->monthL = monthT;
    newNode->yearL = yearT;
    newNode->std_scoreL = std_scoreT;
    newNode->next = head;
    head = newNode;

 }

 void enter_at_the_end_linkedlist(){

    struct studentL *newNode, *temp;

    newNode = (struct studentL*)malloc(sizeof(struct studentL));

    printf("\n enter student name \n");
    scanf("%s",&std_nameT);
    printf("\n enter student ID \n");
    scanf("%d",&std_idT);
    printf("\n enter student birth date day//month//year: \n");
    scanf("%d",&dayT);
    scanf("%d",&monthT);
    scanf("%d",&yearT);
    printf("\n enter student last year score:");
    scanf("%d",&std_scoreT);


    strcpy(newNode->std_nameL,std_nameT);
    newNode->std_idL = std_idT;
    newNode->dayL = dayT;
    newNode->monthL = monthT;
    newNode->yearL = yearT;
    newNode->std_scoreL = std_scoreT;
    newNode->next = NULL;
    temp = head;

    while(temp != NULL && temp->next != NULL){temp = temp->next;}

    temp->next = newNode;
 }

 void compare (int dummy){
       printf("\n*******************************************************\n");
       int* dump;
       clock_t begin = clock();
       dump = (int*)malloc(dummy * sizeof(int));
       for (int i = 0; i < dummy; ++i) {
            dump[i] = i + 1;
        }
        clock_t end = clock();
        timespent=(double)(end - begin)*1000/ CLOCKS_PER_SEC;
        printf("time spent to create dynamic array of %d elements: %1f ms \n",dummy ,timespent);



        clock_t begin6 = clock();
        dump =(int*)realloc(dump,(dummy+1)*sizeof(int));
        for(int i=dummy-1;i>=1;i--){
        dump[i]=dump[i-1];
        }
        dump[0]=1;
        clock_t end6 = clock();
        timespent=(double)(end6 - begin6)*1000/ CLOCKS_PER_SEC;
        printf("time spent to insert at the beginning of dynamic array of %d elements: %1f ms \n",dummy ,timespent);
        clock_t begin5 = clock();
        dump =(int*)realloc(dump,(dummy+1)*sizeof(int));
        for(int i=dummy-1;i>=(dummy/2);i--){
        dump[i]=dump[i-1];
        }
        dump[dummy/2]=1;
        clock_t end5 = clock();
        timespent=(double)(end5 - begin5)*1000/ CLOCKS_PER_SEC;
        printf("time spent to insert at the middle of dynamic array of %d elements: %1f ms \n",dummy ,timespent);
        clock_t begin7 = clock();
        dump =(int*)realloc(dump,(dummy+1)*sizeof(int));
        for(int i=dummy-1;i>=dummy+1;i--){
        dump[i]=dump[i-1];
        }
        dump[dummy]=1;
        clock_t end7 = clock();
        timespent=(double)(end7 - begin7)*1000/ CLOCKS_PER_SEC;
        printf("time spent to insert at the end of dynamic array of %d elements: %1f ms \n",dummy ,timespent);


        clock_t begin1 = clock();
        struct node *headnode,*newnode, *temp;
        headnode = (struct node *)malloc(sizeof(struct node));
        headnode->test=0;
        headnode->next = NULL;
        temp = headnode;
        for(int i=1 ; i<dummy; i++){
            newnode = (struct node *)malloc(sizeof(struct node));
		    newnode->test = i;
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
	    }
        clock_t end1 = clock();
        timespent=(double)(end1 - begin1)*1000/ CLOCKS_PER_SEC;
        printf("\ntime spent to create linked list of %d elements: %1f ms \n",dummy,timespent);

        clock_t begin2= clock();
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->test= 1;
        new_node->next= headnode;
        headnode= new_node;
        clock_t end2 = clock();
        timespent=(double)(end2 - begin2)*1000/ CLOCKS_PER_SEC;
        printf("time spent to insert at the beginning of linked list of %d elements: %1f ms \n",dummy,timespent);

        int z=0;
        clock_t begin4= clock();
        struct node* new_node2 = (struct node*) malloc(sizeof(struct node));
        new_node2->test=1;
        new_node2->next=NULL;
        struct node *last1=headnode;
        while (z<(dummy/2)){
        last1 = last1->next;
        z++;
        }
        last1->next = new_node2;
        clock_t end4 = clock();
        timespent=(double)(end4 - begin4)*1000/ CLOCKS_PER_SEC;
        printf("time spent to insert at the middle of linked list of %d elements: %1f ms \n",dummy,timespent);
        clock_t begin3= clock();
        struct node* new_node3 = (struct node*) malloc(sizeof(struct node));
        new_node3->test=1;
        new_node3->next=NULL;
        struct node *last=headnode;
        while (last->next != NULL){
        last = last->next;}
        last->next = new_node3;
        clock_t end3 = clock();
        timespent=(double)(end3 - begin3)*1000/ CLOCKS_PER_SEC;
        printf("time spent to insert at the end of linked list of %d elements: %1f ms \n",dummy,timespent);
        printf("\n*******************************************************\n");
        free(dump);
        struct node*tmp;
        while(head!=NULL){
        tmp=head;
        head=head->next;
        free(tmp);
        }

 }
