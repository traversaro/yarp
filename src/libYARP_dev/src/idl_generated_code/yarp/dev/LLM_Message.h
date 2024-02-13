/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_STRUCT_LLM_MESSAGE_H
#define YARP_THRIFT_GENERATOR_STRUCT_LLM_MESSAGE_H

#include <yarp/dev/api.h>

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

namespace yarp::dev {

class YARP_dev_API LLM_Message :
        public yarp::os::idl::WirePortable
{
public:
    // Fields
    /**
     * type of message (can be prompt, assistant, function, ...)
     */
    std::string type{};
    /**
     * content of the message
     */
    std::string content{};
    /**
     * possible parameters
     */
    std::vector<std::string> parameters{};
    /**
     * possible arguments of the parameters
     */
    std::vector<std::string> arguments{};

    // Default constructor
    LLM_Message() = default;

    // Constructor with field values
    LLM_Message(const std::string& type,
                const std::string& content,
                const std::vector<std::string>& parameters,
                const std::vector<std::string>& arguments);

    // Read structure on a Wire
    bool read(yarp::os::idl::WireReader& reader) override;

    // Read structure on a Connection
    bool read(yarp::os::ConnectionReader& connection) override;

    // Write structure on a Wire
    bool write(const yarp::os::idl::WireWriter& writer) const override;

    // Write structure on a Connection
    bool write(yarp::os::ConnectionWriter& connection) const override;

    // Convert to a printable string
    std::string toString() const;

    // If you want to serialize this class without nesting, use this helper
    typedef yarp::os::idl::Unwrapped<LLM_Message> unwrapped;

private:
    // read/write type field
    bool read_type(yarp::os::idl::WireReader& reader);
    bool write_type(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_type(yarp::os::idl::WireReader& reader);
    bool nested_write_type(const yarp::os::idl::WireWriter& writer) const;

    // read/write content field
    bool read_content(yarp::os::idl::WireReader& reader);
    bool write_content(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_content(yarp::os::idl::WireReader& reader);
    bool nested_write_content(const yarp::os::idl::WireWriter& writer) const;

    // read/write parameters field
    bool read_parameters(yarp::os::idl::WireReader& reader);
    bool write_parameters(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_parameters(yarp::os::idl::WireReader& reader);
    bool nested_write_parameters(const yarp::os::idl::WireWriter& writer) const;

    // read/write arguments field
    bool read_arguments(yarp::os::idl::WireReader& reader);
    bool write_arguments(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_arguments(yarp::os::idl::WireReader& reader);
    bool nested_write_arguments(const yarp::os::idl::WireWriter& writer) const;
};

} // namespace yarp::dev

#endif // YARP_THRIFT_GENERATOR_STRUCT_LLM_MESSAGE_H