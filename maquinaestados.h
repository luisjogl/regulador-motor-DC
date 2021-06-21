#ifndef MAQUINAESTADOS_H
#define MAQUINAESTADOS_H

#include <QObject>
#include <QStateMachine>
#include "mainwindow.h"
#include <QHistoryState>


class MaquinaEstados : public QObject
{
    Q_OBJECT

public:
    explicit MaquinaEstados(MainWindow *ir, QObject *parent = nullptr);

private:
    QStateMachine *machine;
    QState *enMarcha;
    QHistoryState *ultimoEstado;
    QState *regulandoVelocidad;
    QState *regulandoPosicion;
    QState *paradaEmergencia;

    MainWindow *w;

signals:

public slots:
    void enParadaEmergencia();
    void enEstadoMarcha();
    void enRegulandoVelocidad();
    void enRegulandoPosicion();
    //calculaAccionControl();
    //generaPWM()

};

#endif // MAQUINAESTADOS_H
