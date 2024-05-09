// Function to generate a random prime number
function generateRandomPrime() {
    // Helper function to check if a number is prime
    function isPrime(num) {
      if (num <= 1) return false;
      if (num <= 3) return true;
      if (num % 2 === 0 || num % 3 === 0) return false;
      for (let i = 5; i * i <= num; i += 6) {
        if (num % i === 0 || num % (i + 2) === 0) return false;
      }
      return true;
    }
  
    // Generate random numbers until a prime is found
    let primeCandidate = Math.floor(Math.random() * (1000 - 100)) + 100
    while (!isPrime(primeCandidate)) {
      primeCandidate++;
    }
    return primeCandidate;
 }
  
  // Function to generate a random number in the range [2, prime - 1]
  function generateRandomNumber(prime) {
    return Math.floor(Math.random() * (prime - 2)) + 2;
  }
  
  // Function to compute modular exponentiation (base^exponent mod modulus)
  function modExp(base, exponent, modulus) {
    if (modulus === 1) return 0;
    let result = 1;
    base = base % modulus;
    while (exponent > 0) {
      if (exponent % 2 === 1) {
        result = (result * base) % modulus;
      }
      exponent = exponent >> 1;
      base = (base * base) % modulus;
    }
    return result;
  }
  
  // Generate prime number and primitive root
  const prime = generateRandomPrime();
  const primitiveRoot = generateRandomNumber(prime);
  
  // Alice's secret key
  const aliceSecret = generateRandomNumber(prime);
  
  // Bob's secret key
  const bobSecret = generateRandomNumber(prime);
  
  // Compute public keys
  const alicePublicKey = modExp(primitiveRoot, aliceSecret, prime);
  const bobPublicKey = modExp(primitiveRoot, bobSecret, prime);
  
  // Compute shared secret keys
  const sharedSecretAlice = modExp(bobPublicKey, aliceSecret, prime);
  const sharedSecretBob = modExp(alicePublicKey, bobSecret, prime);
  
  // Display keys in the HTML
  document.getElementById('prime').innerText=prime;
  document.getElementById('aliceSecret').innerText = aliceSecret;
  document.getElementById('bobSecret').innerText = bobSecret;
  document.getElementById('alicePublicKey').innerText = alicePublicKey;
  document.getElementById('bobPublicKey').innerText = bobPublicKey;
  document.getElementById('sharedSecret').innerText = sharedSecretAlice === sharedSecretBob ? sharedSecretAlice : "Keys do not match!";
