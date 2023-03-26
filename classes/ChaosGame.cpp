#include <stdexcept>
#include <cmath>
#include <iostream>
#include <random>
#include <numeric>
#include <functional>
#include <ctime>

#include <matplot/matplot.h>

#include "ChaosGame.hpp"

namespace plt = matplot;


/**
 * @brief Construct a new Chaos Game:: Chaos Game object
 * 
 * @param n 
 * @param r 
 */
ChaosGame::ChaosGame(int n, double r) {

    // Throw errors if arguments aren't within restrictions
    if (n < 3) throw std::invalid_argument("n has to be 3 or larger.");
    if (r <= 0 || r >= 1) throw std::invalid_argument("r has to be in between 0 and 1");

    // Assign class properties
    this->n = n;
    this->r = r;
    this->ngonPoints = generateNgon();

	// Initialize vector
	std::vector<std::vector<double>> p(2);
	this->points = p;
}


/**
 * @brief Generate the points of the n-gon.
 * 
 * @return std::vector<std::vector<double>> 
 */
std::vector<std::vector<double>> ChaosGame::generateNgon() {
    
    // Declare points
    std::vector<double> x;
    std::vector<double> y;

    // Generating pushing points into vectors
    for (int i = 0; i < n; i++) {
        x.push_back(sin((i * 2 * M_PI)/n));
        y.push_back(cos((i * 2 * M_PI)/n));
    }

    return {x, y};
}


/**
 * @brief Choose a random starting point inside the n-gon.
 * 
 * @return std::vector<double> 
 */
std::vector<double> ChaosGame::startingPoint() {

    // Generates random numbers using a mersenne twister.
    std::random_device rnd_dev;
    std::mt19937 mt{rnd_dev()};

    // Generate and normalize weights
    std::vector<double> weights(this->n);
    std::generate(weights.begin(), weights.end(), mt);

    double s = std::accumulate(weights.begin(), weights.end(), 
							   decltype(weights)::value_type(0));
    auto normalize = [&s](double num) { return num/s; };
    std::transform(weights.begin(), weights.end(), weights.begin(), normalize);

    // Take the inner product of the weights and the n-gon points.
    double x_coord = std::inner_product(this->ngonPoints[0].begin(), 
										this->ngonPoints[0].end(),
										weights.begin(), 0.0);
    double y_coord = std::inner_product(this->ngonPoints[1].begin(), 
										this->ngonPoints[1].end(), 
										weights.begin(), 0.0);

    return {x_coord, y_coord};
}


/**
 * @brief Generate points and colors to be plotted into the final figure.
 * 
 * @param n 
 * @param discard 
 */
void ChaosGame::iterate(int n, int discard) {
    
    // Generates random numbers using a mersenne twister.
    std::random_device rnd_dev;
    std::mt19937 mt(rnd_dev()); 

    std::vector<double> p = this->startingPoint();

    int rIndex;
    double x;
    double y;

	// Iterate, but don't keep the first points.
    for (int i = 0; i < discard; i++) {
        rIndex = mt() % this->n;
        x = this->r * p[0] + (1 - this->r) * this->ngonPoints[0][rIndex];
        y = this->r * p[1] + (1 - this->r) * this->ngonPoints[1][rIndex];
    }

	// Push the first value into the vector
    this->points[0].push_back({x});
	this->points[1].push_back({y});
    this->color.push_back(rIndex);

    auto nextColor = this->color.back();

	// Generate the rest of the points
    for (int i = 1; i < n; i++) {
        rIndex = mt() % this->n;
        this->points[0].push_back({this->r * this->points[0][i-1] 
							+ (1 - this->r) * this->ngonPoints[0][rIndex]});
        this->points[1].push_back({this->r * this->points[1][i-1] 
							+ (1 - this->r) * this->ngonPoints[1][rIndex]});
        
        this->color.push_back((rIndex + this->color.back())/2);
    }
}


/**
 * @brief Plots the points of the n-gon.
 * 
 */
void ChaosGame::plotNgon() {

    auto l = plt::scatter(this->ngonPoints[0], this->ngonPoints[1]);
    l->marker_face(true);
    plt::axis(plt::equal);
}


/**
 * @brief Plot points.
 * 
 */
void ChaosGame::plot() {
    if (this->points.empty()) {
        throw ("Vector is empty. iterate method has to be run first.");
    }

    auto l = plt::scatter(this->points[0], this->points[1], 1);

    l->marker_face(true);
    l->marker_colors(this->color);
}


/**
 * @brief Show plot
 * 
 */
void ChaosGame::show() {
    this->plot();

    plt::show();
}


/**
 * @brief Save plot
 * 
 * @param outfile 
 */
void ChaosGame::savePng(std::string outfile) {
    this->plot();

    plt::save(outfile);
}
