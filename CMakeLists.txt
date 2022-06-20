cmake_minimum_required(VERSION 3.22)
project(hangman_game_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hangman_game_CPP
        add_new_word.cpp
        add_new_word.hpp
        draw_word.cpp
        draw_word.hpp
        guess.cpp
        guess.hpp
        hanged.cpp
        hanged.hpp
        have_letter.cpp
        have_letter.hpp
        header_print.cpp
        header_print.hpp
        main.cpp
        main.hpp
        print_secret_word.cpp
        print_secret_word.hpp
        print_wrong_guesses.cpp
        print_wrong_guesses.hpp
        read_file.cpp
        read_file.hpp
        save_file.cpp
        save_file.hpp
        win.cpp
        win.hpp)
