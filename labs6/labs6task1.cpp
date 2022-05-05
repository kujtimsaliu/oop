#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

class NBAPlayer
{
protected:
    char *name;
    char team[40];
    double points;
    double assists;
    double rebounds;
    void copy(const NBAPlayer &p)
    {
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        strcpy(this->team, p.team);
        this->points = p.points;
        this->assists = p.assists;
        this->rebounds = p.rebounds;
    }

public:
    NBAPlayer()
    {
        name = new char[0];
        strcpy(team, "");
        points = 0;
        assists = 0;
        rebounds = 0;
    }
    NBAPlayer(char *name, char *team, double points, double assists, double rebounds)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        strcpy(this->team, team);
        this->points = points;
        this->assists = assists;
        this->rebounds = rebounds;
    }
    NBAPlayer(const NBAPlayer &other) { copy(other); }
    NBAPlayer &operator=(const NBAPlayer &n)
    {
        if (this != &n)
        {
            delete[] name;
            copy(n);
        }
        return *this;
    }
    ~NBAPlayer() { delete[] name; }
    double rating() { return ((points * 0.45) + (assists * 0.30) + (rebounds * 0.25)); }
    void print()
    {
        cout << name << " - " << team << endl;
        cout << "Points: " << points << endl;
        cout << "Assists: " << assists << endl;
        cout << "Rebounds: " << rebounds << endl;
        cout << "Rating: " << rating() << endl;
    }
};

class AllStarPlayer : public NBAPlayer
{
private:
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;
    void copy(const AllStarPlayer &other)
    {
        this->allStarAssists = other.allStarAssists;
        this->allStarPoints = other.allStarPoints;
        this->allStarRebounds = other.allStarRebounds;
    }

public:
    AllStarPlayer() : NBAPlayer()
    {
        double allStarPoints = 0.0;
        double allStarAssists = 0.0;
        double allStarRebounds = 0.0;
    }
    AllStarPlayer(const NBAPlayer &p, double allStarPoints,
                  double allStarAssists,
                  double allStarRebounds) : NBAPlayer(p)
    {
        this->allStarAssists = allStarAssists;
        this->allStarPoints = allStarPoints;
        this->allStarRebounds = allStarRebounds;
    }
    AllStarPlayer(char *name, char *team, double points, double assists, double rebounds,
                  double allStarPoints, double allStarAssists, double allStarRebounds)
        : NBAPlayer(name, team, points, assists, rebounds)
    {
        this->allStarAssists = allStarAssists;
        this->allStarPoints = allStarPoints;
        this->allStarRebounds = allStarRebounds;
    }
    AllStarPlayer(const AllStarPlayer &a) : NBAPlayer(a) { copy(a); }
    AllStarPlayer &operator=(const AllStarPlayer &asp)
    {
        if (this != &asp)
        {
            delete[] name;
            NBAPlayer::copy(asp);
            copy(asp);
        }
        return *this;
    }
    ~AllStarPlayer(){};
    double allStarRating()
    {
        return ((allStarPoints * 0.30) + (allStarAssists * 0.40) + (allStarRebounds * 0.30));
    }
    double rating()
    {
        return ((NBAPlayer::rating() + allStarRating()) / 2);
    }
    void print()
    {
        NBAPlayer::print();
        cout << "All Star Rating: " << allStarRating();
        cout << endl;
        cout << "New Rating: " << rating() << endl;
    }
};

int main()
{

    char name[50];
    char team[40];
    double points;
    double assists;
    double rebounds;
    double allStarPoints;
    double allStarAssists;
    double allStarRebounds;

    NBAPlayer *players = new NBAPlayer[5];
    AllStarPlayer *asPlayers = new AllStarPlayer[5];
    int n;
    cin >> n;

    if (n == 1)
    {

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cin >> name >> team >> points >> assists >> rebounds; // nice
            players[i] = NBAPlayer(name, team, points, assists, rebounds);
            players[i].print();
        }
    }
    else if (n == 2)
    {

        for (int i = 0; i < 5; ++i)
        {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBAPlayer(name, team, points, assists, rebounds);
            asPlayers[i] = AllStarPlayer(players[i], allStarPoints, allStarAssists, allStarRebounds);
        }

        cout << "NBA PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            players[i].print();

        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();
    }
    else if (n == 3)
    {

        for (int i = 0; i < 5; ++i)
        {
            cin >> name >> team >> points >> assists >> rebounds;
            cin >> allStarPoints >> allStarAssists >> allStarRebounds;
            asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                         allStarPoints, allStarAssists, allStarRebounds);
        }
        cout << "ALL STAR PLAYERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i)
            asPlayers[i].print();
    }

    delete[] players;
    delete[] asPlayers;
}
