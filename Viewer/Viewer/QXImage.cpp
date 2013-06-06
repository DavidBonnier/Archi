#include "qximage.h"
#include "qstring.h"
#include "qtransform.h"

QXImage::QXImage()
{
}

QXImage::QXImage(QImage image)
	:QImage(image)
{
}

QXImage::QXImage(QString nomFichier)
	: QImage(nomFichier)
{
}

QXImage::~QXImage()
{
}

QXImage& QXImage::operator = (const QImage &image)
{
	return *this = QXImage(image);
}

void QXImage::Histo (int *tableau, int Coul, int &Maxi)
{
	Maxi=0;
	switch(Coul)
	{
	case 1:
		for(int i=0; i<width(); i++)
			for(int j=0; j<height();j++)
			{
				int rouge = qRed(pixel(i,j));
				tableau[rouge] ++;
				if(tableau[rouge] > Maxi)
					Maxi = tableau[rouge];
			}
			break;
	case 2:
		for(int i=0; i<width(); i++)
			for(int j=0; j<height();j++)
			{
				int vert = qGreen(pixel(i,j));
				tableau[vert] ++;
				if(tableau[vert] > Maxi)
					Maxi = tableau[vert];
			}
			break;
	case 3:
		if(Coul==3 || Coul==0)
		{
			for(int i=0; i<width(); i++)
				for(int j=0; j<height();j++)
				{
					int bleu = qBlue(pixel(i,j));
					tableau[bleu] ++;
					if(tableau[bleu] > Maxi)
						Maxi = tableau[bleu];
				}
		}
		break;
	case 0:
		for(int i=0; i<width(); i++)
			for(int j=0; j<height();j++)
			{
				int couleur = qBlue(pixel(i,j))+qGreen(pixel(i,j))+qRed(pixel(i,j));
				couleur /= 3;
				tableau[couleur] ++;
				if(tableau[couleur] > Maxi)
						Maxi = tableau[couleur];
			}
			break;
	}
}

void QXImage::toGrayscale ( bool keepAlpha)
{
	if(isNull())
		return;

	QImage Alpha = alphaChannel();
	int gris;
	for(int i=0; i<width(); i++)
		for(int j=0; j<height();j++)
		{
			gris = qGray(pixel(i,j));
			setPixel(i,j,qRgb(gris,gris,gris));
		}
		if (keepAlpha)
			setAlphaChannel(Alpha);
}

void QXImage::Seuillage ( int Min, int Max )
{
	QImage Alpha = alphaChannel();
	int NoirBlanc;
	for(int i=0; i<width(); i++)
		for(int j=0; j<height();j++)
		{
			NoirBlanc = qGray(pixel(i,j));

			if(NoirBlanc < Min || NoirBlanc > Max)
				NoirBlanc=255;
			else
				NoirBlanc=0;

			setPixel(i,j,qRgb(NoirBlanc,NoirBlanc,NoirBlanc));
		}
		setAlphaChannel(Alpha);
}

void QXImage::Reglage ( int ValA, int ValR, int ValG, int ValB )
{
	for(int i=0; i<width(); i++)
		for(int j=0; j<height();j++)
		{
			int bleu = addValeur(qBlue(pixel(i,j)), ValB, ValA);
			int vert = addValeur(qGreen(pixel(i,j)), ValG, ValA);
			int rouge = addValeur(qRed(pixel(i,j)), ValR, ValA);

			setPixel(i, j, qRgb(rouge,vert,bleu));
		}
}

int QXImage::addValeur(int couleur, int valeur, int valeur1)
{
	int newColor = couleur + valeur + valeur1;
	if (newColor < 0)
		newColor = 0;
	else if (newColor > 255)
		newColor = 255;
	return newColor;
}

QXImage QXImage::Tourner ( int Quart)
{
	QTransform transphormation;
	return transformed(transphormation.rotate(90*Quart));
}

void QXImage::SommeSoustraire ( QXImage tmp, int signe)
{
	for(int i=0; i<tmp.width(); i++)
		for(int j=0; j<tmp.height();j++)
		{
			//multiplier par -1 change le signe et par 1 reste comme c'est
			int bleu = addValeur(qBlue(pixel(i,j)), qBlue(tmp.pixel(i,j))*signe);
			int vert = addValeur(qGreen(pixel(i,j)), qGreen(tmp.pixel(i,j))*signe);
			int rouge = addValeur(qRed(pixel(i,j)), qRed(tmp.pixel(i,j))*signe);

			setPixel(i, j, qRgb(rouge,vert,bleu));
		}
}