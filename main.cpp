 // Perry Holloway
//Dr.T
// Fundamental Comp II
// October 23, 2019
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


  
  
  
  
  
  class Team 
{
  private:
  string name;
  string coachName;
  string homeCity;
  bool homeStatus;
  int score;
  int teamFouls;
  int timeoutCount;

  public:
  Team(){
    score = 0;
    teamFouls = 0;
    timeoutCount = 0;
  }
  void setName(string);
  void setCoachName(string);
  void setHomeCity(string);
  void setHomeStatus(bool);
  void setScore(int);
  void foulCount(int);
  void setTimeoutCount(int);

  string getName() const;
  string getCoachName() const;
  string getHomeCity() const;
  bool getHomeStatus() const;
  int getScore() const;
  int getFouls() const;
  int getTimeout() const;
};

class Scoreboard
{
  private:
  string home;
  string visitor;
  int homeScore;
  int visitorScore;
  int homeFouls;
  int visitorFouls;
  int homeTimeouts;
  int visitorTimeouts;
  Team team;

  public:
  void setTeamName(string n) { team.setName(n); } 
  void setCoachName(string n) { team.setCoachName(n); }
  void setHomeCity(string n) { team.setHomeCity(n); }
  void setHomeStatus(bool b) { team.setHomeStatus(b); }
  void setScore(int s) { team.setScore(s); }
  void setFouls(int f) { team.foulCount(f); }
  void setTimeoutCount(int t) { team.setTimeoutCount(t); }
 
  string getTeamName() const { return team.getName(); }
  string getCoachName() const { return team.getCoachName(); }
  string getHomeCity() const { return team.getHomeCity(); }
  bool getHomeStatus() const { return team.getHomeStatus(); }
  int getScore() const { return team.getScore(); }
  int getFouls() const { return team.getFouls(); }
  int getTimeoutCount() const { return team.getTimeout(); }

  void showScoreBoard(Team t1,Team t2)
  {
  

    int homeScore = t1.getScore();
    int visitorScore = t2.getScore();
    string red = "\x1b[91;1m";
    string blue = "\x1b[36;1m";
    string underline = "\x1b[4;1m";
    string reset = "\x1b[0m";

    cout << " " << underline <<  "                                          " << reset << " " << endl;
    cout << "                                          " << endl;
    cout << "         " << blue << "HOME" << reset << "              " << red << "VISITOR" << reset <<"        " << endl;
    cout << "        " << underline << t1.getName() << reset << "             " << underline << t2.getName() << reset << "        " << endl;
  
    cout << "        " << underline << " " << setw(2) << setfill ('0') << t1.getScore() << " " << reset << "               " << underline <<" " << setw(2) << setfill ('0') << t2.getScore() << " " << reset << "        " <<endl;
    cout << "                                          " << endl;
    cout << "         " << underline << "Fouls" << reset << "              " << underline << "Fouls" << reset << "         " << endl;
  
    cout << "        " << underline << " " << setw(2) << setfill ('0') << t1.getFouls() << " " << reset << "               " << underline <<" " << setw(2) << setfill ('0') << t2.getFouls() << " " << reset << "        " <<endl;
    cout << "                                          " << endl;
    cout << " " << underline <<  "                                          " << reset << " " << endl;
    cout << "                                          " << endl;
    cout << "Coach:\t\t" << t1.getCoachName() << "\t" << t2.getCoachName() << endl;
    cout << "City:\t\t" << t1.getHomeCity() << "\t\t\t" << t2.getHomeCity() << endl;
    cout << "Timeouts:\t" << t1.getTimeout() << "\t\t\t\t" << t2.getTimeout() << endl;
   
  }
};

void showMenu()
{
  cout << "\nWhat would you like to do" << endl
  << "1: Update the score" << endl
  << "2: Update foul count" << endl
  << "3. Update Team Cities" << endl
  << "4. Update Team Names" << endl
  << "5. Update Team Timeout Counts" << endl
  << "6. Update Coaches names" << endl
  << "E: Exit program" << endl;

  cout << "Please make a choice: ";
  
}

void handleOption(string i, Team &t1, Team &t2){
  string choice, s;
  int n;
  if (i == "1"){
    cout << "\nWhich team would you like to update the score for" << endl;
    cout << "A. " << t1.getName() << endl;
    cout << "B. " << t2.getName() << endl;
    cout << "Please make a choice: ";
    cin >> choice;
     { if (choice == "A" || choice == "a"){
        cout << "New score: ";
        cin >> n;
        t1.setScore(n);
      }
      else if (choice == "B" || choice == "b"){
        cout << "New score: ";
        cin >> n;
        t2.setScore(n);
      }
     }
  
  }
  else if (i == "2"){
    cout << "\nWhich team would you like to update the fouls for" << endl
    << "A. " << t1.getName() << endl
    << "B. " << t2.getName() << endl
    << "Please make a choice: "; 
    cin >> choice;
     { if (choice == "A" || choice == "a"){
        cout << "New fouls: ";
        cin >> n;
        t1.foulCount(n);
      }
      else if (choice == "B" || choice == "b"){
        cout << "New fouls: ";
        cin >> n;
        t2.foulCount(n);
      }
     } 
  }
  else if (i == "3"){
    cout << "\nWHich team would you like to update their city?" << endl
    << "A. " << t1.getName() << endl
    << "B. " << t2.getName() << endl
    << "Please make a choice: ";
    cin >> choice;

     { if (choice == "A" || choice == "a"){
        cout << "New city for " << t1.getName() << " is ";
        cin >> s;
        t1.setHomeCity(s);
      }
      else if (choice == "B" || choice == "b"){
        cout << "New city for " << t2.getName() << " is ";
        cin >> s;
        t2.setHomeCity(s);
      } 
     }
  }
  else if (i == "4") {
    cout << "Which team would you like to update their name:" << endl
      << "A. " << t1.getName() << endl
      << "B. " << t2.getName() << endl
      << "Please make a choice: ";
      cin >> choice;
      { if (choice == "A" || choice == "a"){
          cout << "New name: ";
          cin >> s;
          t1.setName(s);
        }
        else if (choice == "B" || choice == "b"){
          cout << "New name: ";
          cin >> s;
          t2.setName(s);
        }

  }
}
else if (i == "5") {
    cout << "Which team would you like to update the timeout count:" << endl
      << "A. " << t1.getName() << endl
      << "B. " << t2.getName() << endl
      << "Please make a choice: ";
      cin >> choice;
      { if (choice == "A" || choice == "a"){
          cout << "New timeout count: ";
          cin >> n;
          t1.setTimeoutCount(n);
        }
        else if (choice == "B" || choice == "b"){
          cout << "New timeout count: ";
          cin >> n;
          t2.setTimeoutCount(n);
        }

  }
}
else if (i == "6"){
    cout << "\nWhich team's coaches name would you like to update?" << endl
    << "A. " << t1.getName() << endl
    << "B. " << t2.getName() << endl
    << "Please make a choice: ";
    cin >> choice;

     { if (choice == "A" || choice == "a"){
        cout << t1.getName() << " New coach is ";
        cin >> s;
        t1.setCoachName(s);
      }
      else if (choice == "B" || choice == "b"){
        cout << t2.getName() << " New coach is ";
        cin >> s;
        t2.setCoachName(s);
      } 
     }
  }



}

int main(){


  Team t1;
  Team t2;
  Scoreboard game;
  string option;
  t1.setName("Cowboys");
  t1.setHomeCity("Dallas");
  t1.setHomeStatus(true);
  t1.setCoachName("Jason Garret");


  t2.setName("Steelers");
  t2.setHomeCity("Pittsburgh");
  t2.setHomeStatus(false);
  t2.setCoachName("Mike Tomlin");

  t1.setScore(00);
  game.showScoreBoard(t1, t2);
  cout << "\091[2J\091[1;1H";
  do {
  game.showScoreBoard(t1, t2);
  showMenu();
  cin >> option;
  handleOption(option,t1,t2);
  cout << "\091[2J\091[1;1H";
  } while (option != "E" || option != "e");
  cout << "\nPeace Out" << endl;


  return 0;
}



void Team::setName(string n)
{
  name = n; 
}
void Team::setCoachName(string n)
{
  coachName = n;
}
void Team::setHomeCity(string city)
{
  homeCity = city;
}

void Team::setHomeStatus(bool status)
{
  homeStatus = status;
}

void Team::setScore(int i)
{
  score = i;
}

void Team::foulCount(int f)
{
  teamFouls = f;
}

void Team::setTimeoutCount(int t)
{
  timeoutCount = t;
}

string Team::getName() const
{
  return name;
}

string Team::getCoachName() const
{
  return coachName;
}

string Team::getHomeCity() const
{
  return homeCity;
}

bool Team::getHomeStatus() const
{
  return homeStatus;
}

int Team::getScore() const
{
  return score;
}

int Team::getFouls() const
{
  return teamFouls;
}

int Team::getTimeout() const
{
  return timeoutCount;
}



