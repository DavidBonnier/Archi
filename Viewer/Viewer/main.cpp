#include "viewer.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Charger langue local, du système
	//local
	Viewer w;
	w.show();
	return a.exec();
}
