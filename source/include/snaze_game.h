#ifndef SNAZE_GAME_H
#define SNAZE_GAME_H

/*!
 * Class that defines a SnazeGame.
 * 
 * @file snaze_game.h
 * 
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <sstream>
using std::ostringstream;

#include <random>

#include <vector>

#include <string>
using std::string;
using std::stoul;

#include <exception>
using std::invalid_argument;
using std::out_of_range;

#include <memory>

#include <fstream>

#include <thread>

#include <iomanip>

#include "../lib/text_color.h"
#include "level.h"
#include "player.h"
#include "snake.h"

/// This is the main class that represents the Snaze Game.
class SnazeGame {
    /// Game state machine
    enum GameState{
        START = 0,              //!< Initial game state.
        END,                    //!< Final game state.
        WELCOME,                //!< Initial message.
        READ_INPUT,             //!< Reading user input.
        RACING                  //!< Racing game state.
    };

    //== Private members
    private:
        struct RunningOpt {
            size_t fps = 12;                        //!< The of frames (board) presented per second.
            size_t lives = 5;                       //!< The number of lives the snake shall have.
            size_t food = 10;                       //!< The number of lives the snake shall have.
            string player_type = "backtracking";    //!< Type of snake intelligence: random, backtracking.
            string data_filename;                   //!< The data file name.
        };
        RunningOpt opt;                 //!< The running options.
        std::vector<Level> levels;      //!< The vector containing the levels of the game.
        std::vector<Level>::iterator current_level;     //!< Iterator to the current level of the game.
        Snake snake;
        Player player;
        size_t deaths = 0;                              //!< The number of deaths in the game.
        size_t food_eaten = 0;                          //!< Food eaten in each level.
        size_t score = 0;                               //!< Game score total.
        size_t score_last_level = 0;                    //!< Game score in last level.
        bool crashed = 0;                               //!< Flag to indicate if the snake has crashed.
        bool found_solution = 0;                        //!< Flag to indicate if it was found a sequence of directions to the food pellet.
        GameState game_state;                           //!< The current game state.

    //== Public methods
    public:
        /*! Initializes the program.
        */
        void initialize(int argc, char *argv[]);

        /*! Reads from the data file and stores the information into the Data Set.
        * @param data_filename The name of the data file.
        */
        void read_file(string data_filename);

        /*! Returns true if the game state is equal to END.
         *  @return True if the game state is equal to END; false otherwise.
         */
        bool not_ended(void){ return game_state != GameState::END; }

        /*! Process the game.
        */
        void process(void);

        /*! Updates the game.
        */
        void update(void);

        /*! Renders the game.
        */
        void render(void);

        /*!
         * @brief Clean the terminal before render the next snake movement.
         */
        void clear_screen(void);

    //== Aux methods
    private:
        /*! Prints out the welcoming message.
        */
        void welcome_message(void);

        /*! Prints out the syntax to run the program.
        */
        void usage(void);

        /*! Moves the snake to the next position in the maze.
        */
        void move_snake();

        /*! Moves the snake to the next position in the maze 
        *   based on the sequence of directions that will lead the snake to the food pellet.
        */
        void move_snake_towards_food();
};
#endif