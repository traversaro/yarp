# Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

yarp_prepare_plugin(sound_compression_mp3
  TYPE Mp3SoundConverter
  INCLUDE Mp3Sound.h
  CATEGORY portmonitor
  DEPENDS "ENABLE_yarpcar_portmonitor;YARP_HAS_FFMPEG"
)

yarp_renamed_option(ENABLE_yarpcar_mp3Sound ENABLE_yarppm_sound_compression_mp3) # YARP_DEPRECATED never released
yarp_remove_file("${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}/mp3Sound.ini") # YARP_DEPRECATED never released

if(SKIP_sound_compression_mp3)
  return()
endif()

yarp_add_plugin(yarp_pm_sound_compression_mp3)

target_sources(yarp_pm_sound_compression_mp3
  PRIVATE
    Mp3Sound.cpp
    Mp3Sound.h
)
target_link_libraries(yarp_pm_sound_compression_mp3
  PRIVATE
    YARP::YARP_os
    YARP::YARP_sig
)
list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS
  YARP_os
  YARP_sig
)

target_include_directories(yarp_pm_sound_compression_mp3
  SYSTEM PRIVATE
    ${FFMPEG_avcodec_INCLUDE_DIRS}
)
target_link_libraries(yarp_pm_sound_compression_mp3
  PRIVATE
    ${FFMPEG_avcodec_LIBRARIES}
)
# list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS FFMPEG) # Not using targets

yarp_install(
  TARGETS yarp_pm_sound_compression_mp3
  EXPORT YARP_${YARP_PLUGIN_MASTER}
  COMPONENT ${YARP_PLUGIN_MASTER}
  LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
  ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
  YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}
)

set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

set_property(TARGET yarp_pm_sound_compression_mp3 PROPERTY FOLDER "Plugins/Port Monitor")
