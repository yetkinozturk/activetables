cmake_minimum_required(VERSION 3.5)

project(activetables LANGUAGES CXX)

set(CMAKE_CXX_COMPILER /usr/bin/g++)

set_property(GLOBAL PROPERTY CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE 1)


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    #....
else()
    #...
endif()

include_directories(backends)
include_directories(models)
include_directories(models/fields)
include_directories(models/queryset)
include_directories(manage)
include_directories(config)
include_directories(examples/simplemodel)



set(BACKEND_FILES
    backends/basebackend.cpp
    backends/postgresql.cpp )

set(CONFIG_FILES
    config/configure.cpp)

set(MODEL_FILES
    models/model.cpp
    models/fields/basefield.cpp
    models/fields/field.cpp)

file(GLOB SOURCES 
		"models/*.cpp" 
		"models/*/*.cpp"
		"backends/*.cpp"
		"config/*.cpp")

set (LIB_FILES
	${BACKEND_FILES}
	${CONFIG_FILES}
	${MODEL_FILES}
)



add_library(activetables SHARED ${SOURCES})

set(MANAGE_FILES
    manage/manage.cpp)

add_executable(manage ${MANAGE_FILES})

target_link_libraries(manage -lpqxx -lpq -lgflags -lconfig++)

set(EXAMPLE_FILES
    examples/simplemodel/main.cpp
    examples/simplemodel/person.cpp)

# -lpqxx -lpq -laprutil-1 -lexpat -lapr-1

add_executable(simplemodel ${EXAMPLE_FILES})
target_link_libraries(simplemodel activetables -lpqxx -lpq -lgflags -lconfig++)

