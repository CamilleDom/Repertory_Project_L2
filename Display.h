#ifndef UNTITLED_DISPLAY_H
#define UNTITLED_DISPLAY_H

#include <stdio.h>
#include <stdbool.h>

void menuMain();
void menuP12();
void menuBASE();
void ContactFileToList(t_d_list_level* list);
t_d_entry* Search(t_d_list_level* list);
void Test_time(t_d_list_level* list);
#endif