# InformationTheory
A repo for information theory exploration. 

Ideally will serve as a repo for code relating to study of ["Elements of Information Theory"](http://www.cs-114.org/wp-content/uploads/2015/01/Elements_of_Information_Theory_Elements.pdf)


## Entropy (statistics) 
Entropy can be seen as the amount of uncertainty within a random variable. The higher the entropy the more uncertainty there is about a random variable. *Entropy* can be calculated using the following:

<a href="https://www.codecogs.com/eqnedit.php?latex=Entropy&space;=-&space;\sum^n_{i=1}&space;p(x_i)&space;*&space;log_2(p(x_i))" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Entropy&space;=-&space;\sum^n_{i=1}&space;p(x_i)&space;*&space;log_2(p(x_i))" title="Entropy =- \sum^n_{i=1} p(x_i) * log_2(p(x_i))" /></a>


Example: A coin with a 90% chance of heads will have less *entropy (uncertainty)* than a coin with 50% chance of the heads. 
Entropy for coin with 90% chance of heads:\
    *Entropy* = -(0.9 * log(0.9) + 0.1 * log(0.1))\
              = 0.3251\
    
Entropy for coin with 50% chance of heads:\
    *Entropy* = -(0.5 * log(0.5) + 0.5 * log(0.5))\
              = 0.6931\

From above, the coin with the 90% chance has a smaller measure of *entropy*. Aligned with our definition of entropy, *the more uncertainty, the higher the entropy measure*, there is better odds in guessing the outcome of the coin with with a 90% chance of heads than there is with the coin that has a 50% chance of flipping heads. From this we say the fair coin (50% chance) has a higher entropy than that of the 90% chance of heads coin. 
## Conditional information 
