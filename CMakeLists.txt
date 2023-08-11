cmake_minimum_required(VERSION 3.21.0)
project(LearningKorean VERSION 0.1.0 LANGUAGES CXX)

add_executable(LearningKorean 
    main.cpp
    user.cpp
    languageCategory.cpp
)

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
