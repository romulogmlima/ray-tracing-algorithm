#-------------------------------------------------
# Project created by QtCreator
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG-Cenario3D
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        camera.cpp \
        intersection.cpp \
        light.cpp \
        material.cpp \
        object3d.cpp \
        ray.cpp \
        readfile.cpp \
        scene.cpp \
        vertex3.cpp \
        vector3.cpp \
        transform.cpp \
        point3.cpp \
        face3.cpp \
        rgbcolor.cpp

HEADERS  += mainwindow.h \
        camera.h \
        intersection.h \
        light.h \
        material.h \
        object3d.h \
        ray.h \
        readfile.h \
        scene.h \
        constants.h \
        transform.h \
        point3.h \
        vector3.h \
        face3.h \
        vertex3.h \
        rgbcolor.h

FORMS    += mainwindow.ui

OTHER_FILES += \
        f_cylinder.txt \
        v_cylinder.txt \
        f_cube.txt \
        v_cube.txt \
        f_roof.txt \
        v_roof.txt
