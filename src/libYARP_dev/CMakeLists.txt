# SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

project(YARP_dev)

add_subdirectory(src)

include(YarpInstallBasicPackageFiles)
yarp_install_basic_package_files(YARP_dev
  DEPENDENCIES ${YARP_dev_PUBLIC_DEPS}
  PRIVATE_DEPENDENCIES ${YARP_dev_PRIVATE_DEPS}
)

if(YARP_COMPILE_TESTS)
  add_subdirectory(tests)
endif()
