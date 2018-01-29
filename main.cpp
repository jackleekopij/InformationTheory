#include <iostream>
#include <math.h>
#include <set>
#include <map>

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



template <typename T>
inline T const& NormaliseArrays (T const& a){
    for 
    };



int main() {
    // Create the decks of cards to calculate the mutual information for.
    string firstDeck [ ] = {"queen", "jack"};
    string secondDeck [ ]=  {"king", "ace" , "queen", "king"};

    // Empty array length is only allowed for the first dimension.
    double marginal_distribution [ ] = {1.75, 0.75, 2.25};
    double joint_distribution [ ][3] = {{1.25, 1.4, 1.5},{2.25, 0.75, 0.75}};

    cout << "The marginal distribution is:" << endl;
    cout << "The size of the marginal distribution is " << getArrayLength(marginal_distribution) << endl;
    cout << "The size of the joint distribution is [" << getMultiArrayLength(joint_distribution).row << ", " << getMultiArrayLength(joint_distribution).column << "]" << endl;
    for(auto& element:marginal_distribution) cout << element << ", ";

    //for (auto elemnet=marginal_distribution.begin())

    cout << endl;

    cout << endl << "The joint distribution is:" << joint_distribution << endl;
    cout << "The marginal distribution is:" << marginal_distribution << endl;

    const size_t firstDeckLength = getArrayLength(firstDeck);
    cout << "The length of the list is: " << firstDeckLength << endl;
    // Get counts of each of the card strings.
    map<string, double> firstDeckProbDist = calc_counter_occurance(firstDeck, firstDeckLength);



    // Normalise the counts of the cards to create a probability distribution.
    normalize(firstDeckProbDist);

    // Calculate the Shannon entropy
    double entropy = calc_Shannon_entropy(firstDeckProbDist);
    cout << "The entropy for the the current card selection is: " << entropy << endl;

    // Calculate the conditional entropy H(first deck| second deck)
    const size_t secondDeckLength = getArrayLength(secondDeck);





    return 0;
}