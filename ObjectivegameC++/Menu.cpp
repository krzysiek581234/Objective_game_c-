#include "Menu.h"
#include <windows.h>

using namespace std;

void Menu::initMenu()
{


        cout << "                                                   o                                  " << endl;
        cout << "        .-.                  .      .            .---.                                " << endl;
        cout << "       (   )                 |     _|_              /           o                     " << endl;
        cout << "        `-. .  ..--.--. .  . | .-.  |  .-. .--.    /  .  . .-.  .  .-.                " << endl;
        cout << "       (   )|  ||  |  | |  | |(   ) | (   )|      /   |  |(     | (   )               " << endl;
        cout << "        `-' `--|'  '  `-`--`-`-`-'`-`-'`-' '     '---'`--| `-'-' `-`-'`-              " << endl;
        cout << "               ;                                         ;                            " << endl;
        cout << "            `-'                                       `-'                             " << endl;
        cout << "       .   .                    .      .-.  .    .         .                    .     " << endl;
        cout << "       |  /                    _|_     |    |\\  /|         |      o             |     " << endl;
        cout << "       |-'  .--.---..  ..--.---.|  .-.-|-   | \\/ | .-.  .-.| .-.  . .-.---..-.  |.-.  " << endl;
        cout << "       |  \\ |    .' |  |`--. .' | (   )|    |    |(   )(   |(   ) |(    .'(   ) |-.'  " << endl;
        cout << "       '   `'   '---`--|`--''---`-'`-' '    '    ' `-'`-`-'`-`-'`-| `-''---`-'`-'  `- " << endl;
        cout << "                       ;                                          ;                   " << endl;
        cout << "                    `-'                                        `-'                    " << endl;
        cout << "                              .  .-.  .-.    , .---..  .                              " << endl;
        cout << "                            .'| (   )(   )  /      /|  |                              " << endl;
        cout << "                        .--.  |  >-<  >-<  /-.    / '--|-                             " << endl;
        cout << "                        `--.  | (   )(   )(   )  /     |                              " << endl;
        cout << "                        `--''---'`-'  `-'  `-'  '      '                              " << endl;
        cout << "                                                                                      " << endl;
        //cout << "   SWAM Krzysztof Madajczak s188674                                           " << endl;
        cout << "<Enter>: Zacznij juz teraz!" << endl;
        getchar();
        system("cls");
}
int Menu::getMenu(int &height,int &width)
{
    while (true)
    {
    cout << endl;
    cout << "        _________________________________ " << endl
        << "       |         <1> Symuluj             |" << endl
        << "       | ------------------------------- |" << endl
        << "       |         <2> Zaladuj             |" << endl
        << "       | ------------------------------- |" << endl
        << "       |         <3> N:" << height << "                |" << endl
        << "       | ------------------------------- |" << endl
        << "       |         <4> M:" << width << "                |" << endl
        << "       | ------------------------------- |" << endl
        << "       |         <5> Koniec              |" << endl
        << "       |_________________________________|" << endl;

        cout << " >> ";
        int wybor;
        cin >> wybor;
        switch (wybor)
        {
        default:
            break;
            return 0;
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            cout << "Change height" << endl;
            cout << " >> ";
            cin >> height;
            system("cls");
            break;
        case 4:
            cout << "Change Width" << endl;
            cout << " >> ";
            cin >> width;
            system("cls");
            break;
        case 5:
            system("cls");
            Krolik();
            Sleep(1000);
            return 0;
        }
    }
    
    return 0;
}
void Menu::Krolik()
{

cout<<"            ,`.                         "<<endl;
cout<<"          ,'` |        _.-.             "<<endl;
cout<<"         ,`   |      ,',' /             "<<endl;
cout<<"         :    |    ,','  ;              "<<endl;
cout<<"          \\   :   / /   /               "<<endl;
cout<<"           \\   `.' (  ,'                "<<endl;
cout<<"          ,''     _  `.                 "<<endl;
cout<<"        ,'      (o_)  `\\                "<<endl;
cout<<"     . (,.)   _.--     :                "<<endl;
cout<<"   -..`/(  .-'_..-    `|                "<<endl;
cout<<"    .-'\\,`. `-._       ;                "<<endl;
cout<<"        `._           /__               "<<endl;
cout<<"        ,':)-.._   _.(:::`.             "<<endl;
cout<<"        |'\\         / /`:::|            "<<endl;
cout<<"      ,' \\ :       : :   `:|            "<<endl;
cout<<"     /   : |       | |     \\            "<<endl;
cout<<"    :    | |       : :..---.:           "<<endl;
cout<<"    |    | ;       ,`._`-.|_ `.         "<<endl;
cout<<"    |    |'      ,'._  `. `. |_\\        "<<endl;
cout<<"    |    :      /`-. `.  `. `.  :       "<<endl;
cout<<"    :     \\    : __ `. `.  `. \\ ;       "<<endl;
cout<<"     \\     \\   |.  /  `. \\   \\ /        "<<endl;
cout<<"     |\\     `..: `. __  \\ \\   /         "<<endl;
cout<<"     ' `  .:::::\\  `. /  \\ \\,'          "<<endl;
cout<<"       .::::::::::-..'_..-'             "<<endl;
cout << "Dziekuje za piekne spedzone swieta <3" << endl;
}