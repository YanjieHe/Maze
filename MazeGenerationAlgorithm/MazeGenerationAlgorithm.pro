TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    RecursiveBacktracker.cpp \
    UndirectedGraph.cpp \
    Test.cpp \
    Kruskal.cpp \
    Prim.cpp

HEADERS += \
    RecursiveBacktracker.hpp \
    UndirectedGraph.hpp \
    Test.hpp \
    Kruskal.hpp \
    Prim.hpp
