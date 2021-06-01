
# Chess by Dummies 
  Authors: 
  [Gabrielle O'Brien](https://github.com/gobrien06),
  [Ryan Valdeavilla](https://github.com/ryeval),
  [Franco Miranda](https://github.com/fmira008)

## Project Description
  ### Importance
  Chess is a historically interesting game, and as authors we feel implementing a chess system will allow us to grow more comfortable playing the actual game. Additionally, chess allows for great technical challenges in terms of validating user inputs and finding unique ways to display the board. We feel these challenges will be fun to overcome over the course of this project.
 
  ### Technologies
  [C++ Programming Language](https://en.cppreference.com) - C++11
 
  [Valgrind](https://valgrind.org/) - Memory management framework for monitoring programs and executables

  [SFML](https://www.sfml-dev.org/) - Multi-language library for building interfactive interfaces

  [googletest](https://github.com/google/googletest) - Testing framework for C++11 codebases

  ### Input/Output
  #### Input
  Currently, there are two considered options for user input.  
  Option 1:
  Users control pieces with text commands in the [chess algebraic notation](https://en.wikipedia.org/wiki/Algebraic_notation_(chess)). Text commands include a request to end the game that both users must agree to, and the move command for moving pieces (ex: 'move a8 a4').
  
  Option 2:
  User clicks on a piece on the board, and has highlighted positions they can click into to move their piece for their turn. Input is done entirely through the user's clicked locations on the chess board.
  #### Output
  Chess board graphical representation in the terminal, which will update after every move with what positions are occupied by which pieces.
  ### Design Patterns
  #### Singleton Pattern
  The chess game will only utilize one instance of the "Board" class, otherwise we would have multiple games occuring at once. Since users are only playing one board at a time, by implementing the singleton pattern we can restrict our system to one object, the Board. The singleton pattern for the Board class allows for easy retrieval of the instance, which will be used frequently to update or see the chessboard by the pieces.
  #### Visitor Pattern
  The chess pieces are all able to move on the board, but they all follow unique movement patterns. The knight can jump, but other pieces can't. Some pieces move in special directions. To compensate for these differences, while still returning an array of possible movements for the user to pick, a visitor pattern is used. We use a special movement visitor to visit every piece and generate the correct movement. The reason we chose a visitor is because the action will always depend on the piece itself. The visitor pattern also allows for great flexibility in the future. For example, if we want to add unique capture functions for every piece, we just need to extend our visitor implementation.
## Class Diagram
#### Movement
  ![Movement Visitor Diagram](https://user-images.githubusercontent.com/43893085/120246520-4dd03000-c225-11eb-9766-49c31673b74b.png)  
  Note: Piece's implementation is detailed in another diagram.  
  
  Description: Visitor is the abstract interface for all visitors to build off of. MoveVisitor implements the pure virtual visitPiece functions from the interface, it is the ConcreteVisitor. In every Element, our pieces, we accept this visitor and call the respective visits. 
#### Piece
  ![LastOneIPromise](https://user-images.githubusercontent.com/38056263/117528385-c75a6280-af86-11eb-8771-210f561907c8.png)
  
  Description: Piece is a base class which will be used for the different peices. It has subclasses which hold references to different movement objects and sprites corresponding to the type of piece. These subclasses call one or many Movement objects which return valid moves for the piece.
#### Board
  ![Board Class Diagram](https://user-images.githubusercontent.com/38868891/117526920-fec41180-af7c-11eb-88da-5153bb9b86df.png)
  
Description: This is a Singleton class which will keep track of the board state, pieces, animations, and turns. The Board's instance is used througout the entirety of the application.



  > ## Phase III
  > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
  > * Before the meeting you should perform a sprint plan like you did in Phase II
  > * In the meeting with your TA you will discuss: 
  > - How effective your last sprint was (each member should talk about what they did)
  > - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
  > - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
  > - What tasks you are planning for this next sprint.

  > ## Final deliverable
  > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  > Before the demo, you should do the following:
  > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 #### Initialization
 ![Initial Board](https://user-images.githubusercontent.com/43893085/120296616-273de380-c27d-11eb-85ec-b3bfe1c11f59.png)
 #### Mid-Game
 ![Mid-Game](https://user-images.githubusercontent.com/43893085/120296899-708e3300-c27d-11eb-873e-797af0b4c802.png)
 #### During Movements
 ![Moving](https://user-images.githubusercontent.com/43893085/120297619-1fcb0a00-c27e-11eb-8133-5c471051a2bb.png)

 ## Installation/Usage
  #### Installation
  The following steps are the recommended way to run this program:
  ```
  git clone --recursive git@github.com:cs100/final-project-fmira008_gobrien002_rvald013.git Chess
  cd Chess
  cmake .
  make
  ./main
  ```
  Starting the program shows the user an initialized chess board.
  #### Usage
  ##### Starting a Game and Turns
  White pieces can be moved first on the board. Turns swap when the first player finishes their move. With another local player, alternate turns between white and black turns.
  ##### Moving a Piece
  Clicking on a piece will show red squares on the board. These squares are valid movements for that piece. To move a piece, click on that square. Your piece will then move to the square, and the turn changes. All pieces abide by standard chess rules.
  ##### Capturing
  Red movement squares show up for squares occupied by opposing pieces. To capture this piece, click on the red square with the opponent's piece.
  ##### Completing a Game
  The game is complete when the first King piece is in check. The King piece is in check when, after clicking on the piece, there are no more available movements. Movements for the King piece are only available if they won't put the King in check by another piece. When a player's King is in chess, you can either continue to play and allow their piece to capture the King, or close the main application and relaunch.
 ## Testing
  This project was tested with the googletest framework. Each feature had unique test cases written and passed on local compilation.
 
