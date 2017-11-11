//
//  main.cpp
//  Brunel
//
//  Created by Nina Wahler on 07.11.17.
//  Copyright © 2017 Nina Wahler. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Neuron.hpp"
#include <stdio.h>
#include "Network.hpp"

using namespace std;

int main()
{
    Network net; /**< (Network) creat an instance of network */
    cout <<"Creation of the network"<<endl;
    /**
     * Ask the user how many neurons he wants
     */
    int nEx;
    cout << "How many Exhibitories Neuron are you having? " << endl;
    cin >> nEx;
    
    
    //Call all function of Network in order to run a simualtion
     
    net.neuronInitialisation(nEx,0.1, (-0.5));
    cout <<"Neuron initiated"<<endl;
    
    net.connectionNeurons();
     cout <<"Neuron Connected"<<endl;
    net.timeSet();
    cout <<"time set"<<endl;
    
    net.runSimulation();
    cout <<"Simulation ran"<<endl;
    
    net.spikeData();
    
    cout << "end of program"<<endl;

    
    return 0;
}
