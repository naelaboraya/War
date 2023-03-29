



#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"





TEST_CASE("Player test"){

  Player player1("player1");
  Player player2("player2");

  
  //check the stack sizes :
  CHECK(player1.cardesTaken() == 0);
  CHECK(player2.cardesTaken() == 0);

  //check the cards taken :
  CHECK(player1.stacksize() == 0);
  CHECK(player2.stacksize() == 0);
  

}

TEST_CASE("game test"){

  Player player1("player1");
  Player player2("player2");


  //start a game between player1 and player2
  Game game(player1,player2);

  //check cards taken to be zero :
  CHECK(player1.cardesTaken() == 0);
  CHECK(player2.cardesTaken() == 0);
  CHECK_FALSE(player1.cardesTaken() != player2.cardesTaken());
  
  //check players' stacks to be of size 26 : 
  CHECK(player1.stacksize() == 26);
  CHECK(player2.stacksize() == 26);
  CHECK_EQ(player1.stacksize(), player2.stacksize());
  
  //play first turn
  game.playTurn();
  //the following tests are for the first turn : 
  if (player1.stacksize() > player2.stacksize()){
    CHECK(player1.cardesTaken() > player2.cardesTaken());
  }

  if (player2.stacksize() > player1.stacksize()){
    CHECK(player2.cardesTaken() > player1.cardesTaken());
  }

  CHECK_FALSE(player1.stacksize() == player2.stacksize());
  CHECK_FALSE(player1.cardesTaken() == player2.cardesTaken());

  Player player3("player3");
  Player player4("player4");
  Game game2(player3,player4);
  game2.playAll();
  //should not throw an exception if tried to play the same game again 
  CHECK_NOTHROW(Game(player3,player4));


}


TEST_CASE("Exception tests"){
  Player player("player");
  CHECK_THROWS(Game(player , player));//not possible!
  
  Player player2("player2");

  Game game(player,player2);

  CHECK_THROWS(game.printLastTurn());//there are no turns yet!

  game.playTurn();

  CHECK_NOTHROW(game.printLastTurn());//should print last turn (already played!)

  Player player3("player3");
  Player player4("player4");

  Game game2(player3,player4);

  game2.playAll();//play all the turns

  //should throw an exception if tried to play a turn or all turns because the game is finished
  CHECK_THROWS(game2.playTurn());
  CHECK_THROWS(game2.playAll());


  CHECK((player3.stacksize() == 0 || player4.stacksize() == 0));//at the end one of the two players at least should have 0 cards
  CHECK((player3.stacksize() != 0 || player4.stacksize() != 0));
  CHECK((player3.cardesTaken()>player4.cardesTaken() || player4.cardesTaken()>player3.cardesTaken()));
  
  
  

}


