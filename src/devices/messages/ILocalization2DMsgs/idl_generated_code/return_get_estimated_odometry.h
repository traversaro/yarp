/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_ESTIMATED_ODOMETRY_H
#define YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_ESTIMATED_ODOMETRY_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>
#include <yarp/dev/OdometryData.h>

class return_get_estimated_odometry :
        public yarp::os::idl::WirePortable
{
public:
    // Fields
    bool ret{false};
    yarp::dev::OdometryData odom{};

    // Default constructor
    return_get_estimated_odometry() = default;

    // Constructor with field values
    return_get_estimated_odometry(const bool ret,
                                  const yarp::dev::OdometryData& odom);

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
    typedef yarp::os::idl::Unwrapped<return_get_estimated_odometry> unwrapped;

private:
    // read/write ret field
    bool read_ret(yarp::os::idl::WireReader& reader);
    bool write_ret(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_ret(yarp::os::idl::WireReader& reader);
    bool nested_write_ret(const yarp::os::idl::WireWriter& writer) const;

    // read/write odom field
    bool read_odom(yarp::os::idl::WireReader& reader);
    bool write_odom(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_odom(yarp::os::idl::WireReader& reader);
    bool nested_write_odom(const yarp::os::idl::WireWriter& writer) const;
};

#endif // YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_ESTIMATED_ODOMETRY_H