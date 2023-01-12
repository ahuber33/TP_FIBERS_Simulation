#----------------------------------------------------------------------------
# Setup the project
#
cmake_minimum_required(VERSION 3.16...3.21)
#set (CMAKE_CXX_STANDARD 11)

#
project(TPSim)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
option(GEANT4_USE_QT ON)
if(WITH_GEANT4_UIVIS)
#find_package(Geant4 REQUIRED ui_all vis_all)
find_package(Geant4 REQUIRED gdml ui_all vis_all)
else()
find_package(Geant4 REQUIRED)
endif()



#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})

#----------------------------------------------------------------------------
# Find ROOT (required package)
#
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED)
if(ROOT_FOUND)
  message(STATUS "ROOT ok !!!")
  message("Directory :" ${ROOT_USE_FILE})
endif()

# Include ROOT's CMake functions for dictionary generation
#  since root6.20, the file is renamed and included by default, so include
#  only when we find the *old* name
   if(EXISTS "${ROOT_DIR}/modules/RootNewMacros.cmake")
     include("${ROOT_DIR}/modules/RootNewMacros.cmake")
   endif()

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${Geant4_INCLUDE_DIR}
                    ${ROOT_INCLUDE_DIRS})

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs


set(PROJECT_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimPhysics.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/Geometry.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimEventAction.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimTrackingAction.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimVisManager.cc
	#${CMAKE_CURRENT_SOURCE_DIR}/src/GMSimGeometry_Dolphy_Beta.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimGeometry.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimMaterials.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimPrimaryGeneratorAction.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimRunAction.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimSteppingAction.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/TPSimTrackInformation.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/FiberParameterisation.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/FastSimModelOpFiber.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/SimG4FastSimOpFiberRegion.cc
    )

set(PROJECT_HEADER
  ${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimPhysics.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/Geometry.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimEventAction.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimTrackingAction.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimVisManager.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimGeometry.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimMaterials.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimPrimaryGeneratorAction.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimRunAction.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimSteppingAction.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/TPSimTrackInformation.hh
	${CMAKE_CURRENT_SOURCE_DIR}/include/FiberParameterisation.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/include/FastSimModelOpFiber.hh
  ${CMAKE_CURRENT_SOURCE_DIR}/include/SimG4FastSimOpFiberRegion.hh
    )

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(TPSim TPSim.cc ${PROJECT_HEADER} ${PROJECT_SRC})
#
target_link_libraries(TPSim ${Geant4_LIBRARIES} ${ROOT_LIBRARIES} )

#link_directories( ${ROOT_LIBRARY_DIR} )

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS TPSim DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#install(TARGETS TPSim DESTINATION ../bin)
message("Directory :" ${CMAKE_CURRENT_SOURCE_DIR}/bin)
