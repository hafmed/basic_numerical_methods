#ifndef basic_numerical_methods_H
#define basic_numerical_methods_H

#include <QMainWindow>
#include "fparser.hh"

#include "ui_basic_numerical_methods.h"

#include "qcustomplot/qcustomplot.h" // the header file of QCustomPlot. Don't forget to add it to your project, if you use an IDE, so it gets compiled.
#include <QMessageBox>

class basic_numerical_methods : public QMainWindow, public Ui::basic_numerical_methods
{
    Q_OBJECT

public:
    basic_numerical_methods(QWidget *parent = 0);
    QClipboard *pressePapiers = QApplication::clipboard();
    int nbrerow_tableWidget_donnees_eqtnonlineaire;
    int nbrecolumn_tableWidget_donnees_eqtnonlineaire;
    int nbrerow_tableWidget_donnees_eqtdifferentielle;
    int nbrecolumn_tableWidget_donnees_eqtdifferentielle;

    std::size_t array_size=1000000;
    double* y = new double[array_size];
    double* x = new double[array_size];
    int* ksimp13 = new int[array_size];
    int* ksimp38 = new int[array_size];

    double* error_truncation = new double[array_size];
    int fparserfx_EvalError=0;
    int fparsergx_EvalError=0;
    int fparserfprimex_EvalError=0;
    int fparserfxa_EvalError=0;
    int fparserfxb_EvalError=0;
    int fparserfxr_EvalError=0;
    int fparserfxm_EvalError=0;
    QString fx;
    FunctionParser fparserfx;
    QString gx;
    FunctionParser fparsergx;
    QString fprime;
    FunctionParser fparserfprime;
    QString fprimex;
    FunctionParser fparserfprimex;
    //
    QString yprim;
    FunctionParser fparseryprim;
    int fparseryprim_EvalError=0;
    //
    QString fxintegrale;
    FunctionParser fparserfxintegrale;
    int fparserfxintegrale_EvalError=0;
    // 1-8-2020
    bool validfx=true;
    bool validgx=true;
    bool validfprime=true;
    bool validx0=true;
    bool validx1=true;
    bool validtolerance=true;
    bool valida_eqtdifferentielle=true;
    bool validb_eqtdifferentielle=true;
    bool validy0_eqtdifferentielle=true;
    bool valida_tracage=true;
    bool validb_tracage=true;
    bool validdx_tracage=true;
    bool valida_integ=true;
    bool validb_integ=true;

    bool validDiametre=true;
    bool validRuguosite=true;
    bool validDebit=true;

private slots:
    void hafafficherColebrookWhite();
    void hafaffichertracagefx();
    void hafafficherIntegration();
    void changervaleurpas();
    void synchronisationdeuxspinBox();
    void hafafficherprogressBaretape1(int i, int n);
    void hafafficherprogressBaretape2(int i, int n);
    void nselonmethodechoisie();
    void remplireunelinevidetableau(int n);
    void cherchernbrecolumntableau(int n);
    void about();
    //-- CONVERT---
    void convert();
    //-------------
    void plotHAF( QVector<double> x, QVector<double> y);
    // haf 25-7-2020
    void choixmethodeeqtnonlineaire(int id);
    void hafresolutioneqtnonlineaire();
    void hafresolutioneqtnonlineaire_ptfixe();
    void hafresolutioneqtnonlineaire_newtonraphson();
    void hafresolutioneqtnonlineaire_secante();
    void hafresolutioneqtnonlineaire_dichotomie();
    void hafresolutioneqtnonlineaire_fausseposition();
    void copy_tableWidget_donnees_eqtnonlineaire();
    // haf 7-8-2020
    void choixmethodeeqtdifferentielle(int id);
    void hafresolutioneqtdifferentielle();
    void copy_tableWidget_donnees_eqtdifferentielle();
    void hafresolutioneqtdifferentielle_Euler_explicite();
    void changervaleurpas_eqtdifferentielle();
    void hafresolutioneqtdifferentielle_Runge_Kutta();
    void hafresolutioneqtdifferentielle_Kutta_Merson();
    //haf 19-08-2020
    void EvalErrorfunHAF(int fparsergx_EvalError, QString fx, double x);
    void textChangedinfunctionfx();
    void textChangedinfunctiongx();
    void textChangedinfunctionfprime();
    void textChangedinx0();
    void textChangedinx1();
    void textChangedintolerance();
    //
    void textChangedinfunctionyprim();
    void textChangedin_a_methodeeqtdifferentielle();
    void textChangedin_b_methodeeqtdifferentielle();
    void textChangedin_y0_methodeeqtdifferentielle();
    //
    void textChangedinfx_integ();
    void textChangedin_a_integ();
    void textChangedin_b_integ();
    //
    void textChangedinfx_tracage();
    void textChangedin_a_tracage();
    void textChangedin_b_tracage();
    void textChangedin_dx_tracage();
    //
    void textChangedin_Diametre();
    void textChangedin_Ruguosite();
    void textChangedin_Debit();

};

#endif // basic_numerical_methods
