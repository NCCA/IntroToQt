#ifndef SLIDE_SPIN_WIDGET
#define SLIDE_SPIN_WIDGET

#include <QWidget>

class SlideSpinWidget : public  QWidget
{
    Q_OBJECT
    Q_PROPERTY(float value MEMBER m_value READ value WRITE setValue NOTIFY valueChanged)

public :
    SlideSpinWidget(QWidget *parent);
    QString valueAsString() const;
    float value()const ;
    void setValue(float _v) ;


signals :
    void valueChanged(float);

public slots :

private :
    //Q_PROPERTY(float m_min READ min WRITE setMin NOTIFY minChanged)
    //Q_PROPERTY(float m_max READ max WRITE setMax NOTIFY maxChanged)

    float m_value;
    float m_min;
    float m_max;
};

#endif
