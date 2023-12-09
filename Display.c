#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Fonction.h"
#include "timer.h"
#include "Display.h"


void ContactFileToList(t_d_list_level* list)
{
    FILE* f = fopen("C:\\Users\\camil\\CLionProjects\\final\\f.txt","r");//open my file with all my contact
    t_d_entry* c = (t_d_entry*)malloc( 1100* sizeof(t_d_entry));

    for(int i = 0; i<500;i++)
    {
        char contact[100];
        fgets(contact,99,f);
        contact[strlen(contact)-1]='\0';
        c[i] = CreateEntry1(contact);
        InsertCroissantList(c+i,list);
    }

    fclose(f);//close my contact file
}//MARCHE

void Test_time(t_d_list_level* list)
{
    FILE *C = fopen("C:\\Users\\camil\\CLionProjects\\final\\Classic.txt","w+");
    FILE *L = fopen("C:\\Users\\camil\\CLionProjects\\final\\Level.txt","w+");
    for(int j = 0; j < 500; j++)
    {
        FILE *f = fopen("C:\\Users\\camil\\CLionProjects\\final\\f.txt", "r");//open my file with all my contact

        printf("Classic Search %d",j);
        startTimer();
        for (int i = 0; i < j; i++) {
            char contact[100];
            fgets(contact, 99, f);
            contact[strlen(contact) - 1] = '\0';
            char *n = (char *) malloc(3 * sizeof(char));//my 3 first letter temp
            for (int m = 0; m < 3; m++) {
                n[m] = contact[m];
            }
            n[3] = '\0';
            SimpleSearch(n, *list);
        }
        stopTimer();
        displayTime();
        fprintf(C,"%s\n",getTimeAsString());

        fclose(f);//close my contact file

        FILE *f1 = fopen("C:\\Users\\camil\\CLionProjects\\final\\f.txt", "r");//open my file with all my contact

        printf("Level Search %d",j);
        startTimer();
        for (int i = 0; i < j; i++) {
            char contact[100];
            fgets(contact, 99, f1);
            contact[strlen(contact) - 1] = '\0';
            LevelSearch(contact, *list);
        }
        stopTimer();
        displayTime();
        fprintf(L,"%s\n",getTimeAsString());
        fclose(f1);//close my contact file

        printf("\n");
        }
    fclose(C);
    fclose(L);

    printf("You got your values in your associates files ;3 *wink wink*\n");
}

t_d_entry* Search(t_d_list_level* list)
{
    char o[4];
    printf(">> Enter the 3 first letters in lower case of the name you're looking for:\n");
    printf(">>");
    scanf("%s",o);
    t_d_entry* d = LevelSearch(o,*list);

    if (d!= NULL)
    {
        t_d_entry** l = (t_d_entry**)malloc(50 * sizeof(t_d_entry *));
        int i = 0;
        char* n1= Getname(d->contact.name );
        char*n = (char*)malloc(3* sizeof(char));
        for(int m = 0;m<3;m++)
        {
            n[m]=n1[m];

        }
        n[3]='\0';
        int v = 1;

        while(v==1)
        {
            l[i++]= d;
            d = d->search[0];
            n1= Getname(d->contact.name );
            n = (char*)malloc(3* sizeof(char));
            for(int m = 0;m<3;m++)
            {
                n[m]=n1[m];

            }
            n[3]='\0';
            if(strcmp(o,n)!=0)
            {
                v=0;
            }

        }
        printf("\n\n>> select the wished contact :\n");
        int j ;
        for (j = 0; j<i;j++)
        {
            char** Name = GetNAME(l[j]->contact.name);
            printf("[%d]  %s %s\n",j,Name[1],Name[0]);
        }
        printf("[%d] None\n",j++);
        int s=-1;
        while(s<0 || s>j)
        {
            printf(">>");
            scanf("%d",&s);
        }
        if (s==j-1)
        {
            d = NULL;
        }
        else
        {
            d=l[s];
        }

        return d;
    }
    else
    {
        printf(">> there is no such name\n");
        return d;

    }

}//MARCHE

void menuMain()
{
    printf("%c", 201);
    for (int i = 0; i < 50; i++) { printf("%c", 205); }
    printf("%c\n", 187);
    printf("%c                                                  %c\n", 186, 186);
    printf("%c             Welcome to C-Project L2              %c\n", 186, 186);
    printf("%c                                                  %c\n", 186, 186);
    printf("%c                [1] Part 1 & 2                    %c\n", 186, 186);
    printf("%c                                                  %c\n", 186, 186);
    printf("%c                [2] Part 3                        %c\n", 186, 186);
    printf("%c                                                  %c\n", 186, 186);
    printf("%c                [3] Quit                          %c\n", 186, 186);
    printf("%c                                                  %c\n", 186, 186);
    printf("%c", 200);
    for (int i = 0; i < 50; i++) { printf("%c", 205); }
    printf("%c\n", 188);

}
//MENU DE BASE

void menuP12()
{
    printf("%c",201);
    for(int i =0; i<50;i++)
    {printf("%c",205);}
    printf("%c\n",187);
    printf("%c                                                  %c\n",186,186);
    printf("%c                   Part 1 & 2                     %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [1] Create & Display List         %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [2] Time Execution                %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [3] Main Menu                     %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [4] Quit                          %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c",200);
    for(int i =0; i<50;i++)
    {printf("%c",205);}
    printf("%c\n",188);
}


void menuBASE()
{
    printf("%c",201);
    for(int i =0; i<50;i++)
    {printf("%c",205);}
    printf("%c\n",187);
    printf("%c                                                  %c\n",186,186);
    printf("%c                   Welcome to Diary               %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [1] Search contact                %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [2] Add contact                   %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [3] Time Execution                %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [4] Display List                  %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [5] Main Menu                     %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c                [6] Quit                          %c\n",186,186);
    printf("%c                                                  %c\n",186,186);
    printf("%c",200);
    for(int i =0; i<50;i++)
    {printf("%c",205);}
    printf("%c\n",188);
}

