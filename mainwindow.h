#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTextEdit>
#include "videowidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void mouseDoubleClickEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *k);


private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void ExitFullScreen();

    void on_actionFullScreen_triggered();



private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    //QVideoWidget* vw;
    VideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
    QTextEdit* txt;

};

#endif // MAINWINDOW_H
