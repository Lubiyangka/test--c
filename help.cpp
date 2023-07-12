#include "help.h"
#include "ui_help.h"
#include "widget.h"
#include <QGraphicsEffect>
help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    this->setWindowTitle("帮助");
    this->setFixedSize(1000,700);
    mview.setSceneRect(QRect(0,0,1000,700));
    mscene.setSceneRect(QRect(0,0,1000,700));
//    Widget* ww = new Widget;
    QString pt = "://C:/Users/LEO/Desktop/bbbg.jpg";
    if(pt==NULL){
    	printf("error")
    }
    else{
    	bg1.setPixmap(QPixmap(pt));
    	mscene.addItem(&bg1);
    	mview.setScene(&mscene);
    	mview.setParent(this);
    	mview.show();
    	ui->setupUi(this);
    }

help::~help()
{
    delete ui;
}
//修改help.cpp文件
//在热修分支上修改文件
void help::on_pushButton_clicked()
{
    Widget* w = new Widget();
    w->show();
    this->hide();
}
