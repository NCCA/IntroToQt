#include "SlideSpinWidget.h"
#include <QtWidgets>

SlideSpinWidget::SlideSpinWidget(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QGridLayout(this);
    auto *slider = new QSlider( Qt::Horizontal,this);
    // the slider is int only so we use 0 as the min value
    layout->addWidget(slider,0,0,1,2); // make slider 2 wide
    auto *spin = new QDoubleSpinBox(this);
    spin->setMinimum(m_minimum);
    spin->setMaximum(m_maximum);
    spin->setSingleStep(m_step);
    spin->setValue(m_value);
    layout->addWidget(spin,0,3,1,1);
    connect(spin,qOverload<double>(&QDoubleSpinBox::valueChanged),[=](double value)
    {
        emit valueChanged(static_cast<float>(value));
    });
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


float SlideSpinWidget::minimum() const
{
    return m_minimum;
}
void SlideSpinWidget::setMinimum(float _v)
{
    m_minimum=_v;
}

float SlideSpinWidget::maximum() const
{
    return m_maximum;
}
void SlideSpinWidget::setMaximum(float _v)
{
    m_maximum=_v;
}

float SlideSpinWidget::singleStep() const
{
    return m_step;
}
void  SlideSpinWidget::setSingleStep(float _v)
{
    m_step=_v;
}

