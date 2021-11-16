#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QDialog>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtCore/QCoreApplication>
#include "employers.h"
namespace  Ui{
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButtonAjouter_clicked();
    void on_pushButtonSupprimer_clicked();
    void on_pushButtonModifier_clicked();
    void on_pushButtonModifier2_clicked();
    void on_pushButtonafficher_clicked();


    void on_pushButton_Login_clicked();
    //void on_rechercheEmployerButton_clicked();
    bool search(int t);

    //void on_pushButton_clicked();

    void on_pushButton_40_clicked();


    void on_pushButtonAjouterh_clicked();

    void on_pushButton_planning_clicked();

    void on_comboBox_id_p_activated();

    void on_lineEdit_idEmployerachercher_cursorPositionChanged();

    void on_pushButtonEnvoyer_clicked();

    void on_comboBoxTri_activated();

    //void on_pushButton_PDF_clicked();


    void on_pushButtonAfficherMessage_clicked();

    void on_pushButton_Contacter_clicked();
    void browse();
    void sendMail();
    void mailSent(QString status);
    //void on_pushButton_43_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Employers e;
    Employers e1;
    QStringList files;
};

#endif // MAINWINDOW_H
