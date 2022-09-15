#include <iostream>
using namespace std;

const int avgPerPass = 180;
const int maxPassSeats = 250;
const int maxWeight = 125000;


int main(int argc,char * argv[])
{
    int baseWeight = 75000;
    int numberOfPass;
    cout<<"\nEnter the number of passengers : ";
    cin>>numberOfPass;
    cout<<"\nOriginal weight = "<<baseWeight<<endl;
    cout<<"Passenger weight added = "<<(numberOfPass*avgPerPass)<<endl;
    baseWeight = baseWeight + (numberOfPass*avgPerPass);
    cout<<"New weight = "<<baseWeight<<endl;
      
    int *cargoWeight = (int *)malloc(1000*sizeof(int));
    int count=0;
    int shipmentWeight = 0;
    while(true){
        int currCargoWeight;
        cout<<"\nCurrent shipment weight = "<<shipmentWeight<<endl;
        cout<<"Enter the cargo weight : ";
        cin>>currCargoWeight;
        if((currCargoWeight+baseWeight)>maxWeight){
            cout<<currCargoWeight<<" lbs cannot be loaded as train will get overloaded."<<endl;
            break;
        }
        cargoWeight[count] = currCargoWeight;
        shipmentWeight = shipmentWeight + cargoWeight[count];
        baseWeight = baseWeight + currCargoWeight;
        cout<<"New weight = "<<baseWeight<<endl;
        count++;
    }
    cout<<"\nTrain : "<<argv[1]<<endl;
    cout<<"Train Number : "<<argv[2]<<endl;
    cout<<"Number of Passengers : "<<numberOfPass<<endl;
    cout<<"Number of cargo shipments : "<<count<<endl;
    cout<<"All cargo weights are : "<<endl;
    for(int i=0;i<count;i++){
      cout<<cargoWeight[i]<<" ";
    }
    cout<<"\nTotal Weight : "<<baseWeight<<endl;
    cout<<"Maximum Weight : "<<maxWeight<<endl;
    return 0;
}
