#include "manager.h"

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

void drawHorizontalLine(char c, COORD start, int length){
    goto_xy(start);
    for (int i = 0; i < length; ++i) cout << c;
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
            }
        }

    }
}


void drawObject(obstacle* obj) {
    if (obj->getId() == PLAYER) {
        drawObject(c_player, s_player, obj->getXY());
    }
    else {
        drawObject(c_car, s_car, obj->getXY());
    }
}

void clearObject(const unsigned char* obj, COORD size, COORD pos) {
    for (int j = 0; j < size.Y; ++j) {
        for (int i = 0; i < size.X; ++i) {
            int t = curPosition(i, j, size);
            if (obj[t] != '.') {
                goto_xy(pos.X + i, pos.Y + j);
                cout << ' ';
            }
        }

    }
}

void clearObject(obstacle* obj) {
    if (obj->getId() == PLAYER) {
        clearObject(c_player, s_player, obj->getXY());
    }
    else {
        clearObject(c_car, s_car, obj->getXY());
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
                break;
            case 3:
                state = LOAD;
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
    COORD start = { 1, 5 }, end = { scrSize.X - s_player.X - 1, scrSize.Y - s_player.Y -1 };
    bool bKey[6];
    bool gameOver = false;
    player Player(1, 5);

    clrscr();
    drawHorizontalLine('#', COORD{ 0,0 }, scrSize.X);   
    drawHorizontalLine('#', COORD{ 0,4 }, scrSize.X);
    drawHorizontalLine('#', COORD{ 0,scrSize.Y - 1 }, scrSize.X);
    drawVerticalLine('#', COORD{ 0,1 }, scrSize.Y - 2);
    drawVerticalLine('#', COORD{ scrSize.X - 1 ,1 }, scrSize.Y - 2);

    goto_xy(1, 2);
    cout << centered("ESC: pasuse game ; MOVE: UP, DOWN, LEFT, RIGHT", scrSize.X - 4);

    obstacle ob1(CAR), ob2(CAR), ob3(CAR), ob4(CAR);

    ob1.setXY(1, 10);
    ob1.move(RIGHT);
    ob2.setXY(1, 20);
    ob2.move(RIGHT);
    ob3.setXY(scrSize.X, 30);
    ob3.move(LEFT);
    ob4.setXY(1, 30);
    ob4.move(DOWNRIGHT);

    while (!gameOver){
        // Timing =====================================================
        this_thread::sleep_for(50ms);

        // Input ======================================================
        Key mov = getInput(bKey);
        if (bKey[5]) {
            state = PAUSEMENU;
            break;
        }

        goto_xy(2, 3);
        cout << bKey[0] << bKey[1] << bKey[2] << bKey[3] << bKey[4] << bKey[5];

        // Game logic =================================================

        Player.move(mov);
        clearObject(&Player);
        Player.update(start, end);
        clearObject(&ob1);
        ob1.update(start, end);
        clearObject(&ob2);
        ob2.update(start, end);
        clearObject(&ob3);
        ob3.update(start, end);
        clearObject(&ob4);
        ob4.update(start, end);
        // Display ====================================================

        drawObject(&Player);
        drawObject(&ob1);
        drawObject(&ob2);
        drawObject(&ob3);
        drawObject(&ob4);

    }
}
