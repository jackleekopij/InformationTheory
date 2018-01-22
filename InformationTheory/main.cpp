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


int main() {
    string data  [ ] = {"queen", "jack"};
    const size_t list_length = sizeof(data)/sizeof(data[0]);
    cout << "The length of the list is: " << list_length << endl;
    // Get counts of each of the card strings.
    map<string, double> prob_dist = calc_counter_occurance(data, list_length);

    // Normalise the counts of the cards to create a probability distribution.
    normalize(prob_dist);

    // Calculate the Shannon entropy
    double entropy = calc_Shannon_entropy(prob_dist);
    cout << "The entropy for the the current card selection is: " << entropy << endl;

    return 0;
}