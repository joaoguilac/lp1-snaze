/*!
 * @file snaze_game.cpp
 * @brief Implementation of the SnazeGame class.
 */

#include "../include/snaze_game.h"

//====================[ SNAZE METHODS ]========================//

// Prints out the syntax to run the program.
void SnazeGame::usage()
{
    cout << "Usage: snaze [<options>] <input_level_file>\n"
         << "   Game simulation options:\n"
         << "       --help                  Print this help text.\n"
         << "       --fps <num>             Number of frames (board) presented per second. Default = 12.\n"
         << "       --lives <num>           Number of lives the snake shall have. Default = 5.\n"
         << "       --food <num>            Number of food pellets for the entire simulation. Default = 10.\n"
         << "       --playertype <type>     Type of snake intelligence: random, backtracking. Default = backtracking.\n";
    exit(1);
}

/// Prints out the welcoming message.
void SnazeGame::welcome_message(void)
{
    std::ostringstream oss;
    oss << "---------> Welcome to the classic Snake Game <---------\n"
        << "      Copyright © 2021, João Guilherme & Gregorio\n"
        << "=======================================================\n";
        // << "-------------------------------------------------------\n";
    cout << Color::tcolor(oss.str(), Color::WHITE, Color::BOLD);
}

/// Parses the arguments from the command line (CLI).
void SnazeGame::initialize( int argc, char * argv[] )
{   
    //* If only the executable name is passed.
    // if (argc < 2) {
    //     usage();
    // }

    string s_help{"--help"}, s_fps{"--fps"}, s_lives{"--lives"}, s_food{"--food"}, s_playertype{"--playertype"};
    ostringstream oss;

    //* Process the arguments from the command line.
    for(int i{1}; i < argc; i++){
        // Transform the arguments to string and lower case.
        std::string str(argv[i]);
        for (size_t j{0}; j < str.length(); j++) {
            str[j] = std::tolower(str[j]); 
        }
        if(str == s_fps){
            if(i+1 == argc){
                oss << ">>> ERROR! Missing fps value.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            try{
                opt.fps = std::stoi(argv[i+1]);
            }
            catch( const invalid_argument & e ){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' invalid for 'fps'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            catch( const out_of_range & e ){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' of 'fps' out of range.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            if(opt.fps < 1 || 24 < opt.fps){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' invalid for 'fps'. Valid range is [1,24].\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            i++;
        }

        else if(str == s_lives){
            if(i+1 == argc){
                oss << ">>> ERROR! Missing 'number of lives' value.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            try{
                opt.lives = std::stoi(argv[i+1]);
            }
            catch( const invalid_argument & e ){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' invalid for 'number of lives'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            catch( const out_of_range & e ){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' for 'number of lives' out of range.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            if(opt.lives < 1 || 15 < opt.lives){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' invalid for 'number of lives'. Valid range is [1,15].\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            i++;
        }

        else if(str == s_food){
            if(i+1 == argc){
                oss << ">>> ERROR! Missing 'number of food pellets' value.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            try{
                opt.food = std::stoi(argv[i+1]);
            }
            catch( const invalid_argument & e ){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' invalid for 'number of food pellets'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            catch( const out_of_range & e ){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' for 'number of food pellets' out of range.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            if(opt.food < 1 || 15 < opt.food){
                oss << ">>> ERROR! Value '" << argv[i+1] << "' invalid for 'number of food pellets'. Valid range is [1,15].\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            i++;
        }

        else if(str == s_playertype){
            if(i+1 == argc){
                oss << ">>> ERROR! Missing 'player type' value.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            // Transform the playertype to string and lower case.
            std::string pt_str(argv[i+1]);
            for (size_t j{0}; j < str.length(); j++) {
                pt_str[j] = std::tolower(pt_str[j]); 
            }
            opt.player_type = pt_str;
            if( !(opt.player_type == "random" || opt.player_type == "backtracking") ){
                oss << ">>> ERROR! Type '" << argv[i+1] << "' invalid for 'player type'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            i++;
        }

        else if(str == s_help) usage();

        else{
            opt.data_filename = argv[i];
        }
    }
    if(opt.data_filename.empty()){
        oss << ">>> ERROR! Missing file name.\n";
        cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
        oss.clear();
        usage();
    }

    // Set the initial game state.
    game_state = GameState::START;
}

void SnazeGame::read_file(string data_filename) {
    
    std::ifstream ifs(data_filename);
    ostringstream oss;
    
    if (not ifs.is_open())
    {
        // Print an error and exit.
        oss << "\n>>> ERROR! \"" << data_filename << "\" couldn't be opened for reading! This file probably doesn't exist.\n";
        cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
        oss.clear();
        exit(1);
    }

    std::string line;
    std::getline(ifs, line);
    if (ifs.fail()) {
        // Print an error and exit.
        oss << "\n>>> ERROR! We couldn't read \"" << data_filename << "\"! It isn't a data file.\n";
        cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
        oss.clear();
        exit(1);
    }
    ifs.seekg(0); // Put pointer at the beginning of the file

    string strInput;
    char point;
    int n_rows, n_cols;
    Level lv;

    while(ifs){
        ifs >> strInput;
        if(strInput == "") break;
        try{
                n_rows = stoi(strInput);
            }
            catch( const invalid_argument & e ){
                oss << ">>> ERROR! Value '" << strInput << "' invalid for 'number of rows'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            catch( const out_of_range & e ){
                oss << ">>> ERROR! Value '" << strInput << "' for 'number of rows' out of range.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            if(n_rows < 1 || 100 < n_rows){
                oss << ">>> ERROR! Value '" << strInput << "' invalid for 'number of rows'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
        ifs >> strInput;
        try{
                n_cols = stoi(strInput);
            }
            catch( const invalid_argument & e ){
                oss << ">>> ERROR! Value '" << strInput << "' invalid for 'number of cols'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            catch( const out_of_range & e ){
                oss << ">>> ERROR! Value '" << strInput << "' for 'number of cols' out of range.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
            if(n_cols < 1 || 100 < n_cols){
                oss << ">>> ERROR! Value '" << strInput << "' invalid for 'number of cols'.\n";
                cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                oss.clear();
                usage();
            }
        lv.set_dimensions(n_rows, n_cols);
        std::vector<char> row;                  // Vector to store a row of the level.
        getline(ifs, strInput);                 // Gets "\n".
        for(auto i{0}; i < n_rows; i++){
            for(auto j{0}; j < n_cols; j++){
                ifs.get(point);
                if(point != '#' && point != '*' && point != '.' && point != ' '){
                    // Print an error and exit.
                    oss << "\n>>> ERROR! We couldn't read \"" << data_filename << "\" correctly, the file is corrupt.\n";
                    cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
                    oss.clear();
                    exit(1);
                }
                row.push_back(point);
                if(point == '*'){
                    lv.set_start_pos(i, j);
                }
            }
            lv.push_row(row);           // Push back a new row in the level matrix.
            row.clear();
            getline(ifs, strInput);     // Gets "\n". 
        }
        if(lv.has_start_pos()) levels.push_back(lv);         // Push back a new level in the levels vector.
        lv.clear();
    }
}

void SnazeGame::process(void)
{
    if( game_state == GameState::WELCOME )
    {
        read_file(opt.data_filename);
    }
    else if(game_state == GameState::READ_INPUT)
    {
        while (getchar() != '\n') {
            // Waits for the user to press enter to start the animation.
        }
    }
    else if(game_state == GameState::RACING){
        if ((crashed && opt.lives > 0) || (food_eaten == opt.food && current_level != levels.end()-1)) {
            while (getchar() != '\n') {
                // Waits for the user to press enter to continue the game.
            }
        }
        std::chrono::milliseconds  duration{ 1000/opt.fps };
		std::this_thread::sleep_for( duration );
    }
}

void SnazeGame::update(void)
{
    if( game_state == GameState::START )
    {
        game_state = GameState::WELCOME;
    }
    else if ( game_state == GameState::WELCOME )
    {
        game_state = GameState::READ_INPUT;
    }
    else if ( game_state == GameState::READ_INPUT )
    {
        game_state = GameState::RACING;
        current_level = levels.begin();                                                 // Iterator to the current level.
        snake.set_start_pos( current_level->get_start_pos() );                          // Sets snake's start position.
        current_level->set_element_in_location(current_level->get_start_pos(), '<');    // Places snake's head in the start position of the level matrix.
        current_level->place_food();                                                    // Places the food pellet in the level matrix.
        player.bind_level(&(*current_level));                                           // Binds the level to the player.
        player.bind_snake(&snake);                                                      // Binds the snake to the player.
        if(opt.player_type == "backtracking") found_solution = player.find_solution();  // Tries to find a solution to lead the snake to the food pellet.
    }
    else if ( game_state == GameState::RACING )
    {
        // There is no more lives.
        if(opt.lives == 0){
            game_state = GameState::END;
            return;
        }
        // Snake has eaten all level's food pellets.
        if(food_eaten == opt.food){
            // If current level is not the last level.
            if( current_level != levels.end()-1 ){
                current_level++;                    // Goes to the next level.
                food_eaten = 0;                     // Restarts number of food pellets eaten.
                score_last_level = score;           // Set the score of the last level.
                snake.restart(current_level->get_start_pos());                                  // Restarts the snake with the new level start position.
                current_level->set_element_in_location(current_level->get_start_pos(), '<');    // Places snake's head in the start position.
                current_level->place_food();                                                    // Places the food pellet in the level matrix.
                player.bind_level(&(*current_level));                                           // Binds the level to the player.
                player.bind_snake(&snake);                                                      // Binds the snake to the player.
                if(opt.player_type == "backtracking") found_solution = player.find_solution();  // Tries to find a solution to lead the snake to the food pellet.
                return;
            }
            else{
                game_state = GameState::END;
                return;
            }
        }

        auto first = snake.iterator_to_head();              // Iterator to snake's head.
        auto current_node= ++snake.iterator_to_head();      // Iterator to the second node of the snake.                            
        auto last = snake.iterator_to_end();                // Iterator to the position just after the last node of the snake's body.

        // If snake grew up, find new sequence of directions towards food pellet.
        if(snake.get_last_node() == snake.get_prev_pos() && !crashed){
            if(opt.player_type == "backtracking") found_solution = player.find_solution();  // Tries to find a solution to lead the snake to the food pellet.
        }
        
        if(crashed){
            // Erases the snake nodes in the level matrix.
            current_level->set_element_in_location(*first, ' ');
            while(current_node != last){
                current_level->set_element_in_location(*current_node, ' ');
                current_node++;
            }

            snake.restart(current_level->get_start_pos());      // Restarts snake.
            first = snake.iterator_to_head();                   // Updates iterator to head.
            current_node= ++snake.iterator_to_head();           // Updates iterator to the second node.
            last = snake.iterator_to_end();                     // Updates iterator to end.
            crashed = 0;                                        // Turn off crashed flag.
            if(opt.player_type == "backtracking") found_solution = player.find_solution();  // Tries to find a solution to lead the snake to the food pellet.
        }
        else{
            // cout << "found_solution: " << found_solution << "\n"; // Debug
            if( !found_solution || player.bfs() < player.get_min_dist() ){
                if(opt.player_type == "backtracking") found_solution = player.find_solution();  // Tries to find a solution to lead the snake to the food pellet.
            }
            // cout << "found_solution: " << found_solution << "\n"; // Debug
            if(found_solution) move_snake_towards_food();                   // Moves the snake based on the sequence of directions found.
            else move_snake();                                              // Moves the snake randomly.
        }
        // Snake ate food.
        if( current_level->is_food( snake.get_pos() ) ){
            current_level->set_element_in_location(snake.grow(), '+');          // Updates the level matrix with the new last node of the snake.
            first = snake.iterator_to_head();                                   // Updates iterator to head.
            current_node = snake.iterator_to_head()+1;                          // Updates iterator to the second node.
            last = snake.iterator_to_end();                                     // Updates iterator to end.
            food_eaten++;
            score = score_last_level + food_eaten*(food_eaten+1)*10;            // Updates game score.
            current_level->place_food();                                        // Places new food pellet.
        }
        // Snake crashed.
        else if(crashed){
            // Updates snake representation in the level matrix.
            current_level->set_element_in_location(*first, 'x');
            while(current_node != last){
                current_level->set_element_in_location(*current_node, '-');
                current_node++;
            }

            // Updates lives.
            opt.lives--;
            // Updates deaths.
            deaths++;
            return;
        }
        
        // Updates snake's head in the level matrix.
        if(snake.get_direction() == EAST){
            current_level->set_element_in_location(*first, '<');
        }
        else if(snake.get_direction() == WEST){
            current_level->set_element_in_location(*first, '>');
        }
        else if(snake.get_direction() == NORTH){
            current_level->set_element_in_location(*first, 'v');
        }
        else if(snake.get_direction() == SOUTH){
            current_level->set_element_in_location(*first, '^');
        }
        // Updates snake's other nodes (represented by *) in the level matrix.
        while(current_node != last){
            current_level->set_element_in_location(*current_node, '*');
            if(current_node == last-1) current_level->set_element_in_location(*current_node, '+');
            current_node++;
        }
        // if(current_node != last) current_level->set_element_in_location(*current_node, '+');
        // If snake did not grow up, update the previous position of snake's last node in the level matrix.
        if( snake.get_last_node() != snake.get_prev_pos() ){
            current_level->set_element_in_location(snake.get_prev_pos(), ' ');
        }
    }
}

void SnazeGame::render(void)
{
    if ( game_state == GameState::WELCOME )
    {
        welcome_message(); // Prints welcome message.
    }
    else if ( game_state == GameState::READ_INPUT )
    {
        // Display summary.
        std::ostringstream oss;
        oss << " Levels loaded: " << levels.size() << " | Snake lives: " << opt.lives << " | Foods to eat: " << opt.food << "\n"
            << " Player type: " << opt.player_type << " | Fps: " << opt.fps << "\n"
            << " Clear all levels to win the game. Good luck!!!\n"
            << "-------------------------------------------------------\n"
            << ">>> Press <ENTER> to start the game!\n";
        cout << Color::tcolor(oss.str(), Color::YELLOW, Color::REGULAR);
    }
    else if ( game_state == GameState::RACING )
    {
        clear_screen();
        // Header
        string heart{"♥"};
        cout << Color::tcolor("Lives: ", Color::YELLOW, Color::REGULAR);
        for(size_t i{0}; i < opt.lives; i++) cout << Color::tcolor(heart, Color::RED, Color::REGULAR);
        for(size_t i{0}; i < deaths; i++) cout << Color::tcolor(heart, Color::WHITE, Color::REGULAR);
        std::ostringstream oss;
        oss << " | Score: " << score << " | Food eaten: " << food_eaten << " of " << opt.food
            << " | Level: " << current_level - levels.begin() + 1 << " of " << levels.size() << "\n"
            << "------------------------------------------------------------------\n\n";
        cout << Color::tcolor(oss.str(), Color::YELLOW, Color::REGULAR);

        // Prints the level matrix.
        current_level->print_level();
        // current_level->print_level_old_way();


        // Go to the next level.
        if (food_eaten == opt.food && current_level != levels.end()-1) {
            cout << Color::tcolor("\n>>> Good job! You advanced to the next level!\n", Color::GREEN, Color::BOLD);
            cout << Color::tcolor(">>> Press <ENTER> to continue.", Color::YELLOW, Color::REGULAR);
        }
        // The snake died.
        if(crashed && opt.lives > 0){
            cout << Color::tcolor("\n>>> Oh no! Your snake has crashed!\n", Color::RED, Color::BOLD);
            cout << Color::tcolor(">>> Press <ENTER> to continue.", Color::YELLOW, Color::REGULAR);
        }
        // The game is not over.
        if (opt.lives > 0 && !(food_eaten == opt.food && current_level == levels.end()-1)){
            cout << Color::tcolor("\n------------------------------------------------------------------\n", Color::YELLOW, Color::REGULAR);
        }
    }

    else if ( game_state == GameState::END )
    {
        std::ostringstream oss;
        oss.clear();
        if (opt.lives == 0) {
            oss << "          _______             _        _______  _______  _______ " << endl
                << "|\\     /|(  ___  )|\\     /|  ( \\      (  ___  )(  ____ \\(  ____ \\" << endl
                << "( \\   / )| (   ) || )   ( |  | (      | (   ) || (    \\/| (    \\/" << endl
                << " \\ (_) / | |   | || |   | |  | |      | |   | || (_____ | (__    " << endl
                << "  \\   /  | |   | || |   | |  | |      | |   | |(_____  )|  __)   " << endl
                << "   ) (   | |   | || |   | |  | |      | |   | |      ) || (      " << endl
                << "   | |   | (___) || (___) |  | (____/\\| (___) |/\\____) || (____/\\" << endl
                << "   \\_/   (_______)(_______)  (_______/(_______)\\_______)(_______/" << endl;
            cout << Color::tcolor(oss.str(), Color::RED, Color::BOLD);
        }
        else{
            oss << "          _______                     _________ _       " << endl
                << "|\\     /|(  ___  )|\\     /|  |\\     /|\\__   __/( (    /|" << endl
                << "( \\   / )| (   ) || )   ( |  | )   ( |   ) (   |  \\  ( |" << endl
                << " \\ (_) / | |   | || |   | |  | | _ | |   | |   |   \\ | |" << endl
                << "  \\   /  | |   | || |   | |  | |( )| |   | |   | (\\ \\) |" << endl
                << "   ) (   | |   | || |   | |  | || || |   | |   | | \\   |" << endl
                << "   | |   | (___) || (___) |  | () () |___) (___| )  \\  |" << endl
                << "   \\_/   (_______)(_______)  (_______)\\_______/|/    )_)" << endl;
            cout << Color::tcolor(oss.str(), Color::GREEN, Color::BOLD);
        }
        oss.clear();
        // cout << Color::tcolor("------------------------------------------------------------------\n", Color::WHITE, Color::BOLD);
        cout << Color::tcolor("\n==================================================================\n", Color::WHITE, Color::BOLD);
        cout << Color::tcolor(">>> Hope you have enjoyed the Snaze Game!\n", Color::WHITE, Color::BOLD);
        cout << Color::tcolor(">>> Thanks for playing!\n", Color::WHITE, Color::BOLD);
    }
}

void SnazeGame::clear_screen(){
    //some C++ voodoo here ;D
    #if defined _WIN32
        system("cls");
    #elif defined (LINUX) || defined(gnu_linux) || defined(linux)
        system("clear");
    #elif defined (APPLE)
        system("clear");
    #endif
}

void SnazeGame::move_snake(){
        auto dir = player.next_move();
        auto pos = snake.get_pos();

        if(dir == EAST){
            pos.second++;
            snake.set_direction(EAST);
        }
        else if(dir == WEST){
            pos.second--;
            snake.set_direction(WEST);
        }
        else if(dir == NORTH){
            pos.first--;
            snake.set_direction(NORTH);

        }
        else if(dir == SOUTH){
            pos.first++;
            snake.set_direction(SOUTH);
        }
        else{
            crashed = 1;
            return;
        }
        snake.update_pos(pos);
}

void SnazeGame::move_snake_towards_food(){
    auto dir = player.next_dir();
    auto pos = snake.get_pos();

        if(dir == EAST){
            pos.second++;
            snake.set_direction(EAST);
        }
        else if(dir == WEST){
            pos.second--;
            snake.set_direction(WEST);
        }
        else if(dir == NORTH){
            pos.first--;
            snake.set_direction(NORTH);

        }
        else if(dir == SOUTH){
            pos.first++;
            snake.set_direction(SOUTH);
        }
        snake.update_pos(pos);
}

//======================[ snaze_game.cpp ] ======================//
