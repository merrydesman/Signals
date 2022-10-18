#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QApplication>
#include <QString>

QuitWidget::QuitWidget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton *quitBtn = new QPushButton("Quit", this);
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    label = new QLabel(text, this);
    label->move(10, 50);

    moveLabel = new QLabel("Move info", this);
    moveLabel->move(10, 30);
    timerId = QObject::startTimer(1000);

}

void QuitWidget::keyPressEvent(QKeyEvent *event){

   QString labelText = label->text();
   label->resize(1000, 13);
   label->setText(label->text() + event->text());

}

void QuitWidget::moveEvent(QMoveEvent *event){
    int x = event->pos().x();
    int y = event->pos().y();
    QString position = QString::number(x) + ", " + QString::number(y);
    moveLabel->setText(position);
}

QuitWidget::~QuitWidget()
{
    QObject::killTimer(timerId);
}

void QuitWidget::timerEvent(QTimerEvent *e) {
    if (e->timerId() == timerId) {
        QTime time = QTime::currentTime();
        this->setWindowTitle(time.toString("hh:mm:ss"));
 }
}
