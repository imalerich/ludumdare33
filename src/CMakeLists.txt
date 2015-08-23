# Cmake required.
cmake_minimum_required (VERSION 2.6)
project (ludumdare33)

# Version number
set (LudumDare33_VERSION_MAJOR 0)
set (LudumDare33_VERSION_MINOR 1)

# Set compiler and linker flags for gcc
set (GCC_COVERAGE_LINK_FLAGS		"-static-libgcc -static-libstdc++")
set (CMAKE_EXE_LINKER_FLAGS 		"${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set (GCC_COVERAGE_COMPILE_FLAGS "-std-c++11")
set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Configure a header file to pass CMake settings
configure_file (
	"${PROJECT_SOURCE_DIR}/LudumDare33Config.h.in"
	"${PROJECT_BINARY_DIR}/LudumDare33Config.h"
)

# Add the binary tree to the search path
include_directories("${PROJECT_BINARY_DIR}")

# Add the executable
add_executable(LudumDare33 
	main.cpp 
	gameprefix.cpp
	objects/image.cpp
	objects/monster.cpp
	objects/background.cpp
	objects/camera.cpp
	objects/carspawner.cpp
	objects/car.cpp
	math/vector2.cpp
	ui/healthbar.cpp
)

# Include Allegro libraries
target_link_libraries(LudumDare33
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_acodec-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_audio-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/libvorbis-1.3.2-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_color-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_dialog-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_font-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_image-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_memfile-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_physfs-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/liballegro_primitives-5.0.10-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/libdumb-0.9.3-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/libFLAC-1.2.1-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/libogg-1.2.1-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/libzlib-1.2.5-static-mt.a
	${CMAKE_SOURCE_DIR}/allegro/lib/libopenal-1.14-static-mt.a

	libgdiplus.a
	libuuid.a
	libkernel32.a
	libwinmm.a
	libpsapi.a
	libopengl32.a
	libglu32.a
	libuser32.a
	libcomdlg32.a
	libgdi32.a
	libshell32.a
	libole32.a
	libadvapi32.a
	libws2_32.a
	libshlwapi.a
)

# Include the Allegro header files
include_directories("${PROJECT_SOURCE_DIR}/allegro/include")

# Add the install targets
install (TARGETS LudumDare33 DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/AllegroSampleConfig.h"        
         DESTINATION include)
