#ifndef _H_ADHERENTS_H
#define _H_ADHERENTS_H
    //Editer les adherents
    void inscrire_adherent(char* nom, char* prenom, char* numero,char* adresse,char* date_naissance,char* idEtud,int* an,int* mois,int* day);
    void desabonne_adherent(char* numero);
    void lister_adherent();
    void verifierAdherent(char* numero);
    void lister_empreint();

    //Editer les livres 
    void lister_livre();
    void ajouter_livre(char* titre,char* auteur,char* motCle,char* App);
    void enlever_livre(char* numeroL);
    //Emprunter Les livres
    void Emprunter_livre(char* numerE,char* numerL,int* an,int* mois,int* day,int* dateReP);
    
    //Editer les retardaires
#endif