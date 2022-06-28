#include <stdio.h>
#include "mysql.h"
#include "../headers/adherents.h"
#include "../headers/base.h"

void inscrire_adherent(char* nom, char* prenom, char* numero, char* adresse, char* date_naissance,char* idEtud,int* an,int* mois,int* day){
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01";
	char *database = "BIBLIOTHEQUE";

    char requete1[1500] = "";
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password,database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete1, "INSERT INTO ADHERANT (nom,prenom,numero,adresse,annee,idEtu,years,mois,days) VALUES('%s', '%s', '%s','%s','%s','%s','%d','%d','%d')",nom,prenom,numero,adresse,date_naissance,idEtud,an,mois,day);
        mysql_query(&mysql, requete1);
        mysql_close(&mysql);
    }


}

void ajouter_livre(char* titre,char* auteur,char* motCle,char* App){
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete2[1500] = "";
    
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete2, "INSERT INTO LIVRE (titre,auteur,motCle,Appar) VALUES('%s','%s','%s','%s')",titre,auteur,motCle,App);
        mysql_query(&mysql, requete2);
        mysql_close(&mysql);
    }
}


void Emprunter_livre(char* numerE,char* numerL,int* an,int* mois,int* day,int* dateReP){
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete3[1500] = "";
    
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete3, "INSERT INTO EMPRUNT (NumE,NumL,DateEM,mois,days,nbJ) VALUES ('%s', '%s','%d','%d','%d','%d')",numerE,numerL,an,mois,day,dateReP);
        mysql_query(&mysql, requete3);
        mysql_close(&mysql);
    }
}

void lister_adherent(){
    MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete4[1500] = "";
    
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}
    else{
        sprintf(requete4, "select * from ADHERANT");
        mysql_query(&mysql, requete4);
        unsigned int i = 0;
        unsigned int num_champs = 0;
        int j =1;
        result = mysql_use_result(&mysql);
        num_champs = mysql_num_fields(result);
        while ((row = mysql_fetch_row(result)))
            {

                unsigned long *lengths;

                lengths = mysql_fetch_lengths(result);

                
                for(i = 1; i < num_champs; i++)
                    {


                        printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
                    }
                       printf("\n");

            }
        mysql_close(&mysql);
    }
}
    //Editer les livres 
void lister_livre(){
    MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete5[1500] = "";
    
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete5, "select * from LIVRE");
        mysql_query(&mysql, requete5);
        unsigned int i = 0;
        unsigned int num_champs = 0;
        int j =1;
        result = mysql_use_result(&mysql);
        num_champs = mysql_num_fields(result);
        while ((row = mysql_fetch_row(result)))
            {

                unsigned long *lengths;

                lengths = mysql_fetch_lengths(result);

                for(i = 1; i < num_champs; i++)
                    {


                        printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
                    }
                       printf("\n");

            }
        mysql_close(&mysql);
    }
}


void lister_empreint(){
    MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete6[1500] = "";
    
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete6, "select * from EMPRUNT");
        mysql_query(&mysql, requete6);
        unsigned int i = 0;
        unsigned int num_champs = 0;
        int j =1;
        result = mysql_use_result(&mysql);
        num_champs = mysql_num_fields(result);
    
        unsigned long *lengths;
        lengths = mysql_fetch_lengths(result);

        
        for(i = 1; i < num_champs; i++)
            {
                printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
                printf("\n");
            }
            

        
        mysql_close(&mysql);
    }
}


void verifierAdherent(char* numero ){
    MYSQL mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete7[1500] = "";
    
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete7, "select * from ADHERANT where numero='%s'",numero);
        mysql_query(&mysql, requete7);
        unsigned int i = 0;
        unsigned int num_champs = 0;
        int j =1;
        result = mysql_use_result(&mysql);
        num_champs = mysql_num_fields(result);
            

        unsigned long *lengths;

        lengths = mysql_fetch_lengths(result);

                
        for(i = 1; i < num_champs; i++)
            {
                printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
            }
                printf("\n");

            

        mysql_close(&mysql);
    }

}


void desabonne_adherent(char* numero){
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete8[1500] = "";
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete8, "delete from ADHERANT where numero='%s'",numero);
        mysql_query(&mysql, requete8);
        mysql_close(&mysql);
    }
}

void enlever_livre(char* numeroL){
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIOTHEQUE";

    char requete9[1500] = "";
    
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        sprintf(requete9, "delete from LIVRE where numeroL='%s'",numeroL);
        mysql_query(&mysql, requete9);
        mysql_close(&mysql);
    }
}
