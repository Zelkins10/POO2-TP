#include <p6/p6.h>
#include <optional>
#include <array>

// ------------ Classes, Structs, etc. ----------

struct CellCoordinates{
    int x;
    int y;
};

enum class Player{
    Noughts,
    Crosses,
};

template<int size>
class Board{
public:

    std::optional<Player>& operator[](CellCoordinates index){
        return _cells[index.x][index.y];
    }

    const std::optional<Player>& operator[](CellCoordinates index) const{
        return _cells[index.x][index.y];
    }


private:
    std::array<std::array<std::optional<Player>, size>, size> _cells;

};

// ------------ Fonctions ----------

std::optional<CellCoordinates> hoveredCell(int boardSize, glm::vec2 position);

glm::vec2 cellBottomLeftCorner(CellCoordinates remappedCellCoords, int boardSize);

float cellRadius(int boardSize);

glm::vec2 cellCenter(CellCoordinates remappedCellCoords, int boardSize);

void drawNought(p6::Context& ctx, int boardSize, CellCoordinates cellCoords);
void drawCross(p6::Context& ctx, int boardSize, CellCoordinates cellCoords);

void drawBoard(int size, p6::Context& ctx);

template<int size>
void drawNoughtsAndCrosses(const Board<size>& board, p6::Context& ctx);

template<int boardSize>
void placeNoughtOrCross(std::optional<CellCoordinates> cellCoords, Player& currentPlayer, Board<boardSize>& board);

void noughtsAndCrossesGame();