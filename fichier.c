#include "fichier.h"
#include <stdlib.h>
#include <math.h>

t_d_cell P_CreateCell(int value,int nb_next)
{
    t_d_cell cell;
    cell.tab_next= (t_d_cell**)malloc(nb_next * sizeof(t_d_cell*));
    cell.value = value;
    cell.nb_next = nb_next;
    for(int i = 0 ; i< nb_next; i++)
    {
        cell.tab_next[i] = NULL;
    }

    return cell;

} // MARCHE

t_d_list P_CreateList(int nb_level)
{

    t_d_list list;
    list.tab_heads = (t_d_cell**)malloc(nb_level * sizeof(t_d_cell *));
    list.nb_level= nb_level;
    for(int i = 0 ; i< nb_level; i++)
    {
        list.tab_heads[i] = NULL;
    }

    return list;

} // MARCHE

bool P_InsertList(t_d_cell* cell, t_d_list* list)
{
        cell->tab_next[0] = list->tab_heads[0];
        list->tab_heads[0] = cell ;

        for( int i = 1; i<cell->nb_next; i++)
        {
            cell->tab_next[i] = list->tab_heads[i];
            list->tab_heads[i] = cell ;

        }
        return 1;
} //MARCHE

void P_DisplayLevel(int level,t_d_list list)
{
    printf("[list head_%d @-]-->",level);// print list head level

    if (list.tab_heads[level] == NULL)
    {
        printf("NULL\n");// printf null
    }
    else
    {
        t_d_cell *p = list.tab_heads[level];
        while (p->tab_next[level] != NULL) {
            printf("[%d|@-]-->",p-> value);// printf p-> value
            p = p->tab_next[level];
        }
        printf("[%d|@-]-->",p-> value);// printf p-> value
        printf(" NULL\n");// printf null
    }


} // MARCHE

void P_DisplayLevelsList(t_d_list list) // MARCHE
{
    int nb = list.nb_level;
    for ( int i = 0; i<nb; i++)
    {
        P_DisplayLevel(i,list);
    }

}

void P_DisplayAlignedLevelsList(t_d_list list)
{
    P_DisplayLevel(0,list); // Display Head 0

    // Create a list w/ value of all cell in order 0
    int nb[1000];
    int i=0;
    t_d_cell* temp = list.tab_heads[0];
    while(temp->tab_next[0]!= NULL)
    {
        nb[i++] = temp->value;
        temp = temp->tab_next[0];
    }
    nb[i]=temp->value;
    int last = i;

    //Display in aligned order
    for (int j=1;j<list.nb_level; j++)
    {
        temp = list.tab_heads[j];
        i=0;
        int pos = 0;
        int sup ;
        printf("[list head_%d @-]--",j);

        while( temp != NULL)// temps que pas en bou de ligne
        {
            while( nb[i] != temp->value ) // temp que les valeur son pas egale je met des trait
            {
                if(nb[i] >= 10 ) // +1 si deux chiffre (nombre ? je sais jamais)
                {
                    printf("----------");
                }
                if(nb[i] < 10)
                {

                    printf("---------");
                }
                i++;
            }
            printf(">[%d|@-]--",temp->value);// quand cest egal je l'écrit
            temp = temp->tab_next[j];
            i++;
        }
        while(i<=last) // put all the NULL at the same pixel
        {

            if(nb[i] >= 10 ) // +1 si deux chiffre (nombre ? je sais jamais)
            {
                printf("----------");
            }
            if(nb[i] < 10)
            {

                printf("---------");
            }
            i++;


        }
        printf("> NULL\n");// printf null // quand plus de valeur je termine


    }
} // MARCHE

void P_InsertCroissantList(t_d_cell* cell, t_d_list* list)
{
    int nb = list->nb_level;
    int i = 0;
    t_d_cell *temp = list->tab_heads[0], *temp1;
    int h = 1; // my temp1 is a head



    //i look where should be my cell to keep the order
    if (temp == NULL) // if Empty i insert by the head
    {
        P_InsertList(cell, list);

    } else // if not empty
    {
        int pos = -1;

        while (temp != NULL) // i run while im empty
        {
            if (temp->value > cell->value) //  if i fond a superior of my value
            {
                // i install the cell in the place
                cell->tab_next[0] = temp;// the next of my cell is the first sup

                if (h == 1) // if im at the head
                {
                    list->tab_heads[0] = cell;
                } else // else
                {
                    temp1->tab_next[0] = cell;// the previous point on the cell
                }
                pos = i;
                break;
            } else {
                temp1 = temp;
                temp = temp->tab_next[0];
                i++;
                h = 0; // my temp is not a head
            }
        }

        if (pos == -1)// if cell val > all values
        {
            pos = i++;// i install at the end
            // i install the cell in the place
            cell->tab_next[0] = NULL;// the next of my cell is NULL ( im at the end)
            temp1->tab_next[0] = cell;// the previous point on the cell

        }

        // i connect

        for (i = 1; i < nb; i++)// for each head
        {
            temp = list->tab_heads[i], temp1 = NULL;
            h = 1; // temp1 is a head
            if (i < cell->nb_next) // if i have a next of the current level
            {
                int p = 0;

                while (p != 1)// while cell not connected at the level

                    if (temp == NULL) {
                        if (h == 1) {
                            list->tab_heads[i] = cell;
                        } else {
                            temp1->tab_next[i] = cell;
                        }
                        cell->tab_next[i] = NULL;
                        p = 1;
                    } else {
                        if (temp->value > cell->value) {
                            if (h == 1) {
                                list->tab_heads[i] = cell;
                            } else {
                                temp1->tab_next[i] = cell;
                            }

                            cell->tab_next[i] = temp;
                            p = 1;
                        } else {
                            temp1 = temp;
                            temp = temp->tab_next[i];
                            h = 0; // temp1 arent a head
                        }
                    }
            }

        }

    }

}//MARCHE

t_d_list P_CreateLevelList(int nb)
{
    t_d_list list = P_CreateList(nb);// create my level list

    double cell = pow(2,nb)-1; // nb of cell in list

    int level[(int)(cell)];// create a list with each cell equal nb level of each cell of my level list

    // initialise the list to 0
    for( int i = 0; i<cell; i++)
    {
        level[i] = 0;
    }

    int f = 2; // jump to fill ( 1/2 , 1/4 , 1/8 ...)

    int pos =1;// we start at 1 ( cell 0 always level 0)

    // loop to find level of each cell
    for(int i = 0;i <nb;i++)
    {
        while ( pos < cell -1 )// while im in my list
        {
            level[pos] ++;

            pos= pos + f;// we jump
        }

        f = f +f ; // i augment my jump for the next level
        pos = f-1; // my next start


    }


    // now we create each cell


    t_d_cell* c= (t_d_cell*)malloc(cell* sizeof(t_d_cell ));

    for ( int i=0; i<cell;i++)
    {
        c[i] = P_CreateCell(i+1,level[i]+1);
    }

    for (int i=0; i<cell ; i++)
    {
        P_InsertCroissantList(c+i,&list);
    }

    return list;
} // MARCHE

bool P_ClassicSearch(int value, t_d_list list)
{
    t_d_cell *temp = list.tab_heads[0];
    int found = 0, i = 0;
    if(temp != NULL)
    {
        while(temp != NULL && found == 0 )
        {
            if(temp->value == value)
            {
                found = 1;
            }
            temp = temp->tab_next[0];

        }

    }
    return found;
} //MARCHE

bool P_LevelSearch(int value, t_d_list list)
{
    int found = 0;
    int level= (list.nb_level)-1;
    t_d_cell* temp =list.tab_heads[level], *temp1=NULL ;
    int h = 1; // temp1 is a head

    while(found == 0 && level >-1)
    {
        if(temp->value == value)
    {
        found = 1;
    }
        else
    {

        if(temp->value > value)
        {

            if(h == 1)
            {
                temp = list.tab_heads[--level];
            }
            else
            {
                temp = temp1->tab_next[--level];
            }
        }
        else
        {
            if(temp->value < value)
            {
                if(temp->tab_next[level] == NULL)
                {
                    temp1 = temp;
                    temp = temp->tab_next[--level];
                    h =0;

                }
                else
                {
                    temp1 = temp;
                    temp = temp->tab_next[level];
                    h =0;
                }
            }
        }
    }


    }



    return found;
} // MARCHE