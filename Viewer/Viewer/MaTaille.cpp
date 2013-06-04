#include "MaTaille.h"

CMaTaille::CMaTaille(QWidget *parent, int Largeur, int Hauteur)
	: QDialog(parent),
	m_nLargeur(Largeur),
	m_nHauteur(Hauteur)
{
	ui.setupUi(this);
	IsModifier=false;
	m_proportion = static_cast<double>(Hauteur) /Largeur;

	ui.spinBoxHauteur->setMinimum(0);
	ui.spinBoxHauteur->setMaximum(Hauteur*3);
	ui.spinBoxHauteur->setValue(Hauteur);
	ui.spinBoxLargeur->setMinimum(0);
	ui.spinBoxLargeur->setMaximum(Largeur*3);
	ui.spinBoxLargeur->setValue(Largeur);

	connect (ui.spinBoxHauteur,SIGNAL(valueChanged(int)),this,SLOT(Haut()));
	connect (ui.spinBoxLargeur,SIGNAL(valueChanged(int)),this,SLOT(Larg()));
	connect (ui.buttonBox,SIGNAL(accepted()),this,SLOT(MonOk()));
	connect (ui.buttonBox,SIGNAL(rejected()),this,SLOT(close()));
}

CMaTaille::~CMaTaille()
{

}

QSize CMaTaille::getDim ()
{
	return QSize(m_nLargeur, m_nHauteur);
}

void CMaTaille::MonOk()
{
	m_nLargeur = ui.spinBoxLargeur->value();
	m_nHauteur = ui.spinBoxHauteur->value();
	close();
}

void CMaTaille::Larg()
{
	if(!IsModifier)
	{
		if(ui.checkBoxProportionel->isChecked())
		{
			IsModifier=true;
			ui.spinBoxHauteur->setValue(ui.spinBoxLargeur->value()*m_proportion);
		}
	}
	else
		IsModifier=false;
}

void CMaTaille::Haut()
{
	if(!IsModifier)
	{
		if(ui.checkBoxProportionel->isChecked())
		{
			IsModifier=true;
			ui.spinBoxLargeur->setValue(ui.spinBoxHauteur->value()/m_proportion);
		}
	}
	else
		IsModifier=false;
}
