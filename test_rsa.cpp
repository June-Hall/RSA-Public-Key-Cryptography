#include <iostream>
#include <string>
#include "rsa.h"

int main() {
    // BigInt x("-79380248390522737902399703986576");
    // int bits = x.num_bits();
    // std::cout << "bits = " << bits << std::endl;
    // BigInt y(2);
    // y ^= BigInt(bits+1);

    // std::cout << "x = " << x << std::endl;
    // std::cout << "y = " << y << std::endl;
    // std::cout << "x < y = " << (x < y) << std::endl;
    // std::cout << "x += y = " << (x += y) << std::endl;

    // big primes generator network: https://bigprimes.org/
    BigInt p, q, n, e, d;
    // BigInt p("432448950647698696812338979406507178507418924490439046520853078838344278452756308384493440588775061164983145841644509841630164129642338604286593148616128766769115229650218175254017342613266526600191856378370959964095359210453266331018179320056866631251863490961721329682313577012923306804459454748521");
    // BigInt q("110872375559347553500596605232721894451157285027915974057879998131775131507753050904444452719898088628924849405499768013117974518444205759610234323814164973344295011932368760171508552546010878628777265775852686702378466490620622213467309459658008743554907795357114318814247280034946554185708690313219");
    // BigInt p("8060054341390597872165793836720232976158621761160684711518953106918945822452652495169516703378334299");
    // BigInt q("2849724011239592772270777932131298348162298300258461485629998433613767751867799953261016690385573967");
    // BigInt n, e, d;
    bool is_generated = true;
    generate_keys(p, q, n, e, d, is_generated);

    BigInt plaintext = 12345;
    BigInt ciphertext = rsa_encrypt(plaintext, e, n);
    BigInt decrypted = rsa_decrypt(ciphertext, d, n);

    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;

  return 0;
}