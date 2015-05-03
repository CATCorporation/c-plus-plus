#include "renderer.h"

renderer::renderer(QObject *parent) : QObject(parent)
{

}

renderer::~renderer()
{

}

void renderer::rendu(int level, int ordonnee, int abcisse, QGraphicsView *view)
{
    QGraphicsScene *scene = new QGraphicsScene; //creation de la scene

    int w =0,h=0;

    for(int i=0; i<30;i++)
    {
        for(int j =0; j < 30;  j++)
        {
            QPixmap pix;
            if(i%2 ==0)
                pix.load(":/img/mur1.png");
            else
                pix.load(":/img/sol2.png");

            QGraphicsPixmapItem *item_queue = scene->addPixmap(pix);
            /*if(j == 5 && i == 4)
                item_queue->setZValue(5);*/
            item_queue->setPos(w, h);
            w+=20;
        }
        h+=20;
        w=0;
    }
    view->setScene(scene);
}

bool renderer::loadMap(QString idx)
{
    QString fileName = "map" + idx;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(0,"LoadMAP","Failed to load map:"+idx+",`n Contact support or try reinstall sofware");
        return false;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        mapDesign.append(in.readLine(1));
    }
    file.close();
    return true;
}

