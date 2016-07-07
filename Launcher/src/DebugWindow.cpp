#include "DebugWindow.h"
#include "ui_DebugWindow.h"
#include <QProcess>
DebugWindow::DebugWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DebugWindow)
{
  ui->setupUi(this);

}

DebugWindow::~DebugWindow()
{
  delete ui;
}

void DebugWindow::printDebug()
{
  QProcess *process=  dynamic_cast<QProcess *> (sender());
  ui->s_debugOutput->appendPlainText(process->readAllStandardOutput());
  ui->s_debugOutput->appendPlainText(process->readAllStandardError());
}

void DebugWindow::addText(const QString &_text)
{
  ui->s_debugOutput->appendPlainText(_text);
}
