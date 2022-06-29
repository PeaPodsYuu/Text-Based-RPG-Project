#include <iostream>
#include <Windows.h>
#include <fstream>
#include "MapGen.h"
#include "Player.h"

using namespace std;

void buildScreen()
{
//Credit: pitrex29 https://stackoverflow.com/questions/4053554/running-a-c-console-program-in-full-screen
    // Fullscreen
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

//Credit: karlphilip https://stackoverflow.com/questions/3471520/how-to-remove-scrollbars-in-console-windows-c
    // get handle to the console window
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // retrieve screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

    // current window size
    short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
    short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

    // current screen buffer size
    short scrBufferWidth = scrBufferInfo.dwSize.X;
    short scrBufferHeight = scrBufferInfo.dwSize.Y;

    // to remove the scrollbar, make sure the window height matches the screen buffer height
    COORD newSize;
    newSize.X = scrBufferWidth;
    newSize.Y = winHeight;

    // set the new screen buffer dimensions
    int Status = SetConsoleScreenBufferSize(hOut, newSize);
    if (Status == 0)
    {
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << GetLastError() << endl;
        exit(Status);
    }
}

int showMap(int onlvl, Player player)
{
    int check = 0;
    
    MapGen lvl1(1);
    MapGen lvl2(2);
    MapGen lvl3(3);
    MapGen lvl4(4);
    MapGen lvl5(5);

    ifstream f;

    f.open("Data/Story/Level1.txt");
    std::string text;
    while (getline(f, text))
        cout << text << endl;
    cout << endl;

    while (true)
    {
        
        check = lvl1.moveMap();
        if (check == 2)
            return 1;
        system("CLS");
        if (check == 1)
            break;
        
    }
    f.close();

    f.open("Data/Story/Level2.txt");
    while (getline(f, text))
        cout << text << endl;
    cout << endl;

    while (true)
    {
        check = lvl2.moveMap();
        if (check == 2)
            return 1;
        system("CLS");
        if (check == 1)
            break;
        system("CLS");
    }
    f.close();

    f.open("Data/Story/Level3.txt");
    while (getline(f, text))
        cout << text << endl;
    cout << endl;
    
    while (true)
    {
        
        check = lvl3.moveMap();
        if (check == 2)
            return 1;
        system("CLS");
        if (check == 1)
            break;
        system("CLS");
    }
    f.close();

    f.open("Data/Story/Level4.txt");
    while (getline(f, text))
        cout << text << endl;
    cout << endl;

    while (true)
    {
        
        check = lvl4.moveMap();
        if (check == 2)
            return 1;
        system("CLS");
        if (check == 1)
            break;
        system("CLS");
    }
    f.close();

    f.open("Data/Story/Level5.txt");
    while (getline(f, text))
        cout << text << endl;
    cout << endl;

    while (true)
    {
        
        check = lvl5.moveMap();
        if (check == 2)
            return 1;
        system("CLS");
        if (check == 1)
            break;
        system("CLS");
    }
    f.close();

    f.open("Data/Story/Ending.txt");
    while (getline(f, text))
        cout << text << endl;
    cout << endl;

    f.close();

    return 0;
}

int main()
{

    Player a;
    buildScreen();
    
    while (true)
    {
        system("CLS");
        cout << "Would you like to create a new game or save? Warning: creating a new game erases your previous save.\nInput (new / load / exit): ";

        string input;
        cin >> input;

        if (input == "new")
        {
            a.newsave();
            break;
        }
        if (input == "load")
        {
            a.newload();
            break;
        }
        if (input == "exit")
        {
            auto wnd = GetConsoleWindow();
            PostMessage(wnd, WM_CLOSE, 0, 0);
        }
    }

    int playing = 1;
    while (playing == 1)
    {
        system("CLS");
        int onlvl = 1;
        showMap(onlvl, a);
    }

    Sleep(500);
    cout << "Thank you for playing our short demo version of a game we wish to turn into a real project in the future!\n\n";
    Sleep(2000);
    cout << "Created by:\nCecan Bogdan\nVulpe Maria\n";
    Sleep(30000);
    auto wnd = GetConsoleWindow();
    PostMessage(wnd, WM_CLOSE, 0, 0);
}