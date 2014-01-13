#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QFile>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void drawGrid();
    void draw();
    void getData();
    void switchArray();
    void logic();

    void on_loadFile_clicked();
    void on_start_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_stop_clicked();
    void on_step_by_step_clicked();

private:

    Ui::MainWindow *ui;
    QTimer *timer;
    QPixmap *pm;
    QPainter *painter;
    QString fileName;
    QVector<int> iL;
    QVector<int> iA;
    int ** array;
    int ** newArray;
    QString sL, sA;
    int iC;
    int sizeGrid;
    bool grad;
    bool haveData;
};

#endif // MAINWINDOW_H
