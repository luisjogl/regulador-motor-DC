#include "maquinaestados.h"
#include <QDebug>
#include <iostream>

MaquinaEstados::MaquinaEstados(MainWindow *ir, QObject *parent) : QObject(parent)
{
    w = ir;
    machine = new QStateMachine();
    enMarcha = new QState(machine);
    paradaEmergencia = new QState(machine);
    regulandoPosicion = new QState(enMarcha);
    regulandoVelocidad = new QState(enMarcha);
    ultimoEstado = new QHistoryState(enMarcha);
    ultimoEstado->setDefaultState(regulandoVelocidad);

    enMarcha->addTransition(w->ui->botonParadaEmergencia, SIGNAL(clicked()), paradaEmergencia);
    paradaEmergencia->addTransition(w->ui->botonRearme, SIGNAL(clicked()), enMarcha);
    regulandoPosicion->addTransition(w->ui->botonCambiaModo, SIGNAL(clicked()), regulandoVelocidad);
    regulandoVelocidad->addTransition(w->ui->botonCambiaModo, SIGNAL(clicked()), regulandoPosicion);

    connect(paradaEmergencia, SIGNAL(activeChanged(bool)), this, SLOT(enParadaEmergencia()));
    connect(enMarcha, SIGNAL(activeChanged(bool)), this, SLOT(enEstadoMarcha()));
    connect(regulandoPosicion, SIGNAL(activeChanged(bool)), this, SLOT(enRegulandoPosicion()));
    connect(regulandoVelocidad, SIGNAL(activeChanged(bool)), this, SLOT(enRegulandoVelocidad()));


    machine->setInitialState(enMarcha);
    enMarcha->setInitialState(ultimoEstado);
    machine->start();
}

void MaquinaEstados::enParadaEmergencia(){
    if (paradaEmergencia->active() == true){
    qDebug() << "En Parada Emergencia";
    }
}

void MaquinaEstados::enEstadoMarcha(){
    if (enMarcha->active() == true){
    qDebug() << "En Estado Marcha";
    }
}

void MaquinaEstados::enRegulandoPosicion(){
    if (regulandoPosicion->active() == true){
    qDebug() << "Regulando posicion";
    }
}

void MaquinaEstados::enRegulandoVelocidad(){
    if (regulandoVelocidad->active() == true){
    qDebug() << "Regulando velocidad";
    }
}
