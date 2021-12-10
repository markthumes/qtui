#include <QMouseEvent>
#include <QPainter>

#include "fillbar.h"

FillBar::FillBar(QWidget *parent):QWidget(parent){

    m_flip = false;
    m_value = 0;
    m_maximum = 100;

    m_innerSpacing = 0;
    m_borderWidth = 6;
    m_notchLength = 10;
    m_notchHeight = 0;
    
    m_roundness = 100;

    m_borderColor =  QColor( 115, 247, 220 );
    m_fillColor =  QColor(172,0, 3);


    setWindowTitle(tr("Analog Clock"));
    resize(200, 200);
}


void FillBar::paintEvent(QPaintEvent *){


    int side = qMin(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    //painter.setPen(Qt::NoPen);
    //

    int pWidth  = width()  - m_notchLength;
    int pHeight = height() - m_notchLength;

    QPen border;
    border.setWidth(m_borderWidth);
    border.setColor(m_borderColor);
    painter.setPen(border);

    QBrush fillBrush;
    fillBrush.setColor(m_fillColor);


    if( height() > width() ){
	//tall
	int x[2];
	int y[2];
	x[0] =          m_borderWidth/2 + (m_flip ? m_notchLength : 0);
	x[1] = pWidth - m_borderWidth/2 + (m_flip ? m_notchLength : 0);
	y[0] =            pWidth/2*(m_roundness/100.0) + m_borderWidth/2;
	y[1] = height() - pWidth/2*(m_roundness/100.0) - m_borderWidth/2;

    	painter.drawLine( x[0], y[0], x[0], y[1] );
    	painter.drawLine( x[1], y[0], x[1], y[1] );
	painter.drawLine( (m_flip ?               0   : width()               ),  y[1] - (m_notchHeight/100.0)*(y[1]-y[0]), 
			  (m_flip ? 0 + m_notchLength : width() - m_notchLength), y[1] - (m_notchHeight/100.0)*(y[1]-y[0]) );

	x[0] =            m_borderWidth/2 + (m_flip ? m_notchLength : 0);
	y[0] =            m_borderWidth/2;
	y[1] = height() - pWidth*(m_roundness/100.0) - m_borderWidth/2;
    	painter.drawArc( x[0], y[0], pWidth - m_borderWidth, pWidth*(m_roundness/100.0),   0*16, 180*16);
    	painter.drawArc( x[0], y[1], pWidth - m_borderWidth, pWidth*(m_roundness/100.0), 180*16, 180*16);

	//fill
	painter.setPen(Qt::NoPen);
	painter.setBrush(m_fillColor);
	int twidth  = pWidth   - 2*m_borderWidth - 2*m_innerSpacing;
	int theight = height() - 2*m_borderWidth - 2*m_innerSpacing - (m_roundness/100.0)*twidth;
	x[0] = (m_flip ? m_notchLength : 0 ) + m_borderWidth + m_innerSpacing;
	x[1] = x[0] + twidth;
	y[0] = m_borderWidth + m_innerSpacing + (m_roundness/100.0)*twidth/2;
	y[1] = y[0] + theight;
	painter.drawRect(  x[0], y[1] + 1- ((float)m_value/m_maximum)*theight, twidth, ((float)m_value/m_maximum)*theight );
	painter.drawChord( x[0], y[1] - twidth*(m_roundness/100.0)/2, twidth, twidth*(m_roundness/100.0), 180*16, 180*16);
	painter.drawChord( x[0], y[1] + 2 - theight*((float)m_value/m_maximum) - twidth*(m_roundness/100.0)/2, twidth, twidth*(m_roundness/100.0),  0*16, 180*16);
    }
    else{
	//long
	painter.setPen(border);
	int x[2], y[2];
	x[0] =           pHeight/2*(m_roundness/100.0) + m_borderWidth/2;
	x[1] = width() - pHeight/2*(m_roundness/100.0) - m_borderWidth/2;
	y[0] =           m_borderWidth/2 + (m_flip ? m_notchLength : 0 );
	y[1] = pHeight - m_borderWidth/2 + (m_flip ? m_notchLength : 0 );
    	painter.drawLine( x[0], y[0], x[1], y[0] );
    	painter.drawLine( x[0], y[1], x[1], y[1] );
	painter.drawLine( x[1] - (m_notchHeight/100.0)*(x[1]-x[0]), (m_flip ? 0                 : height() - m_notchLength),
			  x[1] - (m_notchHeight/100.0)*(x[1]-x[0]), (m_flip ? 0 + m_notchLength : height()) );

	y[0] = m_borderWidth/2 + (m_flip ? m_notchLength : 0 );
	x[0] = m_borderWidth/2;
	x[1] = width() - pHeight*(m_roundness/100.0) - m_borderWidth/2;
    	painter.drawArc( x[0], y[0], pHeight*(m_roundness/100.0), pHeight - m_borderWidth,  90*16, 180*16);
    	painter.drawArc( x[1], y[0], pHeight*(m_roundness/100.0), pHeight - m_borderWidth, 270*16, 180*16);

	//fill
	painter.setPen(Qt::NoPen);
	painter.setBrush(m_fillColor);
	int theight = pHeight - 2*m_borderWidth - 2*m_innerSpacing;
	int twidth  = width() - 2*m_borderWidth - 2*m_innerSpacing - (m_roundness/100.0)*theight;
	x[0] = m_borderWidth + m_innerSpacing + (m_roundness/100.0)*theight/2;
	x[1] = x[0] + twidth;
	y[0] = (m_flip ? m_notchLength : 0) + m_borderWidth + m_innerSpacing;
	y[1] = y[0] + theight;
	painter.drawRect( x[1] + 1 - ((float)m_value/m_maximum)*twidth, y[0], ((float)m_value/m_maximum)*twidth, theight );
	painter.drawChord( x[1] - theight*(m_roundness/100.0)/2, y[0], theight*(m_roundness/100.0), theight, 270*16, 180*16);
	painter.drawChord( x[1] + 2 - twidth*((float)m_value/m_maximum) - theight*(m_roundness/100.0)/2, y[0], theight*(m_roundness/100.0), theight,  90*16, 180*16);
    }

}

