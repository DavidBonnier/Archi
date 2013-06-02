#include "viewer.h"
#include <QMessageBox>
#include <QFileDialog>

Viewer::Viewer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),
	AjoutEtoile(false)
{
	ui.setupUi(this);
	//Connect du menu Fichier
	connect (ui.actionA_propos,SIGNAL(triggered()),this,SLOT(A_propos()));
	connect (ui.actionOuvrir,SIGNAL(triggered()),this,SLOT(Ouvrir()));
	connect (ui.actionSauver,SIGNAL(triggered()),this,SLOT(Sauver()));
	connect (ui.actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
	connect (ui.actionSauver_sous,SIGNAL(triggered()),this,SLOT(Sauver_sous()));
	connect (ui.actionFermer,SIGNAL(triggered()),this,SLOT(Fermer()));

	//Connect du menu edition
	connect (ui.actionAnnuler,SIGNAL(triggered()),this,SLOT(DepilerAnnuler()));
	connect (ui.actionRefaire,SIGNAL(triggered()),this,SLOT(DepilerRefaire()));
	connect (ui.actionDetruire_Pile_Avant_et_Arri_re,SIGNAL(triggered()),this,SLOT(DetruirePiles()));

	//Connect du menu modif
	connect (ui.actionImage_Noir_et_Blanc,SIGNAL(triggered()),this,SLOT(ImageNoirBlanc()));
	connect (ui.actionInverser_Image,SIGNAL(triggered()),this,SLOT(InverserImage()));
	connect (ui.actionSeuillage,SIGNAL(triggered()),this,SLOT(AfficheSeuillageWidget()));
	connect (ui.actionModifications_des_couleurs,SIGNAL(triggered()),this,SLOT(AfficheReglageWidget()));

	//QDockWidget Seuillage
	connect (ui.pButtonValiderSeuillage,SIGNAL(clicked()),this,SLOT(ValidationSeuillage()));
	connect (ui.pButtonAnnulerSeuillage,SIGNAL(clicked()),this,SLOT(AnnulationSeuillage()));
	connect (ui.spinBoxMaxSeuillage,SIGNAL(valueChanged(int)),this,SLOT(ChangementSeuillage()));
	connect (ui.spinBoxMinSeuillage,SIGNAL(valueChanged(int)),this,SLOT(ChangementSeuillage()));
	ui.DWSeuillage->hide();
	ui.spinBoxMaxSeuillage->setRange(0,255);
	ui.spinBoxMinSeuillage->setRange(0,255);

	//QDockWidget R�glage des couleurs
	connect (ui.pButtonValiderCouleur,SIGNAL(clicked()),this,SLOT(ValidationCouleur()));
	connect (ui.pButtonAnnulerCouleur,SIGNAL(clicked()),this,SLOT(AnnulationCouleur()));
	connect (ui.hSliderLumosite,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	connect (ui.hSliderRouge,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	connect (ui.hSliderVert,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	connect (ui.hSliderBleu,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	ui.DWReglage->hide();

	//Initialisation des scrollBar quand image est trop grand
	scrollArea = new QScrollArea;
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setWidget(ui.imageLabel);
	setCentralWidget(scrollArea);

	MonRep = QString("../../Fichier");
}

Viewer::~Viewer()
{
}


void Viewer::paintEvent(QPaintEvent * evt)
{
	//Getion du titre de la fenetre avec un bool pour etoile ou pas
	setWindowTitle("Visualisation d'images " + nomImage);
	if(AjoutEtoile)
		setWindowTitle("Visualisation d'images " + nomImage + "*");

	//Affcihe image sur le QLabel
	if (!Image.isNull()||!pixmap.isNull())
	{
		pixmap = QPixmap::fromImage(Image);
		ui.imageLabel->setPixmap(pixmap);
		ui.imageLabel->resize(pixmap.size());
	}

	//J'ai touv� cette parade si on ferme le dock widget par la croix
	if(ui.DWSeuillage->isVisible())
		ui.actionSeuillage->setChecked(true);
	else
		ui.actionSeuillage->setChecked(false);

	if(ui.DWReglage->isVisible())
		ui.actionModifications_des_couleurs->setChecked(true);
	else
		ui.actionModifications_des_couleurs->setChecked(false);
}

void Viewer::closeEvent(QCloseEvent *event)
{
	if (peutEtreSauver()) 
		event->accept();
	else
		event->ignore();
}


void Viewer::EmpilerAnnuler (QXImage img)
{
	Pile.push(img);
	PileNom.push(nomImage);
}

//Mondification des bouton action savoir si il sont utilisable ou non
void Viewer::BoutonActionEnable(bool Enable)
{
	ui.actionFermer-> setEnabled(Enable);
	ui.actionSauver-> setEnabled(Enable);
	ui.actionSauver_sous-> setEnabled(Enable);
	ui.actionInverser_Image -> setEnabled(Enable);
	ui.actionImage_Noir_et_Blanc-> setEnabled(Enable);
	ui.actionModifications_des_couleurs-> setEnabled(Enable);
	ui.actionModification_de_la_Taille-> setEnabled(Enable);
	ui.actionSeuillage-> setEnabled(Enable);
}

bool Viewer::peutEtreSauver()
{
	if (AjoutEtoile) 
	{
		QMessageBox::StandardButton ret;
		ret = QMessageBox::warning(this, tr("Application"),
			tr("Ce document a �t� modifier.\n"
			"Voulez vous sauvgarder les chnagements ?"),
			QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		if (ret == QMessageBox::Save)
		{
			Sauver();
			return true;
		}
		else if (ret == QMessageBox::Cancel)
			return false;
	}

	EmpilerAnnuler(Image);
	return true;
}



/************************************************************
---------------- SLOTS PRIVATE ------------------------------
************************************************************/

void Viewer::A_propos()
{
	QMessageBox::about(this,"A Propos d'Image Viewer",
		"Cet <b>Image Viewer</b> a �t� r�alis� pour montrer"
		"<p> des exemples tr�s simple de traitement d'images </p>"
		"<p> <b>D.Bonnier</b> .......... mars 2013-avril 2013</p>");
}

void Viewer::Ouvrir()
{
	//Si on a d�j� un fichier on le ferme puis on ouvre autre
	if(!Fichier.isEmpty())
		Fermer();

	Fichier=QFileDialog::getOpenFileName(this,tr("Ouverture d'un fichier Image"),MonRep,tr("Tout fichier(*);;(*.png *.jpg *.bmp)"));
	if(!Fichier.isEmpty())
	{
		Image = QXImage(Fichier);
		//Vue que l'on charge un fichier on peut passer les boutons action peuvent etre utilis�s
		BoutonActionEnable(true);
		nomImage = Fichier.split("/").back();
		update();
	}
}

void Viewer::Sauver()
{
	EmpilerAnnuler(Image);
	Image.save(Fichier);
	AjoutEtoile = false;
	update();
}

void Viewer::Sauver_sous()
{
	Fichier = QFileDialog::getSaveFileName(this,tr("Sauvgarder Fichier"),MonRep,tr("Tout fichier(*);;(*.png *.jpg *.bmp)"));
	Sauver();
}

void Viewer::Fermer()
{
	ui.actionSeuillage->setChecked(false);
	ui.DWSeuillage->hide();
	BoutonActionEnable(false);

	if(!nomImage.isEmpty())
	{
		if (peutEtreSauver())
		{
			nomImage = "";
			Image = QXImage(nomImage);
			AjoutEtoile = false;
			update();
		}
	}
}

void Viewer::DepilerAnnuler ()
{
	if(!Pile.empty()&&!PileNom.empty())
	{
		//Empile sur Refaire l'image courante
		PileR.push(Image);
		PileNomR.push(nomImage);

		//Depile la derni�re image d'annuler en courante
		Image = Pile.pop();
		nomImage = PileNom.pop();
		update();
	}
	else
		QMessageBox::information(this,"Image Viewer",
		"La pile est vide");

	if(nomImage.isEmpty())
		BoutonActionEnable(false);
	else
		BoutonActionEnable(true);
}

void Viewer::DepilerRefaire ()
{
	if(!PileR.empty()&&!PileNomR.empty())
	{
		//Empile sur Annuler l'image courante
		EmpilerAnnuler (Image);

		//Depile la derni�re image d'annuler en courante
		Image = PileR.pop();
		nomImage = PileNomR.pop();
		update();
	}
	else
		QMessageBox::information(this,"Image Viewer",
		"La pile est vide");

	if(nomImage.isEmpty())
		BoutonActionEnable(false);
	else
		BoutonActionEnable(true);
}

void Viewer::DetruirePiles ()
{
	Pile.clear();
	PileNom.clear();
	PileR.clear();
	PileNomR.clear();
}

void Viewer::ImageNoirBlanc()
{
	AjoutEtoile = true;
	EmpilerAnnuler(Image);
	Image.toGrayscale();
}

void Viewer::InverserImage()
{
	AjoutEtoile = true;
	EmpilerAnnuler(Image);
	Image.invertPixels();
}

void Viewer::AfficheSeuillageWidget()
{
	if(ui.actionModifications_des_couleurs->isChecked())
	{
		ui.actionModifications_des_couleurs->setChecked(false);
		ui.DWReglage->hide();
	}

	if(ui.actionSeuillage->isChecked())
		ui.DWSeuillage->show();
	else
		ui.DWSeuillage->hide();

	ImageTemp = Image;
}

void Viewer::ValidationSeuillage()
{
	AjoutEtoile = true;
	EmpilerAnnuler(ImageTemp);
	ui.DWSeuillage->hide();
	ui.actionSeuillage->setChecked(false);
}

void Viewer::AnnulationSeuillage()
{
	ui.spinBoxMinSeuillage->setValue(0);
	ui.spinBoxMaxSeuillage->setValue(0);
	Image = ImageTemp;
}

void Viewer::ChangementSeuillage()
{
	Image = ImageTemp;
	int Min = ui.spinBoxMinSeuillage->value();
	int Max = ui.spinBoxMaxSeuillage->value();
	ui.spinBoxMinSeuillage->setMaximum(Max);
	ui.spinBoxMaxSeuillage->setMinimum(Min);
	Image.Seuillage(Min, Max);
}

void Viewer::AfficheReglageWidget()
{
	if(ui.actionSeuillage->isChecked())
	{
		ui.actionSeuillage->setChecked(false);
		ui.DWSeuillage->hide();
	}

	if(ui.actionModifications_des_couleurs->isChecked())
		ui.DWReglage->show();
	else
		ui.DWReglage->hide();

	ImageTemp = Image;
}

void Viewer::ValidationCouleur()
{
	AjoutEtoile = true;
	EmpilerAnnuler(ImageTemp);
	ui.DWReglage->hide();
	ui.actionModifications_des_couleurs->setChecked(false);
}

void Viewer::AnnulationCouleur()
{
	ui.hSliderLumosite->setValue(0);
	ui.hSliderRouge->setValue(0);
	ui.hSliderVert->setValue(0);
	ui.hSliderBleu->setValue(0);
	Image = ImageTemp;
}

void Viewer::ReglageCouleur()
{
	Image = ImageTemp;
	int alpha = ui.hSliderLumosite->value();
	int rouge = ui.hSliderRouge->value();
	int vert = ui.hSliderVert->value();
	int bleu = ui.hSliderBleu->value();

	Image.Reglage(rouge, vert, bleu);

	ui.labelNbLumosite->setText(QString::number(alpha));
	ui.labelNbRouge->setText(QString::number(rouge));
	ui.labelNbVert->setText(QString::number(vert));
	ui.labelNbBleu->setText(QString::number(bleu));
}