#ifndef PLAYER_H
#define PLAYER_H

/*!
 *  Class that defines a Player of the Snaze Game.
 */

#include <random>

#include <vector>
using std::vector;

#include <list>

#include <map>

#include <utility>
using std::pair;

#include <cstring>

#include <queue>

#include <iomanip>

#include "snake.h"
#include "level.h"

struct Point{
    size_t row;
    size_t col;
};

struct queueNode{
    Point pt;  // The coordinates of a cell.
    size_t dist;  // Cell's distance of from the source.
};

class Player {
    std::list<Direction> m_seq_dir;  // Sequence of directions.
    Snake * m_snake;                // Pointer to snake.
    Level * m_lv;                   // Pointer to level.
    vector< vector<char> > m_mat;   // Matrix representing a level of the game.
    // vector< vector<char> > m_matrix_path;   // Matrix to store the path to the food.
    vector< vector<size_t> > m_matrix_path;   // Matrix to store the path to the food.
    vector< Snake > m_snakes_positions;     // Vector of snake's positions.
    std::multimap< pair<size_t, size_t>, Direction > m_map_of_snake_positions;   // Map to associate snake's head position to snake's direction.
    size_t m_min_distance;

  public:

    /*! This method binds the snake to the player.
     *  @param ptr_snake Pointer to snake.
     */
    void bind_snake( Snake * ptr_snake );

    /*! This method binds the level to the player.
     *  @param ptr_level Pointer to level.
     */
    void bind_level( Level * ptr_level );

    /*! This method binds the snake to the player.
     *  @param snake Pointer to snake.
     */
    void bind_snake( Snake snake );

    /*! This method finds the snake's next direction to move.
     *  @return Direction to move snake.
     */
    Direction next_move();

    Direction next_move_not_random();

    // /*! This method finds the snake's next direction to food.
    //  *  @return Direction to move snake.
    //  */
    // Direction next_move_to_food();
    
    /*! This method finds the solution to food.
     *  @return TRUE if found solution to food, FALSE otherwise.
     */
    bool find_solution();

    /*! This method returns the next direction from the queue of directions.
     *  @return Direction to move snake.
     */
    Direction next_dir();

    // bool repeated_position(std::pair<size_t, size_t> pos, Direction dir);

    /*! This method finds the minimun distance to the food.
     *  @return TRUE if found solution to food, FALSE otherwise.
     */
    int bfs();

    /*! This method returns the minimun distance to the food.
     *  @return Minimun distance to the food.
     */
    size_t get_min_dist();

    void print_path();
};
#endif