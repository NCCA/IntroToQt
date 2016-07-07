#include <QApplication>
#include "MainWindow.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <iostream>
#include <QDebug>
/* this code runs the basic main window and is created by the Qt Creator app */
int main(int argc, char *argv[])
{
  // make an instance of the QApplication  
  QApplication a(argc, argv);
  QString fname;
  // command line args will override the program
  if(argc==2)
  {
    fname=argv[1];
  }
  // otherwise look for launcher.cfg in current dir
  else
  {


    QString file=QDir::currentPath();

    file+="/launcher.cfg";
    QFileInfo check_file(file);
    if (check_file.exists() && check_file.isFile())
    {
      fname=file;
    }
    else
    {
      std::cerr<<"No launcher.cfg found in current directory\n";
      std::cerr<<"Usage Launcher [filename] or have a launcer.cfg in dir\n";
      exit(EXIT_FAILURE);
    }

  }
  // Create a new MainWindow
  MainWindow w(fname);
  // show it
  w.show();
  // hand control over to Qt framework
  return a.exec();
}
