class Board {
    private:
        void clearScreen();
        int board_state[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        char evaluateSymbol(int sym);
        int evaluateInternalSymbol(char sym);
        char isMatching(int pos1, int pos2, int pos3);
    
    public:
        void drawBoard();
        bool isOWinning();
        bool isXWinning();
        void setSymbol(int pos, char symbol);
        char getSymbol(int pos);
        void playComputer();
        bool isDraw();
        
};