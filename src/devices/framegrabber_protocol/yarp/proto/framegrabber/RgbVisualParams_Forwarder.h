/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_FRAMEGRABBER_PROTOCOL_RGBVISUALPARAMS_FORWARDER_H
#define YARP_FRAMEGRABBER_PROTOCOL_RGBVISUALPARAMS_FORWARDER_H

#include <yarp/dev/IVisualParams.h>
#include <yarp/os/Port.h>

namespace yarp {
namespace proto {
namespace framegrabber {

class RgbVisualParams_Forwarder :
        public yarp::dev::IRgbVisualParams
{
protected:
    yarp::os::Port& m_port;

public:
    RgbVisualParams_Forwarder(yarp::os::Port& port);
    ~RgbVisualParams_Forwarder() override = default;

    int getRgbHeight() override;
    int getRgbWidth() override;
    bool getRgbSupportedConfigurations(yarp::sig::VectorOf<yarp::dev::CameraConfig>& configurations) override;
    bool getRgbResolution(int& width, int& height) override;
    bool setRgbResolution(int width, int height) override;
    bool getRgbFOV(double& horizontalFov, double& verticalFov) override;
    bool setRgbFOV(double horizontalFov, double verticalFov) override;
    bool getRgbIntrinsicParam(yarp::os::Property& intrinsic) override;
    bool getRgbMirroring(bool& mirror) override;
    bool setRgbMirroring(bool mirror) override;
};

} // namespace framegrabber
} // namespace proto
} // namespace yarp

#endif // YARP_FRAMEGRABBER_PROTOCOL_RGBVISUALPARAMS_FORWARDER_H
