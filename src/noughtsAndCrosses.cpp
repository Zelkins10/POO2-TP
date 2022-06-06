#include "noughtsAndCrosses.hpp"
#include <p6/p6.h>
#include <optional>

// Savoir quelle cellule est survolée par la souris
std::optional<CellCoordinates> hoveredCell(int boardSize, glm::vec2 position){
    const auto pos = p6::map(position, glm::vec2{-1.f}, glm::vec2{1.f}, glm::vec2{0.f}, glm::vec2{static_cast<float>(boardSize)});
    const auto remappedCellCoords = CellCoordinates{static_cast<int>(std::floor(pos.x)), static_cast<int>(std::floor(pos.y))};
    
    if(remappedCellCoords.x >= 0 && remappedCellCoords.x < boardSize && remappedCellCoords.y >= 0 && remappedCellCoords.y < boardSize){ // Si remappedCellCoords est bien situé dans le board
        return std::make_optional(remappedCellCoords);
    }
    else{
        return std::nullopt;
    }
}

// ------- Utilitaires pour les cellules --------

// Récupérer les coordonnées du coin bas gauche à partir des indices remappedCellCoords de la cellule
glm::vec2 cellBottomLeftCorner(CellCoordinates remappedCellCoords, int boardSize){
    const auto cellIndices = glm::vec2{static_cast<float>(remappedCellCoords.x), static_cast<float>(remappedCellCoords.y)};
    return p6::map(cellIndices,
                   glm::vec2{0.f}, glm::vec2{static_cast<float>(boardSize), static_cast<float>(boardSize)},
                   glm::vec2{-1.f}, glm::vec2{1.f});
}

// Récupérer le rayon de la cellule
float cellRadius(int boardSize){
    return 1.f /static_cast<float>(boardSize);
}

// Récupérer les coordonéees du centre d'une cellule
glm::vec2 cellCenter(CellCoordinates remappedCellCoords, int boardSize){
    return cellBottomLeftCorner(remappedCellCoords, boardSize) + cellRadius(boardSize);
}

// ----------------------------------------------


// ------- Fonctions pour le dessin --------

// Placer un rond
void drawNought(p6::Context& ctx, int boardSize, CellCoordinates cellCoords){
    ctx.fill = {255, 255, 255};
    ctx.circle(p6::Center{cellCenter(cellCoords, boardSize)}, p6::Radius{static_cast<double>(0.9) * cellRadius(boardSize)});
}

// Placer une croix
void drawCross(p6::Context& ctx, int boardSize, CellCoordinates cellCoords){
    ctx.fill = {255, 255, 255};
    ctx.rectangle(p6::Center{cellCenter(cellCoords, boardSize)}, p6::Radii{cellRadius(boardSize), cellRadius(boardSize)/4}, p6::Rotation{45.0_degrees});
    ctx.rectangle(p6::Center{cellCenter(cellCoords, boardSize)}, p6::Radii{cellRadius(boardSize), cellRadius(boardSize)/4}, p6::Rotation{-45.0_degrees});
}


void drawBoard(int size, p6::Context& ctx){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(i), static_cast<float>(j)},
                                                    glm::vec2{0.f}, glm::vec2{static_cast<float>(size)},
                                                    glm::vec2{-1.f}, glm::vec2{1.f})},
                        p6::Radius{1.f / static_cast<float>(size)});
        }
    }
}

template<int size>
void drawNoughtsAndCrosses(const Board<size>& board, p6::Context& ctx){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            const auto cell = board[{i, j}];
            if(*cell == Player::Noughts){
                drawNought(ctx, size, {i, j});
            }
            else if(*cell == Player::Crosses){
                drawCross(ctx, size, {i, j});
            }
        }
    }
}

/*
template<int boardSize>
void previewNoughtOrCross(CellCoordinates cellCoords, Player currentPlayer, Board<boardSize> board){

}
*/

template<int boardSize>
void placeNoughtOrCross(std::optional<CellCoordinates> cellCoords, Player& currentPlayer, Board<boardSize>& board){
    if(!board[*cellCoords].has_value()){
        board[*cellCoords] = currentPlayer;
        
        if(currentPlayer == Player::Noughts){ // Changement de joueur
            currentPlayer = Player::Crosses;
        }
        else{currentPlayer = Player::Noughts;
        }
    }
}

// -------------------------------------------


void noughtsAndCrossesGame(){
    // Création de la fenêtre
    auto ctx = p6::Context{{720, 720, "Noughts and Crosses"}}; // Create a context with a window
    
    const int boardSize = 3;
    Board board = Board<boardSize>{};
    Player currentPlayer = Player::Crosses;

    // Test de placement à la souris
    ctx.mouse_pressed = [&](p6::MouseButton event){
        placeNoughtOrCross(hoveredCell(boardSize, event.position), currentPlayer, board);
    };

    ctx.update = [&](){ // Define the function that will be called in a loop once you call ctx.start()
        ctx.background({0.f, 0.f, 0.f}); // Clear the background with some color (Try to comment out this line to see what happens)
    
        // Draw board
        ctx.stroke_weight = 0.01f;
        ctx.stroke = {1.f, 1.f, 1.f, 1.f};
        ctx.fill = {0.f, 0.f, 0.f, 0.f};
        drawBoard(boardSize, ctx);

        // Test manuel
        drawCross(ctx, boardSize, {1,1});

        drawNoughtsAndCrosses(board, ctx);

    };

    // Start the p6 application
    ctx.start();

}