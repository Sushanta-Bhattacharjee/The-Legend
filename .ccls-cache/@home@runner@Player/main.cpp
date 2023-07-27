#include <iostream>
#include<ctime>
using namespace std;

void gameStory()
{
  system("clear");
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Return of the Legend."<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Four Years ago, he left mysteriously on the night of his father's death. As a result, he was despised by his family."<<endl;
    cout<<"Now, four years has passed, and he triumphantly returns to exact revenge as the greatest warrior."<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
}

class Player
{
    private:

    int health = 100;
    int minDamage = 30, maxDamage = 10;
    int minHeal = 8, maxHeal = 15;

    public:
    Player()
    {
      cout<<"-----------------------------------------------------------------------"<<endl;
      cout<<"Hi, I am Jonathan Goldstein."<<endl;
      cout<<"Four years ago, I was blamed for the death of my father. I ran away to save myself."<<endl;
      cout<<"Now, I am back to prove my innocence and find the real murderer."<<endl;
      cout<<"My revenge will come as it has for the countless enemies I have defeated in the past four years becoming the greatest warrior - the Legend."<<endl;
      cout<<"-----------------------------------------------------------------------"<<endl;
    }

    int getHealth()
{
  return health;
}

void takeDamage(int damage)
{
  if(health>0)
  {
    cout<<"Critical hit to Player."<<endl;
    cout<<"Enemy is dealing damage of "<<damage<<"to the player."<<endl;
    health =health-damage;
    cout<<"Player's current health is : "<<health<<endl;
    
  }
  else{
    cout<<"Player died."<<endl;
  }
}

int giveDamage()
{
  srand(time(0));
  int randomDamage = (rand()%(maxDamage-minDamage+1)+minDamage);
  return randomDamage;
}

void heal()
{
  srand(time(0));
  int randomHeal = (rand()%(maxHeal-minHeal+1)+minHeal);
  health = health+randomHeal;
  cout<<"Player healed by "<<health<<" HP."<<endl;
  cout<<"Player's health : "<<health<<endl;
}

};

int main() {
  gameStory();
  char userInput;
  do
    {
      cout<<"Press S  to start the game or any other key to exit."<<endl;
      cin>>userInput;
      if(userInput == 's' ||userInput == 's')
      {
        Player playerObj;
      }
      else
      {
        cout<<"Thaks for playing."<<endl;
      }
    }while(userInput == 's' ||userInput == 's');
  
}