#include <stdio.h>
#include "mysql.h"
#include "../headers/base.h"

void base()
{
    MYSQL mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *password = "issa01";
    char *database = "BIBLIOTHEQUE";

    char requete10[250] = "";
    char requete11[250] = "";
    char requete12[250] = "";

    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");

    if (!mysql_real_connect(&mysql, server, user, password,
                            database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(&mysql));
        exit(1);
    }
    else
    {
        sprintf(requete10, "CREATE TABLE IF NOT EXISTS ADHERANT (id INTEGER PRIMARY KEY AUTO_INCREMENT ,nom VARCHAR(30) NOT NULL,prenom VARCHAR(30) NOT NULL,numero VARCHAR(30) NOT NULL,adresse VARCHAR(30) NOT NULL,annee VARCHAR(30) NOT NULL,years INTEGER NOT NULL,mois INTEGER NOT NULL,days INTEGER NOT NULL,idEtu VARCHAR(30) NOT NULL)");
        mysql_query(&mysql, requete10);
        sprintf(requete11, "CREATE TABLE IF NOT EXISTS EMPRUNT (id INTEGER PRIMARY KEY AUTO_INCREMENT ,NumE VARCHAR(30) NOT NULL,NumL VARCHAR(30) NOT NULL,DateEM INTEGER NOT NULL,mois INTEGER NOT NULL,days INTEGER NOT NULL,nbJ INTEGER NOT NULL)");
        mysql_query(&mysql, requete11);
        sprintf(requete12, "CREATE TABLE IF NOT EXISTS LIVRE (id INTEGER PRIMARY KEY AUTO_INCREMENT ,titre VARCHAR(30) NOT NULL,auteur VARCHAR(30) NOT NULL,motCle VARCHAR(30) NOT NULL,Appar VARCHAR(30) NOT NULL)");
        mysql_query(&mysql, requete12);
        mysql_close(&mysql);
    }
}