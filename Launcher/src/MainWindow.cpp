#include "MainWindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QDebug>
#include <iostream>
#include <QByteArray>
#include <QProcess>
#include <QDir>
#include <QCheckBox>
#include <QLabel>
#include <QMessageBox>
#include "DebugWindow.h"

MainWindow::MainWindow(const QString &_filename, QWidget *_parent ): QDialog(_parent)
{
  setWindowTitle(QString("Launcher"));
  layout = new QVBoxLayout;
  layout->addStretch(1);
  readCFGFile(_filename);
  QCheckBox *debugWindow = new QCheckBox("show debug",this);
  setLayout(layout);
  QString m_pwd=QDir::currentPath();
  setWindowFlags(Qt::WindowStaysOnTopHint);
  QObject::connect(debugWindow,SIGNAL(clicked(bool)),this,SLOT(onShowDebug(bool)));
  m_debug = new DebugWindow(this);
  setWindowIcon(QIcon(":/icons/Rocket-50.png"));
  setWindowIconText("Launcher");

}

void MainWindow::onShowDebug(bool _mode)
{
  if(_mode)
  {
    m_debug->show();
  }
  else
  {
    m_debug->hide();
  }

}


void MainWindow::readCFGFile(const QString &_fname)
{
  QFile inputFile(_fname);
  if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
          return;
  QTextStream in(&inputFile);
  int lineNo=0;
  while (!in.atEnd())
  {
      ++lineNo;
      QString line = in.readLine();
      if(*line.begin()=='#')
        continue;
      else
      {
        QStringList data = line.split(' ');
        if(data.size() <3)
        {
          QMessageBox mb(this);
          QString text=QString("Error with launcher.cfg line %1 \n%2").arg(lineNo).arg(line);
          mb.setText(text);
          mb.show();
          mb.exec();
          continue;
        }
        else
        {
          QString args;
          for(int i=3; i<data.size(); ++i)
          {
            args+=data.at(i);
            args+=' ';
          }
          layout->addWidget(addButton(data.at(0), data.at(1), data.at(2),args));
        }
      }

  }


}



void MainWindow::onButtonPress()
{
  QPushButton*button=  dynamic_cast<QPushButton *> (sender());
  QVariant path=button->property("path");
  QVariant exe=button->property("exe");
  QVariant args=button->property("args");


  QProcess *process = new QProcess(this);
  process->setWorkingDirectory(path.toString());
  QString startText=QString("************************************\n"
                            "Starting %1 in directory \n %2"
                            "Arguments %3"
                            ).arg(exe.toString())
                             .arg(path.toString())
                             .arg(args.toString());
  m_debug->addText(startText);
  QObject::connect(process, SIGNAL(readyReadStandardOutput()), m_debug, SLOT(printDebug()));

  process->start(exe.toString(),args.toStringList());
}



QPushButton *MainWindow::addButton(const QString &_text, const QString &_path, const QString &_exe, const QString &_args)
{
  // create a push button with the central widget as the parent
  QPushButton *button = new QPushButton(_text);
  button->setProperty("path",_path);
  button->setProperty("exe",_exe);
  button->setProperty("args",_args);
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
    //case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS); break;
    default : break;
  }
}

