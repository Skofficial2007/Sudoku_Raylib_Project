#include "raylib.h"
#include <iostream>
#include <time.h>

class generatePuzzle
{
private:
    int copyBoard[9][9];

public:
    // Define the initial Sudoku board
    int initialBoard[9][9] = {};         // Stores the initial Sudoku board
    int solvedBoard[9][9] = {};          // Stores the solved Sudoku board
    bool nonChangebleNumbers[9][9] = {}; // Indicates whether a number is changeable or not
    int id = 0;                          // To check if the new board in not same as previous board

    void DefaultBoards()
    {
        int board1[9][9] = {{4, 3, 5, 2, 6, 9, 7, 8, 1},
                            {6, 8, 2, 5, 7, 1, 4, 9, 3},
                            {1, 9, 7, 8, 3, 4, 5, 6, 2},
                            {8, 2, 6, 1, 9, 5, 3, 4, 7},
                            {3, 7, 4, 6, 8, 2, 9, 1, 5},
                            {9, 5, 1, 7, 4, 3, 6, 2, 8},
                            {5, 1, 9, 3, 2, 6, 8, 7, 4},
                            {2, 4, 8, 9, 5, 7, 1, 3, 6},
                            {7, 6, 3, 4, 1, 8, 2, 5, 9}};

        int board2[9][9] = {{9, 2, 5, 6, 3, 1, 8, 4, 7},
                            {6, 1, 8, 5, 7, 4, 2, 9, 3},
                            {3, 7, 4, 9, 8, 2, 5, 6, 1},
                            {7, 4, 9, 8, 2, 6, 1, 3, 5},
                            {8, 5, 2, 4, 1, 3, 9, 7, 6},
                            {1, 6, 3, 7, 9, 5, 4, 8, 2},
                            {2, 8, 7, 3, 5, 9, 6, 1, 4},
                            {4, 9, 1, 2, 6, 7, 3, 5, 8},
                            {5, 3, 6, 1, 4, 8, 7, 2, 9}};

        int board3[9][9] = {{1, 6, 8, 4, 5, 7, 9, 3, 2},
                            {5, 7, 2, 3, 9, 1, 4, 6, 8},
                            {9, 3, 4, 6, 2, 8, 5, 1, 7},
                            {8, 2, 9, 7, 4, 3, 1, 5, 6},
                            {6, 5, 1, 2, 8, 9, 3, 7, 4},
                            {7, 4, 3, 5, 1, 6, 2, 8, 9},
                            {3, 9, 5, 8, 7, 2, 6, 4, 1},
                            {4, 1, 7, 9, 6, 5, 8, 2, 3},
                            {2, 8, 6, 1, 3, 4, 7, 9, 5}};

        int board4[9][9] = {{8, 7, 4, 9, 5, 6, 3, 1, 2},
                            {3, 6, 5, 1, 8, 2, 9, 4, 7},
                            {1, 2, 9, 7, 4, 3, 6, 8, 5},
                            {6, 1, 7, 4, 2, 5, 8, 9, 3},
                            {5, 9, 3, 8, 6, 1, 2, 7, 4},
                            {2, 4, 8, 3, 7, 9, 5, 6, 1},
                            {9, 5, 2, 6, 1, 4, 7, 3, 8},
                            {7, 3, 1, 2, 9, 8, 4, 5, 6},
                            {4, 8, 6, 5, 3, 7, 1, 2, 9}};

        int r;
        srand(time(NULL));
        do
        {
            r = rand() % 4;
        } while (r < 1);

        switch (r)
        {
        case 1:
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    copyBoard[i][j] = board1[i][j];
                    solvedBoard[i][j] = board1[i][j];
                }
            }
            id = 1;
            break;
        }
        case 2:
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    copyBoard[i][j] = board2[i][j];
                    solvedBoard[i][j] = board2[i][j];
                }
            }
            id = 2;
            break;
        }
        case 3:
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    copyBoard[i][j] = board3[i][j];
                    solvedBoard[i][j] = board3[i][j];
                }
            }
            id = 3;
            break;
        }
        case 4:
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    copyBoard[i][j] = board4[i][j];
                    solvedBoard[i][j] = board4[i][j];
                }
            }
            id = 4;
            break;
        }
        default:
        {
            do
            {
                r = rand() % 4;
            } while (r < 1);
        }
        }
    }

    void RemoveElements()
    {
        // Randomly remove numbers from the generated puzzle
        srand(time(NULL)); // Initialize random seed
        int removals = 1;  // Number of numbers to remove

        while (removals > 0)
        {
            int i = rand() % 9;
            int j = rand() % 9;

            if (copyBoard[i][j] != 0)
            {
                copyBoard[i][j] = 0;
                removals--;
            }
        }
    }

    // To reset the boards
    void resetPuzzle()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                copyBoard[i][j] = 0;
                nonChangebleNumbers[i][j] = 0;
                solvedBoard[i][j] = 0;
                initialBoard[i][j] = 0;
            }
        }
    }

    // Method to generate a new Sudoku puzzle
    virtual void GenerateNewPuzzle()
    {
        DefaultBoards();
        RemoveElements();

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                initialBoard[i][j] = copyBoard[i][j];
            }
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (copyBoard[i][j])
                {
                    nonChangebleNumbers[i][j] = true;
                }
                else
                {
                    nonChangebleNumbers[i][j] = false;
                }
            }
        }
    }

    generatePuzzle()
    {
        GenerateNewPuzzle();
    }
};

class SudokuGame : virtual public generatePuzzle
{
public:
    int board[9][9]; // Represents the Sudoku board

private:
    Rectangle cells[9][9];              // Stores the positions and dimensions of each cell
    float windowWidth;                  // Width of the game window
    float windowHeight;                 // Height of the game window
    int offsetX;                        // The offset in x-axis
    int offsetY;                        // The offset in y-axis
    int selectedCellRow = -1;           // Member variables to track the selected cell row
    int selectedCellCol = -1;           // Member variables to track the selected cell column
    bool isRedRectangleVisible = false; // Flag to track if the red rectangle should be visible
    bool isWrongNumber = false;         // To check if there is a wrong input
    float wrongNumberTimer = 0.0f;      // To set the number of sec wrong input text to show

    // Reset Button
    Texture2D resetButton;       // To load reset button texture image
    Rectangle resetButtonRect;   // To create a rectangle on which reset button be set
    float buttonWidth = 100.0f;  // Width of reset button
    float buttonHeight = 100.0f; // Height of reset button
    float buttonX = 10;          // X coordinates of the rectangle for reset button
    float buttonY = 10;          // Y coordinates of the rectangle for reset button

    // Turn Off Button
    Texture2D turnOffButton;                            // To load turn off button texture image
    Rectangle turnOffButtonRect;                        // To create a rectangle for the turn off button
    float TFbuttonWidth = 60.0f;                        // Width of Turn Off button
    float TFbuttonHeight = 60.0f;                       // Height of Turn Off button
    float TFbuttonX = windowWidth - TFbuttonWidth - 30; // X coordinates of the rectangle for Turn Off button
    float TFbuttonY = 30;                               // Y coordinates of the rectangle for Turn Off button

    // Next Button
    Texture2D nextButton;        // To load next button texture image
    Rectangle nextButtonRect;    // To create a rectangle for the next button
    float NbuttonWidth = 250.0f; // Width of Turn Off button
    float NbuttonHeight = 100.0f; // Height of Turn Off button
    float NbuttonX = windowWidth / 2 + 15;
    float NbuttonY = windowHeight / 2 + 100;

    // You Win Image and Buttons
    Texture2D youWinImage; // To load You win image texture file
    Rectangle youWinRec;
    Vector2 youWinSize{600.0f, 400.0f};
    Vector2 youWinPos{windowWidth / 2 - youWinSize.x / 2, windowHeight / 2 - 300};

    Texture2D blurEffect;
    Rectangle blurRec;
    Vector2 blurSize{youWinSize.x * 2, youWinSize.y * 2};
    Vector2 blurPos{windowWidth / 2 - blurSize.x / 2, windowHeight / 2 - blurSize.y / 2};

    Texture2D RestartButton;
    Rectangle RestartRec;
    Vector2 restartSize{250.0f, 105.0f};
    Vector2 restartPos{windowWidth / 2 - restartSize.x - 15.0f, windowHeight / 2 + 97};

    // A score variable to keep track of the player's score
    int score = 0;

    // Array of numeric keys for number input
    int numericKeys[18] = {
        KEY_ONE, KEY_TWO, KEY_THREE, KEY_FOUR, KEY_FIVE, KEY_SIX, KEY_SEVEN, KEY_EIGHT, KEY_NINE,
        KEY_KP_1, KEY_KP_2, KEY_KP_3, KEY_KP_4, KEY_KP_5, KEY_KP_6, KEY_KP_7, KEY_KP_8, KEY_KP_9};

public:
    SudokuGame(int width, int height, int initialBoard[9][9], int offsetX, int offsetY)
        : windowWidth(width), windowHeight(height), offsetX(offsetX), offsetY(offsetY)
    {
        setBoard();

        resetButton = LoadTexture("textures/Reset_Button.png");
        resetButtonRect = {buttonX, buttonY, buttonWidth, buttonHeight};

        turnOffButton = LoadTexture("textures/Power_Button_Off_Button.png");
        turnOffButtonRect = {TFbuttonX, TFbuttonY, TFbuttonWidth, TFbuttonHeight};

        nextButton = LoadTexture("textures/Continue_Button.png");
        nextButtonRect = {NbuttonX, NbuttonY, NbuttonWidth, NbuttonHeight};

        youWinImage = LoadTexture("textures/You_Win_Text.png");
        youWinRec = {youWinPos.x, youWinPos.y, youWinSize.x, youWinSize.y};

        blurEffect = LoadTexture("textures/effect.png");
        blurRec = {blurPos.x, blurPos.y, blurSize.x, blurSize.y};

        RestartButton = LoadTexture("textures/Restart_Button.png");
        RestartRec = {restartPos.x, restartPos.y, restartSize.x, restartSize.y};
    }

    ~SudokuGame()
    {
        UnloadTexture(resetButton);
        UnloadTexture(turnOffButton);
        UnloadTexture(nextButton);
        UnloadTexture(youWinImage);
        UnloadTexture(blurEffect);
        UnloadTexture(RestartButton);
    }

    void setBoard()
    {
        // Initialize cells and board with given dimensions and initial board values
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Set up cells for drawing
                cells[i][j] = {(float)j * (2.0f * windowWidth / 27), (float)i * (2.0f * windowHeight / 27), 2.0f * windowWidth / 27, 2.0f * windowHeight / 27};

                // Set up initial Sudoku board
                board[i][j] = initialBoard[i][j];
            }
        }
    }

    // Method to restart the game with a new puzzle
    void RestartGame()
    {
        // Clear the board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = 0;
                resetPuzzle();
            }
        }
    }

    void IncrementScore()
    {
        score++; // Increment the score when the player wins a game
    }

    void DrawGrid()
    {
        // Draw thin grid lines for each cell
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                DrawRectangleLinesEx(Rectangle{cells[i][j].x + offsetX, cells[i][j].y + offsetY, cells[i][j].width, cells[i][j].height}, 1, DARKGRAY);
            }
        }

        // Draw thicker horizontal lines for each group of three rows
        for (int i = 0; i < 9; i += 3)
        {
            DrawRectangle((float)offsetX, (float)(cells[i][0].y + offsetY - 3), (float)(9 * (2.0f * windowWidth / 27)), 6, DARKGRAY);
        }

        // Draw thicker vertical lines for each group of three columns
        for (int j = 0; j < 9; j += 3)
        {
            DrawRectangle((float)(cells[0][j].x + offsetX - 3), (float)offsetY, 6, (float)(9 * (2.0f * windowHeight / 27)), DARKGRAY);
        }

        // Draw thicker lines at the boundaries of the entire grid
        DrawRectangle((float)(offsetX - 3), (float)(offsetY - 3), (float)(9 * (2.0f * windowWidth / 27)) + 6, 6, DARKGRAY);
        DrawRectangle((float)(offsetX - 3), (float)(cells[8][0].y + cells[8][0].height + offsetY - 3), (float)(9 * (2.0f * windowWidth / 27)) + 6, 6, DARKGRAY);
        DrawRectangle((float)(offsetX - 3), (float)(offsetY - 3), 6, (float)(9 * (2.0f * windowHeight / 27)) + 6, DARKGRAY);
        DrawRectangle((float)(cells[0][8].x + cells[0][8].width + offsetX - 3), (float)(offsetY - 3), 6, (float)(9 * (2.0f * windowHeight / 27)) + 6, DARKGRAY);
    }

    void DrawNumbers()
    {
        // Draw the player's score at the bottom center with a larger font size (e.g., 30)
        DrawText(TextFormat("Score: %d", score), windowWidth / 2 - MeasureText(TextFormat("Score: %d", score), 30) / 2, windowHeight - 40, 30, DARKGRAY);

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != 0)
                {
                    if (nonChangebleNumbers[i][j])
                    {
                        // Draw number text centered within the cell
                        DrawText(TextFormat("%d", board[i][j]),
                                 cells[i][j].x + offsetX + cells[i][j].width / 2 - MeasureText(TextFormat("%d", board[i][j]), 30) / 2,
                                 cells[i][j].y + offsetY + cells[i][j].height / 2 - 30 / 2,
                                 30, BLACK);
                    }
                    else
                    {
                        // Draw number text centered within the cell
                        DrawText(TextFormat("%d", board[i][j]),
                                 cells[i][j].x + offsetX + cells[i][j].width / 2 - MeasureText(TextFormat("%d", board[i][j]), 30) / 2,
                                 cells[i][j].y + offsetY + cells[i][j].height / 2 - 30 / 2,
                                 30, DARKBLUE);
                    }
                }
            }
        }

        // Decrement the wrongNumberTimer
        wrongNumberTimer -= GetFrameTime();

        // Check if it's a wrong number and display a message
        if (isWrongNumber)
        {
            DrawText("Wrong Number! Please try again.", offsetX, offsetY + 9 * (2.0f * windowHeight / 27) + 10, 20, RED);

            // Reset isWrongNumber when the timer reaches zero
            if (wrongNumberTimer <= 0.0f)
            {
                isWrongNumber = false;
            }
        }
    }

    void DrawButtons(bool gameWon)
    {
        DrawTexturePro(resetButton,
                       Rectangle{0, 0, (float)resetButton.width, (float)resetButton.height},
                       resetButtonRect,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);

        DrawTexturePro(turnOffButton,
                       Rectangle{0, 0, (float)turnOffButton.width, (float)turnOffButton.height},
                       turnOffButtonRect,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);
    }

    void HandleKeyboardInput()
    {
        // Check if the arrow keys are pressed and move the selected cell accordingly
        if (IsKeyPressed(KEY_RIGHT) && selectedCellCol < 8)
        {
            selectedCellCol++;
        }
        else if (IsKeyPressed(KEY_LEFT) && selectedCellCol > 0)
        {
            selectedCellCol--;
        }
        else if (IsKeyPressed(KEY_DOWN) && selectedCellRow < 8)
        {
            selectedCellRow++;
        }
        else if (IsKeyPressed(KEY_UP) && selectedCellRow > 0)
        {
            selectedCellRow--;
        }
    }

    // Method to handle mouse input for selecting a rectangle and identifying the cell
    void HandleMouseInput()
    {
        // Get mouse position
        Vector2 mousePos = GetMousePosition();

        // Check if the mouse is within the Sudoku grid
        bool isInsideGrid = CheckCollisionPointRec(mousePos, Rectangle{(float)offsetX, (float)offsetY, 9 * (2.0f * windowWidth / 27), 9 * (2.0f * windowHeight / 27)});

        // Calculate the row and column based on mouse position
        int row = (int)((mousePos.y - offsetY) / (2.0f * windowHeight / 27));
        int col = (int)((mousePos.x - offsetX) / (2.0f * windowWidth / 27));

        // Define padding for the red rectangle
        float paddingX = 4.0f;
        float paddingY = 4.0f;

        // Check if the left mouse button is pressed
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (isInsideGrid)
            {
                // Store the selected cell when clicking inside the Sudoku grid
                selectedCellRow = row;
                selectedCellCol = col;
            }
            else
            {
                // Clicked outside the Sudoku grid, reset selected cell and hide red rectangle
                selectedCellRow = -1;
                selectedCellCol = -1;
            }
        }

        // Draw a smaller red rectangle at the selected cell if it's a valid cell
        if (selectedCellRow != -1 && selectedCellCol != -1)
        {
            DrawRectangleLinesEx(Rectangle{
                                     cells[selectedCellRow][selectedCellCol].x + offsetX + paddingX,
                                     cells[selectedCellRow][selectedCellCol].y + offsetY + paddingY,
                                     cells[selectedCellRow][selectedCellCol].width - 2 * paddingX,
                                     cells[selectedCellRow][selectedCellCol].height - 2 * paddingY},
                                 4, RED);
        }
    }

    bool IsNumberValid(int row, int col, int number)
    {
        // Check if the number is already present in the same row or column
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == number || board[i][col] == number)
            {
                return false;
            }
        }

        // Check if the number is already present in the same 3x3 subgrid
        int subgridStartRow = (row / 3) * 3;
        int subgridStartCol = (col / 3) * 3;

        for (int i = subgridStartRow; i < subgridStartRow + 3; i++)
        {
            for (int j = subgridStartCol; j < subgridStartCol + 3; j++)
            {
                if (board[i][j] == number)
                {
                    return false;
                }
            }
        }

        // If all checks pass, the number is valid
        return true;
    }

    // Handle number input for entering numbers into the Sudoku grid
    void HandleNumberInput()
    {
        if (selectedCellRow != -1 && selectedCellCol != -1)
        {
            // Check if the selected cell is changeable (not a non-changeable number)
            if (!nonChangebleNumbers[selectedCellRow][selectedCellCol])
            {
                // Check for number input (1-9 keys on both number line and numpad)
                for (int number = 1; number <= 9; number++)
                {
                    if (IsKeyPressed(numericKeys[number - 1]))
                    {
                        if (IsNumberValid(selectedCellRow, selectedCellCol, number))
                        {
                            board[selectedCellRow][selectedCellCol] = number;
                        }
                        else
                        {
                            isWrongNumber = true;    // Set the flag to indicate a wrong number
                            wrongNumberTimer = 3.0f; // Set the timer to 3 seconds
                        }
                        break;
                    }
                }

                // Check for numeric keypad input (1-9 keys on the numeric keypad)
                for (int number = 10; number <= 18; number++)
                {
                    if (IsKeyPressed(numericKeys[number - 1]))
                    {
                        // Check if the number is valid in the current cell
                        if (IsNumberValid(selectedCellRow, selectedCellCol, number - 9))
                        {
                            board[selectedCellRow][selectedCellCol] = number - 9; // Subtract 9 to get the correct number
                        }
                        else
                        {
                            isWrongNumber = true;    // Set the flag to indicate a wrong number
                            wrongNumberTimer = 3.0f; // Set the timer to 3 seconds
                        }
                        break; // Only allow one number input per frame
                    }
                }

                // Check for backspace, delete, or Zero number key to clear the cell
                if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_DELETE) || IsKeyPressed(KEY_ZERO) || IsKeyPressed(KEY_KP_0))
                {
                    board[selectedCellRow][selectedCellCol] = 0;
                }
            }
        }
    }

    // Method to check if the Sudoku grid is solved
    bool IsSudokuSolved()
    {
        // Check if the Sudoku grid is completely filled
        bool isGridFilled = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    isGridFilled = false;
                    break;
                }
            }
            if (!isGridFilled)
            {
                break;
            }
        }

        // If the Sudoku grid is completely filled, check if it matches the solved board
        if (isGridFilled)
        {
            bool isSolved = true;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i][j] != solvedBoard[i][j])
                    {
                        isSolved = false;
                        break;
                    }
                }
                if (!isSolved)
                {
                    break;
                }
            }

            // If the grid matches the solved board, return true
            if (isSolved)
            {
                return true;
            }
        }

        return false;
    }

    // Method to handle the "Next" button click
    void HandleNextButtonClick(bool &gameWon)
    {
        int temp = id;

        if (CheckCollisionPointRec(GetMousePosition(), nextButtonRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Restart the game with a new puzzle
            RestartGame();

            while (temp == id)
            {
                // Generate a new puzzle
                GenerateNewPuzzle();
            }

            // Set Board to new puzzle
            setBoard();

            // Reset the game won flag
            gameWon = false;
        }
    }

    // Method to handle the reset button click
    void HandleResetButton(bool &gameWon)
    {
        if ((CheckCollisionPointRec(GetMousePosition(), resetButtonRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || ((gameWon) && (CheckCollisionPointRec(GetMousePosition(), RestartRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))))
        {
            // Reset the game to the initial puzzle (initialBoard)
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    board[i][j] = initialBoard[i][j];
                }
            }

            if (gameWon)
            {
                gameWon = false;
                score--;
            }
        }
    }

    // Method to handle the turn off button click
    void HandleTurnOffButton()
    {
        if (CheckCollisionPointRec(GetMousePosition(), turnOffButtonRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Close the window
            CloseWindow();

            // Exit the program
            exit(0);
        }
    }

    void YouWin()
    {
        DrawTexturePro(blurEffect,
                       Rectangle{0, 0, (float)blurEffect.width, (float)blurEffect.height},
                       blurRec,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);

        DrawTexturePro(youWinImage,
                       Rectangle{0, 0, (float)youWinImage.width, (float)youWinImage.height},
                       youWinRec,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);

        DrawTexturePro(nextButton,
                       Rectangle{0, 0, (float)nextButton.width, (float)nextButton.height},
                       nextButtonRect,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);

        DrawTexturePro(RestartButton,
                       Rectangle{0, 0, (float)RestartButton.width, (float)RestartButton.height},
                       RestartRec,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);
    }
};

class StartMenu
{
private:
    float windowWidth;
    float windowHeight;

    Texture2D startBg;
    Rectangle startBgRec;
    Vector2 startBgSize {};
    Vector2 startBgPos {};

    Texture2D startButton;
    Rectangle startButtonRec;
    Vector2 startButtonSize {};
    Vector2 startButtonPos {};

public:
    StartMenu(int width, int height) : windowWidth(width), windowHeight(height)
    {
        startBgSize = {windowWidth - 100, windowHeight - 150};
        startBgPos = {60.0f, 0.0f};

        startBg = LoadTexture("textures/sudoku_puzzle_game.png");
        startBgRec = {startBgPos.x, startBgPos.y, startBgSize.x, startBgSize.y};

        startButtonSize = {200.0f, 150.0f};
        startButtonPos = {windowWidth / 2 - startButtonSize.x / 2, startBgPos.y + startBgSize.y};

        startButton = LoadTexture("textures/Start_Button.png");
        startButtonRec = {startButtonPos.x, startButtonPos.y, startButtonSize.x, startButtonSize.y};
    }

    ~StartMenu()
    {
        UnloadTexture(startBg);
        UnloadTexture(startButton);
    }

    void Draw()
    {
        DrawTexturePro(startBg,
                       Rectangle{0, 0, (float)startBg.width, (float)startBg.height},
                       startBgRec,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);

        DrawTexturePro(startButton,
                       Rectangle{0, 0, (float)startButton.width, (float)startButton.height},
                       startButtonRec,
                       Vector2{0, 0},
                       0.0f,
                       WHITE);
    }

    void HandleStartButtonClick(bool &startScreen)
    {
        if (CheckCollisionPointRec(GetMousePosition(), startButtonRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            startScreen = false;
        }
    }
};

int main()
{
    // Initialize raylib
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Sudoku Game");
    // InitWindow(1080, 720, "Sudoku Game");
    SetTargetFPS(60);

    // Set the window to full screen
    ToggleFullscreen();

    int windowWidth = GetScreenWidth();
    int windowHeight = GetScreenHeight();
    // int windowWidth = 1080;
    // int windowHeight = 720;

    // Calculate the center of the screen
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;

    // Calculate the offset to center the grid based on the entire grid size
    int offsetX = centerX - (9 * (2.0f * windowWidth / 27)) / 2;
    int offsetY = centerY - (9 * (2.0f * windowHeight / 27)) / 2;

    // Create the StartMenu instance
    StartMenu start(windowWidth, windowHeight);

    // Generate the puzzle
    generatePuzzle puzzleGenerator;

    // Create the Sudoku game instance
    SudokuGame game(windowWidth, windowHeight, puzzleGenerator.initialBoard, offsetX, offsetY);

    // Flag to track if the game is won
    bool gameWon = false;

    // Flag to check if game started
    bool startScreen = true;

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (startScreen)
        {
            start.Draw();
            start.HandleStartButtonClick(startScreen);
        }
        else
        {
            if (!gameWon)
            {
                // Handle mouse input
                game.HandleMouseInput();

                // Handle keyboard input for moving the selected cell
                game.HandleKeyboardInput();

                // Handle number input for entering numbers into the Sudoku grid
                game.HandleNumberInput();
            }

            // Draw the grid with the centered offset and thicker lines
            game.DrawGrid();

            // Draw the numbers on the Sudoku grid
            game.DrawNumbers();

            // Check if Sudoku is solved and the game is not won yet
            if (game.IsSudokuSolved() && !gameWon)
            {
                gameWon = true;        // Set the game as won
                game.IncrementScore(); // Increment the player's score
            }

            game.HandleResetButton(gameWon);
            game.HandleTurnOffButton();

            // Draw the buttons (reset, turn off and next button)
            game.DrawButtons(gameWon); // Draw buttons after grid lines

            if (gameWon)
            {
                // Display "You Won!" message in the center with a larger font size
                // DrawText("YOU WON!", windowWidth / 2 - MeasureText("You Won!", 100) / 2, windowHeight / 2 - 25, 100, GREEN);

                game.YouWin();

                game.HandleNextButtonClick(gameWon);
            }
        }

        EndDrawing();
    }

    // Close raylib
    CloseWindow();

    return 0;
}