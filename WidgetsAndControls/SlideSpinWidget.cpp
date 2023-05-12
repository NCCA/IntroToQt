#include "SlideSpinWidget.h"
#include <QtWidgets>

SlideSpinWidget::SlideSpinWidget(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QGridLayout(this);
    auto *slider = new QSlider( Qt::Horizontal,this);
    // the slider is int only so we use 0 as the min value
    layout->addWidget(slider,0,0,1,2); // make slider 2 wide
    auto *spin = new QDoubleSpinBox(this);
    layout->addWidget(spin,0,3,1,1);
}


QString SlideSpinWidget::valueAsString() const
{
    return QString::number(m_value);
}

float SlideSpinWidget::value() const
{
    return m_value;
}

void SlideSpinWidget::setValue(float _v)
{
    m_value=_v;
}
