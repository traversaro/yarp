/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_SERVICE_ISPEECHTRANSCRIPTIONMSGS_H
#define YARP_THRIFT_GENERATOR_SERVICE_ISPEECHTRANSCRIPTIONMSGS_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>
#include <return_get_language.h>
#include <return_transcribe.h>
#include <yarp/sig/Sound.h>

class ISpeechTranscriptionMsgs :
        public yarp::os::Wire
{
public:
    // Constructor
    ISpeechTranscriptionMsgs();

    virtual bool set_language(const std::string& language);

    virtual return_get_language get_language();

    virtual return_transcribe transcribe(const yarp::sig::Sound& sound);

    // help method
    virtual std::vector<std::string> help(const std::string& functionName = "--all");

    // read from ConnectionReader
    bool read(yarp::os::ConnectionReader& connection) override;
};

#endif // YARP_THRIFT_GENERATOR_SERVICE_ISPEECHTRANSCRIPTIONMSGS_H