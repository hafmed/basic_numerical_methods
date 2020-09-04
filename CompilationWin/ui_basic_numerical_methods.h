/********************************************************************************
** Form generated from reading UI file 'basic_numerical_methods.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASIC_NUMERICAL_METHODS_H
#define UI_BASIC_NUMERICAL_METHODS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_basic_numerical_methods
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_tracage_fx;
    QTextBrowser *textBrowser_resultats_lineEdit_tracage_fx;
    QPushButton *pushButton_Calculer_tracage_fx;
    QLineEdit *lineEdit_b_tracage_fx;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_9;
    QLineEdit *lineEdit_dx_tracage_fx;
    QLineEdit *lineEdit_a_tracage_fx;
    QLabel *label_13;
    QCustomPlot *customPlot;
    QLineEdit *lineEdit_tracage_fx;
    QWidget *tab_calcul_lambda;
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_12;
    QComboBox *comboBox_unite_diametre;
    QComboBox *comboBox_unite_rugosite;
    QComboBox *comboBox_unite_debit;
    QGroupBox *groupBox_7;
    QPushButton *pushButton_Calculer_ColebrookWhite;
    QTextBrowser *lambda_textBrowser;
    QLabel *label_5;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_Diametre;
    QLabel *label_7;
    QLineEdit *lineEdit_Ruguosite;
    QLabel *label_8;
    QLineEdit *lineEdit_Debit;
    QLabel *label_image_eqt_2;
    QWidget *tab_5;
    QGroupBox *groupBox_14;
    QPushButton *pushButton_Calculer_methodesEqtNonLineaire;
    QTableWidget *tableWidget_donnees_eqtnonlineaire;
    QPushButton *pushButton_Copier_TableauEqtNonLineaire;
    QGroupBox *groupBox_16;
    QLabel *label_x0;
    QLineEdit *lineEdit_x0;
    QLabel *label_16;
    QLineEdit *lineEdit_tolerance_eqtnonlineaire;
    QLabel *label_tolerance;
    QProgressBar *progressBar_eqtnonlineaire;
    QLineEdit *lineEdit_fx_eqt_non_lineaire;
    QGroupBox *groupBox_nbreiterationmax;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox_nmax_eqtnonlineaire;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_pointfixe;
    QRadioButton *radioButton_NewtonRaphson;
    QRadioButton *radioButton_secante;
    QRadioButton *radioButton_dichotomie;
    QRadioButton *radioButton_fausseposition;
    QLabel *label_x1;
    QLineEdit *lineEdit_x1;
    QStackedWidget *stackedWidget_gx_fprime;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_gx_fprimefx;
    QLineEdit *lineEdit_gx_eqt_non_lineaire;
    QWidget *page_9;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_gx_fprimefx_2;
    QLineEdit *lineEdit_fprime_eqt_non_lineaire;
    QGroupBox *groupBox_19;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBox_nbredecimaux_eqtnonlineaire;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget_methodeeqtnonlineaire;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_image_Integra_2;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_image_Integra_3;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_image_Integra_4;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_image_Integra_5;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_image_Integra_6;
    QWidget *tab_6;
    QGroupBox *groupBox_18;
    QLabel *label_y0;
    QLineEdit *lineEdit_y0_methodeeqtdifferentielle;
    QLabel *label_17;
    QLineEdit *lineEdit_dx_methodeeqtdifferentielle;
    QLabel *label_dx;
    QProgressBar *progressBar_eqtdifferentielle;
    QLineEdit *lineEdit_yprime_methodeeqtdifferentielle;
    QGroupBox *groupBox_nbrptsmethodeeqtdifferentielle;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *spinBox_nptseqtdifferentielle;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_20;
    QVBoxLayout *verticalLayout_21;
    QRadioButton *radioButton_EuleurExplicite;
    QRadioButton *radioButton_RungeKutta4;
    QRadioButton *radioButton_RungeKuttaMerson;
    QGroupBox *groupBox_21;
    QVBoxLayout *verticalLayout_24;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *spinBox_nbredecimaux_eqtdifferentielle;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_b_methodeeqtdifferentielle;
    QLabel *label_b_2;
    QLabel *label_a_2;
    QLineEdit *lineEdit_a_methodeeqtdifferentielle;
    QPushButton *pushButton_Copier_Tableaueqtdifferentielle;
    QStackedWidget *stackedWidget_methodeeqtdifferentielle;
    QWidget *page_13;
    QVBoxLayout *verticalLayout_22;
    QTableWidget *tableWidget_donnees_eqtdifferentielle;
    QWidget *page_14;
    QVBoxLayout *verticalLayout_23;
    QVBoxLayout *verticalLayout_19;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_image_Integra_7;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_15;
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout_17;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_image_Integra_8;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_16;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QSpacerItem *verticalSpacer;
    QLabel *label_image_Integra_9;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_Calculer_methodeeqtdifferentielle;
    QWidget *tab_intehration_numerique;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget_donnees;
    QLabel *label_2;
    QLineEdit *lineEdit_a;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_b;
    QLabel *label_3;
    QRadioButton *radioButton_fx_a_b_dx;
    QLineEdit *lineEdit_fx_integ;
    QRadioButton *radioButton_tableau_xy;
    QLineEdit *lineEdit_dx;
    QGroupBox *groupBox_3;
    QSpinBox *spinBox_nbre_pts_tableau;
    QCheckBox *checkBox_remplir_tableau;
    QProgressBar *progressBar;
    QGroupBox *groupBox_9;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_trapezes;
    QRadioButton *radioButton_simpson13;
    QRadioButton *radioButton_simpson38;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_Calculer_Integration;
    QTextBrowser *integral_textBrowser;
    QLabel *label_image_Integra;
    QGroupBox *groupBox_10;
    QSpinBox *spinBox_nbre_pts_fx;
    QWidget *tab;
    QTabWidget *tabWidget_convert;
    QWidget *tab_1;
    QPushButton *pushButton_convert_decimal;
    QGroupBox *groupBox;
    QSpinBox *spinBox_degre;
    QGroupBox *groupBox_11;
    QTextBrowser *textBrowser_decimal;
    QGroupBox *groupBox_12;
    QSpinBox *spinBox_mn;
    QGroupBox *groupBox_13;
    QDoubleSpinBox *doubleSpinBox_sec;
    QLabel *label;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_about;
    QLabel *label_version;
    QLabel *label_logo_univ_saida;
    QPushButton *pushButton_close;
    QButtonGroup *buttonGroup_methodesEqtNonLineaire;
    QButtonGroup *buttonGroup_methodeeqtdifferentielle;

    void setupUi(QMainWindow *basic_numerical_methods)
    {
        if (basic_numerical_methods->objectName().isEmpty())
            basic_numerical_methods->setObjectName(QString::fromUtf8("basic_numerical_methods"));
        basic_numerical_methods->resize(360, 640);
        basic_numerical_methods->setMinimumSize(QSize(360, 640));
        basic_numerical_methods->setMaximumSize(QSize(360, 640));
        basic_numerical_methods->setAutoFillBackground(false);
        centralWidget = new QWidget(basic_numerical_methods);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 360, 611));
        tabWidget->setMinimumSize(QSize(360, 600));
        tabWidget->setMaximumSize(QSize(360, 640));
        tabWidget->setContextMenuPolicy(Qt::NoContextMenu);
        tab_tracage_fx = new QWidget();
        tab_tracage_fx->setObjectName(QString::fromUtf8("tab_tracage_fx"));
        textBrowser_resultats_lineEdit_tracage_fx = new QTextBrowser(tab_tracage_fx);
        textBrowser_resultats_lineEdit_tracage_fx->setObjectName(QString::fromUtf8("textBrowser_resultats_lineEdit_tracage_fx"));
        textBrowser_resultats_lineEdit_tracage_fx->setGeometry(QRect(0, 70, 351, 121));
        pushButton_Calculer_tracage_fx = new QPushButton(tab_tracage_fx);
        pushButton_Calculer_tracage_fx->setObjectName(QString::fromUtf8("pushButton_Calculer_tracage_fx"));
        pushButton_Calculer_tracage_fx->setGeometry(QRect(120, 550, 111, 26));
        pushButton_Calculer_tracage_fx->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Calculer_tracage_fx->setMouseTracking(true);
        pushButton_Calculer_tracage_fx->setLayoutDirection(Qt::RightToLeft);
        pushButton_Calculer_tracage_fx->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        lineEdit_b_tracage_fx = new QLineEdit(tab_tracage_fx);
        lineEdit_b_tracage_fx->setObjectName(QString::fromUtf8("lineEdit_b_tracage_fx"));
        lineEdit_b_tracage_fx->setGeometry(QRect(50, 40, 51, 20));
        lineEdit_b_tracage_fx->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab_tracage_fx);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 20, 51, 21));
        label_12 = new QLabel(tab_tracage_fx);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(163, 20, 191, 20));
        label_9 = new QLabel(tab_tracage_fx);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 20, 51, 20));
        lineEdit_dx_tracage_fx = new QLineEdit(tab_tracage_fx);
        lineEdit_dx_tracage_fx->setObjectName(QString::fromUtf8("lineEdit_dx_tracage_fx"));
        lineEdit_dx_tracage_fx->setGeometry(QRect(100, 40, 61, 20));
        lineEdit_dx_tracage_fx->setAlignment(Qt::AlignCenter);
        lineEdit_dx_tracage_fx->setReadOnly(false);
        lineEdit_a_tracage_fx = new QLineEdit(tab_tracage_fx);
        lineEdit_a_tracage_fx->setObjectName(QString::fromUtf8("lineEdit_a_tracage_fx"));
        lineEdit_a_tracage_fx->setGeometry(QRect(0, 40, 51, 20));
        lineEdit_a_tracage_fx->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(tab_tracage_fx);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 20, 61, 20));
        customPlot = new QCustomPlot(tab_tracage_fx);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setEnabled(true);
        customPlot->setGeometry(QRect(0, 200, 351, 341));
        lineEdit_tracage_fx = new QLineEdit(tab_tracage_fx);
        lineEdit_tracage_fx->setObjectName(QString::fromUtf8("lineEdit_tracage_fx"));
        lineEdit_tracage_fx->setGeometry(QRect(160, 40, 191, 20));
        lineEdit_tracage_fx->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_tracage_fx, QString());
        tab_calcul_lambda = new QWidget();
        tab_calcul_lambda->setObjectName(QString::fromUtf8("tab_calcul_lambda"));
        groupBox_5 = new QGroupBox(tab_calcul_lambda);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 331, 571));
        groupBox_5->setAlignment(Qt::AlignCenter);
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(222, 130, 91, 211));
        groupBox_6->setAlignment(Qt::AlignCenter);
        verticalLayout_12 = new QVBoxLayout(groupBox_6);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        comboBox_unite_diametre = new QComboBox(groupBox_6);
        comboBox_unite_diametre->addItem(QString());
        comboBox_unite_diametre->addItem(QString());
        comboBox_unite_diametre->setObjectName(QString::fromUtf8("comboBox_unite_diametre"));

        verticalLayout_12->addWidget(comboBox_unite_diametre);

        comboBox_unite_rugosite = new QComboBox(groupBox_6);
        comboBox_unite_rugosite->addItem(QString());
        comboBox_unite_rugosite->addItem(QString());
        comboBox_unite_rugosite->setObjectName(QString::fromUtf8("comboBox_unite_rugosite"));
        comboBox_unite_rugosite->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        verticalLayout_12->addWidget(comboBox_unite_rugosite);

        comboBox_unite_debit = new QComboBox(groupBox_6);
        comboBox_unite_debit->addItem(QString());
        comboBox_unite_debit->addItem(QString());
        comboBox_unite_debit->addItem(QString());
        comboBox_unite_debit->setObjectName(QString::fromUtf8("comboBox_unite_debit"));
        comboBox_unite_debit->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        verticalLayout_12->addWidget(comboBox_unite_debit);

        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 340, 311, 221));
        groupBox_7->setAlignment(Qt::AlignCenter);
        pushButton_Calculer_ColebrookWhite = new QPushButton(groupBox_7);
        pushButton_Calculer_ColebrookWhite->setObjectName(QString::fromUtf8("pushButton_Calculer_ColebrookWhite"));
        pushButton_Calculer_ColebrookWhite->setGeometry(QRect(90, 190, 121, 26));
        pushButton_Calculer_ColebrookWhite->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Calculer_ColebrookWhite->setMouseTracking(true);
        pushButton_Calculer_ColebrookWhite->setLayoutDirection(Qt::RightToLeft);
        pushButton_Calculer_ColebrookWhite->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        lambda_textBrowser = new QTextBrowser(groupBox_7);
        lambda_textBrowser->setObjectName(QString::fromUtf8("lambda_textBrowser"));
        lambda_textBrowser->setGeometry(QRect(10, 70, 291, 121));
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 291, 41));
        groupBox_8 = new QGroupBox(groupBox_5);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 130, 201, 211));
        groupBox_8->setAlignment(Qt::AlignCenter);
        verticalLayout_11 = new QVBoxLayout(groupBox_8);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        lineEdit_Diametre = new QLineEdit(groupBox_8);
        lineEdit_Diametre->setObjectName(QString::fromUtf8("lineEdit_Diametre"));

        verticalLayout_2->addWidget(lineEdit_Diametre);

        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        lineEdit_Ruguosite = new QLineEdit(groupBox_8);
        lineEdit_Ruguosite->setObjectName(QString::fromUtf8("lineEdit_Ruguosite"));

        verticalLayout_2->addWidget(lineEdit_Ruguosite);

        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        lineEdit_Debit = new QLineEdit(groupBox_8);
        lineEdit_Debit->setObjectName(QString::fromUtf8("lineEdit_Debit"));

        verticalLayout_2->addWidget(lineEdit_Debit);


        verticalLayout_11->addLayout(verticalLayout_2);

        label_image_eqt_2 = new QLabel(groupBox_5);
        label_image_eqt_2->setObjectName(QString::fromUtf8("label_image_eqt_2"));
        label_image_eqt_2->setGeometry(QRect(30, 30, 271, 81));
        label_image_eqt_2->setMouseTracking(true);
        label_image_eqt_2->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_eqt_2->setTextFormat(Qt::PlainText);
        label_image_eqt_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/Eqt_Cool.bmp")));
        label_image_eqt_2->setScaledContents(true);
        label_image_eqt_2->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_calcul_lambda, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        groupBox_14 = new QGroupBox(tab_5);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(0, 340, 351, 241));
        groupBox_14->setAlignment(Qt::AlignCenter);
        pushButton_Calculer_methodesEqtNonLineaire = new QPushButton(groupBox_14);
        pushButton_Calculer_methodesEqtNonLineaire->setObjectName(QString::fromUtf8("pushButton_Calculer_methodesEqtNonLineaire"));
        pushButton_Calculer_methodesEqtNonLineaire->setGeometry(QRect(110, 210, 121, 26));
        pushButton_Calculer_methodesEqtNonLineaire->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Calculer_methodesEqtNonLineaire->setMouseTracking(true);
        pushButton_Calculer_methodesEqtNonLineaire->setLayoutDirection(Qt::RightToLeft);
        pushButton_Calculer_methodesEqtNonLineaire->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        tableWidget_donnees_eqtnonlineaire = new QTableWidget(groupBox_14);
        tableWidget_donnees_eqtnonlineaire->setObjectName(QString::fromUtf8("tableWidget_donnees_eqtnonlineaire"));
        tableWidget_donnees_eqtnonlineaire->setGeometry(QRect(0, 25, 351, 181));
        pushButton_Copier_TableauEqtNonLineaire = new QPushButton(groupBox_14);
        pushButton_Copier_TableauEqtNonLineaire->setObjectName(QString::fromUtf8("pushButton_Copier_TableauEqtNonLineaire"));
        pushButton_Copier_TableauEqtNonLineaire->setGeometry(QRect(240, 210, 111, 26));
        pushButton_Copier_TableauEqtNonLineaire->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Copier_TableauEqtNonLineaire->setMouseTracking(true);
        pushButton_Copier_TableauEqtNonLineaire->setLayoutDirection(Qt::RightToLeft);
        pushButton_Copier_TableauEqtNonLineaire->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        groupBox_16 = new QGroupBox(tab_5);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(0, 0, 355, 251));
        groupBox_16->setAlignment(Qt::AlignCenter);
        label_x0 = new QLabel(groupBox_16);
        label_x0->setObjectName(QString::fromUtf8("label_x0"));
        label_x0->setGeometry(QRect(10, 20, 71, 20));
        label_x0->setAlignment(Qt::AlignCenter);
        lineEdit_x0 = new QLineEdit(groupBox_16);
        lineEdit_x0->setObjectName(QString::fromUtf8("lineEdit_x0"));
        lineEdit_x0->setGeometry(QRect(10, 40, 71, 20));
        lineEdit_x0->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(groupBox_16);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(170, 80, 171, 20));
        label_16->setAlignment(Qt::AlignCenter);
        lineEdit_tolerance_eqtnonlineaire = new QLineEdit(groupBox_16);
        lineEdit_tolerance_eqtnonlineaire->setObjectName(QString::fromUtf8("lineEdit_tolerance_eqtnonlineaire"));
        lineEdit_tolerance_eqtnonlineaire->setGeometry(QRect(10, 80, 71, 20));
        lineEdit_tolerance_eqtnonlineaire->setInputMethodHints(Qt::ImhNone);
        lineEdit_tolerance_eqtnonlineaire->setMaxLength(10);
        lineEdit_tolerance_eqtnonlineaire->setAlignment(Qt::AlignCenter);
        label_tolerance = new QLabel(groupBox_16);
        label_tolerance->setObjectName(QString::fromUtf8("label_tolerance"));
        label_tolerance->setGeometry(QRect(10, 60, 71, 21));
        label_tolerance->setAlignment(Qt::AlignCenter);
        progressBar_eqtnonlineaire = new QProgressBar(groupBox_16);
        progressBar_eqtnonlineaire->setObjectName(QString::fromUtf8("progressBar_eqtnonlineaire"));
        progressBar_eqtnonlineaire->setGeometry(QRect(170, 130, 181, 23));
        progressBar_eqtnonlineaire->setValue(0);
        progressBar_eqtnonlineaire->setAlignment(Qt::AlignCenter);
        lineEdit_fx_eqt_non_lineaire = new QLineEdit(groupBox_16);
        lineEdit_fx_eqt_non_lineaire->setObjectName(QString::fromUtf8("lineEdit_fx_eqt_non_lineaire"));
        lineEdit_fx_eqt_non_lineaire->setGeometry(QRect(170, 100, 181, 20));
        lineEdit_fx_eqt_non_lineaire->setAlignment(Qt::AlignCenter);
        groupBox_nbreiterationmax = new QGroupBox(groupBox_16);
        groupBox_nbreiterationmax->setObjectName(QString::fromUtf8("groupBox_nbreiterationmax"));
        groupBox_nbreiterationmax->setGeometry(QRect(170, 160, 181, 71));
        groupBox_nbreiterationmax->setAlignment(Qt::AlignCenter);
        verticalLayout_10 = new QVBoxLayout(groupBox_nbreiterationmax);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBox_nmax_eqtnonlineaire = new QSpinBox(groupBox_nbreiterationmax);
        spinBox_nmax_eqtnonlineaire->setObjectName(QString::fromUtf8("spinBox_nmax_eqtnonlineaire"));
        spinBox_nmax_eqtnonlineaire->setReadOnly(false);
        spinBox_nmax_eqtnonlineaire->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_nmax_eqtnonlineaire->setAccelerated(true);
        spinBox_nmax_eqtnonlineaire->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_nmax_eqtnonlineaire->setKeyboardTracking(true);
        spinBox_nmax_eqtnonlineaire->setMinimum(2);
        spinBox_nmax_eqtnonlineaire->setMaximum(1000000);
        spinBox_nmax_eqtnonlineaire->setValue(150);

        horizontalLayout->addWidget(spinBox_nmax_eqtnonlineaire);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_10->addLayout(horizontalLayout);

        groupBox_15 = new QGroupBox(groupBox_16);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(0, 100, 161, 161));
        verticalLayout_3 = new QVBoxLayout(groupBox_15);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_pointfixe = new QRadioButton(groupBox_15);
        buttonGroup_methodesEqtNonLineaire = new QButtonGroup(basic_numerical_methods);
        buttonGroup_methodesEqtNonLineaire->setObjectName(QString::fromUtf8("buttonGroup_methodesEqtNonLineaire"));
        buttonGroup_methodesEqtNonLineaire->addButton(radioButton_pointfixe);
        radioButton_pointfixe->setObjectName(QString::fromUtf8("radioButton_pointfixe"));
        radioButton_pointfixe->setChecked(true);

        verticalLayout_3->addWidget(radioButton_pointfixe);

        radioButton_NewtonRaphson = new QRadioButton(groupBox_15);
        buttonGroup_methodesEqtNonLineaire->addButton(radioButton_NewtonRaphson);
        radioButton_NewtonRaphson->setObjectName(QString::fromUtf8("radioButton_NewtonRaphson"));

        verticalLayout_3->addWidget(radioButton_NewtonRaphson);

        radioButton_secante = new QRadioButton(groupBox_15);
        buttonGroup_methodesEqtNonLineaire->addButton(radioButton_secante);
        radioButton_secante->setObjectName(QString::fromUtf8("radioButton_secante"));

        verticalLayout_3->addWidget(radioButton_secante);

        radioButton_dichotomie = new QRadioButton(groupBox_15);
        buttonGroup_methodesEqtNonLineaire->addButton(radioButton_dichotomie);
        radioButton_dichotomie->setObjectName(QString::fromUtf8("radioButton_dichotomie"));

        verticalLayout_3->addWidget(radioButton_dichotomie);

        radioButton_fausseposition = new QRadioButton(groupBox_15);
        buttonGroup_methodesEqtNonLineaire->addButton(radioButton_fausseposition);
        radioButton_fausseposition->setObjectName(QString::fromUtf8("radioButton_fausseposition"));

        verticalLayout_3->addWidget(radioButton_fausseposition);

        label_x1 = new QLabel(groupBox_16);
        label_x1->setObjectName(QString::fromUtf8("label_x1"));
        label_x1->setGeometry(QRect(80, 20, 71, 20));
        label_x1->setAlignment(Qt::AlignCenter);
        lineEdit_x1 = new QLineEdit(groupBox_16);
        lineEdit_x1->setObjectName(QString::fromUtf8("lineEdit_x1"));
        lineEdit_x1->setGeometry(QRect(80, 40, 71, 20));
        lineEdit_x1->setAlignment(Qt::AlignCenter);
        stackedWidget_gx_fprime = new QStackedWidget(groupBox_16);
        stackedWidget_gx_fprime->setObjectName(QString::fromUtf8("stackedWidget_gx_fprime"));
        stackedWidget_gx_fprime->setGeometry(QRect(160, 20, 201, 61));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        verticalLayout_4 = new QVBoxLayout(page_8);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_gx_fprimefx = new QLabel(page_8);
        label_gx_fprimefx->setObjectName(QString::fromUtf8("label_gx_fprimefx"));
        label_gx_fprimefx->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_gx_fprimefx);

        lineEdit_gx_eqt_non_lineaire = new QLineEdit(page_8);
        lineEdit_gx_eqt_non_lineaire->setObjectName(QString::fromUtf8("lineEdit_gx_eqt_non_lineaire"));
        lineEdit_gx_eqt_non_lineaire->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lineEdit_gx_eqt_non_lineaire);

        stackedWidget_gx_fprime->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        verticalLayout_6 = new QVBoxLayout(page_9);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_gx_fprimefx_2 = new QLabel(page_9);
        label_gx_fprimefx_2->setObjectName(QString::fromUtf8("label_gx_fprimefx_2"));
        label_gx_fprimefx_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_gx_fprimefx_2);

        lineEdit_fprime_eqt_non_lineaire = new QLineEdit(page_9);
        lineEdit_fprime_eqt_non_lineaire->setObjectName(QString::fromUtf8("lineEdit_fprime_eqt_non_lineaire"));
        lineEdit_fprime_eqt_non_lineaire->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(lineEdit_fprime_eqt_non_lineaire);

        stackedWidget_gx_fprime->addWidget(page_9);
        groupBox_19 = new QGroupBox(tab_5);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(220, 250, 131, 81));
        groupBox_19->setAlignment(Qt::AlignCenter);
        verticalLayout_7 = new QVBoxLayout(groupBox_19);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        spinBox_nbredecimaux_eqtnonlineaire = new QSpinBox(groupBox_19);
        spinBox_nbredecimaux_eqtnonlineaire->setObjectName(QString::fromUtf8("spinBox_nbredecimaux_eqtnonlineaire"));
        spinBox_nbredecimaux_eqtnonlineaire->setReadOnly(false);
        spinBox_nbredecimaux_eqtnonlineaire->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_nbredecimaux_eqtnonlineaire->setAccelerated(true);
        spinBox_nbredecimaux_eqtnonlineaire->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_nbredecimaux_eqtnonlineaire->setKeyboardTracking(true);
        spinBox_nbredecimaux_eqtnonlineaire->setMinimum(0);
        spinBox_nbredecimaux_eqtnonlineaire->setMaximum(15);
        spinBox_nbredecimaux_eqtnonlineaire->setValue(9);

        horizontalLayout_2->addWidget(spinBox_nbredecimaux_eqtnonlineaire);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_7->addLayout(horizontalLayout_2);

        stackedWidget_methodeeqtnonlineaire = new QStackedWidget(tab_5);
        stackedWidget_methodeeqtnonlineaire->setObjectName(QString::fromUtf8("stackedWidget_methodeeqtnonlineaire"));
        stackedWidget_methodeeqtnonlineaire->setGeometry(QRect(0, 250, 221, 91));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_image_Integra_2 = new QLabel(page);
        label_image_Integra_2->setObjectName(QString::fromUtf8("label_image_Integra_2"));
        label_image_Integra_2->setMouseTracking(true);
        label_image_Integra_2->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_2->setTextFormat(Qt::PlainText);
        label_image_Integra_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/PointFixe.bmp")));
        label_image_Integra_2->setScaledContents(true);
        label_image_Integra_2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_image_Integra_2);

        stackedWidget_methodeeqtnonlineaire->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_8 = new QVBoxLayout(page_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_image_Integra_3 = new QLabel(page_3);
        label_image_Integra_3->setObjectName(QString::fromUtf8("label_image_Integra_3"));
        label_image_Integra_3->setMouseTracking(true);
        label_image_Integra_3->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_3->setTextFormat(Qt::PlainText);
        label_image_Integra_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/Newton-Raphson.bmp")));
        label_image_Integra_3->setScaledContents(true);
        label_image_Integra_3->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_image_Integra_3);

        stackedWidget_methodeeqtnonlineaire->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_9 = new QVBoxLayout(page_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_image_Integra_4 = new QLabel(page_4);
        label_image_Integra_4->setObjectName(QString::fromUtf8("label_image_Integra_4"));
        label_image_Integra_4->setMouseTracking(true);
        label_image_Integra_4->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_4->setTextFormat(Qt::PlainText);
        label_image_Integra_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/secante.bmp")));
        label_image_Integra_4->setScaledContents(true);
        label_image_Integra_4->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_image_Integra_4);

        stackedWidget_methodeeqtnonlineaire->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_14 = new QVBoxLayout(page_2);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_image_Integra_5 = new QLabel(page_2);
        label_image_Integra_5->setObjectName(QString::fromUtf8("label_image_Integra_5"));
        label_image_Integra_5->setMouseTracking(true);
        label_image_Integra_5->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_5->setTextFormat(Qt::PlainText);
        label_image_Integra_5->setPixmap(QPixmap(QString::fromUtf8(":/icons/Dicotomie.bmp")));
        label_image_Integra_5->setScaledContents(true);
        label_image_Integra_5->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_image_Integra_5);

        stackedWidget_methodeeqtnonlineaire->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout_13 = new QVBoxLayout(page_5);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_image_Integra_6 = new QLabel(page_5);
        label_image_Integra_6->setObjectName(QString::fromUtf8("label_image_Integra_6"));
        label_image_Integra_6->setMouseTracking(true);
        label_image_Integra_6->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_6->setTextFormat(Qt::PlainText);
        label_image_Integra_6->setPixmap(QPixmap(QString::fromUtf8(":/icons/Fausse-Position.bmp")));
        label_image_Integra_6->setScaledContents(true);
        label_image_Integra_6->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(label_image_Integra_6);

        stackedWidget_methodeeqtnonlineaire->addWidget(page_5);
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        groupBox_18 = new QGroupBox(tab_6);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(0, 0, 355, 251));
        groupBox_18->setAlignment(Qt::AlignCenter);
        label_y0 = new QLabel(groupBox_18);
        label_y0->setObjectName(QString::fromUtf8("label_y0"));
        label_y0->setGeometry(QRect(80, 60, 81, 20));
        label_y0->setAlignment(Qt::AlignCenter);
        lineEdit_y0_methodeeqtdifferentielle = new QLineEdit(groupBox_18);
        lineEdit_y0_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("lineEdit_y0_methodeeqtdifferentielle"));
        lineEdit_y0_methodeeqtdifferentielle->setGeometry(QRect(80, 80, 81, 20));
        lineEdit_y0_methodeeqtdifferentielle->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(groupBox_18);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(160, 20, 191, 20));
        label_17->setAlignment(Qt::AlignCenter);
        lineEdit_dx_methodeeqtdifferentielle = new QLineEdit(groupBox_18);
        lineEdit_dx_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("lineEdit_dx_methodeeqtdifferentielle"));
        lineEdit_dx_methodeeqtdifferentielle->setEnabled(true);
        lineEdit_dx_methodeeqtdifferentielle->setGeometry(QRect(0, 80, 81, 20));
        lineEdit_dx_methodeeqtdifferentielle->setInputMethodHints(Qt::ImhNone);
        lineEdit_dx_methodeeqtdifferentielle->setMaxLength(11);
        lineEdit_dx_methodeeqtdifferentielle->setAlignment(Qt::AlignCenter);
        lineEdit_dx_methodeeqtdifferentielle->setReadOnly(true);
        label_dx = new QLabel(groupBox_18);
        label_dx->setObjectName(QString::fromUtf8("label_dx"));
        label_dx->setGeometry(QRect(0, 60, 81, 21));
        label_dx->setAlignment(Qt::AlignCenter);
        progressBar_eqtdifferentielle = new QProgressBar(groupBox_18);
        progressBar_eqtdifferentielle->setObjectName(QString::fromUtf8("progressBar_eqtdifferentielle"));
        progressBar_eqtdifferentielle->setGeometry(QRect(180, 80, 171, 21));
        progressBar_eqtdifferentielle->setValue(0);
        progressBar_eqtdifferentielle->setAlignment(Qt::AlignCenter);
        lineEdit_yprime_methodeeqtdifferentielle = new QLineEdit(groupBox_18);
        lineEdit_yprime_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("lineEdit_yprime_methodeeqtdifferentielle"));
        lineEdit_yprime_methodeeqtdifferentielle->setGeometry(QRect(160, 40, 191, 20));
        lineEdit_yprime_methodeeqtdifferentielle->setAlignment(Qt::AlignCenter);
        groupBox_nbrptsmethodeeqtdifferentielle = new QGroupBox(groupBox_18);
        groupBox_nbrptsmethodeeqtdifferentielle->setObjectName(QString::fromUtf8("groupBox_nbrptsmethodeeqtdifferentielle"));
        groupBox_nbrptsmethodeeqtdifferentielle->setGeometry(QRect(200, 110, 151, 71));
        groupBox_nbrptsmethodeeqtdifferentielle->setAlignment(Qt::AlignCenter);
        verticalLayout_20 = new QVBoxLayout(groupBox_nbrptsmethodeeqtdifferentielle);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        spinBox_nptseqtdifferentielle = new QSpinBox(groupBox_nbrptsmethodeeqtdifferentielle);
        spinBox_nptseqtdifferentielle->setObjectName(QString::fromUtf8("spinBox_nptseqtdifferentielle"));
        spinBox_nptseqtdifferentielle->setReadOnly(false);
        spinBox_nptseqtdifferentielle->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_nptseqtdifferentielle->setAccelerated(true);
        spinBox_nptseqtdifferentielle->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_nptseqtdifferentielle->setKeyboardTracking(true);
        spinBox_nptseqtdifferentielle->setMinimum(2);
        spinBox_nptseqtdifferentielle->setMaximum(1000000);
        spinBox_nptseqtdifferentielle->setValue(11);

        horizontalLayout_3->addWidget(spinBox_nptseqtdifferentielle);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_20->addLayout(horizontalLayout_3);

        groupBox_20 = new QGroupBox(groupBox_18);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        groupBox_20->setGeometry(QRect(0, 110, 201, 141));
        verticalLayout_21 = new QVBoxLayout(groupBox_20);
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        radioButton_EuleurExplicite = new QRadioButton(groupBox_20);
        buttonGroup_methodeeqtdifferentielle = new QButtonGroup(basic_numerical_methods);
        buttonGroup_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("buttonGroup_methodeeqtdifferentielle"));
        buttonGroup_methodeeqtdifferentielle->addButton(radioButton_EuleurExplicite);
        radioButton_EuleurExplicite->setObjectName(QString::fromUtf8("radioButton_EuleurExplicite"));
        radioButton_EuleurExplicite->setChecked(true);

        verticalLayout_21->addWidget(radioButton_EuleurExplicite);

        radioButton_RungeKutta4 = new QRadioButton(groupBox_20);
        buttonGroup_methodeeqtdifferentielle->addButton(radioButton_RungeKutta4);
        radioButton_RungeKutta4->setObjectName(QString::fromUtf8("radioButton_RungeKutta4"));

        verticalLayout_21->addWidget(radioButton_RungeKutta4);

        radioButton_RungeKuttaMerson = new QRadioButton(groupBox_20);
        buttonGroup_methodeeqtdifferentielle->addButton(radioButton_RungeKuttaMerson);
        radioButton_RungeKuttaMerson->setObjectName(QString::fromUtf8("radioButton_RungeKuttaMerson"));

        verticalLayout_21->addWidget(radioButton_RungeKuttaMerson);

        groupBox_21 = new QGroupBox(groupBox_18);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        groupBox_21->setGeometry(QRect(200, 180, 151, 71));
        groupBox_21->setAlignment(Qt::AlignCenter);
        verticalLayout_24 = new QVBoxLayout(groupBox_21);
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        spinBox_nbredecimaux_eqtdifferentielle = new QSpinBox(groupBox_21);
        spinBox_nbredecimaux_eqtdifferentielle->setObjectName(QString::fromUtf8("spinBox_nbredecimaux_eqtdifferentielle"));
        spinBox_nbredecimaux_eqtdifferentielle->setReadOnly(false);
        spinBox_nbredecimaux_eqtdifferentielle->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_nbredecimaux_eqtdifferentielle->setAccelerated(true);
        spinBox_nbredecimaux_eqtdifferentielle->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_nbredecimaux_eqtdifferentielle->setKeyboardTracking(true);
        spinBox_nbredecimaux_eqtdifferentielle->setMinimum(0);
        spinBox_nbredecimaux_eqtdifferentielle->setMaximum(15);
        spinBox_nbredecimaux_eqtdifferentielle->setValue(9);

        horizontalLayout_4->addWidget(spinBox_nbredecimaux_eqtdifferentielle);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_24->addLayout(horizontalLayout_4);

        lineEdit_b_methodeeqtdifferentielle = new QLineEdit(groupBox_18);
        lineEdit_b_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("lineEdit_b_methodeeqtdifferentielle"));
        lineEdit_b_methodeeqtdifferentielle->setGeometry(QRect(80, 40, 81, 20));
        lineEdit_b_methodeeqtdifferentielle->setAlignment(Qt::AlignCenter);
        label_b_2 = new QLabel(groupBox_18);
        label_b_2->setObjectName(QString::fromUtf8("label_b_2"));
        label_b_2->setGeometry(QRect(80, 20, 81, 20));
        label_b_2->setAlignment(Qt::AlignCenter);
        label_a_2 = new QLabel(groupBox_18);
        label_a_2->setObjectName(QString::fromUtf8("label_a_2"));
        label_a_2->setGeometry(QRect(0, 20, 81, 20));
        label_a_2->setAlignment(Qt::AlignCenter);
        lineEdit_a_methodeeqtdifferentielle = new QLineEdit(groupBox_18);
        lineEdit_a_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("lineEdit_a_methodeeqtdifferentielle"));
        lineEdit_a_methodeeqtdifferentielle->setGeometry(QRect(0, 40, 81, 20));
        lineEdit_a_methodeeqtdifferentielle->setAlignment(Qt::AlignCenter);
        pushButton_Copier_Tableaueqtdifferentielle = new QPushButton(tab_6);
        pushButton_Copier_Tableaueqtdifferentielle->setObjectName(QString::fromUtf8("pushButton_Copier_Tableaueqtdifferentielle"));
        pushButton_Copier_Tableaueqtdifferentielle->setGeometry(QRect(244, 550, 111, 26));
        pushButton_Copier_Tableaueqtdifferentielle->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Copier_Tableaueqtdifferentielle->setMouseTracking(true);
        pushButton_Copier_Tableaueqtdifferentielle->setLayoutDirection(Qt::RightToLeft);
        pushButton_Copier_Tableaueqtdifferentielle->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        stackedWidget_methodeeqtdifferentielle = new QStackedWidget(tab_6);
        stackedWidget_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("stackedWidget_methodeeqtdifferentielle"));
        stackedWidget_methodeeqtdifferentielle->setGeometry(QRect(-3, 249, 361, 291));
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        verticalLayout_22 = new QVBoxLayout(page_13);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        tableWidget_donnees_eqtdifferentielle = new QTableWidget(page_13);
        tableWidget_donnees_eqtdifferentielle->setObjectName(QString::fromUtf8("tableWidget_donnees_eqtdifferentielle"));

        verticalLayout_22->addWidget(tableWidget_donnees_eqtdifferentielle);

        stackedWidget_methodeeqtdifferentielle->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        verticalLayout_23 = new QVBoxLayout(page_14);
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setContentsMargins(11, 11, 11, 11);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_5);

        label_image_Integra_7 = new QLabel(page_14);
        label_image_Integra_7->setObjectName(QString::fromUtf8("label_image_Integra_7"));
        label_image_Integra_7->setMouseTracking(true);
        label_image_Integra_7->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_7->setTextFormat(Qt::PlainText);
        label_image_Integra_7->setPixmap(QPixmap(QString::fromUtf8(":/icons/Euleur_explicite.bmp")));
        label_image_Integra_7->setScaledContents(true);
        label_image_Integra_7->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_image_Integra_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_6);


        verticalLayout_23->addLayout(verticalLayout_19);

        stackedWidget_methodeeqtdifferentielle->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        verticalLayout_18 = new QVBoxLayout(page_15);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_3);

        label_image_Integra_8 = new QLabel(page_15);
        label_image_Integra_8->setObjectName(QString::fromUtf8("label_image_Integra_8"));
        label_image_Integra_8->setMouseTracking(true);
        label_image_Integra_8->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_8->setTextFormat(Qt::PlainText);
        label_image_Integra_8->setPixmap(QPixmap(QString::fromUtf8(":/icons/Rung_Kutta4.bmp")));
        label_image_Integra_8->setScaledContents(true);
        label_image_Integra_8->setAlignment(Qt::AlignCenter);
        label_image_Integra_8->setWordWrap(false);

        verticalLayout_17->addWidget(label_image_Integra_8);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_4);


        verticalLayout_18->addLayout(verticalLayout_17);

        stackedWidget_methodeeqtdifferentielle->addWidget(page_15);
        page_16 = new QWidget();
        page_16->setObjectName(QString::fromUtf8("page_16"));
        verticalLayout_16 = new QVBoxLayout(page_16);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer);

        label_image_Integra_9 = new QLabel(page_16);
        label_image_Integra_9->setObjectName(QString::fromUtf8("label_image_Integra_9"));
        label_image_Integra_9->setMouseTracking(true);
        label_image_Integra_9->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra_9->setTextFormat(Qt::PlainText);
        label_image_Integra_9->setPixmap(QPixmap(QString::fromUtf8(":/icons/Kutta_Merson.bmp")));
        label_image_Integra_9->setScaledContents(true);
        label_image_Integra_9->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_image_Integra_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_2);


        verticalLayout_16->addLayout(verticalLayout_15);

        stackedWidget_methodeeqtdifferentielle->addWidget(page_16);
        pushButton_Calculer_methodeeqtdifferentielle = new QPushButton(tab_6);
        pushButton_Calculer_methodeeqtdifferentielle->setObjectName(QString::fromUtf8("pushButton_Calculer_methodeeqtdifferentielle"));
        pushButton_Calculer_methodeeqtdifferentielle->setGeometry(QRect(120, 550, 111, 26));
        pushButton_Calculer_methodeeqtdifferentielle->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Calculer_methodeeqtdifferentielle->setMouseTracking(true);
        pushButton_Calculer_methodeeqtdifferentielle->setLayoutDirection(Qt::RightToLeft);
        pushButton_Calculer_methodeeqtdifferentielle->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        tabWidget->addTab(tab_6, QString());
        tab_intehration_numerique = new QWidget();
        tab_intehration_numerique->setObjectName(QString::fromUtf8("tab_intehration_numerique"));
        groupBox_2 = new QGroupBox(tab_intehration_numerique);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(1, 0, 351, 301));
        groupBox_2->setAlignment(Qt::AlignCenter);
        tableWidget_donnees = new QTableWidget(groupBox_2);
        if (tableWidget_donnees->columnCount() < 3)
            tableWidget_donnees->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_donnees->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_donnees->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_donnees->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_donnees->rowCount() < 25)
            tableWidget_donnees->setRowCount(25);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(9, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(10, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(11, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(12, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(13, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(14, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(15, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(16, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(17, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(18, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(19, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(20, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(21, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(22, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(23, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_donnees->setVerticalHeaderItem(24, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_donnees->setItem(0, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_donnees->setItem(0, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_donnees->setItem(1, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_donnees->setItem(1, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_donnees->setItem(2, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_donnees->setItem(2, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_donnees->setItem(3, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_donnees->setItem(3, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_donnees->setItem(4, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_donnees->setItem(4, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_donnees->setItem(5, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_donnees->setItem(5, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_donnees->setItem(6, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_donnees->setItem(6, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_donnees->setItem(7, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_donnees->setItem(7, 1, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_donnees->setItem(8, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_donnees->setItem(8, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_donnees->setItem(9, 0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_donnees->setItem(9, 1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_donnees->setItem(10, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_donnees->setItem(10, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_donnees->setItem(11, 0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_donnees->setItem(11, 1, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_donnees->setItem(12, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_donnees->setItem(12, 1, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget_donnees->setItem(13, 0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_donnees->setItem(13, 1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_donnees->setItem(14, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_donnees->setItem(14, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_donnees->setItem(15, 0, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_donnees->setItem(15, 1, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_donnees->setItem(16, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_donnees->setItem(16, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_donnees->setItem(17, 0, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_donnees->setItem(17, 1, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_donnees->setItem(18, 0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_donnees->setItem(18, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_donnees->setItem(23, 0, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_donnees->setItem(23, 1, __qtablewidgetitem67);
        tableWidget_donnees->setObjectName(QString::fromUtf8("tableWidget_donnees"));
        tableWidget_donnees->setGeometry(QRect(10, 70, 341, 131));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 240, 51, 20));
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit_a = new QLineEdit(groupBox_2);
        lineEdit_a->setObjectName(QString::fromUtf8("lineEdit_a"));
        lineEdit_a->setGeometry(QRect(0, 260, 51, 20));
        lineEdit_a->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 240, 71, 20));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(200, 240, 111, 20));
        label_11->setAlignment(Qt::AlignCenter);
        lineEdit_b = new QLineEdit(groupBox_2);
        lineEdit_b->setObjectName(QString::fromUtf8("lineEdit_b"));
        lineEdit_b->setGeometry(QRect(50, 260, 51, 20));
        lineEdit_b->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 240, 51, 21));
        label_3->setAlignment(Qt::AlignCenter);
        radioButton_fx_a_b_dx = new QRadioButton(groupBox_2);
        radioButton_fx_a_b_dx->setObjectName(QString::fromUtf8("radioButton_fx_a_b_dx"));
        radioButton_fx_a_b_dx->setGeometry(QRect(10, 210, 51, 19));
        radioButton_fx_a_b_dx->setChecked(true);
        lineEdit_fx_integ = new QLineEdit(groupBox_2);
        lineEdit_fx_integ->setObjectName(QString::fromUtf8("lineEdit_fx_integ"));
        lineEdit_fx_integ->setGeometry(QRect(170, 260, 181, 20));
        lineEdit_fx_integ->setAlignment(Qt::AlignCenter);
        radioButton_tableau_xy = new QRadioButton(groupBox_2);
        radioButton_tableau_xy->setObjectName(QString::fromUtf8("radioButton_tableau_xy"));
        radioButton_tableau_xy->setGeometry(QRect(10, 30, 171, 19));
        radioButton_tableau_xy->setChecked(false);
        lineEdit_dx = new QLineEdit(groupBox_2);
        lineEdit_dx->setObjectName(QString::fromUtf8("lineEdit_dx"));
        lineEdit_dx->setGeometry(QRect(100, 260, 71, 20));
        lineEdit_dx->setAlignment(Qt::AlignCenter);
        lineEdit_dx->setReadOnly(true);
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 20, 91, 51));
        groupBox_3->setAlignment(Qt::AlignCenter);
        spinBox_nbre_pts_tableau = new QSpinBox(groupBox_3);
        spinBox_nbre_pts_tableau->setObjectName(QString::fromUtf8("spinBox_nbre_pts_tableau"));
        spinBox_nbre_pts_tableau->setGeometry(QRect(20, 26, 51, 21));
        spinBox_nbre_pts_tableau->setAccelerated(true);
        spinBox_nbre_pts_tableau->setMinimum(2);
        spinBox_nbre_pts_tableau->setMaximum(99999);
        spinBox_nbre_pts_tableau->setValue(7);
        checkBox_remplir_tableau = new QCheckBox(groupBox_2);
        checkBox_remplir_tableau->setObjectName(QString::fromUtf8("checkBox_remplir_tableau"));
        checkBox_remplir_tableau->setGeometry(QRect(70, 210, 131, 19));
        checkBox_remplir_tableau->setChecked(true);
        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(200, 210, 151, 23));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        groupBox_9 = new QGroupBox(tab_intehration_numerique);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 310, 171, 111));
        layoutWidget = new QWidget(groupBox_9);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 125, 89));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_trapezes = new QRadioButton(layoutWidget);
        radioButton_trapezes->setObjectName(QString::fromUtf8("radioButton_trapezes"));
        radioButton_trapezes->setChecked(true);

        verticalLayout->addWidget(radioButton_trapezes);

        radioButton_simpson13 = new QRadioButton(layoutWidget);
        radioButton_simpson13->setObjectName(QString::fromUtf8("radioButton_simpson13"));

        verticalLayout->addWidget(radioButton_simpson13);

        radioButton_simpson38 = new QRadioButton(layoutWidget);
        radioButton_simpson38->setObjectName(QString::fromUtf8("radioButton_simpson38"));

        verticalLayout->addWidget(radioButton_simpson38);

        groupBox_4 = new QGroupBox(tab_intehration_numerique);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 420, 351, 161));
        groupBox_4->setAlignment(Qt::AlignCenter);
        pushButton_Calculer_Integration = new QPushButton(groupBox_4);
        pushButton_Calculer_Integration->setObjectName(QString::fromUtf8("pushButton_Calculer_Integration"));
        pushButton_Calculer_Integration->setGeometry(QRect(90, 125, 181, 26));
        pushButton_Calculer_Integration->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Calculer_Integration->setMouseTracking(true);
        pushButton_Calculer_Integration->setLayoutDirection(Qt::RightToLeft);
        pushButton_Calculer_Integration->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        integral_textBrowser = new QTextBrowser(groupBox_4);
        integral_textBrowser->setObjectName(QString::fromUtf8("integral_textBrowser"));
        integral_textBrowser->setGeometry(QRect(10, 26, 331, 91));
        label_image_Integra = new QLabel(tab_intehration_numerique);
        label_image_Integra->setObjectName(QString::fromUtf8("label_image_Integra"));
        label_image_Integra->setGeometry(QRect(170, 360, 161, 61));
        label_image_Integra->setMouseTracking(true);
        label_image_Integra->setLocale(QLocale(QLocale::Arabic, QLocale::Algeria));
        label_image_Integra->setTextFormat(Qt::PlainText);
        label_image_Integra->setPixmap(QPixmap(QString::fromUtf8(":/icons/Integ.bmp")));
        label_image_Integra->setScaledContents(false);
        label_image_Integra->setAlignment(Qt::AlignCenter);
        groupBox_10 = new QGroupBox(tab_intehration_numerique);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(202, 311, 101, 51));
        groupBox_10->setAlignment(Qt::AlignCenter);
        spinBox_nbre_pts_fx = new QSpinBox(groupBox_10);
        spinBox_nbre_pts_fx->setObjectName(QString::fromUtf8("spinBox_nbre_pts_fx"));
        spinBox_nbre_pts_fx->setGeometry(QRect(20, 26, 61, 21));
        spinBox_nbre_pts_fx->setReadOnly(false);
        spinBox_nbre_pts_fx->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_nbre_pts_fx->setAccelerated(true);
        spinBox_nbre_pts_fx->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_nbre_pts_fx->setKeyboardTracking(true);
        spinBox_nbre_pts_fx->setMinimum(2);
        spinBox_nbre_pts_fx->setMaximum(99999);
        spinBox_nbre_pts_fx->setValue(7);
        tabWidget->addTab(tab_intehration_numerique, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget_convert = new QTabWidget(tab);
        tabWidget_convert->setObjectName(QString::fromUtf8("tabWidget_convert"));
        tabWidget_convert->setGeometry(QRect(10, 40, 331, 291));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        pushButton_convert_decimal = new QPushButton(tab_1);
        pushButton_convert_decimal->setObjectName(QString::fromUtf8("pushButton_convert_decimal"));
        pushButton_convert_decimal->setGeometry(QRect(130, 220, 75, 25));
        pushButton_convert_decimal->setCursor(QCursor(Qt::PointingHandCursor));
        groupBox = new QGroupBox(tab_1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 71, 51));
        spinBox_degre = new QSpinBox(groupBox);
        spinBox_degre->setObjectName(QString::fromUtf8("spinBox_degre"));
        spinBox_degre->setGeometry(QRect(10, 20, 51, 23));
        spinBox_degre->setMaximum(59);
        groupBox_11 = new QGroupBox(tab_1);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(180, 78, 131, 61));
        textBrowser_decimal = new QTextBrowser(groupBox_11);
        textBrowser_decimal->setObjectName(QString::fromUtf8("textBrowser_decimal"));
        textBrowser_decimal->setGeometry(QRect(10, 21, 111, 31));
        textBrowser_decimal->setLineWrapMode(QTextEdit::NoWrap);
        groupBox_12 = new QGroupBox(tab_1);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(20, 80, 71, 51));
        spinBox_mn = new QSpinBox(groupBox_12);
        spinBox_mn->setObjectName(QString::fromUtf8("spinBox_mn"));
        spinBox_mn->setGeometry(QRect(10, 20, 51, 23));
        spinBox_mn->setMaximum(59);
        groupBox_13 = new QGroupBox(tab_1);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(20, 140, 71, 61));
        doubleSpinBox_sec = new QDoubleSpinBox(groupBox_13);
        doubleSpinBox_sec->setObjectName(QString::fromUtf8("doubleSpinBox_sec"));
        doubleSpinBox_sec->setGeometry(QRect(10, 20, 51, 31));
        doubleSpinBox_sec->setDecimals(2);
        label = new QLabel(tab_1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(119, 93, 53, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/go-next.png")));
        tabWidget_convert->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_convert->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget_convert->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_convert->addTab(tab_4, QString());
        tabWidget->addTab(tab, QString());
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 610, 361, 32));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_about = new QPushButton(layoutWidget1);
        pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));
        pushButton_about->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_about->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_about);

        label_version = new QLabel(layoutWidget1);
        label_version->setObjectName(QString::fromUtf8("label_version"));
        label_version->setScaledContents(false);
        label_version->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_version);

        label_logo_univ_saida = new QLabel(layoutWidget1);
        label_logo_univ_saida->setObjectName(QString::fromUtf8("label_logo_univ_saida"));
        label_logo_univ_saida->setMaximumSize(QSize(45, 21));
        label_logo_univ_saida->setPixmap(QPixmap(QString::fromUtf8(":/icons/log_universite_SAIDA.png")));
        label_logo_univ_saida->setScaledContents(true);
        label_logo_univ_saida->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_logo_univ_saida);

        pushButton_close = new QPushButton(layoutWidget1);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_close);

        basic_numerical_methods->setCentralWidget(centralWidget);

        retranslateUi(basic_numerical_methods);

        tabWidget->setCurrentIndex(2);
        stackedWidget_gx_fprime->setCurrentIndex(0);
        stackedWidget_methodeeqtnonlineaire->setCurrentIndex(0);
        stackedWidget_methodeeqtdifferentielle->setCurrentIndex(1);
        tabWidget_convert->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(basic_numerical_methods);
    } // setupUi

    void retranslateUi(QMainWindow *basic_numerical_methods)
    {
        basic_numerical_methods->setWindowTitle(QApplication::translate("basic_numerical_methods", "basic_numerical_methods", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Calculer_tracage_fx->setToolTip(QApplication::translate("basic_numerical_methods", "Cliquer pour tracer la courbe de f(x)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Calculer_tracage_fx->setWhatsThis(QApplication::translate("basic_numerical_methods", "<html><head/><body><p>Tracage de f(x)</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Calculer_tracage_fx->setText(QApplication::translate("basic_numerical_methods", "Tracer-Calculer", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_b_tracage_fx->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de a et b, il faut tenir compte du domaine de d\303\251finition de f(x)!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_b_tracage_fx->setText(QApplication::translate("basic_numerical_methods", "25", nullptr));
        label_4->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">b</span></p></body></html>", nullptr));
        label_12->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">f(x)</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">a</span></p></body></html>", nullptr));
        lineEdit_dx_tracage_fx->setText(QApplication::translate("basic_numerical_methods", "0.1", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_a_tracage_fx->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de a et b, il faut tenir compte du domaine de d\303\251finition de f(x)!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_a_tracage_fx->setText(QApplication::translate("basic_numerical_methods", "-1.75", nullptr));
        label_13->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Le pas</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_tracage_fx->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f(x) peut contenir :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">^ * / + -</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pow(x,3)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pi</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sqrt"
                        "</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sin cos tan cot</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asin acos atan</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sinh cosh tanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asinh acosh atanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">log log10 exp</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">abs ; .....</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_tracage_fx->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit_tracage_fx->setText(QApplication::translate("basic_numerical_methods", "x^2+1+log(x+2)-20*x", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_tracage_fx), QApplication::translate("basic_numerical_methods", "Tracage d'une fonction", nullptr));
        groupBox_5->setTitle(QApplication::translate("basic_numerical_methods", "R\303\251solution de l'\303\251quation de Colebrook-White", nullptr));
        groupBox_6->setTitle(QApplication::translate("basic_numerical_methods", "Unit\303\251s", nullptr));
        comboBox_unite_diametre->setItemText(0, QApplication::translate("basic_numerical_methods", "m", nullptr));
        comboBox_unite_diametre->setItemText(1, QApplication::translate("basic_numerical_methods", "mm", nullptr));

        comboBox_unite_rugosite->setItemText(0, QApplication::translate("basic_numerical_methods", "mm", nullptr));
        comboBox_unite_rugosite->setItemText(1, QApplication::translate("basic_numerical_methods", "m", nullptr));

        comboBox_unite_debit->setItemText(0, QApplication::translate("basic_numerical_methods", "m3/s", nullptr));
        comboBox_unite_debit->setItemText(1, QApplication::translate("basic_numerical_methods", "l/s", nullptr));
        comboBox_unite_debit->setItemText(2, QApplication::translate("basic_numerical_methods", "l/h", nullptr));

        groupBox_7->setTitle(QApplication::translate("basic_numerical_methods", "R\303\251sultats", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Calculer_ColebrookWhite->setToolTip(QApplication::translate("basic_numerical_methods", "Cliquer pour calculer Lambda", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Calculer_ColebrookWhite->setWhatsThis(QApplication::translate("basic_numerical_methods", "Calcul de Lambda", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Calculer_ColebrookWhite->setText(QApplication::translate("basic_numerical_methods", "Calculer Lambda", nullptr));
        label_5->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Lambda</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">(Le coef. de perte de charge unitaire)</span></p></body></html>", nullptr));
        groupBox_8->setTitle(QApplication::translate("basic_numerical_methods", "Donn\303\251es", nullptr));
        label_6->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Diam\303\250tre de la conduite</span></p></body></html>", nullptr));
        lineEdit_Diametre->setText(QApplication::translate("basic_numerical_methods", "1", nullptr));
        label_7->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Rugosit\303\251 absolue K</span><span style=\" font-size:11pt; vertical-align:sub;\">s</span></p></body></html>", nullptr));
        lineEdit_Ruguosite->setText(QApplication::translate("basic_numerical_methods", "0.4", nullptr));
        label_8->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">D\303\251bit d'\303\251coulement</span></p></body></html>", nullptr));
        lineEdit_Debit->setText(QApplication::translate("basic_numerical_methods", "2", nullptr));
#ifndef QT_NO_TOOLTIP
        label_image_eqt_2->setToolTip(QApplication::translate("basic_numerical_methods", "L'\303\251quation de Colebrook-White (1939)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_eqt_2->setWhatsThis(QApplication::translate("basic_numerical_methods", "L'\303\251quation de Colebrook-White (1939)", nullptr));
#endif // QT_NO_WHATSTHIS
        label_image_eqt_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_calcul_lambda), QApplication::translate("basic_numerical_methods", "Calcul de Lambda", nullptr));
        groupBox_14->setTitle(QApplication::translate("basic_numerical_methods", "R\303\251sultats", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Calculer_methodesEqtNonLineaire->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Calculer_methodesEqtNonLineaire->setWhatsThis(QApplication::translate("basic_numerical_methods", "Calcul de l'int\303\251gral", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Calculer_methodesEqtNonLineaire->setText(QApplication::translate("basic_numerical_methods", "R\303\251soudre f(x)=0", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Copier_TableauEqtNonLineaire->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Copier_TableauEqtNonLineaire->setWhatsThis(QApplication::translate("basic_numerical_methods", "Calcul de l'int\303\251gral", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Copier_TableauEqtNonLineaire->setText(QApplication::translate("basic_numerical_methods", "Copier Tableau", nullptr));
        groupBox_16->setTitle(QApplication::translate("basic_numerical_methods", "Donn\303\251es", nullptr));
        label_x0->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">x0</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_x0->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de x0 ou a, il faut tenir compte du domaine de d\303\251finition de la fonction!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_x0->setText(QApplication::translate("basic_numerical_methods", "15", nullptr));
        label_16->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">f(x)</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_tolerance_eqtnonlineaire->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_tolerance_eqtnonlineaire->setText(QApplication::translate("basic_numerical_methods", "1e-9", nullptr));
        label_tolerance->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">Tol\303\251rance</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        progressBar_eqtnonlineaire->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        progressBar_eqtnonlineaire->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_fx_eqt_non_lineaire->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f(x) peut contenir :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">^ * / + -</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pow(x,3)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pi</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sqrt"
                        "</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sin cos tan cot</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asin acos atan</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sinh cosh tanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asinh acosh atanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">log log10 exp</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">abs ; .....</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_fx_eqt_non_lineaire->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit_fx_eqt_non_lineaire->setText(QApplication::translate("basic_numerical_methods", "x^2+1+log(x+2)-20*x", nullptr));
        groupBox_nbreiterationmax->setTitle(QApplication::translate("basic_numerical_methods", "Nombre max d'it\303\251rations", nullptr));
        spinBox_nmax_eqtnonlineaire->setSpecialValueText(QString());
        groupBox_15->setTitle(QApplication::translate("basic_numerical_methods", "M\303\251thode de r\303\251solution", nullptr));
        radioButton_pointfixe->setText(QApplication::translate("basic_numerical_methods", "Point fixe", nullptr));
        radioButton_NewtonRaphson->setText(QApplication::translate("basic_numerical_methods", "Newton-Raphson", nullptr));
        radioButton_secante->setText(QApplication::translate("basic_numerical_methods", "S\303\251cante", nullptr));
        radioButton_dichotomie->setText(QApplication::translate("basic_numerical_methods", "Dichotomie", nullptr));
        radioButton_fausseposition->setText(QApplication::translate("basic_numerical_methods", "Fausse position", nullptr));
        label_x1->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">x1</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_x1->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de x1 ou b, il faut tenir compte du domaine de d\303\251finition de la fonction!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_x1->setText(QApplication::translate("basic_numerical_methods", "21", nullptr));
        label_gx_fprimefx->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">g(x)</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_gx_eqt_non_lineaire->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f(x)=0 =&gt; x=g(x)</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_gx_eqt_non_lineaire->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit_gx_eqt_non_lineaire->setText(QApplication::translate("basic_numerical_methods", "sqrt(-1-log(x+2)+20*x)", nullptr));
        label_gx_fprimefx_2->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f'(x)</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_fprime_eqt_non_lineaire->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f'(x) est la deriv\303\251e de f(x)</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_fprime_eqt_non_lineaire->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit_fprime_eqt_non_lineaire->setText(QApplication::translate("basic_numerical_methods", "2*x+1/(x+2)-20", nullptr));
        groupBox_19->setTitle(QApplication::translate("basic_numerical_methods", "Nombre d\303\251cimaux", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_nbredecimaux_eqtnonlineaire->setToolTip(QApplication::translate("basic_numerical_methods", "Nombre de d\303\251cimaux dans les r\303\251sultats", nullptr));
#endif // QT_NO_TOOLTIP
        spinBox_nbredecimaux_eqtnonlineaire->setSpecialValueText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_3->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_4->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_5->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_5->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_6->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_6->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("basic_numerical_methods", "Equation non-lin\303\251aire", nullptr));
        groupBox_18->setTitle(QApplication::translate("basic_numerical_methods", "Donn\303\251es", nullptr));
        label_y0->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">y0</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_y0_methodeeqtdifferentielle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_y0_methodeeqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "1", nullptr));
        label_17->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">y \342\200\262 = f(x, y)</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_dx_methodeeqtdifferentielle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_dx_methodeeqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "0.1", nullptr));
        label_dx->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">dx</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        progressBar_eqtdifferentielle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        progressBar_eqtdifferentielle->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_yprime_methodeeqtdifferentielle->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f(x) peut contenir :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">^ * / + -</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pow(x,3)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pi</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sqrt"
                        "</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sin cos tan cot</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asin acos atan</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sinh cosh tanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asinh acosh atanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">log log10 exp</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">abs ; .....</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_yprime_methodeeqtdifferentielle->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit_yprime_methodeeqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "-y+x+1", nullptr));
        groupBox_nbrptsmethodeeqtdifferentielle->setTitle(QApplication::translate("basic_numerical_methods", "Nombre de points", nullptr));
        spinBox_nptseqtdifferentielle->setSpecialValueText(QString());
        groupBox_20->setTitle(QApplication::translate("basic_numerical_methods", "M\303\251thode de r\303\251solution", nullptr));
        radioButton_EuleurExplicite->setText(QApplication::translate("basic_numerical_methods", "Euler explicite", nullptr));
        radioButton_RungeKutta4->setText(QApplication::translate("basic_numerical_methods", "Runge-Kutta d'ordre 4", nullptr));
        radioButton_RungeKuttaMerson->setText(QApplication::translate("basic_numerical_methods", "Kutta-Merson", nullptr));
        groupBox_21->setTitle(QApplication::translate("basic_numerical_methods", "Nombre de d\303\251cimaux", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBox_nbredecimaux_eqtdifferentielle->setToolTip(QApplication::translate("basic_numerical_methods", "Nombre de d\303\251cimaux dans les r\303\251sultats", nullptr));
#endif // QT_NO_TOOLTIP
        spinBox_nbredecimaux_eqtdifferentielle->setSpecialValueText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_b_methodeeqtdifferentielle->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de b, il faut tenir compte du domaine de d\303\251finition de la fonction!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_b_methodeeqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "1", nullptr));
        label_b_2->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">b</span></p></body></html>", nullptr));
        label_a_2->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">a</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_a_methodeeqtdifferentielle->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de a, il faut tenir compte du domaine de d\303\251finition de la fonction!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_a_methodeeqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Copier_Tableaueqtdifferentielle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Copier_Tableaueqtdifferentielle->setWhatsThis(QApplication::translate("basic_numerical_methods", "Calcul de l'int\303\251gral", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Copier_Tableaueqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "Copier Tableau", nullptr));
#ifndef QT_NO_TOOLTIP
        label_image_Integra_7->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_7->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_7->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_8->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_8->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_8->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_image_Integra_9->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra_9->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Calculer_methodeeqtdifferentielle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Calculer_methodeeqtdifferentielle->setWhatsThis(QApplication::translate("basic_numerical_methods", "Calcul de l'int\303\251gral", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Calculer_methodeeqtdifferentielle->setText(QApplication::translate("basic_numerical_methods", "Calculer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("basic_numerical_methods", "Equations diff\303\251rentielles ordinaires", nullptr));
        groupBox_2->setTitle(QApplication::translate("basic_numerical_methods", "Donn\303\251es", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_donnees->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("basic_numerical_methods", "x(i)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_donnees->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("basic_numerical_methods", "y(i)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_donnees->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("basic_numerical_methods", "I(j)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_donnees->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("basic_numerical_methods", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_donnees->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("basic_numerical_methods", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_donnees->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("basic_numerical_methods", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_donnees->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("basic_numerical_methods", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_donnees->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("basic_numerical_methods", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_donnees->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("basic_numerical_methods", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_donnees->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("basic_numerical_methods", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_donnees->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("basic_numerical_methods", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_donnees->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("basic_numerical_methods", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_donnees->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("basic_numerical_methods", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_donnees->verticalHeaderItem(10);
        ___qtablewidgetitem13->setText(QApplication::translate("basic_numerical_methods", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_donnees->verticalHeaderItem(11);
        ___qtablewidgetitem14->setText(QApplication::translate("basic_numerical_methods", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_donnees->verticalHeaderItem(12);
        ___qtablewidgetitem15->setText(QApplication::translate("basic_numerical_methods", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_donnees->verticalHeaderItem(13);
        ___qtablewidgetitem16->setText(QApplication::translate("basic_numerical_methods", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_donnees->verticalHeaderItem(14);
        ___qtablewidgetitem17->setText(QApplication::translate("basic_numerical_methods", "15", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_donnees->verticalHeaderItem(15);
        ___qtablewidgetitem18->setText(QApplication::translate("basic_numerical_methods", "16", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_donnees->verticalHeaderItem(16);
        ___qtablewidgetitem19->setText(QApplication::translate("basic_numerical_methods", "17", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_donnees->verticalHeaderItem(17);
        ___qtablewidgetitem20->setText(QApplication::translate("basic_numerical_methods", "18", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_donnees->verticalHeaderItem(18);
        ___qtablewidgetitem21->setText(QApplication::translate("basic_numerical_methods", "19", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_donnees->verticalHeaderItem(19);
        ___qtablewidgetitem22->setText(QApplication::translate("basic_numerical_methods", "20", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_donnees->verticalHeaderItem(20);
        ___qtablewidgetitem23->setText(QApplication::translate("basic_numerical_methods", "21", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_donnees->verticalHeaderItem(21);
        ___qtablewidgetitem24->setText(QApplication::translate("basic_numerical_methods", "22", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_donnees->verticalHeaderItem(22);
        ___qtablewidgetitem25->setText(QApplication::translate("basic_numerical_methods", "23", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_donnees->verticalHeaderItem(23);
        ___qtablewidgetitem26->setText(QApplication::translate("basic_numerical_methods", "24", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_donnees->verticalHeaderItem(24);
        ___qtablewidgetitem27->setText(QApplication::translate("basic_numerical_methods", "25", nullptr));

        const bool __sortingEnabled = tableWidget_donnees->isSortingEnabled();
        tableWidget_donnees->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_donnees->item(0, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("basic_numerical_methods", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_donnees->item(0, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("basic_numerical_methods", "10e3", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_donnees->item(1, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("basic_numerical_methods", "0.4", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_donnees->item(1, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("basic_numerical_methods", "10.1e3", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_donnees->item(2, 0);
        ___qtablewidgetitem32->setText(QApplication::translate("basic_numerical_methods", "0.8", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_donnees->item(2, 1);
        ___qtablewidgetitem33->setText(QApplication::translate("basic_numerical_methods", "10.2e3", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_donnees->item(3, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("basic_numerical_methods", "1.2", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_donnees->item(3, 1);
        ___qtablewidgetitem35->setText(QApplication::translate("basic_numerical_methods", "10.6e3", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_donnees->item(4, 0);
        ___qtablewidgetitem36->setText(QApplication::translate("basic_numerical_methods", "1.6", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_donnees->item(4, 1);
        ___qtablewidgetitem37->setText(QApplication::translate("basic_numerical_methods", "11.3e3", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_donnees->item(5, 0);
        ___qtablewidgetitem38->setText(QApplication::translate("basic_numerical_methods", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_donnees->item(5, 1);
        ___qtablewidgetitem39->setText(QApplication::translate("basic_numerical_methods", "12.3e3", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_donnees->item(6, 0);
        ___qtablewidgetitem40->setText(QApplication::translate("basic_numerical_methods", "2.4", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_donnees->item(6, 1);
        ___qtablewidgetitem41->setText(QApplication::translate("basic_numerical_methods", "12.7e3", nullptr));
        tableWidget_donnees->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">a</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_a->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de a et b, il faut tenir compte du domaine de d\303\251finition de f(x)!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_a->setText(QApplication::translate("basic_numerical_methods", "0", nullptr));
        label_10->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Le pas</span></p></body></html>", nullptr));
        label_11->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">f(x)</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_b->setToolTip(QApplication::translate("basic_numerical_methods", "Dans le choix de a et b, il faut tenir compte du domaine de d\303\251finition de f(x)!", nullptr));
#endif // QT_NO_TOOLTIP
        lineEdit_b->setText(QApplication::translate("basic_numerical_methods", "1", nullptr));
        label_3->setText(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">b</span></p></body></html>", nullptr));
        radioButton_fx_a_b_dx->setText(QApplication::translate("basic_numerical_methods", "f(x) :", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_fx_integ->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">f(x) peut contenir :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">^ * / + -</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pow(x,3)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">pi</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sqrt"
                        "</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sin cos tan cot</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asin acos atan</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sinh cosh tanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asinh acosh atanh</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">log log10 exp</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">abs ; .....</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_fx_integ->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lineEdit_fx_integ->setText(QApplication::translate("basic_numerical_methods", "x^2+1", nullptr));
        radioButton_tableau_xy->setText(QApplication::translate("basic_numerical_methods", "Tableau (x(i) et y(i)) :", nullptr));
        lineEdit_dx->setText(QApplication::translate("basic_numerical_methods", "0.166667", nullptr));
        groupBox_3->setTitle(QApplication::translate("basic_numerical_methods", "Nbre des pts", nullptr));
        checkBox_remplir_tableau->setText(QApplication::translate("basic_numerical_methods", "Remplir Tableau", nullptr));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("basic_numerical_methods", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Taux d'avencement dans le remplissage du tableau ... (si vous trouvez que c'est tres long, d\303\251sactiver \"Remplire Tableau\" et recomencez le calcul, sinon reduire dx</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_9->setTitle(QApplication::translate("basic_numerical_methods", "M\303\251thode d'int\303\251gration", nullptr));
        radioButton_trapezes->setText(QApplication::translate("basic_numerical_methods", "Trap\303\250zes", nullptr));
        radioButton_simpson13->setText(QApplication::translate("basic_numerical_methods", "Simpson 1/3", nullptr));
        radioButton_simpson38->setText(QApplication::translate("basic_numerical_methods", "Simpson 3/8", nullptr));
        groupBox_4->setTitle(QApplication::translate("basic_numerical_methods", "R\303\251sultats", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Calculer_Integration->setToolTip(QApplication::translate("basic_numerical_methods", "Cliquer pour calculer l'int\303\251gral", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_Calculer_Integration->setWhatsThis(QApplication::translate("basic_numerical_methods", "Calcul de l'int\303\251gral", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_Calculer_Integration->setText(QApplication::translate("basic_numerical_methods", "Calculer l'int\303\251grale", nullptr));
#ifndef QT_NO_TOOLTIP
        label_image_Integra->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_image_Integra->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_image_Integra->setText(QString());
        groupBox_10->setTitle(QApplication::translate("basic_numerical_methods", "Nbre des pts", nullptr));
        spinBox_nbre_pts_fx->setSpecialValueText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_intehration_numerique), QApplication::translate("basic_numerical_methods", "Int\303\251gration num\303\251rique", nullptr));
        pushButton_convert_decimal->setText(QApplication::translate("basic_numerical_methods", "Convertir", nullptr));
        groupBox->setTitle(QApplication::translate("basic_numerical_methods", "degr\303\251", nullptr));
        groupBox_11->setTitle(QApplication::translate("basic_numerical_methods", "D\303\251cimal", nullptr));
        groupBox_12->setTitle(QApplication::translate("basic_numerical_methods", "min", nullptr));
        groupBox_13->setTitle(QApplication::translate("basic_numerical_methods", "sec", nullptr));
        label->setText(QString());
        tabWidget_convert->setTabText(tabWidget_convert->indexOf(tab_1), QApplication::translate("basic_numerical_methods", "Coordonn\303\251es", nullptr));
        tabWidget_convert->setTabText(tabWidget_convert->indexOf(tab_2), QApplication::translate("basic_numerical_methods", "M\303\251trique", nullptr));
        tabWidget_convert->setTabText(tabWidget_convert->indexOf(tab_3), QApplication::translate("basic_numerical_methods", "Viscosit\303\251", nullptr));
        tabWidget_convert->setTabText(tabWidget_convert->indexOf(tab_4), QApplication::translate("basic_numerical_methods", "D\303\251bit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("basic_numerical_methods", "Conversion", nullptr));
        pushButton_about->setText(QApplication::translate("basic_numerical_methods", "About", nullptr));
        label_version->setText(QString());
        label_logo_univ_saida->setText(QString());
        pushButton_close->setText(QApplication::translate("basic_numerical_methods", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class basic_numerical_methods: public Ui_basic_numerical_methods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASIC_NUMERICAL_METHODS_H
