#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"
#include "headers/adherents.h"
#include "headers/base.h"
#include <time.h>

int main(int argc, int* argv[])
{
    char nom[30];
    char idEtud[30];
    char prenom[30];
    char date_naissance[30];
    char adresse[30];
    char numero[30];
    char titre[30];
    char auteur[30];
    char motcle[30];
    char app[30];
    char numerE[30];
    char numerL[30];
    char dateEm[30];
    int dateReP;
    char dateRe[30];
    char numeroE[30];
    char numeroL[30];
    char numerLi[30];
    int reponse;
    char repos[10];
    char tab;
    int h, min, s, day, mois, an;
	time_t now;
    
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "";
    char requete1[300]="";
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    struct tm *local = localtime(&now);
    h = local->tm_hour;      	
	min = local->tm_min;     	
	s = local->tm_sec;     	
	day = local->tm_mday;        	
	mois = local->tm_mon + 1;   	
	an = local->tm_year + 1900;

    if (!mysql_real_connect(&mysql, server, user, password,database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", (&mysql));
		exit(1);
    
	}
    else{
        sprintf(requete1,"CREATE DATABASE IF NOT EXISTS BIBLIOTHEQUE");
        mysql_query(&mysql,requete1);
        mysql_close(&mysql);
        base();
		printf("                                           Bienvenue a la Bibliotheque Virtuelle de L'ESATIC \n\n");
		printf("                                                Quelle Action Voulez vous effectuez  \n\n");
        printf("\n\n");
        printf("1-INSCRIPTION                                             2-VERIFIER ADHERANT                                           3-AJOUT DE LIVRE\n");
        printf("4-LISTER LIVRE                                            5-DESABONNEMENT                                               6-EMPRUNT \n");
        printf("7-LISTER EMPRUNT                                          8-RETIRER UN LIVRE                                            9-LISTER LIVRE \n");
        printf("                                                          0-POUR SORTIR \n\n");
		scanf("%d",&reponse);
        while(&reponse!=0)
        {
            switch (reponse)
            {
            case 1:
                printf("                                   POUR L'INSCRIPTION REMPLIR LES FORMULAIRES SUIVANT \n");
                printf("Nom : \n");
                scanf("%s", nom);
            
                printf("Prenom : \n");
                scanf("%s", prenom);

                printf("Numero : \n");
                scanf("%s", numero);

                printf("Adresse : \n");
                scanf("%s", adresse);

                printf("Date de naissance : \n");
                scanf("%s", date_naissance);
                
                printf("identifiant : \n");
                scanf("%s", idEtud);
                inscrire_adherent(nom,prenom,numero,adresse,date_naissance,idEtud,an,mois,day);
                printf("Inscription reussir!!!\n\n");
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 2:
                printf("                                           POUR L'AJOUT DE LIVRE REMPLIR LES FORMULAIRES SUIVANT \n");
                printf("Titre : \n");
                scanf("%s", titre);
            
                printf("Auteur : \n");
                scanf("%s", auteur);

                printf("MotClé : \n");
                scanf("%s", motcle);

                printf("Apparition : \n");
                scanf("%s", app);
                ajouter_livre(titre,auteur,motcle,app);
                printf("Insertion reussir!!!\n\n");
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 3:
                printf("                                               POUR L'EMPRUNT DE LIVRE \n");            
                printf("NumeroEtudiant : \n");
                scanf("%s", numerE);
            
                printf("NumeroLivre : \n");
                scanf("%s", numerLi);

                printf("Nombre de Jour : \n");
                scanf("%d", dateReP);
                
                Emprunter_livre(numerE,numerLi,an,dateReP,mois,day);
                printf("Emprunt reussir!!!\n\n");
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 4:
                printf("                                                   POUR LISTER LES LIVRES \n");
                lister_livre();
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 5:
                printf("                                                     POUR LISTER LES EMPRUNTS \n");
                lister_empreint();
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 6:
                printf("                                                       POUR VERIFIER LES ADHERANTS \n");
                printf("Entrez le numeroEtudiant : \n");
                scanf("%s", numeroE);
                verifierAdherent(numeroE);
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 7:
                printf("                                                 POUR L'INSCRIPTION REMPLIR LES FORMULAIRES SUIVANT \n");
                printf("Entrez le numeroEtudiant : \n");
                scanf("%s",numeroE);
                desabonne_adherent(numeroE);
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 8:
                printf("                                                          Entrez le NumeroLivre : \n");
                scanf("%s",numeroL);
                enlever_livre(numeroL);
                printf("Voulez vous continuez oui/non?");
                scanf("%s",repos);
                if (repos=="non"){break;}
                else{
                    scanf("%d",reponse);
                    }
                break;
            case 0:
                break;
            }
        }
        printf("      Quelle Action Voulez vous effectuez : zero pour sortie \n\n");
        scanf("%s",repos);
	}
}