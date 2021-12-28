#ifndef CHAOS_GAME_HPP
#define CHAOS_GAME_HPP

#include <vector>
#include <string>

class ChaosGame {
private:
    std::vector<std::vector<double>> ngonPoints;
    std::vector<std::vector<double>> points;
    std::vector<double> color;
    int n;
    double r;
    
    std::vector<std::vector<double>> generateNgon();
    std::vector<double> startingPoint();
public:
    ChaosGame(int n, double r);
    void iterate(int steps, int discard = 5);
    void plotNgon();
    void plot();
    void show();
    void savePng(std::string outfile);
};

#endif