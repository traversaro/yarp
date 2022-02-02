# Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
# Copyright (C) 2006-2010 RobotCub Consortium
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

# this is set in the parent directory, but for some reason it does not get inherited
set_source_files_properties(${SWIG_BINDINGS_SOURCE_FILE} PROPERTIES CPLUSPLUS ON)

set(CMAKE_SWIG_FLAGS "-module;yarp;-threads;${SWIG_COMMON_FLAGS}")

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

set(CMAKE_SWIG_OUTDIR "${CMAKE_BINARY_DIR}/lib/python3")
set(SWIG_OUTFILE_DIR "${CMAKE_CURRENT_BINARY_DIR}")

swig_add_library(yarp_python
                 LANGUAGE python
                 SOURCES ${SWIG_BINDINGS_SOURCE_FILE})
swig_link_libraries(yarp_python Python3::Python ${SWIG_YARP_LIBRARIES})

set_target_properties(${SWIG_MODULE_yarp_python_REAL_NAME} PROPERTIES OUTPUT_NAME "_yarp"
                                                                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/python3")

# installation path is determined reliably on most platforms using distutils
execute_process(COMMAND ${Python3_EXECUTABLE} -c "from distutils import sysconfig; print(sysconfig.get_python_lib(plat_specific=True,standard_lib=False,prefix=''))"
                OUTPUT_VARIABLE Python3_INSTDIR
                OUTPUT_STRIP_TRAILING_WHITESPACE )

set(_CMAKE_INSTALL_PYTHON3DIR "${Python3_INSTDIR}")
set(CMAKE_INSTALL_PYTHON3DIR ${_CMAKE_INSTALL_PYTHON3DIR} CACHE PATH "python3 bindings (${_CMAKE_INSTALL_PYTHON3DIR})")
mark_as_advanced(CMAKE_INSTALL_PYTHON3DIR)
if(NOT IS_ABSOLUTE ${CMAKE_INSTALL_PYTHON3DIR})
  set(CMAKE_INSTALL_FULL_PYTHON3DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_PYTHON3DIR}")
else()
  set(CMAKE_INSTALL_FULL_PYTHON3DIR "${CMAKE_INSTALL_PYTHON3DIR}")
endif()

install(FILES ${CMAKE_BINARY_DIR}/lib/python3/yarp.py
        DESTINATION ${CMAKE_INSTALL_PYTHON3DIR})


# Update RPATH
if(NOT CMAKE_SKIP_RPATH AND NOT CMAKE_SKIP_INSTALL_RPATH)
  file(RELATIVE_PATH _rel_path "${CMAKE_INSTALL_FULL_PYTHON3DIR}" "${CMAKE_INSTALL_FULL_LIBDIR}")
  get_target_property(_current_rpath ${SWIG_MODULE_yarp_python_REAL_NAME} INSTALL_RPATH)
  if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    list(APPEND _current_rpath "@loader_path/${_rel_path}")
  else()
    list(APPEND _current_rpath "\$ORIGIN/${_rel_path}")
  endif()
  set_target_properties(${SWIG_MODULE_yarp_python_REAL_NAME} PROPERTIES INSTALL_RPATH "${_current_rpath}")
endif()

install(TARGETS ${SWIG_MODULE_yarp_python_REAL_NAME}
        DESTINATION ${CMAKE_INSTALL_PYTHON3DIR})


# Install pip metadata files to ensure that CMake installations of YARP are listed by pip list
# See https://packaging.python.org/specifications/recording-installed-packages/
# and https://packaging.python.org/en/latest/specifications/core-metadata/#core-metadata
option(YARP_PYTHON_PIP_METADATA_INSTALL "Use CMake to install Python pip metadata. Set to false if some other tool installs it." TRUE)
mark_as_advanced(YARP_PYTHON_PIP_METADATA_INSTALL)
set(YARP_PYTHON_PIP_METADATA_INSTALLER "cmake" CACHE STRING "Specify the string to identify the pip Installer. Default: cmake, change this if you are using another tool.")
mark_as_advanced(YARP_PYTHON_PIP_METADATA_INSTALLER)
if(YARP_PYTHON_PIP_METADATA_INSTALL)
  if(WIN32)
    set(NEW_LINE "\n\r")
  else()
    set(NEW_LINE "\n")
  endif()
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/METADATA "")
  file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/METADATA "Metadata-Version: 2.1${NEW_LINE}")
  file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/METADATA "Name: yarp${NEW_LINE}")
  file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/METADATA "Version: ${YARP_VERSION}${NEW_LINE}")
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/INSTALLER "${YARP_PYTHON_PIP_METADATA_INSTALLER}${NEW_LINE}")
  install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/METADATA" "${CMAKE_CURRENT_BINARY_DIR}/INSTALLER"
    DESTINATION ${CMAKE_INSTALL_PYTHON3DIR}/yarp-${YARP_VERSION}.dist-info)
endif()

if(YARP_COMPILE_TESTS)
  add_subdirectory(tests)
endif()

yarp_deprecated_option(CREATE_PYTHON_VERSION)
yarp_deprecated_option(YARP_USE_PYTHON_VERSION)
