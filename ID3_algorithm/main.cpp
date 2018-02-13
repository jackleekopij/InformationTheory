#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <Eigen/Dense>
#include <sstream>
#include <typeinfo>

using namespace Eigen;
using namespace std;



struct data_dimensions{
    long num_examples;
    long num_variables;
};

data_dimensions getNumberOfTrainingExamples( vector<vector<string>> training_data){
    int num_training_data = training_data.size();
    int number_of_variables =  training_data[0].size();
    return data_dimensions{num_training_data, number_of_variables};
}

vector<vector<string>> transpose_vector_of_vectors(vector<vector<string>> training_data){
    int row_number =training_data[0].size();
    int col_number =training_data.size();
    vector<vector<string>> transposed_data;
    string myString =  training_data[0][0];
    for(int j=0; j<row_number; j++){
        vector<string> temp_array;
        for(int i=0; i!=col_number; i++){
            temp_array.push_back(training_data[i][j]);
        }
        transposed_data.push_back(temp_array);
    }
    return transposed_data;
}





double calculateEntropy( vector<vector<string>> training_data, map<int,string> training_data_column_map,   double normalising_value){
    map<string,double> entropy_store;
    for(int i=0; i < training_data.size(); i++){
        // training data by transposed row
        map<string,double> row_counts;
        for(int j=0; j<training_data[i].size(); j++){
            if(row_counts.count(training_data[i][j])){
                row_counts[training_data[i][j]] += 1.0/normalising_value;
            }
            else{
                row_counts[training_data[i][j]] = 1.0/normalising_value;
            }
        }
        // calculate entropy
        double entropy = 0;
        //for(auto& element:row_counts) cout << "For the column value " << element.first << " is: " << element.second << endl;
        for(auto& element:row_counts) entropy += (-1) * element.second * log2(element.second);
        entropy_store[training_data_column_map[i]] = entropy;
    }
    for (auto& element:entropy_store) cout << "The entropy for " << element.first << " is: " << element.second << endl;
    return 7.2;
}



int main() {
    // Create example training data.
    //
    map<int,string> training_data_column_map = {{0,"Id"},{1,"stream"},{2,"slope",},{3,"elevation",},{4,"vegetation"}};

     vector<vector<string>> data_matrix_vectors = {{"1", "false", "steep", "high", "chapparal"},
                                          {"2", "true", "moderate", "low", "riparian"},
                                          {"3", "true", "steep", "medium", "riparian"},
                                          {"4", "false", "steep", "medium", "chapparal"},
                                          {"5", "false", "flat", "high", "conifer"},
                                          {"6", "true", "steep", "highest", "conifer"},
                                          {"7", "true", "steep", "high", "chapparal"}};


    vector<vector<string>> transpose_test = transpose_vector_of_vectors(data_matrix_vectors);

    double entropy = calculateEntropy(transpose_test, training_data_column_map, 7.0);


    // print out the transposed data matrix
    cout << "The transposed matrix is: " << transpose_test[0][0] << endl;
    //for(auto & element:transpose_test) for(auto & index:element) cout << index << endl;


    // print out a map value
    cout << "The value for the integer 1 in the map: " << training_data_column_map[10] << endl;

    // Print size of the training data
    data_dimensions training_data_dimensions = getNumberOfTrainingExamples(data_matrix_vectors);
    int num_training_examples = training_data_dimensions.num_examples;
    int num_variables = training_data_dimensions.num_variables;

    cout << "The training data has: " << num_variables << " number of variables and " << num_training_examples << " examples." <<  endl;

}