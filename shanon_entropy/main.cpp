#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <vector>

using namespace std;

template <class Key,class Val> void normalize(std::map<Key,Val>& prob_Map)
{
    Val sum=Val();
    // auto: is used for type deduction...
    for (auto& vp : prob_Map)sum+=vp.second;
    for (auto& vp : prob_Map)vp.second/=sum;
}

// Calculate the probability distribution of the data.
map<string, double> calc_counter_occurance ( string data  [ ], size_t list_length) {
    std::map<string , double> card_dictionary;
    int i;

    for(i=0; i < list_length; i++){
        string key = data[i];
        card_dictionary[key]+=1;
    }
    return card_dictionary;
}

double calc_Shannon_entropy (map<string, double> prob_distribution){
    int i;
    double shannon_entropy = 0;
    for (auto& prob_value: prob_distribution) shannon_entropy += prob_value.second * log2(prob_value.second);
    // Reflect entropy to the positive range
    if (shannon_entropy < 0) {
        shannon_entropy *= (-1);
    }
    return shannon_entropy;
}

/*
const size_t getArraySize(string dataArray [ ]){
    return sizeof(dataArray)/ sizeof(dataArray[0]);
}
*/

/*
map<string, map<string, double>> jointDistribution (string combinedArray [ ], int arrayLength){
    // Parse probability distribution
    string delimiter = ",";
    string firstArray [ ] = {};
    string secondArray [ ]= {};

    int i;
    for (i = 0; i < arrayLength; i++){

    }

    int i;
    for (i=0; i < firstArrayLength; i++ ){

    }
};
*/

// Templates are a way to define an independent type for a class or function.
// Things like vector<int> is a generic type for storing integers in a vector.
// 'inline' will enable compiler optimisation by not having to jump around the
//      place to execute the function.

// 'size_t' is the return type of the funciton which should calculate the size
// of the array.

// 'struct' is used to group member types together. 'structs' should only access
// or set data and should contain NO functionality. Will return a
// multi-dimensional array.
struct size_multi_array {
    size_t row;
    size_t column;
};


template <typename T>
inline size_t const& getArrayLength (T const& array){
    return sizeof(array)/ sizeof(array[0]);
}


template <typename T>
inline size_multi_array  const& getMultiArrayLength (T const& multi_array){
    return {sizeof(multi_array[0])/ sizeof(multi_array[0][0]), sizeof(multi_array)/ sizeof(multi_array[0])};
}


// You cannot return an array, you must return a pointer to the array.
// This must be dereferenced with the * operator whe instantiated.
template <typename T>
inline double * NormaliseArray (T const& array, int array_length){
    double sum = 0;
    int i = 0;
    double normalised_array [array_length];
    for (auto&  element:array) sum+=element;
    for (i; i < array_length; i++){
        normalised_array[i] = array[i]/sum;
    }
    for (auto& element:normalised_array) cout << element;
    return normalised_array;
    };



// iterate across a vector of vectors to calculate the joint distribution
template <typename T>
inline vector< vector<double>>  NormaliseMultiArray (T  multi_array){

    double normalisation_constant = 0;

    for(int row = 0 ; row < multi_array.size(); row++){
        for(int col = 0; col < multi_array[row].size(); col++){
            cout << "The first value of the iterator vector is " << multi_array[row][col] << endl;
            normalisation_constant += multi_array[row][col];
        }
    }

    vector< vector<double> > joint_distribution = multi_array;

    for(int row = 0 ; row < multi_array.size(); row++){
        for(int col = 0; col < multi_array[row].size(); col++){

            joint_distribution[row][col] = multi_array[row][col] / normalisation_constant;
        }
    }
    return joint_distribution;

}

template <typename T>
inline vector< vector<double>>  ShannonEntropyMultiArray (T  normalised_multi_array){

    double total_entropy = 0;
    double row_entropy = 0;
    vector< vector<double> > joint_distribution = normalised_multi_array;

    for(int row = 0 ; row < normalised_multi_array.size(); row++){
        double row_norm_constant = 0;
        for(auto& element:normalised_multi_array[row]) row_norm_constant += element;
        for(int col = 0; col < normalised_multi_array[row].size(); col++){
            for(auto& element:normalised_multi_array[row]) row_entropy += element/row_norm_constant * log2(element/row_norm_constant);
            total_entropy += row_norm_constant * row_norm_constant;
        }
    }
    return joint_distribution;

}


// Will return the pointer for the first array of arrays.


int main() {
    // Create the decks of cards to calculate the mutual information for.
    string firstDeck [ ] = {"queen", "jack"};
    string secondDeck [ ]=  {"king", "ace" , "queen", "king"};

    int i = 0 ;


    // Empty array length is only allowed for the first dimension.
    double marginal_distribution [ ] = {175, 0.75, 2.25};
    vector< vector<double> > joint_distribution = {{1, 14000000, 150},{22, 90, 10}};

    vector< vector<double> > joint_distribution_normalised = NormaliseMultiArray(joint_distribution);

    cout << endl << "Size of the joint distribution " << joint_distribution_normalised[0].size() << endl;

    for(auto& element:marginal_distribution) cout << element << ", ";

    int size = 10;
    int index = 0;

    std::vector<int> test_vector(size);

    for(index; index < size; index++){
        test_vector[i] = i + 5;
    }


    double sum = 0;

    vector<int>::iterator first_element = test_vector.begin();


    cout << "Sum total " << sum << endl;

    size_t  array_length = getArrayLength(marginal_distribution);

    double normalised_array =  *(NormaliseArray(marginal_distribution, array_length));
    size_multi_array joint_distribution_dim = getMultiArrayLength(joint_distribution);

    const size_t firstDeckLength = getArrayLength(firstDeck);
    // Get counts of each of the card strings.
    map<string, double> firstDeckProbDist = calc_counter_occurance(firstDeck, firstDeckLength);



    // Normalise the counts of the cards to create a probability distribution.
    normalize(firstDeckProbDist);

    // Calculate the Shannon entropy
    double entropy = calc_Shannon_entropy(firstDeckProbDist);


    // Calculate the conditional entropy H(first deck| second deck)
    const size_t secondDeckLength = getArrayLength(secondDeck);





    return 0;
}