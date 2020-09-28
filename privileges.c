//
// Created by HP EliteBook on 9/17/2020.
//

#include <stdio.h>
#include "privileges.h"

static char *currentAdminPassword;
static student_t student[MAX_RECORDS];
static int availableStudentIndex[MAX_RECORDS];
static int availableIndex=0;
static void saferFree(void **pp);
static int get_id_index(int id);


void set_admin_password(void){
	currentAdminPassword = (char*)malloc(strlen("0000") + 1);
	strcpy(currentAdminPassword,"0000");
}

int check_admin_password(char *adminPassword){

	int flag;

	if (strcmp(currentAdminPassword,adminPassword) == 0 )


		flag =0;
	else
		flag=1;
	return flag;
}


void change_admin_password (char *newAdminPassword){

	currentAdminPassword=realloc(currentAdminPassword,strlen(newAdminPassword)+1);

	strcpy(currentAdminPassword,newAdminPassword);

}

int check_user_id_password(int id,char *password){

	int i, flag=0;
	for (i=0; i < MAX_RECORDS && flag == 0; i++){
		if(student[i].id == id && strcmp (student[i].password,password) == 0){
			flag=1;
		}
		else {
			flag=0;
		}
	}
	return flag;
}

int available_index(){

	int i,flag=0;
	for (i=0; i < MAX_RECORDS && flag == 0; i++){

		if(availableStudentIndex[i] == 0){

			flag=1;
			availableIndex=i;
			availableStudentIndex[i]=1;
		}
		else{
			flag=0;
		}
	}

	return flag;
}

int add_student_record(char *name,char *password,int degree,int id){
	int flag;
	if(available_index() && get_id_index(id) == -1){


		student[availableIndex].name=(char*)malloc(strlen(name) + 1);
		strcpy(student[availableIndex].name,name);

		student[availableIndex].password=(char*)malloc(strlen(password) + 1);
		strcpy(student[availableIndex].password,password);

		student[availableIndex].degree=degree;
		/*     check avalible id   */

		student[availableIndex].id=id;

		flag=1;

	}
	else{
		flag=0;
	}

	return flag;
}

static int get_id_index(int id)
{
	int i;
	for (i = 0; i < MAX_RECORDS; ++i)
	{
		if (availableStudentIndex[i] == 1 && student[i].id == id)
			return i;
	}
	return -1;
}


int change_student_name(int id,char *name){

	int i, flag =0;
	int index = get_id_index(id);
	if(index != -1)
	{

		student[index].name=realloc(student[index].name, strlen(name) + 1);
		strcpy(student[index].name,name);
		flag=1;
	}
	else {
		flag=0;
	}
	return flag;
}


int change_student_password(int id,char *password){

	int i, flag =0;
	i = get_id_index(id);
	if(i != -1){

			student[i].password =realloc(student[i].password, strlen(password) + 1);
			strcpy(student[i].password,password);
			printf("password changed successfully\n");
			flag=1;
		}
		else {
			flag=0;
		}




	return flag;
}




int change_student_degree(int id,int degree){

	int i, flag =0;
	i = get_id_index(id);
	if(i != -1){
			student[i].degree=degree;
			printf("degree changed successfully\n");
			flag=1;
		}
		else {
			flag=0;
		}



	return flag;
}
int view_student_info(int id){

	int i, flag =0;
	i = get_id_index(id);
	if(i != -1){
		printf("student name:%s\n",student[i].name);
		printf("student password:%s\n",student[i].password);
		printf("student degree:%d\n",student[i].degree);
		flag=1;

	}
	else {
		flag=0;
		printf("wrong id\n");
	}

	return flag;
}

int remove_student_record(int id){

	int i, flag =0;
	for (i=0; i < MAX_RECORDS && flag == 0; i++){
		if(student[i].id == id){

			safeFree(student[i].name);
			safeFree(student[i].password);
			student[i].degree=0;


			flag=1;
		}
		else {
			flag=0;
		}

	}

	return flag;
}



static void saferFree(void **pp)
{
	if (pp != NULL && *pp != NULL) {
		free(*pp);
		*pp = NULL;
	}
}
