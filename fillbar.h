
#ifndef __H_FILLBAR_H__
#define __H_FILLBAR_H__

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT FillBar : public QWidget{

    Q_OBJECT
    Q_PROPERTY(int maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool flip READ flip WRITE setFlip)

    Q_PROPERTY(int innerSpacing READ innerSpacing WRITE setInnerSpacing )
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth )
    Q_PROPERTY(int notchLength READ notchLength WRITE setNotchLength )
    Q_PROPERTY(int roundness READ roundness WRITE setRoundness )
    Q_PROPERTY(int notchHeight READ notchHeight WRITE setNotchHeight )

    Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor )
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor )

public:
    explicit FillBar(QWidget *parent = 0);

    int value() const{ return m_value; }
    int maximum() const{ return m_maximum; }
    bool flip() const{ return m_flip; }
    int innerSpacing() const{ return m_innerSpacing; }
    int borderWidth() const{ return m_borderWidth; }
    int notchLength() const{ return m_notchLength; }
    int roundness() const{ return m_roundness; }
    int notchHeight() const{ return m_notchHeight; }

    QColor fillColor() const{ return m_fillColor; }
    QColor borderColor() const{ return m_borderColor; }

    void setNotchHeight( int height ){
	    m_notchHeight = height;
	    repaint();
    }
    void setInnerSpacing( int spacing ){
	    m_innerSpacing = spacing;
	    repaint();
    }
    void setBorderWidth( int width ){
	    m_borderWidth = width;
	    repaint();
    }
    void setNotchLength( int length ){
	    m_notchLength = length;
	    repaint();
    }
    void setFillColor( QColor color ){
	    m_fillColor = color;
	    repaint();
    }
    void setBorderColor( QColor color ){
	    m_borderColor = color;
	    repaint();
    }


    void setValue( int value ){
	    m_value = value;
	    repaint();
	    emit valueChanged(value);
    }
    void setMaximum( int maximum ){
	    m_maximum = maximum;
	    repaint();
	    emit maximumChanged(maximum);
    }
    void setRoundness( int roundness ){
	    m_roundness = roundness;
	    repaint();
    }

    void setFlip( bool flip ){
	    m_flip = flip;
	    repaint();
    }


signals:
	void valueChanged(int);
	void maximumChanged(int);


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    int m_maximum;
    int m_value;
    bool m_flip;

    int m_innerSpacing;
    int m_borderWidth;
    int m_notchLength;
    int m_roundness;
    int m_notchHeight;
    QColor m_fillColor;
    QColor m_borderColor;
};

#endif
