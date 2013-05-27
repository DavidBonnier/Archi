#include "viewer.h"
#include <QMessageBox>
#include <QFileDialog>

Viewer::Viewer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),
	Image(NULL)
{
	ui.setupUi(this);
	connect (ui.actionA_propos,SIGNAL(triggered()),this,SLOT(A_propos()));
	connect (ui.actionOuvrir,SIGNAL(triggered()),this,SLOT(Ouvrir()));
	connect (ui.actionSauver,SIGNAL(triggered()),this,SLOT(Sauvegarder()));
	connect (ui.actionQuitter,SIGNAL(triggered()),this,SLOT(Quitter()));
	connect (ui.actionSauver_sous,SIGNAL(triggered()),this,SLOT(Sauver_sous()));
	connect (ui.actionFermer,SIGNAL(triggered()),this,SLOT(Fermer()));

	MonRep=new QString("../../Fichier");
}

Viewer::~Viewer()
{
	delete MonRep;
}


void Viewer::A_propos()
{
	QMessageBox::about(this,"A Propos d'Image Viewer",
		"Cet <b>Image Viewer</b> a été réalisé pour montrer"
		"<p> des exemples très simple de traitement d'images </p>"
		"<p> <b>D.Bonnier</b> .......... mars 2013-avril 2013</p>");
}

void Viewer::Ouvrir()
{
	Fichier=QFileDialog::getOpenFileName(this,tr("Fichier a ouvrir"),*MonRep,tr("Tout fichier(*);;(*.png *.jpg *.bmp)"));
	if(Fichier != NULL)
	{
		Image = new QImage(Fichier);
		update();
	}
}

void Viewer::Quitter()
{
	close();
}

void Viewer::Sauver()
{

}

void Viewer::Sauver_sous()
{

}

void Viewer::Fermer()
{

}

void Viewer::paintEvent(QPaintEvent * evt)
{
	if (Image!= NULL)
	{
		*pixmap = QPixmap::fromImage(*Image) ;
		int h = pixmap->height() ;
		int w = pixmap->width() ;
		Dim.setX(w);
		Dim.setY(h) ;
		ui.imageLabel->setGeometry(0,0,Dim.x(),Dim.y()) ;
		ui.imageLabel->setPixmap(*pixmap) ;
	}
}