#include <iostream>
#include<ctime>
using namespace std;

class Player
{
    private:

    int health = 100;
    int minDamage = 10, maxDamage = 30;
    int minHeal = 8, maxHeal = 15;

    public:
    Player()
    {
      system("clear");
      
      cout<<"Hi, I am Jonathan Goldstein."<<endl;
      cout<<"\nFour years ago, I was blamed for the death of my father. I ran away to save myself.\n"<<endl;
      cout<<"Now, I am back to prove my innocence and find the real murderer.\n"<<endl;
      cout<<"My revenge will come as it has for the countless enemies I have defeated in the past four years becoming the greatest warrior - the Legend."<<endl;
      cout<<"\n-----------------------------------------------------------------------"<<endl;
    }

    int getHealth()
    {
      return health;
    }

    void takeDamage(int damage)
    {
      cout<<"\nCritical hit to Player."<<endl;
      //acout<<"\nEnemy is dealing damage of "<<damage<<" to the player."<<endl;
      health =health-damage;
      if(health<00)
      {
        cout<<"\nPlayer died.You Lost."<<endl;
        cout<<"\n-----------------------------------------------------------------------"<<endl;
      }
      else{
        cout<<"\nPlayer's current health after receiving damage : "<<health<<endl;
        cout<<"\n-----------------------------------------------------------------------"<<endl;
      }
    }

    int giveDamage()
    {
      srand(time(0));
      int randomDamage = (rand()%(maxDamage-minDamage+1)+minDamage);
      cout<<"\nPlayer damage of "<<randomDamage<<" dealth to the Enemy."<<endl;
      return randomDamage;
    }

    void heal()
    {
      srand(time(0));
      int randomHeal = (rand()%(maxHeal-minHeal+1)+minHeal);
      health = health+randomHeal;
      cout<<"\nPlayer healed by "<<randomHeal<<" HP."<<endl;
      cout<<"\nPlayer's current health : "<<health<<endl;
    }

};

class Enemy
{
  private:

    int health = 100;
    int minDamage = 10, maxDamage = 20;

  public:

  Enemy()
  {
    system("clear");
    cout<<"\nI am the Legend Killer."<<endl;
    cout<<"\nI have become the ruler after taking the life of my competition."<<endl;
    cout<<"\nNo one can defeat me."<<endl;
    cout<<"\n-----------------------------------------------------------------------"<<endl;
  }

  int getHealth()
  {
    return health;
  }

  void takeDamage(int damage)
  {
    cout<<"\nCritical hit to Enemy."<<endl;
    //cout<<"\nPlayer is dealing damage of "<<damage<<" to the Enemy."<<endl;
    health =health-damage;
    if(health<0)
    {
      cout<<"\nEnemy died. You Won."<<endl;
      cout<<"\n-----------------------------------------------------------------------"<<endl;
    }
    else{
      cout<<"\nEnemy's current health after receiving damage : "<<health<<endl;
      cout<<"\n-----------------------------------------------------------------------"<<endl;
    }
  }

  int giveDamage()
  {
    srand(time(0));
    int randomDamage = (rand()%(maxDamage-minDamage+1)+minDamage);
    cout<<"\nEnemy damage of "<<randomDamage<<" dealth to the Player."<<endl;
    return randomDamage;
  }

};

void gameLoop(Player player, Enemy enemy)
{
  char playerChoice;
  do
    {
      cout<<"\n\nPress A to attack and H to heal.\n"<<endl;
      cin>>playerChoice;
      if(playerChoice == 'A' || playerChoice =='a')
      {
        system("clear");
        //Attack
        enemy.takeDamage(player.giveDamage());
        if(enemy.getHealth()>0)
        {
          cout<<"\n\nIt's the Legend Killer's turn now.\n"<<endl;
          player.takeDamage(enemy.giveDamage());
        }
  
      }
      else if(playerChoice == 'H' || playerChoice =='h')
      {
        system("clear");
        //Heal
        player.heal();
        if(enemy.getHealth()>0)
        {
          cout<<"\n\nIt's the Legend Killer's turn now.\n"<<endl;
          player.takeDamage(enemy.giveDamage());
        }
      }
      else
      {
        system("clear");
        cout<<"\nInvalid Input.\n"<<endl;
      }
    }while(player.getHealth()>0 && enemy.getHealth()>0);
}

void gameStory()
{
  system("clear");
  cout<<"-----------------------------------------------------------------------"<<endl;
  cout<<"Return of the Legend."<<endl;
  cout<<"-----------------------------------------------------------------------"<<endl;
  cout<<"Four Years ago, he left mysteriously on the night of his father's death. As a result, he was despised by his family.\n"<<endl;
  cout<<"Now, four years has passed, and he triumphantly returns to exact revenge as the greatest warrior."<<endl;
  cout<<"-----------------------------------------------------------------------"<<endl;
}

int main() {
  gameStory();
  char userInput;
  do
    {
      cout<<"\n\nPress S  to start the game or any other key to exit."<<endl;
      cin>>userInput;
      if(userInput == 'S' ||userInput == 's')
      {
        Player playerObj;
        //Testing Functions
        //cout<<"\nPlayer Health : "<<playerObj.getHealth()<<endl;
        //playerObj.takeDamage(50);
        //playerObj.giveDamage();
        //playerObj.heal();
        
        Enemy enemyObj;
        //Testing Functions
        //cout<<"\nEnemy Health : "<<enemyObj.getHealth()<<endl;
        //enemyObj.giveDamage();

        gameLoop(playerObj, enemyObj);
      }
      else
      {
        system("clear");
        cout<<"\nThanks for playing."<<endl;
      }
    }while(userInput == 'S' ||userInput == 's');
  
}