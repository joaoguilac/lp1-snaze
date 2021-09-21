/*!
 * @file snake.cpp
 * @brief Implementation of Snake class.
 */

#include "../include/snake.h"

void Snake::set_start_pos(std::pair <size_t, size_t> pos){
      m_body.push_back(pos);
}

void Snake::restart(std::pair <size_t, size_t> pos){
    m_body.clear();
    m_body.push_back(pos);
    m_current_dir = EAST;
}

size_t Snake::get_size(){
    return m_body.size();
}

std::pair <size_t, size_t> Snake::grow(){
    m_body.push_back(m_prev_pos);
    return m_prev_pos;
}

Direction Snake::get_direction(){
    return m_current_dir;
}

void Snake::set_direction(Direction dir){
    m_current_dir = dir;
}

std::pair <size_t, size_t> Snake::get_pos(){
    return *m_body.begin();
}

void Snake::update_pos(std::pair <size_t, size_t> pos){
    auto first = m_body.begin();              // Iterator to Snake's head.
    auto current_node = --m_body.end();       // Iterator to Snake's current node, starting from the last node.
    m_prev_pos = *current_node;               // Updates the previous position of the snake's last node.
    while(first != current_node){
    *current_node = *(current_node-1);      // Updates the position of the current node.
    current_node--;
    }
    *first = pos;                             // Updates the position of the snake's head.
}

std::pair <size_t, size_t> Snake::get_prev_pos(){
    return m_prev_pos;
}

std::pair <size_t, size_t> Snake::get_last_node(){
    return m_body.back();
}

std::vector<std::pair<size_t, size_t>>::iterator Snake::iterator_to_head(){
    return m_body.begin();
}

std::vector<std::pair<size_t, size_t>>::iterator Snake::iterator_to_end(){
    return m_body.end();
}

void Snake::print_node(std::pair <size_t, size_t> node){
    cout << "(" << node.first << ", " << node.second << ")" << "\n";
}

void Snake::set_state(Snake snake){
    m_current_dir = snake.m_current_dir;
    m_body = snake.m_body;
    m_prev_pos = snake.m_prev_pos;
}