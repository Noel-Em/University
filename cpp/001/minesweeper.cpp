//This code is for testing purposes and I'm making it to improve my C++ skills and to verify them

#include <iostream>
#include <random>
using namespace std;

struct Map
{
    char **mapCharacters;
    int width;
    int height;

    Map(int width = 1, int height = 1) : width(width), height(height)
    {
        mapCharacters = new char*[width];

        for(int i = 0; i < width; i++)
        {
            mapCharacters[i] = new char[height];
        }

        Reset();
    }

    void Reset()
    {
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                mapCharacters[i][j] = '*';
            }
        }
    }

    void setBombs()
    {

    }

    void View()
    {
        char checkInput;
        cout << "Map: \n";
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                cout << mapCharacters[i][j] << " ";
            }
            cout << endl;
        }
        system("PAUSE");
    }

    ~Map()
    {
        for(int i = 0; i < width; i++)
        {
            delete[] mapCharacters[i];
        }

        delete[] mapCharacters;
    }
};

bool Game(int difficulty)
{
    int widthAheight = difficulty == 1 ? 20 : (difficulty == 2 ? 15 : 10);
    Map map(widthAheight , widthAheight);

    char choice = '-';

    while(true)
    {
        cout << "Select action: " << endl << "1) View Map \n2) Set Piece\nSelect: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case '1':
            map.View();
            choice = 0;
            break;
        case '2':
            break;
        default:
            break;
        }
        system("CLS");
    }

    return false;

}

int main()
{
    int gamePos = 0;
    char select = '-';
    bool result = false;

    while(true)
    {
        switch (gamePos)
        {
            case 1:
            case 2:
            case 3:
                result = Game(gamePos);
                if(result)
                    cout << "CONGRATS! YOU WON!";
                else
                    cout << "Oh... it seems you didn't make it...";
                
                gamePos = 0;
                break;
            default:
                cout << "Welcome player! " << endl << "Select the game difficulty:" << endl;
                cout << "1) Easy" << endl;
                cout << "2) Medium" << endl;
                cout << "3) Hard" << endl << "Select: ";
                cin >> select;
                
                if(select == '1')
                    gamePos = 1;
                else if (select == '2')
                    gamePos = 2;
                else if(select == '3')
                    gamePos = 3;

                break;
        }
        system("CLS");
    }

    return 0;
}