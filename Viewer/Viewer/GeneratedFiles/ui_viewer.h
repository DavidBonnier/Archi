/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created: Sun 2. Jun 01:57:44 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewerClass
{
public:
    QAction *actionOuvrir;
    QAction *actionFermer;
    QAction *actionSauver;
    QAction *actionSauver_sous;
    QAction *actionQuitter;
    QAction *actionAnnuler;
    QAction *actionRefaire;
    QAction *actionDetruire_Pile_Avant_et_Arri_re;
    QAction *actionAide;
    QAction *actionA_propos;
    QAction *actionModification_de_la_Taille;
    QAction *actionSeuillage;
    QAction *actionImage_Noir_et_Blanc;
    QAction *actionInverser_Image;
    QAction *actionModifications_des_couleurs;
    QWidget *centralWidget;
    QLabel *imageLabel;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuCaract_riqtique_Images;
    QMenu *menuModif;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *DWdockWidget;
    QWidget *dockWidgetContents_3;
    QFormLayout *formLayout_2;
    QPushButton *pushButtonValider;
    QPushButton *pushButtonAnnuler;
    QLabel *labelMinimum;
    QLabel *labelMaximum;
    QSpinBox *spinBoxMinimum;
    QSpinBox *spinBoxMaximum;

    void setupUi(QMainWindow *ViewerClass)
    {
        if (ViewerClass->objectName().isEmpty())
            ViewerClass->setObjectName(QString::fromUtf8("ViewerClass"));
        ViewerClass->resize(600, 400);
        actionOuvrir = new QAction(ViewerClass);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionFermer = new QAction(ViewerClass);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionFermer->setEnabled(false);
        actionSauver = new QAction(ViewerClass);
        actionSauver->setObjectName(QString::fromUtf8("actionSauver"));
        actionSauver->setEnabled(false);
        actionSauver_sous = new QAction(ViewerClass);
        actionSauver_sous->setObjectName(QString::fromUtf8("actionSauver_sous"));
        actionSauver_sous->setEnabled(false);
        actionQuitter = new QAction(ViewerClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAnnuler = new QAction(ViewerClass);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionAnnuler->setEnabled(true);
        actionRefaire = new QAction(ViewerClass);
        actionRefaire->setObjectName(QString::fromUtf8("actionRefaire"));
        actionRefaire->setEnabled(true);
        actionDetruire_Pile_Avant_et_Arri_re = new QAction(ViewerClass);
        actionDetruire_Pile_Avant_et_Arri_re->setObjectName(QString::fromUtf8("actionDetruire_Pile_Avant_et_Arri_re"));
        actionAide = new QAction(ViewerClass);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        actionA_propos = new QAction(ViewerClass);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionModification_de_la_Taille = new QAction(ViewerClass);
        actionModification_de_la_Taille->setObjectName(QString::fromUtf8("actionModification_de_la_Taille"));
        actionModification_de_la_Taille->setEnabled(false);
        actionSeuillage = new QAction(ViewerClass);
        actionSeuillage->setObjectName(QString::fromUtf8("actionSeuillage"));
        actionSeuillage->setCheckable(true);
        actionSeuillage->setEnabled(false);
        actionImage_Noir_et_Blanc = new QAction(ViewerClass);
        actionImage_Noir_et_Blanc->setObjectName(QString::fromUtf8("actionImage_Noir_et_Blanc"));
        actionImage_Noir_et_Blanc->setCheckable(false);
        actionImage_Noir_et_Blanc->setEnabled(false);
        actionInverser_Image = new QAction(ViewerClass);
        actionInverser_Image->setObjectName(QString::fromUtf8("actionInverser_Image"));
        actionInverser_Image->setCheckable(false);
        actionInverser_Image->setEnabled(false);
        actionModifications_des_couleurs = new QAction(ViewerClass);
        actionModifications_des_couleurs->setObjectName(QString::fromUtf8("actionModifications_des_couleurs"));
        actionModifications_des_couleurs->setCheckable(true);
        actionModifications_des_couleurs->setEnabled(false);
        centralWidget = new QWidget(ViewerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(280, 110, 51, 21));
        ViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuCaract_riqtique_Images = new QMenu(menuBar);
        menuCaract_riqtique_Images->setObjectName(QString::fromUtf8("menuCaract_riqtique_Images"));
        menuModif = new QMenu(menuBar);
        menuModif->setObjectName(QString::fromUtf8("menuModif"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        ViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ViewerClass->setStatusBar(statusBar);
        DWdockWidget = new QDockWidget(ViewerClass);
        DWdockWidget->setObjectName(QString::fromUtf8("DWdockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        formLayout_2 = new QFormLayout(dockWidgetContents_3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        pushButtonValider = new QPushButton(dockWidgetContents_3);
        pushButtonValider->setObjectName(QString::fromUtf8("pushButtonValider"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pushButtonValider);

        pushButtonAnnuler = new QPushButton(dockWidgetContents_3);
        pushButtonAnnuler->setObjectName(QString::fromUtf8("pushButtonAnnuler"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pushButtonAnnuler);

        labelMinimum = new QLabel(dockWidgetContents_3);
        labelMinimum->setObjectName(QString::fromUtf8("labelMinimum"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelMinimum);

        labelMaximum = new QLabel(dockWidgetContents_3);
        labelMaximum->setObjectName(QString::fromUtf8("labelMaximum"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelMaximum);

        spinBoxMinimum = new QSpinBox(dockWidgetContents_3);
        spinBoxMinimum->setObjectName(QString::fromUtf8("spinBoxMinimum"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBoxMinimum);

        spinBoxMaximum = new QSpinBox(dockWidgetContents_3);
        spinBoxMaximum->setObjectName(QString::fromUtf8("spinBoxMaximum"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBoxMaximum);

        DWdockWidget->setWidget(dockWidgetContents_3);
        ViewerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DWdockWidget);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuCaract_riqtique_Images->menuAction());
        menuBar->addAction(menuModif->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionFermer);
        menuFichier->addAction(actionSauver);
        menuFichier->addAction(actionSauver_sous);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionRefaire);
        menuEdition->addAction(actionDetruire_Pile_Avant_et_Arri_re);
        menuCaract_riqtique_Images->addAction(actionModification_de_la_Taille);
        menuModif->addAction(actionImage_Noir_et_Blanc);
        menuModif->addAction(actionInverser_Image);
        menuModif->addAction(actionSeuillage);
        menuModif->addAction(actionModifications_des_couleurs);
        menu->addAction(actionAide);
        menu->addAction(actionA_propos);

        retranslateUi(ViewerClass);

        QMetaObject::connectSlotsByName(ViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerClass)
    {
        ViewerClass->setWindowTitle(QApplication::translate("ViewerClass", "Visualisation d'images", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("ViewerClass", "Ouvrir", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setShortcut(QApplication::translate("ViewerClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionFermer->setText(QApplication::translate("ViewerClass", "Fermer", 0, QApplication::UnicodeUTF8));
        actionSauver->setText(QApplication::translate("ViewerClass", "Sauver", 0, QApplication::UnicodeUTF8));
        actionSauver->setShortcut(QApplication::translate("ViewerClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSauver_sous->setText(QApplication::translate("ViewerClass", "Sauver sous", 0, QApplication::UnicodeUTF8));
        actionSauver_sous->setShortcut(QApplication::translate("ViewerClass", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("ViewerClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("ViewerClass", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("ViewerClass", "Annuler", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setShortcut(QApplication::translate("ViewerClass", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRefaire->setText(QApplication::translate("ViewerClass", "Refaire", 0, QApplication::UnicodeUTF8));
        actionRefaire->setShortcut(QApplication::translate("ViewerClass", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionDetruire_Pile_Avant_et_Arri_re->setText(QApplication::translate("ViewerClass", "Detruire Pile Avant et Arri\303\250re", 0, QApplication::UnicodeUTF8));
        actionAide->setText(QApplication::translate("ViewerClass", "Aide", 0, QApplication::UnicodeUTF8));
        actionAide->setShortcut(QApplication::translate("ViewerClass", "F1", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("ViewerClass", "A propos", 0, QApplication::UnicodeUTF8));
        actionModification_de_la_Taille->setText(QApplication::translate("ViewerClass", "Modification de la Taille", 0, QApplication::UnicodeUTF8));
        actionSeuillage->setText(QApplication::translate("ViewerClass", "Seuillage", 0, QApplication::UnicodeUTF8));
        actionImage_Noir_et_Blanc->setText(QApplication::translate("ViewerClass", "Image Noir et Blanc", 0, QApplication::UnicodeUTF8));
        actionInverser_Image->setText(QApplication::translate("ViewerClass", "Inverser une Image", 0, QApplication::UnicodeUTF8));
        actionModifications_des_couleurs->setText(QApplication::translate("ViewerClass", "R\303\251glages des couleurs", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        menuFichier->setTitle(QApplication::translate("ViewerClass", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("ViewerClass", "Edition", 0, QApplication::UnicodeUTF8));
        menuCaract_riqtique_Images->setTitle(QApplication::translate("ViewerClass", "Caract\303\251riqtique Images", 0, QApplication::UnicodeUTF8));
        menuModif->setTitle(QApplication::translate("ViewerClass", "Modif", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ViewerClass", "?", 0, QApplication::UnicodeUTF8));
        DWdockWidget->setWindowTitle(QApplication::translate("ViewerClass", "Seuillage", 0, QApplication::UnicodeUTF8));
        pushButtonValider->setText(QApplication::translate("ViewerClass", "Valider", 0, QApplication::UnicodeUTF8));
        pushButtonAnnuler->setText(QApplication::translate("ViewerClass", "Annuler", 0, QApplication::UnicodeUTF8));
        labelMinimum->setText(QApplication::translate("ViewerClass", "Minimum", 0, QApplication::UnicodeUTF8));
        labelMaximum->setText(QApplication::translate("ViewerClass", "Maximum", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewerClass: public Ui_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
