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

private:

};

#endif // QXIMAGE_H