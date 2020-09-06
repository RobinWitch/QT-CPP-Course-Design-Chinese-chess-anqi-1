#include "Board.h"
#include<QPainter>

Board::Board(QWidget *parent) : QWidget(parent)   //Board构造函数
{
    for(int i=0;i<32;i++)
    {
        _s[i].init(i);//对每个棋子进行位置、颜色、死亡、是否翻面的初始化
    }
}
void Board::paintEvent(QPaintEvent*)      //画棋盘和棋子
{
    QPainter painter(this);

    int d=40;  //棋子直径
    _r=d/2;

    for(int i=1;i<=10;i++)  //画十条横线
    {
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }

    for(int i=1;i<=9;i++)   //画九条竖线
    {
        if(i==1||i==9)
            painter.drawLine(QPoint(d*i,d),QPoint(i*d,10*d));
        else
        {
            painter.drawLine(QPoint(d*i,d),QPoint(i*d,5*d));
            painter.drawLine(QPoint(d*i,6*d),QPoint(i*d,10*d));
        }
    }

    painter.drawLine(QPoint(d*4,d),QPoint(6*d,3*d));    //画九宫格
    painter.drawLine(QPoint(d*6,d),QPoint(4*d,3*d));
    painter.drawLine(QPoint(d*4,10*d),QPoint(6*d,8*d));
    painter.drawLine(QPoint(d*6,10*d),QPoint(4*d,8*d));


    for(int i=0;i<32;i++)   //画32个棋子
    {
        drawStone(painter,i);
    }
}

QPoint Board::center(int row,int col)
{
    QPoint ret;
    ret.rx()=(col+1.5)*(_r)*2;
    ret.ry()=(row+1.5)*(_r)*2;
    return ret;
}
QPoint Board::center(int id)
{
    return center(_s[id]._row,_s[id]._col);
}

void Board::drawStone(QPainter &painter,int id)     //给每个棋子写字上色
{
    QPoint c=center(id);
    QRect rect=QRect(c.rx()-(_r),c.ry()-(_r),(_r)*2,(_r)*2);

    painter.setBrush(QBrush(QColor(255,255,0)));   //棋子背景颜色
    painter.setPen(Qt::black);  //画黑色矩形框以承载字体

    if(_s[id]._red)
        painter.setPen(Qt::red);  //将黑色矩形框换为红色矩形框

    painter.setFont(QFont("system", _r, 700));  //字体

    painter.drawEllipse(center(id),_r,_r);
    painter.drawText(rect,_s[id].getText(),QTextOption(Qt::AlignCenter));
}
