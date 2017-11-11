
#ifndef Constant_hpp
#define Constant_hpp

#include <stdio.h>



    extern double h;               /**< (double) Step in time */

    extern double tau;             /**< (double) Time constant */
    extern double r;               /**< (double) Membrane resistance (=tau/C) */
    extern double z;               /**< (double) (=-(h/tau)) */
    
    extern double Je;              /**< (double) input constant given when an exibitor spikes */
    extern double Ji;              /**< (double) input constant given when an inhibitor spikes */
    
    extern double thresholdSpikes; /**< (double) Gives the value of the threshold after which the neuron spikes */
    extern int D;                  /**< (int) Delay in which the input is stored in buffer */
    extern double bufferSize;      /**< (double) Gives the size of the buffer */
    extern int presision;          /**< (double) Constant to try out sth */
    
    extern double Ce;              /**< (double) Gives the number of connection to exibitors */
    extern double Ci;              /**< (double) Gives the number of connections with inhibitors */
    

    extern double Vthr;            /**< (double)Value assiociated wit hthe threshold, use to calculate Vext */
    
    extern double Vext;            /**< (double) Gives the value of the external potential  */


#endif /* Constant_hpp */
