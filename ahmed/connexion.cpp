#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_C++");
db.setUserName("marwen");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
    //else throw QString("ERREUR PARAMETRES" +test);
   // return test;

}

void connexion::fermerconnexion()
{ db.close();}
