#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include <QString>

class StyleHelper
{
public:
    //Настройка интерфейса осноного окна приложения
    static QString getMainWidgetStyle();
    static QString getNameStyle();
    static QString getLabelStyle();
    static QString getPortraitStyle();
};

#endif // STYLEHELPER_H
