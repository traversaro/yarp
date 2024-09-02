/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Sat Apr  6 12:45:14 2024


#ifndef FRAMETRANSFORMSTORAGE_PARAMSPARSER_H
#define FRAMETRANSFORMSTORAGE_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FrameTransformStorage.
*
* These are the used parameters:
* | Group name | Parameter name                   | Type   | Units | Default Value | Required | Description                                               | Notes              |
* |:----------:|:--------------------------------:|:------:|:-----:|:-------------:|:--------:|:---------------------------------------------------------:|:------------------:|
* | -          | FrameTransform_verbose_debug     | bool   | -     | false         | 0        | Enables additinal debug print                             | NB: FOR TEST ONLY. |
* | -          | FrameTransform_container_timeout | double | s     | 0.2           | 0        | After this time, not-refreshed transforms will be deleted | -                  |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device frameTransformStorage --FrameTransform_verbose_debug false --FrameTransform_container_timeout 0.2
* \endcode
*
* \code{.unparsed}
* yarpdev --device frameTransformStorage
* \endcode
*
*/

class FrameTransformStorage_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FrameTransformStorage_ParamsParser();
    ~FrameTransformStorage_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"FrameTransformStorage"};
    const std::string m_device_name = {"frameTransformStorage"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_FrameTransform_verbose_debug_defaultValue = {"false"};
    const std::string m_FrameTransform_container_timeout_defaultValue = {"0.2"};

    bool m_FrameTransform_verbose_debug = {false};
    double m_FrameTransform_container_timeout = {0.2};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif