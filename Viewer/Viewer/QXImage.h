#ifndef QXIMAGE_H
#define QXIMAGE_H

#include <QImage>

class QXImage : public QImage
{
public:
	QXImage();
	QXImage(QImage image);
	QXImage(QString nomFichier);
	~QXImage();

public:
	QXImage& operator = (const QImage &image);

	int * Histo ( int Coul, int &Maxi);
	void toGrayscale ( bool keepAlpha = true);
	void Seuillage ( int Min, int Max );
	void Reglage ( int ValA, int ValR, int ValG, int ValB );
	QXImage Tourner ( int Quart);
	//Si le signe est 1 alors Somme, si c'est -1 c'est la soustraction
	void SommeSoustraire ( QXImage tmp, int signe = 1);

private:
	int addValeur(int coleur, int valeur, int valeur1=0);
};

#endif // QXIMAGE_H