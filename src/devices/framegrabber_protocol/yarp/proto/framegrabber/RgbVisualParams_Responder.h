/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_FRAMEGRABBER_PROTOCOL_RGBVISUALPARAMS_RESPONDER_H
#define YARP_FRAMEGRABBER_PROTOCOL_RGBVISUALPARAMS_RESPONDER_H

#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/IVisualParams.h>

namespace yarp {
namespace proto {
namespace framegrabber {

class RgbVisualParams_Responder :
        public yarp::dev::DeviceResponder
{
private:
    yarp::dev::IRgbVisualParams* iRgbVisual {nullptr};

public:
    RgbVisualParams_Responder() = default;
    ~RgbVisualParams_Responder() override = default;

    bool configure(yarp::dev::IRgbVisualParams* interface);
    bool respond(const yarp::os::Bottle& cmd, yarp::os::Bottle& response) override;
};

} // namespace framegrabber
} // namespace proto
} // namespace yarp

#endif // YARP_FRAMEGRABBER_PROTOCOL_RGBVISUALPARAMS_RESPONDER_H
