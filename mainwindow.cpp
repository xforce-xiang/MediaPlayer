#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    vw = new VideoWidget(this);
 //   txt = new QTextEdit(this);

    player->setVideoOutput(vw);
    this->setCentralWidget(vw);


    slider = new QSlider(this);
    bar  = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
 //   ui->statusBar->addPermanentWidget(txt);
    ui->statusBar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    QString mediaTime =QString::number(slider->maximum());
    //connect(player,&QMediaPlayer::durationChanged,txt,&QTextEdit::setText(mediaTime));
    qDebug()<< mediaTime;
    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    if(vw->isFullScreen())
    {
        vw->setFullScreen(false);
        qDebug()<<"have been setFullscreen = false";
    }
    else if(vw->isFullScreen() != true)
    {
        vw->setFullScreen(true);
        qDebug()<<"have been setFullscreen = true";
    }
    else
    {
        qDebug()<<"can't know the vw's play states";
    }
    qDebug()<<"I know you have been double click...";
}


void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_Space)
    {
        if(player->state() == QMediaPlayer::PlayingState )
        {
            player->pause();
        }
        else
        {
            player->play();
        }
    }
    qDebug()<< "get keypress event....";

}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","E:\\","Video File(*.*)");
    on_actionStop_triggered();
    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();

}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusBar->showMessage("Playing");

}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Paused...");
}

void MainWindow::on_actionStop_triggered()
{

    player->stop();
    ui->statusBar->showMessage("Stopped");
}


void MainWindow::ExitFullScreen()
{
    if(vw->isFullScreen())
    {
        vw->setFullScreen(false);
    }
}

void MainWindow::on_actionFullScreen_triggered()
{
    vw->setFullScreen(true);

}
