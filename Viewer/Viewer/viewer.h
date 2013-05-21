#ifndef VIEWER_H
#define VIEWER_H

#include <QtGui/QMainWindow>
#include "ui_viewer.h"
#include "QPoint"
#include "QXImage.h"
#include <QString>

class Viewer : public QMainWindow
{
	Q_OBJECT

public:
	Viewer(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Viewer();
	QImage *Image;
	QPixmap *pixmap;
	QPoint Dim;

private:
	Ui::ViewerClass ui;
	QString *MonRep;
	QString Fichier;

public :
	void paintEvent(QPaintEvent * evt);

private:


public slots:
	void A_propos();
	void Ouvrir();
	void Quitter();
	void Sauver();
	void Sauver_sous();
	void Fermer();
};

#endif // VIEWER_H
