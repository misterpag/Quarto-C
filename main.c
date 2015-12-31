#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAILLE 4    //taille du tableau de jeu

struct _piece  // tous booléens
{
    char couleur;
    char taille;
    char forme;
    char trou;
};
typedef struct _piece piece;


int initPieces (piece *p)
//création des pièces du jeu
{

    int i;
    for (i=0; i<16; i++)
    {
        p[i].couleur='0';
        p[i].taille='0';
        p[i].forme='0';
        p[i].trou='0';
    }

    for (i=1; i<16;i++)
    {
        if (i>7)
        {
            p[i].trou='1';
        }
        if (p[i-1].couleur=='0')
        {
            p[i].couleur='1';
        }
        else if (p[(i-1)].couleur=='1')
        {
            p[i].couleur='0';
        }

    }

    for (i=2; i<16;i=i+2)
    {
        if (p[(i-1)].taille=='0')
        {
            p[i].taille='1';
            p[i+1].taille='1';
        }
        else if (p[(i-1)].taille=='1')
        {
            p[i].taille='0';
            p[i+1].taille='0';
        }
    }
    for (i=4; i<16;i=i+4)
    {
        if (p[(i-1)].forme=='0')
        {
            p[i].forme='1';
            p[i+1].forme='1';
            p[i+2].forme='1';
            p[i+3].forme='1';
        }
        else if (p[(i-1)].forme=='1')
        {
            p[i].forme='0';
            p[i+1].forme='0';
            p[i+2].forme='0';
            p[i+3].forme='0';
        }
    }


  /*  int i,n;
    for (i=0; i<16; i++)
    {
        n=i;
        n ^ (n >> 1);
        p[i].couleur='0';
        p[i].taille='0';
        p[i].forme='0';
        p[i].trou='0';
    }*/


    return 1;
}

int initPlateau (piece **p)
//création des pièces du jeu
{
    int i, j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            p[i][j].couleur=' ';
            p[i][j].taille=' ';
            p[i][j].forme=' ';
            p[i][j].trou=' ';
        }
    }
    return 1;
}

void affPiece(piece **p, int i ,int j)
{
    char str[4];// = {p[i][j].couleur, p[i][j].forme, p[i][j].taille, p[i][j].trou,'\0'};
    str[0]= p[i][j].trou;
    str[1]= p[i][j].forme;
    str[2]= p[i][j].taille;
    str[3]= p[i][j].couleur;
    str[4]='\0';
    printf("%s", str);
}

void affLigne(piece **p,int ligne)
{
    int i;
    printf("  | ");
    for (i=0; i<4;i++){
        if(i>0)
        printf(" ");
    affPiece(p,ligne,i);
    printf(" |");
    }
    printf("\t\t");
}

int affichagePlateau (piece **p,piece *tab)
//affichage du tableau de pieces et de l'interface utilisateur
{
    int i = 0;
    printf("   ______ ______ ______ ______\t\t");   printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    affLigne(p,0);printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |------|------|------|------|\t\t");  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    affLigne(p,1);  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |------|------|------|------|\t\t");  printf("%d:  %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d: %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    affLigne(p,2);  printf("%d: %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d: %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |------|------|------|------|\t\t");  printf("%d: %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |      |      |      |      |\t\t");  printf("%d: %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    affLigne(p,3);  printf("%d: %c%c%c%c\n",i+1, tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;
    printf("  |______|______|______|______|\t\t");  printf("%d: %c%c%c%c\n", i+1,tab[i].trou,tab[i].forme, tab[i].taille,tab[i].couleur); i++;

    return 0;
}


int verification (int joueur, int tour, piece **p, int dligne, int dcol)
{
    /*In: numéro du joueur
        numéro du tour
        plateau de piece
        derniere ligne jouée
        derniere colonne jouée
    EdB: tester si les cases sont égales , incrémenter les compteurs de param, si = 3 gagné
    Sortie : fin du jeu =1(oui) ou 0 */

    int fini=0,ligne,col, ccoul=0,ctrou=0,ctaille=0,cforme=0;

    if (tour>3 && tour<17) //verif apres le tour 4
    {
        for(ligne=1; ligne<TAILLE; ligne++) //verification de la derniere colonne
        {
            if(p[0][dcol].couleur==p[ligne][dcol].couleur)
                ccoul++;
            else if(p[0][dcol].trou==p[ligne][dcol].trou)
                ctrou++;
            else if(p[0][dcol].taille==p[ligne][dcol].taille)
                ctaille++;
            else if(p[0][dcol].forme==p[ligne][dcol].forme)
                cforme++;

        }

        for(col=1; col<TAILLE; col++) // verification de la derniere ligne
        {
            if(p[dligne][0].couleur==p[dligne][col].couleur)
                ccoul++;
            else if(p[dligne][0].trou==p[dligne][col].trou)
                ctrou++;
            else if(p[dligne][0].taille==p[dligne][col].taille)
                ctaille++;
            else if(p[dligne][0].forme==p[dligne][col].forme)
                cforme++;

        }

        if ( dcol==dligne ) // verfication des diagonales
        {
            for(col=1,ligne=1; col<TAILLE; col++, ligne++)
            {
                if(p[0][0].couleur==p[col][ligne].couleur)
                    ccoul++;
                else if(p[0][0].trou==p[col][ligne].trou)
                    ctrou++;
                else if(p[0][0].taille==p[col][ligne].taille)
                    ctaille++;
                else if(p[0][0].forme==p[col][ligne].forme)
                    cforme++;
            }
        }
        else if  ( dligne== (-dcol+3) ) // verfication des diagonales
        {
            for(col=3,ligne=0; ligne<TAILLE; col--, ligne++)
            {
                if(p[0][3].couleur==p[col][ligne].couleur)
                    ccoul++;
                else if(p[0][3].trou==p[col][ligne].trou)
                    ctrou++;
                else if(p[0][3].taille==p[col][ligne].taille)
                    ctaille++;
                else if(p[0][3].forme==p[col][ligne].forme)
                    cforme++;
            }
        }

    }
printf("\n");

    if( ccoul==3)
    {
        fini=1;
        printf (" Joueur %d a gagne par la couleur\n", joueur);
    }
    if(ctaille==3)
    {
        fini=1;
        printf (" Joueur %d a gagne par la taille\n", joueur);
    }
    if(cforme==3)
    {
        fini=1;
        printf (" Joueur %d a gagne par la forme\n", joueur);
    }
    if(ctrou == 3)
    {
        fini=1;
        printf (" Joueur %d a gagne par le trou\n", joueur);
    }
    if (tour>=17)
    {
        fini=1;
        printf("Match nul ...");
    }
    else
        printf (" Personne ne gagne \n");

    return fini;
}



int verificationCon(int joueur,int tour,piece **p)
{
    int i, j, flag=0;

    if (tour <4)
    {
        for (i=0 ; i<4; i++)
        {
            for (j=1; j<4; j++)
            {
                if(p[i][0].couleur!=p[i][j].couleur)
                {
                    j=4;
                    flag=0;
                }
                else if (p[i][0].taille!=p[i][j].taille)
                {
                    j=4;
                    flag=0;
                }
                else if (p[i][0].forme!=p[i][j].forme)
                {
                    j=4;
                    flag=0;
                }
                else if (p[i][0].trou!=p[i][j].trou)
                {
                    j=4;
                    flag=0;
                }
                else flag=1;
            }
        }
        if(flag==0)
        {
            for (j=0 ; j<4; j++)
            {
                for (i=1; i<4; i++)
                {
                    if(p[0][j].couleur!=p[i][j].couleur)
                    {
                        i=4;
                        flag=0;
                    }
                    else if(p[0][j].taille!=p[i][j].taille)
                    {
                        i=4;
                        flag=0;

                    }
                    else if(p[0][j].forme!=p[i][j].forme)
                    {
                        i=4;
                        flag=0;
                    }
                    else if(p[0][j].trou!=p[i][j].trou)
                    {
                        i=4;
                        flag=0;
                    }
                    else flag=2;
                }
            }
        }
        if(flag==0)
        {
            for (i=1,j=1; i<4&&j<4; i++,j++)
            {
                if(p[0][0].couleur!=p[i][j].couleur)
                {
                    i=4;
                    j=4;
                    flag=0;
                }
                else if(p[0][0].taille!=p[i][j].taille)
                {
                    i=4;
                    j=4;
                    flag=0;

                }
                else if(p[0][0].forme!=p[i][j].forme)
                {
                    i=4;
                    j=4;
                    flag=0;
                }
                else if(p[0][0].trou!=p[i][j].trou)
                {
                    i=4;
                    j=4;
                    flag=0;
                }
                else flag=1;
            }
        }
        if(flag==0)
        {
            for (i=2,j=2; i==0&&j==0; i--,j--)
            {
                if(p[3][3].couleur!=p[i][j].couleur)
                {
                    i=0;
                    j=0;
                    flag=0;
                }
                else if(p[3][3].taille!=p[i][j].taille)
                {
                    i=0;
                    j=0;
                    flag=0;
                }
                else if(p[3][3].forme!=p[i][j].forme)
                {
                    i=0;
                    j=0;
                    flag=0;
                }
                else if(p[3][3].trou!=p[i][j].trou)
                {
                    i=0;
                    j=0;
                    flag=0;
                }
                else flag=1;
            }
        }

printf("\n");
        switch (flag)
        {
        case 0:
            printf ("personne n'a gagné\n");
            break;
        case 1:
            printf ("Joueur %d a gagne par la couleur\n", joueur);
            break;
        case 2:
            printf ("Joueur %d a gagne par la taille\n", joueur);
            break;
        case 3:
            printf ("Joueur %d a gagne par la forme\n", joueur);
            break;
        case 4:
            printf ("Joueur %d a gagne par le trou\n", joueur);
            break;
        default:
            printf ("Probleme !\n");
        }
    }
    if (tour >=16)
    {
        printf("erreur de jeu, plus de solutions !\n");
    }
    return flag;
}

void placement(piece **p,piece *t)
{
int npiece, ligne, colonne, flag =0;
printf("\n \n Quelle piece veux-tu donner a ton adversaire ? \t");
scanf("%d", &npiece);
while ((npiece<1 || npiece>16)||(t[npiece-1].couleur == ' '))
{
    printf("\n Piece non valide ou deja utilise, recommence !\t");
    scanf("%d", &npiece);
   // printf("%c %c %c %c", t[npiece-1].couleur, t[npiece-1].taille, t[npiece-1].forme ,t[npiece-1].trou );
    puts("");
}

do {
printf("Ou veux-tu la placer ? \n");
printf("Ligne : ");
scanf("%d", &ligne);
printf("\nColonne : ");
scanf("%d", &colonne);

ligne--;
colonne--;

if ((ligne <4 && ligne >=0)&&(colonne<4 && colonne >=0)&&(p[ligne][colonne].couleur ==' ') )
    {

    p[ligne][colonne].couleur= t[npiece-1].couleur;
    p[ligne][colonne].taille= t[npiece-1].taille;
    p[ligne][colonne].forme= t[npiece-1].forme;
    p[ligne][colonne].trou= t[npiece-1].trou;

    t[npiece-1].couleur= ' ';
    t[npiece-1].taille = ' ';
    t[npiece-1].forme = ' ';
    t[npiece-1].trou = ' ';

    flag=1;
    }
    else
    {
        printf("Probleme, recommence !");
        flag=0;
    }
}while (flag==0);
}


int main(int argc, char *argv[])
{

    int i =0 ,tour=0, joueur=0, ligne=1, colonne=1;
    piece **plateau;
    plateau = malloc(sizeof(piece*)*TAILLE);
    for(i = 0; i<TAILLE; i++)
    {
        plateau[i] = malloc(sizeof(piece)*TAILLE);
    }
    piece *tab;
    tab = malloc(sizeof(piece*)*16);

    initPieces(tab);
    initPlateau(plateau);

    puts("");
printf("   ____  _    _         _____ _______ ____       ____   \n");
printf("  / __ \\| |  | |  /\\   |  __ \\__   __/ __ \\      \\   | \n");
printf(" | |  | | |  | | /  \\  | |__) | | | | |  | |      \\  |    \n");
printf(" | |  | | |  | |/ /\\ \\ |  _  /  | | | |  | |       \\ |   \n");
printf(" | |__| | |__| / ____ \\| | \\ \\  | | | |__| |        \\|    \n");
printf("  \\___\\_\\\\____/_/    \\_\\_|  \\_\\ |_|  \\____/         \n");
puts("                                                    ##     ");
    puts("");

// fin de l'initialisation//

// début de jeu :

do {
        tour++;
        joueur= (tour%2)+1;
    affichagePlateau(plateau,tab);
    //  verificationCon(joueur,tour, plateau);
    placement(plateau, tab);
    /* -- debug affichage --*//*
    puts("");
    for (i=0; i<4; i++)
    {
        for(j=0; j<4 ; j++)
        {
            printf("%c",plateau[i][j].couleur);
            printf("%c",plateau[i][j].taille);
            printf("%c",plateau[i][j].forme);
            printf("%c",plateau[i][j].trou);
            printf("\t");
        }
        printf("\n");
    }
*/
    }while (//verificationCon(joueur,tour, plateau)
            verification(joueur,tour,plateau,ligne,colonne)==0 );


    free(tab);
    free(plateau);
    return 0;
}

