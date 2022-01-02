// RSA encryption decryption

#include<stdio.h>
#include<math.h>

int gcd(long long a, long long b){
	if(b == 0)
	    return a;
	return gcd(b, a%b);
}

int main(){
	int p = 3, q = 7, n = p*q, phi = (p-1)*(q-1), e = 2, k = 2;
	double d = 0;
       // public key  = {e, n}
       // private key = {d, n}
      
       // public key
      	while(e < phi){
	    if(gcd(e, phi) == 1)
		break;
	    else
		e++;
	}
	if(e >= phi) e = 1;

	//private key
	d = ((1 + k*phi))/e;

	double msg = 31;
	printf("Enter message to be encrypted: ");
	scanf("%lf", &msg);

	double encrypted = fmod(pow(msg, e), n);
	printf("Encrypted message: %lf\n", encrypted);

	double decrypted = fmod(pow(encrypted, d), n);
	printf("Decrypted message: %lf\n", decrypted);

	return 0;
}

