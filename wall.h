#ifndef WALL_H
#define WALL_H

#include <QtGui/QDialog>
#include "ui_wall.h"
#include "buddies.h"


class Wall : public QDialog
{
    Q_OBJECT

public:
    Wall(QWidget *parent = 0);
    ~Wall();

public slots:
	void send();
	void wallreload();

private:
    Ui::WallClass ui;
};

#endif // WALL_H
