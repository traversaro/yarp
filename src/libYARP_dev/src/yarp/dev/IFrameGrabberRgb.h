/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_DEV_IFRAMEGRABBERRGB_H
#define YARP_DEV_IFRAMEGRABBERRGB_H

#include <yarp/dev/api.h>

namespace yarp {
namespace dev {

/**
 * @ingroup dev_iface_media
 *
 * RGB Interface to a FrameGrabber device.
 */
class YARP_dev_API IFrameGrabberRgb
{
public:
    virtual ~IFrameGrabberRgb();
    /**
     * Get a rgb buffer from the frame grabber, if required
     * demosaicking/color reconstruction is applied
     *
     * @param buffer: pointer to the buffer to be filled (must be previously allocated)
     * @return true/false upon success/failure
     */
    virtual bool getRgbBuffer(unsigned char *buffer) = 0;

    /**
     * Return the height of each frame.
     * @return image height
     */
    virtual int height() const = 0;

    /**
     * Return the width of each frame.
     * @return image width
     */
    virtual int width() const = 0;
};

} // namespace dev
} // namespace yarp

#endif // YARP_DEV_IFRAMEGRABBERRGB_H
