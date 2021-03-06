#include "client.h"
#include <QDebug>
client::client()
{

}
client::client(int cin,QString nom,QString prenom,QString adresse,int numtel,QString img)
{
    this->img=img;
    this->cin=cin;
    this->nom=nom;
    this->numtel=numtel;
    this->prenom=prenom;
    this->adresse=adresse;
}
bool client::rech(QString a)
{
    QSqlQuery q1;
    q1.exec("select * from client where cin='"+a+"'");
    bool test=q1.next();
    return test;
}
QString client::retournerInfos(QString a)
{                           //retourner le nom et le numtel de client en question
      QString infos="";
   QSqlQuery q("select * from client where cin="+a);
   while (q.next()) {
    infos="Nom : "+q.value(1).toString()+" numtel: "+q.value(4).toString();
   }
   return infos;

}
bool client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO client VALUES(:cin,:nom,:prenom,:adresse,:numtel,:img)");
    query.bindValue(":adresse",adresse);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":cin",cin);
     query.bindValue(":numtel",numtel);
     query.bindValue(":img",img);
    return query.exec();
}
bool client::supprimer(QString cin)
{
    if(!rech(cin)){return false;}
    QSqlQuery query;

    query.prepare("Delete from client where cin=:cin");
    query.bindValue(":cin",cin);
    return query.exec();
}
QSqlQueryModel *client::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from client");
    return model;
}
QSqlQueryModel *client::afficherTri(QString critere)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from client order by "+critere);
    return model;
}
QSqlQueryModel *client::afficherRech(QString critere,QString rech)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from client where "+critere+" like '"+rech+"%'");
    return model;
}
bool client::modifier(QString rech1)
{
    QSqlQuery query;
    query.prepare("update client set image=:img,nom=:nom,prenom=:prenom,adresse=:adresse,numtel=:numtel where cin=:cin");
    query.bindValue(":adresse",adresse);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":cin",cin);
     query.bindValue(":numtel",numtel);
      query.bindValue(":img",img);
    return query.exec();
}
