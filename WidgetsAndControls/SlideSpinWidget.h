#ifndef SLIDE_SPIN_WIDGET
#define SLIDE_SPIN_WIDGET

#include <QWidget>

class SlideSpinWidget : public  QWidget
{
    Q_OBJECT
    Q_PROPERTY(float value MEMBER m_value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(float minimum MEMBER m_minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)
    Q_PROPERTY(float maximum MEMBER m_maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY(float step MEMBER m_step READ singleStep WRITE setSingleStep NOTIFY stepChanged)

public :
    SlideSpinWidget(QWidget *parent);
    QString valueAsString() const;
    float value()const ;
    void setValue(float _v) ;
    float minimum() const;
    void setMinimum(float _v);
    float maximum() const;
    void setMaximum(float _v);
    float singleStep() const;
    void  setSingleStep(float _v);

signals :
    void valueChanged(float);
    void minimumChanged(float);
    void maximumChanged(float);
    void stepChanged(float);

public slots :

private :

    float m_value=0.0f;
    float m_minimum=-20.0f;
    float m_maximum=20.0f;
    float m_step=0.2f;
};

#endif
