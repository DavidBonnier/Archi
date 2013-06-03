/********************************************************************************
** Form generated from reading UI file 'MaTaille.ui'
**
** Created: Sun 2. Jun 23:16:39 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATAILLE_H
#define UI_MATAILLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMaTaille
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitre;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelLargeur;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *spinBoxLargeur;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelHauteur;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBoxHauteur;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxProportionel;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *CMaTaille)
    {
        if (CMaTaille->objectName().isEmpty())
            CMaTaille->setObjectName(QString::fromUtf8("CMaTaille"));
        CMaTaille->resize(503, 361);
        verticalLayout = new QVBoxLayout(CMaTaille);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitre = new QLabel(CMaTaille);
        labelTitre->setObjectName(QString::fromUtf8("labelTitre"));

        verticalLayout->addWidget(labelTitre);

        widget = new QWidget(CMaTaille);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelLargeur = new QLabel(widget);
        labelLargeur->setObjectName(QString::fromUtf8("labelLargeur"));

        horizontalLayout_2->addWidget(labelLargeur);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        spinBoxLargeur = new QSpinBox(widget);
        spinBoxLargeur->setObjectName(QString::fromUtf8("spinBoxLargeur"));
        spinBoxLargeur->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(spinBoxLargeur);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(CMaTaille);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelHauteur = new QLabel(widget_2);
        labelHauteur->setObjectName(QString::fromUtf8("labelHauteur"));

        horizontalLayout_3->addWidget(labelHauteur);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        spinBoxHauteur = new QSpinBox(widget_2);
        spinBoxHauteur->setObjectName(QString::fromUtf8("spinBoxHauteur"));
        spinBoxHauteur->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(spinBoxHauteur);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_2);

        checkBoxProportionel = new QCheckBox(CMaTaille);
        checkBoxProportionel->setObjectName(QString::fromUtf8("checkBoxProportionel"));

        verticalLayout->addWidget(checkBoxProportionel);

        widget_3 = new QWidget(CMaTaille);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(216, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(widget_3);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addWidget(widget_3);


        retranslateUi(CMaTaille);

        QMetaObject::connectSlotsByName(CMaTaille);
    } // setupUi

    void retranslateUi(QWidget *CMaTaille)
    {
        CMaTaille->setWindowTitle(QApplication::translate("CMaTaille", "CMaTaille", 0, QApplication::UnicodeUTF8));
        labelTitre->setText(QApplication::translate("CMaTaille", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Taille de l'image :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelLargeur->setText(QApplication::translate("CMaTaille", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Largeur</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelHauteur->setText(QApplication::translate("CMaTaille", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Hauteur</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        checkBoxProportionel->setText(QApplication::translate("CMaTaille", "respect de la proportionalit\303\251", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMaTaille: public Ui_CMaTaille {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATAILLE_H
