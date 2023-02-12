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
