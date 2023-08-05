"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    xcount = 0
    ocount = 0
    length = len(board)
    length_row = len(board[0])

    for i in range(0, length):
        for j in range(0, length_row):
            if board[i][j] == X:
                xcount += 1
            elif board[i][j] == O:
                ocount += 1

    if ocount < xcount:
        return O
    else:
        return X


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    actions_set = set()
    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                actions_set.add((i, j))

    return actions_set


def result(boardv, actionv):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    result = copy.deepcopy(boardv)
    result[actionv[0]][actionv[1]] = player(boardv)

    return result




def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    # check horizontal
    for row in board:
        winner = []
        for cell in row:
            winner.append(cell)
        if winner.count(winner[0]) == len(winner):
            return winner[0]
        else:
            winner = []


    # check vertical
    vertical = []
    for i in range(3):

        for row in board:
            vertical.append(row[i])
        if vertical.count(vertical[0]) == len(vertical):
            return vertical[0]
        else:
            vertical = []

    # check first diagonal
    diagonal1 = []
    for i in range(3):
        for j in range(3):
            if i == j:
                diagonal1.append(board[i][j])

    if diagonal1.count(diagonal1[0]) == len(diagonal1):
            return diagonal1[0]
    else:
        diagonal1 = []

    # check second diagonal
    diagonal2 = []
    for i in range(3):
        for j in range(3):
            if i + j == 2:
                diagonal2.append(board[i][j])

    if diagonal2.count(diagonal2[0]) == len(diagonal2):
            return diagonal2[0]
    else:
        diagonal2 = []

    return None



def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """

    if winner(board):
        return True
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == EMPTY:
                return False
    return True


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if terminal(board):
        value = winner(board)
        if value == "X":
            return 1
        elif value == "O":
            return -1
        elif value == None:
            return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board
    """
    if terminal(board):
        return None
    else:
        if player(board) == "X":
            v, move = max_value(board)


        elif player(board) == "O":
            v, move = min_value(board)

    return move



def max_value(board):
    if terminal(board):
        return utility(board), None

    v = float('-inf')
    move = None
    for action in actions(board):
        a, b = min_value(result(board, action))
        if a > v:
            v = a
            move = action

            if v == 1:
                return v, move


    return v, move


def min_value(board):
    if terminal(board):
        return utility(board), None

    v = float('inf')
    move = None
    for action in actions(board):

        a, b = max_value(result(board, action))
        if a < v:
            v = a
            move = action

            if v == -1:
                return v, move


    return v, move
