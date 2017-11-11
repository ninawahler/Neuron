//
//  Neuron.cpp
//  Brunel
//
//  Created by Nina Wahler on 07.11.17.
//  Copyright © 2017 Nina Wahler. All rights reserved.
//

#include "Neuron.hpp"
#include "Constant.cpp"
#include <cmath>
#include <iostream>
#include <random>
#include <assert.h>


using namespace std;

/** Constructor of Neuron
 * Inisialize all of Neuron's attributs
 * @param J (double) determine whether the neuron is inhibitory(-0.5) or exhibitory(0.1)
 */
Neuron::Neuron(double J)
{
    setMembranePot(0.0);
    iext=0.0;
    timeOwn=0.0;
    output = J;
    
    isRefractory=false;
    alreadyRefractory=false;
    spikeOccured=false;
    
    tSpikes.clear();
    connection.clear();


    for (int i(0); i < bufferSize; i++)
    {
        buffer[i]=0.0;
    }
    
}

/** Acces and return the value of the membrane potental
 *param none
 *@return the value of the membrane potential (double)
 */
double Neuron::getMembranePot()
{
    return membranePot;
}

/**
 * Acces and return the value of the external current
 * @return iext (double)
 */
double Neuron::getIExp()
{
    return iext;
}

/**
 * Acces and return the own time of the neuron
 * @return timeOwn (double)
 */
double Neuron::getTimeOwn()
{
    return timeOwn;
}


/**
 * Acces the number of time the neuron spiked: returns the size of the vector storing these values
 * @return tSpikes.size()
 */
double Neuron::getNbrSpikes()
{
    return tSpikes.size();
}


/**
 * Acces and return a boolean saying true if the neuron spiked
 * @return spikeOccured
 */
bool Neuron::getSpikeOccured()
{
    return spikeOccured;
}

/**
 * Acces the number of connection the neuron have: returns the size of the vector storing the connected neurons (pointers on neurons)
 * @return connection.size()
 */
unsigned long Neuron::getSizeConnection()
{
    return connection.size();
}


/**
 * Modify the membrane potential of the neuron
 * @param mp : membranePot (double)
 */
void Neuron::setMembranePot(double mp)
{
    membranePot=mp;
}

/**
 * Modify the external potential of the neuron
 * @param ie : Iext (double)
 */
void Neuron::setIExt(double ie)
{
    iext=ie;
}


/**
 * Add a neuron to the vector of connection with other neurons
 * @param other : (Pointer on Neuron)
 */

void Neuron::connectWith(Neuron* other)
{
     connection.push_back(other);

}



/**
 * One simulation : updates all the state at a time t
 * @param poisson : (int) random neuron representing number of spike from the rest of the brain 
 * the definition of this poisson distribution is done in the class Network
 */
void Neuron::simulation(int const& poisson)
{
    /**Check State of Neuron:
     *   if Refractory -> nothing happens: V=0 for 2ms
     *   if NotRefractory -> Upadate normally
     */

    if(isRefractory==true)
    {
        membranePot=0.0;
        spikeOccured = false;
        
        if (alreadyRefractory==true)
        {
            isRefractory = false;
        } else {
            alreadyRefractory=true;
        }
        
    }else {
        
        /**Check the membranePot:
         *   if V>Vseuil -> spike and have to put the state to refractory
         *   if V<seuil -> Continue incrementing
         */
        
        if (membranePot >= thresholdSpikes)
        {
            spikeOccured=true;
            tSpikes.push_back(timeOwn);
            isRefractory=true;
            giveSpike(timeOwn, output);
            
        }else{
            membranePot=((exp(z)* membranePot) + (iext*r*(1-(exp(z)))) + buffer[idxRead(timeOwn)])+ 0.1*poisson;
        }
    }
    resetBuffer(timeOwn);
    timeOwn=timeOwn+h;
}

/**
 * Gives the place in buffer where we are at a time t
 * @param now : (double) time at which we are in simulation
 * @return read : (int) place in buffer we have to read
 */
int Neuron::idxRead(double now)
{
    int w = static_cast<int>(now*10);
    int read = w % (D+1);

    return read;
}

/**
 * Gives the place in buffer where we are at a time t
 * @param temps : (double) time at which we are in simulation
 * @param give : (double) output given by the neuron to its connected neuron
 */
void Neuron::giveSpike(double const& temps, double give)
{
    if (!connection.empty())
    {
        for (size_t i(0); i<connection.size(); ++i)
        {
            connection[i]->addBuffer(temps, give);
        }
    }
}

/**
 * Update the buffer by entering the value of input a neuron receive from other neuron to which it's connected to
 * @param ut : (double) time at which we are in simulation: have to be place in buffer at time+delay
 * @param get : (double) input received by the neuron to which its connected
 */
void Neuron::addBuffer(double const& ut, double get)
{
    int d = static_cast<int>(ut*10 + D);
    buffer[d % (D+1)]+=get;

}

/**
 * Reset the place of the buffer in which we are at zero after each time set in the simulation
 * @param temps : (double) time at which we are in simulation
 */

void Neuron::resetBuffer(double temps)
{
    int w = static_cast<int>(temps*10);
    buffer[w % (D+1)]=0.0;
}



/**
 * Acces the time of a spike in the vector timeSpikes
 * @param i : position in vector
 * @return ts : time of the spike
 * used in the class Network to creat the file spikes.txt
 */
double Neuron:: accesVectorSpikesTime(int i)
{
    double ts;
    if (tSpikes.size()!=0)
    {
        assert(tSpikes.size()!=0);
        ts=tSpikes[i];
    }else
    {
        ts=0.0;
    }
    return ts;
}

/**
 * Destructor: clear the vector containing all pointers on connected neurons
 * param none
 */

Neuron::~Neuron()
{
    connection.clear();
}


