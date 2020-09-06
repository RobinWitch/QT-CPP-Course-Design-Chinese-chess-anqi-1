#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include"Stone.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

    Stone _s[32];
    int _r;//棋子半径

    //返回棋盘对应的窗口坐标
    QPoint center(int row,int col);
    QPoint center(int id);

    void drawStone(QPainter &painter,int id);   //给棋子上色
    void paintEvent(QPaintEvent *);             //画棋盘

signals:

public slots:
};

#endif // BOARD_H
