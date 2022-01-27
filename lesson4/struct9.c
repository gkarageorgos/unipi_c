#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int am;
    char name[20];
    char surname[20];
    struct student *next;
};
struct student *head;

void add(int am, char name[20], char surname[20]){
    struct student *pts;
    pts= malloc(sizeof(struct student));
    pts->am = am;
    strcpy(pts->name,name);
    strcpy(pts->surname,surname);
    if(head==NULL){
        pts->next = NULL;
        head = pts;
    } else{
        pts->next = head;
        head = pts;
    }
}

void readAll(){
    struct student *temp;
    temp=head;
    if(temp==NULL){
        return;
    }
    printf("*****************************************************\n");
    while (temp!=NULL){
        printf("Student: %s %s, with am:%d\n", temp->name, temp->surname, temp->am);
        temp=temp->next;
    }
    printf("*****************************************************\n");
}

void delete_by_am(int am){
	struct student *temp;
	temp = head;
	int count = 0;
	while (temp != NULL){
		count++;
		if (temp->am == am){
			break;
		}
		temp = temp->next;
	}
	if (temp == NULL){
		if (count == 0){
			printf("there are no students\n");
			return;
		}
		else {
			printf("There is not student with am %d\n", am);
			return;
		}
	}
	struct student *pts;
	pts = head;
	int i;
	if (count == 1){
		head = pts->next;
	}
	else {
		for (i = 1; i < (count -1); i++){
			pts = pts->next;
		}
		pts->next = (pts->next)->next;
	}
}

int main(){
    int i,AM;
    char stname[20],stsurname[20];
    while(1){
        printf("1.Add Student\n");
        printf("2.Display Students\n");
        printf("3.Delete Student\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&i);
        if (i==1){
            printf("Enter the student's AM:");
            scanf("%d",&AM);
            printf("Enter the student's name:");
            scanf("%s",stname);
            printf("Enter the student's surname:");
            scanf("%s",stsurname);
            add(AM,stname,stsurname);
        }
        else if (i==2){
            readAll();
        }
		else if (i==3){
			int user_input;
        	printf("Enter an am:");
        	scanf("%d", &user_input);
        	delete_by_am(user_input);
		}
		else if (i==4){
        	return 0;
		}
    }
    return 0;
}
