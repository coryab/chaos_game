#include <iostream>
#include <vector>

#include <matplot/matplot.h>

#include "classes/ChaosGame.hpp"

namespace plt = matplot;

int main() {

	// Chaos game with a triangle
    ChaosGame cg(3, 0.5);

    cg.iterate(10000);

    cg.show();

    cg.savePng("image.png");

    return 0;
}
