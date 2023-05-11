#include "mat4.h"
#include "mat4plugin.h"

#include <QtPlugin>

Mat4Plugin::Mat4Plugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void Mat4Plugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool Mat4Plugin::isInitialized() const
{
    return m_initialized;
}

QWidget *Mat4Plugin::createWidget(QWidget *parent)
{
    return new Mat4(parent);
}

QString Mat4Plugin::name() const
{
    return QLatin1String("Mat4");
}

QString Mat4Plugin::group() const
{
    return QLatin1String("");
}

QIcon Mat4Plugin::icon() const
{
    return QIcon();
}

QString Mat4Plugin::toolTip() const
{
    return QLatin1String("");
}

QString Mat4Plugin::whatsThis() const
{
    return QLatin1String("");
}

bool Mat4Plugin::isContainer() const
{
    return false;
}

QString Mat4Plugin::domXml() const
{
    return QLatin1String("<widget class=\"Mat4\" name=\"mat4\">\n</widget>\n");
}

QString Mat4Plugin::includeFile() const
{
    return QLatin1String("mat4.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(mat4plugin, Mat4Plugin)
#endif // QT_VERSION < 0x050000
