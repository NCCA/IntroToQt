#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <iostream>

int main(int argc, char *argv[])
{
  // create the main Qt app
  QApplication app(argc, argv);
  // create a main window widget
  QMainWindow mainwin;
  // set the name
<<<<<<< HEAD
  mainwin.setObjectName(QString::fromUtf8("MainWindow"));
=======
  mainwin.setObjectName(QString::fromUtf8("MainWindowTest"));
  std::cout<<mainwin.objectName().toStdString()<<'\n';
>>>>>>> 4269b9d436f770575c045e26185c3f8a18eb3dcb
  // set the size
  mainwin.resize(200,200);
  // set the title of the window
  mainwin.setWindowTitle("A MainWindow App");
  // create a central widget with the main window as the parent
  QWidget *centralwidget = new QWidget(&mainwin);
<<<<<<< HEAD
=======
  QGridLayout *grid = new QGridLayout(centralwidget);
  centralwidget->setLayout(grid);
>>>>>>> 4269b9d436f770575c045e26185c3f8a18eb3dcb
  // create a push button with the central widget as the parent
  QPushButton *button = new QPushButton(centralwidget);
  grid->addWidget(button);
  // set the name
  button->setObjectName(QString::fromUtf8("button"));
  // set the geometry
  button->setGeometry(QRect(10, 80, 100, 32));
  // set the text of the button
  button->setText("Button");
  // set the central widget for the main window
  mainwin.setCentralWidget(centralwidget);
  // show the window
  mainwin.show();
  // run the application
  return app.exec();
}
