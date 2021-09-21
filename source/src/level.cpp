/*!
 * @file level.cpp
 * @brief Implementation of Level class.
 */

#include "../include/level.h"

void Level::push_row(std::vector<char> row){
      m_mat.push_back(row);
    }

void Level::set_dimensions(int rows, int cols){
    m_rows = rows;
    m_cols = cols;
}

std::pair <size_t, size_t> Level::get_dimensions(){
    std::pair <size_t, size_t> dimensions{m_rows, m_cols};
    return dimensions;
}

void Level::clear(){
    m_rows = m_cols = 0;
    m_mat.clear();
}

void Level::print_level(){
    std::ostringstream oss;
    for(auto i{0}; i < m_rows; i++){
        for(auto j{0}; j < m_cols; j++){
            switch (m_mat[i][j]) {
                case ' ':
                    cout << " ";
                    break;
                case 'o':
                    cout << Color::tcolor("●", Color::YELLOW, Color::BOLD);
                    break;
                case '#':
                    cout << "█";
                    break;
                case '*':
                    cout << Color::tcolor("✱", Color::GREEN, Color::BOLD);
                    break;
                case '+':
                    cout << Color::tcolor("✱", Color::GREEN, Color::BOLD);
                    break;
                case '<':
                    cout << Color::tcolor("<", Color::GREEN, Color::BOLD);
                    break;
                case '>':
                    cout << Color::tcolor(">", Color::GREEN, Color::BOLD);
                    break;
                case 'v':
                    cout << Color::tcolor("v", Color::GREEN, Color::BOLD);
                    break;
                case '^':
                    cout << Color::tcolor("∧", Color::GREEN, Color::BOLD);
                    break;
                case '.':
                    cout << Color::tcolor(" ", Color::GREEN, Color::BOLD);
                    break;
                case 'x':
                    cout << Color::tcolor("×", Color::RED, Color::BOLD);
                    break;
                case '-':
                    cout << Color::tcolor("◌", Color::RED, Color::BOLD);
                    break;
            }
        }
        cout << "\n";
    }
}

void Level::print_level_old_way(){
    for(auto i{0}; i < m_rows; i++){
        for(auto j{0}; j < m_cols; j++){
            cout << m_mat[i][j];
        }
        cout << "\n";
    }
}

void Level::place_food(){
    /*Random number generation.*/
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> row_dist(0, m_rows-1);
    std::uniform_int_distribution<> col_dist(0, m_cols-1);
    int row = row_dist(g);
    int col = col_dist(g);
    while(m_mat[row][col] != ' '){
    row = row_dist(g);
    col = col_dist(g);
    }
    m_mat[row][col] = 'o';
    m_food_position.first = row;
    m_food_position.second = col;
}

std::pair <size_t, size_t> Level::get_food_pos(){
    return m_food_position;
}

void Level::set_start_pos(int row, int col){
    m_has_start_pos = 1;
    m_snake_start_pos = {row, col};
}

std::pair <size_t, size_t> Level::get_start_pos(){
    return m_snake_start_pos;
}

bool Level::has_start_pos(){
    return m_has_start_pos;
}

char Level::get_element_in_location(int row, int col){
    return m_mat[row][col];
}

bool Level::can_go(int row, int col){
    if( m_mat[row][col] != '#' && m_mat[row][col] != '*' ) return 1;
    else return 0;
}

bool Level::is_food(std::pair<size_t, size_t> pos){
    if( m_mat[pos.first][pos.second] == 'o') return 1;
    else return 0;
}

bool Level::is_wall(std::pair<size_t, size_t> pos){
    if( m_mat[pos.first][pos.second] == '#') return 1;
    else return 0;
}

void Level::set_element_in_location(std::pair<size_t, size_t> pos, char element){
    m_mat[pos.first][pos.second] = element;
}

void Level::set_element_in_location(size_t row, size_t col, char element){
    m_mat[row][col] = element;
}

vector< vector<char> > Level::get_matrix(){
    return m_mat;
}

void Level::set_matrix(vector< vector<char> > matrix){
    m_mat = matrix;
}