#include "widget.h"
#include "ui_widget.h"
#include "help.h"
#include <QTimer>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setWindowTitle("贪吃蛇");
    this->setFixedSize(670,750);

    mGameView.setSceneRect(QRect(0,0,1000,1000));
    mScene.setSceneRect(QRect(0,0,1000,1000));
    path = "://C:/Users/LEO/Desktop/bbg1.png";
    mBackGround1.setPixmap(QPixmap(path));
    mBackGround2.setPixmap(QPixmap(path));
    mTitle.setPixmap(QPixmap("://C:/Users/LEO/Desktop/title.png"));
    mBackGround2.setPos(-mBackGround2.pixmap().width(),0);
    mScene.addItem(&mBackGround1);//图片元素添加到场景
    mScene.addItem(&mBackGround2);
    mScene.addItem(&mTitle);
    mGameView.setScene(&mScene);//设置视图场景
    mGameView.setParent(this);//设置视图父亲为窗口
    mGameView.show();
    mBGMoveTimer = new QTimer(this);
    mBGMoveTimer->start(10);
    connect(mBGMoveTimer,&QTimer::timeout,this,&Widget::BGMove);
    ui->setupUi(this);
    QPushButton* btn1 = new QPushButton;
    connect(btn1,&QPushButton::clicked,this,&Widget::setStyle);
    btn1->setParent(this);
//    btn1->setText("style");
//    QFont ft("Times New Roman",30,1,0);
    btn1->setFlat(true);
    btn1->resize(100,55);
//    btn1->setFont(ft);
    btn1->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::BGMove()
{
    mBackGround2.moveBy(2,0);
    mBackGround1.moveBy(2,0);
    if(mBackGround1.x() >= mBackGround1.pixmap().width())
    {
        mBackGround1.setX(-mBackGround1.pixmap().width());
    }else if(mBackGround2.x() >= mBackGround2.pixmap().width())
    {
        mBackGround2.setX(-mBackGround2.pixmap().width());
    }

}
void Widget::setStyle()
{
    if(path == "://C:/Users/LEO/Desktop/bbg2.png")
    {
        path = "://C:/Users/LEO/Desktop/bbg1.png";
        mBackGround1.setPixmap(QPixmap(path));
        mBackGround2.setPixmap(QPixmap(path));
    }
    else
    {
        path = "://C:/Users/LEO/Desktop/bbg2.png";
        mBackGround1.setPixmap(QPixmap(path));
        mBackGround2.setPixmap(QPixmap(path));
    }
}

void Widget::on_help_clicked()
{
    help* h = new help();
    this->hide();
    h->show();
}
QString Widget::getPath(){
    return this->path;
}

