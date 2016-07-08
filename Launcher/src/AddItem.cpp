#include "AddItem.h"
#include "ui_AddItem.h"
#include <QFileDialog>
#include <QDebug>

AddItem::AddItem(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AddItem)
{
  ui->setupUi(this);
  QObject::connect(ui->m_chooseDir, SIGNAL(clicked()), this, SLOT(addDirectory()));
  QObject::connect(ui->m_chooseExe, SIGNAL(clicked()), this, SLOT(addExecutable()));

  ui->m_buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
  QObject::connect(this,SIGNAL(dialogFull()), this, SLOT(setOKActive()));

}

AddItem::~AddItem()
{
  delete ui;
}

void AddItem::addDirectory()
{
  QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                               "./",
                                               QFileDialog::ShowDirsOnly
                                               | QFileDialog::DontResolveSymlinks);
  if(dir !=nullptr)
  {
    ui->m_dirText->setText(dir);
    m_dirText=true;
    checkFilled();
  }
}

void AddItem::addExecutable()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "./",
                                                  tr("*"));
  if(fileName !=nullptr)
  {
    qDebug()<<"add exe doing text things";
    ui->m_exeText->setText(fileName);
    m_exeText=true;
    checkFilled();
  }

}

void AddItem::checkFilled()
{
  m_buttonText = ui->m_buttonText->text().size() == 0 ? false : true;
  qDebug()<<"Check Filled" << m_buttonText<<" "<<m_dirText<<" "<<m_exeText<<"\n";
  if (m_buttonText && m_exeText && m_dirText)
  {
    emit dialogFull();

  }
}
void AddItem::setOKActive()
{
  qDebug()<<"SetOK Active called";
  ui->m_buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

}

const QString AddItem::executable(){return ui->m_exeText->text(); }
const QString AddItem::path(){return ui->m_dirText->text(); }
const QString AddItem::arguments(){return ui->m_arguments->text(); }
const QString AddItem::buttonText(){return ui->m_buttonText->text(); }
