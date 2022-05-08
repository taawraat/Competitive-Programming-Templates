
#include <iostream>
using namespace std;

// ===> start <=== //
// findGCD function to find GCD
int findGCD(int first, int second)
{ 
  if(!second)
    return first;
  
  return findGCD(second, first % second);
}
// ===> end <=== //

// ===> start <=== //
const int constrains = (1e6);
char prime[constrains + 5];

// check is n is prime for sieve
bool isPrime(int n){
    if(n == 2) return true;
    else if(!(n&1)) return false;
    else if(!prime[n]) return true;
    else return false;
}

// sieve algorithm
void sieve(){
    prime[0] = prime[1] = 1;

    for(int i = 3; i*i <= constrains; i += 2){
        if(isPrime(i)){
            for(int j = i+i; j <= constrains; j += i)
                prime[j] = 1;
        }
    }
}
// ===> end <=== //


// ===> start <=== //
// bigMod function to calculate (a^b mod m)
ll bigMod(ll a, ll b, ll m)
{
  ll ans = 1;
  a = a % m;
  
  while(b){
    // checking if bit is 1
    if(b & 1)
      ans = (ans * a) % m;
      
    a = (a*a) % m;
    b /= 2;
  }
  return ans;
}
// ===> end <=== //

// ===> start <=== //
ll phiof[10000+10];
// returns the value phi(n)
ll phi(ll n){
    ll result = n;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            result /= i;
            result *= (i-1);

            while(n%i == 0)
                n = n/i;
        }
    }
    if(n > 1)
        result /= n, result *= (n-1);

    return result;
}

// Generates the value of phi
void phiGenerate(){
    phiof[1] = 1;
    for(int i = 2; i <= 10000; i++)
        phiof[i] = phi(i);
}
// ===> end <=== //

// driver function
int main(){  
  // start
}
