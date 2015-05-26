#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class renderer : public QObject
{
    Q_OBJECT
public:
    explicit renderer(QObject *parent = 0);
    ~renderer();
    void rendu(QString player ="", int level=0, QGraphicsView * view = NULL);
    bool loadMap(QString idx);

signals:

public slots:

private:
    QStringList mapDesign;
    QPoint start;

};

#endif // RENDERER_H
