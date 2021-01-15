add_executable(test_larvotto
        test_larvotto_main.cpp
        test_larvotto.cpp
        ../src/larvotto.cpp)

target_include_directories(test_larvotto PUBLIC ../include)

if (MATH_LIBRARY)
    target_link_libraries(test_larvotto ${MATH_LIBRARY})
endif ()

find_package(Catch2 REQUIRED)
target_link_libraries(test_larvotto PRIVATE Catch2::Catch2)

add_test(NAME test_larvotto COMMAND test_larvotto)
