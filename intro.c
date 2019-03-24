#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "conio.c"

typedef char *chaine ;

int menu() // Affiche le menu principal et donne le choix de l'utilisateur
{

    chaine t [] = {  "1-  CHOMSKY PROGRAMM CASSIFICATION                                            ",
                     "2-  GUIDE MENU                                                                ",
                     "3-  QUIITER                                                                   ",

                  };

    int n = 3;
    int i , j , quite = 1, quite2 , y = 30  , x= 45 , y1= n+4 , x1 =  strlen(t[0])+6 , choix ;
    char c1,c2 ,c3 , c4 ;
    debut :



    textbackground(WHITE);
    textcolor(LIGHTGRAY);

    for (i=1 ; i<= x1 ; i++)
    {
        for ( j=1 ; j<= y1 ; j++)
        {
            gotoxy(x-4+i,y-3+j);
            printf("%c",219);
        }

    }
    printf("\n");
    textcolor(15);

    for( i = 0 ; i< n ; i++)
    {
        if (i==0) textbackground(1);
        else textbackground(0);
        gotoxy(x,y+i);
        printf("%s\n",t[i]);
    }
    i=0;
    while( quite)
    {
        c1 = getch();
        if( c1 == 13 )
        {
            if ( c1 == 27 )
            {
                quite2 = 1 ;
                choix = 1 ;
                gotoxy(1,y);
                textattr(0);
                system("cls");
                textattr(204);
                for (i=1 ; i<= 46  ; i++)
                {
                    for ( j=1 ; j<= 4 ; j++)
                    {
                        gotoxy(x+13+i,y-3+j);
                        printf("%c",219);
                    }

                }
                textattr(207);
                gotoxy(x+15,y);
                printf("ETES VOUS SURE DE VOULOIR QUITTER ?!  (Y%cN) ",92);
                gotoxy(109,y);
                textattr(143);
                printf("O");
                while(quite2)
                {
                    c3 = getch();
                    if ( c3 == 13) quite2 = 0 ;
                    else if ( c3 == -32)
                    {
                        c4 = getch();
                        if (c4 == 77 && choix == 1 )
                        {
                            gotoxy(111,y);
                            textattr(143);
                            printf("N");
                            gotoxy(109,y);
                            textattr(207);
                            printf("O");
                            choix -- ;
                        }
                        if (c4 == 75 && choix == 0)
                        {
                            gotoxy(109,y);
                            textattr(143);
                            printf("O");
                            gotoxy(111,y);
                            textattr(207);
                            printf("N");
                            choix ++ ;
                        }
                    }

                }

                textattr(15);
                if ( choix == 1)
                {
                    i = -1 ;
                    quite = 0 ;
                }
                else  goto debut ;
            }
            else quite = 0 ;
        }

        else if( c1 == -32 )
        {
            c2 = getch();
            if (c2 == 72 )
            {
                if(i > 0)
                {
                    gotoxy(x,i-1+y);
                    textbackground(1);
                    printf("%s\n",t[i-1]);
                    textbackground(0);
                    gotoxy(x,i+y);
                    printf("%s\n",t[i]);
                    i--;
                }
                else
                {
                    gotoxy(x,y+n-1);
                    textbackground(1);
                    printf("%s\n",t[n-1]);
                    gotoxy(x,y);
                    textbackground(0);
                    printf("%s\n",t[0]);
                    i=n-1;
                }
            }
            else if (c2 == 80)
            {
                if( i < n-1)
                {
                    gotoxy(x,y+i+1);
                    textbackground(1);
                    printf("%s\n",t[i+1]);
                    textbackground(0);
                    gotoxy(x,y+i);
                    printf("%s\n",t[i]);
                    i++;
                }
                else
                {
                    gotoxy(x,y);
                    textbackground(1);
                    printf("%s\n",t[0]);
                    gotoxy(x,y+i);
                    textbackground(0);
                    printf("%s\n",t[i]);
                    i=0 ;
                }
            }
        }
    }
    textbackground(WHITE);
    system("cls");
    return i+1;
}
void dessiner_chomsky(){
int x,y;    x=10;y=15;
gotoxy(x,y);
printf("     %c%c%c     %c%c%c  %c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c  %c%c%c%c%c   %c%c%c%c%c    ",219,219,219, 219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("    %c%c%c%c%c%c%c  %c%c   %c%c   %c%c%c%c%c%c  %c%c%c     %c%c%c %c%c%c%c%c%c%c  %c%c     %c%c    %c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+1);
printf("     %c%c%c%c    %c%c%c  %c%c    %c%c  %c%c   %c%c  %c%c%c%c%c%c %c%c%c%c%c%c    ",219,219,219,219,219,219,219,219,219,219,219,219,219, 219,219, 219,219,219,219,219,219, 219,219,219,219,219,219);
printf("    %c%c%c%c%c%c%c  %c%c   %c%c   %c%c  %c%c  %c%c%c%c  %c%c%c%c%c %c%c       %c%c     %c%c    %c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+2);
printf("     %c%c%c%c%c   %c%c%c  %c%c    %c%c  %c%c   %c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c    ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("    %c%c       %c%c%c%c%c%c%c   %c%c  %c%c  %c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(x,y+2);
gotoxy(x,y+3);
printf("     %c%c%c%c%c%c  %c%c%c  %c%c    %c%c  %c%c%c%c%c%c%c  %c%c%c  %c%c%c  %c%c%c    ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("    %c%c       %c%c   %c%c   %c%c  %c%c  %c%c  %c%c%c  %c%c      %c%c  %c%c           %c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+4);
printf("     %c%c%c%c%c%c%c %c%c%c  %c%c    %c%c  %c%c   %c%c  %c%c%c   %c   %c%c%c    ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("    %c%c%c%c%c%c%c  %c%c   %c%c   %c%c  %c%c  %c%c   %c   %c%c      %c%c  %c%c           %c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+5);
printf("     %c%c%c  %c%c%c%c%c%c  %c%c    %c%c  %c%c   %c%c  %c%c%c       %c%c%c    ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("    %c%c%c%c%c%c%c  %c%c   %c%c   %c%c%c%c%c%c  %c%c       %c%c %c%c%c%c%c%c%c  %c%c           %c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219, 219,219,219,219,219,219,219,219,219,219,219);
gotoxy(x,y+6);
printf("     %c%c%c  %c%c%c%c%c%c  %c%c%c%c%c%c%c%c  %c%c   %c%c  %c%c%c       %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}
void entete (){

    int i ;
    gotoxy(50,3);
    textbackground(WHITE);
    textcolor(BLACK);
    printf("REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE ");
    gotoxy(60,5);
    printf("UNIVERSITE IBN KHALDOUN TIARET \n");
    for (i=1 ; i <= 150 ; i++) printf("_");
    printf("\n") ;

}
void pied_de_page (int y)

{
    int i ;
    gotoxy(1,y);
    for (i=1 ; i <= 150 ; i++) printf("_");
    gotoxy(65,y+2);
    printf("REALISE PAR:");
    gotoxy(55,y+4);
    printf("KHIATI REZKZLLAH NOUREDDINE");
    gotoxy(60,y+6);
    printf("2 LMD    |   GROUPE 4");
    gotoxy(65,y+8);
    printf("ENSEIGNANT :");
    gotoxy(63,y+10);
    printf("Mr MEZZOUG KARIM ");
    gotoxy(55,y+12);
    printf("ANNEE UNIVERSITAIRE : 2017/2018\n");
    for (i=1 ; i <= 150 ; i++) printf("_");

}
void intro (){
    int d=50 , c=20,i;
   entete();
   dessiner_chomsky();

   for (i=0 ; i<=100 ; i++)
    {
        if ( i<44 || i>60)
        {
            textcolor(RED);
            gotoxy(d+i-24,10+c);
            printf("%c%c",219,219);
            delay(10);
        }
        textcolor(WHITE);
        textbackground(RED);
        gotoxy(d+21,10+c);
        printf("CHARGEMENT: %d %c\r",i,37);
        delay(5);
    }
    gotoxy(30,33);
    textbackground(LIGHTBLUE);
    textcolor(WHITE);
    printf("PROGRAMME CLASSIFICATION DES GRAMMAIRES APPUYEZ SUR N'IMPORTE QULLE TOUCHE POUR ENTRER ............. ");

    textbackground(WHITE);
    textcolor(BLACK);
   pied_de_page (35);

   gotoxy(130,33);
   getch();







}
void dessine_menu (int x , int y)
{
    entete();

 gotoxy(x,y);
 printf("%c%c%c%c%c   %c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+1);
 printf("%c%c%c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c    %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+2);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c        %c%c%c%c%c%c   %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+3);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+3);
 printf("%c%c%c  %c%c%c  %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+4);
 printf("%c%c%c   %c   %c%c%c   %c%c%c        %c%c%c%c  %c%c%c%c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+5);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c    %c%c%c%c%c   %c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+6);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c    %c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

    pied_de_page(43);
}
void writeCh(char ch[],int temps)
{
    int i;
    for (i=0 ; i < strlen(ch); i++)
    {
        printf("%c",ch[i]);
        delay(temps);
    }
}



