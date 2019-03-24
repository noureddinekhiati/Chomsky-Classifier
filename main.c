#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "intro.c"
typedef char *chaine;
void effacer(int n)
{


    if(n==1){
         textcolor(WHITE);
    cputsxy(wherex()-2,wherey()," ");
    gotoxy(wherex()-1,wherey());}
    if(n==2){
       textcolor(LIGHTCYAN);
    cputsxy(wherex()-1,wherey()," ");
    gotoxy(wherex()-1,wherey());}

}
void lire_non_terminaux(char t[]) {

    char c;
    int i=0,j;

    bool fin = false ;
    textcolor(BLACK);
            textbackground(WHITE);
    printf("{ ");
    t[i]=0 ;
    while(!fin){
    c=getch();

    if((c>='A') &&(c<='Z') &&(strchr(t,c)==NULL)) {

            textcolor(BLACK);
            textbackground(WHITE);
            printf("%c",c);
            printf(",");
            t[i]=c ;
            i++ ;
            t[i]=0;

            } else if((c==13) && i) fin = true ;
                   else if (c==8){if(i==0) printf("\a");else {i--;t[i]=0;effacer(1);}}
                         else printf("\a");
    }
    t[i]=0;
    delline();
    textcolor(BLACK);
    textbackground(WHITE);
    printf("{");
    for(j=0;j<strlen(t);j++) printf("%c,",t[j]);
    cputsxy(wherex()-1,wherey()," ");
    printf("}");
//-----------------------------------------------------------------------//

}


void lire_terminaux(char t[]) {

    char c;
    int i=0,j;

    bool fin = false ;
    textcolor(BLACK);
            textbackground(WHITE);
    printf("{ ");
    t[i]=0 ;
    while(!fin){
    c=getch();

    if((c>='a') &&(c<='z') &&(strchr(t,c)==NULL)) {

            textcolor(BLACK);
            textbackground(WHITE);
            printf("%c",c);
            printf(",");
            t[i]=c ;
            i++ ;
            t[i]=0;

            } else if((c==13) && i) fin = true ;
                   else if (c==8){if(i==0) printf("\a");else {i--;t[i]=0;effacer(1);}}
                         else printf("\a");
    }
    t[i]=0;
    delline();
    printf("{");
    for(j=0;j<strlen(t);j++) printf("%c,",t[j]);
    cputsxy(wherex()-1,wherey()," ");
    printf("}");

//-----------------------------------------------------------------------//

}


void lire_regle(char **t,char alphabet[],char regle[],int nbr_regle,int pos[]){

    char c,tmp[20];
    bool fin ;
    int i,j=0;


   while (j<nbr_regle*2){
    fin = false ;
    i=0 ;
    tmp[i]=0 ;


    if(j%2==0) gotoxy(28,pos[j]); else gotoxy(84,pos[j]);

    while(!fin){

    c=getch();
    if((strchr(alphabet,c)!=NULL) || (strchr(regle,c)!=NULL) || (c=='$')) {
            if((c=='$') && (j%2==0)) printf("\a");
            else {
            textcolor(BLACK);
            textbackground(LIGHTCYAN);
            printf("%c",c);
            tmp[i]=c ;
            i++ ;
            tmp[i]=0 ;
            }
            } else if((c==13) && (i) && ( (j%2!=0) || (strpbrk(tmp,regle)!=NULL)) ){ if(((j%2!=0)&&(strlen(tmp)>1)&&(strchr(tmp,'$')!=NULL))|| ((j%2!=0)&&(strlen(tmp)==1)&&(strpbrk(tmp,regle)!=NULL)))printf("\a"); else fin = true ;}
                   else if (c==8){if(i==0) printf("\a");else {i--;effacer(2);tmp[i]=0 ;}}
                          else printf("\a");

            }



       tmp[i]=0 ;

      t[j]=(char *)(malloc((i+1)*sizeof(char)));
      strcpy(t[j],tmp);

      j++;


        }
    }

void champs(int x,int y,int l ){
    int i;
    gotoxy(x,y);
    textcolor(LIGHTCYAN);
    for(i=1;i<=l;i++) printf("%c",219);
    gotoxy(x,y+1);
    for(i=1;i<=l;i++) printf("%c",219);
    textcolor(BLACK);
    textbackground(WHITE);
    printf("      -------------------------%c",16);
    textcolor(LIGHTCYAN);
    gotoxy(x+55,y);
    for(i=1;i<=l;i++) printf("%c",219);
    gotoxy(x+55,y+1);
    for(i=1;i<=l;i++) printf("%c",219);

}
void champs_regle(int x,int y,int nbr_regle,int t[])
{
    int i,j=0 ;
    for(i=0;i<nbr_regle;i++){
        champs(x,y+3*i,20);
        t[i]=y+3*i;

    }

    t[i]=0;

}
int verfier(char **t,int l){
    int i,type=0 ;
    bool type_0_1=false ;

    for(i=0;i<l;i+=2){
        if(strlen(t[i])>1){type_0_1=true ; break ;}
    }
    if(type_0_1) {
       type = 1 ;
       for(i=0;i<l;i+=2){
        if(strlen(t[i]) > strlen(t[i+1])){type=0 ; break ;}
       }
    } else {

      type=3 ;
      for(i=1;i<l;i+=2){
        if(strlen(t[i])>2){type=2 ; break ;}
        else if((strlen(t[i])==1) && isupper(t[i][0]) )
              {type=2 ; break ;}
               else if(strlen(t[i])==2){
                        if (isupper(t[i][0])==isupper(t[i][1])) {type=2; break;}
                                       }

    }
    }
  return type ;

}
void lire_nbr_regle(int *n){
    gotoxy(57,23);
      char c;
      char t[20];
    int i=0,j;

    bool fin = false ;
    textcolor(BLACK);
    textbackground(WHITE);

    t[i]=0 ;
    while(!fin){
    c=getch();

    if((c>='1') &&(c<='9') ) {

            textcolor(BLACK);
            textbackground(WHITE);
            printf("%c",c);

            t[i]=c ;
            i++ ;
            t[i]=0;

            } else if((c==13) && i) {if(strlen(t)<=2)fin = true ; else printf("\a");}
                   else if (c==8){if(i==0) printf("\a");else {i--;t[i]=0;textcolor(WHITE);
                                                                cputsxy(wherex()-1,wherey()," ");
                                                                gotoxy(wherex()-1,wherey());}}
                         else printf("\a");
    }

    t[i]=0;

    (*n)=atoi(t);


}

int main()
{
    system("mode con LINES=300 COLS=150");
    system("COLOR FC");
    intro();
    dessiner_chomsky();
    system("cls");


    char t1[26],t2[10];
    int pos[20],tmp[20];
    chaine t[20] ;

    int k,nbr_regle ;

   int  n;
    d : dessine_menu(50,15);
        n = menu() ;
    switch(n){
    case 1 :



    textbackground(WHITE);
    textcolor(LIGHTRED);
    gotoxy(40,5);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,6);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,7);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(53,6);

     textbackground(LIGHTRED);
    textcolor(BLACK);
    printf("   TERMINAUX ");

     textbackground(WHITE);
    textcolor(LIGHTRED);
    gotoxy(40,13);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,14);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,15);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(50,14);

     textbackground(LIGHTRED);
    textcolor(BLACK);
    printf("  NON TERMINAUX ");


    textbackground(WHITE);
    textcolor(LIGHTRED);
    gotoxy(40,20);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,21);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,22);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(50,21);

     textbackground(LIGHTRED);
    textcolor(BLACK);
    printf("  NOMBRE DE REGLES ");


    textbackground(WHITE);
    textcolor(LIGHTRED);
    gotoxy(40,27);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,28);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,29);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(53,28);

     textbackground(LIGHTRED);
    textcolor(BLACK);
    printf("  LES REGLES ");

    gotoxy(50,10);
    lire_terminaux(t1);

    gotoxy(50,16);
    lire_non_terminaux(t2);

    lire_nbr_regle(&nbr_regle);

   champs_regle(25,30,nbr_regle,tmp);
    int i,j ;
    for(j=0,i=0;tmp[i]!=0;j+=2,i++){
            pos[j]=tmp[i];
            pos[j+1]=tmp[i];
    }

    lire_regle(t,t1,t2,nbr_regle,pos);

     int p = wherey();
    textbackground(WHITE);
    textcolor(LIGHTGREEN);
    gotoxy(40,p+5);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,p+6);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,p+7);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(41,p+6);
     textbackground(LIGHTGREEN);
    textcolor(BLACK);

    writeCh("VOTRE GRAMMAIRE ET DE TYPE ",30);
    printf("%d",verfier(t,nbr_regle));


    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(10,wherey()+7);
    printf("APPUYEZ SUR N'IMPORTE QULLE TOUCHE POUR RETOURNER AU MENU PRINCIPALE.................");
    getch();
    case 2 :
        textbackground(WHITE);
    textcolor(LIGHTRED);
    gotoxy(40,5);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,6);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,7);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(53,6);

     textbackground(LIGHTRED);
    textcolor(BLACK);
    printf("   <--------- ");
    gotoxy(45,10);
    textbackground(WHITE);
    textcolor(BLACK);
       printf(" Supprimer le caractére Précedent ");

    textbackground(WHITE);
    textcolor(LIGHTRED);
    gotoxy(40,13);
    for(k=0;k<=40;k++) printf("%c",219);
    gotoxy(40,14);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(40,15);
    for(k=0;k<=40;k++) printf("%c",219);
     gotoxy(50,14);

     textbackground(LIGHTRED);
    textcolor(BLACK);
    printf("    Le dollar  ' $ '     ");

    gotoxy(45,18);
    textbackground(WHITE);
    textcolor(BLACK);
    printf("  Pour designer l'epsilon ");

    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(10,wherey()+15);
    printf("APPUYEZ SUR N'IMPORTE QULLE TOUCHE POUR RETOURNER AU MENU PRINCIPALE.................");
    getch();



    }

    if (n>=3) goto e ; else {textbackground(WHITE);system("cls");}
   goto d ;
    e :
    return 0;
}
