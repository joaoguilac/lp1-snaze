#ifndef LEVEL_H
#define LEVEL_H

/*!
 *  Class that defines a Level of the Snaze Game.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <sstream>
using std::ostringstream;

#include <random>

#include <vector>
using std::vector;

#include "text_color.h"

class Level {
    int m_rows;
    int m_cols;
    vector< vector<char> > m_mat;   // Matrix representing a level of the game.
    std::pair <size_t, size_t> m_snake_start_pos;
    bool m_has_start_pos = 0;
    std::pair <size_t, size_t> m_food_position;

  public:

    /*! This method adds a row to the level matrix.
     *  @param row Row to be added.
     */
    void push_row(std::vector<char> row);

    /*! This method sets the dimensions (rows and columns) of the level matrix.
     *  @param rows Number of rows.
     *  @param cols Number of cols.
     */
    void set_dimensions(int rows, int cols);

    /*! This method gets the dimensions (rows and columns) of the level matrix.
     *  @return Pair with dimensions (rows and columns) of the level matrix.
     */
    std::pair <size_t, size_t> get_dimensions();

    /*! This method clears the level matrix.
     */
    void clear();

    /*! This method prints the game frame.
     */
    void print_level();

    /*! This method prints the level matrix.
     */
    void print_level_old_way();

    /*! This method places the food pellet in the level matrix.
     */
    void place_food();

    /*! This method gets the food pellet position in the level matrix.
     */
    std::pair <size_t, size_t> get_food_pos();

    /*! This method sets the snake's start position.
     *  @param row Row of snake's start position.
     *  @param col Column of snake's start position.
     */
    void set_start_pos(int row, int col);

    /*! This method gets the snake's start position.
     *  @return Snake's start position.
     */
    std::pair <size_t, size_t> get_start_pos();

    /*! This method returns TRUE if the level matrix has a start position for the snake, FALSE otherwise.
     *  @return TRUE if the level matrix has a start position for the snake, FALSE otherwise.
     */
    bool has_start_pos();

    /*! This method gets the element present in the location of the level matrix defined by row and col.
     *  @param row Row of the level matrix.
     *  @param col Column of the level matrix.
     *  @return Element present in this location.
     */
    char get_element_in_location(int row, int col);
    
    /*! This method returns TRUE if the snake's head can go to the position defined by row and col, FALSE otherwise.
     *  @param row Row of the level matrix.
     *  @param col Column of the level matrix.
     *  @return TRUE if the snake's head can go to the position defined by row and col, FALSE otherwise.
     */
    bool can_go(int row, int col);

    /*! This method returns TRUE if there is a food pellet present in the position defined by row and col, FALSE otherwise.
     *  @param row Row of the level matrix.
     *  @param col Column of the level matrix.
     *  @return TRUE if there is a food pellet present in the position defined by row and col, FALSE otherwise.
     */
    bool is_food(std::pair<size_t, size_t> pos);

    /*! This method returns TRUE if there is a wall present in the position defined by row and col, FALSE otherwise.
     *  @param row Row of the level matrix.
     *  @param col Column of the level matrix.
     *  @return TRUE if there is a wall present in the position defined by row and col, FALSE otherwise.
     */
    bool is_wall(std::pair<size_t, size_t> pos);

    /*! This method sets the element in the position pos of the level matrix.
     *  @param pos Position of the level matrix.
     *  @param element Element to be set in position pos.
     */
    void set_element_in_location(std::pair<size_t, size_t> pos, char element);

    /*! This method sets the element in the position of the level matrix defined by row and col.
     *  @param row Row of the level matrix.
     *  @param col Column of the level matrix.
     *  @param element Element to be set in position pos.
     */
    void set_element_in_location(size_t row, size_t col, char element);

    vector< vector<char> > get_matrix();

    void set_matrix(vector< vector<char> > matrix);

};
#endif