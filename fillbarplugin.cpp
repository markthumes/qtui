#include <QtPlugin>

#include "fillbar.h"
#include "fillbarplugin.h"

FillBarPlugin::FillBarPlugin(QObject *parent) : QObject(parent), initialized(false){
}

void FillBarPlugin::initialize(QDesignerFormEditorInterface * /* core */){
    if (initialized)
        return;

    initialized = true;
}
bool FillBarPlugin::isInitialized() const{
    return initialized;
}
QWidget *FillBarPlugin::createWidget(QWidget *parent){
    return new FillBar(parent);
}
QString FillBarPlugin::name() const{
    return "FillBar";
}
QString FillBarPlugin::group() const{
    return "QTUI Widgets";
}
QIcon FillBarPlugin::icon() const{
    return QIcon();
}
QString FillBarPlugin::toolTip() const{
    return "";
}
QString FillBarPlugin::whatsThis() const{
    return "";
}
bool FillBarPlugin::isContainer() const{
    return false;
}
QString FillBarPlugin::domXml() const{
    return "<ui language=\"c++\">\n"
           " <widget class=\"FillBar\" name=\"fillBar\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>Fill Bar</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>Filler.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}
QString FillBarPlugin::includeFile() const{
    return "fillbar.h";
}
