#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include <unistd.h>
#include<conio.h>



typedef struct hnach
{
    int x,y;
    struct hnach* suiv;
}snake;
snake* tete;



int skin_snk=1, skin_jeu=1, skin_pom=1;




snake* init_snake()
{
    tete=malloc(sizeof (snake));
    tete->x=12;
    tete->y=10;
    tete->suiv=NULL;
    return tete;
}
typedef struct mange
{
    int a,b;
}fruit;
fruit manga;
fruit grand_manga;
int choix;
int score=0;
char mat[25][30];

int mute=0;
COORD coord = {0, 0} ;

void gotoxy (int x, int y)
{

coord.X = x ; coord.Y = y ; // X et Y sont les coordonn es

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
coord);

}

void dormir ( long milli )
{
  clock_t end, current = clock();
  for( end = current + milli; current < end; current = clock() );
}
void transition_loading ( void )
{
  int x = 0;
  const char *barRotate = "|\\-/";
  printf ( "Loading configuration files... " );
  for ( int i=0;i<20 ;i++ ) {
    if ( x > 3 ) x = 0;
    printf ( "%c\b", barRotate[x++] );
    dormir ( 200 );
  }

}


void delay( unsigned int value)
{
    unsigned int count1 =0;
    unsigned int count2 = 0;

    for(count1 = 0; count1 < value ; count1++ )
    {
        for(count2 = 0; count2 < count1 ; count2++ )
        {

        }
    }
}


// string to display Rocket
const char rocket[] =
    "\t\t\t\t           ^ \n\t\t\t\t\
          /^\\\n\t\t\t\t\
          |-|\n\t\t\t\t\
          | |\n\t\t\t\t\
          |S|\n\t\t\t\t\
          |N|\n\t\t\t\t\
          |A|\n\t\t\t\t\
          |K|\n\t\t\t\t\
         /|E|\\\n\t\t\t\t\
        / | | \\\n\t\t\t\t\
       |  | |  |\n\t\t\t\t\
        `-\"\"\"-`\n\t\t\t\t\
";

const char rocket2[] =
    "\t\t\t\t           ^ \n\t\t\t\t\
          /^\\\n\t\t\t\t\
          |-|\n\t\t\t\t\
          | |\n\t\t\t\t\
          |J|\n\t\t\t\t\
          |E|\n\t\t\t\t\
          |R|\n\t\t\t\t\
          |B|\n\t\t\t\t\
         /|I|\\\n\t\t\t\t\
        / | | \\\n\t\t\t\t\
       |  | |  |\n\t\t\t\t\
        `-\"\"\"-`\n\t\t\t\t\
";

const char rocket3[] =
    "\t\t\t\t           ^ \n\t\t\t\t\
          /^\\\n\t\t\t\t\
          |-|\n\t\t\t\t\
          |N|\n\t\t\t\t\
          |O|\n\t\t\t\t\
          |U|\n\t\t\t\t\
          |R|\n\t\t\t\t\
          |H|\n\t\t\t\t\
         /|E|\\\n\t\t\t\t\
        / |N| \\\n\t\t\t\t\
       |  |E|  |\n\t\t\t\t\
        `-\"\"\"-`\n\t\t\t\t\
";
void print_transition_1()
{

    int jumpControlAtBottom = 0;
    const int someDelay = 30000;
    int shifControl = 0;


    //jump to bottom of console

    for (jumpControlAtBottom = 0; jumpControlAtBottom < 30; ++jumpControlAtBottom)
    {
        printf("\n");
    }

    //Print rocket
    fputs(rocket,stdout);


    for (shifControl = 0; shifControl < 30; ++shifControl)
    {
        // Rocket move on the basis of delay
        delay(someDelay);

        // move rocket a line upward
        printf("\n");
    }

}
void print_transition_2()
{

    int jumpControlAtBottom = 0;
    const int someDelay = 30000;
    int shifControl = 0;


    //jump to bottom of console

    for (jumpControlAtBottom = 0; jumpControlAtBottom < 30; ++jumpControlAtBottom)
    {
        printf("\n");
    }

    //Print rocket
    fputs(rocket2,stdout);

    for (shifControl = 0; shifControl < 30; ++shifControl)
    {
        // Rocket move on the basis of delay
        delay(someDelay);

        // move rocket a line upward
        printf("\n");
    }

}

void print_transition_3()
{

    int jumpControlAtBottom = 0;
    const int someDelay = 30000;
    int shifControl = 0;


    //jump to bottom of console

    for (jumpControlAtBottom = 0; jumpControlAtBottom < 30; ++jumpControlAtBottom)
    {
        printf("\n");
    }

    //Print rocket

    fputs(rocket3,stdout);

    for (shifControl = 0; shifControl < 30; ++shifControl)
    {
        // Rocket move on the basis of delay
        delay(someDelay);

        // move rocket a line upward
        printf("\n");
    }

}






void modifier_skin()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int choix_modif;
    debut:
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(30,6);
    printf("Nous allons vous montrer les skins du cadre, snake et fruit \n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,8);
    printf("Tapez [1] si vous voulez changer le skin du cadre \n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,10);
    printf("Tapez [2] si vous voulez changer le skin du snake \n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED);
    gotoxy(35,12);
    printf("Tapez [3] si vous voulez changer le skin du pomme \n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,14);
    printf("Tapez [4] pour rendre les skins par defaut\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,16);
    printf("Tapez [5] pour retourner au menu principale\n\n");
    do
    {
        printf("Votre choix: \t");
        scanf("%d",&choix_modif);
    }while(choix_modif!=1 && choix_modif!=2 && choix_modif!=3 && choix_modif!=4 && choix_modif!=5);
    if(choix_modif==1)
    {
        system("cls");

        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(52,10);
        transition_loading();
        sleep(1);

        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED   | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(45,4);
        printf("voici les skins du cadre \n\n");
        sleep(1);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("skin 1: \n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED);
        for (int i = 1; i <= 5; i++)
        {
            printf("\t\t");
            for (int j = 1; j <= 5; j++) {
                if (i == 1 || i == 5 || j == 1 || j == 5)
                {
                        printf("*");
                } else
                {
                printf(" ");
                }
            }
            printf("\n");
        }

        sleep(1);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("skin 2:\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED);
        for (int i = 1; i <= 5; i++)
        {
            printf("\t\t");
            for (int j = 1; j <= 5; j++) {
                if (i == 1 || i == 5 || j == 1 || j == 5)
                {
                        printf("#");
                } else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        sleep(1);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("skin 3:\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED);
        for (int i = 1; i <= 5; i++)
        {
            printf("\t\t");
            for (int j = 1; j <= 5; j++) {
                if (i == 1 || i == 5 || j == 1 || j == 5)
                {
                    printf("+");
                } else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
        do
        {
            printf("votre choix:");
            scanf("%d",&skin_jeu);
        }while(skin_jeu!=1 && skin_jeu!=2 && skin_jeu!=3);

        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(45,10);
        printf("Press any key to continue...");
        getch();
        system("cls");
        goto debut;
    }
    else
        if(choix_modif==2)
        {
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(52,10);
            transition_loading();
            sleep(1);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(45,4);
            printf("voici les skins du snake \n");
            sleep(1);
            SetConsoleTextAttribute(console,  FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("skin 1:\n");
            SetConsoleTextAttribute(console,  FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("\t\toooooooo");
            SetConsoleTextAttribute(console,  FOREGROUND_BLUE |FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("+\n\n");
            sleep(1);
            SetConsoleTextAttribute(console,  FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("skin 2: \n");
            SetConsoleTextAttribute(console,  FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("\t\t*********");
            SetConsoleTextAttribute(console,  FOREGROUND_BLUE |FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("#\n\n");
            sleep(1);
            SetConsoleTextAttribute(console,  FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("skin 3: \n");
            SetConsoleTextAttribute(console,  FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("\t\t&&&&&&&&&&");
            SetConsoleTextAttribute(console,  FOREGROUND_BLUE |FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("D\n\n");
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED);
            do
            {
                printf("votre choix:");
                scanf("%d",&skin_snk);
            }while(skin_snk!=1 && skin_snk!=2 && skin_snk!=3);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(45,10);
            printf("Press any key to continue...");
            getch();
            system("cls");
            goto debut;

        }
        else
            if(choix_modif==3)
            {
                system("cls");
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
                gotoxy(52,10);
                transition_loading();
                sleep(1);
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                gotoxy(45,4);
                printf("voici les skins du Pomme \n");
                sleep(1);
                SetConsoleTextAttribute(console,  FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
                printf("skin 1:\n");
                SetConsoleTextAttribute(console,  FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                printf("\t\t#\n\n");
                sleep(1);
                SetConsoleTextAttribute(console,  FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
                printf("skin 2:\n");
                SetConsoleTextAttribute(console,  FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                printf("\t\t@\n\n");
                sleep(1);
                SetConsoleTextAttribute(console,  FOREGROUND_RED  | BACKGROUND_GREEN  | BACKGROUND_RED);
                printf("skin 3: \n");
                SetConsoleTextAttribute(console,  FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                printf("\t\t$\n\n");
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED);
                do
                {
                    printf("votre choix:");
                    scanf("%d",&skin_pom);
                }while(skin_pom!=1 && skin_pom!=2 && skin_pom!=3);
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                gotoxy(45,10);
                printf("Press any key to continue...");
                getch();
                system("cls");
                goto debut;
            }
            else
                if(choix_modif==4)
                {
                    skin_snk=1;
                    skin_jeu=1;
                    skin_pom=1;
                    system("cls");
                    goto debut;
                }


}



void affiche_game()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("\t\t\t\t\t\t\t SCORE: %d\n",score);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("\t\t\t\t\t\t\t X: PAUSE\n\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    snake* parc = tete;
    int i, j;
    printf("\t\t\t\t");
    for(i = 0; i < 25; i++)
    {
        for(j = 0; j < 30; j++)
        {
            int isSnakePart = 0;
            while(parc != NULL)
            {
                if(i == parc->x && j == parc->y && parc==tete)
                {
                    if(skin_snk==1)
                    {
                            SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
                            printf("+");
                    }
                    else
                        if(skin_snk==2)
                        {
                            SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
                            printf("#");
                        }
                        else
                            if(skin_snk==3)
                            {
                                   SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
                                    printf("D");
                            }
                    isSnakePart = 1;

                }
                else
                    if(i == parc->x && j == parc->y )
                    {
                        SetConsoleTextAttribute(console, FOREGROUND_BLUE|FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
                        if(skin_snk==1)
                            printf("O");
                        else
                            if(skin_snk==2)
                                printf("*");
                            else
                                if(skin_snk==3)
                                    printf("&");
                        isSnakePart = 1;

                    }
                parc = parc->suiv;
            }
            if(!isSnakePart)
            {
                if(i == manga.a && j == manga.b)
                {
                    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
                    if(skin_pom==1)
                        printf("#");
                    else
                        if(skin_pom==2)
                            printf("@");
                        else
                            if(skin_pom==3)
                                printf("$");
                }
                else
                    /*if(i == grand_manga.a && j == grand_manga.b)
                    {
                        printf("$");
                    }
                    else*/
                    {
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
                        printf("%c", mat[i][j]);
                    }
            }
            parc = tete;
        }
        printf("\n");
        printf("\t\t\t\t");
    }
}



void init_mat()
{
    int i,j;
    for(i = 0; i <= 24; i++) {
      for(j = 0; j <= 29; j++) {
         if(i == 0 || i == 24|| j == 0 || j == 29)
         {
            if(skin_jeu==1)
                mat[i][j]='*';
            else
                if(skin_jeu==2)
                    mat[i][j]='#';
                else
                    if(skin_jeu==3)
                        mat[i][j]='+';


         }
        else
        {
            mat[i][j]=' ';

        }
      }
   }
}

int test(int a, int b)
{
    snake* parc;
    parc=tete;
    int ok=0;
    while(parc!=NULL)
    {
        if(parc->x==a && parc->y==b)
        {
            ok=1;
            break;
        }
        else
            parc=parc->suiv;
    }
    return ok;
}

void generer_alea()
{

    srand(time(NULL));
    do
    {
        manga.a = rand() % 22  + 1;
        manga.b=rand()% 27+1;
    }while(test(manga.a,manga.b)==1);

}

int verif_perd()
{
    if(tete->x==0 || tete->x==24 || tete->y==29 || tete->y==0)
    {
            return 1;
    }
    snake* parcours = tete->suiv;
    while (parcours != NULL)
    {
        if (tete->x == parcours->x && tete->y == parcours->y)
        {
            return 1;
            break;
        }
        parcours = parcours->suiv;
    }

}


int verif_manger()
{

    if(tete->x == manga.a && tete->y==manga.b)
        return 1;
}

void afficher_game_over()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
   printf("\n----------------------------------------------------------------------------------------------------\n\n");
   SetConsoleTextAttribute(console, FOREGROUND_RED |  BACKGROUND_GREEN  | BACKGROUND_RED);
   printf("\t\t\t\t\t GAME OVER\n\n");
   SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
   printf("----------------------------------------------------------------------------------------------------\n");
}
void deplacement_auto(int hist)
{
    //haut
    if(hist==1)
    {
        snake* nouvelle_tete = malloc(sizeof(snake));
        nouvelle_tete->x = tete->x -1;
        nouvelle_tete->y = tete->y ;
        nouvelle_tete->suiv = tete;
        tete = nouvelle_tete;

        snake* parcours = tete;
        while (parcours->suiv->suiv != NULL) {
            parcours = parcours->suiv;
        }
        free(parcours->suiv);
        parcours->suiv = NULL;
    }
    else
        //bas
        if(hist==2)
        {
            snake* nouvelle_tete = malloc(sizeof(snake));
            nouvelle_tete->x = tete->x +1;
            nouvelle_tete->y = tete->y ;
            nouvelle_tete->suiv = tete;
            tete = nouvelle_tete;

            snake* parcours = tete;
            while (parcours->suiv->suiv != NULL) {
                parcours = parcours->suiv;
            }
            free(parcours->suiv);
            parcours->suiv = NULL;
        }
        else
            //droit
            if(hist==0)
            {
                snake* nouvelle_tete = malloc(sizeof(snake));
                nouvelle_tete->x = tete->x ;
                nouvelle_tete->y = tete->y +1;
                nouvelle_tete->suiv = tete;
                tete = nouvelle_tete;

                snake* parcours = tete;
                while (parcours->suiv->suiv != NULL) {
                    parcours = parcours->suiv;
                }
                free(parcours->suiv);
                parcours->suiv = NULL;
            }
            else
                //gauche
                if(hist==3)
                {
                    snake* nouvelle_tete = malloc(sizeof(snake));
                    nouvelle_tete->x = tete->x ;
                    nouvelle_tete->y = tete->y -1;
                    nouvelle_tete->suiv = tete;
                    tete = nouvelle_tete;

                    snake* parcours = tete;
                    while (parcours->suiv->suiv != NULL) {
                        parcours = parcours->suiv;
                    }
                    free(parcours->suiv);
                    parcours->suiv = NULL;
                }
}
snake* grand_snake_auto(int hist)
{
    if(hist==1)
    {
        if (tete == NULL) {
        return NULL;
        }

        snake* ajout = malloc(sizeof(snake));

        ajout->suiv = NULL;

        snake* parc = tete;
        while (parc->suiv != NULL) {
            parc = parc->suiv;
        }
        parc->suiv = ajout;
        ajout->x = (parc->x)-1;
        ajout->y = parc->y;

        return tete;
    }
    else
        if(hist==2)
        {
            if (tete == NULL) {
            return NULL;
            }

            snake* ajout = malloc(sizeof(snake));

            ajout->suiv = NULL;

            snake* parc = tete;
            while (parc->suiv != NULL) {
                parc = parc->suiv;
            }
            parc->suiv = ajout;
            ajout->x = (parc->x)+1;
            ajout->y = parc->y;

            return tete;
        }
        else
            if(hist==3)
            {
                if (tete == NULL) {
                    return NULL;
                }

                snake* ajout = malloc(sizeof(snake));

                ajout->suiv = NULL;

                snake* parc = tete;
                while (parc->suiv != NULL) {
                    parc = parc->suiv;
                }
                parc->suiv = ajout;
                ajout->x = parc->x;
                ajout->y = (parc->y)-1;

                return tete;

            }
            else
                if(hist==0)
                {
                    if (tete == NULL) {
                        return NULL;
                    }

                    snake* ajout = malloc(sizeof(snake));

                    ajout->suiv = NULL;

                    snake* parc = tete;
                    while (parc->suiv != NULL) {
                        parc = parc->suiv;
                    }
                    parc->suiv = ajout;
                    ajout->x = parc->x;
                    ajout->y = (parc->y)-1;

                    return tete;

                }
    return tete;
}

/* pour la variable hist
0: droit
1: haut
2:bas
3: gauche
*/
int start_game()
{

    if(mute!=1)
    {
        PlaySound(TEXT("Super-Mario-Bros.wav"),NULL,SND_ASYNC);
    }
    int ok=0;
    char jeu;
    int hist=0;
    generer_alea();
    while(ok==0)
    {
        affiche_game();
        if(jeu!='x')
        {
            do
            {
                fflush(stdin);
                fflush(stdout);
                deplacement_auto(hist);
                ok=verif_perd();
                if(ok==1)
                {

                    afficher_game_over();
                    if(mute!=1)
                    {
                        PlaySound(TEXT("3310-Nokia.wav"),NULL,SND_ASYNC);
                    }
                    sleep(8);
                    break;
                }
                if(verif_manger()==1)
                {
                    tete=grand_snake_auto(hist);
                    score=score+10;
                    generer_alea();

                }
                system("cls");
                fflush(stdin);
                fflush(stdout);
                affiche_game();
                long double i;
                for(i=0; i<=(10900000); i++);

            }while(!kbhit());
        }

        if(ok!=1)
        {
            jeu=getch();
            if(jeu=='z' && hist!=2)
            {
                fflush(stdin);
                fflush(stdout);
                hist=1;
                deplacement_auto(hist);


                ok=verif_perd();
                if(ok==1)
                {

                    afficher_game_over();
                    if(mute!=1)
                    {
                        PlaySound(TEXT("3310-Nokia.wav"),NULL,SND_ASYNC);
                    }
                    sleep(8);
                    break;
                }
                 if(verif_manger()==1)
                {
                    tete=grand_snake_auto(hist);
                    score=score+10;
                    generer_alea();

                }
                long double i;
                for(i=0; i<=(10900000); i++);
                system("cls");
                fflush(stdin);
                fflush(stdout);





            }
            else
                if(jeu=='s' && hist!=1 )
                {
                    fflush(stdin);
                    fflush(stdout);
                    hist=2;
                    deplacement_auto(hist);



                    ok=verif_perd();
                    if(ok==1)
                    {

                        afficher_game_over();
                        if(mute!=1)
                        {
                            PlaySound(TEXT("3310-Nokia.wav"),NULL,SND_ASYNC);
                        }
                        sleep(8);
                        break;
                    }
                     if(verif_manger()==1)
                     {
                        tete=grand_snake_auto(hist);
                        score=score+10;
                        generer_alea();
                    }
                    long double i;
                    for(i=0; i<=(10900000); i++);
                    system("cls");
                    fflush(stdin);
                    fflush(stdout);


                }
                else
                    if(jeu=='q' && hist!=0)
                    {
                        fflush(stdin);
                        fflush(stdout);
                        hist=3;
                        deplacement_auto(hist);



                        ok=verif_perd();
                        if(ok==1)
                        {

                            afficher_game_over();
                            if(mute!=1)
                            {
                                PlaySound(TEXT("3310-Nokia.wav"),NULL,SND_ASYNC);
                            }
                            sleep(8);
                            break;
                        }
                         if(verif_manger()==1)
                         {
                            tete=grand_snake_auto(hist);
                            generer_alea();
                            score=score+10;

                        }
                        long double i;
                        for(i=0; i<=(10900000); i++);
                        system("cls");
                        fflush(stdin);
                        fflush(stdout);

                    }
                    else
                        if(jeu=='d' && hist!=3)
                        {

                            fflush(stdin);
                            fflush(stdout);
                            hist=0;
                            deplacement_auto(hist);



                            ok=verif_perd();
                            if(ok==1)
                            {

                                afficher_game_over();
                                if(mute!=1)
                                {
                                    PlaySound(TEXT("3310-Nokia.wav"),NULL,SND_ASYNC);
                                }
                                sleep(8);
                                break;
                            }
                            if(verif_manger()==1)
                            {
                                tete=grand_snake_auto(hist);
                                score=score+10;
                                generer_alea();

                            }
                            long double i;
                            for(i=0; i<=(10900000); i++);
                            system("cls");
                            fflush(stdin);
                            fflush(stdout);

                        }
                        else
                            if((jeu!='z' && jeu!='s' && jeu!='q' && jeu!='d')|| (jeu=='d' && hist==3)|| (jeu=='q' && hist==0)|| (jeu=='s' && hist==1)|| (jeu=='z' && hist==2))
                            {
                                fflush(stdin);
                                fflush(stdout);
                                long double i;
                                for(i=0; i<=(10900000); i++);
                                system("cls");
                                fflush(stdin);
                                fflush(stdout);

                            }

        }



    }
    return score;
}

void affiche_design()
{
   HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
   gotoxy(18,0);
   printf("--------------------------------------------------------------------------\n\n");
   SetConsoleTextAttribute(console, FOREGROUND_RED |  BACKGROUND_GREEN  | BACKGROUND_RED);
   gotoxy(18,2);
   printf("\t\t\t\t Jeu de SNAKE\n\n");
   SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
   gotoxy(18,4);
   printf("--------------------------------------------------------------------------\n");

}
int menu()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(43,6);
    printf("Tapez [1] pour jouer\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(38,8);
    printf("Tapez [2] pour comprendre le jeu\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN |FOREGROUND_BLUE|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(38,10);
    printf("Tapez [3] pour modifier la musique\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE|FOREGROUND_INTENSITY |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,12);
    printf("Tapez [4] pour choisir le design de jeu\n");
    SetConsoleTextAttribute(console,  FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(43,14);
    printf("Tapez [5] pour quitter\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    do
    {
        printf("choix:\t");
        scanf("%d",&choix);
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);
    return choix;
}

void guide()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(52,10);
    transition_loading();
    sleep(1);
    system("cls");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,0);
    printf("-----------------------------------\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(40,2);
    printf("\t Le guide\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(35,4);
    printf("-----------------------------------\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("1- ");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Le jeu commence avec un serpent de taille initiale et une pomme qui apparait a un emplacement aleatoire sur l'ecran.\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("2-");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf(" Le but du jeu est de controler le serpent pour qu'il mange la pomme et grandisse.\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("3- ");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Chaque fois que le serpent mange une pomme, sa taille augmente d'une unite.\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("4- ");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Le serpent ne peut pas se deplacer a l'oppose de sa direction actuelle, ce qui signifie qu'il ne peut pas faire demi-tour. \n");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("5- ");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Le joueur doit eviter que le serpent ne touche les bords de l'ecran ou ne se heurte a son propre corps.\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("6- ");
    SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Le jeu continue jusqu'a ce que le serpent meure. Le score est calcule en fonction du nombre de pommes mangees.\n\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
    //system("cls");
    gotoxy(42,15);
    printf("Press any key to continue...");
    getch();
    system("cls");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Les touches :\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("\t\t\t\t\tz: haut\n");
    printf("\t\t\t\t\ts: bas\n");
    printf("\t\t\t\t\tq: gauche\n");
    printf("\t\t\t\t\td: droit\n");
    printf("\t\t\t\t\tx: Pause\n\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("voici le cadre par defaut du jeu:\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    for (int i = 1; i <= 5; i++)
    {
        printf("\t\t\t\t\t");
        for (int j = 1; j <= 5; j++) {
            if (i == 1 || i == 5 || j == 1 || j == 5)
            {
                printf("*");
            } else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Voici le skin par defaut de snake :\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("\t\t\t\t\toooooooooo");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("+ \n\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Voici le skin par defaut de pomme:\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("\t\t\t\t\t#\n\n");

    SetConsoleTextAttribute(console, FOREGROUND_RED|FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Press any key to continue....\n");
    getch();
    system("cls");


}


void jeu()
{
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        init_mat();
        char name[20];
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(52,8);
        printf("Enter your name\n");
        gotoxy(54,10);
        SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
        scanf("%s",name);

//transition ///////////////////////////////////////
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(52,10);
        printf("Bienvenu le joueur ");
        SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf(" %s  \n",name);
        sleep(2);
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(52,10);
        transition_loading();
        sleep(1);
        //////////////////////////////////////
        system("cls");
        score=start_game();
        system("cls");
        if(mute!=1)
            PlaySound(TEXT("Soolking-Suavemente-_Clip-Officiel_.wav"),NULL,SND_ASYNC);
        FILE *info;
        info=fopen("score.txt","a+");
        fprintf(info,"Player Name :%s\n",name);
        time_t mytime;
        mytime = time(NULL);
        fprintf(info,"Played Date:%s\n",ctime(&mytime));
        fprintf(info,"Score:%d\n",score);
        fprintf(info,"____________________________________\n");
        fclose(info);
        score=0;
}




void repertoire_musique()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    int music, choix_mus;
    debut_music:
    gotoxy(30,5);
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("tapez [1] si vous voulez voir la repertoire \n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(30,10);
    printf("tapez [2] si vous voulez mettre en pause la musique\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(30,15);
    printf("tapez [3] si vous voulez quitter\n\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    do
    {
        printf("votre choix:\t");
        scanf("%d",&music);
    }while(music!=1 && music!=2 && music!=3);
    system("cls");
    if(music==1)
    {

        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(52,10);
        transition_loading();
        sleep(1);
        system("cls");
        mute=0;
        gotoxy(30,2);
        SetConsoleTextAttribute(console, FOREGROUND_GREEN |FOREGROUND_BLUE|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("1- Soolking yal bahri\n");
        gotoxy(30,4);
        printf("2- Soolking Suavemente\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(30,6);
        printf("3- PNL bene\n");
        gotoxy(30,8);
        printf("4- PNL 91's\n");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(30,10);
        printf("5- Samara Ouuuu\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(30,12);
        printf("6- A vava Inouva\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
        gotoxy(30,14);
        printf("7- Retourner au menu principale\n\n");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
        do
        {
            printf("votre choix:\t");
            scanf("%d",&choix_mus);
        }while(choix_mus!=1 && choix_mus!=2 && choix_mus!=3 && choix_mus!=4 && choix_mus!=5 && choix_mus!=6 && choix_mus!=7);
        if(choix_mus==1)
        {
            PlaySound(NULL,NULL,SND_ASYNC);
            PlaySound(TEXT("Soolking-Ya-Ibahri-_Audio-Officiel_.wav"),NULL,SND_ASYNC);
            system("cls");
            goto debut_music;
        }
        else
            if(choix_mus==2)
            {

                PlaySound(NULL,NULL,SND_ASYNC);
                PlaySound(TEXT("Soolking-Suavemente-_Clip-Officiel_.wav"),NULL,SND_ASYNC);
                system("cls");
                goto debut_music;
            }
            else
                if(choix_mus==3)
                {

                    PlaySound(NULL,NULL,SND_ASYNC);
                    PlaySound(TEXT("Bené.wav"),NULL,SND_ASYNC);
                    system("cls");
                    goto debut_music;
                }
                else
                    if(choix_mus==4)
                    {
                        PlaySound(NULL,NULL,SND_ASYNC);
                        PlaySound(TEXT("91s.wav"),NULL,SND_ASYNC);
                        system("cls");
                        goto debut_music;
                    }
                    else
                        if(choix_mus==5)
                        {
                            PlaySound(NULL,NULL,SND_ASYNC);
                            PlaySound(TEXT("Samara-Ooouuu-_Clip-Officiel_-Prod-by-Voluptyk.wav"),NULL,SND_ASYNC);
                            system("cls");
                            goto debut_music;
                        }
                        else
                            if(choix_mus==6)
                            {
                                PlaySound(NULL,NULL,SND_ASYNC);
                                PlaySound(TEXT("A-Vava-Inouva.wav"),NULL,SND_ASYNC);
                                system("cls");
                                goto debut_music;
                            }
                            else
                                {
                                    system("cls");
                                    goto debut_music;
                                }

    }
    else
    {
        if(music==2)
        {
          mute=1;
          PlaySound(NULL,NULL,SND_ASYNC);
          system("cls");
          goto debut_music;
        }

    }
}



















int main()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("Jeu de SNAKE");
    system("color 60");
    PlaySound(TEXT("91s.wav"),NULL,SND_ASYNC);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    debut:
    affiche_design();
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY|  BACKGROUND_GREEN  | BACKGROUND_RED);
    choix=menu();
    tete=init_snake();
    if(choix==1)
    {
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED|  BACKGROUND_GREEN  | BACKGROUND_RED);

        print_transition_1();

        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE  |   BACKGROUND_GREEN  | BACKGROUND_RED);

        print_transition_2();
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN |   BACKGROUND_GREEN  | BACKGROUND_RED);

        print_transition_3();
        system("cls");


        jeu();
        goto debut;
    }
    else
        if(choix==2)
        {
            system("cls");
           SetConsoleTextAttribute(console, FOREGROUND_RED|  BACKGROUND_GREEN  | BACKGROUND_RED);

            print_transition_1();

            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE  |   BACKGROUND_GREEN  | BACKGROUND_RED);

            print_transition_2();
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN |   BACKGROUND_GREEN  | BACKGROUND_RED);

            print_transition_3();
            system("cls");

            guide();
            system("cls");
            goto debut;
        }
        else
            if(choix==4)
            {
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_RED|  BACKGROUND_GREEN  | BACKGROUND_RED);

                print_transition_1();

                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_BLUE  |   BACKGROUND_GREEN  | BACKGROUND_RED);

                print_transition_2();
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN |   BACKGROUND_GREEN  | BACKGROUND_RED);

                print_transition_3();
                system("cls");

                modifier_skin();
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                gotoxy(45,10);
                printf("Press any key to continue...");
                getch();
                system("cls");
                goto debut;
            }
            else
                if(choix==3)
                {
                    system("cls");
                    SetConsoleTextAttribute(console, FOREGROUND_RED|  BACKGROUND_GREEN  | BACKGROUND_RED);

                    print_transition_1();

                    system("cls");
                    SetConsoleTextAttribute(console, FOREGROUND_BLUE  |   BACKGROUND_GREEN  | BACKGROUND_RED);

                    print_transition_2();
                    system("cls");
                    SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN |   BACKGROUND_GREEN  | BACKGROUND_RED);

                    print_transition_3();
                    system("cls");
                    repertoire_musique();
                    system("cls");
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE  | BACKGROUND_GREEN  | BACKGROUND_RED);
                    gotoxy(45,10);
                    printf("Press any key to continue...");
                    getch();
                    system("cls");
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
                    goto debut;
                }
    return 0;
}
