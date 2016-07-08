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
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include "DebugWindow.h"
#include "AddItem.h"


MainWindow::MainWindow(const QString &_filename, QWidget *_parent ): QMainWindow(_parent)
{
  // set title of window.
  setWindowTitle(QString("Launcher"));
  // make the window stay on top
  setWindowFlags(Qt::WindowStaysOnTopHint);
  // add the icon from the resource and add to window
  setWindowIcon(QIcon(":/icons/Rocket-50.png"));
  // add the icon text
  setWindowIconText("Launcher");
  m_filename=_filename;
  // create a layout for the main window
  layout = new QVBoxLayout;
  layout->addStretch(1);
  // read the config file
  readJSonFile(_filename);
  // create a check box for the debug window
  QCheckBox *debugWindow = new QCheckBox("show debug",this);
  // connect the slots
  QObject::connect(debugWindow,SIGNAL(clicked(bool)),this,SLOT(onShowDebug(bool)));
  // add to the window
  layout->addWidget(debugWindow);

  // create a debug window for the output of the process but keep it hiden
  m_debug = new DebugWindow(this);
  // now add the menu items
  m_menuBar = new QMenuBar(this);
  m_helpAction = new QAction(tr("&About"), this);
  m_helpAction->setStatusTip(tr("About"));
  QObject::connect(m_helpAction, SIGNAL(triggered()), this, SLOT(showHelp()));
  m_helpMenu = m_menuBar->addMenu(tr("&Help"));
  m_helpMenu->addAction(m_helpAction);
  setMenuBar(m_menuBar);
  // create a Widget for the window and add the layout to id.
  QWidget *window = new QWidget();
  window->setLayout(layout);
  // set as the window centeral widget
  setCentralWidget(window);
  // now add the menu items etc
  m_addItemAction = new QAction(tr("Add Item"), this);
  m_addItemAction->setStatusTip(tr("Add Item"));
  QObject::connect(m_addItemAction, SIGNAL(triggered()), this, SLOT(addItem()));
  m_fileMenu = m_menuBar->addMenu(tr("&Add"));
  m_fileMenu->addAction(m_addItemAction);
  setMenuBar(m_menuBar);

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

void MainWindow::showHelp()
{
  QMessageBox mb(this);
  QString text=QString("Launcher system for simple apps\n"
                       "Run from a directory containing launcher.cfg file\n"
                       "Or pass a command line argument\n"
                       "see https://github.com/NCCA/IntroToQt/tree/master/Launcher\n");
  mb.setText(text);
  mb.show();
  mb.exec();

}

void MainWindow::addItem()
{
  AddItem *item = new AddItem(this);
  item->show();
  bool ret=item->exec();
  if(ret==false)
  {
    return;
  }
  else
  {
    layout->addWidget(addButton(item->buttonText(),
                                item->path(),
                                item->executable(),
                                item->arguments()));
    QFile inputFile(m_filename);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QByteArray data=inputFile.readAll();
    inputFile.close();
    // we are now going to save the data back to the json file.
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject jsonObject=doc.object();
    QJsonObject newJson;
    newJson["ButtonText"]=item->buttonText();
    newJson["Exe"]=item->executable();
    newJson["Path"]=item->path();
    newJson["arguments"]=item->arguments();
    QJsonArray programs = jsonObject["Programs"].toArray();
    programs.append(newJson);
    QJsonObject root;
    root["Programs"]=programs;
    QJsonDocument newDoc(root);

    QFile saveFile(m_filename);
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save file.");
           return ;
    }
    saveFile.write(newDoc.toJson());
    saveFile.close();

  }
}



void MainWindow::readJSonFile(const QString &_fname)
{
  QFile inputFile(_fname);
  if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
          return;
  QByteArray data=inputFile.readAll();
  inputFile.close();
  QJsonDocument doc = QJsonDocument::fromJson(data);
  QJsonObject jsonObject=doc.object();
  QJsonArray programs = jsonObject["Programs"].toArray();
  QString buttonText,path,exe,args;

  for(auto&& item: programs)
  {
    const QJsonObject& prog = item.toObject();
    buttonText=prog["ButtonText"].toString();
    path=prog["Path"].toString();
    exe=prog["Exe"].toString();
    args=prog["arguments"].toString();
    qDebug()<<args;
    layout->addWidget(addButton(buttonText, path, exe,args));
  }




}
