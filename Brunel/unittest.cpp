

#include "Neuron.hpp"
#include "Constant.hpp"
#include "Network.hpp"
#include "googletest/include/gtest/gtest.h"
#include <cmath>

using namespace std;


 TEST (NeuronTest, PositiveInput)
 {
 
 Neuron ntest(0);
 
 //We test one simulation of one neuron having a Iext = 0.0 : should have any spike
 ntest.setIExt(0.0);
 ntest.simulation(0);
 EXPECT_EQ(0.0, ntest.getNbrSpikes());
 
 Neuron nTest2(0);
 //We test one simulation of one neuron having a Iext = 19.9 : should have any spike
 nTest2.setIExt(19.9);
 nTest2.simulation(0);
 EXPECT_EQ(0.0, nTest2.getNbrSpikes());
 

 Neuron nTest3(0.0);
 //We test some simulation of one neuron having a high Iext : should have one spike quickly
 nTest3.setIExt(1000.0);
 nTest3.simulation(0);
 nTest3.simulation(0);
 EXPECT_EQ(1.0, nTest3.getNbrSpikes());

 }
 

 TEST (NeuronTest, NbrSpike)
 {
 Neuron n(0.0);
 n.setIExt(1.01);
 //Since iext = 1.01, a spike should arrive at time 92.5 (we have a time step of 0.1)
 for (int i(0); i<924 ; i++)
 {
  n.simulation(0);
 }
 
 
 EXPECT_EQ(0.0, n.getNbrSpikes());
 
 for (int j(0); j<2; j++)
 {
  n.simulation(0);
 }
 EXPECT_EQ(1.0, n.getNbrSpikes());
 
 
 }

 
 TEST (NetworkTest, nbrNeurons)
 {
 //The number of inhibitories neurons has to be proportional to the number of exhibitories -> ne=4ni
 Network net;
 net.neuronInitialisation(100,0.0,0.0);
 EXPECT_EQ(25, (net.getSizeNeurons() - 100)); //We substract the 100 exhibitories
 
 }


 TEST (NetworkNeuron, connections)
 {
 //Creating 2 neurons, assuming they are exhibitory
 Neuron* n1 = new Neuron(0.1);
 Neuron* n2 = new Neuron(0.0);
 
 n1->setIExt(10);
 //Testing the connection of two neurons
 n1->connectWith(n2);
 EXPECT_EQ(1, n1->getSizeConnection());
 
 //Now that n1 is connected to n2-> if n2 spike n1 will receive an input
 
 n1->setMembranePot(19.9);
 
 for (int j(0); j<17; j++) //Take into account the delay and n1 will spike at the 2nd simulation
 {
     n1->simulation(0);
     n2->simulation(0);
 }
 
 //Now the membrane potential after a delay time step n2 will be :
 EXPECT_EQ(0.1, n2->getMembranePot());
 }
 

int main(int argc, char **argv)
{
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


