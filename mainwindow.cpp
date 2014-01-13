#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileName = "file.txt";
    pm = new QPixmap(QSize(ui->label->width(), ui->label->height()));
    pm->fill(ui->label, 0, 0);
    painter = new QPainter(pm);
    painter->fillRect(painter->viewport(), QColor(255,255,255));
    ui->label->setPixmap(*pm);
    grad = true;
    haveData = false;
//    ui->textEdit->append(sL);
    timer = new QTimer(this);
}

void MainWindow::on_loadFile_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "txt-files (*.txt)");

//    getData();
//    draw();
    ui->start->setEnabled(true);
    ui->step_by_step->setEnabled(true);
}

void MainWindow::on_start_clicked()
{
    ui->loadFile->setEnabled(false);
    ui->stop->setEnabled(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_step_by_step_clicked()));
    timer->start(10);
}


void MainWindow::on_stop_clicked()
{
    timer->stop();
}

void MainWindow::on_step_by_step_clicked()
{
    ui->loadFile->setEnabled(false);
    ui->textEdit_A->setEnabled(false);
    ui->textEdit_C->setEnabled(false);
    ui->textEdit_L->setEnabled(false);

    if(!haveData) { getData(); haveData = true; }
    draw();
    logic();
}

void MainWindow::on_radioButton_clicked()
{
    if(ui->radioButton->isChecked()) {
        grad = false;
        //draw();
    }
}


void MainWindow::on_radioButton_2_clicked()
{
    if(ui->radioButton_2->isChecked()) {
        grad = true;
        //draw();
    }
}
void MainWindow::drawGrid()
{
    painter->fillRect(painter->viewport(), QColor(255,255,255));
    painter->setPen(QColor(0, 0, 0));
//    QFont font = painter->font() ;
//    font.setPointSize(7);
//    painter->setFont(font);
    for(int i = 0; i < sizeGrid; i++)
    {
        painter->drawLine(0, i*(ui->label->height())/sizeGrid, ui->label->width(), i*(ui->label->height())/sizeGrid);
        painter->drawLine(i*(ui->label->width())/sizeGrid, 0, i*(ui->label->width())/sizeGrid, ui->label->height());
        //painter->drawText(QPoint(i*(ui->label->width())/sizeGrid, 10), QString::number(i));
        //painter->drawText(QPoint(2, (i + 1)*(ui->label->height())/sizeGrid), QString::number(i));
    }
    ui->label->setPixmap(*pm);
}

void MainWindow::draw()
{
//    painter->setPen(QColor(255, 0, 0));
//    painter->drawLine(100, 200, temp, 100);
//    ui->label->setPixmap(*pm);
//    if (temp < 2550) temp += 10;
//    else timer->stop();
    painter->setPen(Qt::gray);
    for(int i = 0; i < sizeGrid; i++)
        for(int j = 0; j < sizeGrid; j++)
        {
            if (array[i][j] == 0) painter->setBrush (Qt::black);
            else
                if (grad) painter->setBrush (QColor(255, 200*array[i][j]/(iC + 1), 0));
                else painter->setBrush (QColor(255, 200, 0));
            painter->drawRect(i*(ui->label->width())/sizeGrid, j*(ui->label->height())/sizeGrid, (ui->label->width())/sizeGrid + 1, (ui->label->height())/sizeGrid + 1);
        }
    ui->label->setPixmap(*pm);
}

void MainWindow::getData()
{
    sL = ui->textEdit_L->toPlainText();
    sA = ui->textEdit_A->toPlainText();
    for(int i = 0; i < sL.length(); i++)
    {
        iL.push_back(sL[i].toAscii() - 48);
    }
    for(int i = 0; i < sA.length(); i++) {
        iA.push_back(sA[i].toAscii() - 48);
//        ui->textEdit->append(QString::number(iA[i]));
    }
    iC = (ui->textEdit_C->toPlainText()).toInt();

    QVector<QString> str;
    QFile file(fileName);
    //ui->textEdit->append(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    while (!in.atEnd())
        str.push_back(in.readLine());
    file.close();
    sizeGrid = str.size();

    array = new int * [sizeGrid];
    newArray = new int * [sizeGrid];
    for(int i = 0; i < sizeGrid; i++)
    {
        array[i] = new int[sizeGrid];
        newArray[i] = new int[sizeGrid];
    }
    for(int i = 0; i < sizeGrid; i++)
    {
        QStringList list = str[i].split(" ");
        for(int j = 0; j < sizeGrid; j++)
        {
//            if(list[j].toInt() != 0) array[j][i] = iC;
//            else array[j][i] = 0;
            //newArray[j][i] = list[j].toInt();
            if(list[j].toInt() >= iC) array[j][i] = iC + 1;
            else array[j][i] = list[j].toInt();
        }
    }
}

void MainWindow::switchArray()
{
    for(int i = 0; i < sizeGrid; i++)
        for(int j = 0; j < sizeGrid; j++)
            array[i][j] = newArray[i][j];
}

void MainWindow::logic()
{


//    QFile fout("out.txt");
//    fout.open(QIODevice::Append | QIODevice::Text);
//    QTextStream out(&fout);

//    out << "array \n";
//    for(int i = 0; i < sizeGrid; i++) {
//        for(int j = 0; j < sizeGrid; j++)
//            out << array[i][j] << " ";
//          out << "\n";
//    }


    int alive, birth;
    for(int i = 0; i < sizeGrid; i++)
    {
        for(int j = 0; j < sizeGrid; j++)
        {
            alive = 0;
            birth = 0;

            if(i != 0 && j != 0 && array[i - 1][j - 1] == iC + 1) { alive++; birth++; }
            if(i != 0 && array[i - 1][j] == iC + 1) { alive++; birth++; }
            if(i != 0 && j != sizeGrid - 1 && array[i - 1][j + 1] == iC + 1) { alive++; birth++; }

            if(j != 0 && array[i][j - 1] == iC + 1) { alive++; birth++; }
            if(j != sizeGrid - 1 && array[i][j + 1] == iC + 1) { alive++; birth++; }

            if(i != sizeGrid - 1 && j != 0 && array[i + 1][j - 1] == iC + 1) { alive++; birth++; }
            if(i != sizeGrid - 1 && array[i + 1][j] == iC + 1) { alive++; birth++; }
            if(i != sizeGrid - 1 && j != sizeGrid - 1 && array[i + 1][j + 1] == iC + 1) { alive++; birth++; }

            bool test = false;
            for(int k = 0; k < iL.size(); k++)
                if (alive == iL[k])
                {
                    test = true;
                    break;
                }
            if ((test && array[i][j] == iC + 1) || array[i][j] == 0)
                newArray[i][j] = array[i][j];
            else
                newArray[i][j] = array[i][j] - 1;

            test = false;
            for(int k = 0; k < iA.size(); k++)
                if (birth == iA[k])
                {
                    test = true;
                    break;
                }
            if (test == true && array[i][j] == 0)
                newArray[i][j] = iC + 1;
            else if(array[i][j] == 0)
                newArray[i][j] = 0;
        }

    }

    switchArray();

//    out << "array \n";
//    for(int i = 0; i < sizeGrid; i++) {
//        for(int j = 0; j < sizeGrid; j++)
//            out << array[i][j] << " ";
//          out << "\n";
//    }
//    fout.close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete painter;
    delete pm;
    for(int i = 0; i < sizeGrid; i++)
    {
        delete [] array[i];
        delete [] newArray[i];
    }
    delete [] array;
    delete [] newArray;
}
