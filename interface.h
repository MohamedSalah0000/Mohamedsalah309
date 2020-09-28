//
// Created by HP EliteBook on 9/17/2020.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include "privileges.h"

#define MAX_LENGTH 50

void systemm_init(void);

void system_run (void);

void admin_mode(void);

void admin_menu (void);

void admin_function(void);

void user_mode(void);

void user_menu (void);

void user_function (int id);



#endif //INTERFACE_H
