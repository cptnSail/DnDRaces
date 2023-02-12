#include "stylehelper.h"

QString StyleHelper::getMainWidgetStyle() {
    return "QWidget {"
           "background-color: #49545c}";
}

QString StyleHelper::getNameStyle()
{
    return "QLabel {"
           "color: white;"
           "font-size: 20px;"
           "font-weight: 500}";
}

QString StyleHelper::getLabelStyle()
{
    return "QLabel {"
           "color: white;"
           "font-size: 40px;"
           "font-weight: 600;"
           "letter-spacing: 3px}";
}

QString StyleHelper::getPortraitStyle()
{
    return "QPushButton {"
           "background-color: #1c1c1c;"
           "border: 3px solid qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 0, 0, 255), stop:1 rgba(160, 0, 0, 255));"
           "border-radius: 5px"
           "}"
           "QPushButton:hover {"
           "border: 3px solid rgba(255, 0, 0, 255)"
           "}"
           "QPushButton:pressed {"
           "border: 3px solid rgba(141, 0, 0, 255) }";
}
