cmake_minimum_required(VERSION 3.21.0)
project(LearningKorean VERSION 0.1.0 LANGUAGES CXX)

add_executable(LearningKorean 
    main.cpp
    user.cpp
    languageCategory.cpp
)

# Ustawienie standardu C++11
set(CMAKE_CXX_STANDARD 11)

# Linkowanie z biblioteką SFML
target_link_libraries(LearningKorean PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

add_custom_target(clean_target
    COMMAND rm -rf ${CMAKE_BINARY_DIR}/*.o ${CMAKE_BINARY_DIR}/LearningKorean
)

add_custom_target(pack
    COMMAND ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_BINARY_DIR}/CasinoGames_Source.zip"
            "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/user.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/languageCategory.cpp"            
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Creating source archive"
)

