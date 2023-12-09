#include "Fonction.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Scan Function
char* ScanNAME()
{
    char name[100],Name[100];
    char* merge = (char*)malloc(200*sizeof (char));

    printf("Enter the name of the contact (form \"Firstname Name\"): \n");
    printf(">>");
    scanf("%s %s",name,Name);

   for(int i = 0; i < strlen(name); i++) // get everything in lower case
    {
        name[i] = tolower(name[i]);
    }

    for(int i = 0; i < strlen(Name); i++) // get everything in lower case
    {
        Name[i] = tolower(Name[i]);
    }

    for(int i = 0;i<strlen(Name);i++)// i insert in merge name
    {
        merge[i] = Name[i];
    }

    for(int i = 0;i<strlen(name)+1;i++)// i insert firstname
    {
        merge[i+strlen(Name)+1] = name[i];
    }
    merge[strlen(Name)]='_'; // i insert '_'

    return merge;

} // MARCHE
char* scanDate()
{
    char* day= (char*)malloc(3*sizeof (char));
    char* month= (char*)malloc(3*sizeof (char));
    char* year= (char*)malloc(5*sizeof (char));

    printf("Insert date of an the appointment ( dd/mm/yyyy) :\n>>");

    scanf("%s",year);
    char** Date= GetDATE(year);
    day = Date[0];
    month = Date[1];
    year = Date[2];

    if (strlen(year)!=4||strlen(month)!=2|| strlen(day)!=2)
    {
        printf("NOT A DATE\n");

        return scanDate();

    }
    else
    {
        if(day[0]<'0' || day[0]> '3'|| day[1]>'9' || day[1]<'0' || (day[1]=='0'&& day[0]=='0')||(day[0]=='3'&& day[1]>'1'))
        {
            printf("WRONG DAY\n");

            return scanDate();
        }
        else
        {
            if(month[0]<'0'||month[0]>'1' || month[1]>'9'|| month[1]<'0'||(month[1]=='0'&& month[0]=='0')||(month[0]=='1'&& month[1]>'3'))
            {
                printf("WRONG MONTH\n");

                return scanDate();
            }
            else
            {
                if((((month[0]=='0'&& month[1]=='2')||(month[0]=='0'&& month[1]=='4')||(month[0]=='0'&& month[1]=='6')||(month[0]=='0'&& month[1]=='9')||(month[0]=='1'&& month[1]=='1'))&&(day[0]=='3'&& day[1]>'0')))
                {
                    printf("NOT A 31 DAYS MONTH\n");

                    return scanDate();
                }
                else
                {
                    if((month[0]=='0'&& month[1]=='2')&&(day[0]>='3'||(day[0]>='2' && day[1]>'9')))
                    {
                        printf("WRONG February\n");
                        return scanDate();

                    }
                    else
                    {
                        char* o = (char*)malloc(10* sizeof(char));
                        for (int i = 0; i < 2; i++)// i insert in o name
                        {
                            o[i] = day[i];
                        }
                        o[2] = '/'; // i insert '_'
                        for (int i = 0; i < 2; i++)// i insert month
                        {
                            o[i + 2 + 1] = month[i];
                        }
                        o[5] = '/'; // i insert '_'
                        for (int i = 0; i < 4 + 1; i++)// i insert firstname
                        {
                            o[i + 2 + 2 + 2] = year[i];
                        }
                        return o;
                    }
                }
            }
        }

    }



}// MARCHE
char* scanHours()
{
    char* hour=(char*)malloc(3*sizeof (char)),*min;
    printf("Insert the appointment time ( hh:mm) :\n>>");
    scanf("%s",hour);
    char** N = GetHT(hour);
    hour = N[0];
    min = N[1];


    if (strlen(hour)!=2|| strlen(min)!=2)
    {
        printf("NOT AN HOURLY\n");

        return scanHours();

    }
    else
    {
        if(hour[0]<'0' || hour[0]> '2'|| hour[1]>'9' || hour[1]<'0' || (hour[0]=='2'&& hour[1]>'3'))
        {
            printf("WRONG HOUR\n");

            return scanHours();
        }
        else
        {
            if(min[0]<'0'||min[0]>'5' || min[1]>'9'|| min[1]<'0')
            {
                printf("WRONG MIN\n");

                return scanHours();
            }
            else
            {
                char* o = (char*)malloc(10* sizeof(char));
                for (int i = 0; i < 2; i++)// i insert in o name
                {
                    o[i] = hour[i];
                }
                o[2] = ':'; // i insert '_'
                for (int i = 0; i < 2+1; i++)// i insert month
                {
                    o[i + 2 + 1] = min[i];
                }

                return o;
            }


        }

    }



}//MARCHE
char* scanTime()
{
    char* hour=(char*)malloc(3*sizeof (char)),*min;
    printf("Insert the appointment time length ( hh:mm) :\n>>");
    scanf("%s",hour);
    char** N = GetHT(hour);
    hour = N[0];
    min = N[1];

    if (strlen(hour)!=2|| strlen(min)!=2)
    {
        printf("NOT A TIME LENGTH\n");

        return scanHours();

    }
    else
    {
        if(hour[0]<'0' || hour[0]> '2'|| hour[1]>'9' || hour[1]<'0' || (hour[0]=='2'&& hour[1]>'3'))
        {
            printf("WRONG HOUR\n");

            return scanHours();
        }
        else
        {
            if(min[0]<'0'||min[0]>'5' || min[1]>'9'|| min[1]<'0')
            {
                printf("WRONG MIN\n");

                return scanHours();
            }
            else
            {
                char* o = (char*)malloc(10* sizeof(char));
                for (int i = 0; i < 2; i++)// i insert in o name
                {
                    o[i] = hour[i];
                }
                o[2] = ':'; // i insert '_'
                for (int i = 0; i < 2+1; i++)// i insert month
                {
                    o[i + 2 + 1] = min[i];
                }

                return o;
            }


        }

    }



}//MARCHE
char* scanGoal()
{
    printf("Enter the Goal of the Appointment (only 100 characters, replaced all space by underscore): \n");
    char* goal = (char*)malloc(1000*sizeof (char));
    printf(">>");
    scanf(" %s", goal);// get my sentence "Firstname Name"
    if(strlen(goal)>100)
    {
        printf(">>To many characters");
        return scanGoal();
    }
    else
    {
        return goal;
    }

}//marche
char* Getname(char* contact)
{
    int i=0;
    char* c = (char*)malloc( 100* sizeof(char));
    while(contact[i]!='_')
    {
        c[i]=contact[i];
        i++;
    }
    c[i]='\0';

    return c;

}//MARCHE
char** GetNAME(char* contact)
{
    int i=0;
    char* c = (char*)malloc( 100* sizeof(char));
    while(contact[i]!='_')
    {
        if(i==0)
        {
            c[i]= toupper(contact[i]);
            i++;
        }
        else
        {
            c[i]=contact[i];
            i++;
        }
    }
    c[i++]='\0';
    char** N = (char**)malloc( 100* sizeof(char*));
    N[0]= c;
    char* C = (char*)malloc( 100* sizeof(char));
    int j=0;
    while(contact[i]!='\0')
    {
        if(j==0)
        {
            C[j++]= toupper(contact[i]);
            i++;
        }
        else
        {
            C[j++]=contact[i];
            i++;
        }

    }
    C[i]='\0';
    N[1]= C;


    return N;
}//MARCHE
char** GetDATE(char* date)
{
    int i=0;
    char** N =(char**)malloc( 100* sizeof(char*));
    char* day = (char*)malloc( 5* sizeof(char));
    char* month = (char*)malloc( 5* sizeof(char));
    char* year = (char*)malloc( 5* sizeof(char));
    int j=0;
    while(date[i]!='/')
    {
        day[j++]=date[i++];
    }
    day[j]='\0';
    N[0]= day;

    j=0;
    i++;
    while(date[i]!='/')
    {
        month[j++]=date[i++];
    }
    month[j]='\0';
    N[1]=month;

    j=0;
    i++;
    while(date[i]!='\0')
    {
        year[j++]=date[i++];
    }
    year[j]='\0';
    N[2]=year;

    return N;
}//MARCHE
char** GetHT(char* ht)
{
    int i=0;
    char** N =(char**)malloc( 100* sizeof(char*));
    char* hour = (char*)malloc( 5* sizeof(char));
    char* min = (char*)malloc( 5* sizeof(char));
    int j=0;
    while(ht[i]!=':')
    {
        hour[j++]=ht[i++];
    }
    hour[j]='\0';
    N[0]= hour;

    j=0;
    i++;
    while(ht[i]!='\0')
    {
        min[j++]=ht[i++];
    }
    min[j]='\0';
    N[1]=min;

    return N;
}//MARCHE

// Create Structure
t_d_contact CreateContact()
{
    t_d_contact contact;

    contact.name= ScanNAME();

    return contact;

}//MARCHE
t_d_appointment* CreateAppointment()
{
    t_d_appointment* ap = (t_d_appointment*)malloc( sizeof(t_d_appointment));
    ap->date = scanDate();
    ap->hour = scanHours();
    ap->time = scanTime();
    ap->goal = scanGoal();

    return ap;
}// MARCHE
t_cell* CreateCell()
{
    t_cell* cell = (t_cell*)malloc(sizeof (t_cell));
    cell->next = NULL;
    cell->appointment = CreateAppointment();

    return cell;
}//MARCHE
t_std_list* CreateEmptyList()
{
    t_std_list* list = (t_std_list*)malloc(sizeof (t_std_list));
    list->head = NULL;

    return list;
}//MARCHE
t_d_entry CreateEntry()
{
    t_d_entry entry;
    entry.contact = CreateContact();
    //t_std_list list = CreateEmptyList();
    entry.list = CreateEmptyList();
    entry.lv = 0;
    entry.nbcap= 0;
    entry.search = (t_d_entry**)malloc(4 * sizeof(t_d_entry *));
    for(int i = 0 ; i< 4; i++)
    {
        entry.search[i] = NULL;
    }

    return entry;
}//MARCHE
t_d_entry CreateEntry1(char* c)
{
    t_d_entry entry;
    char* o = (char*)malloc(strlen(c)+1 * sizeof(char));
    for(int i = 0;i<strlen(c)+1;i++)// i insert in o name
    {
        o[i] = c[i];
    }
    entry.contact.name = o;
    //t_std_list list = CreateEmptyList();
    entry.list = CreateEmptyList();
    entry.lv = 0;
    entry.nbcap = 0;
    entry.search = (t_d_entry**)malloc(4 * sizeof(t_d_entry *));
    for(int i = 0 ;i<4; i++)
    {
        entry.search[i] = NULL;
    }

    return entry;
}//MARCHE
t_d_list_level CreateList(int nb_level)
{

    t_d_list_level list;
    list.tab_heads = (t_d_entry**)malloc(nb_level * sizeof(t_d_entry *));
    list.nb_level= nb_level;
    for(int i = 0 ; i< nb_level; i++)
    {
        list.tab_heads[i] = NULL;
    }

    return list;

} // MAARCHE


//insert list
void InsertList(t_d_entry* entry, t_d_list_level * list)
{
    entry->search[0] = list->tab_heads[0];
    list->tab_heads[0] = entry ;

    for( int i = 1; i<4; i++)
    {
        entry->search[i] = list->tab_heads[i];
        list->tab_heads[i] = entry ;

    }
    entry->lv = 4;
}//MARCHE
void InsertCroissantList(t_d_entry* entry, t_d_list_level * list)
{
    int nb = 4;
    t_d_entry* temp = list->tab_heads[0], *temp1;
    char* n1= Getname(entry->contact.name );//name of my entry
    int h = 1; // my temp1 is a head

    //i look where should be my entry to keep the order
    if(temp == NULL)
    {
        InsertList(entry,list);
    }
    else
    {
        int pos = -1;// entry not yet install

        while(temp != NULL)
        {
            char* n2 = Getname(temp->contact.name );// split Fistname and name

            if(strcmp(n1, n2) == -1)// if name entry < name temp
            {
                entry->search[0] = temp;

                if(h == 1)// at the head
                {
                    list->tab_heads[0] = entry;
                }
                else
                {
                    temp1->search[0] = entry;
                }
                pos = 1;// cell install
                break;
            }
            else
            {
                if(strcmp(n1,n2)==1)// if name entry > name temp
                {

                    temp1 = temp ;
                    temp = temp->search[0];
                    h=0;
                }
            }
        }

        if(pos == -1)// at the end of the list
        {
            entry->search[0]= NULL;
            temp1->search[0]= entry;

        }

        // i connect


            int x ;// nb of character were interested of
            //DisplayLevelsList(*list);
           for (int j = 1; j<4; j++)
           {
               // at lv j we only care about the x first character
               if(j ==1)
               {
                   x = 3;
               }
               if(j == 2)
               {
                   x = 2;
               }
               if(j == 3)
               {
                   x = 1;
               }

               temp = list->tab_heads[j];// i take my head j
               temp1 = NULL;//im at a head so there's no previous
               h=1;// im at a head
               pos = -1;// my entry is not yet connected


               char*n = (char*)malloc(x+1* sizeof(char));// the part of our entry name were interested in
               char*N = (char*)malloc(x+1* sizeof(char));// the part of the temp name were interested in

               // i get the x first letter of my entry
               for(int m = 0;m<x;m++)
               {
                   n[m]=n1[m];

               }
               n[x]='\0';

               while(pos ==-1)// while my head is not connected
               {
                   if(temp == NULL)// if my current position is empty i connect
                   {
                       if (h == 1)
                       {
                           list->tab_heads[j] = entry;
                       } else {
                           temp1->search[j] = entry;
                       }
                       entry->search[j] = NULL;
                       entry->lv = j+1;
                       pos = 1;
                   }
                   else
                   {
                        char* n2 = Getname(temp->contact.name);
                       // i get the x first letter of my entry
                       for(int m = 0;m<x;m++)
                       {
                           N[m]=n2[m];

                       }
                       N[x]='\0';

                       if (strcmp(n, N) == 1)// if name entry > name temp
                       {
                           //i pass
                           temp1 = temp;
                           temp = temp->search[j];
                           h = 0;//no more at a head so we have a temp1

                       }
                       else
                       {
                           if (strcmp(n, N) == 0)//if x first letter same
                           {
                               if (strcmp(n1,n2 ) == -1)//if entry < temp
                               {
                                   // entry then first its him who must be connected
                                   entry->search[j] = temp->search[j];// entry get the next of temp
                                   temp->search[j] = NULL;// temp no more have a next since he will no more get connected
                                   entry->lv = j+1;
                                   temp->lv--;
                                   // now i connect entry to the head
                                   if (h == 1)
                                   {
                                       list->tab_heads[j] = entry;
                                   } else
                                   {
                                       temp1->search[j] = entry;
                                   }
                               }

                               pos =1;// it's connected
                           }
                           else {
                               if (strcmp(n, N) == -1)// if n < N
                               {
                                   entry->search[j] = temp;
                                   entry->lv = j+1;

                                   if (h == 1)
                                   {
                                       list->tab_heads[j] = entry;
                                   } else {
                                       temp1->search[j] = entry;
                                   }

                                   pos =1;


                               }
                           }
                       }
                   }

               }




           }



    }
}//MARCHE

//DisplayLEVEL
void DisplayLevelsList(t_d_list_level list)
{
    int nb = list.nb_level;
    for ( int i = 0; i<nb; i++)
    {
        DisplayLevel(i,list);
        printf("\n");
    }

}// MARCHE
void DisplayLevel(int level,t_d_list_level list)
{
    printf("[list head_%d @-]-->",level);// print list head level

    if (list.tab_heads[level] == NULL)
    {
        printf("NULL\n");// printf null
    }
    else
    {
        t_d_entry *p = list.tab_heads[level];
        while (p!= NULL) {
            char* n1= Getname(p->contact.name );// split Fistname and name
            printf("[%s|@-]-->",n1);// printf p-> value
            p = p->search[level];
        }
        printf(" NULL\n");// printf null
    }


} // MARCHE

//Search function
t_d_entry* LevelSearch(char* value, t_d_list_level list)
{
    int found = 0;
    char*n = (char*)malloc(3* sizeof(char));//my 3 first letter temp
    int level= (list.nb_level)-1;
    t_d_entry* temp =list.tab_heads[level], *temp1=NULL ;
    int h = 1; // temp1 is a head



    while(found == 0 && level >-1) {
        char *n1 = Getname(temp->contact.name);
        // i get the 3 first letter of my temp
        for (int m = 0; m < 3; m++) {
            n[m] = n1[m];
        }
        n[3] = '\0';

        if (strcmp(value, n) == 0) {
            found = 1;
        } else {
            if (strcmp(value, n) == -1)// value < temp
            {

                if (h == 1) {
                    temp = list.tab_heads[--level];
                } else {
                    temp = temp1->search[--level];
                }
            } else {
                if (strcmp(value, n) == 1) // value > temp
                {
                    if (temp->search[level] == NULL) {
                        temp1 = temp;
                        temp = temp->search[--level];
                        h = 0;
                    } else {
                        temp1 = temp;
                        temp = temp->search[level];
                        h = 0;
                    }
                }
            }
        }
    }
    if (found == 1)
    {
        return temp;
    }
    else
    {
        temp = NULL;
        return temp;
    }




    }

int DisplayAppointment(t_d_entry entry)
{
    char** Name = GetNAME(entry.contact.name);
    printf("\n\n>> %s %s\n",Name[1],Name[0]);

    if(entry.list->head == NULL)
    {

        printf(">> This Contact dont have appointmenent yet\n");
        return 0;
    }
    else
    {
        printf(">> This Contact have %d appointment for now :\n",entry.nbcap);
        t_cell* a = entry.list->head;
        for(int i= 1; i<=entry.nbcap;i++)
        {
            printf("[%d] the %s at %s during %s for : %s\n", i,a->appointment->date,a->appointment->hour,a->appointment->time,a->appointment->goal);
            a = a->next;
        }
        printf("\n");

        return 1;
    }
}

void CreateInsertAppointment(t_d_entry* entry)
{
    if(entry->list->head == NULL)
    {
        entry->list->head = CreateCell();
        //printf("the %s at %s during %s for : %s\n",entry->list->head->appointment->date,entry->list->head->appointment->hour,entry->list->head->appointment->time,entry->list->head->appointment->goal);

        entry->nbcap++;
    }
    else
    {
        t_cell* temp = entry->list->head;
        while(temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = CreateCell();
        entry->nbcap++;
    }



}

int SimpleSearch(char* value, t_d_list_level list)
{
    int found = 0;
    char*n = (char*)malloc(3* sizeof(char));//my 3 first letter temp
    t_d_entry* temp =list.tab_heads[0];

        while(temp != NULL && found == 0 )
        {
            char *n1 = Getname(temp->contact.name);
            // i get the 3 first letter of my temp
            for (int m = 0; m < 3; m++) {
                n[m] = n1[m];
            }
            n[3] = '\0';

            if(strcmp(value, n) == 0)
            {
                found = 1;
            }
            else{temp = temp->search[0];}


        }

    return found;
}



