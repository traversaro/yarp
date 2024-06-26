# SPDX-FileCopyrightText: 2006-2023 Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

if (YARP_COMPILE_ALL_FAKE_DEVICES)
  set(ENABLE_yarpmod_fakeJointCoupling ON CACHE BOOL "" FORCE)
endif()

yarp_prepare_plugin(fakeJointCoupling
  CATEGORY device
  TYPE FakeJointCoupling
  INCLUDE FakeJointCoupling.h
  GENERATE_PARSER
)

if(NOT SKIP_fakeJointCoupling)
  yarp_add_plugin(yarp_fakeJointCoupling)

  target_sources(yarp_fakeJointCoupling
    PRIVATE
      FakeJointCoupling.cpp
      FakeJointCoupling.h
      FakeJointCoupling_ParamsParser.cpp
      FakeJointCoupling_ParamsParser.h
  )

  target_link_libraries(yarp_fakeJointCoupling
    PRIVATE
      YARP::YARP_os
      YARP::YARP_sig
      YARP::YARP_dev
  )
  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS
    YARP_os
    YARP_sig
    YARP_dev
    YARP_math
  )

  yarp_install(
    TARGETS yarp_fakeJointCoupling
    EXPORT YARP_${YARP_PLUGIN_MASTER}
    COMPONENT ${YARP_PLUGIN_MASTER}
    LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
    ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
    YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}
  )

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  set_property(TARGET yarp_fakeJointCoupling PROPERTY FOLDER "Plugins/Device/Fake")

  if(YARP_COMPILE_TESTS)
    add_subdirectory(tests)
  endif()

endif()
