#ifndef SNAKE_H
#define SNAKE_H

/*!
 *  Class that defines a Snake of the Snaze Game.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include "text_color.h"

enum Direction{
        SOUTH = 0,
        WEST,
        EAST,
        NORTH,
        NONE
};

class Snake {
    Direction m_current_dir = EAST;                 // Snake's current direction.
    vector< std::pair<size_t, size_t> > m_body;     // Snake's body.
    std::pair <size_t, size_t> m_prev_pos;          // Previous position of the snake's last node, or current position of snake's last node if snake just grew up.

  public:

    /*! This method sets snake's start position.
     *  @param pos Snake's start position.
     */
    void set_start_pos(std::pair <size_t, size_t> pos);

    /*! This method restarts the snake.
     *  @param pos Snake's start position.
     */
    void restart(std::pair <size_t, size_t> pos);
    
    /*! This method gets the size of snake's body.
     *  @return Size of snake's body.
     */
    size_t get_size();

    /*! This method gets the snake's current direction.
     *  @return Snake's current direction.
     */
    Direction get_direction();

    /*! This method sets the snake's current direction.
     *  @param dir Snake's new direction.
     */
    void set_direction(Direction dir);

    /*! This method gets the current position of snake's head.
     *  @return Current position of snake's head.
     */
    std::pair <size_t, size_t> get_pos();

    /*! This method gets the previous position of the snake's last node, or current position of snake's last node if snake just grew up.
     *  @return Previous position of the snake's last node, or current position of snake's last node if snake just grew up.
     */
    std::pair <size_t, size_t> get_prev_pos();

    /*! This method gets the position of snake's last node.
     *  @return Position of snake's last node.
     */
    std::pair <size_t, size_t> get_last_node();

    /*! This method returns an iterator to snake's head.
     *  @return Iterator to snake's head.
     */
    std::vector<std::pair<size_t, size_t>>::iterator iterator_to_head();

    /*! This method returns an iterator to the snake's end.
     *  @return Iterator to the position just after the last node of the snake's body.
     */
    std::vector<std::pair<size_t, size_t>>::iterator iterator_to_end();

    /*! This method updates the positions of snake's nodes.
     *  @param pos New position of snake's head.
     */
    void update_pos(std::pair <size_t, size_t> pos);

    /*! This method grows the snake's body.
     *  @return Position of the snake's new last node.
     */
    std::pair <size_t, size_t> grow();

    /*! This method prints a node.
     *  @param node to be printed.
     */
    void print_node(std::pair <size_t, size_t> node);

    void set_state(Snake snake);
};
#endif