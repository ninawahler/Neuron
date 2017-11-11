

#include "Network.hpp"
#include <fstream>
#include <random>
#include <assert.h>

using namespace std;


/** Constructor of Network
 * Inisialize all of Network's attributs
 */
Network::Network()
{
    allNeurons.clear();
    
    nbrExN = 0;
    nbrInN = 0;
    
    time = 0.0;
    tStop = 0.0;
}


/**
 * Inisialize the number of exhibitories and inhibitories and push_back both vectors accordingly
 * @param nExi : (int) number of exhibitory neuron
 * @param jExi : (double) value of the output given by exhibitory neuron: 0.1
 * @param jInhi : (double) value of the output given by inhibitories neuron: -0.5
 */
void Network::neuronInitialisation(const int& nExi, double jExi, double jInhi)
{
    nbrExN=nExi;
    
    for (int i(0); i<nbrExN; i++)
    {
        Neuron n(jExi);
       allNeurons.push_back(n);
    }
    assert(allNeurons.size()>=0);
    
    //N=Ne+Ni -> Ne= 0.8N, Ni=0.2N -> N=Ne/0.8=Ni/0.2 -> Ne=Ni(0.8/0.2)=4Ni ->Ni =1/4Ne
    //Initialisation of Inhibitory Neurons
    nbrInN=nbrExN/4;
    cout<<"Since Ne=4Ni you are having : "<< nbrInN << endl;
    
    for (int i(0); i<nbrInN; i++)
    {
        Neuron n(jInhi);
        allNeurons.push_back(n);
    }
}


/**
 * Connects randomly neurons to one another
 * param : 'none'
 * Gives a random number : Random neuron to which it'll be connected
 * Range : nbr of Neuron we have both exhibitory and inhibitory
 */
void Network::connectionNeurons()
{
    random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<> dis_ex(0, nbrExN-1);
    uniform_int_distribution<> dis_in(nbrExN, nbrExN+(nbrInN-1));
    
    
    int I;
    int K;

    for (size_t i(0); i<allNeurons.size(); i++)     //Go through all exhi neuron to connect them
    {
        for (int j(0); j<(nbrExN/10); j++)
        {
            I = dis_ex(gen);
            assert(I<=nbrExN-1);
            allNeurons[i].connectWith(&allNeurons[I]);
            
        }
        
        for (int k(0); k<(nbrInN/10); k++) //k=250
        {
            //Choose random nbr between 0 and nbr total of inhibiteur neuron
            K = dis_in(gen);
            assert(K<=allNeurons.size());
            assert (K>=nbrExN);
            allNeurons[i].connectWith(&allNeurons[K]);
        }
    }
}

/**
 * Set the time of the simulation
 * param : none
 * Here we ask the user the initial and final time of the duration of the simulation and the program will consider the interval of time : tStop represents total time of simulation
 */
void  Network::timeSet()
{
    double a;
    double b;
    
    cout << "Choose your time interval"<< endl;
    cout<< "Simulation start:"<< endl;
    cin>>a;
    cout<<"Simulation end:" <<endl;
    cin>>b;
    
    tStop = b-a; //Time of the simulation
    assert(tStop>=0);
    
}


/**
 * Runs the simulation with all the variables chosen during a certain amount of time
 * param none
 * There is the possibility to save all the values and state of all neurons during the simulation in aexternal file. But due to lack of uses and of necessity we commented this option
 */
void Network::runSimulation ()
{
    //copy variable to a file : creation of ofstream
    /*ofstream cVar;
     cVar.open("Variables.txt");
     cVar.fail(); //In order to test if you coud open your file
     if (cVar.fail()==true)
     {
     cout << "Error in opening of the file"<< endl;
     } else {
     cout << "Your file could be opened"<< endl;
     }
     */
    
    static random_device rd; //attribut
    static mt19937 generator(rd());
    static poisson_distribution<>  distribution (20*h);
    
    //Run neuron simulation for the time interval and print the values in text file
    do
    {
        for (size_t i(0); i<allNeurons.size(); i++)
        {
            //cout << "For neuron number " << i+1 << endl;
            allNeurons[i].simulation(distribution(generator));
            
           //cout << "membrane potential at time " << allNeurons[i].getTimeOwn()<<" : "<< allNeurons[i].getMembranePot()<<endl;
            //cout << "At time: " <<allNeurons[i].getTimeOwn() <<" the number of spike is: " << allNeurons[i].getNbrSpikes() << endl;
            //cout << endl;
            
            //Update de timeSpikes
            /*if (allNeurons[i].getSpikeOccured()==true)
             {
             
             cout <<"!! A spike has occur at time: " << endl;
             cout << endl;
             }
            */
            
        }
        
    time=time+h;
    }
    while(time <= tStop);
    //cVar.close();
}


/**
 * Creates a file and store which neuron spikes at what time: enables to recreat the wanted graph using python
 * param none
 */
void Network::spikeData()
{
    ofstream data;
    data.open("spikes.txt");
    data.fail(); //In order to test if you coud open your file
    if (data.fail()==true)
    {
        cout << "Error in opening of the file"<< endl;
    } else {
        cout << "Your file could be opened"<< endl;
    }
    
    
    for (size_t i(0); i<allNeurons.size(); ++i)
    {
        
        for(int k(0); k<allNeurons[i].getNbrSpikes(); ++k)
        {
            double timeDataEx;
            timeDataEx = allNeurons[i].accesVectorSpikesTime(k);
            data<< timeDataEx <<  '\t' << i << '\n' ;
        }
    }
    
    cout << "Data stored "<<endl;
    data.close();
    
}


/**
 * Returns the size of the vector containing all the neurons of the network
 * param none
 */

unsigned long Network::getSizeNeurons()
{
    return allNeurons.size();
}


/**
 * In charge of freeing all memories
 * param none
 */
Network::~Network()
{
    allNeurons.clear();
    assert(allNeurons.empty());
}


