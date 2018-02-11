# InformationTheory
A repo for information theory exploration. 

Ideally will serve as a repo for code relating to study of ["Elements of Information Theory"](http://www.cs-114.org/wp-content/uploads/2015/01/Elements_of_Information_Theory_Elements.pdf)


## Entropy (statistics) 
Entropy can be seen as the amount of uncertainty within a random variable. The higher the entropy the more uncertainty there is about a random variable. *Entropy* can be calculated using the following:

<div style="text-align:center">
<a href="https://www.codecogs.com/eqnedit.php?latex=Entropy&space;=-&space;\sum^n_{i=1}&space;p(x_i)&space;*&space;log_2(p(x_i))" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Entropy&space;=-&space;\sum^n_{i=1}&space;p(x_i)&space;*&space;log_2(p(x_i))" title="Entropy =- \sum^n_{i=1} p(x_i) * log_2(p(x_i))" /></a>
</div>


Example: A coin with a 90% chance of heads will have less *entropy (uncertainty)* than a coin with 50% chance of the heads. 
Entropy for coin with 90% chance of heads:\
    *Entropy* = -(0.9 * log(0.9) + 0.1 * log(0.1))\
              = 0.3251
    
Entropy for coin with 50% chance of heads:\
    *Entropy* = -(0.5 * log(0.5) + 0.5 * log(0.5))\
              = 0.6931

From above, the coin with the 90% chance has a smaller measure of *entropy*. Aligned with our definition of entropy, *the more uncertainty, the higher the entropy measure*, there is better odds in guessing the outcome of the coin with with a 90% chance of heads than there is with the coin that has a 50% chance of flipping heads. From this we say the fair coin (50% chance) has a higher entropy than that of the 90% chance of heads coin. 

## Conditional entropy 
*Conditional entropy* is explained as the amount of entropy present in variable X conditional on the variable Y. Denoted as H(X|Y) the *conditional entropy* is calculated from the joint distribution of X and Y, P(X, Y). For this joint distribution the same inverse probability (Bayes) rules apply. Heuristically, the higher the *conditional entropy* the less X is *explained* by Y, as H(X|Y) is the residual entropy once Y is controlled for. Conversely, H(X|Y) = 0 pertains to X completely being explained by variable Y.


This extends to the following:

<a href="https://www.codecogs.com/eqnedit.php?latex=H(X|Y&space;=&space;y)&space;=&space;entropy&space;\quad&space;of&space;\quad&space;X&space;\quad&space;coditioned&space;\quad&space;on&space;\quad&space;for&space;\quad&space;a&space;\quad&space;value&space;\quad&space;y" target="_blank"><img src="https://latex.codecogs.com/gif.latex?H(X|Y&space;=&space;y)&space;=&space;entropy&space;\quad&space;of&space;\quad&space;X&space;\quad&space;coditioned&space;\quad&space;on&space;\quad&space;for&space;\quad&space;a&space;\quad&space;value&space;\quad&space;y" title="H(X|Y = y) = entropy \quad of \quad X \quad coditioned \quad on \quad for \quad a \quad value \quad y" /></a>

Applying this to the all values of Y we arrive at the average entropy of X from Y. 

<a href="https://www.codecogs.com/eqnedit.php?latex=H(X|Y)&space;=&space;\sum^n_{i=1}&space;H(X|Y=y_i)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?H(X|Y)&space;=&space;\sum^n_{i=1}&space;H(X|Y=y_i)" title="H(X|Y) = \sum^n_{i=1} H(X|Y=y_i)" /></a>


 



## Mutual information/information gain
*Mutual information* (or *information gain*) is read as the amount of information gains about X from knowing the variable Y. I.e. two variables which have a high (relative) information gain are said hold high amounts of information about one another whereas a lower *information gain* would relate to less shared information.
