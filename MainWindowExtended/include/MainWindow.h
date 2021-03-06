#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

/// @file MainWindow.h

class MainWindow : public QMainWindow
{
  Q_OBJECT
  protected :
    /// @brief override the keyPressEvent inherited from QObject so we can handle key presses.
    /// @param [in] _event the event to process
    void keyPressEvent(QKeyEvent *_event);
    /// @brief override the resizeEvent inherited from QObject so we can handle key presses.
    /// @param [in] _event the event to process

    void resizeEvent (QResizeEvent * _event);
    public:
    /// @brief constructor
    /// @param _parent the parent window the for this window
    MainWindow(QWidget *_parent = 0);
    /// @brief  dtor free up the GLWindow and all resources
    ~MainWindow();
  private slots :

  private:


};

#endif // MAINWINDOW_H
