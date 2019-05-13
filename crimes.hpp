#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Crimes {
    private:
    struct storage {
        string month;
		double longitude;
		double latitude;
		string crimeType;
        ifstream dataFile;
    };
    vector<storage> cMonth; //Initial vector declaration
    //vector<vector> allCrime;
    ifstream dataFile;
    string files [9];
    
    protected:
    
    public:
    Crimes();
    
    void setCrimes();

    
    //vector<vector> getCrimes();
};

Crimes::Crimes(){
    vector<storage> cMonth;
    //vector<vector> allCrime;
    string files [9] = {"2018-01-lincolnshire-street.csv", "2018-02-lincolnshire-street.csv", "2018-03-lincolnshire-street.csv", "2018-04-lincolnshire-street.csv", "2018-05-lincolnshire-street.csv", "2018-06-lincolnshire-street.csv", "2018-07-lincolnshire-street.csv", "2018-08-lincolnshire-street.csv", "2018-09-lincolnshire-street.csv"};
    ifstream dataFile;
};

struct storage {
        string month;
		double longitude;
		double latitude;
		string crimeType;
};

void Crimes::setCrimes() {

    for(int i = 0; i <= 9; i++){
        dataFile.open (files[i]);
        
        if(dataFile.is_open() && dataFile.good())
        {        
         try {  
               string dataField, dataField2, dataField5, reports, falls, LScode, LSname, dataField3, dataField4; 
             
               while(getline(dataFile,dataField,',')) {
                    string id = dataField;
                    
                    getline(dataFile,dataField2,',');
                    string month = dataField2;

                    getline(dataFile,reports,',');
                    getline(dataFile,falls,',');
                    
                    getline(dataFile,dataField3,',');
                    double longi = stod(dataField3);
                    
                    getline(dataFile,dataField4,',');
                    double lati = stod(dataField4);
                    
                    getline(dataFile,LScode,',');
                    getline(dataFile,LSname,',');
                    
                    getline(dataFile,dataField5,',');
                    string type = dataField5;
                    
                    storage t = { month, longi, lati, type };
                    cMonth.push_back(t);
                    
                    
                    getline(dataFile,dataField,'\n');
                    }
                }
          
         
         catch (exception) {
         std::cout << "Error Reading File" << std::endl; 
         }
        
         dataFile.close();
        }
   
    //size_t temp = cMonth.size() - 1;
    //if (cMonth != NULL){//
        //for (size_t t = 0; t <= temp; t++){
            //allCrime.push_back(cMonth[t]);
        //}
    //}
    }
};
