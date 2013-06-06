#include <qpainter.h>
#include <qpoint.h>

#include "Histo.h"


CHisto::CHisto(QWidget *parent)
	: QWidget(parent),
	m_commencer(20,20)
{
	m_nTab = NULL;
}


CHisto::~CHisto(void)
{
	delete m_nTab;
}


void CHisto::setHisto( int * Tab, int Maxi, int Coul)
{
	m_nTab = new int [256];

	for(int i=0; i<256; i++)
			m_nTab[i] = Tab[i];

	m_nMaxi = Maxi;
	m_nCoul = Coul;
	update();
}

void CHisto::paintEvent(QPaintEvent * evt)
{
	if(m_nTab!=NULL)
	{
		QBrush brosse = QColor(Qt::black);
		QPen pen;
		switch(m_nCoul)
		{
		case 1:
			brosse.setColor(Qt::red);
			pen.setColor(Qt::red);
			break;
		case 2:
			brosse.setColor(Qt::green);
			pen.setColor(Qt::green);
			break;
		case 3:
			brosse.setColor(Qt::blue);
			pen.setColor(Qt::blue);
			break;
		}

		QPainter peintre(this);
		peintre.setPen(pen);
		peintre.setBrush(brosse);

		//tableau de QPoint pour tracer après
		QPoint tabPoint [258];

		//Un sur 2 convertit en double suffit normalement
		double pasX = (double)(width()-m_commencer.x()) / (double)m_nMaxi;
		double pasY = (double)(height()-m_commencer.y()) / 255.0;

		for(int i=0; i<256; i++)
			tabPoint[i] = QPoint((m_nTab[i]*pasX)+m_commencer.y(), (i*pasY)+m_commencer.y());
		tabPoint[256] = QPoint(m_commencer.x(),height());
		tabPoint[257] = QPoint(m_commencer.x(),m_commencer.y());

		peintre.drawPolygon(tabPoint, 258);

		peintre.setPen(QPen(QColor(255,0,255)));
		peintre.drawLine(m_commencer.x(), m_commencer.y(), width(), m_commencer.y());
		peintre.drawLine(m_commencer.x(), m_commencer.y(), m_commencer.x(), height());
		
		peintre.drawText(0, m_commencer.y(), "0");
		peintre.drawText(0, height()/2 + m_commencer.y(), "128");
		peintre.drawText(0, height(), "255");
		
		//peintre.drawText(0,5,10,10,Qt::AlignCenter,"0");
		//peintre.drawText(0,5,10,10,Qt::AlignCenter,"0");
	}
}