#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include "element.h"
#include "brick.h"
#include "plate.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include <QDebug>


// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;


// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent),m_Trackball(WIN_WIDTH, WIN_HEIGHT, true, 1.0f)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);


//    // Reglage de la lampe
//    glEnable(GL_LIGHT0);
//   GLfloat lighta_tab[]={0.2,0.2,0.2,1.0};
//   GLfloat colorSpeculaire_tab[]={1.0,1.0,1.0,1.0};
//   GLfloat colorDiffuse_tab[]={0.8,0.8,0.8,1.0};
//   GLfloat light_tab[]={0.0,0.0,10,0,1.0};

//   glLightfv(GL_LIGHT0,GL_AMBIENT ,lighta_tab);
//   glLightfv(GL_LIGHT0,GL_SPECULAR ,colorSpeculaire_tab);
//   glLightfv(GL_LIGHT0,GL_DIFFUSE ,colorDiffuse_tab);
//   glLightfv(GL_LIGHT0,GL_POSITION ,light_tab);


//    // Activation de la lumiere
//    glEnable(GL_LIGHTING);

    //Remplissage du vector contenant les briques
    for (int i=0;i<10;i++){
        for (int j=0;j<4;j++){
            float px=i;
            float py=j;
            m_Bricks.push_back(new Brick(px*10.0,py*10.0));
            qDebug()<< "Brique placée à (" <<py<<","<<px<<")";
        }
    }


}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la position de la camera
    glLoadIdentity();
    gluLookAt(10.0f, -3.0f, 60.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Mise a jour du trackball
    glMultMatrixf(m_Trackball.GetMatrix());

    //Affichage des briques

    for (int i=0;i<m_Bricks.size();i++){
        m_Bricks[i]->Display();

    }

    //Affichage du plateau
    Plate* plateau=new Plate(40,-50.0,10);
    plateau->Display();




}


// Fonctions de gestion d'interactions souris
void MyGLWidget::mousePressEvent(QMouseEvent * event)
{
    // Gestion du click droit
    if(event->buttons() & Qt::RightButton)
    {
        m_Trackball.Press(event->pos());
        updateGL();
        event->accept();
    }
}



void MyGLWidget::mouseReleaseEvent(QMouseEvent * event)
{
    // Gestion du click droit
    if(event->button() ==  Qt::RightButton)
    {
        m_Trackball.Release(event->pos());
        updateGL();
        event->accept();
    }
}


void MyGLWidget::wheelEvent(QWheelEvent * event)
{
    m_Trackball.Wheel(event->delta());
    updateGL();
    event->accept();
}


void MyGLWidget::mouseMoveEvent(QMouseEvent * event)
{
    // Gestion du click droit
    if(event->buttons() & Qt::RightButton)
    {
        m_Trackball.Move(event->pos());
        updateGL();
        event->accept();
    }
}

// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Activation/Arret de l'animation
        case Qt::Key_Space:
        {
            if(m_AnimationTimer.isActive())
                m_AnimationTimer.stop();
            else
                m_AnimationTimer.start();

            break;
        }

        // Sortie de l'application
        case Qt::Key_Escape:
        {
            exit(0);
        }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}
