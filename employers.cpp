#include "employers.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

Employers::Employers()
{
    id_e=0;
    nom_e="";
    prenom_e="";
    adresse_e="";
    telephone_e=0;
    type="";
    specialite="";

}
Employers::Employers(int id,QString nom, QString prenom,QDate date_naissance,QString adresse,int telephone,QString type, QString specialite)
{
this->id_e=id;
this->nom_e=nom;
this->prenom_e=prenom;
this->date_naissance_e=date_naissance;
this->adresse_e=adresse;
this->telephone_e=telephone;
this->type=type;
this->specialite=specialite;
}
bool Employers::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(id_e); //convertion
    QString res1 = QString::number(telephone_e);

    query.prepare("insert into EMPLOYERS(id_e,nom_e,prenom_e, date_naissance_e, adresse_e,telephone_e,type,specialite)"" values(:id,:nom,:prenom, :date_naissance, :adresse,:telephone,:type,:specialite)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom_e);
    query.bindValue(":prenom",prenom_e);
    query.bindValue(":date_naissance",date_naissance_e);
    query.bindValue(":adresse",adresse_e);
    query.bindValue(":telephone",res1);
    query.bindValue(":type",type);
    query.bindValue(":specialite",specialite);
    return query.exec();
}
QSqlQueryModel * Employers::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Employers");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("specialite"));
    return model;
}
bool Employers::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from EMPLOYERS where ID_E= :id");
    query.bindValue(":id",res);
    return  query.exec();
}

bool Employers::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(telephone_e);
    //QString res2 = QString::number(date);
    query.prepare("UPDATE EMPLOYERS SET nom_e= :nom, prenom_e= :prenom,date_naissance_e= :date_naissance_e,adresse_e= :adresse,telephone_e= :telephone_e, type= :type, specialite= :specialite WHERE id_e = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom_e);
    query.bindValue(":prenom",prenom_e);
    query.bindValue(":date_naissance",date_naissance_e);
    query.bindValue(":adresse",adresse_e);
    query.bindValue(":telephone",res1);
    query.bindValue(":type",type);
    query.bindValue(":specialite",specialite);
    return query.exec();
}






















//***************************************RECHERCHE*********************

QSqlQueryModel * Employers::recherche(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString c=QString::number(id);
    model->setQuery("select * from EMPLOYERS where ID_E="+c);
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"Nom");
    model->setHeaderData(2,Qt::Horizontal,"Prenom");
    model->setHeaderData(3,Qt::Horizontal,"date_naissance");
    model->setHeaderData(4,Qt::Horizontal,"adresse");
    model->setHeaderData(5,Qt::Horizontal,"telephone");
    model->setHeaderData(5,Qt::Horizontal,"type");
    model->setHeaderData(5,Qt::Horizontal,"specialite");
    return(model);
}

//******************************MAILING************************


