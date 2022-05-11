#include <p6/p6.h>

// void createContext(){

// }

void draw_board(int size, p6::Context& ctx)
{
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            ctx.square(p6::BottomLeftCorner{p6::map(i,0,2,0,720/3), p6::map(j,0,2,0,720/3)}, p6::Radius{720/3});
        }
    }
}

void noughtsAndCrossesGame(){
    // Create the window
        auto ctx = p6::Context{{720, 720, "Noughts and Crosses"}}; // Create a context with a window
        ctx.update = [&](){                    // Define the function that will be called in a loop once you call ctx.start()
            ctx.background({0.f, 0.f, 0.f}); // Clear the background with some color (Try to comment out this line to see what happens)
            //ctx.circle(p6::Center{ctx.mouse()}, // Draw a circle centered on the mouse cursor
                        //p6::Radius{0.3f});       // with a radius of 0.3
            //ctx.square(p6::Center{0, 0}, // Draw a circle centered // on the mouse cursor : Center{ctx.mouse()} 
                        //p6::Radius{0.3f});       // with a radius of 0.3
        
            // Draw board
            ctx.stroke_weight = 0.01f;
            ctx.stroke = {1.f, 1.f, 1.f, 1.f};
            ctx.fill = {0.f, 0.f, 0.f, 0.f};
            draw_board(3, ctx);
    };

    // Start the p6 application
    ctx.start();

}