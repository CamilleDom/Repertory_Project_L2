#ifndef UNTITLED_FONCTION_H
#define UNTITLED_FONCTION_H

#include <stdio.h>
#include <stdbool.h>
// contact
typedef struct s_d_contact
{
    char* name;//name_firstname

}t_d_contact;

// appointment
typedef struct s_d_appointment
{
    char* date; //jj/mm/yyyy
    char* hour; // hh:mm
    char* time; //hh:mm
    char* goal;

}t_d_appointment;

// cell for simply linked list
typedef struct s_cell
{
    struct s_d_appointment* appointment;
    struct s_cell* next;

}t_cell;

// simply linked list
typedef struct s_std_list
{
    t_cell* head;

}t_std_list;

// entry
typedef struct s_d_entry
{
    struct s_d_contact contact;
    t_std_list* list;
    int nbcap;
    struct s_d_entry** search;
    int lv;

}t_d_entry;

// level list
typedef struct s_d_list_level
{
    struct s_d_entry** tab_heads;
    int nb_level;

}t_d_list_level;

//Create Structure
t_d_contact CreateContact();
t_d_appointment* CreateAppointment();
t_cell* CreateCell();
t_std_list* CreateEmptyList();
t_d_entry CreateEntry();
t_d_entry CreateEntry1(char* c);
t_d_list_level CreateList(int nb_level);

// Scan Functions
char* ScanNAME();
char* scanDate();
char* scanHours();
char* scanTime();
char* scanGoal();
char* Getname(char* contact);
char** GetNAME(char* contact);
char** GetDATE(char* date);
char** GetHT(char* ht);


//insert List
void InsertList(t_d_entry* entry, t_d_list_level * list);
void InsertCroissantList(t_d_entry* entry, t_d_list_level * list);


int DisplayAppointment(t_d_entry entry);
void CreateInsertAppointment(t_d_entry* entry);
void DeleteAppointment(t_d_entry* entry);
void SaveAppointmentfile();
void LoadAppointmentfile();
/*t_cell* Create1Cell();*/

// Display
void DisplayLevel(int level,t_d_list_level list);
void DisplayLevelsList(t_d_list_level list);

//Search function
t_d_entry* LevelSearch(char* value, t_d_list_level list);
int SimpleSearch(char* value, t_d_list_level list);


#endif