
#include "Dir_t.hpp"

int main()
{
    Dir_t d;

    d.add("Ahmed", "0689971837", "abdo@gmail.com");
    d.add("Said", "0658743651", "said@gmail.com");
    d.add("Sami", "065754871", "sami@gmail.com");
    d.add("Samira", "065876588", "samira@gmail.com");
    d.add("Amin", "0697484135", "amin@gmail.com");
    d.add("Bahija", "0654478154", "bahija@gmail.com");
    d.add("Fatima", "054678465", "fatima@gmail.com");

    // d.print();
    //  d.deleteList("said@gmail.com");//pour supprimer le contact de said@gmail.com

    d.print();
    return 0;
}