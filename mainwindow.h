#ifndef QUITWIDGET_H
#define QUITWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QMoveEvent>
#include <QFont>
#include <QTimer>
#include <QTime>


class QuitWidget:public QWidget
{
private:
    QLabel *label;
    QString text = "Hello";


    QLabel *moveLabel;
    QTimer *timer;
    virtual void timerEvent (QTimerEvent *);
    int timerId;
private slots:
    void slotTimerAlarm();
public:
    QuitWidget(QWidget *parent = nullptr);

    ~QuitWidget();

    void keyPressEvent(QKeyEvent *e);
    void moveEvent(QMoveEvent *e);
};

#endif // QUITWIDGET_H
