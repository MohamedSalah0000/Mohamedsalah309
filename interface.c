//
// Created by HP EliteBook on 9/17/2020.
//

#include "interface.h"

void system_init(){

    set_admin_password();
    printf("welcome to student record system");

}


void system_run (void){
	int mode;

	printf("enter the mode you need \n");

	printf("1.admin mode \n2.user mode\n");

	scanf("%d",&mode);

	while (mode !=1 && mode !=2 ){
		printf("wrong entry please try again \n");

		scanf("%d",&mode);
	}
	switch (mode){

	case 1 :
		admin_mode();
		break;

	case 2 :
		user_mode();
		break;
	default:
		break;
	}

}



void admin_mode(void){
	char adminPassword[MAX_LENGTH];

	printf("enter the password \n");

	fflush(stdin);
	gets(adminPassword);

	while (check_admin_password(adminPassword)){

		printf("wrong password \n");
		printf("enter the password again \n");
		fflush(stdin);
		gets(adminPassword);

	}

	admin_menu();
	admin_function ();

}

void admin_menu (void){

	printf("1.Add new student \n");
	printf("2.Edit student name.\n");
	printf("3.Edit student password \n");
	printf("4.Edit student degree. \n");
	printf("5.View student info. \n");
	printf("6.Remove student record.\n");
	printf("7.Edit admin password. \n");
	printf("8.return to main menu \n");


}


void admin_function(void){

	char studentName[MAX_LENGTH];
	char studentPassword[MAX_LENGTH];
	char adminPassword[MAX_LENGTH];
	int degree;
	int id;

	int choice = 0;
	printf("enter your choice \n");
	scanf("%d",&choice);
	while (choice < 1 || choice > 8){
		printf("wrong entry enter it again \n");
		scanf("%d",&choice);
	}

	switch(choice)
	{
	case 1:

		printf("enter student name \n");
		fflush(stdin);
		gets(studentName);

		printf("enter student password \n");
		fflush(stdin);
		gets(studentPassword);

		printf("enter student degree \n");
		scanf("%d",&degree);

		printf("enter student id \n");
		scanf("%d",&id);



		if (add_student_record(studentName,studentPassword,degree,id)){
			printf("added successfully \n");

		}
		else{
			printf("no capacity \n");
		}

		break;

	case 2:

		printf("enter student id \n");
		scanf("%d",&id);

		printf("enter the new student name \n");
		fflush(stdin);
		gets(studentName);

		if (change_student_name(id,studentName)){
			printf("the name has changed successful \n");
		}
		else{
			printf("the id is wrong \n");
		}
		break;


	case 3:

		printf("enter student id \n");
		scanf("%d",&id);

		printf("enter the new student password \n");
		fflush(stdin);
		gets(studentPassword);

		if (change_student_password(id,studentPassword)){
			printf("the password has changed successful \n");
		}
		else{
			printf("the id is wrong \n");
		}

		break;

	case 4:
		printf("enter student id \n");
		scanf("%d",&id);

		printf("enter the new student degree \n");
		scanf("%d",&degree);

		if (change_student_degree(id,degree)){
			printf("the degree has changed successful \n");
		}
		else{
			printf("the id is wrong \n");
		}
		break;

	case 5:
		printf("enter student id \n");
		scanf("%d",&id);
		view_student_info(id);

		break;

	case 6:
		printf("enter student id \n");
		scanf("%d",&id);
		if(remove_student_record(id)){

			printf("student removed successfully \n");
		}
		else{
			printf("the id is wrong \n");
		}


	case 7:
		printf("enter the new password \n");
		fflush(stdin);
		gets(adminPassword);
		change_admin_password(adminPassword);
		break;

	case 8:
		system_run();
		break;

	default:
		break;
	}
	admin_menu();
	admin_function();

}


void user_mode(void){

	int id;
	char password[MAX_LENGTH];

	printf("enter your id \n");

	scanf("%d",&id);

	printf("enter your password\n");
	fflush(stdin);
	gets(password);


	while (!check_user_id_password(id,password)){

		printf("wrong id or password please enter them again\n");


		printf("enter your id \n");

		scanf("%d",&id);

		printf("enter your password\n");
		fflush(stdin);
		gets(password);

	}
	user_menu();

	user_function(id);

}
void user_menu (void){

	printf("1.View your info. \n");
	printf("2.Edit your password. \n");
	printf("3.Return to main menu. \n");

}

void user_function (int id){
	char studentPassword[MAX_LENGTH];
	int choice =0;
	scanf("%d",&choice);
	while (choice <1 || choice >3){

		printf("wrong entery please try again \n");
		scanf("%d",&choice);

	}
	switch(choice)
	{
	case 1:
		view_student_info(id);
		break;

	case 2:

		printf("enter your new password \n");
		fflush(stdin);
		gets(studentPassword);
		change_student_password(id,studentPassword);
		break;

	case 3:
		system_run();
		break;
	}
	user_menu();
	user_function(id);
}





