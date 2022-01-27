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

void the_number_of_Students(){
	struct student *temp;
	temp = head;
	int count = 0;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	printf("The number of students is %d\n", count);
}

void search_by_am(int am){
	struct student *temp;
	temp = head;
	while (temp != NULL){
		if (temp->am == am){
			printf("The student %s %s has am %d\n", temp->name, temp->surname, temp->am);
			return;
		}
		temp = temp->next;
	}
	printf("There is not student with am %d\n", am);
}

void search_name(char name[20]) {
	struct student *temp;
	temp = head;
	int count = 0;
	while (temp != NULL){
		if (strcmp(temp->name,name) == 0){
			count++;
		}
		temp = temp->next;
	}
	printf("The number of students with name: %s is %d\n", name, count);
}

void new_data_by_am (int am){
	struct student *temp;
	temp = head;
	int i;
	char name[20], surname[20];
	while (temp != NULL){
		if (temp->am == am){
			printf("Do you want to change the name %s?\n", temp->name);
			printf("Enter 1 for changing name, or else enter 0:");
			scanf("%d", &i);
			if (i){
				printf("Enter the new student's name:");
				scanf("%s", name);
				strcpy(temp->name, name);
			}
			printf("Do you want to change the surname %s?\n", temp->surname);
			printf("Enter 1 for changing surname, or else enter 0:");
			scanf("%d", &i);
			if (i){
				printf("Enter the new student's surname:");
				scanf("%s", surname);
				strcpy(temp->surname, surname);
			}
			return;
		}
		temp = temp->next;
	}
	printf("There is not student with am %d\n", am);
}

void delete(int n){
	struct student *temp;
	temp = head;
	int i;
	if (n == 1){
		head = temp->next;
		return;
	}
	else {
		for (i = 1; i < (n - 1); i++){
			temp = temp->next;
		}
		temp->next = (temp->next)->next;
	}
}

int main(){
    int i,AM;
    char stname[20],stsurname[20];
    while(1){
        printf("1.Add Student\n");
        printf("2.Display Students\n");
        printf("3.Display the number of Students\n");
        printf("4.Search by am\n");
        printf("5.Search name\n");
        printf("6.Change the data\n");
        printf("7.Delete Student\n");
        printf("8.Exit\n");
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
        	the_number_of_Students();
		}
        else if (i==4){
        	int user_input;
        	printf("Enter an am:");
        	scanf("%d", &user_input);
            search_by_am(user_input);
        }
        else if (i==5){
        	char user_input[20];
        	printf("Enter a name:");
        	scanf("%s", user_input);
            search_name(user_input);
		}
		else if (i==6){
        	int user_input;
        	printf("Enter the am:");
        	scanf("%d", &user_input);
            new_data_by_am(user_input);
		}
		else if (i==7){
			the_number_of_Students();
			int user_input;
			printf("which student do you want me to delete?");
			scanf("%d", &user_input);
        	delete(user_input);
		}
		else if (i==8){
        	return 0;
		}
    }
    return 0;
}
