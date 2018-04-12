# configuration Qt
QT       += core gui opengl widgets
CONFIG	 += c++14
TEMPLATE  = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
unix {
	LIBS     += -lGL -lGLU
}


# nom de l'exe genere
TARGET 	  = TD3

# fichiers sources/headers/ressources
SOURCES += main.cpp myglwidget.cpp \
    brick.cpp \
    element.cpp \
    wall.cpp \
    ball.cpp \
    plate.cpp \
    trackball.cpp
HEADERS += myglwidget.h \
    brick.h \
    element.h \
    wall.h \
    ball.h \
    plate.h \
    trackball.h
