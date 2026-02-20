# CMakeList.txt : CMake project for Indoor-Positioning-System, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Indoor-Positioning-System")

# Add source to this project's executable.
add_executable (Indoor-Positioning-System "Indoor-Positioning-System.cpp" "Indoor-Positioning-System.h")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Indoor-Positioning-System PROPERTY CXX_STANDARD 20)
endif()


# Copy Beacons.csv to the target output directory after build (Ninja / single-config).
add_custom_command(TARGET Indoor-Positioning-System
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_SOURCE_DIR}/Beacons.csv"
            "$<TARGET_FILE_DIR:Indoor-Positioning-System>/Beacons.csv"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_SOURCE_DIR}/PathwayPoints.csv"
            "$<TARGET_FILE_DIR:Indoor-Positioning-System>/PathwayPoints.csv"
    COMMENT "Copy Beacons.csv to output directory"
)

# TODO: Add tests and install targets if needed.
