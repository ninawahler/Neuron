Neuron

Simulation of neurons 

ABOUT MAKING: 
- After a couple of days I realised that having a class Network would be advisable in oder to have a class dealing with the all the neuron of the program and their connection 
- After finishing the program I realised the complexity was to high, therefore I chose to modify it so it would consider the outgoing spikes and not the incoming spikes. That induced major changement in my code but reduced the complexity

ABOUT THE PROGRAM: 
- The aim of this program is to replicate the Brunel model which is a simple simulation of neurons in a brain

- The program considers two types of neurons: Exhibitors and Inhibitors. The difference between the two types lay in the energy they produce: exhibitory gives a positive energy and inhibitors a negative energy. The number of exhibitors is chosen by the user at the beginning and thanks to a ration Nexi=4Ninhi the number of inhibitors is initialised. 

- Then the class network will connect the neurons : The amount a neuron have is determined by a ration and the neuron connected are determined randomly thanks to Poission distribution. Being connected means that if a neuron spikes, it will give an amount of energy to the connected neuron stored in a vector of pointer on neurons

- The main aim of the program is to simulate the states of many neurons and their interaction. The state of a neuron is determined by its potential membrane. 
  1) If it attain a threshold it will spike
  2) Once it spiked the neuron will enter a state of refractory where its potential membrane is set at 0
  3) Regular update of the potential membrane folowing an equation taking several values in consideration  :
    a) The external current initialised at 0
    b) The incoming spike of neurons to which it's connected 
    c) Income from the rest of the brain determined randomly 
    d) Some constants which can be fined in the class Constant
 
 - The program updates these states for a time interval chosen by the user 
