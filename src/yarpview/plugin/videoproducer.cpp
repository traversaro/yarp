/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "videoproducer.h"
#include <QVideoFrame>

VideoProducer::VideoProducer(QObject *parent) :
    QObject(parent)
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    m_format = nullptr;
#endif
    m_surface = nullptr;
    m_frame = nullptr;
}

VideoProducer::~VideoProducer()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    if(m_format)
    {
        delete m_format;
        m_format = nullptr;
    }
#endif
}


/*! \brief returns the abstract surface
 *
 *  this property is called by the qml videooutput to get the render surface
 */
QAbstractVideoSurface* VideoProducer::videoSurface() const
{
    return m_surface;
}

/*! \brief sets the abstract surface
 *
 *  this property is called by the qml videooutput and set the abstract surface to its surface
 */
void VideoProducer::setVideoSurface(QAbstractVideoSurface *surface)
{
    if (m_surface != surface && m_surface && m_surface->isActive()) {
        m_surface->stop();
    }
    m_surface = surface;

}

/*! \brief returns the width of the surface
 *  \return the width
 */
int VideoProducer::getWidth()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    if(!m_format){
        return 0;
    }
    int w = m_format->frameWidth();
#else
    if(!m_frame) {
        return 0;
    }
    int w = m_frame->width();
#endif
    return w;
}

/*! \brief returns the height of the surface
 *  \return the height
 */
int VideoProducer::getHeight()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    if(!m_format){
        return 0;
    }
    int h = m_format->frameHeight();
#else
    if(!m_frame) {
        return 0;
    }
    int h = m_frame->height();
#endif
    return h;
}

/*! \brief This gets the frame and presents it to the abstract surface
 *  \param frame the video frame
 */
void VideoProducer::onNewVideoContentReceived(QVideoFrame *frame)
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    if (m_surface){
        if(m_surface->isActive() && (m_format->frameWidth() != frame->size().width() ||
                                     m_format->frameHeight() != frame->size().height()))
        {
            m_surface->stop();
            delete m_format;
            m_format = nullptr;
        }
        if (!m_surface->isActive())
        {
            QSize s = frame->size();
            QVideoFrame::PixelFormat f = frame->pixelFormat();
            m_format = new QVideoSurfaceFormat(s, f);

            bool b = m_surface->start(*m_format);
            if (b)
            {
                qDebug("Surface STARTED! Dimensions: %dx%d -- PixelFormat: %d", s.width(), s.height(), (int)f);
            }
            else
            {
                qDebug("Surface START ERROR");
                delete m_format;
            }
            emit resizeWindowRequest();
        }
    }

    if (m_surface && m_format){
        bool b = m_surface->present(*frame);
        if (!b) {
            qWarning("Surface PRESENT ERROR");
        }
        else{
            mutex.lock();
            if(m_frame != nullptr){
                delete m_frame;
            }
            m_frame = new QVideoFrame(*frame);
            mutex.unlock();
        }
    }
#else

#endif
}

/*! \brief Pics the rgb value of the pixel specified by x and y and return it as a string
 *  \param x Integer: The x coordinate of the pixel
 *  \param y Integer: The y coordinate of the pixel
 *  \return rgbHex QString: The hexadecimal string containing the pixel color value
 */
QString VideoProducer::getPixelAsStr(int x, int y){
    mutex.lock();
    if (m_frame == nullptr || x>=m_frame->size().width() || y>=m_frame->size().height() || x<0 || y<0){
        mutex.unlock();
        return QString("Invalid");
    }
    m_frame->map( QAbstractVideoBuffer::ReadOnly );
    QImage image(m_frame->bits(), m_frame->width(),
                 m_frame->height(), m_frame->bytesPerLine(),
                 QImage::Format_RGB32);
    mutex.unlock();
    QRgb pixelVal = image.pixel(x,y);
    QString rgbHex("#");
    rgbHex += QString::number(pixelVal,16);

    return rgbHex;
}
