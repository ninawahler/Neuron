

#ifndef Network_hpp
#define Network_hpp
#include "Neuron.hpp"
#include "Constant.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;


/**
 * class Network
 * Here we have all the function and variables needed in order to run a simualation of a chosen number of neurons for a chosen time.
 * Here we creat a vector containing all our neurons : the first part contains the exhibitories (differs by having a J=0.1 while Jinhi=-0.5)
 * We also connect all neurons to each other randomly 
 * The class Network will be called in the main()
 */

class Network
{
private:
    vector<Neuron> allNeurons; /**< (Vector of Neuron) stores all the Neuron we have: the first part have exhibitories */
    
    int nbrExN; /**< (int) number of all the Exhibitory we have : Jexi=0.1 */
    int nbrInN; /**< (int) number of all the Inhibitory we have: Jinhi=(-0.5) */
    
    double time;    /**< (double) time of the simulation, initialy at 0.0 */
    double tStop;   /**< (double) final time of the simulation, initialy at 0.0, this is the user who chooses */
    
    
    
public:
    /**
     * ... Constructor ...
     */
    Network();
    
    /**
     * ... functions to initailise all the variables needed for the running of simulation ...
     */
    void neuronInitialisation (const int& nExi, double jExi, double jInhi);
    void connectionNeurons();
    void timeSet();
    
    /**
     * ... Running the simulation ...
     */
    void runSimulation();
    void spikeData();
    
    /**
     * ... Function for tests ...
     */
    unsigned long getSizeNeurons();
    
    /**
     * ... Destructor ...
     */
    ~Network();
    
};

#endif /* Network_hpp */
