#ifndef VIEWER_H
#define VIEWER_H

#include <QtGui/QMainWindow>
#include "ui_viewer.h"

#include "QXImage.h"

#include "QPoint"
#include <QString>
#include <QScrollArea>
#include <QCloseEvent>
#include <QStack>

class Viewer : public QMainWindow
{
	Q_OBJECT

public:
	Viewer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Viewer();
	QXImage Image;
	QXImage ImageTemp;
	QPixmap pixmap;
	QPoint Dim;

private:
	Ui::ViewerClass ui;
	QString MonRep;
	QString Fichier;
	QString nomImage;
	QScrollArea *scrollArea;
	bool AjoutEtoile;

	QStack <QXImage> Pile ; // pile des images pour annuler
	QStack<QString> PileNom; // pile des noms d'images pour annuler
	QStack <QXImage> PileR ; // pile des images pour refaire
	QStack<QString> PileNomR; // pile des noms d'images pour refaire

public :

private:
	void paintEvent ( QPaintEvent * event);
	void closeEvent ( QCloseEvent *event);

	void EmpilerAnnuler( QXImage img);

	void BoutonActionEnable ( bool Enable);
	bool peutEtreSauver ();

private slots:
	void A_propos ();
	void Ouvrir ();
	void Sauver ();
	void Sauver_sous ();
	void Fermer ();
	void DepilerAnnuler ();
	void DepilerRefaire ();
	void DetruirePiles ();
	void ImageNoirBlanc();
	void InverserImage();
	void AfficheSeuillageWidget();
	void ValidationSeuillage();
	void AnnulationSeuillage();
	void ChangementSeuillage();
};

#endif // VIEWER_H
