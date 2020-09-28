//
// Created by HP EliteBook on 9/17/2020.
//

#ifndef PRIVILEGES_H
#define PRIVILEGES_H

#include <string.h>
#include <stdlib.h>
#include "struct.h"

#define safeFree(p) saferFree((void**)&(p))

#define MAX_RECORDS 10

void set_admin_password(void);

int check_admin_password(char *adminPassword);

void change_admin_password (char *newAdminPassword);

int check_user_id_password(int id,char *password);

int available_index();

int add_student_record(char *name,char *password,int degree,int id);

int check_avalible_id(int id);

int change_student_name(int id,char *name);

int change_student_password(int id,char *password);

int change_student_degree(int id,int degree);

int view_student_info(int id);

int remove_student_record(int id);

#endif //PRIVILEGES_H
