#include "renderer.h"
#include <QDir>

renderer::renderer(QObject *parent) : QObject(parent)
{

}

renderer::~renderer()
{

}

void renderer::rendu(QString player,int level, QGraphicsView *view)
{
    QGraphicsScene *scene = new QGraphicsScene; //creation de la scene

    int w = 0, h = 0, x = 0, y = 0 , hide = 0;

    if(level > 3 && level <=8)
        hide = (30-( ( (level*30)/10 ))) /2 ;
    else if(level > 8)
        hide = 2;
    else
        hide = 30;

    QString sens;

    if(!player.isEmpty())
    {
        sens = player.split("&").at(1);
        x = player.split("&").at(2).toInt();
        y = player.split("&").at(3).toInt();
    }

    for(int i=0; i<30;i++)
    {
        for(int j =0; j < 30;  j++)
        {
            QPixmap pix;
            if( (i < (hide+x)) && (i > (x-hide)) &&
                (j < (y+hide)) && (j > (y-hide)))
            {
                if(mapDesign.at(i).at(j)=='D' && player.isEmpty())
                {
                    start = QPoint(i,j);
                    pix.load(":/img/down.png");
                }
                else if(mapDesign.at(i).at(j)=='A')
                {
                    start = QPoint(i,j);
                    pix.load(":/img/finish.PNG");
                }
                else if(mapDesign.at(i).at(j)=='*')
                    pix.load(":/img/mur1.png");
                else if(!player.isEmpty() &&  x == i &&  y == j)
                {
                    pix.load(":/img/"+sens+".png");
                }
                else
                    pix.load(":/img/sol2.png");
            }
            else
                pix.load(":/img/vide.png");

            QGraphicsPixmapItem *item_queue = scene->addPixmap(pix);
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
    mapDesign.clear();

    QString fileName = QDir::currentPath() + "/map/map" + idx+ ".txt";
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(0,"LoadMAP","Failed to load map:"+idx+",`n Contact support or try reinstall sofware");
        return false;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        mapDesign.append(in.readLine());
    }
    file.close();
    return true;
}

