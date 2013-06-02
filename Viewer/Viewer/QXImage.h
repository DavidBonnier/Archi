#ifndef QXIMAGE_H
#define QXIMAGE_H

#include <QImage>

class QXImage : public QImage
{
public:
	QXImage();
	QXImage(QString nomFichier);
	~QXImage();

public:
	void toGrayscale ( bool keepAlpha = true);
	void Seuillage ( int Min, int Max );
	void Reglage ( int ValR, int ValG, int ValB );

private:

};

#endif // QXIMAGE_H