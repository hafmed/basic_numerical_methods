// Les programmes Enseignement 14-15 / 19-20 /20-21 29-06-2021
// HAFIANE Mohamed le 5-9-2020 V 1.9.0
// HAFIANE Mohamed le 1-8-2021 V 3.0.10
// HAFIANE Mohamed le 15-5-2022 V 3.0.17
//#include <QDesktopWidget>
#include "fparser.hh"
#include <iostream>
#include <string>
#include <QMessageBox>
#include <QtGui>
#include <QString>
#include "basic_numerical_methods.h"
#include "ui_basic_numerical_methods.h"
#include "constants.h"
#include <QMessageBox>
#include <math.h>
#include <QRegularExpression>
/////---- 21-7-201 ----
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
#include <limits>
/////------------------
basic_numerical_methods::basic_numerical_methods(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    //label_version->setText("HAF-MED Ver: " APP_VERSION "");

    // HAF le 1-9-2009 pour Kubuntu seulement-------------
    setlocale(LC_NUMERIC, "C"); //avoir comme separateur decimal le point ...
    //----------------------------------------------------
    //tableWidget_donnees->setEditTriggers(QAbstractItemView::NoEditTriggers); //pour empecher l'edition du tableau

    connect(pushButton_about,SIGNAL(clicked()), this, SLOT(about()));
    connect(pushButton_help,SIGNAL(clicked()), this, SLOT(help()));

    connect(pushButton_Calculer_ColebrookWhite, SIGNAL(clicked()), this, SLOT(hafafficherColebrookWhite()));
    connect(pushButton_Calculer_Integration, SIGNAL(clicked()), this, SLOT(hafafficherIntegration()));
    connect(pushButton_Calculer_tracage_fxgx, SIGNAL(clicked()), this, SLOT(hafaffichertracagefxgx()));

    connect(spinBox_nbre_pts_fx, SIGNAL(editingFinished()), this, SLOT(nselonmethodechoisie()));
    connect(spinBox_nbre_pts_fx, SIGNAL(valueChanged(int)), this, SLOT(changervaleurpas()));
    connect(lineEdit_a, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(changervaleurpas()));
    connect(lineEdit_b, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(changervaleurpas()));
    connect(spinBox_nbre_pts_tableau, SIGNAL(valueChanged(int)), this, SLOT(synchronisationdeuxspinBox()));
    //---5-9-2009
    connect(radioButton_trapezes, SIGNAL(clicked()), this, SLOT(nselonmethodechoisie()));
    connect(radioButton_simpson13, SIGNAL(clicked()), this, SLOT(nselonmethodechoisie()));
    connect(radioButton_simpson38, SIGNAL(clicked()), this, SLOT(nselonmethodechoisie()));
    //-- convert HAF - 5-9-2009 -----------
    connect(pushButton_convert_decimal,SIGNAL(clicked()), this, SLOT(convert()));
    //-------------------------------------
    //-HAF 25-7-2020
    connect(buttonGroup_methodesEqtNonLineaire,SIGNAL(idClicked(int)), this, SLOT(choixmethodeeqtnonlineaire(int)));
    connect(pushButton_Calculer_methodesEqtNonLineaire, SIGNAL(clicked()), this, SLOT(hafresolutioneqtnonlineaire()));
    lineEdit_x1->hide();
    label_x1->hide();
    //-HAF 5-8-2020
    const QRegularExpression double_rx("[+]?[0-9]*\\.?[0-9]+([eE][-]?[0-9]+)?"); //sans - et e-
    lineEdit_tolerance_eqtnonlineaire->setValidator(new QRegularExpressionValidator(double_rx,this));
    const QRegularExpression double_x0("[+-]?[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?");
    lineEdit_x0->setValidator(new QRegularExpressionValidator(double_x0,this));
    lineEdit_x1->setValidator(new QRegularExpressionValidator(double_x0,this));
    connect(pushButton_Copier_TableauEqtNonLineaire,SIGNAL(clicked()), this, SLOT(copy_tableWidget_donnees_eqtnonlineaire()));
    pushButton_Copier_TableauEqtNonLineaire->hide();
    //-HAF 7-8-2020
    connect(buttonGroup_methodeeqtdifferentielle,SIGNAL(idClicked(int)), this, SLOT(choixmethodeeqtdifferentielle(int)));
    connect(pushButton_Calculer_methodeeqtdifferentielle, SIGNAL(clicked()), this, SLOT(hafresolutioneqtdifferentielle()));
    connect(pushButton_Copier_Tableaueqtdifferentielle,SIGNAL(clicked()), this, SLOT(copy_tableWidget_donnees_eqtdifferentielle()));
    pushButton_Copier_Tableaueqtdifferentielle->hide();
    connect(spinBox_nptseqtdifferentielle, SIGNAL(valueChanged(int)), this, SLOT(changervaleurpas_eqtdifferentielle()));
    connect(lineEdit_a_methodeeqtdifferentielle, SIGNAL(editingFinished()), this, SLOT(changervaleurpas_eqtdifferentielle()));
    connect(lineEdit_b_methodeeqtdifferentielle, SIGNAL(editingFinished()), this, SLOT(changervaleurpas_eqtdifferentielle()));
    //-HAF 5-8-2020
    lineEdit_tolerance_eqtnonlineaire->setToolTip("f(xi)<=Tolérance");
    //-HAF 19-8-2020
    connect(lineEdit_fx_eqt_non_lineaire, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfunctionfx()));
    connect(lineEdit_gx_eqt_non_lineaire, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfunctiongx()));
    connect(lineEdit_fprime_eqt_non_lineaire, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfunctionfprime()));
    //
    connect(lineEdit_x0, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinx0()));
    connect(lineEdit_x1, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinx1()));
    connect(lineEdit_tolerance_eqtnonlineaire, SIGNAL(textChanged(const QString)), this, SLOT(textChangedintolerance()));
    fparserfx.AddConstant("pi", M_PI);
    fparsergx.AddConstant("pi", M_PI);
    fparserfprime.AddConstant("pi", M_PI);
    fparserfprimex.AddConstant("pi", M_PI);
    fparseryprim.AddConstant("pi", M_PI);
    fparserfxintegrale.AddConstant("pi", M_PI);
    //
    connect(lineEdit_yprime_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfunctionyprim()));
    connect(lineEdit_a_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_a_methodeeqtdifferentielle()));
    connect(lineEdit_b_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_b_methodeeqtdifferentielle()));
    connect(lineEdit_y0_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_y0_methodeeqtdifferentielle()));
    lineEdit_a_methodeeqtdifferentielle->setValidator(new QRegularExpressionValidator(double_x0,this));
    lineEdit_b_methodeeqtdifferentielle->setValidator(new QRegularExpressionValidator(double_x0,this));
    lineEdit_y0_methodeeqtdifferentielle->setValidator(new QRegularExpressionValidator(double_x0,this));
    //
    connect(lineEdit_fx_integ, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfx_integ()));
    connect(lineEdit_a, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_a_integ()));
    connect(lineEdit_b, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_b_integ()));
    lineEdit_a->setValidator(new QRegularExpressionValidator(double_x0,this));
    lineEdit_b->setValidator(new QRegularExpressionValidator(double_x0,this));
    //
    connect(lineEdit_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfx_tracage()));
    connect(lineEdit_a_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_a_tracage()));
    connect(lineEdit_b_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_b_tracage()));
    connect(lineEdit_dx_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_dx_tracage()));
    lineEdit_a_tracage_fx->setValidator(new QRegularExpressionValidator(double_x0,this));
    lineEdit_b_tracage_fx->setValidator(new QRegularExpressionValidator(double_x0,this));
    lineEdit_dx_tracage_fx->setValidator(new QRegularExpressionValidator(double_rx,this));
    //
    lineEdit_Diametre->setValidator(new QRegularExpressionValidator(double_rx,this));
    lineEdit_Ruguosite->setValidator(new QRegularExpressionValidator(double_rx,this));
    lineEdit_Debit->setValidator(new QRegularExpressionValidator(double_rx,this));
    //
    connect(lineEdit_Diametre, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_Diametre()));
    connect(lineEdit_Ruguosite, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_Ruguosite()));
    connect(lineEdit_Debit, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_Debit()));
    // ver 3 -25-6-2021
    connect(spinBox_nbre_eqts, SIGNAL(valueChanged(int )), this, SLOT(resize_tableWidget_donnees_SysteqtsLineaires(int )));
    tableWidget_donnees_SysteqtsLineaires->resizeColumnsToContents();
    groupBox_tolerance_methodeSystEqtLineares->hide();
    groupBox_nbreItera->hide();
    //
    connect(buttonGroup_methodeSystEqtLineares,SIGNAL(idClicked(int)), this, SLOT(choixmethodeSystEqtLineares(int)));
    connect(pushButton_Calculer_methodeSystEqtLineares, SIGNAL(clicked()), this, SLOT(hafresolutionSystEqtLineares()));
    progressBar_SysteqtsLineaires->setMaximum(spinBox_nbre_itera->value());
    progressBar_SysteqtsLineaires->setValue(0);
    progressBar_SysteqtsLineaires->hide();
    /////5-7-2021
    pushButton_mouveRow->hide();
    connect(pushButton_mouveRow, SIGNAL(clicked()), this, SLOT(on_PushButonClicked()));
    /////
    fgBrush = tableWidget_donnees_SysteqtsLineaires->item(0, 0)->foreground();
    bgBrush = tableWidget_donnees_SysteqtsLineaires->item(0, 0)->background();
    /////----15-7-2021--------
    connect(spinBox_nbre_pts_ApproximationPolynomiale, SIGNAL(valueChanged(int )), this, SLOT(resize_tableWidget_donnees_ApproximationPolynomiale(int )));
    tableWidget_donnees_ApproximationPolynomiale->resizeColumnsToContents();
    connect(buttonGroup_methodeApproximationPolynomiale,SIGNAL(idClicked(int)), this, SLOT(choixmethodeApproximationPolynomiale(int)));
    connect(pushButton_Calculer_methodeApproximationPolynomiale, SIGNAL(clicked()), this, SLOT(hafcalculApproximationPolynomiale()));

#if defined(Q_OS_ANDROID)
    pushButton_navigation->show();
    connect(pushButton_navigation, SIGNAL(clicked()), this, SLOT(tabWidgetNavigation()));
#else
    pushButton_navigation->hide();
    //connect(pushButton_close,SIGNAL(clicked()), this, SLOT(close()));
#endif

    //-10-6-2022
    connect(buttonGroup_AlgoProgra, SIGNAL(idToggled(int , bool )), this, SLOT(choiseAlgoOrganProg(int , bool)));
}
void basic_numerical_methods::choiseAlgoOrganProg(int id, bool checked)
{
    /////qDebug()<<"id"<<id<<"et checked="<<checked;
    if (id==-2 && checked) {
        stackedWidget_AffectationEntrees->setCurrentIndex(0);
        stackedWidget_Test->setCurrentIndex(0);
        stackedWidget_Boucle->setCurrentIndex(0);
        stackedWidget_Boucle_Test->setCurrentIndex(0);
        stackedWidget_Sorties->setCurrentIndex(0);
    }else if (id==-3 && checked) {
        stackedWidget_AffectationEntrees->setCurrentIndex(1);
        stackedWidget_Test->setCurrentIndex(1);
        stackedWidget_Boucle->setCurrentIndex(1);
        stackedWidget_Boucle_Test->setCurrentIndex(1);
        stackedWidget_Sorties->setCurrentIndex(1);
    }else if (id==-4 && checked) {
        stackedWidget_AffectationEntrees->setCurrentIndex(2);
        stackedWidget_Test->setCurrentIndex(2);
        stackedWidget_Boucle->setCurrentIndex(2);
        stackedWidget_Boucle_Test->setCurrentIndex(2);
        stackedWidget_Sorties->setCurrentIndex(2);
    }

}
//-----HAF 9-6-2022-----
void basic_numerical_methods::tabWidgetNavigation()
{
    int temp=tabWidget->currentIndex();
    if (temp==tabWidget->count()-1) {
        tabWidget->setCurrentIndex(0);
    }else{
        tabWidget->setCurrentIndex(temp+1);
    }
}
//-----HAF 21-08-2021-----
void basic_numerical_methods::hafclearcustomPlot()
{
    customPlot->clearGraphs();
    for( int g=0; g<customPlot->graphCount(); g++ )
    {
        customPlot->graph(g)->data().clear();
    }
    customPlot->replot();
}
/////----15-7-2021--------
void basic_numerical_methods::hafcalculApproximationPolynomiale()
{
    id=buttonGroup_methodeApproximationPolynomiale->checkedId();
    switch (id) {
    case -2:
        n=tableWidget_donnees_ApproximationPolynomiale->rowCount();
        resize_tableWidget_donnees_ApproximationPolynomiale(spinBox_nbre_pts_ApproximationPolynomiale->value());
        hafcalculApproximationPolynomiale_Lagrange();
        stackedWidget_choixmethodeApproximationPolynomiale->setCurrentIndex(0);
        break;

    case -3:
        hafcalculApproximationPolynomiale_Newton();
        stackedWidget_choixmethodeApproximationPolynomiale->setCurrentIndex(1);
        break;
    }
}
void basic_numerical_methods::choixmethodeApproximationPolynomiale(int id)
{
    pushButton_Calculer_methodeSystEqtLineares->show();
    pushButton_mouveRow->hide();
    n=spinBox_nbre_pts_ApproximationPolynomiale->value();
    resize_tableWidget_donnees_ApproximationPolynomiale(n);
    switch (id) {
    case -2:
        tableWidget_donnees_ApproximationPolynomiale->setColumnCount(2);
        stackedWidget_choixmethodeApproximationPolynomiale->setCurrentIndex(0);
        tableWidget_donnees_ApproximationPolynomiale->item(0, 1)->setForeground(fgBrush);
        tableWidget_donnees_ApproximationPolynomiale->item(0, 1)->setBackground(bgBrush);
        break;

    case -3:
        tableWidget_donnees_ApproximationPolynomiale->setColumnCount(n+1);
        stackedWidget_choixmethodeApproximationPolynomiale->setCurrentIndex(1);
        break;
    }
}
void basic_numerical_methods::hafcalculApproximationPolynomiale_Lagrange()
{
    outputtext="";
    ApproximationPolynomiale_textBrowser->clear();
    /////
    n=tableWidget_donnees_ApproximationPolynomiale->rowCount();
    resize_tableWidget_donnees_ApproximationPolynomiale(spinBox_nbre_pts_ApproximationPolynomiale->value());
    for(i=0;i<n;i++)
    {
        item = tableWidget_donnees_ApproximationPolynomiale->item(i,0);
        if (!item || item->text().isEmpty()) /* the cell is not empty */
        {
            ApproximationPolynomiale_textBrowser->clear();
            resultatsMessage.warning(this, tr("Erreur données"),
                                     tr("Veuillez remplir complètement le tableau!"));
            goto fin5;
        }
        else /* the cell is empty */
        {
            xploy[i]=tableWidget_donnees_ApproximationPolynomiale->item(i,0)->text().toFloat();
        }
        item = tableWidget_donnees_ApproximationPolynomiale->item(i,1);
        if (!item || item->text().isEmpty()) /* the cell is not empty */
        {
            ApproximationPolynomiale_textBrowser->clear();
            resultatsMessage.warning(this, tr("Erreur données"),
                                     tr("Veuillez remplir complètement le tableau!"));
            goto fin5;
        }
        else /* the cell is empty */
        {
            yploy[i]=tableWidget_donnees_ApproximationPolynomiale->item(i,1)->text().toFloat();
        }
        //qDebug()<<"x["<<i<<"]="<<xploy[i];
        //qDebug()<<"y["<<i<<"]="<<yploy[i];
    }
    m=n-1;
    ////
    for (i=0; i<=m; i++)
        s[i]=cof[i]=0.0;
    s[m] = -xploy[0];
    for (i=1; i<=m; i++)
    {
        for (j=m-i; j<=m-1; j++)
            s[j] -= xploy[i]*s[j+1];
        s[m] -= xploy[i];
    }
    for (j=0; j<=m; j++)
    {
        phi=m+1;
        for (k=m; k>=1; k--)
            phi=k*s[k]+xploy[j]*phi;
        ff=yploy[j]/phi;
        b=1.0;
        for (k=m; k>=0; k--)
        {
            cof[k] += b*ff;
            b=s[k]+xploy[j]*b;
        }
    }
    //for (i=m; i>=0; i--)
    //    qDebug()<<"cof["<<i<<"]="<<cof[i];
    //*Affichage des résultats*//
    id=buttonGroup_methodeApproximationPolynomiale->checkedId();
    switch (id) {
    case -2:
        outputtext+=tr("Les coefficients du polynôme de Lagrange sont :\n");
        break;
    case -3:
        outputtext+=tr("Les coefficients du polynôme de Newton sont :\n");
        break;
    }
    for (i=m; i>=0; i--){
        if (abs(cof[i])<numeric_limits<double>::epsilon()
                || cof[i]-(int)(cof[i]/
                                numeric_limits<double>::epsilon())*numeric_limits<double>::epsilon()==0) cof[i]=0; // pb mulitple de eps (fmod)c++ 21-7-2021
    }
    for(i=m; i>=0; i--){
        outputtext+="coef["+QString::number(m-i+1)+"]="+QString::number(cof[i])+"  ";
    }
    outputtext+="\n";
    outputtext+=tr("Le polynôme est : P")+QString::number(m)+"(x)=";
    for(i=m; i>=0; i--){
        if (cof[i]>0 && i!=m && !(cof[i+1]==0 && i!=0)) outputtext+="+";
        if (cof[i]!=0 && QString::number(cof[i])!="1" && QString::number(cof[i])!="-1"){
            if (i==0){
                outputtext+=QString::number(cof[i]);
            }else{
                if (i==1){
                    outputtext+=QString::number(cof[i])+"*x";
                }else{
                    outputtext+=QString::number(cof[i])+"*x^"+QString::number(i);
                }
            }
        }else{
            if (QString::number(cof[i])=="1") {
                if (i==0){
                    outputtext+=QString::number(cof[i]);
                }else{
                    if (i==1){
                        outputtext+="x";
                    }else{
                        outputtext+="x^"+QString::number(i);
                    }
                }
            }
            if (QString::number(cof[i])=="-1") {
                if (i==0){
                    outputtext+=QString::number(cof[i]);
                }else{
                    if (i==1){
                        outputtext+="-x";
                    }else{
                        outputtext+="-x^"+QString::number(i);
                    }
                }
            }
        }
    }

    ApproximationPolynomiale_textBrowser->setText(outputtext);

fin5:;

}
void basic_numerical_methods::hafcalculApproximationPolynomiale_Newton()
{
    hafcalculApproximationPolynomiale_Lagrange();
    /////
    n=tableWidget_donnees_ApproximationPolynomiale->rowCount();
    //   resize_tableWidget_donnees_ApproximationPolynomiale(spinBox_nbre_pts_ApproximationPolynomiale->value());
    for(i=0;i<n;i++)
    {
        f[i][0]=yploy[i];

    }
    for(i=1;i<n;i++)
    {
        for( j = 1;j<=n;++j){
            f[i][j]= (f[i][j-1]-f[i-1][j-1])/(xploy[i]-xploy[i-j]);
            //qDebug() << "f["<< i<< "]["<< j<< "]=" << f[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for( j = 2;j<=n;++j){
            if (i>=j-1){
                tableWidget_donnees_ApproximationPolynomiale->setItem(i,j,new QTableWidgetItem(QString::number(f[i][j-1])));
                if (j==i+1)  tableWidget_donnees_ApproximationPolynomiale->item(i,j)->setBackground(Qt::red);
            }
        }
    }
    tableWidget_donnees_ApproximationPolynomiale->item(0,1)->setBackground(Qt::red);
    tableWidget_donnees_ApproximationPolynomiale->resizeColumnsToContents();
}
void basic_numerical_methods::resize_tableWidget_donnees_ApproximationPolynomiale(int n)
{
    headtextH_ApproximationPolynomiale.clear();
    ApproximationPolynomiale_textBrowser->clear();
    tableWidget_donnees_ApproximationPolynomiale->setStyleSheet("QTableView {selection-background-color: green;}");
    headtextV_ApproximationPolynomiale.clear();

    for (i =0 ; i<n ; i++){
        headtextV_ApproximationPolynomiale+="Point("+ QString::number(i)+")";
    }

    tableWidget_donnees_ApproximationPolynomiale->setRowCount(n);
    tableWidget_donnees_ApproximationPolynomiale->setVerticalHeaderLabels(headtextV_ApproximationPolynomiale);
    tableWidget_donnees_ApproximationPolynomiale->resizeColumnsToContents();

    headtextH_ApproximationPolynomiale+="x(i)";
    headtextH_ApproximationPolynomiale+="y(i)";
    id=buttonGroup_methodeApproximationPolynomiale->checkedId();
    switch (id) {
    case -2:
        /////
        tableWidget_donnees_ApproximationPolynomiale->setColumnCount(2);
        tableWidget_donnees_ApproximationPolynomiale->item(0, 1)->setForeground(fgBrush);
        tableWidget_donnees_ApproximationPolynomiale->item(0, 1)->setBackground(bgBrush);
        break;
    case -3:
        tableWidget_donnees_ApproximationPolynomiale->setColumnCount(n+1);
        /////
        for(i=2;i<=n;i++)
        {
            QString temp="f[";
            for(j=0;j<i;j++)
            {
                if (j!=i-1){
                    temp+="x"+QString::number(j)+",";
                }else{
                    temp+="x"+QString::number(j);
                }
            }
            temp+="]";
            headtextH_ApproximationPolynomiale+=temp;
        }
        tableWidget_donnees_ApproximationPolynomiale->setHorizontalHeaderLabels(headtextH_ApproximationPolynomiale);

        /////
        break;
    }
    tableWidget_donnees_ApproximationPolynomiale->resizeColumnsToContents();
}
/////---------------------
void basic_numerical_methods::on_PushButonClicked(){
    n=tableWidget_donnees_SysteqtsLineaires->rowCount();
    //    tableWidget_matrice_triangulaire_sup->verticalHeader()->moveSection(n-1, n-2);
    k=indexRowPivotNul;
    //qDebug() << "k=" << k;
    //qDebug() << "indexRowDownPivotNul=" << indexRowDownPivotNul;
    tableWidget_donnees_SysteqtsLineaires->clear();
    //if (indexRowDownPivotNul==n-1 && k!=0) indexRowDownPivotNul-=1;
    //qDebug() << "indexRowDownPivotNul=" << indexRowDownPivotNul;
    for(i = 0;i<n;++i){
        if (i==k){
            for( j = 0;j<=n;++j){
                QTableWidgetItem* item = tableWidget_matrice_triangulaire_sup->item(k,j);
                if (item && !item->text().isEmpty()) /* the cell is not empty */
                {
                    tableWidget_matrice_triangulaire_sup->takeItem(k,j);
                    tableWidget_donnees_SysteqtsLineaires->setItem(indexRowDownPivotNul,j,item);
                }
            }

            for( j = 0;j<=n;++j){
                QTableWidgetItem* item = tableWidget_matrice_triangulaire_sup->item(indexRowDownPivotNul,j);
                if (item && !item->text().isEmpty()) /* the cell is not empty */
                {
                    tableWidget_matrice_triangulaire_sup->takeItem(indexRowDownPivotNul,j);
                    tableWidget_donnees_SysteqtsLineaires->setItem(k,j,item);
                }
            }
            i=i+1;
        }

        for(j = 0;j<=n;++j){
            QTableWidgetItem* item = tableWidget_matrice_triangulaire_sup->item(i,j);
            if (item && !item->text().isEmpty()) /* the cell is not empty */
            {
                tableWidget_matrice_triangulaire_sup->takeItem(i,j);
                tableWidget_donnees_SysteqtsLineaires->setItem(i,j,item);
            }
        }

    }
    tableWidget_donnees_SysteqtsLineaires->resizeColumnsToContents();
    hafresolutionsysteqtlineaire_Gauss();
    for(i=0;i<n;i++)
    {for(j=0;j<=n;j++){
            tableWidget_donnees_SysteqtsLineaires->setItem(i,j,new QTableWidgetItem(QString::number(aold[i][j])));
        }
    }
}
void basic_numerical_methods::hafresolutionsysteqtlineaire_Jacobi()
{
    outputtext="";
    SysteqtsLineaires_textBrowser->clear();
    okToleranceReache_GaussSeidel=false;
    double a[10][10], b[10], m[10], x[10]={0}, e[10]={0}, xold[10]={0};
    int q;
    // cout << "Enter size of 2D array : ";
    // cin >> p;
    headtextH_SystEqtLineares_Gauss_Seidel.clear();
    headtextV_SystEqtLineares_Gauss_Seidel.clear();
    n=tableWidget_donnees_SysteqtsLineaires->rowCount();
    tableWidget_Resultats_Gauss_Seidel->setColumnCount(n+1);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,j);
            if (!item || item->text().isEmpty()) /* the cell is not empty */
            {
                SysteqtsLineaires_textBrowser->clear();
                resultatsMessage.warning(this, tr("Erreur données"),
                                         tr("Veuillez remplir complètement le tableau! A.X=b"));
                tableWidget_matrice_triangulaire_sup->clearContents();
                goto fin4;
            }
            else /* the cell is empty */
            {
                a[i][j]=tableWidget_donnees_SysteqtsLineaires->item(i,j)->text().toFloat();
            }
        }
    }
    //    cout << "\nEnter values to the right side of equation\n";
    for (i = 0; i < n; i++) {
        QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,n);
        if (!item || item->text().isEmpty()) /* the cell is not empty */
        {
            SysteqtsLineaires_textBrowser->clear();
            resultatsMessage.warning(this, tr("Erreur données"),
                                     tr("Veuillez remplir complètement le tableau! A.X=b"));
            goto fin4;
        }
        else /* the cell is empty */
        {
            b[i]=tableWidget_donnees_SysteqtsLineaires->item(i,n)->text().toFloat();
        }
    }
    //cout << "Enter initial values of x\n";
    for (i = 0; i < n; i++) {
        QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,n+1);
        if (!item || item->text().isEmpty()) /* the cell is not empty */
        {
            SysteqtsLineaires_textBrowser->clear();
            resultatsMessage.warning(this, tr("Erreur données"),
                                     tr("Veuillez remplir complètement le tableau! A.X=b"));
            goto fin4;
        }
        else /* the cell is empty */
        {
            m[i]=tableWidget_donnees_SysteqtsLineaires->item(i,n+1)->text().toFloat();
        }
    }
    for (i = 0; i < n; i++) {
        headtextH_SystEqtLineares_Gauss_Seidel+="x("+ QString::number(i+1)+")";
        tableWidget_Resultats_Gauss_Seidel->setItem(0,i,new QTableWidgetItem(QString::number(m[i])));
    }
    headtextH_SystEqtLineares_Gauss_Seidel+="MaxErreur";
    //cout << "\nEnter the no. of iteration : ";
    outputtext=tr("La solution du système par la méthode de Jacobi est :\n");

    q=spinBox_nbre_itera->value();
    iter=0;
    for (i = 0; i < n; i++) {
        xold[i]=m[i];
    }
    double S;
    while (q > 0 ) {
        progressBar_SysteqtsLineaires->setValue(iter);
        iter=iter+1;
        tableWidget_Resultats_Gauss_Seidel->setRowCount(iter+1);
        for (i = 0; i < n; i++) {
            S=0;
            for (j = 0; j < n; j++) {
                if (j == i)
                    continue;
                S+=a[i][j] * xold[j];
            }
            x[i] = (b[i] - S)/a[i][i] ;
        }
        for (i = 0; i < n; i++) {
            e[i]=fabs(x[i]-xold[i]);
            xold[i]=x[i];
        }
        Maxe=e[0];
        for(i = 0; i < n; i++)
        {
            if(e[i]>Maxe){
                Maxe=e[i];
            }
        }

        for (i = 0; i < n; i++) {
            tableWidget_Resultats_Gauss_Seidel->setItem(iter,i,new QTableWidgetItem(QString::number(x[i])));
        }

        headtextV_SystEqtLineares_Gauss_Seidel+="Itér("+ QString::number(iter-1)+")";
        tableWidget_Resultats_Gauss_Seidel->setItem(iter,n,new QTableWidgetItem(QString::number(Maxe)));

        if (Maxe<lineEdit_tolerance_SystEqtLineares->text().toFloat()){
            okToleranceReache_GaussSeidel=true;
            break;
        }else{
            q--;
        }
    }
    //*Affichage des résultats*//
    headtextV_SystEqtLineares_Gauss_Seidel+="Itér("+ QString::number(iter)+")";
    tableWidget_Resultats_Gauss_Seidel->setHorizontalHeaderLabels(headtextH_SystEqtLineares_Gauss_Seidel);
    tableWidget_Resultats_Gauss_Seidel->setVerticalHeaderLabels(headtextV_SystEqtLineares_Gauss_Seidel);
    tableWidget_Resultats_Gauss_Seidel->resizeColumnsToContents();

    if (okToleranceReache_GaussSeidel && !std::isnan(Maxe)){
        resultatsMessage.information(this, tr("Résultats"),
                                     tr("La condition de tolérance est bien respectée aprés ")+
                                     QString::number(iter,'i',0)+ tr(" itérations!"));
        for (i = 0; i < n; i++) {
            outputtext+="x"+QString::number(i+1)+"="+QString::number(x[i])+"   ";
        }
        outputtext+=tr("\naprès ")+QString::number(iter,'i',0)+ tr(" itérations!");
        SysteqtsLineaires_textBrowser->setText(outputtext);
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Vérifier la condition de convergence de la méthode "
                                    "ou augmenter le nombre maximal d'itérations!."));
    }
    for (i = 0; i < n; i++) {
        tableWidget_Resultats_Gauss_Seidel->item(iter,i)->setBackground(Qt::red);
    }
    tableWidget_Resultats_Gauss_Seidel->setCurrentCell(iter, n);
    progressBar_SysteqtsLineaires->setValue(spinBox_nbre_itera->value());
fin4:;
}
void basic_numerical_methods::hafresolutionsysteqtlineaire_Gauss_Seidel()
{
    outputtext="";
    SysteqtsLineaires_textBrowser->clear();
    okToleranceReache_GaussSeidel=false;
    double a[10][10], b[10], m[10], x[10]={0}, e[10]={0}, xold[10]={0};
    int q;
    // cout << "Enter size of 2D array : ";
    // cin >> p;
    headtextH_SystEqtLineares_Gauss_Seidel.clear();
    headtextV_SystEqtLineares_Gauss_Seidel.clear();
    n=tableWidget_donnees_SysteqtsLineaires->rowCount();
    tableWidget_Resultats_Gauss_Seidel->setColumnCount(n+1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,j);
            if (!item || item->text().isEmpty()) /* the cell is not empty */
            {
                SysteqtsLineaires_textBrowser->clear();
                resultatsMessage.warning(this, tr("Erreur données"),
                                         tr("Veuillez remplir complètement le tableau! A.X=b"));
                tableWidget_matrice_triangulaire_sup->clearContents();
                goto fin3;
            }
            else /* the cell is empty */
            {
                a[i][j]=tableWidget_donnees_SysteqtsLineaires->item(i,j)->text().toFloat();
            }
        }
    }
    //    cout << "\nEnter values to the right side of equation\n";
    for (i = 0; i < n; i++) {
        QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,n);
        if (!item || item->text().isEmpty()) /* the cell is not empty */
        {
            SysteqtsLineaires_textBrowser->clear();
            resultatsMessage.warning(this, tr("Erreur données"),
                                     tr("Veuillez remplir complètement le tableau! A.X=b"));
            goto fin3;
        }
        else /* the cell is empty */
        {
            b[i]=tableWidget_donnees_SysteqtsLineaires->item(i,n)->text().toFloat();
        }
    }
    //cout << "Enter initial values of x\n";
    for (i = 0; i < n; i++) {
        QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,n+1);
        if (!item || item->text().isEmpty()) /* the cell is not empty */
        {
            SysteqtsLineaires_textBrowser->clear();
            resultatsMessage.warning(this, tr("Erreur données"),
                                     tr("Veuillez remplir complètement le tableau! A.X=b"));
            goto fin3;
        }
        else /* the cell is empty */
        {
            m[i]=tableWidget_donnees_SysteqtsLineaires->item(i,n+1)->text().toFloat();
        }
    }
    for (i = 0; i < n; i++) {
        headtextH_SystEqtLineares_Gauss_Seidel+="x("+ QString::number(i+1)+")";
        tableWidget_Resultats_Gauss_Seidel->setItem(0,i,new QTableWidgetItem(QString::number(m[i])));
    }
    headtextH_SystEqtLineares_Gauss_Seidel+="MaxErreur";
    //cout << "\nEnter the no. of iteration : ";
    outputtext=tr("La solution du système par la méthode de Gauss-Seidel est :\n");

    q=spinBox_nbre_itera->value();
    iter=0;
    for (i = 0; i < n; i++) {
        xold[i]=m[i];
    }
    double S;
    while (q > 0 ) {
        progressBar_SysteqtsLineaires->setValue(iter);
        iter=iter+1;
        tableWidget_Resultats_Gauss_Seidel->setRowCount(iter+1);

        for (i = 0; i < n; i++) {
            S=0;
            for (j = 0; j < n; j++) {
                if (j < i)
                    S+=a[i][j] * x[j];
                if (j > i)
                    S+=a[i][j] * xold[j];
            }
            x[i] = (b[i] - S)/a[i][i] ;
        }

        for (i = 0; i < n; i++) {
            e[i]=fabs(x[i]-xold[i]);
            xold[i]=x[i];
        }
        Maxe=e[0];
        for(i = 0; i < n; i++)
        {
            if(e[i]>Maxe){
                Maxe=e[i];
            }
        }

        for (i = 0; i < n; i++) {
            tableWidget_Resultats_Gauss_Seidel->setItem(iter,i,new QTableWidgetItem(QString::number(x[i])));
        }
        headtextV_SystEqtLineares_Gauss_Seidel+=tr("Itér(")+ QString::number(iter-1)+")";
        tableWidget_Resultats_Gauss_Seidel->setItem(iter,n,new QTableWidgetItem(QString::number(Maxe)));

        if (Maxe<lineEdit_tolerance_SystEqtLineares->text().toFloat()){
            okToleranceReache_GaussSeidel=true;
            break;
        }else{
            q--;
        }
    }
    //*Affichage des résultats*//
    headtextV_SystEqtLineares_Gauss_Seidel+=tr("Itér(")+ QString::number(iter)+")";

    tableWidget_Resultats_Gauss_Seidel->setHorizontalHeaderLabels(headtextH_SystEqtLineares_Gauss_Seidel);
    tableWidget_Resultats_Gauss_Seidel->setVerticalHeaderLabels(headtextV_SystEqtLineares_Gauss_Seidel);
    tableWidget_Resultats_Gauss_Seidel->resizeColumnsToContents();

    if (okToleranceReache_GaussSeidel && !std::isnan(Maxe)){
        resultatsMessage.information(this, tr("Résultats"),
                                     tr("La condition de tolérance est bien respectée aprés ")+
                                     QString::number(iter,'i',0)+ tr(" itérations!"));
        for (i = 0; i < n; i++) {
            outputtext+="x"+QString::number(i+1)+"="+QString::number(x[i])+"   ";
        }
        outputtext+=tr("\naprès ")+QString::number(iter,'i',0)+ tr(" itérations!");
        SysteqtsLineaires_textBrowser->setText(outputtext);
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Vérifier la condition de convergence de la méthode "
                                    "ou augmenter le nombre maximal d'itérations!."));
    }
    for (i = 0; i < n; i++) {
        tableWidget_Resultats_Gauss_Seidel->item(iter,i)->setBackground(Qt::red);
    }
    tableWidget_Resultats_Gauss_Seidel->setCurrentCell(iter, n);
    progressBar_SysteqtsLineaires->setValue(spinBox_nbre_itera->value());
fin3:;
}
void basic_numerical_methods::hafresolutionSystEqtLineares()
{
    progressBar_SysteqtsLineaires->setMaximum(spinBox_nbre_itera->value());
    progressBar_SysteqtsLineaires->setValue(0);
    id=buttonGroup_methodeSystEqtLineares->checkedId();
    switch (id) {
    case -2:
        n=tableWidget_donnees_SysteqtsLineaires->rowCount();
        resize_tableWidget_donnees_SysteqtsLineaires(spinBox_nbre_eqts->value());
        for(i=0;i<n;i++)
        {
            for(j=0;j<=n;j++)
            {
                QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,j);
                if (!item || item->text().isEmpty()) /* the cell is not empty */
                {
                    SysteqtsLineaires_textBrowser->clear();
                    resultatsMessage.warning(this, tr("Erreur données"),
                                             tr("Veuillez remplir complètement le tableau! A.X=b"));
                    tableWidget_matrice_triangulaire_sup->clearContents();
                    goto finGauss;
                }
                else /* the cell is empty */
                {
                    aold[i][j]=tableWidget_donnees_SysteqtsLineaires->item(i,j)->text().toFloat();
                }
            }
        }
        hafresolutionsysteqtlineaire_Gauss();
        stackedWidget_choixmethodeSystEqtLineares->setCurrentIndex(0);
finGauss:;
        break;

    case -3:
        hafresolutionsysteqtlineaire_Gauss_Seidel();
        stackedWidget_choixmethodeSystEqtLineares->setCurrentIndex(3);
        break;

    case -4:
        hafresolutionsysteqtlineaire_Jacobi();
        stackedWidget_choixmethodeSystEqtLineares->setCurrentIndex(3);
        break;
    }
}
void basic_numerical_methods::choixmethodeSystEqtLineares(int id)
{
    pushButton_Calculer_methodeSystEqtLineares->show();
    pushButton_mouveRow->hide();
    n=spinBox_nbre_eqts->value();
    resize_tableWidget_donnees_SysteqtsLineaires(n);
    switch (id) {
    case -2:
        tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+1);
        stackedWidget_choixmethodeSystEqtLineares->setCurrentIndex(1);
        groupBox_tolerance_methodeSystEqtLineares->hide();
        groupBox_nbreItera->hide();
        progressBar_SysteqtsLineaires->hide();
        break;

    case -3:
        tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+2);
        stackedWidget_choixmethodeSystEqtLineares->setCurrentIndex(2);
        groupBox_tolerance_methodeSystEqtLineares->show();
        groupBox_nbreItera->show();
        progressBar_SysteqtsLineaires->show();
        break;

    case -4:
        tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+2);
        stackedWidget_choixmethodeSystEqtLineares->setCurrentIndex(4);
        groupBox_tolerance_methodeSystEqtLineares->show();
        groupBox_nbreItera->show();
        progressBar_SysteqtsLineaires->show();
        break;

    }
}
void basic_numerical_methods::hafresolutionsysteqtlineaire_Gauss()
{
    pushButton_mouveRow->hide();
    outputtext="";
    SysteqtsLineaires_textBrowser->clear();

    double a[10][10],c,x[10]={0};
    n=tableWidget_donnees_SysteqtsLineaires->rowCount();
    resize_tableWidget_donnees_SysteqtsLineaires(spinBox_nbre_eqts->value());
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,j);
            if (!item || item->text().isEmpty()) /* the cell is not empty */
            {
                SysteqtsLineaires_textBrowser->clear();
                resultatsMessage.warning(this, tr("Erreur données"),
                                         tr("Veuillez remplir complètement le tableau! A.X=b"));
                tableWidget_matrice_triangulaire_sup->clearContents();
                goto fin2;
            }
            else /* the cell is empty */
            {
                a[i][j]=tableWidget_donnees_SysteqtsLineaires->item(i,j)->text().toFloat();
            }
        }
    }
    //Transformation en matrice triangulaire supérieure//
    //*Processus d'élimination avant*//
    for(k=0;k<n-1;k++)for(i=k+1;i<=n-1;i++)
    {
        if(a[k][k]==0) {
            SysteqtsLineaires_textBrowser->clear();
            for( j = 0;j<=n;++j){
                tableWidget_matrice_triangulaire_sup->setItem(0,j,new QTableWidgetItem(QString::number(a[0][j])));
            }
            indexRowPivotNul=k;
            if (indexRowPivotNul==0){
                for(i = 0;i<n;++i){
                    for( j = 0;j<=n;++j){
                        QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,j);
                        if (item && !item->text().isEmpty()) /* the cell is not empty */
                        {
                            tableWidget_donnees_SysteqtsLineaires->takeItem(i,j);
                            tableWidget_matrice_triangulaire_sup->setItem(i,j,item);
                        }
                        tableWidget_donnees_SysteqtsLineaires->setItem(i,j,new QTableWidgetItem(QString::number(a[i][j])));
                    }
                }
            }
            resultatsMessage.critical(this, tr("Erreur!"),
                                      tr("Pivot nul! Essayer de permuter les lignes en cliquant sur le bouton de dessous."));
            pushButton_mouveRow->show();
            pushButton_Calculer_methodeSystEqtLineares->hide();
            goto fin2;
        }
        c=(a[i][k]/a[k][k]) ;
        for(j=k;j<=n;j++){
            a[i][j]-=c*a[k][j];
            tableWidget_matrice_triangulaire_sup->setItem(i,j,new QTableWidgetItem(QString::number(a[i][j])));
            if (j<i) {
                //if (QString::number(a[i][j]) == "1.77636e-15")  a[i][j]=0; // pb dans Manjaro (Qt5.15.2) et Win10 (Qt6.2.0)
                if (abs(a[i][j])<numeric_limits<double>::epsilon()
                        || a[i][j]-(int)(a[i][j]/
                                         numeric_limits<double>::epsilon())*numeric_limits<double>::epsilon()==0) a[i][j]=0;// pb mulitple de eps (fmod)c++ 21-7-2021
                tableWidget_matrice_triangulaire_sup->item(i,j)->setBackground(Qt::red);
            }
        }
    }
    //*Matrice triangulaire supérieure*//
    for(i=0;i<n;i++)
    {for(j=0;j<=n;j++){
            tableWidget_matrice_triangulaire_sup->setItem(i,j,new QTableWidgetItem(QString::number(a[i][j])));
            if (j<i)  tableWidget_matrice_triangulaire_sup->item(i,j)->setBackground(Qt::red);
            //printf("%6.1f",a[i][j]);
        }
    }
    //*Substitution arrière*//
    //a[n-1][n] est b(n)
    if(a[n-1][n-1]==0) {
        SysteqtsLineaires_textBrowser->clear();
        //tableWidget_matrice_triangulaire_sup->clearContents();
        resultatsMessage.critical(this, tr("Erreur!"),
                                  tr("Pivot nul! Essayer de permuter les lignes en cliquant sur le bouton de dessous."));
        pushButton_mouveRow->show();
        pushButton_Calculer_methodeSystEqtLineares->hide();
        goto fin2;
    }
    x[n-1]=a[n-1][n]/a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {c=0;for(j=i;j<=n-1;j++){
            c=c+a[i][j]*x[j];}
        x[i]=(a[i][n]-c)/a[i][i];}
    //*Affichage des résultats*//
    outputtext+=tr("La solution du système par la méthode du pivot de Gauss est :\n");
    for(i=0;i<n;i++){
        outputtext+="x"+QString::number(i+1)+"="+QString::number(x[i])+"   ";
    }

    SysteqtsLineaires_textBrowser->setText(outputtext);

    tableWidget_matrice_triangulaire_sup->resizeColumnsToContents();
    for(i=0;i<n;i++)
    {for(j=0;j<=n;j++){
            tableWidget_donnees_SysteqtsLineaires->item(i, j)->setForeground(fgBrush);
            tableWidget_donnees_SysteqtsLineaires->item(i, j)->setBackground(bgBrush);
        }
    }

    pushButton_Calculer_methodeSystEqtLineares->show();
    pushButton_mouveRow->hide();
fin2:;
    for(i = 0;i<n;++i){
        okpermutationrow="fase";
        if (a[i][k]!=0 && i>k){
            indexRowDownPivotNul=i;
            //qDebug() << "indexRowDownPivotNul=" << indexRowDownPivotNul;
            okpermutationrow="true";
            return;
        }
    }

}
void basic_numerical_methods::resize_tableWidget_donnees_SysteqtsLineaires(int n)
{
    tableWidget_matrice_triangulaire_sup->clear();
    SysteqtsLineaires_textBrowser->clear();
    pushButton_Calculer_methodeSystEqtLineares->show();
    pushButton_mouveRow->hide();
    tableWidget_donnees_SysteqtsLineaires->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_matrice_triangulaire_sup->setStyleSheet("QTableView {selection-background-color: green;}");

    tableWidget_matrice_triangulaire_sup->setRowCount(n);
    tableWidget_matrice_triangulaire_sup->setColumnCount(n+1);
    headtextH_SystEqtLineares.clear();
    headtextV_SystEqtLineares.clear();

    for (i = 1 ; i <=n ; i++){
        headtextH_SystEqtLineares+="a(i,"+ QString::number(i)+")";
    }
    /////
    for(i=0;i<=n;i++)
    {
        QTableWidgetItem* item = tableWidget_donnees_SysteqtsLineaires->item(i,n+1);
        if (item && !item->text().isEmpty()) /* the cell is not empty */
        {
            X0[i]=tableWidget_donnees_SysteqtsLineaires->item(i,n+1)->text().toFloat();
            //SysteqtsLineaires_textBrowser->setText(QString::number(X0[i]));
        }
    }
    /////
    tableWidget_donnees_SysteqtsLineaires->setRowCount(n);
    tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+1);
    id=buttonGroup_methodeSystEqtLineares->checkedId();
    switch (id) {
    case -2:
        /////
        tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+1);
        /////
        headtextH_SystEqtLineares+="b(i)";
        break;
    case -3:
        tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+2);
        headtextH_SystEqtLineares+="b(i)";
        headtextH_SystEqtLineares+="X0(i)";
        /////
        for(i=0;i<=n;i++)
        {
            tableWidget_donnees_SysteqtsLineaires->setItem(i,n+1,new QTableWidgetItem(QString::number(X0[i])));
        }
        /////
        break;
    case -4:
        tableWidget_donnees_SysteqtsLineaires->setColumnCount(n+2);
        headtextH_SystEqtLineares+="b(i)";
        headtextH_SystEqtLineares+="X0(i)";
        /////
        for(i=0;i<=n;i++)
        {
            tableWidget_donnees_SysteqtsLineaires->setItem(i,n+1,new QTableWidgetItem(QString::number(X0[i])));
        }
        /////
        break;
    }

    for (i = 1 ; i <=n ; i++){
        headtextV_SystEqtLineares+="a("+ QString::number(i)+",j)";
    }

    tableWidget_donnees_SysteqtsLineaires->setHorizontalHeaderLabels(headtextH_SystEqtLineares);
    tableWidget_donnees_SysteqtsLineaires->setVerticalHeaderLabels(headtextV_SystEqtLineares);
    tableWidget_donnees_SysteqtsLineaires->resizeColumnsToContents();

    tableWidget_matrice_triangulaire_sup->setHorizontalHeaderLabels(headtextH_SystEqtLineares);
    tableWidget_matrice_triangulaire_sup->setVerticalHeaderLabels(headtextV_SystEqtLineares);
    tableWidget_matrice_triangulaire_sup->resizeColumnsToContents();
}
////////////////
void basic_numerical_methods::textChangedin_Diametre()
{
    fprime=lineEdit_Diametre->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_Diametre->setPalette(palette);
        validDiametre=false;
    }
    else
    {
        validDiametre=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_Diametre->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_Ruguosite()
{
    fprime=lineEdit_Ruguosite->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_Ruguosite->setPalette(palette);
        validRuguosite=false;
    }
    else
    {
        validRuguosite=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_Ruguosite->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_Debit()//
{
    fprime=lineEdit_Debit->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_Debit->setPalette(palette);
        validDebit=false;
    }
    else
    {
        validDebit=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_Debit->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_a_tracage()
{
    fprime=lineEdit_a_tracage_fx->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_a_tracage_fx->setPalette(palette);
        valida_tracage=false;
    }
    else
    {
        valida_tracage=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_a_tracage_fx->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_b_tracage()
{
    fprime=lineEdit_b_tracage_fx->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_b_tracage_fx->setPalette(palette);
        validb_tracage=false;
    }
    else
    {
        validb_tracage=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_b_tracage_fx->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_dx_tracage()
{
    fprime=lineEdit_dx_tracage_fx->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_dx_tracage_fx->setPalette(palette);
        validdx_tracage=false;
    }
    else
    {
        validdx_tracage=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_dx_tracage_fx->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinfx_tracage()
{
    fx=lineEdit_tracage_fx->text();
    int res = fparserfx.Parse(fx.toStdString(), "x");

    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_tracage_fx->setPalette(palette);
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_tracage_fx->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_a_integ()
{
    fprime=lineEdit_a->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_a->setPalette(palette);
        valida_integ=false;
    }
    else
    {
        valida_integ=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_a->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_b_integ()
{
    fprime=lineEdit_b->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_b->setPalette(palette);
        validb_integ=false;
    }
    else
    {
        validb_integ=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_b->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinfx_integ()
{
    fx=lineEdit_fx_integ->text();
    int res = fparserfx.Parse(fx.toStdString(), "x");

    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_fx_integ->setPalette(palette);
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_fx_integ->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_y0_methodeeqtdifferentielle()
{
    fprime=lineEdit_y0_methodeeqtdifferentielle->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_y0_methodeeqtdifferentielle->setPalette(palette);
        validy0_eqtdifferentielle=false;
    }
    else
    {
        validy0_eqtdifferentielle=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_y0_methodeeqtdifferentielle->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_b_methodeeqtdifferentielle()
{
    fprime=lineEdit_b_methodeeqtdifferentielle->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_b_methodeeqtdifferentielle->setPalette(palette);
        validb_eqtdifferentielle=false;
    }
    else
    {
        validb_eqtdifferentielle=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_b_methodeeqtdifferentielle->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedin_a_methodeeqtdifferentielle()
{
    fprime=lineEdit_a_methodeeqtdifferentielle->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_a_methodeeqtdifferentielle->setPalette(palette);
        valida_eqtdifferentielle=false;
    }
    else
    {
        valida_eqtdifferentielle=true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_a_methodeeqtdifferentielle->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinfunctionyprim()
{
    yprim=lineEdit_yprime_methodeeqtdifferentielle->text();
    fparseryprim.AddConstant("pi", M_PI);
    int res = fparseryprim.Parse(yprim.toStdString(), "x,y");

    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_yprime_methodeeqtdifferentielle->setPalette(palette);
    }
    else
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_yprime_methodeeqtdifferentielle->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::EvalErrorfunHAF(int fparser_EvalError, QString fx, double x,int ndecimaux)
{
    QString message;
    if (fparser_EvalError!=0){
        switch (fparser_EvalError) {
        case 1:
            message=tr("division par zéro");
            break;
        case 2:
            message=tr("erreur sqrt (sqrt d'une valeur négative)");
            break;
        case 3:
            message=tr("erreur log (logarithme d'une valeur négative)");
            break;
        case 4:
            message=tr("erreur trigonométrique (asin ou acos d'une valeur incorrecte ; non comprise entre -1 et 1)");
            break;
        case 5:
            message=tr("niveau de récursivité maximum dans eval() atteint");
            break;
        }
        //ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
        message+=tr(" dans x=")+QString::number(x,'f',ndecimaux);
        resultatsMessage.critical(this, tr("Erreur dans ")+ QString("%1").arg(fx),message);
        return;
    }
}
void basic_numerical_methods::textChangedinfunctionfx()
{
    fx=lineEdit_fx_eqt_non_lineaire->text();
    fparserfx.AddConstant("pi", M_PI);
    int res = fparserfx.Parse(fx.toStdString(), "x");

    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_fx_eqt_non_lineaire->setPalette(palette);
        validfx = false;
    }
    else
    {
        validfx = true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_fx_eqt_non_lineaire->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinfunctiongx()
{
    gx=lineEdit_gx_eqt_non_lineaire->text();
    fparsergx.AddConstant("pi", M_PI);
    int res = fparsergx.Parse(gx.toStdString(), "x");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_gx_eqt_non_lineaire->setPalette(palette);
        validgx = false;
    }
    else
    {
        validgx = true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_gx_eqt_non_lineaire->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinfunctionfprime()
{
    fprime=lineEdit_fprime_eqt_non_lineaire->text();
    fparserfprime.AddConstant("pi", M_PI);
    int res = fparserfprime.Parse(fprime.toStdString(), "x");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_fprime_eqt_non_lineaire->setPalette(palette);
        validfprime = false;
    }
    else
    {
        validfprime = true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_fprime_eqt_non_lineaire->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinx0()
{
    fprime=lineEdit_x0->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_x0->setPalette(palette);
        validx0 = false;
    }
    else
    {
        validx0 = true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_x0->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedinx1()
{
    fprime=lineEdit_x1->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_x1->setPalette(palette);
        validx1 = false;
    }
    else
    {
        validx1 = true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_x1->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::textChangedintolerance()
{
    fprime=lineEdit_tolerance_eqtnonlineaire->text();
    int res = fparserfprime.Parse(fprime.toStdString(), "e");
    if(res > -1)
    {
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::red);
        lineEdit_tolerance_eqtnonlineaire->setPalette(palette);
        validtolerance = false;
    }
    else
    {
        validtolerance = true;
        QPalette palette;
        palette.setColor(QPalette::Text,Qt::black);
        lineEdit_tolerance_eqtnonlineaire->setPalette(QApplication::style()->standardPalette());
    }
}
void basic_numerical_methods::hafresolutioneqtdifferentielle_Kutta_Merson()
{
    progressBar_eqtdifferentielle->setValue(0);

    while(true)
    {
        yprim=lineEdit_yprime_methodeeqtdifferentielle->text();
        int res = fparseryprim.Parse(yprim.toStdString(), "x,y");
        if(res < 0) break;
        if (strlen(fparseryprim.ErrorMsg())!=0){
            resultatsMessage.critical(this, tr("Erreur dans f(x,y)"),
                                      fparseryprim.ErrorMsg());
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparseryprim.ErrorMsg() << "\n\n";
    }
    tableWidget_donnees_eqtdifferentielle->setRowCount(2);
    tableWidget_donnees_eqtdifferentielle->setColumnCount(3);
    nbrecolumn_tableWidget_donnees_eqtdifferentielle=3;
    tableWidget_donnees_eqtdifferentielle->clear();

    QStringList headtext={"i","x[i]","y[i]"};
    tableWidget_donnees_eqtdifferentielle->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtdifferentielle->setHorizontalHeaderLabels(headtext);
    double a=lineEdit_a_methodeeqtdifferentielle->text().toDouble();
    double b=lineEdit_b_methodeeqtdifferentielle->text().toDouble();
    ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
    n=spinBox_nptseqtdifferentielle->text().toInt();
    progressBar_eqtdifferentielle->setMaximum(n);
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
    x[0]=a;
    y[0]=lineEdit_y0_methodeeqtdifferentielle->text().toDouble();
    i=0;
    tableWidget_donnees_eqtdifferentielle->setItem(0,0,new QTableWidgetItem(QString::number(i)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,1,new QTableWidgetItem(QString::number(x[0],'f',ndecimaux)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,2,new QTableWidgetItem(QString::number(y[0],'f',ndecimaux)));

    double k1,k2,k3,k4,k5;
    for (i = 1 ; i <n ; i++){
        x[i]=x[0]+i*dx;
    }

    for (i=1; i<n; i++){
        progressBar_eqtdifferentielle->setValue(i);
        double variablesk1[2] = {x[i-1],y[i-1]};
        k1=1./3*dx*fparseryprim.Eval(variablesk1);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk2[2] = {x[i-1],y[i-1]+k1};
        k2=1./3*dx*fparseryprim.Eval(variablesk2);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk3[2] = {x[i-1],y[i-1]+k2/2+k2/2};
        k3=1./3*dx*fparseryprim.Eval(variablesk3);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk4[2] = {x[i-1],y[i-1]+3./8*k1+9./3*k3};
        k4=1./3*dx*fparseryprim.Eval(variablesk4);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk5[2] = {x[i-1],y[i-1]+3./2*k1-9./2*k3+6*k4};
        k5=1./3*dx*fparseryprim.Eval(variablesk5);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        error_truncation[i]=0.2*k1-0.9*k3+0.8*k4-0.1*k5;
        y[i]=y[i-1]+1/2.*(k1+4*k4+k5);
        tableWidget_donnees_eqtdifferentielle->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        tableWidget_donnees_eqtdifferentielle->setItem(i,1,new QTableWidgetItem(QString::number(x[i],'f',ndecimaux)));
        tableWidget_donnees_eqtdifferentielle->setItem(i,2,new QTableWidgetItem(QString::number(y[i],'f',ndecimaux)));
        tableWidget_donnees_eqtdifferentielle->setRowCount(i+2);
    }
    tableWidget_donnees_eqtdifferentielle->resizeColumnsToContents();
    tableWidget_donnees_eqtdifferentielle->verticalHeader()->hide();
    progressBar_eqtdifferentielle->setValue(n);
    nbrerow_tableWidget_donnees_eqtdifferentielle=i-1;
    pushButton_Copier_Tableaueqtdifferentielle->show();
}
void basic_numerical_methods::hafresolutioneqtdifferentielle_Runge_Kutta()
{
    progressBar_eqtdifferentielle->setValue(0);

    while(true)
    {
        yprim=lineEdit_yprime_methodeeqtdifferentielle->text();
        int res = fparseryprim.Parse(yprim.toStdString(), "x,y");
        if(res < 0) break;
        if (strlen(fparseryprim.ErrorMsg())!=0){
            resultatsMessage.critical(this, tr("Erreur dans f(x,y)"),
                                      fparseryprim.ErrorMsg());
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparseryprim.ErrorMsg() << "\n\n";
    }
    tableWidget_donnees_eqtdifferentielle->setRowCount(2);
    tableWidget_donnees_eqtdifferentielle->setColumnCount(3);
    nbrecolumn_tableWidget_donnees_eqtdifferentielle=3;
    tableWidget_donnees_eqtdifferentielle->clear();

    QStringList headtext={"i","x[i]","y[i]"};
    tableWidget_donnees_eqtdifferentielle->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtdifferentielle->setHorizontalHeaderLabels(headtext);
    double a=lineEdit_a_methodeeqtdifferentielle->text().toDouble();
    double b=lineEdit_b_methodeeqtdifferentielle->text().toDouble();
    ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
    n=spinBox_nptseqtdifferentielle->text().toInt();
    progressBar_eqtdifferentielle->setMaximum(n);
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
    x[0]=a;
    y[0]=lineEdit_y0_methodeeqtdifferentielle->text().toDouble();
    i=0;
    tableWidget_donnees_eqtdifferentielle->setItem(0,0,new QTableWidgetItem(QString::number(i)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,1,new QTableWidgetItem(QString::number(x[0],'f',ndecimaux)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,2,new QTableWidgetItem(QString::number(y[0],'f',ndecimaux)));

    double k1,k2,k3,k4;
    for (i = 1 ; i <n ; i++){
        x[i]=x[0]+i*dx;
    }
    for (i=1; i<n; i++){
        progressBar_eqtdifferentielle->setValue(i);
        double variablesk1[2] = {x[i-1],y[i-1]};
        k1=dx*fparseryprim.Eval(variablesk1);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        double variablesk2[2] = {x[i-1]+dx/2,y[i-1]+k1/2};
        k2=dx*fparseryprim.Eval(variablesk2);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]+dx/2,ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        double variablesk3[2] = {x[i-1]+dx/2,y[i-1]+k2/2};
        k3=dx*fparseryprim.Eval(variablesk3);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]+dx/2,ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        double variablesk4[2] = {x[i-1]+dx,y[i-1]+k3};
        k4=dx*fparseryprim.Eval(variablesk4);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]+dx,ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        y[i]=y[i-1]+1/6.*(k1+2*k2+2*k3+k4);
        tableWidget_donnees_eqtdifferentielle->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        tableWidget_donnees_eqtdifferentielle->setItem(i,1,new QTableWidgetItem(QString::number(x[i],'f',ndecimaux)));
        tableWidget_donnees_eqtdifferentielle->setItem(i,2,new QTableWidgetItem(QString::number(y[i],'f',ndecimaux)));
        tableWidget_donnees_eqtdifferentielle->setRowCount(i+2);
    }
    tableWidget_donnees_eqtdifferentielle->resizeColumnsToContents();
    tableWidget_donnees_eqtdifferentielle->verticalHeader()->hide();
    progressBar_eqtdifferentielle->setValue(n);
    nbrerow_tableWidget_donnees_eqtdifferentielle=i-1;
    pushButton_Copier_Tableaueqtdifferentielle->show();
}
void basic_numerical_methods::hafresolutioneqtdifferentielle_Euler_explicite()
{
    progressBar_eqtdifferentielle->setValue(0);
    while(true)
    {
        yprim=lineEdit_yprime_methodeeqtdifferentielle->text();
        int res = fparseryprim.Parse(yprim.toStdString(), "x,y");
        if(res < 0) break;
        if (strlen(fparseryprim.ErrorMsg())!=0){
            resultatsMessage.critical(this, tr("Erreur dans f(x,y)"),
                                      fparseryprim.ErrorMsg());
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparseryprim.ErrorMsg() << "\n\n";
    }
    tableWidget_donnees_eqtdifferentielle->setRowCount(2);
    tableWidget_donnees_eqtdifferentielle->setColumnCount(3);
    nbrecolumn_tableWidget_donnees_eqtdifferentielle=3;
    tableWidget_donnees_eqtdifferentielle->clear();

    QStringList headtext={"i","x[i]","y[i]"};
    tableWidget_donnees_eqtdifferentielle->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtdifferentielle->setHorizontalHeaderLabels(headtext);
    double a=lineEdit_a_methodeeqtdifferentielle->text().toDouble();
    double b=lineEdit_b_methodeeqtdifferentielle->text().toDouble();
    ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
    n=spinBox_nptseqtdifferentielle->text().toInt();
    progressBar_eqtdifferentielle->setMaximum(n);
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
    x[0]=a;
    y[0]=lineEdit_y0_methodeeqtdifferentielle->text().toDouble();
    i=0;
    tableWidget_donnees_eqtdifferentielle->setItem(0,0,new QTableWidgetItem(QString::number(i)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,1,new QTableWidgetItem(QString::number(x[0],'f',ndecimaux)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,2,new QTableWidgetItem(QString::number(y[0],'f',ndecimaux)));

    for (i = 1 ; i <n ; i++){
        x[i]=x[0]+i*dx;
    }
    for (i=1; i<n; i++){
        progressBar_eqtdifferentielle->setValue(i);
        double variables[] = {x[i-1],y[i-1]};
        y[i]=y[i-1]+dx*fparseryprim.Eval(variables);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1],ndecimaux);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        tableWidget_donnees_eqtdifferentielle->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        tableWidget_donnees_eqtdifferentielle->setItem(i,1,new QTableWidgetItem(QString::number(x[i],'f',ndecimaux)));
        tableWidget_donnees_eqtdifferentielle->setItem(i,2,new QTableWidgetItem(QString::number(y[i],'f',ndecimaux)));
        tableWidget_donnees_eqtdifferentielle->setRowCount(i+2);
    }
    tableWidget_donnees_eqtdifferentielle->resizeColumnsToContents();
    tableWidget_donnees_eqtdifferentielle->verticalHeader()->hide();
    progressBar_eqtdifferentielle->setValue(n);
    nbrerow_tableWidget_donnees_eqtdifferentielle=i-1;
    pushButton_Copier_Tableaueqtdifferentielle->show();
}
void basic_numerical_methods::changervaleurpas_eqtdifferentielle()
{
    tableWidget_donnees_eqtdifferentielle->clear();
    n=spinBox_nptseqtdifferentielle->text().toInt();
    double a=lineEdit_a_methodeeqtdifferentielle->text().toDouble();
    double b=lineEdit_b_methodeeqtdifferentielle->text().toDouble();
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
}
void basic_numerical_methods::copy_tableWidget_donnees_eqtdifferentielle()
{
    QString resultatsfr0="";
    for (j=0; j<nbrecolumn_tableWidget_donnees_eqtdifferentielle ;j++)
    {
        resultatsfr0+=tableWidget_donnees_eqtdifferentielle->horizontalHeaderItem(j)->text()+"\t";
    }
    resultatsfr0+="\n";
    for (i=0; i<=nbrerow_tableWidget_donnees_eqtdifferentielle ;i++)
    {
        for (j=0; j<nbrecolumn_tableWidget_donnees_eqtdifferentielle ;j++)
        {
            resultatsfr0+=tableWidget_donnees_eqtdifferentielle->item(i,j)->text()+"\t";
        }
        resultatsfr0+="\n";
    }
    pressePapiers->setText(resultatsfr0);
}
void basic_numerical_methods::hafresolutioneqtdifferentielle()
{
    fparseryprim_EvalError=0;
    stackedWidget_methodeeqtdifferentielle->setCurrentIndex(0);
    tableWidget_donnees_eqtdifferentielle->clear();
    pushButton_Copier_Tableaueqtdifferentielle->hide();
    id=buttonGroup_methodeeqtdifferentielle->checkedId();
    switch (id) {
    case -2:
        if (valida_eqtdifferentielle && validb_eqtdifferentielle && validy0_eqtdifferentielle){
            hafresolutioneqtdifferentielle_Euler_explicite();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez a ou/et b ou/et y0"));
        }
        break;

    case -3:
        if (valida_eqtdifferentielle && validb_eqtdifferentielle && validy0_eqtdifferentielle){
            hafresolutioneqtdifferentielle_Runge_Kutta();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez a ou/et b ou/et y0"));
        }
        break;

    case -4:
        if (valida_eqtdifferentielle && validb_eqtdifferentielle && validy0_eqtdifferentielle){
            hafresolutioneqtdifferentielle_Kutta_Merson();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez a ou/et b ou/et y0"));
        }
        break;
    }
}
void basic_numerical_methods::choixmethodeeqtdifferentielle(int id)
{
    progressBar_eqtdifferentielle->setValue(0);
    tableWidget_donnees_eqtdifferentielle->clear();
    pushButton_Copier_Tableaueqtdifferentielle->hide();
    switch (id) {
    case -2:
        stackedWidget_methodeeqtdifferentielle->setCurrentIndex(1);
        break;

    case -3:
        stackedWidget_methodeeqtdifferentielle->setCurrentIndex(2);
        break;

    case -4:
        stackedWidget_methodeeqtdifferentielle->setCurrentIndex(3);
        break;

    }
}
void basic_numerical_methods::choixmethodeeqtnonlineaire(int id)
{
    stackedWidget_nolineairEqt->setCurrentIndex(0);
    progressBar_eqtnonlineaire->setValue(0);
    tableWidget_donnees_eqtnonlineaire->clear();
    pushButton_Copier_TableauEqtNonLineaire->hide();
    switch (id) {
    case -2:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(0);
        stackedWidget_gx_fprime->show();
        stackedWidget_gx_fprime->setCurrentIndex(0);
        lineEdit_x1->hide();
        label_x1->hide();
        label_x0->setText("x0");
        lineEdit_tolerance_eqtnonlineaire->setToolTip(tr("f(xi)<=Tolérance"));
        break;

    case -3:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(1);
        stackedWidget_gx_fprime->show();
        stackedWidget_gx_fprime->setCurrentIndex(1);
        label_gx_fprimefx->show();
        lineEdit_gx_eqt_non_lineaire->show();
        lineEdit_x1->hide();
        label_x1->hide();
        label_x0->setText("x0");
        lineEdit_tolerance_eqtnonlineaire->setToolTip(tr("f(xi)<=Tolérance"));
        break;

    case -4:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(2);
        label_x0->setText("x0");
        label_x1->setText("x1");
        lineEdit_x1->show();
        label_x1->show();
        stackedWidget_gx_fprime->hide();
        lineEdit_tolerance_eqtnonlineaire->setToolTip(tr("f(xi)<=Tolérance"));
        break;

    case -5:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(3);
        lineEdit_x1->show();
        label_x1->show();
        label_x0->setText("a");
        label_x1->setText("b");
        stackedWidget_gx_fprime->hide();
        lineEdit_tolerance_eqtnonlineaire->setToolTip(tr("(b-a)<=Tolérance"));
        break;

    case -6:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(4);
        lineEdit_x1->show();
        label_x1->show();
        label_x0->setText("a");
        label_x1->setText("b");
        stackedWidget_gx_fprime->hide();
        lineEdit_tolerance_eqtnonlineaire->setToolTip(tr("f(r)<=Tolérance"));
        break;
    }
}
//--------------------------HAF 25-07-2020----------------------
void basic_numerical_methods::copy_tableWidget_donnees_eqtnonlineaire()
{
    QString resultatsfr0="";
    for (j=0; j<nbrecolumn_tableWidget_donnees_eqtnonlineaire ;j++)
    {
        resultatsfr0+=tableWidget_donnees_eqtnonlineaire->horizontalHeaderItem(j)->text()+"\t";
    }
    resultatsfr0+="\n";
    for (i=0; i<=nbrerow_tableWidget_donnees_eqtnonlineaire ;i++)
    {
        for (j=0; j<nbrecolumn_tableWidget_donnees_eqtnonlineaire ;j++)
        {
            resultatsfr0+=tableWidget_donnees_eqtnonlineaire->item(i,j)->text()+"\t";
        }
        resultatsfr0+="\n";
    }
    pressePapiers->setText(resultatsfr0);
}

void basic_numerical_methods::hafresolutioneqtnonlineaire_fausseposition()
{
    progressBar_eqtnonlineaire->setValue(0);

    ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    double a=lineEdit_x0->text().toDouble();
    double b=lineEdit_x1->text().toDouble();
    if(a==std::numeric_limits<double>::infinity() || a==-std::numeric_limits<double>::infinity() ||
            b==std::numeric_limits<double>::infinity() || b==-std::numeric_limits<double>::infinity()
            ){
        QMessageBox::critical(this, tr("Erreur"),
                              tr("La valeur de a ou/et b dépasse les limites admissibles!"));
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();
    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            resultatsMessage.critical(this, tr("Erreur dans f(x)"),
                                      fparserfx.ErrorMsg());
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }

    tableWidget_donnees_eqtnonlineaire->setRowCount(2);
    tableWidget_donnees_eqtnonlineaire->setColumnCount(6);
    nbrecolumn_tableWidget_donnees_eqtnonlineaire=6;
    tableWidget_donnees_eqtnonlineaire->clear();

    QStringList headtext={"i","a","b","r","f(a)*f(r)","f(b)*f(r)"};
    tableWidget_donnees_eqtnonlineaire->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtnonlineaire->setHorizontalHeaderLabels(headtext);
    valsa[0]=a;
    valsb[0]=b;
    double fa=fparserfx.Eval(valsa);
    fparserfxa_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a,ndecimaux);
    double fb=fparserfx.Eval(valsb);
    fparserfxb_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxb_EvalError,"f(x=b)",b,ndecimaux);
    double r=b-fb*(a-b)/(fa-fb);
    valsr[0]=r;
    double faxfb=fa*fb;

    if ((faxfb>=0 || a>=b) && (fparserfxa_EvalError==0 && fparserfxb_EvalError==0))
    {
        QMessageBox::critical(this, tr("Erreur"),
                              tr("Il faut que (f(a)*f(b)<0 ; a<b) et f(x) doit être monotone entre a et b!"));
        return ;
    }

    double fxaxfxr;
    double fxbxfxr;
    i=0;
    double fr=fparserfx.Eval(valsr);
    fparserfxr_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxr_EvalError,"f(x=r)",r,ndecimaux);

    while(fabs(fr)>eps && i<nmax && fparserfxr_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        fa=fparserfx.Eval(valsa);
        fparserfxa_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a,ndecimaux);
        fb=fparserfx.Eval(valsb);
        fparserfxb_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxb_EvalError,"f(x=b)",b,ndecimaux);
        r=b-fb*(a-b)/(fa-fb);
        valsr[0]=r;
        fr=fparserfx.Eval(valsr);
        fparserfxr_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxr_EvalError,"f(x=r)",r,ndecimaux);

        fxaxfxr=fa*fr;
        fxbxfxr=fb*fr;
        tableWidget_donnees_eqtnonlineaire->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,1,new QTableWidgetItem(QString::number(a,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,2,new QTableWidgetItem(QString::number(b,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,3,new QTableWidgetItem(QString::number(r,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,4,new QTableWidgetItem(QString::number(fxaxfxr,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,5,new QTableWidgetItem(QString::number(fxbxfxr,'f',ndecimaux)));

        if (fxaxfxr < 0)
            b=r;
        else if (fxbxfxr < 0)
            a=r;

        valsa[0]=a;
        valsb[0]=b;
        i+=1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+1);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i-1;
    if(fparserfxa_EvalError==0 && fparserfxb_EvalError==0 && fparserfxr_EvalError==0 && i<nmax && !std::isnan(r)&& !std::isnan(fparserfx.Eval(valsr)) && r!=std::numeric_limits<double>::infinity() && r!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i-1, 3);
        resultatsMessage.information(this, tr("Résultats"),tr("La méthode converge vers x=")+
                                     QString::number(r,'f',ndecimaux));
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Peut-être que vous devez changer a ou/et b ou augmenter la tolérance ou le nombre maximal d'itérations!"));
    }else if(fparserfxa_EvalError!=0 || fparserfxb_EvalError!=0 || fparserfxr_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes!"));
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("La méthode diverge  "
                                    ": Peut-être que vous devez changer a ou/et b"));
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_dichotomie()
{
    progressBar_eqtnonlineaire->setValue(0);

    double valsa[1];
    double valsb[1];
    double valsxm[1];
    ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    double a=lineEdit_x0->text().toDouble();
    double b=lineEdit_x1->text().toDouble();
    if(a==std::numeric_limits<double>::infinity() || a==-std::numeric_limits<double>::infinity() ||
            b==std::numeric_limits<double>::infinity() || b==-std::numeric_limits<double>::infinity()
            ){
        QMessageBox::critical(this, tr("Erreur"),
                              tr("La valeur de a ou/et b dépasse les limites admissibles!"));
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();
    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans f(x)"),
                                  fparserfx.ErrorMsg());
            errorMessage.show();
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }

    tableWidget_donnees_eqtnonlineaire->setRowCount(2);
    tableWidget_donnees_eqtnonlineaire->setColumnCount(5);
    nbrecolumn_tableWidget_donnees_eqtnonlineaire=5;
    tableWidget_donnees_eqtnonlineaire->clear();

    QStringList headtext={"i","a","b","xm=(a+b)/2","f(xm)*f(a)"};
    tableWidget_donnees_eqtnonlineaire->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtnonlineaire->setHorizontalHeaderLabels(headtext);

    valsa[0]=a;
    valsb[0]=b;

    double fa=fparserfx.Eval(valsa);
    fparserfxa_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a,ndecimaux);
    double fb=fparserfx.Eval(valsb);
    fparserfxb_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxb_EvalError,"f(x=b)",b,ndecimaux);

    double faxfb=fa*fb;

    if ((faxfb>=0 || a>=b) && fparserfxa_EvalError==0 && fparserfxb_EvalError==0)
    {
        QMessageBox::critical(this, tr("Erreur"),
                              tr("Il faut que (f(a)*f(b)<0 ; a<b) et f(x) doit être monotone entre a et b!"));
        return ;
    }

    i=0;
    double fxmxfxa;
    double fm;
    while((b-a)>eps && i<nmax && fparserfxa_EvalError==0 && fparserfxb_EvalError==0 && fparserfxm_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        valsa[0]=a;
        valsb[0]=b;
        xm=(a+b)/2;
        valsxm[0]=xm;
        fa=fparserfx.Eval(valsa);
        fparserfxa_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a,ndecimaux);
        fm=fparserfx.Eval(valsxm);
        fparserfxm_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxm_EvalError,"f(x=xm)",xm,ndecimaux);

        fxmxfxa=fm*fa;
        tableWidget_donnees_eqtnonlineaire->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,1,new QTableWidgetItem(QString::number(a,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,2,new QTableWidgetItem(QString::number(b,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,3,new QTableWidgetItem(QString::number(xm,'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,4,new QTableWidgetItem(QString::number(fxmxfxa,'f',ndecimaux)));

        if(fxmxfxa>0)
        {
            a=xm;
        }
        else
        {
            b=xm;
        }
        i+=1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+1);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i-1;
    if(fparserfxa_EvalError==0 && fparserfxb_EvalError==0 && fparserfxm_EvalError==0 && i<nmax && !std::isnan(xm) && !std::isnan(fparserfx.Eval(valsa))&& !std::isnan(fparserfx.Eval(valsb)) && xm!=std::numeric_limits<double>::infinity() && xm!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i-1, 3);
        resultatsMessage.information(this, tr("Résultats"),tr("La méthode converge vers x=")+
                                     QString::number(xm,'f',ndecimaux));
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Peut-être que vous devez changer a ou/et b ou "
                                    "augmenter la tolérance ou le nombre maximal d'itérations!"));
    }else if(fparserfxa_EvalError!=0 || fparserfxb_EvalError!=0 || fparserfxm_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes!"));
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("La méthode diverge  "
                                    ": Peut-être que vous devez changer a ou/et b"));
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_secante()
{
    progressBar_eqtnonlineaire->setValue(0);

    double valsi[1];
    double valsimoisun[1];
    ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    i=0;
    double x[nmax];
    x[0]=lineEdit_x0->text().toDouble();
    x[1]=lineEdit_x1->text().toDouble();
    if(x[0]==std::numeric_limits<double>::infinity() || x[0]==-std::numeric_limits<double>::infinity() ||
            x[1]==std::numeric_limits<double>::infinity() || x[1]==-std::numeric_limits<double>::infinity()
            ){
        QMessageBox::critical(this, tr("Erreur"),
                              tr("La valeur de x0 ou/et x1 dépasse les limites admissibles!"));
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();

    if (x[0]==x[1])
    {
        QMessageBox::critical(this, tr("Erreur"),
                              tr("Il faut que x0 soit différent de x1!"));
        return ;
    }

    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans f(x)"),
                                  fparserfx.ErrorMsg());
            errorMessage.show();
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }

    tableWidget_donnees_eqtnonlineaire->setRowCount(2);
    tableWidget_donnees_eqtnonlineaire->setColumnCount(3);
    nbrecolumn_tableWidget_donnees_eqtnonlineaire=3;
    tableWidget_donnees_eqtnonlineaire->clear();

    QStringList headtext={"i","x(i)","f(x(i))"};
    tableWidget_donnees_eqtnonlineaire->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtnonlineaire->setHorizontalHeaderLabels(headtext);
    valsi[0]=x[0];
    tableWidget_donnees_eqtnonlineaire->setItem(0,0,new QTableWidgetItem(QString::number(0)));
    tableWidget_donnees_eqtnonlineaire->setItem(0,1,new QTableWidgetItem(QString::number(x[0],'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(0,2,new QTableWidgetItem(QString::number(fparserfx.Eval(valsi),'f',ndecimaux)));
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x=x[0])",x[0],ndecimaux);
    valsi[0]=x[1];
    valsimoisun[0]=x[0];
    tableWidget_donnees_eqtnonlineaire->setItem(1,0,new QTableWidgetItem(QString::number(1)));
    tableWidget_donnees_eqtnonlineaire->setItem(1,1,new QTableWidgetItem(QString::number(x[1],'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(1,2,new QTableWidgetItem(QString::number(fparserfx.Eval(valsi),'f',ndecimaux)));
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x=x[1])",x[1],ndecimaux);
    i=1;
    double valeurfxi;
    double valeurfximoisun;
    while (fabs(fparserfx.Eval(valsi))>eps && i<nmax && fparserfx_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        valsi[0]=x[i];
        valsimoisun[0]=x[i-1];
        valeurfximoisun=fparserfx.Eval(valsimoisun);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i-1],ndecimaux);
        valeurfxi=fparserfx.Eval(valsi);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i],ndecimaux);
        x[i+1]=x[i]-valeurfxi*(x[i]-x[i-1])/(valeurfxi-valeurfximoisun);
        tableWidget_donnees_eqtnonlineaire->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,1,new QTableWidgetItem(QString::number(x[i],'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i,2,new QTableWidgetItem(QString::number(valeurfxi,'f',ndecimaux)));
        i=i+1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+1);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i-1;
    if(fparserfx_EvalError==0 && i<nmax  && !std::isnan(x[i-1])&& !std::isnan(fparserfx.Eval(valsi)) && x[i-1]!=std::numeric_limits<double>::infinity() && x[i-1]!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i-1, 1);
        resultatsMessage.information(this, tr("Résultats"),tr("La méthode converge vers x=")+
                                     QString::number(x[i-1],'f',ndecimaux));
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Peut-être que vous "
                                    "devez changer x0 ou/et x1 ou augmenter la tolérance ou le nombre maximal d'itérations!"));
    }else if(fparserfx_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes!"));
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("La méthode diverge  "
                                    ": Peut-être que vous devez changer x0 ou/et x1"));
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_newtonraphson()
{
    progressBar_eqtnonlineaire->setValue(0);

    double vals[1];
    ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    i=0;
    double x[nmax];
    x[0]=lineEdit_x0->text().toDouble();
    if(x[0]==std::numeric_limits<double>::infinity() || x[0]==-std::numeric_limits<double>::infinity()){
        QMessageBox::critical(this, tr("Erreur"),
                              tr("La valeur de x0 dépasse les limites admissibles!"));
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();
    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans f(x)"),
                                  fparserfx.ErrorMsg());
            errorMessage.show();
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }
    while(true)
    {
        fprimex=lineEdit_fprime_eqt_non_lineaire->text();
        int res = fparserfprimex.Parse(fprimex.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfprimex.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans f'(x)"),
                                  fparserfprimex.ErrorMsg());
            errorMessage.show();
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfprimex.ErrorMsg() << "\n\n";
    }

    tableWidget_donnees_eqtnonlineaire->setRowCount(2);
    tableWidget_donnees_eqtnonlineaire->setColumnCount(4);
    nbrecolumn_tableWidget_donnees_eqtnonlineaire=4;
    tableWidget_donnees_eqtnonlineaire->clear();
    QStringList headtext={"i","x(i)","f(x(i))","f'(x(i))"};
    tableWidget_donnees_eqtnonlineaire->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtnonlineaire->setHorizontalHeaderLabels(headtext);

    vals[0]=x[i];
    tableWidget_donnees_eqtnonlineaire->setItem(i,0,new QTableWidgetItem(QString::number(i)));
    tableWidget_donnees_eqtnonlineaire->setItem(i,1,new QTableWidgetItem(QString::number(x[i],'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(i,2,new QTableWidgetItem(QString::number(fparserfx.Eval(vals),'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(i,3,new QTableWidgetItem(QString::number(fparserfprimex.Eval(vals),'f',ndecimaux)));
    fparserfprimex_EvalError=fparserfprimex.EvalError();
    EvalErrorfunHAF(fparserfprimex_EvalError,"f'(x)",x[i],ndecimaux);
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i],ndecimaux);
    while (fabs(fparserfx.Eval(vals))>eps && i<nmax && fparserfx_EvalError==0 && fparserfprimex_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        vals[0]=x[i];
        x[i+1]=x[i]-fparserfx.Eval(vals)/fparserfprimex.Eval(vals);
        vals[0]=x[i+1];
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,0,new QTableWidgetItem(QString::number(i+1)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,1,new QTableWidgetItem(QString::number(x[i+1],'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,2,new QTableWidgetItem(QString::number(fparserfx.Eval(vals),'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,3,new QTableWidgetItem(QString::number(fparserfprimex.Eval(vals),'f',ndecimaux)));
        fparserfprimex_EvalError=fparserfprimex.EvalError();
        EvalErrorfunHAF(fparserfprimex_EvalError,"f'(x)",x[i+1],ndecimaux);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i+1],ndecimaux);
        i=i+1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+2);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i;
    if(fparserfx_EvalError==0 && fparserfprimex_EvalError==0 && i<nmax && !std::isnan(x[i])&& !std::isnan(fparserfx.Eval(vals)) && x[i]!=std::numeric_limits<double>::infinity() && x[i]!=-std::numeric_limits<double>::infinity() ){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i, 1);
        resultatsMessage.information(this, tr("Résultats"),tr("La méthode converge vers x=")+
                                     QString::number(x[i],'f',ndecimaux));
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Peut-être que vous devez changer x0 ou augmenter "
                                    "la tolérance ou le nombre maximal d'itérations!"));
    }else if(fparserfx_EvalError!=0 || fparserfprimex_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes!"));
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("La méthode diverge  "
                                    ": Peut-être que vous devez changer x0!"));
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_ptfixe()
{
    progressBar_eqtnonlineaire->setValue(0);

    double vals[1];
    ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    i=0;
    double x[nmax];
    x[0]=lineEdit_x0->text().toDouble();
    if(x[0]==std::numeric_limits<double>::infinity() || x[0]==-std::numeric_limits<double>::infinity()){
        QMessageBox::critical(this, tr("Erreur"),
                              tr("La valeur de x0 dépasse les limites admissibles!"));
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();
    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans f(x)"),
                                  fparserfx.ErrorMsg());
            errorMessage.show();
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }
    while(true)
    {
        gx=lineEdit_gx_eqt_non_lineaire->text();
        int res = fparsergx.Parse(gx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparsergx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans g(x)"),
                                  fparsergx.ErrorMsg());
            errorMessage.show();
            // break ;
            return ; // HAF 1-8-2020
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparsergx.ErrorMsg() << "\n\n";
    }

    tableWidget_donnees_eqtnonlineaire->setRowCount(2);
    tableWidget_donnees_eqtnonlineaire->setColumnCount(4);
    nbrecolumn_tableWidget_donnees_eqtnonlineaire=4;
    tableWidget_donnees_eqtnonlineaire->clear();
    QStringList headtext={"i","x(i)","g(x(i))","f(x(i))"};
    tableWidget_donnees_eqtnonlineaire->setStyleSheet("QTableView {selection-background-color: green;}");
    tableWidget_donnees_eqtnonlineaire->setHorizontalHeaderLabels(headtext);

    vals[0]=x[i];
    tableWidget_donnees_eqtnonlineaire->setItem(i,0,new QTableWidgetItem(QString::number(i)));
    tableWidget_donnees_eqtnonlineaire->setItem(i,1,new QTableWidgetItem(QString::number(x[i],'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(i,2,new QTableWidgetItem(QString::number(fparsergx.Eval(vals),'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(i,3,new QTableWidgetItem(QString::number(fparserfx.Eval(vals),'f',ndecimaux)));
    fparsergx_EvalError=fparsergx.EvalError();
    EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i],ndecimaux);
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i],ndecimaux);
    while (fabs(fparserfx.Eval(vals))>eps && i<nmax && fparserfx_EvalError==0 && fparsergx_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        vals[0]=x[i];
        x[i+1]=fparsergx.Eval(vals);
        fparsergx_EvalError=fparsergx.EvalError();
        EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i],ndecimaux);
        vals[0]=x[i+1];
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,0,new QTableWidgetItem(QString::number(i+1)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,1,new QTableWidgetItem(QString::number(x[i+1],'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,2,new QTableWidgetItem(QString::number(fparsergx.Eval(vals),'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,3,new QTableWidgetItem(QString::number(fparserfx.Eval(vals),'f',ndecimaux)));
        fparsergx_EvalError=fparsergx.EvalError();
        EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i+1],ndecimaux);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i+1],ndecimaux);
        i=i+1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+2);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i;
    if(fparserfx_EvalError==0 && fparsergx_EvalError==0 && i<nmax && !std::isnan(x[i])&& !std::isnan(fparserfx.Eval(vals)) && x[i]!=std::numeric_limits<double>::infinity() && x[i]!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i, 1);
        resultatsMessage.information(this, tr("Résultats"),tr("La méthode converge vers x=")+
                                     QString::number(x[i],'f',ndecimaux));
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Le nombre maximal d'itérations a été atteint sans "
                                    "qu'aucune solution satisfaisante la tolérance n'a pu être trouvée :\n"
                                    "Peut-être que vous devez changer "
                                    "g(x) ou/et x0! (ou augmenter la tolérance ou le nombre maximal d'itérations)"));
    }else if(fparserfx_EvalError!=0 || fparsergx_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes!"));
    }else{
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("La méthode diverge  "
                                    ": Peut-être que vous devez changer g(x) ou/et x0!"));
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire()
{
    stackedWidget_nolineairEqt->setCurrentIndex(1);
    fparserfx_EvalError=0;
    fparsergx_EvalError=0;
    fparserfprimex_EvalError=0;

    tableWidget_donnees_eqtnonlineaire->clear();
    pushButton_Copier_TableauEqtNonLineaire->hide();
    id=stackedWidget_methodeeqtnonlineaire->currentIndex();
    switch (id) {
    case 0:
        if (validx0 && validtolerance){
            hafresolutioneqtnonlineaire_ptfixe();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez x0 ou/et Tolérance"));
        }
        break;

    case 1:
        if (validx0 && validtolerance){
            hafresolutioneqtnonlineaire_newtonraphson();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez x0 ou/et Tolérance"));
        }
        break;

    case 2:
        if (validx0 && validx1 && validtolerance){
            hafresolutioneqtnonlineaire_secante();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez x0 ou/et x1 ou/et Tolérance"));
        }
        break;

    case 3:
        if (validx0 && validx1 && validtolerance){
            hafresolutioneqtnonlineaire_dichotomie();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez a ou/et b ou/et Tolérance"));
        }
        break;

    case 4:
        if (validx0 && validx1 && validtolerance){
            hafresolutioneqtnonlineaire_fausseposition();
        }else{
            resultatsMessage.warning(this, tr("Résultats"),
                                     tr("Données incorrectes! Vérifiez a ou/et b ou/et Tolérance"));
        }
        break;
    }
}
//--------------------------HAF 17-05-2015-----21-8-2021---------------
void basic_numerical_methods::plotHAF( QVector<double> x,  QVector<double> y,  QVector<double> g)
{
    //-----HAF 21-8-2021-----
    // Détermination Max et Mini de y and g
    double highy,lowy;
    highy=y[0];
    lowy=y[0];

    for(int i = 1; i < n; i++)
    {
        if(y[i]>highy){
            highy=y[i];
        }else{
            if(y[i]<lowy){
                lowy=y[i];
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(g[i]>highy){
            highy=g[i];
        }else{
            if(g[i]<lowy){
                lowy=g[i];
            }
        }
    }
    //-----------------------
    customPlot->addGraph();
    customPlot->graph(0)->setName("f(x)");
    customPlot->graph(0)->setData(x, y);
    customPlot->addGraph();
    customPlot->graph(1)->setName("g(x)");
    customPlot->graph(1)->setData(x, g);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("f(x) & g(x)");
    customPlot->xAxis->setRange(lineEdit_a_tracage_fx->text().toDouble(), lineEdit_b_tracage_fx->text().toDouble());

    customPlot->yAxis->setRange(lowy-abs(0.5*lowy),highy+abs(0.25*highy));

    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    customPlot->graph(0)->setPen(QPen(Qt::red));
    //customPlot->graph(0)->rescaleAxes();
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::white, 7));
    customPlot->graph(1)->setPen(QPen(Qt::blue));
    //customPlot->graph(1)->rescaleAxes();
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->legend->setVisible(true);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    customPlot->replot();
}
//--------------------------------------------------------------
double haff(double x,double Ks,double D,double Re)
{
    return (1/sqrt(x)+2*log10(Ks/(3.71*D)+2.51/(Re*sqrt(x))));
}
void basic_numerical_methods::hafafficherColebrookWhite()
{
    if (!validDiametre || !validRuguosite || !validDebit){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes! Vérifiez Diamètre ou/et Rugosité ou/et Débit"));
        return;
    }
    // Récupérations des données de l'interface GUI
    double D=lineEdit_Diametre->text().toDouble();
    double Ks=lineEdit_Ruguosite->text().toDouble();
    double Q=lineEdit_Debit->text().toDouble();
    int index_unite_diametre=comboBox_unite_diametre->currentIndex();
    int index_unite_rugosite=comboBox_unite_rugosite->currentIndex();
    int index_unite_debit=comboBox_unite_debit->currentIndex();

    switch(index_unite_diametre)
    {
    case 0: D=D ;break;
    case 1: D=D*1e-3 ;break;
    }
    switch(index_unite_rugosite)
    {
    case 0: Ks=Ks*1e-3 ;break;
    case 1: Ks=Ks ;break;
    }
    switch(index_unite_debit)
    {
    case 0: Q=Q ;break;
    case 1: Q=Q*1e-3 ;break;
    case 2: Q=Q*1e-3/3600 ;break;
    }

    // Calcul par la méthode de bissection (Epsilon=Ks/D)

    double pi=M_PI;
    double nul=0.000001;
    double S=pi*pow(D,2)/4;
    double Umoy=Q/S;
    double Re=Umoy*D/nul;
    double a=0.000001;
    double b=3;

    if (haff(a,Ks,D,Re)*haff(b,Ks,D,Re)<0 and Re>=2500)
    {
        double c=(a+b)/2;
        i=1;
        int imax=100;
        while ((haff(a,Ks,D,Re)-haff(b,Ks,D,Re))>=0.00000000001)
        {
            if ((haff(c,Ks,D,Re)*haff(a,Ks,D,Re))>0)
            {
                a=c;
            }
            else
            {
                b=c;
            }
            c=(a+b)/2;
            i+=1;
            if (i>imax)
            {
                break;
            }
        }

        outputtext=tr("Lambda est ")+QString::number(c)+tr(" avec Re égal à ")+QString::number(Re);
        lambda_textBrowser->setText(outputtext);
    }
    else
    {
        if (Re<2500)
        {
            outputtext=tr("L'écoulement n'est pas turbulent, donc l'équation de Colebrook-White n'est pas valable ! Re : ")
                    +QString::number(Re);
        }
        else
        {
            outputtext=tr("Erreur de données !");
        }
        lambda_textBrowser->setText(outputtext);
    }

}
void basic_numerical_methods::hafaffichertracagefxgx()
{
    if (!valida_tracage || !validb_tracage || !validdx_tracage){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes! Vérifiez a ou/et b ou/et dx"));
        hafclearcustomPlot();
        return;
    }
    fparserfx_EvalError=0;
    fparsergx_EvalError=0;
    textBrowser_resultats_lineEdit_tracage_fx->setText("");
    customPlot->clearGraphs();
    while(true)
    {
        fx=lineEdit_tracage_fx->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            resultatsMessage.critical(this, tr("Erreur dans f(x)"),
                                      fparserfx.ErrorMsg());
            //-----HAF 21-08-2021-----
            hafclearcustomPlot();
            //------------------------
            return ;
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }
    while(true)
    {
        gx=lineEdit_tracage_gx->text();
        int res = fparsergx.Parse(gx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparsergx.ErrorMsg())!=0){
            resultatsMessage.critical(this, tr("Erreur dans g(x)"),
                                      fparsergx.ErrorMsg());
            //-----HAF 21-08-2021-----
            hafclearcustomPlot();
            //------------------------
            return ;
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparsergx.ErrorMsg() << "\n\n";
    }
    double a=lineEdit_a_tracage_fx->text().toDouble();
    double b=lineEdit_b_tracage_fx->text().toDouble();
    double dx=lineEdit_dx_tracage_fx->text().toDouble();
    n=int((b-a)/dx+1);
    if (a>=b)
    {
        resultatsMessage.critical(this, tr("Erreur"),
                                  tr("Il faut que a<b!"));
        hafclearcustomPlot();
        return ;
    }

    QVector<double> x(n);
    QVector<double> y(n);
    QVector<double> g(n);
    double vals[1];
    outputtext="";
    i=0;
    for(i=0; i<n; i++)
    {
        vals[0]=a+i*dx;
        x[i]=vals[0];
        y[i]=fparserfx.Eval(vals);
        g[i]=fparsergx.Eval(vals);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i],ndecimaux);
        if(fparserfx_EvalError!=0) {
            n=i;
            //-----HAF 21-08-2021-----
            hafclearcustomPlot();
            //------------------------
            return;
        }
        fparsergx_EvalError=fparsergx.EvalError();
        EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i],ndecimaux);
        if(fparsergx_EvalError!=0) {
            n=i;
            //-----HAF 21-08-2021-----
            hafclearcustomPlot();
            //------------------------
            return;
        }
        outputtext+="f("+QString::number(x[i])+") =\t"+QString::number(y[i])+"\t";
        outputtext+="g("+QString::number(x[i])+") =\t"+QString::number(g[i])+"\n";
    }

    customPlot->replot();
    textBrowser_resultats_lineEdit_tracage_fx->setText(outputtext);
    QVector<double> xnew(n);
    QVector<double> ynew(n);
    QVector<double> gnew(n);
    for(i=0; i<n; i++)
    {
        xnew[i]=x[i];
        ynew[i]=y[i];
        gnew[i]=g[i];
    }
    plotHAF(xnew,ynew,gnew);

}
void basic_numerical_methods::hafafficherIntegration()
{
    if (!valida_integ || !validb_integ){
        resultatsMessage.warning(this, tr("Résultats"),
                                 tr("Données incorrectes! Vérifiez a ou/et b"));
        return;
    }
    fparserfxintegrale_EvalError=0;
    while(true)
    {
        fxintegrale=lineEdit_fx_integ->text();
        int res = fparserfxintegrale.Parse(fxintegrale.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfxintegrale.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, tr("Erreur dans f(x)"),
                                  fparserfxintegrale.ErrorMsg());
            errorMessage.show();
            break ;
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfxintegrale.ErrorMsg() << "\n\n";
    }
    nselonmethodechoisie();
    progressBar->setValue(0);
    const int m=array_size; //le nbre max de lines dans le tableau x(i) et y(i).
    double a,b,dx;

    double I;

    ksimp13[0]=1;
    for (i=1; i<m ;i++)
    {
        ksimp13[i]=2*i+1;
    }
    ksimp38[0]=4;
    for (i=1; i<m ;i++)
    {
        ksimp38[i]=3*i+4;
    }

    if (radioButton_tableau_xy->isChecked())
    {
        n=spinBox_nbre_pts_tableau->text().toInt();
    }
    else if (radioButton_fx_a_b_dx->isChecked())
    {
        n=spinBox_nbre_pts_fx->text().toInt();
    }
    for (i=0; i<n ;i++)
    {
        if (radioButton_tableau_xy->isChecked())
        {
            QTableWidgetItem* item0 = tableWidget_donnees->item(i,0);
            QTableWidgetItem* item1 = tableWidget_donnees->item(i,1);
            if(!item0 || item0->text().isEmpty() || !item1 || item1->text().isEmpty())
            {
                outputtext=tr("Veuillez remplir svp tous le tableau des données (x et y) jusqu'à la ligne numéro :  ")+QString::number(n);
                QMessageBox::warning(this,tr("Erreur données !"),outputtext);
                integral_textBrowser->setText("");
                goto fin;
            }
        }
    }

    if (radioButton_trapezes->isChecked())
    {
        if (radioButton_tableau_xy->isChecked())
        {
            for (i=0; i<n ;i++)
            {
                x[i]=tableWidget_donnees->item(i,0)->text().toDouble();
                y[i]=tableWidget_donnees->item(i,1)->text().toDouble();
            }
        }
        else if (radioButton_fx_a_b_dx->isChecked())
        {
            a=lineEdit_a->text().toDouble();
            b=lineEdit_b->text().toDouble();
            if (a>=b)
            {
                QMessageBox::critical(this, tr("Erreur"),
                                      tr("Il faut que a<b!"));
                return ;
            }
            n=spinBox_nbre_pts_fx->text().toInt();
            dx=(b-a)/(n-1);
            tableWidget_donnees->setRowCount(m);
            spinBox_nbre_pts_tableau->setValue(n);
            tableWidget_donnees->clear();
            double vals[1];
            for(i=0; i<n; i++)
            {
                vals[0]=a+i*dx;
                x[i]=vals[0];
                y[i]=fparserfxintegrale.Eval(vals);
                fparserfxintegrale_EvalError=fparserfxintegrale.EvalError();
                EvalErrorfunHAF(fparserfxintegrale_EvalError,"f(x)",x[i],ndecimaux);
                if (fparserfxintegrale_EvalError!=0) { integral_textBrowser->setText("");return;}
            }
        }

        I=0;
        if (radioButton_tableau_xy->isChecked())
        {

            tableWidget_donnees->setItem(0,2,new QTableWidgetItem(QString::number(0)));
            dx=x[1]-x[0];
            for (i=0; i<n-1; i++)
            {
                I=I+dx/2*(y[i]+y[i+1]);
                tableWidget_donnees->setItem(i+1,2,new QTableWidgetItem(QString::number(I)));
            }
            cherchernbrecolumntableau(n);
        }
        else if (radioButton_fx_a_b_dx->isChecked())
        {
            spinBox_nbre_pts_fx->setValue(n);
            if(checkBox_remplir_tableau->isChecked())
            {
                QStringList headtext={"x(i)","y(i) ","I(j)"};
                tableWidget_donnees->setStyleSheet("QTableView {selection-background-color: green;}");
                tableWidget_donnees->setHorizontalHeaderLabels(headtext);
                for(i=0; i<n; i++)
                {
                    hafafficherprogressBaretape1(i,n);
                    tableWidget_donnees->setItem(i,0,new QTableWidgetItem(QString::number(x[i])));
                    tableWidget_donnees->setItem(i,1,new QTableWidgetItem(QString::number(y[i])));
                }
                remplirunelinevidetableau(n);
                tableWidget_donnees->setItem(0,2,new QTableWidgetItem(QString::number(0)));
            }
            dx=lineEdit_dx->text().toDouble();
            for (i=0; i<n-1; i++)
            {

                I=I+dx/2*(y[i]+y[i+1]);
                if(checkBox_remplir_tableau->isChecked())
                {
                    hafafficherprogressBaretape2(i,n);
                    tableWidget_donnees->setItem(i+1,2,new QTableWidgetItem(QString::number(I)));
                }

            }
        }

        if (radioButton_tableau_xy->isChecked())
        {
            outputtext=tr("L'intégrale (selon le tableau au dessus) entre ")+QString::number(x[0])+tr(" et ")
                    +QString::number(x[n-1])+tr(" avec un pas de ")+QString::number(x[1]-x[0])
                    +tr(" par la méthode des trapèzes est égale à ")+QString::number(I);
        }
        else if (radioButton_fx_a_b_dx->isChecked())
        {
            a=lineEdit_a->text().toDouble();
            b=lineEdit_b->text().toDouble();
            dx=lineEdit_dx->text().toDouble();
            fx=lineEdit_fx_integ->text();
            outputtext=tr("L'intégrale de f(x)=")+fx+tr(" entre ")+QString::number(a)+tr(" et ")
                    +QString::number(b)+tr(" avec un pas de ")+QString::number(dx)
                    +tr(" par la méthode des trapèzes est égale à ")+QString::number(I);
        }
        integral_textBrowser->setText(outputtext);
        tableWidget_donnees->resizeColumnsToContents();
    }

    if (radioButton_simpson13->isChecked())
    {
        nselonmethodechoisie();
        bool okpoursimpson13=false;
        if (radioButton_tableau_xy->isChecked())
        {
            for (i=0; i<=m; i++)
            {
                if (n==ksimp13[i])
                {
                    okpoursimpson13=true;
                }
            }
        }
        else if (radioButton_fx_a_b_dx->isChecked())
        {
            a=lineEdit_a->text().toDouble();
            b=lineEdit_b->text().toDouble();
            if (a>=b)
            {
                QMessageBox::critical(this, tr("Erreur"),
                                      tr("Il faut que a<b!"));
                return ;
            }
            n=spinBox_nbre_pts_fx->text().toInt();
            dx=(b-a)/(n-1);
            tableWidget_donnees->setRowCount(m);
            spinBox_nbre_pts_tableau->setValue(n);
            tableWidget_donnees->clear();
            double vals[1];
            for(i=0; i<n; i++)
            {
                vals[0]=a+i*dx;
                x[i]=vals[0];
                y[i]=fparserfxintegrale.Eval(vals);
                fparserfxintegrale_EvalError=fparserfxintegrale.EvalError();
                EvalErrorfunHAF(fparserfxintegrale_EvalError,"f(x)",x[i],ndecimaux);
                if (fparserfxintegrale_EvalError!=0) {integral_textBrowser->setText("");return;}
            }
            for (i=0; i<=m; i++)
            {
                if (n==ksimp13[i])
                {
                    okpoursimpson13=true;
                }
            }
        }

        if (okpoursimpson13==true)
        {
            I=0;
            if (radioButton_tableau_xy ->isChecked())
            {
                for (i=0; i<n ;i++)
                {
                    x[i]=tableWidget_donnees->item(i,0)->text().toDouble();
                    y[i]=tableWidget_donnees->item(i,1)->text().toDouble();
                }
                tableWidget_donnees->setItem(0,2,new QTableWidgetItem(QString::number(0)));
                dx=x[1]-x[0];
                k=0;
                for (i=0; i<n-2; i+=2)
                {
                    I=I+dx/3*(y[i]+4*y[i+1]+y[i+2]);
                    tableWidget_donnees->setItem(i+2,2,new QTableWidgetItem(QString::number(I)));
                    tableWidget_donnees->setItem(k+1,2,new QTableWidgetItem(""));
                    k+=2;
                }
                cherchernbrecolumntableau(n);
            }
            else if (radioButton_fx_a_b_dx->isChecked())
            {
                spinBox_nbre_pts_fx->setValue(n);
                if(checkBox_remplir_tableau->isChecked())
                {
                    QStringList headtext={"x(i)","y(i) ","I(j)"};
                    tableWidget_donnees->setStyleSheet("QTableView {selection-background-color: green;}");
                    tableWidget_donnees->setHorizontalHeaderLabels(headtext);

                    for(i=0; i<n; i++)
                    {
                        hafafficherprogressBaretape1(i,n);
                        tableWidget_donnees->setItem(i,0,new QTableWidgetItem(QString::number(x[i])));
                        tableWidget_donnees->setItem(i,1,new QTableWidgetItem(QString::number(y[i])));
                    }
                    remplirunelinevidetableau(n);
                    tableWidget_donnees->setItem(0,2,new QTableWidgetItem(QString::number(0)));
                }
                dx=lineEdit_dx->text().toDouble();
                for (i=0; i<n-2; i+=2)
                {
                    I=I+dx/3*(y[i]+4*y[i+1]+y[i+2]);
                    if(checkBox_remplir_tableau->isChecked())
                    {
                        hafafficherprogressBaretape2(i,n);
                        tableWidget_donnees->setItem(i+2,2,new QTableWidgetItem(QString::number(I)));
                    }

                }
            }
            if (radioButton_tableau_xy->isChecked())
            {
                outputtext=tr("L'intégrale (selon le tableau au dessus) entre ")+QString::number(x[0])+tr(" et ")
                        +QString::number(x[n-1])+tr(" avec un pas de ")+QString::number(x[1]-x[0])
                        +tr(" par la méthode SIMPSON 1/3 est égale à ")+QString::number(I);

            }
            else if (radioButton_fx_a_b_dx->isChecked())
            {
                a=lineEdit_a->text().toDouble();
                b=lineEdit_b->text().toDouble();
                dx=lineEdit_dx->text().toDouble();
                fx=lineEdit_fx_integ->text();
                outputtext=tr("L'intégrale de f(x)=")+fx+tr(" entre ")+QString::number(a)+tr(" et ")
                        +QString::number(b)+tr(" avec un pas de ")+QString::number(dx)+tr(" par la méthode SIMPSON 1/3 est égale à ")
                        +QString::number(I);
            }
            integral_textBrowser->setText(outputtext);
            tableWidget_donnees->resizeColumnsToContents();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur données !"),
                                 tr("Le nombre des x et y (Nbre des pts) n'est pas compatible "
                                    "avec la méthode d'intégration numérique choisie (n=2m+1 avec m=0 à l'infini)."));
            integral_textBrowser->setText("");
        }
    }

    if (radioButton_simpson38->isChecked())
    {
        nselonmethodechoisie();
        bool okpoursimpson38=false;
        if (radioButton_tableau_xy->isChecked())
        {
            for (i=0; i<=m; i++)
            {
                if (n==ksimp38[i])
                {
                    okpoursimpson38=true;
                }

            }

        }
        else if (radioButton_fx_a_b_dx->isChecked())
        {
            a=lineEdit_a->text().toDouble();
            b=lineEdit_b->text().toDouble();
            if (a>=b)
            {
                QMessageBox::critical(this, tr("Erreur"),
                                      tr("Il faut que a<b!"));
                return ;
            }
            n=spinBox_nbre_pts_fx->text().toInt();
            dx=(b-a)/(n-1);
            tableWidget_donnees->setRowCount(m);
            spinBox_nbre_pts_tableau->setValue(n);
            tableWidget_donnees->clear();
            double vals[1];
            for(i=0; i<n; i++)
            {
                vals[0]=a+i*dx;
                x[i]=vals[0];
                y[i]=fparserfxintegrale.Eval(vals);
                fparserfxintegrale_EvalError=fparserfxintegrale.EvalError();
                EvalErrorfunHAF(fparserfxintegrale_EvalError,"f(x)",x[i],ndecimaux);
                if (fparserfxintegrale_EvalError!=0) {integral_textBrowser->setText("");return;}
            }
            for (i=0; i<=m; i++)
            {
                if (n==ksimp38[i])
                {
                    okpoursimpson38=true;
                }

            }
        }
        if (okpoursimpson38==true)
        {
            double I=0;
            if (radioButton_tableau_xy ->isChecked())
            {
                for (i=0; i<n ;i++)
                {
                    x[i]=tableWidget_donnees->item(i,0)->text().toDouble();
                    y[i]=tableWidget_donnees->item(i,1)->text().toDouble();
                }
                tableWidget_donnees->setItem(0,2,new QTableWidgetItem(QString::number(0)));
                dx=x[1]-x[0];
                k=0;
                for (i=0; i<n-3; i+=3)
                {
                    I=I+3*dx/8*(y[i]+3*y[i+1]+3*y[i+2]+y[i+3]);
                    tableWidget_donnees->setItem(i+3,2,new QTableWidgetItem(QString::number(I)));
                    tableWidget_donnees->setItem(k+1,2,new QTableWidgetItem(""));
                    tableWidget_donnees->setItem(k+2,2,new QTableWidgetItem(""));
                    k+=3;
                }
                cherchernbrecolumntableau(n);
            }
            else if (radioButton_fx_a_b_dx->isChecked())
            {
                spinBox_nbre_pts_fx->setValue(n);
                if(checkBox_remplir_tableau->isChecked())
                {
                    QStringList headtext={"x(i)","y(i) ","I(j)"};
                    tableWidget_donnees->setStyleSheet("QTableView {selection-background-color: green;}");
                    tableWidget_donnees->setHorizontalHeaderLabels(headtext);

                    for(i=0; i<n; i++)
                    {
                        hafafficherprogressBaretape1(i,n);
                        tableWidget_donnees->setItem(i,0,new QTableWidgetItem(QString::number(x[i])));
                        tableWidget_donnees->setItem(i,1,new QTableWidgetItem(QString::number(y[i])));
                    }
                    remplirunelinevidetableau(n);
                    tableWidget_donnees->setItem(0,2,new QTableWidgetItem(QString::number(0)));
                }
                dx=lineEdit_dx->text().toDouble();
                for (i=0; i<n-3; i+=3)
                {
                    I=I+3*dx/8*(y[i]+3*y[i+1]+3*y[i+2]+y[i+3]);
                    if(checkBox_remplir_tableau->isChecked())
                    {
                        hafafficherprogressBaretape2(i,n);
                        tableWidget_donnees->setItem(i+3,2,new QTableWidgetItem(QString::number(I)));
                    }

                }
            }

            if (radioButton_tableau_xy->isChecked())
            {
                outputtext=tr("L'intégrale (selon le tableau au dessus) entre ")+QString::number(x[0])+tr(" et ")
                        +QString::number(x[n-1])+tr(" avec un pas de ")+QString::number(x[1]-x[0])
                        +tr(" par la méthode SIMPSON 3/8 est égale à ")+QString::number(I);
            }
            else if (radioButton_fx_a_b_dx->isChecked())
            {
                a=lineEdit_a->text().toDouble();
                b=lineEdit_b->text().toDouble();
                dx=lineEdit_dx->text().toDouble();
                fx=lineEdit_fx_integ->text();
                outputtext=tr("L'intégrale de f(x)=")+fx+tr(" entre ")+QString::number(a)+tr(" et ")+QString::number(b)
                        +tr(" avec un pas de ")+QString::number(dx)+tr(" par la méthode SIMPSON 3/8 est égale à ")+QString::number(I);
            }
            integral_textBrowser->setText(outputtext);
            tableWidget_donnees->resizeColumnsToContents();
        }
        else
        {
            QMessageBox::warning(this,tr("Erreur données !"),tr("Le nombre des x et y (Nbre des pts) "
                                                                "n'est pas compatible avec la méthode d'intégration numérique choisie (n=3m+4 avec m=0 à l'infini)."));
            integral_textBrowser->setText("");
        }
    }
fin:;
    progressBar->setValue(100);
    tableWidget_donnees->horizontalHeader()->setStretchLastSection(true);
    tableWidget_donnees->resizeColumnsToContents();
}
void basic_numerical_methods::hafafficherprogressBaretape1(int i, int n)
{
    if (i>=n/10 && i<n/5)
    {
        progressBar->setValue(10);
    }
    if (i>=n/5 && i<n/4)
    {
        progressBar->setValue(15);
    }
    if (i>=n/4 && i<n/3)
    {
        progressBar->setValue(20);
    }
    if (i>=n/3 && i<n/2)
    {
        progressBar->setValue(25);
    }
    if (i>=n/2 && i<n/1.5)
    {
        progressBar->setValue(30);
    }
    if (i>=n/1.5 && i<=n)
    {
        progressBar->setValue(35);
    }
}
void basic_numerical_methods::hafafficherprogressBaretape2(int i, int n)
{
    if (i>=n/25 && i<n/15 )
    {
        progressBar->setValue(40);
    }
    if (i>=n/15 && i<n/10 )
    {
        progressBar->setValue(45);
    }
    if (i>=n/10 && i<n/8 )
    {
        progressBar->setValue(50);
    }
    if (i>=n/8 && i<n/5 )
    {
        progressBar->setValue(65);
    }
    if (i>=n/5 && i<n/3 )
    {
        progressBar->setValue(75);
    }
    if (i>=n/2 && i<n/1.75 )
    {
        progressBar->setValue(95);
    }
    if (i>=n/1.75 && i<=n )
    {
        progressBar->setValue(97);
    }
}
void basic_numerical_methods::changervaleurpas()
{
    n=spinBox_nbre_pts_fx->text().toInt();
    double a=lineEdit_a->text().toDouble();
    double b=lineEdit_b->text().toDouble();
    double dx=(b-a)/(n-1);
    lineEdit_dx->setText(QString::number(dx));
    if (radioButton_fx_a_b_dx->isChecked())
    {
        spinBox_nbre_pts_tableau->setValue(n);
    }
}
void basic_numerical_methods::synchronisationdeuxspinBox()
{
    if (radioButton_fx_a_b_dx->isChecked())
    {
        n=spinBox_nbre_pts_fx->text().toInt();
        spinBox_nbre_pts_tableau->setValue(n);
    }
}
void basic_numerical_methods::nselonmethodechoisie()
{
    const int m=99999; //le nbre max de lines dans le tableau x(i) et y(i).
    n=spinBox_nbre_pts_fx->text().toInt();
    if (radioButton_simpson38->isChecked())
    {
        int ksimp38[m];ksimp38[0]=4;
        for (i=1; i<m ;i++)
        {
            ksimp38[i]=3*i+4;
            if (n<=ksimp38[i])
            {
                n=ksimp38[i];
                goto finboucle1;
            }
        }
finboucle1:;
        spinBox_nbre_pts_fx->setValue(n);
        spinBox_nbre_pts_fx->setSingleStep(3);
    }
    if (radioButton_simpson13->isChecked())
    {
        int ksimp13[m];ksimp13[0]=3;
        for (i=1; i<m ;i++)
        {
            ksimp13[i]=2*i+1;
            if (n<=ksimp13[i])
            {
                n=ksimp13[i];
                goto finboucle2;
            }
        }
finboucle2:;
        spinBox_nbre_pts_fx->setValue(n);
        spinBox_nbre_pts_fx->setSingleStep(2);
    }
    if (radioButton_trapezes->isChecked())
    {
        spinBox_nbre_pts_fx->setSingleStep(1);
    }
}
void basic_numerical_methods::remplirunelinevidetableau(int n)
{
    for (i=n; i<n+15 ;i++)
    {
        tableWidget_donnees->setItem(i,0,new QTableWidgetItem(""));
        tableWidget_donnees->setItem(i,1,new QTableWidgetItem(""));
    }
}
void basic_numerical_methods::cherchernbrecolumntableau(int n)
{
    const int m=99999; //le nbre max de lines dans le tableau x(i) et y(i).
    for (i=n; i<m ;i++)
    {
        QTableWidgetItem* item = tableWidget_donnees->item(i,0);
        if(!item || item->text().isEmpty() )
        {
            nbrecolumntableau=i;
            goto fin7;
        }
    }
fin7:;
    for (i=n; i<nbrecolumntableau ;i++)
    {
        tableWidget_donnees->setItem(i,2,new QTableWidgetItem(""));
    }
}
void basic_numerical_methods::convert()
{
    int degre=spinBox_degre->value();
    int mn=spinBox_mn->value();
    double sec=doubleSpinBox_sec->value();

    double decimal=(sec/3600)+(double(mn)/60)+degre;

    textBrowser_decimal->setText(QString::number(decimal));
}
/// for Android 1-6-2022
/// 1-7-2022
void basic_numerical_methods::help()
{
    QString link = "https://sites.google.com/site/courshaf";
    QDesktopServices::openUrl(QUrl(link));
}
#if defined(Q_OS_ANDROID)
void basic_numerical_methods::about()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("À propos"));
    msgBox.setTextFormat(Qt::RichText);
    QString pubabout=tr("Les programmes d'enseignement Informatique et Méthodes numériques 2021-2022 ; \n")+
            "Ver. "+ APP_VERSION +tr(" sur Linux, Windows et Android ; \n")+
            "("+ QString("%1").arg(BLD_DATE) +tr(") ; ")+
            "\n HAFIANE Mohamed ; e-mail for feedback: thakir.dz@gmail.com"+
            tr(" ou ")+
            "mohammed.hafiane@univ-saida.dz;\n\n"+
            tr("Page web : ")+
            "https://sites.google.com/site/courshaf; \n\n"+
            tr("Programmé avec C++ (mingw64) avec comme IDE (Qt Creator) et avec ")+
            " Qt Ver. " +QT_VERSION_STR +" ; (Function Parser for C++ v4.5.2).\n\n"+
            tr("Vous pouvez utiliser :")+"\n"+"^ * / + -\npow(x,5)\npi\nsqrt\nsin cos tan "+
            "cot\nasin acos atan\nsinh cosh tanh\nasinh acosh atanh\nlog log10 exp\nabs ; .....";
    msgBox.setText(pubabout);
    msgBox.exec();
}
#else
void basic_numerical_methods::about()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle(tr("À propos"));
    msgBox.setTextFormat(Qt::RichText);
    QString pubabout=tr("Les programmes d'enseignement Informatique et Méthodes numériques 2021-2022 ; \n")+
            "Ver. "+ APP_VERSION +tr(" sur Linux, Windows et Android ; \n")+
            "("+ QString("%1").arg(BLD_DATE) +tr(") ; ")+
            tr("\n HAFIANE Mohamed ; e-mail pour (feedback) <a href=\"mailto:thakir.dz@gmail.com?")+
            "subject=About%20Application%20basic_numerical_methods\">thakir.dz@gmail.com</a>"+
            tr(" ou ")+
            "<a href=\"mailto:mohammed.hafiane@univ-saida.dz?subject=About%20Application%20basic_numerical_methods\">mohammed.hafiane@univ-saida.dz</a>"+tr(" ;\n\n")+
            tr("Page web : ")+
            "<a href='https://sites.google.com/site/courshaf'>https://sites.google.com/site/courshaf</a>"+tr(" ;\n\n")+
            tr("Programmé avec C++ (mingw64) avec comme IDE (Qt Creator) et avec ")+
            " Qt Ver. " +QT_VERSION_STR +"; (Function Parser for C++ v4.5.2).";

    msgBox.setText(pubabout);
    msgBox.exec();
}
#endif
