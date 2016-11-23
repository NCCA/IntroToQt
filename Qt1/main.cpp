#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QCalendarWidget>


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QCalendarWidget *label = new QCalendarWidget();
  label->setObjectName(QString::fromUtf8("label"));
  label->setGeometry(QRect(100, 100, 200, 100));
 // label->setText("Hello World");
  label->show();
  return app.exec();
}
