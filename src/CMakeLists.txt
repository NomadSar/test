cmake_minimum_required(VERSION 3.30)

project("test" VERSION 1.0)

cmake_minimum_required(VERSION 3.30)

project("search_engine" VERSION 1.0)


# Пути к файлам реализации библиотеки
file(
        GLOB SOURCE_LIB
        ../src/*.cpp  # измените на реальный путь к вашим исходным файлам библиотеки
)

# Создаем библиотеку только из исходных файлов реализации
add_library(MySearchEngineLib ${SOURCE_LIB})

# Включаем сторонние библиотеки
include(FetchContent)

# Отключаем модульные тесты для json
set(JSON_BuildTests OFF CACHE INTERNAL "")


# Скачиваем nlohmann_json
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

# Связываем json с нашей библиотекой
target_link_libraries(
        MySearchEngineLib
        nlohmann_json::nlohmann_json
)

# Создаем основной исполняемый файл
add_executable(
        test
        main.cpp
)

# Связываем исполняемый файл с библиотекой
target_link_libraries(
        test
        MySearchEngineLib
)