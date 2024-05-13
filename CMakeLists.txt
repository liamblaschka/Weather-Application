cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(curl
	GIT_REPOSITORY https://github.com/curl/curl
    GIT_TAG curl-8_7_1
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(curl)

file(GLOB SOURCES "src/*.cpp")
add_executable(weather ${SOURCES})
target_link_libraries(weather PRIVATE sfml-graphics nlohmann_json::nlohmann_json CURL::libcurl)
target_compile_features(weather PRIVATE cxx_std_17)

include_directories("${PROJECT_SOURCE_DIR}/include")

if(WIN32)
    add_custom_command(
        TARGET weather
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:weather>
        VERBATIM)
endif()

install(TARGETS weather)
