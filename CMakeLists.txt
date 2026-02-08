cmake_minimum_required(VERSION 3.5)
project(Prototype LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(INC_DIR
    ${PROJECT_SOURCE_DIR}/Data
    ${PROJECT_SOURCE_DIR}/Element
    ${PROJECT_SOURCE_DIR}/MessageHandler
)

# Define source / include files
set(SOURCES
    ${PROJECT_SOURCE_DIR}/Data/Data.h
    ${PROJECT_SOURCE_DIR}/Data/DerivedData.h
    ${PROJECT_SOURCE_DIR}/Data/DerivedData.cpp
    ${PROJECT_SOURCE_DIR}/Data/PictureData.h
    ${PROJECT_SOURCE_DIR}/Data/PictureData.cpp
    ${PROJECT_SOURCE_DIR}/Data/VideoData.h
    ${PROJECT_SOURCE_DIR}/Data/VideoData.cpp
    ${PROJECT_SOURCE_DIR}/Element/DerivedElement.h
    ${PROJECT_SOURCE_DIR}/Element/DerivedElement.cpp
    ${PROJECT_SOURCE_DIR}/Element/Element.h
    ${PROJECT_SOURCE_DIR}/Element/Element.cpp
    ${PROJECT_SOURCE_DIR}/MessageHandler/MessageHandler.h
    ${PROJECT_SOURCE_DIR}/MessageHandler/MessageHandler.cpp
    ${PROJECT_SOURCE_DIR}/driver.cpp
)

# Define executable to be built
add_executable(Debug ${SOURCES})

# Define destination for our include directory for target 
target_include_directories(Debug PUBLIC ${INC_DIR})

# # Installs the executable to the install interface
# install(TARGETS Debug)
# install(DIRECTORY configs DESTINATION .)