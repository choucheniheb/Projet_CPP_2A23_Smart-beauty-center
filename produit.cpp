#include "produit.h"
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

produit::produit()
{

  this -> quantite_produit=0;
  this -> prix_uni=0;
  this ->  prix_promo=0;
  this -> categorie="";
  this -> code_a_barre=0;
  this -> nom_p="";
  this -> date_expiration="";
 // this -> stock="";
}

produit::produit(int code_a_barre, QString nom_p , int prix_uni ,int prix_promo,QString categorie,QString date_expiration,int quantite_produit)
{

    this -> quantite_produit=quantite_produit;
    this -> prix_uni=prix_uni;
    this ->  prix_promo=prix_promo;
    this -> categorie=categorie;
    this -> code_a_barre=code_a_barre;
    this -> nom_p=nom_p;
    this -> date_expiration=date_expiration;
   // this -> stock=stock;
}
//get

int produit::getquantite_produit(){return quantite_produit;}
int produit::getprix_uni(){return prix_uni;}
int produit::getprix_promo(){return prix_promo;}
QString produit::getcategorie(){return categorie;}
int produit::getcode_a_barre(){return code_a_barre;}
QString produit::getnom_p(){return nom_p;}
QString produit::getdate_expiration(){return date_expiration;}
// bool produit::getstock(){return stock;}

//set

void produit::setquantite_produit(int quantite_produit){this -> quantite_produit=quantite_produit;}
void produit::setprix_uni(int prix_uni){this -> prix_uni=prix_uni;}
void produit::setprix_promo(int prix_promo){this -> prix_promo=prix_promo;}
void produit::setcategorie(QString categorie){this -> categorie=categorie;}
void produit::setcode_a_barre(int code_a_barre){this -> code_a_barre=code_a_barre;}
void produit::setnom_p(QString nom_p){this -> nom_p=nom_p;}
void produit::setdate_expiration(QString date_expiration){this -> date_expiration=date_expiration;}
// void produit::setstock(bool stock){this -> stock=stock;}

//recherche
QSqlQueryModel* produit::rechercheMulticritere(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();

    trouve->setQuery("SELECT * FROM produit WHERE code_a_barre LIKE '"+recherche+"%' OR nom_p LIKE '"+recherche+"%' OR categorie LIKE '"+recherche+"%'");

    trouve->setHeaderData(0,Qt::Horizontal,QObject::tr("code_a_barre"));
    trouve->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_p"));
    trouve->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_uni"));
    trouve->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_promo"));
    trouve->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
    trouve->setHeaderData(5,Qt::Horizontal,QObject::tr("date_expiration"));
    trouve->setHeaderData(6,Qt::Horizontal,QObject::tr("quantite_produit"));


    return trouve;
}

/* fonction rechercher
QSqlQueryModel * produit::recherche(int code_a_barre)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString c=QString::number(code_a_barre);
    model->setQuery("select * from produit where code_a_barre="+c);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code_a_barre"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_p"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_uni"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_promo"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date_expiration"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("quantite_produit"));
    return(model);
} */

//ajout////////////
bool produit::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(code_a_barre);
    QString res1 = QString::number(prix_uni);
    QString res2 = QString::number(prix_promo);
    QString res3 = QString::number(quantite_produit);

    query.prepare("insert into produit( code_a_barre,  nom_p ,  prix_uni , prix_promo,date_expiration,categorie, quantite_produit)"" values(:code_a_barre,:nom_p,:prix_uni,:prix_promo,:date_expiration,:categorie,:quantite_produit)");
    query.bindValue(":code_a_barre",res);
    query.bindValue(":nom_p",nom_p);
    query.bindValue(":prix_uni",res1);
    query.bindValue(":prix_promo",res2);

    query.bindValue(":date_expiration",date_expiration);
    query.bindValue(":categorie",categorie);
    query.bindValue(":quantite_produit",res3);
    return query.exec();

}
//fonction afficher
QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from produit");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CODE_A_BARRE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX_UNI"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_PROMO"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_P"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("CATEGORIE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_EXPIRATION"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("QUANTITE_PRODUIT"));
    return model;
}
//fonction supprimer
bool produit::supprimer(int code_a_barre)
{
    QSqlQuery query;
    QString res =QString::number(code_a_barre);
    query.prepare("delete from produit where code_a_barre= :code_a_barre");
    query.bindValue(":code_a_barre",res);
    return  query.exec();
}
//fonction modifier
bool produit::modifier(int code_a_barre)
{
    QSqlQuery query;
    QString res = QString::number(code_a_barre);
     QString res1 = QString::number(prix_uni);
      QString res2 = QString::number(prix_promo);
       QString res3 = QString::number(quantite_produit);

    query.prepare("UPDATE produit SET prix_uni= :prix_uni,prix_promo= :prix_promo, quantite_produit= :quantite_produit WHERE code_a_barre = :code_a_barre");
    query.bindValue(":code_a_barre",res);
    query.bindValue(":prix_uni",res1);
    query.bindValue(":prix_promo",res2);
    query.bindValue(":quantite_produit",res3);
    return query.exec();
}

