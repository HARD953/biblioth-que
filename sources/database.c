#include <stdio.h>
#include "mysql.h"
#include <stdlib.h>
#include "../headers/base.h"
#include "../headers/database.h"

MYSQL connexion(){
    MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "localhost";
	char *user = "root";
	char *password = "issa01"; 
	char *database = "BIBLIO";
	
	mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if (!mysql_real_connect(&mysql, server, user, password, 
                                      database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(&mysql));
		exit(1);
	}

    else{
        return mysql;
    }
}