///**************************************************************************
/// HEADER: Contains All Structures
///**************************************************************************

#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "Main.h"


// Kernel Types
enum Kernel { Gaussian=1, Bell_shaped=2, Cubic_spline=3, Quadratic=4, Quintic=5, Quintic_spline=6 };

// model of viscosity formulation
enum ViscoMod { violeau=1 };

// integrationMethod = euler ou RK2
enum IntegrationMethod {euler, RK2};

// densityInitMethod = hydrosatic, etc.
enum DensityInitMethod {hydrostatic, homogeneous};

// stateEquationMethod = quasiIncompressible, perfectGas, etc.
enum StateEquationMethod {quasiIncompressible, perfectGas};

// massInitMethod = violeau2012 (all particles have same volumes), etc.
enum MassInitMethod {violeau2012};

// speedLaw = Will dictate the behaviour of moving boundaries: constant, sine, exponential
enum SpeedLaw {constant, sine, exponential};

// mode of the moveing particle 
enum MoveMod { none=1, uni_sin=2, expon=3, levier=4 };

// Write Format output
enum Format { ParaView=1, Matlab=2, Both=3 };

// charactTime = characteristic time of movement or period of oscillations

// movingDirection = direction de la paroi mouvante

/* Parameter Structure
 * kh = smothing length
 * k = time step
 * T = simulation time
 * densityRef = density of the fluid at atmospheric pressure
 * l & u = lower and upper limit of the domain
 * B & gamma = fluid constants
 * g = gravity
 * writeInteval = time interval between two outputs file are generated
*/
struct Parameter {
    double kh, k, T, densityRef, B, gamma, g, writeInterval, charactTime;
    double movingDirection[3];
    Kernel kernel;
    ViscoMod viscoMod;
    IntegrationMethod integrationMethod;
    DensityInitMethod densityInitMethod;
    StateEquationMethod stateEquationMethod;
    MassInitMethod massInitMethod;
    SpeedLaw speedLaw;
    MoveMod moveMod;
    Format format;
};


struct Field {
    int nFree, nFixed, nMoving;

    std::vector<double> s;

    double l[3];
    double u[3];

    std::vector<double> pos;

    std::vector<double> speed;

    std::vector<double> density;

    std::vector<double> pressure;

    std::vector<double> mass;

};



#endif
