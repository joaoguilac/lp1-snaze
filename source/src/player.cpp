/*!
 * @file player.cpp
 * @brief Implementation of Player class.
 */

#include "../include/player.h"

void Player::bind_snake( Snake * ptr_snake ){
      m_snake = ptr_snake;
    }

void Player::bind_level( Level * ptr_level ){
    m_lv = ptr_level;
}

Direction Player::next_move(){
    auto pos = m_snake->get_pos();    // Current position of snake's head.

    /*Random number generation.*/
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<> dist(0, 2);
    int choice = dist(g);

    // Current direction is east.
    if(m_snake->get_direction() == EAST){
        if( !( m_lv->can_go(pos.first, pos.second+1) || m_lv->can_go(pos.first-1, pos.second) || m_lv->can_go(pos.first+1, pos.second) ) ){                                             
            return NONE;         // Snake is going to crash.
        }
        while(1){
            choice = dist(g);
            if(choice == 0){
                if( m_lv->can_go(pos.first, pos.second+1) ){   // Can go east?
                    return EAST;
                }
            }
            else if (choice == 1){
                if( m_lv->can_go(pos.first-1, pos.second)){    // Can go north?
                    return NORTH;
                }
            }
            else if (choice == 2){
                if( m_lv->can_go(pos.first+1, pos.second)){    // Can go south?
                    return SOUTH;
                }
            }
        }
    }
    // Current direction is west.
    else if(m_snake->get_direction() == WEST){
        if( !( m_lv->can_go(pos.first, pos.second-1) || m_lv->can_go(pos.first-1, pos.second) || m_lv->can_go(pos.first+1, pos.second) ) ){
            return NONE;         // Snake is going to crash.
        }
        while(1){
            choice = dist(g);
            if(choice == 0){
                if( m_lv->can_go(pos.first, pos.second-1) ){   // Can go west?
                    return WEST;
                }
            }
            else if (choice == 1){
                if( m_lv->can_go(pos.first-1, pos.second)){    // Can go north?
                    return NORTH;
                }
            }
            else if (choice == 2){
                if( m_lv->can_go(pos.first+1, pos.second)){    // Can go south?
                    return SOUTH;
                }
            }
        }
    }
    // Current direction is north.
    else if(m_snake->get_direction() == NORTH){
        if( !( m_lv->can_go(pos.first-1, pos.second) || m_lv->can_go(pos.first, pos.second+1) || m_lv->can_go(pos.first, pos.second-1) ) ){
            return NONE;         // Snake is going to crash.
        }
        while(1){
            choice = dist(g);
            if(choice == 0){
                if( m_lv->can_go(pos.first-1, pos.second)){         // Can go north?
                    return NORTH;
                }
            }
            else if (choice == 1){
                if( m_lv->can_go(pos.first, pos.second+1) ){        // Can go east?
                    return EAST;
                }
            }
            else if (choice == 2){
                if( m_lv->can_go(pos.first, pos.second-1) ){        // Can go west?
                    return WEST;
                }
            }
        }
    }
    // Current direction is south.
    else if(m_snake->get_direction() == SOUTH){
        if( !( m_lv->can_go(pos.first+1, pos.second) || m_lv->can_go(pos.first, pos.second+1) || m_lv->can_go(pos.first, pos.second-1) ) ){
            return NONE;         // Snake is going to crash.
        }
        while(1){
            choice = dist(g);
            if(choice == 0){
                if( m_lv->can_go(pos.first+1, pos.second)){        // Can go south?
                    return SOUTH;
                }
            }
            else if (choice == 1){
                if( m_lv->can_go(pos.first, pos.second+1) ){       // Can go east?
                    return EAST;
                }
            }
            else if (choice == 2){
                if( m_lv->can_go(pos.first, pos.second-1) ){        // Can go west?
                    return WEST;
                }
            }
        }
    }
    return NONE;
}

Direction Player::next_move_not_random(){
    auto pos = m_snake->get_pos();    // Current position of snake's head.

    // Current direction is east.
    if(m_snake->get_direction() == EAST){
        if( !( m_lv->can_go(pos.first, pos.second+1) || m_lv->can_go(pos.first-1, pos.second) || m_lv->can_go(pos.first+1, pos.second) ) ){                                             
            return NONE;         // Snake is going to crash.
        }
        if( m_lv->can_go(pos.first, pos.second+1) ){   // Can go east?
            return EAST;
        }
        else if( m_lv->can_go(pos.first-1, pos.second)){    // Can go north?
            return NORTH;
        }
        else if( m_lv->can_go(pos.first+1, pos.second)){    // Can go south?
            return SOUTH;
        }
    }
    // Current direction is west.
    else if(m_snake->get_direction() == WEST){
        if( !( m_lv->can_go(pos.first, pos.second-1) || m_lv->can_go(pos.first-1, pos.second) || m_lv->can_go(pos.first+1, pos.second) ) ){
            return NONE;         // Snake is going to crash.
        }
        if( m_lv->can_go(pos.first, pos.second-1) ){   // Can go west?
            return WEST;
        }
        else if( m_lv->can_go(pos.first-1, pos.second)){    // Can go north?
            return NORTH;
        }
        else if( m_lv->can_go(pos.first+1, pos.second)){    // Can go south?
            return SOUTH;
        }
    }
    // Current direction is north.
    else if(m_snake->get_direction() == NORTH){
        if( !( m_lv->can_go(pos.first-1, pos.second) || m_lv->can_go(pos.first, pos.second+1) || m_lv->can_go(pos.first, pos.second-1) ) ){
            return NONE;         // Snake is going to crash.
        }
        if( m_lv->can_go(pos.first-1, pos.second)){    // Can go north?
            return NORTH;
        }
        else if( m_lv->can_go(pos.first, pos.second+1) ){   // Can go east?
            return EAST;
        }
        else if( m_lv->can_go(pos.first, pos.second-1) ){   // Can go west?
            return WEST;
        }
    }
    // Current direction is south.
    else if(m_snake->get_direction() == SOUTH){
        if( !( m_lv->can_go(pos.first+1, pos.second) || m_lv->can_go(pos.first, pos.second+1) || m_lv->can_go(pos.first, pos.second-1) ) ){
            return NONE;         // Snake is going to crash.
        }
        if( m_lv->can_go(pos.first+1, pos.second)){    // Can go south?
            return SOUTH;
        }
        else if( m_lv->can_go(pos.first, pos.second+1) ){   // Can go east?
            return EAST;
        }
        else if( m_lv->can_go(pos.first, pos.second-1) ){   // Can go west?
            return WEST;
        }
    }
    return NONE;
}

bool Player::find_solution(){
    auto matrix_backup = m_lv->get_matrix();
    m_seq_dir.clear();
    // int rowNum[] = {1, 0, 0, -1};
    // int colNum[] = {0, -1, 1, 0};
    
    int dist = bfs();
    if (dist != -1){
        // cout << "Shortest Path is " << dist << "\n";
        cout << "";
        m_min_distance = dist;
    }
    // else{
    //     // cout << "Shortest Path doesn't exist.\n";
    //     while(dist == -1){
    //         size_t rows{m_lv->get_dimensions().first};
    //         size_t cols{m_lv->get_dimensions().second};
    //         bool visited[rows][cols];                               // Matrix to store visited positions.
    //         memset(visited, false, sizeof visited);                 // Fill matrix with 0's.
    //         auto pos = m_snake->get_pos();                          // Current position of snake's head.
    //         auto dir = m_snake->get_direction();                    // Current direction of snake's head.
    //         auto opposite_dir{dir};
    //         if(dir == EAST) opposite_dir = WEST;
    //         else if(dir == WEST) opposite_dir = EAST;
    //         else if(dir == NORTH) opposite_dir = SOUTH;
    //         else if(dir == SOUTH) opposite_dir = NORTH;

    //         if(dir == EAST){
    //             for (int i = 0; i < 4; i++){
    //                 size_t row = pos.first + rowNum[i];
    //                 size_t col = pos.second + colNum[i];
                    
    //                 if (m_lv->can_go(row, col) && !visited[row][col] && opposite_dir != i ){
    //                     // mark cell as visited and enqueue it
    //                     visited[row][col] = true;
    //                     queueNode Adjcell = { {row, col}, curr.dist + 1 };
    //                     q.push(Adjcell);
    //                     matrix[row][col] = curr.dist + 1;
    //                 }
    //             }
    //             pos.second++;
    //             m_snake->set_direction(EAST);
    //         }
    //         else if(dir == WEST){
    //             pos.second--;
    //             m_snake->set_direction(WEST);
    //         }
    //         else if(dir == NORTH){
    //             pos.first--;
    //             m_snake->set_direction(NORTH);

    //         }
    //         else if(dir == SOUTH){
    //             pos.first++;
    //             m_snake->set_direction(SOUTH);
    //         }
    //     }
    //     return 0;
    // }
    else{
        // cout << "Shortest Path doesn't exist.\n";
        // while(dist == -1){
        //     auto pos = m_snake->get_pos();                          // Current position of snake's head.
        //     Snake initial_snake = *m_snake;                         // Snake's initial position.
        //     m_snakes_positions.push_back(initial_snake);            // Pushes back the snake's initial position into the vector of snake's positions.    
        //     m_map_of_snake_positions.insert({pos, initial_snake.get_direction()});
        //     auto dir = next_move_not_random();

        //     if(dir == EAST){
        //         pos.second++;
        //         m_snake->set_direction(EAST);
        //     }
        //     else if(dir == WEST){
        //         pos.second--;
        //         m_snake->set_direction(WEST);
        //     }
        //     else if(dir == NORTH){
        //         pos.first--;
        //         m_snake->set_direction(NORTH);

        //     }
        //     else if(dir == SOUTH){
        //         pos.first++;
        //         m_snake->set_direction(SOUTH);
        //     }
        // }
        return 0;
    }

    auto food_position = m_lv->get_food_pos();
    auto pos = m_snake->get_pos();                          // Current position of snake's head.
    Snake initial_snake = *m_snake;                         // Snake's initial position.
    m_snakes_positions.push_back(initial_snake);            // Pushes back the snake's initial position into the vector of snake's positions.    
    m_map_of_snake_positions.insert({pos, initial_snake.get_direction()});

    auto first = m_snake->iterator_to_head();                                   // Iterator to snake's head.
    auto current_node = m_snake->iterator_to_head()+1;                          // Iterator to snake's second node.
    auto last = m_snake->iterator_to_end();                                     // Iterator to snake's end.

    while(food_position != pos){
        auto dir = m_snake->get_direction();
        size_t num;

        if(dir == EAST){
            // print_path();
            num = m_matrix_path[pos.first][pos.second+1];
            if(m_matrix_path[pos.first-1][pos.second] < num){
                num = m_matrix_path[pos.first-1][pos.second];
                dir = NORTH;
            }
            if(m_matrix_path[pos.first+1][pos.second] < num){
                num = m_matrix_path[pos.first+1][pos.second];
                dir = SOUTH;
            }
        }
        else if(dir == WEST){
            // print_path();
            num = m_matrix_path[pos.first][pos.second-1];
            if(m_matrix_path[pos.first-1][pos.second] < num){
                num = m_matrix_path[pos.first-1][pos.second];
                dir = NORTH;
            }
            if(m_matrix_path[pos.first+1][pos.second] < num){
                num = m_matrix_path[pos.first+1][pos.second];
                dir = SOUTH;
            }
        }
        else if(dir == NORTH){
            // print_path();
            num = m_matrix_path[pos.first-1][pos.second];
            if(m_matrix_path[pos.first][pos.second+1] < num){
                num = m_matrix_path[pos.first][pos.second+1];
                dir = EAST;
            }
            if(m_matrix_path[pos.first][pos.second-1] < num){
                num = m_matrix_path[pos.first][pos.second-1];
                dir = WEST;
            }
        }
        else if(dir == SOUTH){
            // print_path();
            num = m_matrix_path[pos.first+1][pos.second];
            if(m_matrix_path[pos.first][pos.second+1] < num){
                num = m_matrix_path[pos.first][pos.second+1];
                dir = EAST;
            }
            if(m_matrix_path[pos.first][pos.second-1] < num){
                num = m_matrix_path[pos.first][pos.second-1];
                dir = WEST;
            }
        }

        if(dir == EAST){
            pos.second++;
            m_snake->set_direction(EAST);
        }
        else if(dir == WEST){
            pos.second--;
            m_snake->set_direction(WEST);
        }
        else if(dir == NORTH){
            pos.first--;
            m_snake->set_direction(NORTH);

        }
        else if(dir == SOUTH){
            pos.first++;
            m_snake->set_direction(SOUTH);
        }
        m_snake->update_pos(pos);
        m_seq_dir.push_back( dir );                 // Stores new direction.
        m_snakes_positions.push_back(*m_snake);     // Stores new snake position.
        pos = m_snake->get_pos();
    }
    m_snake->set_state( initial_snake );                // Restores snake to initial position.
    m_snakes_positions.clear();
    m_map_of_snake_positions.clear();
    m_lv->set_matrix(matrix_backup);                    // Restores matrix initial configuration.
    
    return 1;
}

Direction Player::next_dir(){
    auto dir = m_seq_dir.front();
    m_seq_dir.pop_front();
    return dir;
}

int Player::bfs(){   
    m_matrix_path.clear();
    Point source{m_lv->get_food_pos().first, m_lv->get_food_pos().second};
    Point dest{m_snake->get_pos().first, m_snake->get_pos().second};
    int rowNum[] = {1, 0, 0, -1};
    int colNum[] = {0, -1, 1, 0};
    size_t rows{m_lv->get_dimensions().first};
    size_t cols{m_lv->get_dimensions().second};
    
    bool visited[rows][cols];
    memset(visited, false, sizeof visited);
    int matrix[rows][cols];
    memset(matrix, -1, sizeof matrix);
     
    // Mark the source cell as visited.
    visited[source.row][source.col] = true;
 
    // Create a queue for BFS.
    std::queue<queueNode> q;
     
    // Distance of source cell is 0.
    queueNode s = {source, 0};
    q.push(s);  // Enqueue source cell.
    int x = source.row;
    int y = source.col;
    matrix[x][y] = 0;
    auto dir = m_snake->get_direction();
 
    // Do a BFS starting from source cell.
    while (!q.empty()){
        queueNode curr = q.front();
        Point pt = curr.pt;
 
        // If we have reached the destination cell, we are done.
        if (pt.row == dest.row && pt.col == dest.col){
            
            // cout << "Achou caminho.\n";
            // for(int i{0}; i < rows; i++){
            //     for(int j{0}; j < cols; j++){
            //         cout << std::setw(3) << matrix[i][j];
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";

            std::vector<size_t> row;                  // Vector to store a row.
            for(size_t i{0}; i < rows; i++){
                for(size_t j{0}; j < cols; j++){
                    if(matrix[i][j] == -1) row.push_back(curr.dist+1);
                    else row.push_back(matrix[i][j]);
                }
                m_matrix_path.push_back(row);
                row.clear();
            }
            return curr.dist;
        }
 
        // Otherwise dequeue the front cell in the queue and enqueue its adjacent cells.
        q.pop();

        for (int i = 0; i < 4; i++){
            size_t row = pt.row + rowNum[i];
            size_t col = pt.col + colNum[i];
             
            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (m_lv->can_go(row, col) && !visited[row][col] && !( (row == dest.row && col == dest.col) && dir == i ) ){
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col}, curr.dist + 1 };
                q.push(Adjcell);
                matrix[row][col] = curr.dist + 1;
            }
        }
    }
 
    // Return -1 if destination cannot be reached
    // cout << "Não achou caminho.\n";
    // for(int i{0}; i < rows; i++){
    //     for(int j{0}; j < cols; j++){
    //         cout << std::setw(3) << matrix[i][j];
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    return -1;
}

size_t Player::get_min_dist(){
    return m_min_distance;
}

void Player::print_path(){
    for(int i{0}; i < m_matrix_path.size(); i++){
        for(int j{0}; j < m_matrix_path[i].size(); j++){
            cout << std::setw(3) << m_matrix_path[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}


// bool Player::repeated_position(std::pair<size_t, size_t> pos, Direction dir){
//     if(dir == EAST){
//         pos.second++;
//     }
//     else if(dir == WEST){
//         pos.second--;
//     }
//     else if(dir == NORTH){
//         pos.first--;
//     }
//     else if(dir == SOUTH){
//         pos.first++; 
//     }
//     // cout << "pos: " << pos.first << "," << pos.second << ": " << dir << "\n";
//     auto range = m_map_of_snake_positions.equal_range(pos);
//     for(auto i = range.first; i != range.second; ++i){
//         // getchar();
//         if( i->second == dir ){
//             // cout << "achou uma posição com a mesma direção.\n";
//             return 1;
//         }
//     }
//     return 0;
// }

// Direction Player::next_move_to_food(){
//     auto pos = m_snake->get_pos();    // Current position of snake's head.

//     /*Random number generation.*/
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::uniform_int_distribution<> dist(0, 2);
//     int choice = dist(g);
    
//     int flag1 = 0;
//     int flag2 = 0;
//     int flag3 = 0;

//     // Current direction is east.
//     if(m_snake->get_direction() == EAST){
//         if( !( ( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ) 
//         || ( m_lv->can_go(pos.first-1, pos.second) && !repeated_position(pos, NORTH) ) || ( m_lv->can_go(pos.first+1, pos.second) && !repeated_position(pos, SOUTH) ) ) ){                                             
//             return NONE;         // Snake does not have direction to go.
//         }
//         while(1){
//             choice = dist(g);
//             if(choice == 0 && flag1 == 0){
//                 flag1 = 1;
//                 if( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ){   // Can go east?
//                     return EAST;
//                 }
//             }
//             else if (choice == 1 && flag2 == 0){
//                 flag2 = 1;
//                 if( m_lv->can_go(pos.first-1, pos.second) && !repeated_position(pos, NORTH) ){    // Can go north?
//                     return NORTH;
//                 }
//             }
//             else if (choice == 2 && flag3 == 0){
//                 flag3 = 1;
//                 if( m_lv->can_go(pos.first+1, pos.second) && !repeated_position(pos, SOUTH)  ){    // Can go south?
//                     return SOUTH;
//                 }
//             }
//         }
//     }
//     // Current direction is west.
//     else if(m_snake->get_direction() == WEST){
//         if( !( ( m_lv->can_go(pos.first, pos.second-1) && !repeated_position(pos, WEST) ) 
//         || ( m_lv->can_go(pos.first-1, pos.second) && !repeated_position(pos, NORTH) ) || ( m_lv->can_go(pos.first+1, pos.second) && !repeated_position(pos, SOUTH) ) ) ){
//             return NONE;         // Snake does not have direction to go.
//         }
//         while(1){
//             choice = dist(g);
//             if(choice == 0 && flag1 == 0){
//                 flag1 = 1;
//                 if( m_lv->can_go(pos.first, pos.second-1) && !repeated_position(pos, WEST)  ){   // Can go west?
//                     return WEST;
//                 }
//             }
//             else if (choice == 1 && flag2 == 0){
//                 flag2 = 1;
//                 if( m_lv->can_go(pos.first-1, pos.second) && !repeated_position(pos, NORTH) ){    // Can go north?
//                     return NORTH;
//                 }
//             }
//             else if (choice == 2 && flag3 == 0){
//                 flag3 = 1;
//                 if( m_lv->can_go(pos.first+1, pos.second) && !repeated_position(pos, SOUTH) ){    // Can go south?
//                     return SOUTH;
//                 }
//             }
//         }
//     }
//     // Current direction is north.
//     else if(m_snake->get_direction() == NORTH){
//         if( !( ( m_lv->can_go(pos.first-1, pos.second) && !repeated_position(pos, NORTH) ) 
//         || ( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ) || ( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ) ) ){
//             return NONE;         // Snake does not have direction to go.
//         }
//         while(1){
//             choice = dist(g);
//             if(choice == 0 && flag1 == 0){
//                 flag1 = 1;
//                 if( m_lv->can_go(pos.first-1, pos.second) && !repeated_position(pos, NORTH) ){         // Can go north?
//                     return NORTH;
//                 }
//             }
//             else if (choice == 1 && flag2 == 0){
//                 flag2 = 1;
//                 if( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ){        // Can go east?
//                     return EAST;
//                 }
//             }
//             else if (choice == 2 && flag3 == 0){
//                 flag3 = 1;
//                 if( m_lv->can_go(pos.first, pos.second-1) && !repeated_position(pos, WEST) ){        // Can go west?
//                     return WEST;
//                 }
//             }
//         }
//     }
//     // Current direction is south.
//     else if(m_snake->get_direction() == SOUTH){
//         if( !( ( m_lv->can_go(pos.first+1, pos.second) && !repeated_position(pos, SOUTH) ) 
//         || ( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ) || ( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ) ) ){
//             return NONE;         // Snake does not have direction to go.
//         }
//         while(1){
//             choice = dist(g);
//             if(choice == 0 && flag1 == 0){
//                 flag1 = 1;
//                 if( m_lv->can_go(pos.first+1, pos.second) && !repeated_position(pos, SOUTH) ){        // Can go south?
//                     return SOUTH;
//                 }
//             }
//             else if (choice == 1 && flag2 == 0){
//                 flag2 = 1;
//                 if( m_lv->can_go(pos.first, pos.second+1) && !repeated_position(pos, EAST) ){       // Can go east?
//                     return EAST;
//                 }
//             }
//             else if (choice == 2 && flag3 == 0){
//                 flag3 = 1;
//                 if( m_lv->can_go(pos.first, pos.second-1) && !repeated_position(pos, WEST) ){        // Can go west?
//                     return WEST;
//                 }
//             }
//         }
//     }
//     return NONE;
// }