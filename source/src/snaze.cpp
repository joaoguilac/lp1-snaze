/**
 * @file snaze.cpp
 * @author Gregorio Pinheiro Cunha (gregopc@hotmail.com)
 * @author João Guilherme Lopes Alves da Costa (joguicosta@hotmail.com)
 * @brief In this programming project we developed a simulation of the
 * classic Snake video game with a twist: the snake is trapped inside a maze!
 * @version 1.0
 * @date 2021-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/snaze_game.h"

int main( int argc, char * argv[] ){
    SnazeGame sg;
    
    sg.initialize( argc, argv );

    // Keep running until the end.
    while( sg.not_ended() ) 
    {
        sg.process();
        sg.update();
        sg.render();
    }

    return EXIT_SUCCESS;
}