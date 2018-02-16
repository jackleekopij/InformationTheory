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





string calculateEntropy( vector<vector<string>> training_data, map<int,string> training_data_column_map,   double normalising_value){
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

    double max_value = 0;
    string highest_entropy_variable = "";
    for (auto& element:entropy_store) if (element.second > max_value and element.first != "Id") {max_value = element.second; highest_entropy_variable = element.first;};

    return highest_entropy_variable;
}



map<string, vector<int>> getIndexOfSplitValues(vector<vector<string>> training_data, string variable_to_split, map<int,string> variable_to_col_num){
    // Get col number of the variable to split the training data on.
    int split_col_number;
    for(map<int,string>::iterator it = variable_to_col_num.begin(); it != variable_to_col_num.end(); it++){
        if (it->second == variable_to_split) split_col_number = it->first;
    }
    vector<string> variable_split_data = training_data[split_col_number];
    map<string, vector<int>> variable_data_split_by_level;

    for(int i=0; i<variable_split_data.size(); i++){
        variable_data_split_by_level[variable_split_data[i]].push_back(i+1);
    }
    return variable_data_split_by_level;
}

int main() {
    // A data structure to build the ordering of importance of variables.
    // string: is the name of the variable that was split on
    // vector<vector<string>>: a matrix to store the tree for it's variable's (the key) split.
    //vector<vector<map<string,vector<int>>>> dichotimiser_tree = { };
    vector<map<string,vector<int>>> dichotimiser_tree = { };
    // Create example training data.
    map<int,string> training_data_column_map = {{0,"Id"},{1,"stream"},{2,"slope",},{3,"elevation",},{4,"vegetation"}};

     vector<vector<string>> data_matrix_vectors = {{"1", "false", "steep", "high", "chapparal"},
                                          {"2", "true", "moderate", "low", "riparian"},
                                          {"3", "true", "steep", "medium", "riparian"},
                                          {"4", "false", "steep", "medium", "chapparal"},
                                          {"5", "false", "flat", "high", "conifer"},
                                          {"6", "true", "steep", "highest", "conifer"},
                                          {"7", "true", "steep", "high", "chapparal"}};

    vector<vector<string>> transpose_test = transpose_vector_of_vectors(data_matrix_vectors);

    string important_variable = calculateEntropy(transpose_test, training_data_column_map, 7.0);


    // Test the variable split
    map<string, vector<int>> variable_test_split = getIndexOfSplitValues(transpose_test, important_variable, training_data_column_map);

    cout << "Print out the current level of the tree: " << endl;
    for (auto& element:variable_test_split) for(auto& index:element.second) cout << "The varaible have currently split on is: " << important_variable << " with the level: " << element.first << " and the index " << index << endl;

    dichotimiser_tree.push_back(variable_test_split);

    // print the dichotmiser tree so far
    for (auto& element:dichotimiser_tree[0]) for (auto& index:element.second)  cout << "The first levels of the dichotimiser are: " << element.first << " and the index values " << index << endl;




    data_dimensions training_data_dimensions = getNumberOfTrainingExamples(data_matrix_vectors);
    int num_training_examples = training_data_dimensions.num_examples;
    int num_variables = training_data_dimensions.num_variables;

}