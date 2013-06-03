#ifndef MATAILLE_H
#define MATAILLE_H

#include <QDialog>
#include <QSize>
#include "ui_MaTaille.h"

class CMaTaille : public QDialog
{
	Q_OBJECT
public:
	CMaTaille(QWidget *parent, int Largeur, int Hauteur);
	~CMaTaille();
	QSize getDim ();
	bool IsModifier;

private:
	Ui::CMaTaille ui;
	double m_proportion;
	int m_nLargeur;
	int m_nHauteur;

private slots:
	void MonOk();
	void Larg();
	void Haut();
};

#endif // MATAILLE_H
