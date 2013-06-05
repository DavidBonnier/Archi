#include "viewer.h"
#include <QMessageBox>
#include <QFileDialog>

Viewer::Viewer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags),
	AjoutEtoile(false)
{
	ui.setupUi(this);

	tailleImage=NULL;

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

	//Carractériqtique Images
	connect (ui.actionModification_de_la_Taille,SIGNAL(triggered()),this,SLOT(modifTailleImage()));
	connect (ui.actionMiroir_horizontal_de_l_image,SIGNAL(triggered()),this,SLOT(MiroirH()));
	connect (ui.actionMiroir_vertical_de_l_image,SIGNAL(triggered()),this,SLOT(MiroirV()));
	connect (ui.actionFaire_un_quart_de_tour,SIGNAL(triggered()),this,SLOT(Quart()));
	connect (ui.actionFaire_un_demi_tour,SIGNAL(triggered()),this,SLOT(DemiTour()));

	//Spzctre Image
	connect (ui.actionSpectre_de_l_image,SIGNAL(triggered()),this,SLOT(Histo()));
	ui.DWSpectreImage->hide();
	connect (ui.radioButtonSpectreBleu,SIGNAL(clicked()),this,SLOT(SpectreBleu()));
	connect (ui.radioButtonSpectreRouge,SIGNAL(clicked()),this,SLOT(SpectreRouge()));
	connect (ui.radioButtonSpectreVert,SIGNAL(clicked()),this,SLOT(SpectreVert()));
	connect (ui.radioButtonSpectreTout,SIGNAL(clicked()),this,SLOT(SpectreTout()));

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

	//QDockWidget Réglage des couleurs
	connect (ui.pButtonValiderCouleur,SIGNAL(clicked()),this,SLOT(ValidationCouleur()));
	connect (ui.pButtonAnnulerCouleur,SIGNAL(clicked()),this,SLOT(AnnulationCouleur()));
	connect (ui.hSliderLumosite,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	connect (ui.hSliderRouge,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	connect (ui.hSliderVert,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	connect (ui.hSliderBleu,SIGNAL(valueChanged(int)),this,SLOT(ReglageCouleur()));
	ui.DWReglage->hide();

	//Connect du menu Opération de base
	connect (ui.actionAddition,SIGNAL(triggered()),this,SLOT(Somme()));
	connect (ui.actionSoustraction,SIGNAL(triggered()),this,SLOT(Soustraire()));

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
	//Si l'image a été modifier car que je modifie AjoutEtoile passe a true
	if(AjoutEtoile)
		setWindowTitle("Visualisation d'images " + nomImage + "*");

	if(tailleImage!=NULL)
	{
		if(tailleImage->isHidden())
		{
			empilerAnnuler(Image);
			Image = Image.scaled(tailleImage->getDim());
			delete tailleImage;
			tailleImage = NULL;
		}
	}

	//Affcihe image sur le QLabel
	if (!Image.isNull()||!pixmap.isNull())
	{
		pixmap = QPixmap::fromImage(Image);
		ui.imageLabel->setPixmap(pixmap);
		ui.imageLabel->resize(pixmap.size());
	}
}

void Viewer::closeEvent(QCloseEvent *event)
{
	if (peutEtreSauver()) 
		event->accept();
	else
		event->ignore();
}


void Viewer::empilerAnnuler (QXImage img)
{
	//Dès que j'empile une image sa veut dire que je l'ai modifier donc *
	AjoutEtoile = true;
	Pile.push(img);
	PileNom.push(nomImage);
}

//Mondification des bouton action savoir si il sont utilisable ou non
void Viewer::boutonActionEnable(bool Enable)
{
	ui.actionFermer-> setEnabled(Enable);
	ui.actionSauver-> setEnabled(Enable);
	ui.actionSauver_sous-> setEnabled(Enable);
	ui.actionInverser_Image -> setEnabled(Enable);
	ui.actionImage_Noir_et_Blanc-> setEnabled(Enable);
	ui.actionModifications_des_couleurs-> setEnabled(Enable);
	ui.actionModification_de_la_Taille-> setEnabled(Enable);
	ui.actionMiroir_horizontal_de_l_image-> setEnabled(Enable);
	ui.actionMiroir_vertical_de_l_image-> setEnabled(Enable);
	ui.actionFaire_un_quart_de_tour-> setEnabled(Enable);
	ui.actionSpectre_de_l_image-> setEnabled(Enable);
	ui.actionSeuillage-> setEnabled(Enable);
	ui.actionAddition-> setEnabled(Enable);
	ui.actionSoustraction-> setEnabled(Enable);
	ui.actionFaire_un_demi_tour-> setEnabled(Enable);
}

bool Viewer::peutEtreSauver()
{
	if (AjoutEtoile) 
	{
		QMessageBox::StandardButton ret;
		ret = QMessageBox::warning(this, tr("Application"),
			tr("Ce document a été modifier.\n"
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

	empilerAnnuler(Image);
	return true;
}

bool Viewer::ouvertureFichier(QString &fichierOuvert, QXImage &imageOuvert)
{
	fichierOuvert=QFileDialog::getOpenFileName(this,tr("Ouverture d'un fichier Image"),MonRep,tr("Tout fichier(*);;(*.png *.jpg *.bmp)"));
	if(!fichierOuvert.isEmpty())
	{
		imageOuvert = QXImage(fichierOuvert);
		//Vue que l'on charge un fichier on peut passer les boutons action peuvent etre utilisés
		boutonActionEnable(true);
		return true;
	}
	else
		return false;
}



/************************************************************
---------------- SLOTS PRIVATE ------------------------------
************************************************************/

void Viewer::A_propos()
{
	QMessageBox::about(this,"A Propos d'Image Viewer",
		"Cet <b>Image Viewer</b> a été réalisé pour montrer"
		"<p> des exemples très simple de traitement d'images </p>"
		"<p> <b>D.Bonnier</b> .......... mars 2013-avril 2013</p>");
}

void Viewer::Ouvrir()
{
	//Si on a déjà un fichier on le ferme puis on ouvre autre
	if(!Fichier.isEmpty())
		Fermer();

	if(ouvertureFichier(Fichier, Image))
	{
		nomImage = Fichier.split("/").back();
		update();
	}
}

void Viewer::Sauver()
{
	empilerAnnuler(Image);
	Image.save(Fichier);
	AjoutEtoile = false;
	update();
}

void Viewer::Sauver_sous()
{
	Fichier = QFileDialog::getSaveFileName(this,tr("Sauvgarder Fichier"),MonRep,tr("(*.png *.jpg *.bmp)"));

	if(!Fichier.isEmpty())
	{
		//Vue que l'on a un fichier on peut passer les boutons action peuvent etre utilisés
		boutonActionEnable(true);
		nomImage = Fichier.split("/").back();
		Sauver();
		Image = QXImage(Fichier);
		update();
	}
}

void Viewer::Fermer()
{
	if(!nomImage.isEmpty())
	{
		if (peutEtreSauver())
		{
			ui.actionSeuillage->setChecked(false);
			ui.DWSeuillage->hide();
			ui.actionModifications_des_couleurs->setChecked(false);
			ui.DWReglage->hide();
			ui.actionSpectre_de_l_image->setChecked(false);
			ui.DWSpectreImage->hide();
			boutonActionEnable(false);
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

		//Depile la dernière image d'annuler en courante
		Image = Pile.pop();
		nomImage = PileNom.pop();
		AjoutEtoile = true;
		update();
	}
	else
		QMessageBox::information(this,"Image Viewer",
		"La pile est vide");

	if(nomImage.isEmpty())
		boutonActionEnable(false);
	else
		boutonActionEnable(true);
}

void Viewer::DepilerRefaire ()
{
	if(!PileR.empty()&&!PileNomR.empty())
	{
		//Empile sur Annuler l'image courante
		empilerAnnuler (Image);

		//Depile la dernière image d'annuler en courante
		Image = PileR.pop();
		nomImage = PileNomR.pop();
		update();
	}
	else
		QMessageBox::information(this,"Image Viewer",
		"La pile est vide");

	if(nomImage.isEmpty())
		boutonActionEnable(false);
	else
		boutonActionEnable(true);
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
	empilerAnnuler(Image);
	Image.toGrayscale();
}

void Viewer::InverserImage()
{
	empilerAnnuler(Image);
	Image.invertPixels();
}

void Viewer::AfficheSeuillageWidget()
{
	if(ui.actionSeuillage->isChecked())
	{
		ui.actionModifications_des_couleurs->setChecked(false);
		ui.DWReglage->hide();
		ui.actionSpectre_de_l_image->setChecked(false);
		ui.DWSpectreImage->hide();
		ui.DWSeuillage->show();
	}
	else
		ui.DWSeuillage->hide();

	ImageTemp = Image;
	ChangementSeuillage();
}

void Viewer::ValidationSeuillage()
{
	empilerAnnuler(ImageTemp);
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
	if(ui.actionModifications_des_couleurs->isChecked())
	{
		ui.actionSeuillage->setChecked(false);
		ui.DWSeuillage->hide();
		ui.actionSpectre_de_l_image->setChecked(false);
		ui.DWSpectreImage->hide();
		ui.DWReglage->show();
	}
	else
		ui.DWReglage->hide();

	ImageTemp = Image;
	ReglageCouleur();
}

void Viewer::ValidationCouleur()
{
	empilerAnnuler(ImageTemp);
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

	Image.Reglage(alpha, rouge, vert, bleu);

	ui.labelNbLumosite->setText(QString::number(alpha));
	ui.labelNbRouge->setText(QString::number(rouge));
	ui.labelNbVert->setText(QString::number(vert));
	ui.labelNbBleu->setText(QString::number(bleu));
}

void Viewer::modifTailleImage()
{
	tailleImage =  new CMaTaille (this, Image.width(),Image.height());
	tailleImage->show();
}

void Viewer::MiroirH ()
{
	empilerAnnuler(Image);
	Image = Image.mirrored(true,false);
}

void Viewer::MiroirV ()
{
	empilerAnnuler(Image);
	//Valeur par défaut mais plus clair
	Image = Image.mirrored(false,true);
}

void Viewer::Quart ()
{
	empilerAnnuler(Image);
	Image = Image.Tourner(1);
}

void Viewer::DemiTour ()
{
	empilerAnnuler(Image);
	Image = Image.Tourner(2);
}

void Viewer::Histo ()
{
	if(ui.actionSpectre_de_l_image->isChecked())
	{
		ui.actionSeuillage->setChecked(false);
		ui.DWSeuillage->hide();
		ui.actionModifications_des_couleurs->setChecked(false);
		ui.DWReglage->hide();
		ui.DWSpectreImage->show();
	}
	else
		ui.DWSpectreImage->hide();

	ImageTemp = Image;
}

void Viewer::SpectreBleu()
{
	int Max;
	Image.Histo(3,Max);
}

void Viewer::SpectreRouge()
{
	int Max;
	Image.Histo(1,Max);
}

void Viewer::SpectreVert()
{
	int Max;
	Image.Histo(2,Max);
}

void Viewer::SpectreTout()
{
	int Max;
	Image.Histo(0,Max);
}

void Viewer::Soustraire()
{
	QXImage imaTemp;
	QString strTemp;
	if(ouvertureFichier(strTemp,imaTemp))
	{
		empilerAnnuler(Image);
		Image.SommeSoustraire(imaTemp, -1);
	}
	update();
}

void Viewer::Somme()
{
	QXImage imaTemp;
	QString strTemp;
	if(ouvertureFichier(strTemp,imaTemp))
	{
		empilerAnnuler(Image);
		Image.SommeSoustraire(imaTemp);
	}
	update();
}