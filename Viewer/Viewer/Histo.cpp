#include "Histo.h"


CHisto::CHisto(QWidget *parent)
	: QWidget(parent)
{
}


CHisto::~CHisto(void)
{
}


void CHisto::setHisto( int * Tab, int Maxi, int Coul)
{
	m_nTab = Tab;
	m_nMaxi = Maxi;
	m_nCoul = Coul;
	update();
}

void CHisto::paintEvent(QPaintEvent * evt)
{

}