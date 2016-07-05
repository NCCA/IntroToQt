#include "MainWindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QDebug>
#include <iostream>
#include <QByteArray>
#include <QProcess>
#include <QDir>
MainWindow::MainWindow(const QString &_filename, QWidget *_parent ): QDialog(_parent)
{
  setWindowTitle(QString("Launcher"));
  layout = new QVBoxLayout;
  layout->addStretch(1);
  readCFGFile(_filename);
  setLayout(layout);
  QString m_pwd=QDir::currentPath();

}


void MainWindow::readCFGFile(const QString &_fname)
{
  QFile inputFile(_fname);
  if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
          return;
  QTextStream in(&inputFile);
  while (!in.atEnd())
  {
      QString line = in.readLine();
      if(*line.begin()=='#')
        continue;
      else
      {
        QStringList data = line.split(' ');
        if(data.size() !=3)
        {
          return;
        }
        else
        {
          layout->addWidget(addButton(data.at(0), data.at(1), data.at(2)));
        }
      }

  }


}



void MainWindow::onButtonPress()
{
  QPushButton*button=  dynamic_cast<QPushButton *> (sender());
  QVariant path=button->property("path");
  QVariant exe=button->property("exe");
  //qDebug()<<path.toString()<<" "<<exe.toString()<<"\n";
  //std::cout<<"onButton\n";
  QProcess *process = new QProcess(this);
  process->setWorkingDirectory(path.toString());
  process->start(exe.toString());
}



QPushButton *MainWindow::addButton(const QString &_text, const QString &_path, const QString _exe)
{
  // create a push button with the central widget as the parent
  QPushButton *button = new QPushButton(_text);
  button->setProperty("path",_path);
  button->setProperty("exe",_exe);
  button->resize(100,50);
  QObject::connect(button,SIGNAL(clicked()),this,SLOT(onButtonPress()));

  return button;

}



MainWindow::~MainWindow()
{
}


void MainWindow::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
    case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS); break;
    default : break;
  }
}

