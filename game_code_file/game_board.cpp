#include "game_board.h"
#include "ui_game_board.h"

game_board::game_board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game_board)
{
    ui->setupUi(this);
}

game_board::~game_board()
{
    delete ui;
}
