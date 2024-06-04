/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef VIDEOPRODUCER_H
#define VIDEOPRODUCER_H

#include <QObject>
#include <QMutex>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QVideoSink>
typedef QVideoSink QAbstractVideoSurface;
#else
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#endif

/*! \class VideoProducer
    \brief The videoproducer class

    This class has a property where the video frame is rendered and used by the QML VideoOutput
*/
class VideoProducer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractVideoSurface *videoSurface READ videoSurface WRITE setVideoSurface)
    Q_PROPERTY(int frameWidth READ getWidth)
    Q_PROPERTY(int frameHeight READ getHeight)

public:
    VideoProducer(QObject *parent = 0);
    ~VideoProducer();
    QString getPixelAsStr(int x, int y);

    QAbstractVideoSurface *videoSurface() const;
    void setVideoSurface(QAbstractVideoSurface *surface);

    int getWidth();
    int getHeight();

private:
    QAbstractVideoSurface *m_surface;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QVideoSurfaceFormat *m_format;
#endif
    QVideoFrame *m_frame;  // Stores the value of the current video frame to allow "color picking"
    QMutex mutex;

signals:
    void resizeWindowRequest();

public slots:
    void onNewVideoContentReceived(QVideoFrame *frame);


};

#endif // VIDEOPRODUCER_H
