#include <stdio.h>
#include "Fonction.h"
#include "fichier.h"
#include "Display.h"
#include "timer.h"

int main()
{
    int Main_loop =1;
    int s=-1;//input

    while(Main_loop)
    {
        menuMain();//Main Menu
        while(s<1 || s>3)
        {
            printf(">>");
            scanf("%d",&s);
        }

        if(s==1)
        {
            s=-1;
            int one_two = 1;
            while(one_two)
            {
                menuP12();// Menue P 1&2
                while (s < 1 || s > 5)
                {
                    printf(">>");
                    scanf("%d", &s);
                }

                if(s==1)//create & display level list
                {
                    int nb =0;
                    printf("Enter a number of lv (inferior or equal to 10):\n>>");
                    scanf("%d",&nb);
                    t_d_list list = P_CreateLevelList(nb); // i create my list
                    printf("Display List:\n");
                    P_DisplayLevelsList(list);
                    printf("\nDisplay List Aligned:\n");
                    P_DisplayAlignedLevelsList(list); // to display
                    s=0;
                }
                if(s==2)// teste time
                {
                    int nb = 7;//as conseilled

                    for(int i = nb ; i < 16; i++) // we will test from a level list of 7 to a level list of 10
                    {
                        printf("\nLevel list of grade %d\n",i); // i print the the grad tested

                        t_d_list list = P_CreateLevelList(i); // i create my list
                        // DisplayAlignedLevelsList(list); // to display
                        int f;

                        printf("Classic Search ");
                        startTimer();
                        for(int j = 0; j < 10000 ;j++ )// i test 10000 different research in the list
                        {f = P_ClassicSearch(j, list);}
                        stopTimer();
                        displayTime();


                        printf("Level Search");
                        startTimer();
                        for(int j = 0; j < 10000 ;j++ )// i test 10000 different research in the list
                        {f =P_LevelSearch(j, list);}
                        stopTimer();
                        displayTime();
                    }
                    printf("Confer Graph in Rapport\n\n");
                    s=0;
                }
                if(s==3)// Main Menu
                {
                    one_two = 0;
                    s=0;
                }
                if(s==4)//quit
                {
                    one_two = 0;
                    Main_loop = 0;
                    s=0;
                }
            }

            }
        if(s==2)
        {

            int three = 1;
            t_d_list_level list = CreateList(4);//create my list
            ContactFileToList(&list);//Get my contact from my contact File

            while(three)
            {
                s=-1;

                menuBASE();//Menu Part 3
                while(s<1|| s>6)
                {
                    printf(">>");
                    scanf("%d", &s);
                }
                if(s == 1) // Search
                {
                    t_d_entry* d = Search(&list);
                    if(d == NULL)// if contact not founded
                    {
                        printf("\n\n>> Do you want to Create a contact ?\n");
                        printf("[1] Yes\n");
                        printf("[2] No \n\n");
                        s=-1;
                        while(s<1 || s>2)
                        {
                            printf(">>");
                            scanf("%d",&s);
                        }
                        if(s==1)
                        {
                            t_d_entry new = CreateEntry();
                            InsertCroissantList(&new,&list);
                        }
                        s = 0;
                    }
                    else// if contact founded
                    {
                        int ap = DisplayAppointment(*d);// return 0 if there no appointment and 1 if there some appointment
                        s = 0;
                        if(ap==1)
                        {
                            printf(">> Do you want to Create an appointment ?\n");
                            printf("[1] Create Appointment\n");
                            printf("[2] No Thanks\n\n");
                            while(s<1 || s>2)
                            {
                                printf(">>");
                                scanf("%d",&s);
                            }
                            if(s==1)
                            {
                                CreateInsertAppointment(d);
                            }

                        }
                        else
                        {
                            printf(">> Do you want to Create an appointment ?\n");
                            printf("[1] Create Appointment\n");
                            printf("[2] No Thanks\n\n");
                            while(s<1 || s>2)
                            {
                                printf(">>");
                                scanf("%d",&s);
                            }
                            if(s==1)
                            {
                                CreateInsertAppointment(d);
                            }
                        }
                        s=0;
                    }
                    s=-1;

                }
                if(s==2)//Create contact
                {
                    t_d_entry new = CreateEntry();
                    InsertCroissantList(&new,&list);
                    s=0;
                }
                if(s==3)//Complexity
                {
                    Test_time(& list);
                }
                if(s==4)//Display list
                {
                    DisplayLevelsList(list);
                }
                if(s==5)//quit Part 3
                {
                    three = 0;
                }
                if(s==6)//quit Program
                {
                    three =0;
                    Main_loop=0;
                    s=0;
                }
            }

        }
        if(s==3)
        {
        Main_loop =0;
        }


    }

    return 0;
}