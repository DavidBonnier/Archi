#include "qximage.h"
#include "qstring.h"

QXImage::QXImage()
{

}

QXImage::QXImage(QString nomFichier) :
QImage(nomFichier)
{
}

QXImage::~QXImage()
{
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

void QXImage::Reglage ( int ValR, int ValG, int ValB )
{
	QImage Alpha = alphaChannel();
	for(int i=0; i<width(); i++)
		for(int j=0; j<height();j++)
		{
			int bleu = qBlue (pixel(i,j));
			int vert = qGreen (pixel(i,j));
			int rouge = qRed(pixel(i,j));

			setPixel(i,j,qRgb(rouge+ValR,vert+ValG,bleu+ValB));
		}
	setAlphaChannel(Alpha);
}