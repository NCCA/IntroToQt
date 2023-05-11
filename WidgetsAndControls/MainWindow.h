#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private :
    void setupLeftUI(QGroupBox *_parent);
    void setupRightUI(QGroupBox *_parent);
};
#endif // MAINWINDOW_H
