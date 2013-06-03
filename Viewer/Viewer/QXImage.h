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

	void toGrayscale ( bool keepAlpha = true);
	void Seuillage ( int Min, int Max );
	void Reglage ( int ValR, int ValG, int ValB );

private:
	int addValeur(int coleur, int valeur);
};

#endif // QXIMAGE_H