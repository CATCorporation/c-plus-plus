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
    void rendu(int level,int ordonnee,int abcisse, QGraphicsView * view);
    bool loadMap(QString idx);

signals:

public slots:

private:
    QStringList mapDesign;

};

#endif // RENDERER_H
