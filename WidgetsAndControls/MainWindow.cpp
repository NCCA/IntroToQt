#include "MainWindow.h"
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,200);
    setWindowTitle("Example of Controls and Custom Widgets");
    // create a simple layout we will use a grid layout
    // this is added to a Widget then set as the centralWidget of the main window.
    QWidget *centralWidget = new QWidget(parent);
    auto *layout=new QGridLayout(centralWidget);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    // going to create two group boxes left and right
    // these will contain different version of the same thing
    auto *left = new QGroupBox("No Widget Vertsion",centralWidget);
    auto *right = new QGroupBox("Widget Vertsion",centralWidget);
    layout->addWidget(left,0,0,1,1);
    layout->addWidget(right,0,1,1,1);
    // for ease of coding I will create a function to populate the left and right elements
    setupLeftUI(left);
    setupRightUI(right);
}

void MainWindow::setupLeftUI(QGroupBox *_parent)
{
    // going to set some constants these will be used in the controls
    constexpr double min = -20.0;
    constexpr double max = 20.0;
    constexpr double step = 0.2;
    constexpr int range=max-min / step;

    auto *layout=new QGridLayout(_parent);
    _parent->setLayout(layout);
    auto *slider = new QSlider( Qt::Horizontal,_parent);
    // the slider is int only so we use 0 as the min value
    slider->setMinimum(0);
    // range is the max / number of total steps
    slider->setMaximum(range);
    layout->addWidget(slider,0,0,1,2); // make slider 2 wide

    auto *spin = new QDoubleSpinBox(_parent);
    spin->setMinimum(min);
    spin->setValue(0.0);
    spin->setMaximum(max);
    spin->setSingleStep(step);
    layout->addWidget(spin,0,3,1,1);

    // now set slider based on the value of the spin
    // min ------ max   needs to map to 0 ---- range
    // v= (spin->value - min) / (max - min ) * (range)
    int  value = (spin->value() - min) / (max-min) * range;
    slider->setValue(value);


    auto *text = new QLineEdit(_parent);
    text->setReadOnly(true);
    text->setText(spin->textFromValue(spin->value()));
    layout->addWidget(text,1,0,1,4);


    // now we need to connect a few things together to make it work
    // 1st lets connect the spinbox to the text and slider
    connect(spin,&QDoubleSpinBox::valueChanged,[=]
            (double value)
            {
                // update the slider to the new position
                double  v  = (value - min) / (max-min) * range;
                // make sure we don't re-signal and update
                slider->blockSignals(true);
                slider->setValue(v);
                slider->blockSignals(false);
                // set text box for viewing
                text->setText(spin->textFromValue(spin->value()));

            });

    connect(slider,&QSlider::valueChanged,[=](int value)
    {

        // basically linear interpolation to map back
        double v= min + (max-min)*(float)value/range;
        // make sure we don't re-signal and update
        spin->blockSignals(true);
        spin->setValue(v);
        spin->blockSignals(false);
        text->setText(spin->textFromValue(spin->value()));

    });
}
void MainWindow::setupRightUI(QGroupBox *_parent)
{
    auto *layout=new QGridLayout(_parent);
    _parent->setLayout(layout);

}




MainWindow::~MainWindow()
{
}

