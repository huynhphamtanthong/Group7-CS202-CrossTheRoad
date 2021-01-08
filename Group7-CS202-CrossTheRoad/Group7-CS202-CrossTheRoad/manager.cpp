#include "manager.h"
#include <string>

string str_lane = "";

void gen_lane(int width, string s) {
    while (str_lane.length() + s.length() <= width) str_lane = str_lane + s;
}

short int dd[500][100];
short int dd_counter = 0;

bool checkCollision(const unsigned char* obj, COORD size, COORD pos) {
    for (int j = 0; j < size.Y; ++j) {
        for (int i = 0; i < size.X; ++i) {
            int t = curPosition(i, j, size);
            if (obj[t] != '.') {
                if (dd[pos.X + i][pos.Y + j] == dd_counter) return true;
            }
        }
    }
    return false;
}

bool checkCollision(obstacle* obj) {
    if (obj->isActive())
        if (obj->getId() == PLAYER) {
            return checkCollision(c_player, s_player, obj->getXY());
        }
        else {
            return checkCollision(c_car, s_car, obj->getXY());
        }
}

Key getInput(bool b[6]){
    // Input =============================================
    b[0] = (bool)(GetAsyncKeyState(VK_UP) & 0x8000);
    b[1] = (bool)(GetAsyncKeyState(VK_RIGHT) & 0x8000);
    b[2] = (bool)(GetAsyncKeyState(VK_DOWN) & 0x8000);
    b[3] = (bool)(GetAsyncKeyState(VK_LEFT) & 0x8000);
    b[4] = (bool)(GetAsyncKeyState(VK_RETURN) & 0x8000);
    b[5] = (bool)(GetAsyncKeyState(VK_ESCAPE) & 0x8000);

    if (b[0]) {
        if (b[1]) return UPRIGHT;
        if (b[3]) return UPLEFT;
        return UP;
    }
    if (b[2]) {
        if (b[1]) return DOWNRIGHT;
        if (b[3]) return DOWNLEFT;
        return DOWN;
    }
    if (b[1]) return RIGHT;
    if (b[3]) return LEFT;
    return STOP; 
}

void goto_xy(int x, int y)
{
    COORD coord = {(short) x, (short) y};
    goto_xy(coord);
}

void goto_xy(COORD coord)
{
    static HANDLE std_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(std_handle, coord);
}

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int curPosition(int x, int y, COORD size){
    return y * size.X + x;
}

void clrscr(){
    system("cls");
}

void pause() {
    system("pause");
}

void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };

    SetConsoleScreenBufferSize(handle, new_size);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

COORD getWindowSize(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    return new_size;
}

void drawLevelLose(COORD start, int width) {
    goto_xy(start);

    set_color(BACKGROUND_RED);

    cout << centered("YOU LOSE THIS LEVEL !", width);

    set_color(7);

}

void drawLevelWIN(COORD start, int width) {
    goto_xy(start);

    set_color(18);

    cout << centered("YOU WIN THIS LEVEL !", width);

    set_color(7);

}

void drawHorizontalLine(char c, COORD start, int length){
    goto_xy(start);
    //for (int i = 0; i < length; ++i) cout << c;
    cout << string(length, c);
}

void drawVerticalLine(char c, COORD start, int length){
    for (int i = 0; i < length; ++i){
        goto_xy(start.X, start.Y + i);
        cout << c;
    }
}

void drawObject(const unsigned char * obj, COORD size, COORD pos){
    for (int j = 0; j < size.Y; ++j){
        for (int i = 0; i < size.X; ++i){
            int t = curPosition(i,j, size);
            if(obj[t] != '.'){
                goto_xy(pos.X + i, pos.Y + j);
                cout << obj[t];

                dd[pos.X + i][pos.Y + j] = dd_counter;
            }
        }

    }
    //goto_xy(2, 10);
    //cout << "              ";
    //goto_xy(2, 10);
    //cout << "object drawed";
}

/*
void drawObject(obstacle* obj) {
    if (obj->getId() == PLAYER) {
        clearObject(c_player, s_player, obj->last_coord);
        drawObject(c_player, s_player, obj->getXY());
    }
    else {
        clearObject(c_car, s_car, obj->last_coord);
        drawObject(c_car, s_car, obj->getXY());
    }
}
*/

void drawObject(obstacle* obj) {

    switch (obj->getId()) {
    case PLAYER:
        clearObject(c_player, s_player, obj->last_coord);
        drawObject(c_player, s_player, obj->getXY());
        break;
    case DOG:
        clearObject(c_dog, s_dog, obj->last_coord);
        drawObject(c_dog, s_dog, obj->getXY());
        break;
    case CAR2:
        clearObject(c_car2, s_car2, obj->last_coord);
        drawObject(c_car2, s_car2, obj->getXY());
        break;
    case TRUCK:
        clearObject(c_truck, s_truck, obj->last_coord);
        drawObject(c_truck, s_truck, obj->getXY());
        break;
    case CAR:
        clearObject(c_car, s_car, obj->last_coord);
        drawObject(c_car, s_car, obj->getXY());
        break;
    default:
        break;
    }
}

void clearObject(const unsigned char* obj, COORD size, COORD pos) {
    for (int j = 0; j < size.Y; ++j) {
        for (int i = 0; i < size.X; ++i) {
            int t = curPosition(i, j, size);
            if (obj[t] != '.' && pos.X + i > 0) {
                goto_xy(pos.X + i, pos.Y + j);
                cout << ' ';
            }
        }

    }
    //goto_xy(2, 10);
    //cout << "              ";
    //goto_xy(2, 10);
    //cout << "object cleared";
}

void clearObject(obstacle* obj) {
    switch (obj->getId()) {
    case PLAYER:
        clearObject(c_player, s_player, obj->getXY());
        break;
    case DOG:
        clearObject(c_dog, s_dog, obj->getXY());
        break;
    case CAR2:
        clearObject(c_car2, s_car2, obj->getXY());
        break;
    case TRUCK:
        clearObject(c_truck, s_truck, obj->getXY());
        break;
    case CAR:
        clearObject(c_car, s_car, obj->getXY());
        break;
    default:
        break;
    }
}

void clearLevel(level& lvl) {
    for (int l = 0; l < lvl.lane; ++l) {
        for (auto i = lvl.lane_vector[l].begin(); i != lvl.lane_vector[l].end(); ++i) 
            if ((*i)->isActive()) clearObject(*i);
    }
}

void drawString(string s, COORD start) {
    goto_xy(start);
    cout << s;

}

void fillBlock(char c, COORD start, int width, int height) {
    goto_xy(start);
    for (int j = 0; j < height; ++j) {
        goto_xy(start.X, start.Y + j);
        for (int i = 0; i < width; ++i) cout << c;
    }
}

string centered(string str, int width) {
    int pad = width - (int)str.size();
    if (pad <= 0) return str;
    int pad_left = pad / 2;
    return string(pad_left, ' ') + str + string(pad - pad_left, ' ');
}

void drawLevel(const level& lvl){
    if (str_lane == "") gen_lane(lvl.end.X - 1, " __ ");
    for (int i = 1; i < lvl.lane; ++i)
    {
        if (i % 2 == 0) drawHorizontalLine('_', lvl.lanes[i], lvl.end.X - 1);
        else drawString(centered(str_lane, lvl.end.X - 1), lvl.lanes[i]);
    }

    for (int l = 0; l < lvl.lane; ++l) 
        for (auto i = lvl.lane_vector[l].begin(); i != lvl.lane_vector[l].end(); ++i) {
            if ((*i)->isActive())drawObject(*i);
            else clearObject(*i);
        }
            
        
    

    for (int i = 1; i < lvl.lane; ++i) {
        if (i % 2 == 1) {
            drawTrafficLight(lvl.lanes[i], lvl.light_tick[i] < 0);
            drawTrafficLight(COORD{ lvl.end.X - 3,lvl.lanes[i].Y }, lvl.light_tick[i] < 0);
        }
    }
}

void drawTrafficLight(COORD start, bool stop) {
    set_color(7);
    goto_xy(start);
    if (!stop) set_color(BACKGROUND_GREEN);
    cout << "[O]";
    
    set_color(7);
    goto_xy(start.X, start.Y + 1);
    if (stop) set_color(BACKGROUND_RED);
    cout << "[X]";

    set_color(7);
}

manager::manager(){}

void manager::init() {
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    clrscr();
    FixConsoleWindow();
    remove_scrollbar();
    ShowConsoleCursor(false);

    state = MENU;
    scrSize = getWindowSize();
}

void manager::ui_loop(){
    last_state = state;
    switch (state){
    case MENU :
        ui_menu_loop();
        break;
    case PAUSEMENU:
        ui_pausemenu_loop();
        break;
    case LOAD:
        break;
    case GAMMING:
        ui_game_loop();
        break;
    case RESTART:
        lvl.clear();
        lvl.createLevel();
        state = GAMMING;
        break;
    case NEXTLEVEL:
        lvl.clear();
        lvl.lvl++;
        lvl.generate();
        lvl.createLevel();
        state = GAMMING;
        break;
    case EXIT:
        lvl.clear();
        break;
    default:
        break;
    }
}

void manager::ui_menu_loop(){
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    int counter = 1;
    int set[] = { 12,7,7 };
    char key = '*';
    while (1) {
        clrscr();
        set_color(set[0]);
        if (counter == 1) cout << ">>>";
        std::cout << "new game" << std::endl;

        set_color(set[1]);
        if (counter == 2) cout << ">>>";
        std::cout << "load game" << std::endl;

        set_color(set[2]);
        if (counter == 3) cout << ">>>";
        std::cout << "exit" << std::endl;

        
        key = _getch();

        if (key == 72) {
            if (counter == 1)
                counter = 3;
            else counter--;
        }

        if (key == 80) {
            if (counter == 3)
                counter = 1;
            else counter++;
        }

        if (key == '\r') {
            switch(counter){
            case 1:
                state = GAMMING;
                break;
            case 2:
                state = LOAD;
                ui_load_game();
                break;
            case 3:
                state = EXIT;
                break;
            }
            break;
        }

        set[0] = 7;
        set[1] = 7;
        set[2] = 7;
        set[counter - 1] = 12;
    }
}
void manager::ui_pausemenu_loop(){
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    int counter = 1;
    int set[] = { 12,7,7,7 };
    char key = '*';
    while (1) {
        clrscr();
        set_color(set[0]);
        if (counter == 1) cout << ">>>";
        std::cout << "resume game" << std::endl;


        set_color(set[1]);
        if (counter == 2) cout << ">>>";
        std::cout << "save game" << std::endl;

        set_color(set[2]);
        if (counter == 3) cout << ">>>";
        std::cout << "load game" << std::endl;

        set_color(set[3]);
        if (counter == 4) cout << ">>>";
        std::cout << "exit" << std::endl;

        
        
        key = _getch();

        if (key == 72) {
            if (counter == 1)
                counter = 4;
            else counter--;
        }

        if (key == 80) {
            if (counter == 4)
                counter = 1;
            else counter++;
        }

        if (key == '\r') {
            switch(counter){
            case 1:
                state = GAMMING;
                break;
            case 2:
                state = SAVE;
                ui_save_game();
                break;
            case 3:
                state = LOAD;
                ui_load_game();
                break;
            case 4:
                state = EXIT;
                break;
            default:
                break;
            }
            break;
        }

        set[0] = 7;
        set[1] = 7;
        set[2] = 7;
        set[3] = 7;
        set[counter - 1] = 12;
    }
}
void manager::ui_game_loop(){
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    // Game logic
    COORD start = { 1, 9 }, end = { scrSize.X - 1, scrSize.Y - 4 };
    bool bKey[6];
    bool gameOver = false;
    bool winlevel = false;
    bool loseLevel = false;

    for (int i = 0; i < scrSize.X; ++i)
        for (int j = 0; j < scrSize.Y; ++j) dd[i][j] = 0;
    dd_counter = 0;

    if (!lvl.isInit()) {
        lvl.init(start, end);
        if (last_state != LOAD) lvl.generate();
        lvl.createLevel();
    }

    clrscr();
    drawHorizontalLine('#', COORD{ 0,0 }, scrSize.X);   
    drawHorizontalLine('#', COORD{ 0,4 }, scrSize.X);
    drawHorizontalLine('#', COORD{ 0,scrSize.Y - 1 }, scrSize.X);
    drawVerticalLine('#', COORD{ 0,1 }, scrSize.Y - 2);
    drawVerticalLine('#', COORD{ scrSize.X - 1 ,1 }, scrSize.Y - 2);

    goto_xy(1, 2);
    cout << centered("ESC: pasuse game ; MOVE: UP, DOWN, LEFT, RIGHT ; FINISH LEVEL : HOLD ENTER", scrSize.X - 4);
    goto_xy(1, 2);
    cout << "Level: " << lvl.lvl;
    player Player(1, 5, COORD{ 1,5 }, COORD{ scrSize.X - 1 , scrSize.Y - 1 });

    while (!gameOver){
        // dd
        ++dd_counter;
        if (dd_counter > 750) dd_counter = 0;
        // Timing =====================================================
        this_thread::sleep_for(20ms);

        // Input ======================================================
        Key mov = getInput(bKey);
        if (bKey[5]) {
            state = PAUSEMENU;
            break;
        }
        if ((winlevel || loseLevel) && bKey[4]) {
            break;
        }
        //goto_xy(2, 3);
        //cout << bKey[0] << bKey[1] << bKey[2] << bKey[3] << bKey[4] << bKey[5];

        // Game logic =================================================
        Player.move(mov);
        
        lvl.update();
        Player.update();

        if (!loseLevel && !winlevel && Player.getY() >= scrSize.Y - 2 - s_player.Y) {
            state = NEXTLEVEL;
            winlevel = true;
        }
        // Display ====================================================
        drawHorizontalLine('=', COORD{ 1,8 }, scrSize.X - 2);
        drawHorizontalLine('=', COORD{ 1,scrSize.Y - 3 }, scrSize.X - 2);
        drawLevel(lvl);

        if (!loseLevel && !winlevel && checkCollision(&Player)) {
            state = RESTART;
            loseLevel = true;
        }
        drawObject(&Player);
        if (loseLevel) {
            drawLevelLose(COORD{ 1, scrSize.Y / 2 }, scrSize.X - 2);
            COORD pos = Player.getXY();
            Player.setActive(false);
            
            set_color(BACKGROUND_RED | FOREGROUND_RED);

            fillBlock('X', pos, 1, 1);
            this_thread::sleep_for(500ms);
            fillBlock('X', COORD{ pos.X - 1 , pos.Y - 1 }, 3, 3);
            this_thread::sleep_for(500ms);
            fillBlock('X', COORD{ pos.X - 2 , pos.Y - 2 }, 5, 5);
            this_thread::sleep_for(500ms);
            fillBlock('X', COORD{ pos.X - 3 , pos.Y - 3 }, 7, 7);
            this_thread::sleep_for(500ms);

            set_color(7);
        }
        else if (winlevel) drawLevelWIN(COORD{ 1, scrSize.Y / 2 }, scrSize.X - 2);
        
        
    }
}

void manager::ui_save_game() {
    string filename = "";
    while (filename.length() == 0) {
        clrscr();
        cout << "Input file save name (example : \"Today\", \"level 13\" ) :" << endl;
        getline(cin, filename);
        if (filename == "") continue;
        ofstream f;
        f.open(filename + ".lvl", ios::out | ios::app | ios::binary);
        
        f << lvl.lvl << endl;
        f << lvl.lane << endl;
        f << lvl.obj << endl;
        for (int i = 0; i < lvl.lane; ++i) f << lvl.lane_rand[i] << endl;

        f << "end" << endl;

        cout << "Saving done !" << endl;
        state = PAUSEMENU;

        f.close();

        pause();

        break;
    }
}

void manager::ui_load_game() {
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    ifstream f;
    bool read = false;
    bool bKey[6];
    while (!read) {
        clrscr();
        getInput(bKey);
        cout << "Press ESC + ENTER to go back to menu, or: " << endl;
        cout << "Enter file save name (example \"today\", \"lvl9\" ) : " << endl;
        
        if (bKey[5]) {
            state = MENU;
            break;
        }
        
        string filename = "";
        getline(cin, filename);
        if (filename == "") continue;
        try {
            f.open(filename + ".lvl", ios::in);
            if (!f) throw(filename);
        }
        catch (string filename) {
            cout << "Can not find any file names: " << filename << endl;
            pause();
            continue;
        }

        f >> lvl.lvl;
        f >> lvl.lane;
        f >> lvl.obj;
        for (int i = 0; i < lvl.lane; ++i) f >> lvl.lane_rand[i];

        cout << "Loading done ." << endl;
        pause();
        state = GAMMING;
        
        f.close();

        break;
    }
    
    
}