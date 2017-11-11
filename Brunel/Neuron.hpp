

#ifndef Neuron_hpp
#define Neuron_hpp
#include <vector>
#include <array>

#include "Constant.hpp"



/* Neuron_hpp */

/**
 * class Neuron
 * Creation and Initialisation of all attributs that a neuron needs
 * Different functions to simulate a neuron: connecting them, calculating its input,...
 * Many functions to modify or have acces to the varibales outside of the class
 */

class Neuron
{
    
private:
    
    /**
     *  ... General attributs ...
     */
    double membranePot;     /**< (double) Value of Membrane Potential, initialized at zero, update every h */
    double iext;            /**< (double) Value of the external Current that the user chooses */
    double timeOwn;         /**< (double) Represent the time proper to that Neuron */
    double output;          /**< (double) Represent the J given by the Neuron to connextion */
    /**
     * ... variables for updates ...
     */
    bool isRefractory;      /**< (bool) True if the neuron is in a refractory state */
    bool alreadyRefractory; /**< (bool) true if a neuron has been refractory for already one h */
    bool spikeOccured;      /**< (bool) True if at time h the neuron spiked */
    
    /**
     * ... Vectors ...
     */
    std::vector <double> tSpikes;           /**< (Vector of double) stores all timeSpikes*/
    std::vector <Neuron*> connection;    /**< (Vectors of *Neurons) lists all the neuron it's connected to */
    
    
    std::array <double, 16> buffer;            /**< (Vector of double) Store the totalInput with a delay (+15h)*/
    
    
public:
    
    /**
     * ... Constructor ...
     */
    Neuron (double J);
    
    /**
     * ... Getteurs to acces class member ...
     */
    
    double getMembranePot();
    double getNbrSpikes();
    double getIExp();
    bool getSpikeOccured();
    double getTimeOwn();
    double accesVectorSpikesTime(int i);
    unsigned long getSizeConnection();
    
    /**
     * ... Setteur to modify class member ...
     */
    void setMembranePot(double mp);
    void setIExt(double ie);
    
    /**
     * ... Methode that updates the neuron state from time t to time t+T (T=n*h) ...
     */
    void simulation(int const& poisson);
    void giveSpike(double const& temps, double give);
    void addBuffer(double const& ut, double get);
    void resetBuffer(double temps);
    int idxRead(double now);
    
    
    /**
     * ... Methode dealing with the connected neurons ...
     */
    void connectWith(Neuron* other);

    
    ~Neuron();
};
#endif

