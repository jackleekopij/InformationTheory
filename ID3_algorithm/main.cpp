#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <Eigen/Dense>
#include <algorithm>

using namespace Eigen;
using namespace std;



struct data_dimensions{
    long num_examples;
    long num_variables;
};




struct data_subest_entropy_calc{
    vector<int> column_variable_index;
    vector<int> data_row_subset;
};



data_dimensions getDimensionsOfTrainingExamples( vector<vector<string>> training_data){
    // getNumberOfTrainingExamples calculates the dimensions of training data
    // args:
    //  training_data: a matrix of training data to have dimensions calculated
    int num_training_data = training_data.size();
    int number_of_variables =  training_data[0].size();
    return data_dimensions{num_training_data, number_of_variables};
}




vector<vector<string>> transpose_vector_of_vectors(vector<vector<string>> training_data){
    // transpose_vector_of_vectors returns a transposed matrix
    // args:
    //  training_data: a matrix that is to be transpoed.
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



double getEntropy(vector<string> vegetation_values){
    double normalisation_const = vegetation_values.size();
    map<string, double> entropy_store;
    double entropy;

    for(vector<string>::iterator it=vegetation_values.begin(); it!=vegetation_values.end();it++){
        if (entropy_store.count(*it)) {
            entropy_store[*it] += 1.0 / normalisation_const;
        } else {
            entropy_store[*it] = 1.0 / normalisation_const;
        }
    }

    for (auto& element:entropy_store) cout << "The proability values are: " << element.second << endl;

    for(auto& index:entropy_store) entropy += (-1) * index.second * log2(index.second);
    return entropy;
}

<<<<<<< HEAD

double getEntropyForMap(map<string, vector<string>> vegetation_map, map<string, double> partition_prob_map){
    double total_entropy;
    for (auto& partitioned_variable:vegetation_map) total_entropy += partition_prob_map[partitioned_variable.first] * getEntropy(partitioned_variable.second);
    return total_entropy;
}

string calculateEntropy( vector<vector<string>> training_data, map<int,string> training_data_column_map,   double normalising_value, int classification_variable){
    map<string,double> entropy_store;
    map<string, map<string, vector<string>>> classification_partitions;
    map<string, map<string,double>> partition_counts_by_level;
    for(int i=1; i < training_data.size(); i++){
        string variable_analysed = training_data_column_map[i];
        // Only get cardinality count if for non-classification variable.
        if(i!= classification_variable) {
            map<string, double> row_counts;
            map<string, vector<string>> classification_variables_by_levels;
            for (int j = 0; j < training_data[i].size(); j++) {
                if (row_counts.count(training_data[i][j])) {
                    row_counts[training_data[i][j]] += 1.0 / normalising_value;
                } else {
                    row_counts[training_data[i][j]] = 1.0 / normalising_value;
                }
                classification_variables_by_levels[training_data[i][j]].push_back(training_data[classification_variable][j]);
=======
string calculateEntropy( vector<vector<string>> training_data, map<int,string> training_data_column_map,   double normalising_value){
    // calculateEntropy returns the variable which has the highest Shanon entropy. TODO: should be changed to lowest.
    // args:
    //  training_data: a matrix of training data to have entropy calculated. 
    //  training_data_column_map: a map used to translate variable names into column integers.
    //  normalising_value: an integer needed to calcualate the marginal distribution for each variable.
    map<string,double> entropy_store;
    for(int i=0; i < training_data.size(); i++){
        map<string,double> row_counts;
        for(int j=0; j<training_data[i].size(); j++){
            if(row_counts.count(training_data[i][j])){
                row_counts[training_data[i][j]] += 1.0/normalising_value;
            }
            else{
                row_counts[training_data[i][j]] = 1.0/normalising_value;
>>>>>>> 3b2f24510b47fe418ab198ff6ba751e243695301
            }
            classification_partitions[variable_analysed] = classification_variables_by_levels;
            partition_counts_by_level[variable_analysed] = row_counts;
            double entropy = 0;
            for (auto &element:row_counts) entropy += (-1) * element.second * log2(element.second);
            entropy_store[variable_analysed] = entropy;
        }
<<<<<<< HEAD
=======
        
        double entropy = 0;
        for(auto& element:row_counts) entropy += (-1) * element.second * log2(element.second);
        entropy_store[training_data_column_map[i]] = entropy;
>>>>>>> 3b2f24510b47fe418ab198ff6ba751e243695301
    }



    for(auto& variables:classification_partitions) cout << "The classification partitions are: " << variables.first << endl;

    for(auto& variable_names:classification_partitions["elevation"]) cout << "The levels of elevation are " << variable_names.first << endl;

    cout << "Entropy for elevation: " << endl;
    cout << getEntropyForMap(classification_partitions["stream"], partition_counts_by_level["stream"]);



    double max_value = 0;
    string highest_entropy_variable = "";
    for (auto& element:entropy_store) if (element.second > max_value and element.first != "Id") {max_value = element.second; highest_entropy_variable = element.first;};

    return highest_entropy_variable;
}




// Use the filtered map to only iterate over the data points which are in the current level of a variable.
string calculateEntropySecondary( vector<vector<string>> training_data, vector<int> variable_selection, map<int, string> training_data_column_map,  vector<int> row_selection, string variable_name){
    // calculateEntropySecondary returns a string identifing variable with highest IG.
    // args:
    //  training_data: a matrix of training data
    //  variable_selection: a vector selecting variables to calculate entropy for
    //  row_selection: selecting which data points include in entropy calculation
    //  trianing_data_column_map: column name to column integer reference map.

    int normalising_value = row_selection.size();
    map<string,double> entropy_store;


    // dereference the iterator to extract the
    for(vector<int>::iterator i=variable_selection.begin();i!= variable_selection.end(); i++){
        map<string,double> reduced_row_counts = {};
        double entropy = 0;
        for(auto& element:row_selection){
            if(reduced_row_counts.count(training_data[*i][element])){
                reduced_row_counts[training_data[*i][element]] += 1.0/normalising_value;
            }
            else{
                reduced_row_counts[training_data[*i][element]] = 1.0/normalising_value;
            }
            cout << "Current entropy for " << element << " is: " << reduced_row_counts[training_data[*i][element]] << endl;
        }

        for(auto& element:reduced_row_counts) entropy += (-1) * element.second * log2(element.second);
        entropy_store[training_data_column_map[*i]] = entropy;
    }


    double max_value = 0;
    string highest_entropy_variable = "";

    for (auto& element:entropy_store) if (element.second >= max_value and element.first != "Id") {max_value = element.second; highest_entropy_variable = element.first;};

    cout << "The maximum entropy score is for " << variable_name << " is " << max_value << endl;

    return highest_entropy_variable;
}




map<string, vector<int>> getMapIndexOfSplitValues(vector<vector<string>> training_data, string variable_to_split, map<int,string> variable_to_col_num){
<<<<<<< HEAD
    // Get col number of the variable to split the training data on.
    // getMapIndexOfSplitValues returns a map with variable levels as key and row indexes as values
    // args:
    //  training_data: a data set to calculate the division on.
    //  variable_to_split: the variable to calculate the division on.
    //  variable_to_col_num: a map to identify the column of 'variable_to_split' in 'training_data'

=======
    // getMapIndexOfSplitValues returns a map of variable levels with row indexes as values
    // args:
    //  training_data: a matrix of training data
    //  variable_to_split: a variable to partition into levels
    //  variable_to_col_num: column name to column integer reference map.
>>>>>>> 3b2f24510b47fe418ab198ff6ba751e243695301
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




data_subest_entropy_calc GetNextDichotomiser(vector<vector<string>> training_data_transposed, string prev_variable, map<int, string> variable_column_map, map<string, vector<int>> map_of_prev_IG_split){
    // Using map created 'getMapIndexOfSplitValues' each 'level' of the variable will be iterated
    // through to with the corresponding 'vector<int>' of 'index values' of the data to by included in
    // the analysis for the next information gain calculation.
    // args:
    //  training_data_transposed: is the training data to calculate the information gain on.
    //  prev_variable: identifying which variables was the previous to have highest IG.
    //  variable_column_map: a map to assist identifying column numbers to exclude from IG calc.
    //  map_of_prev_IG_split: a map to identify groups of indexes to include in next IG calc. Key: variable levels, Value: index vector

    // Create a vector of column numbers to include in IG calculation.
    vector<int> column_num_to_include;
    for(auto& variable:variable_column_map) if(variable.second != prev_variable){column_num_to_include.push_back(variable.first);};


    // Get a vector of int's for each level of 'prev_variable' to calc IG for next divisions/branches.
    // ***TEST: DIVISION LEVEL="HIGH"
    // ALWAYS REMEMBER THE DOUBLE QUOTES FOR A STRING!
    vector<int> row_subset_index;
    vector<int> data_index_for_division = map_of_prev_IG_split.find("highest")->second;
    for(auto& element:map_of_prev_IG_split) cout << "The keys in the data set are: " << element.first << endl;

    map<string, string> prev_variable_level_and_variable_for_division;

    for(auto& row_index:map_of_prev_IG_split){
        string variable_for_division = calculateEntropySecondary(training_data_transposed, column_num_to_include, variable_column_map, row_index.second, row_index.first);
        cout << "The variable for divison: " << variable_for_division << endl;
        prev_variable_level_and_variable_for_division[row_index.first] = variable_for_division;
    }
    // Calculate entropy for each level of 'prev_variable'
    //for()
    //calculateEntropySecondary(training_data_transposed, subset_columns_and_rows.column_variable_index, variable_column_map, subset_columns_and_rows.data_row_subset);

    for(auto& IG_divsion:prev_variable_level_and_variable_for_division) cout << "The level " << IG_divsion.first << " has " << IG_divsion.second << " as its next branch in the tree." << endl;

    return {column_num_to_include, data_index_for_division};
    //return {column_num_to_include, row_subset_index};

}


int getMapKeyFromValue(map<int, string> training_data_column_map, string variable_value){
    // getMapKeyFromValue returns an int for the column index of the desired variable
    // args:
    //  training_data_column_map: a map identifying column indexes for variables.
    //  variable_value: string to get column number for.
    int column_index = -1;
    for(auto& element:training_data_column_map) if(element.second == variable_value){column_index = element.first;};
    return column_index;
}



int main() {
    vector<map<string,vector<int>>> dichotimiser_tree = { };

    map<int,string> training_data_column_map = {{0,"Id"},{1,"stream"},{2,"slope",},{3,"elevation",},{4,"vegetation"}};
    map<char, int> TEST_map = {{'jac',11}, {'sam', 12}};
     vector<vector<string>> data_matrix_vectors = {{"1", "false", "steep", "high", "chapparal"},
                                          {"2", "true", "moderate", "low", "riparian"},
                                          {"3", "true", "steep", "medium", "riparian"},
                                          {"4", "false", "steep", "medium", "chapparal"},
                                          {"5", "false", "flat", "high", "conifer"},
                                          {"6", "true", "steep", "highest", "conifer"},
                                          {"7", "true", "steep", "high", "chapparal"}};

    vector<vector<string>> transpose_test = transpose_vector_of_vectors(data_matrix_vectors);

    int column_index_classification_variable = getMapKeyFromValue(training_data_column_map, "vegetation");

    string important_variable = calculateEntropy(transpose_test, training_data_column_map, 7.0, column_index_classification_variable);


    /*

    // variable_test_split stores a map of the previous variable split by levels as key, with data indexes as values.
    map<string, vector<int>> variable_test_split = getMapIndexOfSplitValues(transpose_test, important_variable, training_data_column_map);
    for (auto& element:variable_test_split) for(auto& index:element.second) cout << "The varaible have currently split on is: " << important_variable << " with the level: " << element.first << " and the index " << index << endl;
    dichotimiser_tree.push_back(variable_test_split);

    // Print out the first dichotimiser split.
    for (auto& element:dichotimiser_tree[0]) for (auto& index:element.second)  cout << "The first levels of the dichotimiser are: " << element.first << " and the index values " << index << endl;

    data_subest_entropy_calc subset_columns_and_rows =  GetNextDichotomiser(transpose_test, "elevation", training_data_column_map, variable_test_split);

    for(auto& index:subset_columns_and_rows.column_variable_index) cout << "The column numbers to iterate over: " << index << endl;
    for(auto& index:subset_columns_and_rows.data_row_subset) cout << "The row indexes to iterate over: " << index << endl;

    vector<int> test_vector = {1,2,4};
    int min_int_in_vector = *(std::min_element(test_vector.begin(), test_vector.end()));

    int column_index_classification_variable = getMapKeyFromValue(training_data_column_map, "vegetation");
    cout << column_index_classification_variable;

     */

<<<<<<< HEAD
}
=======
}
>>>>>>> 3b2f24510b47fe418ab198ff6ba751e243695301
