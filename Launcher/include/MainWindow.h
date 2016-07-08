#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "DebugWindow.h"


class MainWindow : public QMainWindow
{
  Q_OBJECT
  protected :
    /// @brief override the keyPressEvent inherited from QObject so we can handle key presses.
    /// @param [in] _event the event to process
    void keyPressEvent(QKeyEvent *_event);
    /// @brief override the resizeEvent inherited from QObject so we can handle key presses.
    /// @param [in] _event the event to process

    public:
    /// @brief constructor
    /// @param _parent the parent window the for this window
    MainWindow(const QString &_filename,QWidget *_parent = 0);
    /// @brief  dtor free up the GLWindow and all resources
    ~MainWindow();
  public slots :
    void onButtonPress();
    void onShowDebug(bool _mode);
    void showHelp();
    void addItem();
  private:
    QPushButton *addButton(const QString &_text, const QString &_path, const QString &_exe, const QString &_args);
    void readJSonFile(const QString &_fname);
    QBoxLayout *layout;
    DebugWindow *m_debug=nullptr;
    QMenuBar *m_menuBar;
    QMenu *m_helpMenu;
    QAction *m_helpAction;
    QMenu *m_fileMenu;
    QAction *m_addItemAction;

};

#endif // MAINWINDOW_H
