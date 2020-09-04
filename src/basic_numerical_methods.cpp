// Les programmes Enseignement 14-15 / 19-20
// HAFIANE Mohamed le 1-8-2020 V 1.5.10
#include <QDesktopWidget>
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

basic_numerical_methods::basic_numerical_methods(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    label_version->setText("HAF-MED Ver: " APP_VERSION "");

    // HAF le 1-9-2009 pour Kubuntu seulement-------------
    setlocale(LC_NUMERIC, "C"); //avoir comme separateur decimal le point ...
    //----------------------------------------------------
    //tableWidget_donnees->setEditTriggers(QAbstractItemView::NoEditTriggers); //pour empecher l'edition du tableau

    connect(pushButton_about,SIGNAL(clicked()), this, SLOT(about()));
    connect(pushButton_close,SIGNAL(clicked()), this, SLOT(close()));
    connect(pushButton_Calculer_ColebrookWhite, SIGNAL(clicked()), this, SLOT(hafafficherColebrookWhite()));
    connect(pushButton_Calculer_Integration, SIGNAL(clicked()), this, SLOT(hafafficherIntegration()));
    connect(pushButton_Calculer_tracage_fx, SIGNAL(clicked()), this, SLOT(hafaffichertracagefx()));

    connect(spinBox_nbre_pts_fx, SIGNAL(editingFinished()), this, SLOT(nselonmethodechoisie()));
    connect(spinBox_nbre_pts_fx, SIGNAL(valueChanged(QString)), this, SLOT(changervaleurpas()));
    connect(lineEdit_a, SIGNAL(editingFinished()), this, SLOT(changervaleurpas()));
    connect(lineEdit_b, SIGNAL(editingFinished()), this, SLOT(changervaleurpas()));
    connect(spinBox_nbre_pts_tableau, SIGNAL(valueChanged(QString)), this, SLOT(synchronisationdeuxspinBox()));
    //---5-9-2009
    connect(radioButton_trapezes, SIGNAL(clicked()), this, SLOT(nselonmethodechoisie()));
    connect(radioButton_simpson13, SIGNAL(clicked()), this, SLOT(nselonmethodechoisie()));
    connect(radioButton_simpson38, SIGNAL(clicked()), this, SLOT(nselonmethodechoisie()));
    //-- convert HAF - 5-9-2009 -----------
    connect(pushButton_convert_decimal,SIGNAL(clicked()), this, SLOT(convert()));
    //-------------------------------------
    //-HAF 25-7-2020
    connect(buttonGroup_methodesEqtNonLineaire,SIGNAL(buttonClicked(int)), this, SLOT(choixmethodeeqtnonlineaire(int)));
    connect(pushButton_Calculer_methodesEqtNonLineaire, SIGNAL(clicked()), this, SLOT(hafresolutioneqtnonlineaire()));
    lineEdit_x1->hide();
    label_x1->hide();
    //-HAF 5-8-2020
    QRegExp double_rx("[+]?[0-9]*\\.?[0-9]+([eE][-]?[0-9]+)?"); //sans - et e-
    lineEdit_tolerance_eqtnonlineaire->setValidator(new QRegExpValidator(double_rx,this));
    QRegExp double_x0("[+-]?[0-9]*\\.?[0-9]+([eE][+-]?[0-9]+)?");
    lineEdit_x0->setValidator(new QRegExpValidator(double_x0,this));
    lineEdit_x1->setValidator(new QRegExpValidator(double_x0,this));
    connect(pushButton_Copier_TableauEqtNonLineaire,SIGNAL(clicked()), this, SLOT(copy_tableWidget_donnees_eqtnonlineaire()));
    pushButton_Copier_TableauEqtNonLineaire->hide();
    //-HAF 7-8-2020
    connect(buttonGroup_methodeeqtdifferentielle,SIGNAL(buttonClicked(int)), this, SLOT(choixmethodeeqtdifferentielle(int)));
    connect(pushButton_Calculer_methodeeqtdifferentielle, SIGNAL(clicked()), this, SLOT(hafresolutioneqtdifferentielle()));
    connect(pushButton_Copier_Tableaueqtdifferentielle,SIGNAL(clicked()), this, SLOT(copy_tableWidget_donnees_eqtdifferentielle()));
    pushButton_Copier_Tableaueqtdifferentielle->hide();
    connect(spinBox_nptseqtdifferentielle, SIGNAL(valueChanged(QString)), this, SLOT(changervaleurpas_eqtdifferentielle()));
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
    fparserfx.AddConstant("pi", 3.1415926535897932);
    fparsergx.AddConstant("pi", 3.1415926535897932);
    fparserfprime.AddConstant("pi", 3.1415926535897932);
    fparserfprimex.AddConstant("pi", 3.1415926535897932);
    fparseryprim.AddConstant("pi", 3.1415926535897932);
    fparserfxintegrale.AddConstant("pi", 3.1415926535897932);
    //
    connect(lineEdit_yprime_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfunctionyprim()));
    connect(lineEdit_a_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_a_methodeeqtdifferentielle()));
    connect(lineEdit_b_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_b_methodeeqtdifferentielle()));
    connect(lineEdit_y0_methodeeqtdifferentielle, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_y0_methodeeqtdifferentielle()));
    lineEdit_a_methodeeqtdifferentielle->setValidator(new QRegExpValidator(double_x0,this));
    lineEdit_b_methodeeqtdifferentielle->setValidator(new QRegExpValidator(double_x0,this));
    lineEdit_y0_methodeeqtdifferentielle->setValidator(new QRegExpValidator(double_x0,this));
    //
    connect(lineEdit_fx_integ, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfx_integ()));
    connect(lineEdit_a, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_a_integ()));
    connect(lineEdit_b, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_b_integ()));
    lineEdit_a->setValidator(new QRegExpValidator(double_x0,this));
    lineEdit_b->setValidator(new QRegExpValidator(double_x0,this));
    //
    connect(lineEdit_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedinfx_tracage()));
    connect(lineEdit_a_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_a_tracage()));
    connect(lineEdit_b_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_b_tracage()));
    connect(lineEdit_dx_tracage_fx, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_dx_tracage()));
    lineEdit_a_tracage_fx->setValidator(new QRegExpValidator(double_x0,this));
    lineEdit_b_tracage_fx->setValidator(new QRegExpValidator(double_x0,this));
    lineEdit_dx_tracage_fx->setValidator(new QRegExpValidator(double_rx,this));
    //
    lineEdit_Diametre->setValidator(new QRegExpValidator(double_rx,this));
    lineEdit_Ruguosite->setValidator(new QRegExpValidator(double_rx,this));
    lineEdit_Debit->setValidator(new QRegExpValidator(double_rx,this));
    //
    connect(lineEdit_Diametre, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_Diametre()));
    connect(lineEdit_Ruguosite, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_Ruguosite()));
    connect(lineEdit_Debit, SIGNAL(textChanged(const QString)), this, SLOT(textChangedin_Debit()));



}
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
    fparseryprim.AddConstant("pi", 3.1415926535897932);
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
void basic_numerical_methods::EvalErrorfunHAF(int fparser_EvalError, QString fx, double x)
{
    QString message;
    if (fparser_EvalError!=0){
        switch (fparser_EvalError) {
        case 1:
            message="division by zero";
            break;
        case 2:
            message="sqrt error (sqrt of a negative value)";
            break;
        case 3:
            message="log error (logarithm of a negative value)";
            break;
        case 4:
            message="trigonometric error (asin or acos of illegal value)";
            break;
        case 5:
            message="maximum recursion level in eval() reached";
            break;
        }
        int ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
        message+=" in x="+QString::number(x,'f',ndecimaux);
        QMessageBox errorMessage;
        errorMessage.setFixedSize(500, 200);
        errorMessage.critical(this, "Error in "+ QString("%1").arg(fx),message);
        errorMessage.show();
        return;
    }
}
void basic_numerical_methods::textChangedinfunctionfx()
{
    fx=lineEdit_fx_eqt_non_lineaire->text();
    fparserfx.AddConstant("pi", 3.1415926535897932);
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
    fparsergx.AddConstant("pi", 3.1415926535897932);
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
    fparserfprime.AddConstant("pi", 3.1415926535897932);
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

    double valsa[1];
    double valsb[1];
    while(true)
    {
        yprim=lineEdit_yprime_methodeeqtdifferentielle->text();
        int res = fparseryprim.Parse(yprim.toStdString(), "x,y");
        if(res < 0) break;
        if (strlen(fparseryprim.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, "Error in f(x,y)",
                                  fparseryprim.ErrorMsg());
            errorMessage.show();
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
    int ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
    int n=spinBox_nptseqtdifferentielle->text().toInt();
    progressBar_eqtdifferentielle->setMaximum(n);
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
    x[0]=a;
    y[0]=lineEdit_y0_methodeeqtdifferentielle->text().toDouble();
    int i=0;
    tableWidget_donnees_eqtdifferentielle->setItem(0,0,new QTableWidgetItem(QString::number(i)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,1,new QTableWidgetItem(QString::number(x[0],'f',ndecimaux)));
    tableWidget_donnees_eqtdifferentielle->setItem(0,2,new QTableWidgetItem(QString::number(y[0],'f',ndecimaux)));

    double k1,k2,k3,k4,k5;
    for (i = 1 ; i <n ; i++){
        x[i]=x[0]+i*dx;
    }
    double error_truncation[n];
    for (i=1; i<n; i++){
        progressBar_eqtdifferentielle->setValue(i);
        double variablesk1[2] = {x[i-1],y[i-1]};
        k1=1./3*dx*fparseryprim.Eval(variablesk1);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk2[2] = {x[i-1],y[i-1]+k1};
        k2=1./3*dx*fparseryprim.Eval(variablesk2);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk3[2] = {x[i-1],y[i-1]+k2/2+k2/2};
        k3=1./3*dx*fparseryprim.Eval(variablesk3);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk4[2] = {x[i-1],y[i-1]+3./8*k1+9./3*k3};
        k4=1./3*dx*fparseryprim.Eval(variablesk4);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i-1);
            i-=1;
            break;
        }
        double variablesk5[2] = {x[i-1],y[i-1]+3./2*k1-9./2*k3+6*k4};
        k5=1./3*dx*fparseryprim.Eval(variablesk5);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
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

    double valsa[1];
    double valsb[1];
    while(true)
    {
        yprim=lineEdit_yprime_methodeeqtdifferentielle->text();
        int res = fparseryprim.Parse(yprim.toStdString(), "x,y");
        if(res < 0) break;
        if (strlen(fparseryprim.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, "Error in f(x,y)",
                                  fparseryprim.ErrorMsg());
            errorMessage.show();
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
    int ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
    int n=spinBox_nptseqtdifferentielle->text().toInt();
    progressBar_eqtdifferentielle->setMaximum(n);
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
    x[0]=a;
    y[0]=lineEdit_y0_methodeeqtdifferentielle->text().toDouble();
    int i=0;
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
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        double variablesk2[2] = {x[i-1]+dx/2,y[i-1]+k1/2};
        k2=dx*fparseryprim.Eval(variablesk2);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]+dx/2);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        double variablesk3[2] = {x[i-1]+dx/2,y[i-1]+k2/2};
        k3=dx*fparseryprim.Eval(variablesk3);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]+dx/2);
        if(fparseryprim_EvalError!=0) {
            tableWidget_donnees_eqtdifferentielle->removeRow(i);
            break;
        }
        double variablesk4[2] = {x[i-1]+dx,y[i-1]+k3};
        k4=dx*fparseryprim.Eval(variablesk4);
        fparseryprim_EvalError=fparseryprim.EvalError();
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]+dx);
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
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, "Error in f(x,y)",
                                  fparseryprim.ErrorMsg());
            errorMessage.show();
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
    int ndecimaux=spinBox_nbredecimaux_eqtdifferentielle->text().toInt();
    int n=spinBox_nptseqtdifferentielle->text().toInt();
    progressBar_eqtdifferentielle->setMaximum(n);
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
    x[0]=a;
    y[0]=lineEdit_y0_methodeeqtdifferentielle->text().toDouble();
    int i=0;
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
        EvalErrorfunHAF(fparseryprim_EvalError,"f(x,y)",x[i-1]);
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
    int n=spinBox_nptseqtdifferentielle->text().toInt();
    double a=lineEdit_a_methodeeqtdifferentielle->text().toDouble();
    double b=lineEdit_b_methodeeqtdifferentielle->text().toDouble();
    double dx=(b-a)/(n-1);
    lineEdit_dx_methodeeqtdifferentielle->setText(QString::number(dx));
}
void basic_numerical_methods::copy_tableWidget_donnees_eqtdifferentielle()
{
    QString resultatsfr0="";
    for (int j=0; j<nbrecolumn_tableWidget_donnees_eqtdifferentielle ;j++)
    {
        resultatsfr0+=tableWidget_donnees_eqtdifferentielle->horizontalHeaderItem(j)->text()+"\t";
    }
    resultatsfr0+="\n";
    for (int i=0; i<=nbrerow_tableWidget_donnees_eqtdifferentielle ;i++)
    {
        for (int j=0; j<nbrecolumn_tableWidget_donnees_eqtdifferentielle ;j++)
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
    int id=buttonGroup_methodeeqtdifferentielle->checkedId();
    switch (id) {
    case -2:
        if (valida_eqtdifferentielle && validb_eqtdifferentielle && validy0_eqtdifferentielle){
        hafresolutioneqtdifferentielle_Euler_explicite();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez a ou/et b ou/et y0");
            resultatsMessage.show();
        }
        break;

    case -3:
        if (valida_eqtdifferentielle && validb_eqtdifferentielle && validy0_eqtdifferentielle){
        hafresolutioneqtdifferentielle_Runge_Kutta();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez a ou/et b ou/et y0");
            resultatsMessage.show();
        }
        break;

    case -4:
        if (valida_eqtdifferentielle && validb_eqtdifferentielle && validy0_eqtdifferentielle){
        hafresolutioneqtdifferentielle_Kutta_Merson();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez a ou/et b ou/et y0");
            resultatsMessage.show();
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
        lineEdit_tolerance_eqtnonlineaire->setToolTip("f(xi)<=Tolérance");
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
        lineEdit_tolerance_eqtnonlineaire->setToolTip("f(xi)<=Tolérance");
        break;

    case -4:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(2);
        label_x0->setText("x0");
        label_x1->setText("x1");
        lineEdit_x1->show();
        label_x1->show();
        stackedWidget_gx_fprime->hide();
        lineEdit_tolerance_eqtnonlineaire->setToolTip("f(xi)<=Tolérance");
        break;

    case -5:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(3);
        lineEdit_x1->show();
        label_x1->show();
        label_x0->setText("a");
        label_x1->setText("b");
        stackedWidget_gx_fprime->hide();
        lineEdit_tolerance_eqtnonlineaire->setToolTip("(b-a)<=Tolérance");
        break;

    case -6:
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(4);
        lineEdit_x1->show();
        label_x1->show();
        label_x0->setText("a");
        label_x1->setText("b");
        stackedWidget_gx_fprime->hide();
        lineEdit_tolerance_eqtnonlineaire->setToolTip("f(r)<=Tolérance");
        break;
    }
}
//--------------------------HAF 25-07-2020----------------------
void basic_numerical_methods::copy_tableWidget_donnees_eqtnonlineaire()
{
    QString resultatsfr0="";
    for (int j=0; j<nbrecolumn_tableWidget_donnees_eqtnonlineaire ;j++)
    {
        resultatsfr0+=tableWidget_donnees_eqtnonlineaire->horizontalHeaderItem(j)->text()+"\t";
    }
    resultatsfr0+="\n";
    for (int i=0; i<=nbrerow_tableWidget_donnees_eqtnonlineaire ;i++)
    {
        for (int j=0; j<nbrecolumn_tableWidget_donnees_eqtnonlineaire ;j++)
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

    double valsa[1];
    double valsb[1];
    double valsr[1];
    int ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    double a=lineEdit_x0->text().toDouble();
    double b=lineEdit_x1->text().toDouble();
    if(a==std::numeric_limits<double>::infinity() || a==-std::numeric_limits<double>::infinity() ||
            b==std::numeric_limits<double>::infinity() || b==-std::numeric_limits<double>::infinity()
            ){
        QMessageBox::critical(this, "Erreur",
                              "La valeur de a ou/et b dépasse les limites admissibles!");
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();
    double xm;
    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, "Error in f(x)",
                                  fparserfx.ErrorMsg());
            errorMessage.show();
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
    EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a);
    double fb=fparserfx.Eval(valsb);
    fparserfxb_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxb_EvalError,"f(x=b)",b);
    double r=b-fb*(a-b)/(fa-fb);
    valsr[0]=r;
    double faxfb=fa*fb;

    if ((faxfb>=0 || a>=b) && (fparserfxa_EvalError==0 && fparserfxb_EvalError==0))
    {
        QMessageBox::critical(this, "Erreur",
                              "Il faut que (f(a)*f(b)<0 ; a<b) et f(x) doit être monotone entre a et b!");
        return ;
    }

    double fxaxfxr;
    double fxbxfxr;
    int i=0;
    double fr=fparserfx.Eval(valsr);
    fparserfxr_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxr_EvalError,"f(x=r)",r);

    while(fabs(fr)>eps && i<nmax && fparserfxr_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        fa=fparserfx.Eval(valsa);
        fparserfxa_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a);
        fb=fparserfx.Eval(valsb);
        fparserfxb_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxb_EvalError,"f(x=b)",b);
        r=b-fb*(a-b)/(fa-fb);
        valsr[0]=r;
        fr=fparserfx.Eval(valsr);
        fparserfxr_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxr_EvalError,"f(x=r)",r);

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
    if(fparserfxa_EvalError==0 && fparserfxb_EvalError==0 && fparserfxr_EvalError==0 && i<nmax && !std::isnan(r) && r!=std::numeric_limits<double>::infinity() && r!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i-1, 3);
        QMessageBox resultatsMessage;
        resultatsMessage.information(this, "Résultats","La méthode converge vers x="+
                                     QString::number(r,'f',ndecimaux));
        resultatsMessage.show();
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Le nombre maximal d'itérations a été atteint sans qu'aucune solution satisfaisante "
                                 "(la tolérance) ait été trouvée "
                                 ": Peut-être que vous devez changer a ou/et b ou augmenter la tolérance ou le nombre maximal d'itérations!");
        resultatsMessage.show();
    }else if(fparserfxa_EvalError!=0 || fparserfxb_EvalError!=0 || fparserfxr_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes!");
        resultatsMessage.show();
    }else{
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "La méthode diverge  "
                                 ": Peut-être que vous devez changer a ou/et b");
        resultatsMessage.show();
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_dichotomie()
{
    progressBar_eqtnonlineaire->setValue(0);

    double valsa[1];
    double valsb[1];
    double valsxm[1];
    int ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    double a=lineEdit_x0->text().toDouble();
    double b=lineEdit_x1->text().toDouble();
    if(a==std::numeric_limits<double>::infinity() || a==-std::numeric_limits<double>::infinity() ||
            b==std::numeric_limits<double>::infinity() || b==-std::numeric_limits<double>::infinity()
            ){
        QMessageBox::critical(this, "Erreur",
                              "La valeur de a ou/et b dépasse les limites admissibles!");
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();
    double xm;
    while(true)
    {
        fx=lineEdit_fx_eqt_non_lineaire->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, "Error in f(x)",
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
    EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a);
    double fb=fparserfx.Eval(valsb);
    fparserfxb_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfxb_EvalError,"f(x=b)",b);

    double faxfb=fa*fb;

    if ((faxfb>=0 || a>=b) && fparserfxa_EvalError==0 && fparserfxb_EvalError==0)
    {
        QMessageBox::critical(this, "Erreur",
                              "Il faut que (f(a)*f(b)<0 ; a<b) et f(x) doit être monotone entre a et b!");
        return ;
    }

    int i=0;
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
        EvalErrorfunHAF(fparserfxa_EvalError,"f(x=a)",a);
        fm=fparserfx.Eval(valsxm);
        fparserfxm_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfxm_EvalError,"f(x=xm)",xm);

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
    if(fparserfxa_EvalError==0 && fparserfxb_EvalError==0 && fparserfxm_EvalError==0 && i<nmax && !std::isnan(xm) && xm!=std::numeric_limits<double>::infinity() && xm!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i-1, 3);
        QMessageBox resultatsMessage;
        resultatsMessage.information(this, "Résultats","La méthode converge vers x="+
                                     QString::number(xm,'f',ndecimaux));
        resultatsMessage.show();
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Le nombre maximal d'itérations a été atteint sans qu'aucune solution satisfaisante "
                                 "(la tolérance) ait été trouvée : Peut-être que vous devez changer a ou/et b ou "
                                 "augmenter la tolérance ou le nombre maximal d'itérations!");
        resultatsMessage.show();
    }else if(fparserfxa_EvalError!=0 || fparserfxb_EvalError!=0 || fparserfxm_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes!");
        resultatsMessage.show();
    }else{
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "La méthode diverge  "
                                 ": Peut-être que vous devez changer a ou/et b");
        resultatsMessage.show();
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_secante()
{
    progressBar_eqtnonlineaire->setValue(0);

    double valsi[1];
    double valsimoisun[1];
    int ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    int i=0;
    double x[nmax];
    x[0]=lineEdit_x0->text().toDouble();
    x[1]=lineEdit_x1->text().toDouble();
    if(x[0]==std::numeric_limits<double>::infinity() || x[0]==-std::numeric_limits<double>::infinity() ||
            x[1]==std::numeric_limits<double>::infinity() || x[1]==-std::numeric_limits<double>::infinity()
            ){
        QMessageBox::critical(this, "Erreur",
                              "La valeur de x0 ou/et x1 dépasse les limites admissibles!");
        return ;
    }
    double eps=lineEdit_tolerance_eqtnonlineaire->text().toDouble();

    if (x[0]==x[1])
    {
        QMessageBox::critical(this, "Erreur",
                              "Il faut que x0 soit différant de x1!");
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
            errorMessage.critical(this, "Error in f(x)",
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
    EvalErrorfunHAF(fparserfx_EvalError,"f(x=x[0])",x[0]);
    valsi[0]=x[1];
    valsimoisun[0]=x[0];
    tableWidget_donnees_eqtnonlineaire->setItem(1,0,new QTableWidgetItem(QString::number(1)));
    tableWidget_donnees_eqtnonlineaire->setItem(1,1,new QTableWidgetItem(QString::number(x[1],'f',ndecimaux)));
    tableWidget_donnees_eqtnonlineaire->setItem(1,2,new QTableWidgetItem(QString::number(fparserfx.Eval(valsi),'f',ndecimaux)));
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x=x[1])",x[1]);
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
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i-1]);
        valeurfxi=fparserfx.Eval(valsi);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i]);
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
    if(fparserfx_EvalError==0 && i<nmax  && !std::isnan(x[i-1]) && x[i-1]!=std::numeric_limits<double>::infinity() && x[i-1]!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i-1, 1);
        QMessageBox resultatsMessage;
        resultatsMessage.information(this, "Résultats","La méthode converge vers x="+
                                     QString::number(x[i-1],'f',ndecimaux));
        resultatsMessage.show();
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Le nombre maximal d'itérations a été atteint sans qu'aucune "
                                 "solution satisfaisante (la tolérance) ait été trouvée : Peut-être que vous "
                                 "devez changer x0 ou/et x1 ou augmenter la tolérance ou le nombre maximal d'itérations!");
        resultatsMessage.show();
    }else if(fparserfx_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes!");
        resultatsMessage.show();
    }else{
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "La méthode diverge  "
                                 ": Peut-être que vous devez changer x0 ou/et x1");
        resultatsMessage.show();
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_newtonraphson()
{
    progressBar_eqtnonlineaire->setValue(0);

    double vals[1];
    int ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    int i=0;
    double x[nmax];
    x[0]=lineEdit_x0->text().toDouble();
    if(x[0]==std::numeric_limits<double>::infinity() || x[0]==-std::numeric_limits<double>::infinity()){
        QMessageBox::critical(this, "Erreur",
                              "La valeur de x0 dépasse les limites admissibles!");
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
            errorMessage.critical(this, "Error in f(x)",
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
            errorMessage.critical(this, "Error in f'(x)",
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
    EvalErrorfunHAF(fparserfprimex_EvalError,"f'(x)",x[i]);
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i]);
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
        EvalErrorfunHAF(fparserfprimex_EvalError,"f'(x)",x[i+1]);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i+1]);
        i=i+1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+2);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i;
    if(fparserfx_EvalError==0 && fparserfprimex_EvalError==0 && i<nmax && !std::isnan(x[i]) && x[i]!=std::numeric_limits<double>::infinity() && x[i]!=-std::numeric_limits<double>::infinity() ){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i, 1);
        QMessageBox resultatsMessage;
        resultatsMessage.information(this, "Résultats","La méthode converge vers x="+
                                     QString::number(x[i],'f',ndecimaux));
        resultatsMessage.show();
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Le nombre maximal d'itérations a été atteint sans qu'aucune solution satisfaisante "
                                 "(la tolérance) ait été trouvée : Peut-être que vous devez changer x0 ou augmenter "
                                 "la tolérance ou le nombre maximal d'itérations!");
        resultatsMessage.show();
    }else if(fparserfx_EvalError!=0 || fparserfprimex_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes!");
        resultatsMessage.show();
    }else{
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "La méthode diverge  "
                                 ": Peut-être que vous devez changer x0!");
        resultatsMessage.show();
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire_ptfixe()
{
    progressBar_eqtnonlineaire->setValue(0);

    double vals[1];
    int ndecimaux=spinBox_nbredecimaux_eqtnonlineaire->text().toInt();
    int nmax=spinBox_nmax_eqtnonlineaire->text().toInt();
    progressBar_eqtnonlineaire->setMaximum(nmax);
    int i=0;
    double x[nmax];
    x[0]=lineEdit_x0->text().toDouble();
    if(x[0]==std::numeric_limits<double>::infinity() || x[0]==-std::numeric_limits<double>::infinity()){
        QMessageBox::critical(this, "Erreur",
                              "La valeur de x0 dépasse les limites admissibles!");
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
            errorMessage.critical(this, "Error in f(x)",
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
            errorMessage.critical(this, "Error in g(x)",
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
    EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i]);
    fparserfx_EvalError=fparserfx.EvalError();
    EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i]);
    while (fabs(fparserfx.Eval(vals))>eps && i<nmax && fparserfx_EvalError==0 && fparsergx_EvalError==0)
    {
        progressBar_eqtnonlineaire->setValue(i);
        vals[0]=x[i];
        x[i+1]=fparsergx.Eval(vals);
        fparsergx_EvalError=fparsergx.EvalError();
        EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i]);
        vals[0]=x[i+1];
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,0,new QTableWidgetItem(QString::number(i+1)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,1,new QTableWidgetItem(QString::number(x[i+1],'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,2,new QTableWidgetItem(QString::number(fparsergx.Eval(vals),'f',ndecimaux)));
        tableWidget_donnees_eqtnonlineaire->setItem(i+1,3,new QTableWidgetItem(QString::number(fparserfx.Eval(vals),'f',ndecimaux)));
        fparsergx_EvalError=fparsergx.EvalError();
        EvalErrorfunHAF(fparsergx_EvalError,"g(x)",x[i+1]);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i+1]);
        i=i+1;
        tableWidget_donnees_eqtnonlineaire->setRowCount(i+2);
    }
    tableWidget_donnees_eqtnonlineaire->resizeColumnsToContents();
    tableWidget_donnees_eqtnonlineaire->verticalHeader()->hide();
    progressBar_eqtnonlineaire->setValue(nmax);
    nbrerow_tableWidget_donnees_eqtnonlineaire=i;
    if(fparserfx_EvalError==0 && fparsergx_EvalError==0 && i<nmax && !std::isnan(x[i]) && x[i]!=std::numeric_limits<double>::infinity() && x[i]!=-std::numeric_limits<double>::infinity()){
        tableWidget_donnees_eqtnonlineaire->setCurrentCell(i, 1);
        QMessageBox resultatsMessage;
        resultatsMessage.information(this, "Résultats","La méthode converge vers x="+
                                     QString::number(x[i],'f',ndecimaux));
        resultatsMessage.show();
        pushButton_Copier_TableauEqtNonLineaire->show();
    }else if(i>=nmax){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Le nombre maximal d'itérations a été atteint sans qu'aucune solution satisfaisante "
                                 "(la tolérance) ait été trouvée : Peut-être que vous devez changer "
                                 "g(x) ou/et x0! (ou augmenter la tolérance ou le nombre maximal d'itérations)");
        resultatsMessage.show();
    }else if(fparserfx_EvalError!=0 || fparsergx_EvalError!=0){
        tableWidget_donnees_eqtnonlineaire->clear();
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes!");
        resultatsMessage.show();
    }else{
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "La méthode diverge  "
                                 ": Peut-être que vous devez changer g(x) ou/et x0!");
        resultatsMessage.show();
    }
    tableWidget_donnees_eqtnonlineaire->scrollToBottom();
}
void basic_numerical_methods::hafresolutioneqtnonlineaire()
{
    fparserfx_EvalError=0;
    fparsergx_EvalError=0;
    fparserfprimex_EvalError=0;

    tableWidget_donnees_eqtnonlineaire->clear();
    pushButton_Copier_TableauEqtNonLineaire->hide();
    int id=stackedWidget_methodeeqtnonlineaire->currentIndex();
    switch (id) {
    case 0:
        if (validx0 && validtolerance){
            hafresolutioneqtnonlineaire_ptfixe();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez x0 ou/et Tolérance");
            resultatsMessage.show();
        }
        break;

    case 1:
        if (validx0 && validtolerance){
        hafresolutioneqtnonlineaire_newtonraphson();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez x0 ou/et Tolérance");
            resultatsMessage.show();
        }
        break;

    case 2:
        if (validx0 && validx1 && validtolerance){
        hafresolutioneqtnonlineaire_secante();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez x0 ou/et x1 ou/et Tolérance");
            resultatsMessage.show();
        }
        break;

    case 3:
        if (validx0 && validx1 && validtolerance){
        hafresolutioneqtnonlineaire_dichotomie();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez a ou/et b ou/et Tolérance");
            resultatsMessage.show();
        }
        break;

    case 4:
        if (validx0 && validx1 && validtolerance){
        hafresolutioneqtnonlineaire_fausseposition();
        }else{
            QMessageBox resultatsMessage;
            resultatsMessage.warning(this, "Résultats",
                                     "Données incorrectes! Vérifiez a ou/et b ou/et Tolérance");
            resultatsMessage.show();
        }
        break;
    }
}
//--------------------------HAF 17-05-2015----------------------
void basic_numerical_methods::plotHAF( QVector<double> x,  QVector<double> y)
{
    customPlot->addGraph();
    customPlot->graph(0)->setName("Confidence Band 68%");
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("f(x)");
    customPlot->xAxis->setRange(lineEdit_a_tracage_fx->text().toDouble(), lineEdit_b_tracage_fx->text().toDouble());
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    customPlot->graph(0)->rescaleAxes();
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->legend->setVisible(false);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
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
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes! Vérifiez Diamètre ou/et Rugosité ou/et Débit");
        resultatsMessage.show();
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

    double pi=3.1415926535897931;
    double nul=0.000001;
    double S=pi*pow(D,2)/4;
    double Umoy=Q/S;
    double Re=Umoy*D/nul;
    double a=0.000001;
    double b=3;

    if (haff(a,Ks,D,Re)*haff(b,Ks,D,Re)<0 and Re>=2500)
    {
        double c=(a+b)/2;
        int i=1;
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

        QString outputtext1;
        outputtext1="Lambda est "+QString::number(c)+" avec Re égal à "+QString::number(Re);
        lambda_textBrowser->setText(outputtext1);
    }
    else
    {
        QString outputtext2;
        if (Re<2500)
        {
            outputtext2="L'écoulement n'est pas turbulent, donc l'équation de Colebrook-White n'est pas valable ! Re : "+QString::number(Re);
        }
        else
        {
            outputtext2="Erreur de données !!!";
        }
        lambda_textBrowser->setText(outputtext2);
    }

}
void basic_numerical_methods::hafaffichertracagefx()
{
    if (!valida_tracage || !validb_tracage || !validdx_tracage){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes! Vérifiez a ou/et b ou/et dx");
        resultatsMessage.show();
        return;
    }
    fparserfx_EvalError=0;
    textBrowser_resultats_lineEdit_tracage_fx->setText("");
    customPlot->clearGraphs();
    while(true)
    {
        fx=lineEdit_tracage_fx->text();
        int res = fparserfx.Parse(fx.toStdString(), "x");
        if(res < 0) break;
        if (strlen(fparserfx.ErrorMsg())!=0){
            QMessageBox errorMessage;
            errorMessage.setFixedSize(500, 200);
            errorMessage.critical(this, "Error in f(x)",
                                  fparserfx.ErrorMsg());
            errorMessage.show();
            break ;
        }
        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparserfx.ErrorMsg() << "\n\n";
    }
    double a=lineEdit_a_tracage_fx->text().toDouble();
    double b=lineEdit_b_tracage_fx->text().toDouble();
    double dx=lineEdit_dx_tracage_fx->text().toDouble();
    int n=int((b-a)/dx+1);
    if (a>=b)
    {
        QMessageBox::critical(this, "Erreur",
                              "Il faut que a<b!");
        return ;
    }
debut1:;
    QVector<double> x(n);
    QVector<double> y(n);
    double vals[1];
    QString outputtext7;
    outputtext7="";
    int i=0;
    for(i=0; i<n; i++)
    {
        vals[0]=a+i*dx;
        x[i]=vals[0];
        y[i]=fparserfx.Eval(vals);
        fparserfx_EvalError=fparserfx.EvalError();
        EvalErrorfunHAF(fparserfx_EvalError,"f(x)",x[i]);
        if(fparserfx_EvalError!=0) {
            n=i;
            break;
        }
        outputtext7=outputtext7+"f("+QString::number(x[i])+") = "+QString::number(y[i])+"\n";
    }
    if (x[n-1]<b && fparserfx_EvalError==0)
    {
        n=n+1;
        goto debut1;
    }
    for( int g=0; g<customPlot->graphCount(); g++ )
    {
        customPlot->graph(g)->data().clear();
    }
    customPlot->replot();
    textBrowser_resultats_lineEdit_tracage_fx->setText(outputtext7);
    QVector<double> xnew(n);
    QVector<double> ynew(n);
    for(i=0; i<n; i++)
    {
        xnew[i]=x[i];
        ynew[i]=y[i];
    }
    plotHAF(xnew,ynew);



}
void basic_numerical_methods::hafafficherIntegration()
{
    if (!valida_integ || !validb_integ){
        QMessageBox resultatsMessage;
        resultatsMessage.warning(this, "Résultats",
                                 "Données incorrectes! Vérifiez a ou/et b");
        resultatsMessage.show();
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
            errorMessage.critical(this, "Error in f(x)",
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
    int n;
    double a,b,dx;

    int i;
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
            if(tableWidget_donnees->item(i,0)->text().isEmpty() || tableWidget_donnees->item(i,1)->text().isEmpty())
            {
                QString outputtexta;
                outputtexta="Veillez remplir svp tous le tableau des données (x et y) jusqu'à la ligne numéro :  "+QString::number(n);
                QMessageBox::warning(this,"Erreur données !!!",outputtexta);
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
                QMessageBox::critical(this, "Erreur",
                                      "Il faut que a<b!");
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
                EvalErrorfunHAF(fparserfxintegrale_EvalError,"f(x)",x[i]);
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
                remplireunelinevidetableau(n);
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

        QString outputtext1;
        if (radioButton_tableau_xy->isChecked())
        {
            outputtext1="L'intégrale (selon le tableau au dessus) entre "+QString::number(x[0])+" et "+QString::number(x[n-1])+" avec un pas de "+QString::number(x[1]-x[0])+" par la méthode des trapèzes est égale à "+QString::number(I);
        }
        else if (radioButton_fx_a_b_dx->isChecked())
        {
            a=lineEdit_a->text().toDouble();
            b=lineEdit_b->text().toDouble();
            dx=lineEdit_dx->text().toDouble();
            fx=lineEdit_fx_integ->text();
            outputtext1="L'intégrale de f(x)="+fx+" entre "+QString::number(a)+" et "+QString::number(b)+" avec un pas de "+QString::number(dx)+" par la méthode des trapèzes est égale à "+QString::number(I);
        }
        integral_textBrowser->setText(outputtext1);
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
                QMessageBox::critical(this, "Erreur",
                                      "Il faut que a<b!");
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
                EvalErrorfunHAF(fparserfxintegrale_EvalError,"f(x)",x[i]);
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
                int k=0;
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
                    remplireunelinevidetableau(n);
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
            QString outputtext2;
            if (radioButton_tableau_xy->isChecked())
            {
                outputtext2="L'intégrale (selon le tableau au dessus) entre "+QString::number(x[0])+" et "+QString::number(x[n-1])+" avec un pas de "+QString::number(x[1]-x[0])+" par la méthode SIMPSON 1/3 est égale à "+QString::number(I);

            }
            else if (radioButton_fx_a_b_dx->isChecked())
            {
                a=lineEdit_a->text().toDouble();
                b=lineEdit_b->text().toDouble();
                dx=lineEdit_dx->text().toDouble();
                fx=lineEdit_fx_integ->text();
                outputtext2="L'intégrale de f(x)="+fx+" entre "+QString::number(a)+" et "+QString::number(b)+" avec un pas de "+QString::number(dx)+" par la méthode SIMPSON 1/3 est égale à "+QString::number(I);
            }
            integral_textBrowser->setText(outputtext2);
            tableWidget_donnees->resizeColumnsToContents();
        }
        else
        {
            QMessageBox::warning(this,"Erreur données !!!","Le nombre des x et y (Nbre des pts) n'est pas compatible avec la méthode d'intégration numérique choisie (n=2m+1 avec m=0 à l'infini).");
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
                QMessageBox::critical(this, "Erreur",
                                      "Il faut que a<b!");
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
                EvalErrorfunHAF(fparserfxintegrale_EvalError,"f(x)",x[i]);
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
                int k=0;
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
                    remplireunelinevidetableau(n);
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
            QString outputtext3;
            if (radioButton_tableau_xy->isChecked())
            {
                outputtext3="L'intégrale (selon le tableau au dessus) entre "+QString::number(x[0])+" et "+QString::number(x[n-1])+" avec un pas de "+QString::number(x[1]-x[0])+" par la méthode SIMPSON 3/8 est égale à "+QString::number(I);
            }
            else if (radioButton_fx_a_b_dx->isChecked())
            {
                a=lineEdit_a->text().toDouble();
                b=lineEdit_b->text().toDouble();
                dx=lineEdit_dx->text().toDouble();
                fx=lineEdit_fx_integ->text();
                outputtext3="L'intégrale de f(x)="+fx+" entre "+QString::number(a)+" et "+QString::number(b)+" avec un pas de "+QString::number(dx)+" par la méthode SIMPSON 3/8 est égale à "+QString::number(I);
            }
            integral_textBrowser->setText(outputtext3);
            tableWidget_donnees->resizeColumnsToContents();
        }
        else
        {
            QMessageBox::warning(this,"Erreur données !!!","Le nombre des x et y (Nbre des pts) n'est pas compatible avec la méthode d'intégration numérique choisie (n=3m+4 avec m=0 à l'infini).");
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
    int n=spinBox_nbre_pts_fx->text().toInt();
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
        int n=spinBox_nbre_pts_fx->text().toInt();
        spinBox_nbre_pts_tableau->setValue(n);
    }
}
void basic_numerical_methods::nselonmethodechoisie()
{
    const int m=99999; //le nbre max de lines dans le tableau x(i) et y(i).
    int n=spinBox_nbre_pts_fx->text().toInt();
    if (radioButton_simpson38->isChecked())
    {
        int i;
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
        int i;
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
void basic_numerical_methods::remplireunelinevidetableau(int n)
{
    int i;
    for (i=n; i<n+15 ;i++)
    {
        tableWidget_donnees->setItem(i,0,new QTableWidgetItem(""));
        tableWidget_donnees->setItem(i,1,new QTableWidgetItem(""));
    }
}
void basic_numerical_methods::cherchernbrecolumntableau(int n)
{
    const int m=99999; //le nbre max de lines dans le tableau x(i) et y(i).
    int nbrecolumntableau;
    int i;
    for (i=n; i<m ;i++)
    {
        if(tableWidget_donnees->item(i,0)->text().isEmpty())
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
void basic_numerical_methods::about()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("About App");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText("Les programmes d'enseignement Informatique et Méthodes numériques 19-20 ; \n"
                   "Ver. " APP_VERSION " sur Lunix et Windows; \n"
                                       "("+ QString("%1").arg(BLD_DATE) +"); \n\n"
                                                                         "HAFIANE Mohamed ; e-mail for feedback : <a href=\"mailto:thakir.dz@gmail.com?subject=About%20Thakir%20Prayer%20Times%20SailfishOS\">thakir.dz@gmail.com</a> ;\n\n"
                                                                         "Page web: <a href='https://sites.google.com/site/courshaf'>https://sites.google.com/site/courshaf</a> ; \n\n"
                                                                         "Programmé avec C++ (mingw64) avec commme IDE (Qt Creator) et avec Qt Ver. " QT_VERSION_STR " ; (Function Parser for C++ v4.5.1).");
    msgBox.exec();
}

