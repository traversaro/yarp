# SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

yarp_prepare_plugin(JoypadControlClient
  CATEGORY device
  TYPE JoypadControlClient
  INCLUDE JoypadControlClient.h
  EXTRA_CONFIG
    WRAPPER=JoypadControlClient
  DEFAULT ON
  GENERATE_PARSER
)

if(NOT SKIP_JoypadControlClient)
  yarp_add_plugin(yarp_JoypadControlClient)

  target_sources(yarp_JoypadControlClient
    PRIVATE
      JoypadControlClient.cpp
      JoypadControlClient.h
      JoypadControlClient_ParamsParser.cpp
      JoypadControlClient_ParamsParser.h
  )

  target_sources(yarp_JoypadControlClient PRIVATE $<TARGET_OBJECTS:joypadcontrolnetutils>)
  target_include_directories(yarp_JoypadControlClient PRIVATE $<TARGET_PROPERTY:joypadcontrolnetutils,INTERFACE_INCLUDE_DIRECTORIES>)

  target_link_libraries(yarp_JoypadControlClient
    PRIVATE
      YARP::YARP_os
      YARP::YARP_sig
      YARP::YARP_dev
  )
  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS
    YARP_os
    YARP_sig
    YARP_dev
  )

  yarp_install(
    TARGETS yarp_JoypadControlClient
    EXPORT YARP_${YARP_PLUGIN_MASTER}
    COMPONENT ${YARP_PLUGIN_MASTER}
    LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
    ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
    YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}
  )

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  if(YARP_COMPILE_TESTS)
    add_subdirectory(tests)
  endif()

  set_property(TARGET yarp_JoypadControlClient PROPERTY FOLDER "Plugins/Device")
endif()
