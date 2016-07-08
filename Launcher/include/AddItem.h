#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
  class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

  public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();
    const QString executable();
    const QString path();
    const QString arguments();
    const QString buttonText();


  private slots :
    void addDirectory();
    void addExecutable();
    void setOKActive();
  signals :
    void dialogFull();
  private:
    Ui::AddItem *ui;
    bool m_buttonText=false;
    bool m_dirText=false;
    bool m_exeText=false;
    void checkFilled();
};

#endif // ADDITEM_H
