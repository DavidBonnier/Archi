#pragma once
#include "qwidget.h"

class CHisto : public QWidget
{
	Q_OBJECT

public:
	CHisto(QWidget *parent);
	~CHisto();

private:
	//Pour ne pas commencer a tracer en 0,0
	QPoint m_commencer;

	int * m_nTab;
	int m_nMaxi ;
	int m_nCoul ; // 0 = Noir, 1= Red, 2 = Green, 3= Bleu

public:
	void setHisto( int * Tab, int Maxi, int Coul) ;

protected:
	void paintEvent(QPaintEvent * evt) ;
};

