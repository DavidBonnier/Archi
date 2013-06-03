/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created: Mon 3. Jun 11:21:49 2013
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
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
    QAction *actionMiroir_horizontal_de_l_image;
    QAction *actionMiroir_vertical_de_l_image;
    QAction *actionFaire_un_quart_de_tour;
    QAction *actionSpectre_de_l_image;
    QAction *actionAddition;
    QAction *actionSoustraction;
    QWidget *centralWidget;
    QLabel *imageLabel;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuCaract_riqtique_Images;
    QMenu *menuModif;
    QMenu *menu;
    QMenu *menuOperations_de_base;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *DWSeuillage;
    QWidget *dockWidgetContents_3;
    QFormLayout *formLayout_2;
    QPushButton *pButtonValiderSeuillage;
    QPushButton *pButtonAnnulerSeuillage;
    QLabel *labelMinSeuillage;
    QLabel *labelMaxSeuillage;
    QSpinBox *spinBoxMinSeuillage;
    QSpinBox *spinBoxMaxSeuillage;
    QDockWidget *DWReglage;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    QLabel *labelRouge;
    QSlider *hSliderRouge;
    QSlider *hSliderBleu;
    QSlider *hSliderVert;
    QLabel *labelNbRouge;
    QLabel *labelVert;
    QLabel *labelNbLumosite;
    QLabel *labelNbVert;
    QLabel *labelBleu;
    QLabel *labelNbBleu;
    QPushButton *pButtonValiderCouleur;
    QPushButton *pButtonAnnulerCouleur;
    QLabel *labelLuminosite;
    QSlider *hSliderLumosite;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *ViewerClass)
    {
        if (ViewerClass->objectName().isEmpty())
            ViewerClass->setObjectName(QString::fromUtf8("ViewerClass"));
        ViewerClass->resize(600, 401);
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
        actionMiroir_horizontal_de_l_image = new QAction(ViewerClass);
        actionMiroir_horizontal_de_l_image->setObjectName(QString::fromUtf8("actionMiroir_horizontal_de_l_image"));
        actionMiroir_horizontal_de_l_image->setEnabled(false);
        actionMiroir_vertical_de_l_image = new QAction(ViewerClass);
        actionMiroir_vertical_de_l_image->setObjectName(QString::fromUtf8("actionMiroir_vertical_de_l_image"));
        actionMiroir_vertical_de_l_image->setEnabled(false);
        actionFaire_un_quart_de_tour = new QAction(ViewerClass);
        actionFaire_un_quart_de_tour->setObjectName(QString::fromUtf8("actionFaire_un_quart_de_tour"));
        actionFaire_un_quart_de_tour->setEnabled(false);
        actionSpectre_de_l_image = new QAction(ViewerClass);
        actionSpectre_de_l_image->setObjectName(QString::fromUtf8("actionSpectre_de_l_image"));
        actionSpectre_de_l_image->setEnabled(false);
        actionAddition = new QAction(ViewerClass);
        actionAddition->setObjectName(QString::fromUtf8("actionAddition"));
        actionAddition->setEnabled(false);
        actionSoustraction = new QAction(ViewerClass);
        actionSoustraction->setObjectName(QString::fromUtf8("actionSoustraction"));
        actionSoustraction->setEnabled(false);
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
        menuOperations_de_base = new QMenu(menuBar);
        menuOperations_de_base->setObjectName(QString::fromUtf8("menuOperations_de_base"));
        ViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ViewerClass->setStatusBar(statusBar);
        DWSeuillage = new QDockWidget(ViewerClass);
        DWSeuillage->setObjectName(QString::fromUtf8("DWSeuillage"));
        DWSeuillage->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        formLayout_2 = new QFormLayout(dockWidgetContents_3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        pButtonValiderSeuillage = new QPushButton(dockWidgetContents_3);
        pButtonValiderSeuillage->setObjectName(QString::fromUtf8("pButtonValiderSeuillage"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, pButtonValiderSeuillage);

        pButtonAnnulerSeuillage = new QPushButton(dockWidgetContents_3);
        pButtonAnnulerSeuillage->setObjectName(QString::fromUtf8("pButtonAnnulerSeuillage"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pButtonAnnulerSeuillage);

        labelMinSeuillage = new QLabel(dockWidgetContents_3);
        labelMinSeuillage->setObjectName(QString::fromUtf8("labelMinSeuillage"));
        labelMinSeuillage->setFrameShape(QFrame::NoFrame);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelMinSeuillage);

        labelMaxSeuillage = new QLabel(dockWidgetContents_3);
        labelMaxSeuillage->setObjectName(QString::fromUtf8("labelMaxSeuillage"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelMaxSeuillage);

        spinBoxMinSeuillage = new QSpinBox(dockWidgetContents_3);
        spinBoxMinSeuillage->setObjectName(QString::fromUtf8("spinBoxMinSeuillage"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBoxMinSeuillage);

        spinBoxMaxSeuillage = new QSpinBox(dockWidgetContents_3);
        spinBoxMaxSeuillage->setObjectName(QString::fromUtf8("spinBoxMaxSeuillage"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBoxMaxSeuillage);

        DWSeuillage->setWidget(dockWidgetContents_3);
        ViewerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DWSeuillage);
        DWReglage = new QDockWidget(ViewerClass);
        DWReglage->setObjectName(QString::fromUtf8("DWReglage"));
        DWReglage->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelRouge = new QLabel(dockWidgetContents_2);
        labelRouge->setObjectName(QString::fromUtf8("labelRouge"));

        gridLayout->addWidget(labelRouge, 4, 1, 1, 1);

        hSliderRouge = new QSlider(dockWidgetContents_2);
        hSliderRouge->setObjectName(QString::fromUtf8("hSliderRouge"));
        hSliderRouge->setMinimum(-100);
        hSliderRouge->setMaximum(100);
        hSliderRouge->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hSliderRouge, 4, 0, 1, 1);

        hSliderBleu = new QSlider(dockWidgetContents_2);
        hSliderBleu->setObjectName(QString::fromUtf8("hSliderBleu"));
        hSliderBleu->setMinimum(-100);
        hSliderBleu->setMaximum(100);
        hSliderBleu->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hSliderBleu, 6, 0, 1, 1);

        hSliderVert = new QSlider(dockWidgetContents_2);
        hSliderVert->setObjectName(QString::fromUtf8("hSliderVert"));
        hSliderVert->setMinimum(-100);
        hSliderVert->setMaximum(100);
        hSliderVert->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hSliderVert, 5, 0, 1, 1);

        labelNbRouge = new QLabel(dockWidgetContents_2);
        labelNbRouge->setObjectName(QString::fromUtf8("labelNbRouge"));

        gridLayout->addWidget(labelNbRouge, 4, 2, 1, 1);

        labelVert = new QLabel(dockWidgetContents_2);
        labelVert->setObjectName(QString::fromUtf8("labelVert"));

        gridLayout->addWidget(labelVert, 5, 1, 1, 1);

        labelNbLumosite = new QLabel(dockWidgetContents_2);
        labelNbLumosite->setObjectName(QString::fromUtf8("labelNbLumosite"));

        gridLayout->addWidget(labelNbLumosite, 2, 2, 1, 1);

        labelNbVert = new QLabel(dockWidgetContents_2);
        labelNbVert->setObjectName(QString::fromUtf8("labelNbVert"));

        gridLayout->addWidget(labelNbVert, 5, 2, 1, 1);

        labelBleu = new QLabel(dockWidgetContents_2);
        labelBleu->setObjectName(QString::fromUtf8("labelBleu"));

        gridLayout->addWidget(labelBleu, 6, 1, 1, 1);

        labelNbBleu = new QLabel(dockWidgetContents_2);
        labelNbBleu->setObjectName(QString::fromUtf8("labelNbBleu"));

        gridLayout->addWidget(labelNbBleu, 6, 2, 1, 1);

        pButtonValiderCouleur = new QPushButton(dockWidgetContents_2);
        pButtonValiderCouleur->setObjectName(QString::fromUtf8("pButtonValiderCouleur"));

        gridLayout->addWidget(pButtonValiderCouleur, 8, 0, 1, 1);

        pButtonAnnulerCouleur = new QPushButton(dockWidgetContents_2);
        pButtonAnnulerCouleur->setObjectName(QString::fromUtf8("pButtonAnnulerCouleur"));

        gridLayout->addWidget(pButtonAnnulerCouleur, 8, 1, 1, 2);

        labelLuminosite = new QLabel(dockWidgetContents_2);
        labelLuminosite->setObjectName(QString::fromUtf8("labelLuminosite"));
        labelLuminosite->setLineWidth(1);

        gridLayout->addWidget(labelLuminosite, 1, 0, 1, 1);

        hSliderLumosite = new QSlider(dockWidgetContents_2);
        hSliderLumosite->setObjectName(QString::fromUtf8("hSliderLumosite"));
        hSliderLumosite->setMinimum(-100);
        hSliderLumosite->setMaximum(100);
        hSliderLumosite->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hSliderLumosite, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        DWReglage->setWidget(dockWidgetContents_2);
        ViewerClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DWReglage);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuCaract_riqtique_Images->menuAction());
        menuBar->addAction(menuModif->menuAction());
        menuBar->addAction(menuOperations_de_base->menuAction());
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
        menuCaract_riqtique_Images->addAction(actionMiroir_horizontal_de_l_image);
        menuCaract_riqtique_Images->addAction(actionMiroir_vertical_de_l_image);
        menuCaract_riqtique_Images->addAction(actionFaire_un_quart_de_tour);
        menuCaract_riqtique_Images->addSeparator();
        menuCaract_riqtique_Images->addAction(actionSpectre_de_l_image);
        menuModif->addAction(actionImage_Noir_et_Blanc);
        menuModif->addAction(actionInverser_Image);
        menuModif->addAction(actionSeuillage);
        menuModif->addAction(actionModifications_des_couleurs);
        menu->addAction(actionAide);
        menu->addAction(actionA_propos);
        menuOperations_de_base->addAction(actionAddition);
        menuOperations_de_base->addAction(actionSoustraction);

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
        actionMiroir_horizontal_de_l_image->setText(QApplication::translate("ViewerClass", "Miroir horizontal de l'image", 0, QApplication::UnicodeUTF8));
        actionMiroir_vertical_de_l_image->setText(QApplication::translate("ViewerClass", "Miroir vertical de l'image", 0, QApplication::UnicodeUTF8));
        actionFaire_un_quart_de_tour->setText(QApplication::translate("ViewerClass", "Faire un quart de tour", 0, QApplication::UnicodeUTF8));
        actionSpectre_de_l_image->setText(QApplication::translate("ViewerClass", "Spectre de l'image", 0, QApplication::UnicodeUTF8));
        actionAddition->setText(QApplication::translate("ViewerClass", "Addition", 0, QApplication::UnicodeUTF8));
        actionSoustraction->setText(QApplication::translate("ViewerClass", "Soustraction", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        menuFichier->setTitle(QApplication::translate("ViewerClass", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("ViewerClass", "Edition", 0, QApplication::UnicodeUTF8));
        menuCaract_riqtique_Images->setTitle(QApplication::translate("ViewerClass", "Caract\303\251riqtique Images", 0, QApplication::UnicodeUTF8));
        menuModif->setTitle(QApplication::translate("ViewerClass", "Modif", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ViewerClass", "?", 0, QApplication::UnicodeUTF8));
        menuOperations_de_base->setTitle(QApplication::translate("ViewerClass", "Operations de base", 0, QApplication::UnicodeUTF8));
        DWSeuillage->setWindowTitle(QApplication::translate("ViewerClass", "Seuillage", 0, QApplication::UnicodeUTF8));
        pButtonValiderSeuillage->setText(QApplication::translate("ViewerClass", "Valider", 0, QApplication::UnicodeUTF8));
        pButtonAnnulerSeuillage->setText(QApplication::translate("ViewerClass", "Annuler", 0, QApplication::UnicodeUTF8));
        labelMinSeuillage->setText(QApplication::translate("ViewerClass", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Minimum</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelMaxSeuillage->setText(QApplication::translate("ViewerClass", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Maximum</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        DWReglage->setWindowTitle(QApplication::translate("ViewerClass", "R\303\251glage des couleurs", 0, QApplication::UnicodeUTF8));
        labelRouge->setText(QApplication::translate("ViewerClass", "<html><head/><body><p><span style=\" font-size:10pt; color:#ff0000;\">R</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelNbRouge->setText(QApplication::translate("ViewerClass", "00", 0, QApplication::UnicodeUTF8));
        labelVert->setText(QApplication::translate("ViewerClass", "<html><head/><body><p><span style=\" font-size:10pt; color:#00ff00;\">V</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelNbLumosite->setText(QApplication::translate("ViewerClass", "00", 0, QApplication::UnicodeUTF8));
        labelNbVert->setText(QApplication::translate("ViewerClass", "00", 0, QApplication::UnicodeUTF8));
        labelBleu->setText(QApplication::translate("ViewerClass", "<html><head/><body><p><span style=\" font-size:10pt; color:#0000ff;\">B</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelNbBleu->setText(QApplication::translate("ViewerClass", "00", 0, QApplication::UnicodeUTF8));
        pButtonValiderCouleur->setText(QApplication::translate("ViewerClass", "Valider", 0, QApplication::UnicodeUTF8));
        pButtonAnnulerCouleur->setText(QApplication::translate("ViewerClass", "Annuler", 0, QApplication::UnicodeUTF8));
        labelLuminosite->setText(QApplication::translate("ViewerClass", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Luminosit\303\251</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewerClass: public Ui_ViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
