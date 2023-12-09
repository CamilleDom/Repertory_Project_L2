#ifndef UNTITLED_FICHIER_H
#define UNTITLED_FICHIER_H

#include <stdio.h>
#include <stdbool.h>


///// PARTIE 1
typedef struct s_d_cell
{
    int value;
    int nb_next;
    struct s_d_cell** tab_next;
}t_d_cell;

t_d_cell P_CreateCell(int value,int nb_next);


typedef struct s_d_list
{
    int nb_level;
    struct s_d_cell** tab_heads;
}t_d_list;

t_d_list P_CreateList(int nb_level);
bool P_InsertList(t_d_cell* cell, t_d_list* list);
void P_DisplayLevel(int level,t_d_list list);
void P_DisplayLevelsList(t_d_list list);
void nDisplayAlignedLevelsList(t_d_list* list);
void P_DisplayAlignedLevelsList(t_d_list list);
void P_InsertCroissantList(t_d_cell* cell, t_d_list* list);

///// PARTIE 2

t_d_list P_CreateLevelList(int nb);
bool P_ClassicSearch(int value, t_d_list list);
bool P_LevelSearch(int value, t_d_list list);

#endif