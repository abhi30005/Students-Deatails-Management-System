#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    char stream[50];
    int roll;
    float marks[10];
    struct student *next;
};
typedef struct student node;
node *start = NULL;

int show(int roll){
	  node *temp = start;
    while (temp != NULL) {
    	if(temp->roll == roll){
            printf("\n Student Name:\n %s\n",temp->name);
            printf("\n Student Marks:\n %.2f\n",temp->marks);
            printf("\n Student Stream:\n %s\n",temp->stream);
    }
        temp = temp->next;
    }
}


int check(int roll){
    node *temp = start;
    while (temp != NULL) {
        if(temp->roll == roll){
            return 1;
        }
        temp = temp->next;
    }
}

void entry(char *name, char *stream,int roll, float marks) {

    if (check(roll)) {
        printf("Student with this roll number already exists..\n Sorry..!!\n");
        return;
    }
    node *new_node = (node*)malloc(sizeof(node));

    strcpy(new_node->name, name);
    strcpy(new_node->stream,stream);   
    new_node->roll = roll;
    int i;
    for(i=0;i<7;i++){
		new_node->marks[i] = marks;
    }
	new_node->next = NULL;
    if (start == NULL) {
        start=new_node;
    }
    else {
        node*ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    printf("\nCreate Successfully Done..\n");
}

void delete(int roll) {

    if (start == NULL) {
        printf("The list is empty, nothing to delete\n");
        return;
    }
    node*pre = NULL;
    node *cur = start;
    while (cur!= NULL && cur->roll != roll) {
        pre = cur;
        cur = cur->next;
    }
    if (cur== NULL) {
        printf("Student with this roll number not found\n");
        return;
    }
    if (pre == NULL) {
        start = cur->next;
    }
    else {
        pre->next = cur->next;
    }
    printf("\n\n Roll No %d Delete Successful...\n",roll);
	free(cur);
}

void replace(int roll, char *name,char *stream ,float marks) {
    if (start == NULL) {
        printf("The list is empty, nothing to replace\n");
        return;
    }
    node *cur = start;

    while (cur != NULL && cur->roll != roll) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Student with this roll number not found\n");
        return;
    }
    strcpy(cur->name, name);
    strcpy(cur->stream,stream);
   // cur->marks = marks;
    printf("\nReplace Successful..\n");
}

void display() {
	int i;
    if (start == NULL) {
        printf("The list is empty, nothing to display\n");
        return;
    }
  node *temp = start;
    printf("\nName\tDept.\tRoll\tMarks\n");
    printf("----\t----\t----\t-----\n");
	    while (temp != NULL) {
        printf("%s\t %s\t %d\t", temp->name,temp->stream,temp->roll);
        for(i=0;i<7;i++)
        	printf("%f\n",temp->marks[i]);
        temp = temp->next;
    }
}

int search(){
	int result=0,ch,roll;
    printf("\nEnter Roll No. for searching Student.\n");
	scanf("%d",&roll);
	result=check(roll);
	if(result!=1){
	printf("\nStudent Roll no. Not Found..!!\n");
//	menu();
	//return;
}
else{
	printf("\nStudent Details Found..\n");
	printf("\n Press 1 for show student Details..\n Press others for Return Main Menu.\n\n");
	scanf("%d",&ch);
if(ch==1){
	show(roll);
	}
else{
	menu();
	}	
	}
}

int menu() {
    int choice;
    printf("\n   #..Student Database..#\n\n");
    printf("-.-.-.-.-.-.-.-.-.-.-.-.-.-+\n");
    printf("1. Create student Details.  !\n");
    printf("2. Delete student Details.  !\n");
    printf("3. Replace student Details. !\n");
    printf("4. Search student Details.  !\n");    
    printf("5. Display student Details. !\n");
    printf("6. Exit.                    !");
    printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-+\n");
    printf("\n\n> Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice, roll,sum=0,i;
    char name[50];
    char stream[50];
    float marks[10];
    while (1) {
        choice = menu();
        system("cls");
        switch (choice) {
            case 1:
                printf("Enter name:\n");
                scanf("%s",name);
                printf("Enter Stream:\n");
                scanf("%s",stream);
                printf("Enter roll number:\n");
                scanf("%d",&roll);
                printf("Enter marks:\n");
                for(i=0;i<7;i++)
                	scanf("%f",&marks[i]);
                entry(name,stream,roll, *marks);
                break;
            case 2: 
                printf("Enter the roll number of the student to be deleted\n");
                scanf("%d", &roll);
                delete(roll);
                break;
            case 3: 
                printf("Enter the roll number of the student to be replaced\n");
                scanf("%d", &roll);
                sum=check(roll);
                if(sum==0)
                 printf("Roll not Found...!!\n");
				else{
				printf("Enter name:\n");
                scanf("%s",name);
				printf("Enter Stream:\n");
                scanf("%s",stream);
                printf("Enter marks:\n");
                scanf("%f",&marks);
                replace(roll, name,stream, *marks);
            }
                break;
            case 4:
            	search();
            	break;
            case 5: 
                display();
                break;
            case 6:
                printf(" Thank you..!!\n");
                exit(0);
            default:
                printf(" Invalid choice..!!\n please try again....\n");
        }
    }
    return 0;
}
