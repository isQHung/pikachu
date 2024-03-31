#include "Struct.h"

char box[5][12] = {
            {" --------- "},
            {"|         |"},
            {"|         |"},
            {"|         |"},
            {" --------- "}
};

void Normal::drawbox(int background = 0){
    if (!isValid) return;//chi ve box khi hop le

    setColor(15, 0);
    for(int i = 0; i < 5; i++){
    gotoxy(x*10, y*4 + i);
    cout << box[i];
    }
    
    if (isSelected && !background) background = 15; // mau trang
    else if (suggestions && !background) background = 8; // mau xam

    // ve nen
    setColor(15,background);
    for (int i = 1; i < 4; i++) {
        gotoxy(x * 10 + 1, y * 4 + i);
        cout << "         ";
    }
    // them c
    gotoxy(x*10+5,y*4+2);
    setColor(c%14 + 1, background);
    cout << "\e[1m" << c << "";
    // if (isSelected){
    //     setColor(15,15); // nen trang
    //     for (int i = 1; i < 4; i++) {
    //         gotoxy(x * 10 + 1, y * 4 + i);
    //         cout << "         ";
    //     }

    //     gotoxy(x*10+5, y*4+2);
    //     setColor(c%6 + 9, 15);
    //     cout << "\e[1m" << c << "";
    // }else if (suggestions){
    //     setColor(15,8); // nen xam
    //     for (int i = 1; i < 4; i++) {
    //         gotoxy(x * 10 + 1, y * 4 + i);
    //         cout << "         ";
    //     }

    //     gotoxy(x*10+5, y*4+2);
    //     setColor(c%6 + 9, 8);
    //     cout << "\e[1m" << c << "";
    // }else{
    //     gotoxy(x*10+5,y*4+2);
    //     setColor(c%14 + 1, 0);
    //     cout << "\e[1m" << c << "";
    // }
    setColor(15, 0);//reset color
}

void Normal::deletebox(){
    setColor(15,0);
    for(int i = 0; i < 5; i++){
        gotoxy(x*10, y*4 + i);
        cout << "           ";
    }

}

//background
void displayBackground(int x, int y){
    char bg[21][81] ={
        {" _______ _________ _        _______  _                                          "},
        {"(  ____ \\\\__   __/( (    /|(  ___  )( \\                                         "},
        {"| (    \\/   ) (   |  \\  ( || (   ) || (                                         "},
        {"| (__       | |   |   \\ | || (___) || |                                         "},
        {"|  __)      | |   | (\\ \\) ||  ___  || |                                         "},
        {"| (         | |   | | \\   || (   ) || |                                         "},
        {"| )      ___) (___| )  \\  || )   ( || (____/\\                                   "},
        {"|/       \\_______/|/    )_)|/     \\|(_______/                                   "},                                                            
        {" _______  _______  _______ _________ _______  _______ _________                 "},
        {"(  ____ )(  ____ )(  ___  )\\__    _/(  ____ \\(  ____ \\__   __/                  "},
        {"| (    )|| (    )|| (   ) |   )  (  | (    \\/| (    \\/   ) (                    "},
        {"| (____)|| (____)|| |   | |   |  |  | (__    | |         | |                    "},
        {"|  _____)|     __)| |   | |   |  |  |  __)   | |         | |                    "},
        {"| (      | (\\ (   | |   | |   |  |  | (      | |         | |                    "},
        {"| )      | ) \\ \\__| (___) ||\\_)  )  | (____/\\| (____/\\   | |                    "},
        {"|/       |/   \\__/(_______)(____/   (_______/(_______/   )_(                    "},
        {"                                                                                "},
        {"          .-. .-.  .--.  .----. .----..-.  .-.   .----.   .--..-.  .-.          "},
        {"          | {_} | / {} \\ | {}  }| {}  }\\ \\/ /    | {}  \\ / {} \\ \\/ /           "},
        {"          | { } |/  /\\  \\| .--' | .--'  }  {     |     //  /\\  \\}  {            "},
        {"          `-' `-'`-'  `-'`-'    `-'     `--'     `----' `-'  `-'`--'            "},
    };

    setColor(15, 0);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 11; j++){
            gotoxy((x) * 10 + j, (y) * 4 + i);
            cout << bg[(y-1)*4 + i][(x-1)*10 + j];
        }
    }
}

void displayStatus(bool win){
    if (win){
        char status[][50] = {
        {"\e[1m__   _____  _   _  __        _____ _   _ "},
        {"\e[1m\\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | |"},
        {"\e[1m \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| |"},
        {"\e[1m  | || |_| | |_| |   \\ V  V /  | || |\\  |"},
        {"\e[1m  |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_|"},
    };
    setColor(10,0);
    for (int i = 0; i < 5; i++){
        gotoxy(45,10+i);
        cout << status[i];
    }
    }else{
        char status[][52] = {
        {"\e[1m__   _____  _   _   _     ___  ____  _____ "},
        {"\e[1m\\ \\ / / _ \\| | | | | |   / _ \\/ ___|| ____|"},
        {"\e[1m \\ V / | | | | | | | |  | | | \\___ \\|  _|  "},
        {"\e[1m  | || |_| | |_| | | |__| |_| |___) | |___ "},
        {"\e[1m  |_| \\___/ \\___/  |_____\\___/|____/|_____|"},
        };
        setColor(12,0);
        for (int i = 0; i < 5; i++){
            gotoxy(42,10+i);
            cout << status[i];
        }
    }
    setColor(15,0);
}

void getPlayerInfo(Player& p) {
    gotoxy(50, 12);
    cout << "Enter player name: ";
    cin.getline(p.name,50);
    // cin.ignore();
    p.life = 3;
    p.point = 0;
    p.help = 3;
}