//
// omer lichter
// id: 314649666
//

#include "AIPlayer.h"

AIPlayer::AIPlayer(Cell color) : Player(color) {
}

Point* AIPlayer::chooseMove(vector<Point>* points, const Logic& logic, const Board& board) const {

    // possible moves of AI Player
    vector<Point>* vPossibleMoves = points;

    // initial the min value to the number of the cells
    int minOppScore = board.getSize() * board.getSize();
    Point* minOppScoreMove = new Point(-1, -1);

    // do every possible move on virtual board
    for (int i = 0; i < vPossibleMoves->size(); i++) {
        // the AI Player move point
        Point AIPlyerMove = vPossibleMoves->at(i);

        // create new virtual board that is copy of the original board
        Board vBoard(board);

        // make the AI player move
        logic.makeMove(this->playerColor_, AIPlyerMove, vBoard);

        // get the max score of the opponent in this state of board
        int maxScore = maxOppScore(logic, vBoard);

        if (maxScore < minOppScore) {
            minOppScore = maxScore;
            minOppScoreMove->setColumn(AIPlyerMove.getColumn());
            minOppScoreMove->setRow(AIPlyerMove.getRow());
        }
    }
    return minOppScoreMove;
}

int AIPlayer::maxOppScore(const Logic &logic, Board &board) const {

    // initial the max value to the minimal possible score
    int maxScore = board.getSize() * board.getSize() * -1;
    Cell oppColor;
    if (this->playerColor_ == Black) {
        oppColor = White;
    } else {
        oppColor = Black;
    }

    vector<Point>* oppPossibleMoves = logic.moveOptions(oppColor, board);
    for (int i = 0; i < oppPossibleMoves->size(); i++) {
        // create new virtual board that is copy of the board
        Board vBoard(board);

        // the opp Player move point
        Point oppMove = oppPossibleMoves->at(i);

        // make the opp move
        logic.makeMove(oppColor, oppMove, vBoard);

        // calculate the score of the move
        int score = vBoard.getNumberOfBlackCells() - vBoard.getNumberOfWhiteCells();

        // if the current score is bigger then the maximum score until now
        if (score > maxScore) {
            maxScore = score;
        }
    }
    delete(oppPossibleMoves);
    return maxScore;
}