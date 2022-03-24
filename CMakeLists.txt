cmake_policy(SET CMP0048 NEW)

project(PFE3DDecimator)

cmake_minimum_required(VERSION 3.2.0)
include(CheckCXXCompilerFlag)

# CMake configuration ==========================================

set(BUILD_LIBS ON)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)

if (APPLE)
	set(CMAKE_MACOSX_RPATH ON)
	set(CMAKE_OSX_SYSROOT /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk)
	set(CMAKE_PREFIX_PATH /usr/local/opt/)
	set(GL_SILENCE_DEPRECATION ON)
	add_definitions(-DGL_SILENCE_DEPRECATION)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	CHECK_CXX_COMPILER_FLAG("-std=c++11" HAS_CPP11_FLAG)

	if (HAS_CPP11_FLAG)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	else()
		message(FATAL_ERROR "Unsupported compiler -- requires C++11 support!")
	endif()
	if (NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEBUG)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
	endif()
endif ()

if (DEBUG_ALL)
	add_definitions(-DDEBUG_OPENGL_CONTEXT)
endif ()

# Libraries ====================================================

set(EXTERNAL external)

# CLI11 --------------------------------------------------------

set(CLI11_DIR ${ROOT_DIR}/${EXTERNAL}/CLI11)
add_subdirectory(${CLI11_DIR})

# pmp ----------------------------------------------------------

set(PMP_DIR ${ROOT_DIR}/${EXTERNAL}/pmp)
add_subdirectory(${PMP_DIR})

# glfw ---------------------------------------------------------

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "")
set(GLFW_INSTALL        OFF CACHE BOOL "")
set(GLFW_DIR ${ROOT_DIR}/${EXTERNAL}/glfw)
add_subdirectory(${GLFW_DIR})

# Eigen --------------------------------------------------------

set(EIGEN_DIR ${ROOT_DIR}/${EXTERNAL}/eigen3)
include_directories(${EIGEN_DIR})

# Includes =====================================================

include_directories(include)

# Executables ==================================================

add_definitions(-DDATA_DIR="${PROJECT_SOURCE_DIR}/data/")
add_definitions(-DTEST_DATA_DIR="${PROJECT_SOURCE_DIR}/tests/data/")

# Viewer -------------------------------------------------------

set(DECIMATOR_NAME Decimator)
file(GLOB DECIMATOR_SOURCES
		${ROOT_DIR}/src/*.cpp)
file(GLOB DECIMATOR_HEADERS
		${ROOT_DIR}/include/*.h)

set(DECIMATOR_LIBRARIES
		CLI11
		pmp
		glfw)

set(DECIMATOR_INCLUDE
		${ROOT_DIR}/include/
		${CLI11_DIR}
		${PMP_DIR}
		${GLFW_DIR}/include/
		${EIGEN_DIR})

add_executable(${DECIMATOR_NAME}
		${DECIMATOR_SOURCES}
		${DECIMATOR_HEADERS})
target_include_directories(${DECIMATOR_NAME} PUBLIC ${DECIMATOR_INCLUDE})
target_link_libraries(${DECIMATOR_NAME} PUBLIC ${DECIMATOR_LIBRARIES})

# Tests ========================================================

if (BUILD_TESTING)
	# Libraries ================================================

	# Catch2 ---------------------------------------------------

	set(CATCH2_DIR ${EXTERNAL}/Catch2)
	add_subdirectory(${CATCH2_DIR})
	include_directories(${CATCH2_DIR}/src/catch2)

	# Executables ==============================================

	set(TESTS tests)
	add_subdirectory(${TESTS})
endif ()
